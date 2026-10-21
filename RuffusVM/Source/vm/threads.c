#include "threads.h"
#include "util_timer.h"
#include "heap.h"
#include "vm.h"
#include "exceptions.h"
#include "native.h"
#include "objects.h"
#include "methods.h"
#include "board.h"

///////////////////////////////////////////////////////////////////////////

#define _get_thread_from_instance(a)	( ( thread_t * )a->data )

///////////////////////////////////////////////////////////////////////////

void thread_dump( void )
{
	instance_t * search_instance = NULL;
	thread_t * thread;
	uint16_t counter;

	counter = 0;

	// go through all threads and remove the object
	while( ( search_instance = instance_get( search_instance ) ) != NULL )
	{
		thread = _get_thread_from_instance( search_instance );
		DEBUG_THREAD( "ID = %03d, MODE = 0x%04x, slice = %5d, sleep = %05d\n",	thread->thread_id, 
																				thread->run_mode, 
																				thread->slice_ms, 
																				thread->sleep_ms );

		DEBUG_THREAD( "ID = %03d, sync = 0x%04x, wait = 0x%04x, task = 0x%04x, req = 0x%04x\n",	thread->thread_id, 
																								search_instance->sync_object, 
																								search_instance->wait_object, 
																								search_instance->task_object, 
																								search_instance->req_object );

		DEBUG_THREAD( "ID = %03d, sp = 0x%04x, base = 0x%04x, local = 0x%04x\n",	thread->thread_id, 
																					search_instance->sp - search_instance->stack, 
																					search_instance->stack_base - search_instance->stack, 
																					search_instance->locals - search_instance->stack );

		counter++;
	}

	DEBUG_THREAD( "Total: %d\n", counter );
}

bool_t thread_monitor_check( object_t object )
{
	instance_t * search_instance = NULL;

	// go through all threads and remove the object
	while( ( search_instance = instance_get( search_instance ) ) != NULL )
	{
		// do not execute
		if( ( search_instance->sync_object != 0 ) &&
			( search_instance->sync_object == object ) ) return FALSE;
	}

	// let it go
	return( TRUE );
}

void thread_set_notify( object_t object, bool_t is_all )
{
	instance_t * search_instance = NULL;

	// go through all threads and remove the object
	while( ( search_instance = instance_get( search_instance ) ) != NULL )
	{
		if( search_instance->wait_object == object )
		{
			search_instance->wait_object = 0;
			_get_thread_from_instance( search_instance )->run_mode &= ~THREAD_MODE_WAIT;

			if( is_all == FALSE ) break;
		}
	}
}

void thread_set_wait( object_t object )
{
	// get object who wants to wait
	thread_instance()->wait_object = object;

	// set thread to wait
	thread_get()->run_mode |= THREAD_MODE_WAIT;

	// expire this thread
	thread_expire();

	// yield
	thread_vm_yield();    
}

void thread_vm_yield(void)
{
	thread_t * next_thread;
	next_thread = thread_get_next();

	if( next_thread != NULL )
	{
		// pc will be incremented AFTER thread is switched,
		// and wont increment either when coming back to this thread...
		// so increment PC now
		thread_get()->pc += 3;

		// set new thread
		thread_set( next_thread );

		// reset time slice
		thread_reset_timer();

		// after this native call, pc is incremented in 3, so discount it here first!
		thread_get()->pc -= 3;
	}
}

void thread_expire( void )
{
    if( thread_get() == NULL ) return;
    
	thread_get()->slice_ms = 0;
}

uint8_t thread_is_expired( void )
{
	// no active thread
	if( thread_get() == NULL ) return FALSE;
    
    // this thread never expires
    if( thread_get()->slice_ms == NEG_U32 ) return FALSE;
    if( thread_get()->run_mode & THREAD_ONE_OFF ) return FALSE;

	if( ( thread_get()->slice_ms == 0 ) ||
		( ms_timer_get_ms() >= thread_get()->slice_ms ) )
	{
		// this thread has been expired
		return TRUE;
	}

	return FALSE;
}

void thread_never_expires( void )
{
	// no active thread
	if( thread_get() == NULL ) return;

	// set new timer
	thread_get()->slice_ms = NEG_U32;
}

void thread_reset_timer( void )
{
	// no active thread
	if( thread_get() == NULL ) return;

	// set new timer
	thread_get()->slice_ms = ms_timer_get_ms() + THREAD_TIME_SLICE;
    
    if( thread_get()->slice_ms == NEG_U32 ) thread_get()->slice_ms--;
}

instance_t * thread_search_instance( thread_t * thread )
{
	instance_t * search_instance = NULL;

	if( thread == NULL ) return NULL;

	while( ( search_instance = instance_get( search_instance ) ) != NULL )
	{
		if( ( ( thread_t * )search_instance->data )->thread_id == thread->thread_id )
		{
			return search_instance;
		}
	}

	return NULL;
}

void thread_set( thread_t * thread )
{
	instance_t * search_instance = NULL;

	app_data->thread_obj = thread;
	if( thread == NULL ) return;

	search_instance = thread_search_instance( thread );
	if( search_instance != NULL ) instance_set( search_instance );
}

thread_t * thread_get( void )
{
	if( app_data->thread_obj == NULL ) return NULL;
    if( instance_get_current() == NULL ) return NULL;
	return _get_thread_from_instance( instance_get_current() );
}

void thread_create_new( void )
{
	instance_t * new_instance;
	thread_t * thread;

	// create instance
	new_instance = instance_create();
	if( new_instance == NULL )
	{
		app_set_error( ERROR_VM_OUT_OF_MEMORY );
		return;
	}

	// create thread
	thread = ( thread_t * )heap_malloc( sizeof( thread_t ) );
	if( thread == NULL )
	{
		// out of memory, try garbage collection
		object_garbage_collection();

		thread = ( thread_t * )heap_malloc( sizeof( thread_t ) );
		if( thread == NULL )
		{
			app_set_error( ERROR_VM_OUT_OF_MEMORY );
			return;
		}
	}

	memset( thread, 0x00, sizeof( thread_t ) );
	thread->thread_id = ++app_data->global_thread_index;

	// set thread
	new_instance->data = thread;
	thread_set( thread );

	// reset time slice
	thread_reset_timer();
}

thread_t * thread_get_next( void )
{
	instance_t * next_instance;
	instance_t * curr_instance;
	instance_t * check_instance;

	// get current thread
	curr_instance = check_instance = instance_get_current();
	if( check_instance == NULL )
	{
		check_instance = instance_get_last();
		if( check_instance == NULL ) return NULL;
	}

	// check is there are more threads
	if( ( check_instance->prev_instance == NULL ) && 
		( check_instance->next_instance == NULL ) )
	{
		return _get_thread_from_instance( curr_instance );
	}

	while( 1 )
	{
		// get who is the next
		next_instance = instance_get( check_instance );
		if( next_instance == NULL )
		{
			next_instance = instance_get( NULL );
		}

		// thread has been interrupted
		if( _get_thread_from_instance( next_instance )->run_mode & THREAD_MODE_INTERRUPT )
		{
			// remove interrupt state to avoid conflits
			_get_thread_from_instance( next_instance )->run_mode &= ~THREAD_MODE_INTERRUPT;

			// set interrupt flag (Java spec)
			_get_thread_from_instance( next_instance )->run_mode |= THREAD_INTERRUPT_FLAG;

			// throw interrupt exception
			exception_new( NATIVE_CLASS_THROW_LANG_INTERRUPTEDEXCEPTION, "Object has been interrupted" );

			// thread free to run
			break;
		}

		// check thread state
		else if( _get_thread_from_instance( next_instance )->run_mode & THREAD_MODE_WAIT )
		{
			// check if thread is waiting
			if( next_instance->wait_object == 0 ) 
			{
				_get_thread_from_instance( next_instance )->run_mode &= ~THREAD_MODE_WAIT;
				break;
			}
		}
        
        // check if this thread is waiting for a monitor
		else if( _get_thread_from_instance( next_instance )->run_mode & THREAD_WAIT_PROPERTY )
		{
			// check if thread is waiting
			if( ( next_instance->wait_object != 0 ) && ( next_instance->prop_object != 0 ) )
			{
				
				break;
			}
        }
        
		// check for sleeping thread
		else if( _get_thread_from_instance( next_instance )->run_mode & THREAD_MODE_SLEEP )
		{
			// check time elapsed
			if( _get_thread_from_instance( next_instance )->sleep_ms <= ms_timer_get_ms() ) 
			{
				_get_thread_from_instance( next_instance )->run_mode &= ~THREAD_MODE_SLEEP;

				if( _get_thread_from_instance( next_instance )->thread_id == 4 )
				{
					break;
				}
				break;
			}
		}

		// timertask thread
		else if( _get_thread_from_instance( next_instance )->run_mode & THREAD_WAIT_TIMERTASK )
		{
			// call the handler
			if( timer_check_expired( next_instance->task_object ) == TRUE )
			{
				// now this thread is running, this flag notifies termination to restart
				_get_thread_from_instance( next_instance )->run_mode &= ~THREAD_WAIT_TIMERTASK;
				_get_thread_from_instance( next_instance )->run_mode |= THREAD_MODE_TIMERTASK;
				break;
			}
		}

		// check if this thread is waiting for a monitor
		else if( _get_thread_from_instance( next_instance )->run_mode & THREAD_MODE_LOCKED )
		{
			// check if object is available
			if( thread_monitor_check( next_instance->req_object ) == TRUE )
			{
				DEBUG_INFO( "thread %d takes ownership of object %08x\n", _get_thread_from_instance( next_instance )->thread_id, next_instance->req_object );

				// gets the object ownership
				next_instance->sync_object = next_instance->req_object;
				next_instance->req_object = 0;
				_get_thread_from_instance( next_instance )->run_mode &= ~THREAD_MODE_LOCKED;
				break;
			}
		}

		// no state set, let it go
		else
		{
			break;
		}

		// this thread is stopped, get another one
		check_instance = next_instance;

		// checked all already, none is running
		if( check_instance == curr_instance )
		{
			return NULL;
		}
	}

	// set the next thread;
	return _get_thread_from_instance( next_instance );
}

void thread_vm_terminate( uint16_t id )
{
	thread_t thread_search;
	thread_t * curr_thread;
	thread_t * thread;
	instance_t * search_instance;

	if( ( thread_get() != NULL ) &&
		( thread_get()->thread_id == id ) )
	{
		// self termination
		thread_destroy();
	}

	// search for the thread
	thread_search.thread_id = id;
	search_instance = thread_search_instance( &thread_search );
	if( search_instance == NULL ) return;

	thread = _get_thread_from_instance(search_instance);

	// first call thread callback
	//if( thread_search->callback != NULL )
	//{
	//	thread_search->callback( thread_get()->task_object );
	//}

	// save the current thread to reuse code
	curr_thread = thread_get();

	// set thread to terminate as current
	thread_set( thread );

	// destroy thread
	thread_destroy();

	// restore current thread
	thread_set( curr_thread );
}


bool_t thread_destroy( void )
{
	thread_t * next_thread;
	thread_t * curr_thread;
	instance_t * instance;
	bool_t is_exit = FALSE;

	// get current thread
	curr_thread = thread_get();
	next_thread = thread_get_next();
	if( next_thread == curr_thread ) 
	{
		// no thread is running, check if there is actually any
		instance = thread_search_instance( curr_thread );
		if( ( instance->next_instance == NULL ) &&
			( instance->prev_instance == NULL ) )
		{
			is_exit = TRUE;
		}
		else
		{
			next_thread = NULL;
		}
	}

	//object_garbage_collection();

	// destroy the thread
	heap_free( curr_thread );
	instance_destroy( thread_instance() );

	// there is no more thread, indicate end of application
	if( is_exit == TRUE ) return FALSE;

	// set the next thread;
	thread_set( next_thread );
	
	// reset time slice
	thread_reset_timer();

	return TRUE;
}
