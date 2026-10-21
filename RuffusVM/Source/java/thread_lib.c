#include "thread_lib.h"
#include "heap.h"
#include "application.h"
#include "threads.h"
#include "exceptions.h"
#include "native.h"
#include "objects.h"
#include "stack.h"
#include "value_type.h"
#include "strings.h"
#include "methods.h"
#include "vm.h"

/////////////////////////////////////////////////////////////////////////////

bool_t timer_check_expired( object_t object )
{
	// get data extension
	timertask_t * fields = ( timertask_t * )object_get_extension( object );

	// this thread never restarts
	if( fields->reload_ms == 0 ) return FALSE;

	// check if timer expired
	if( ms_timer_get_ms() < fields->expire_ms ) return FALSE;

	// expired, reload counters
	fields->expire_ms = ms_timer_get_ms() + fields->reload_ms;

	// sign to restart thread
	return TRUE;
}

void timer_restart_thread( object_t timer_task )
{
	// get data extension
	timertask_t * fields = ( timertask_t * )object_get_extension( timer_task );

	// reset stack
	thread_instance()->sp = fields->stack_base;

	// put it on hold
	thread_get()->run_mode |= THREAD_WAIT_TIMERTASK;

	// set PC again
	thread_get()->pc = fields->start_pc;

	// force context switch and reset timer
	// thread_get() = thread_get_next();
	thread_set( thread_get_next() );
	thread_reset_timer();
}

/////////////////////////////////////////////////////////////////////////////

void timer_schedule_start( object_t object, uint32_t period_ms, uint32_t delay_ms, object_t timer_task )
{
	timertask_t * fields; 
	thread_t * curr_thread;

	// the TimerTask object must be stored into the local field
	object_get_fields_ptr( object )[ NATIVE_FIELD_UTIL_TIMER_TIMERTASK_OBJ ] = timer_task;

	// extension is already created
	fields = ( timertask_t * )object_get_extension( timer_task );

	// setup timer parameters
	fields->expire_ms = ms_timer_get_ms() + delay_ms + period_ms;
	fields->reload_ms = period_ms;

	// save the current thread so it carries on
	curr_thread = thread_get();

	// start as new thread
	if( native_thread_start( timer_task, THREAD_CLASS_METHOD_NAME, NULL ) == FALSE )
	{
		exception_new( NATIVE_CLASS_THROW_LANG_ILLEGALARGUMENTEXCEPTION, msg_throw_invalid_ref );
	}

	// save data of this new thread
	fields->stack_base = thread_instance()->sp;

	// update thread id
	fields->thread_id = thread_get()->thread_id;

	// put it on hold
	thread_get()->run_mode |= THREAD_WAIT_TIMERTASK;
	thread_instance()->task_object = timer_task;

	// native_thread_start does pc-=3, so we need to roll back
	thread_get()->pc += 3;
	fields->start_pc = thread_get()->pc;

	// restore current thread
	thread_set( curr_thread );

	// native_thread_start increments the PC, move it back
	thread_get()->pc -= 3;
}

bool_t native_thread_start( object_t object, const char * name, object_t * params )
{
	app_method_t * ptr_method;
	runnable_t * runnable;
	object_t runnable_object;

	// check if it's Thread class or from Runnable
	if( object_get_class_ref( object ) >= GET_CLASS_REF( NATIVE_CLASS_LANG_THREAD ) )
	{
		// it's native Thread, get runnable
		runnable_object = object_get_fields_ptr( object )[ NATIVE_FIELD_LANG_THREAD_RUNNABLE ];

		// if the runnable is null, nothing to do
		if( runnable_object == 0 ) return TRUE;
	}
	else
	{
		// it's an instance of Thread class, id is an extention
		runnable_object = object;
	}

	// and get the data extension of this runnable
	runnable = ( runnable_t * )object_get_extension( runnable_object );

	// get method data
	ptr_method = method_find_by_name( runnable_object, name, NULL );

	if( ptr_method == NULL )
	{
		// exception_new( NATIVE_CLASS_THROW_LANG_ILLEGALARGUMENTEXCEPTION, msg_throw_invalid_ref );
		return FALSE;
	}

	// that wont return to the creating thread, so increase the PC
	thread_get()->pc += 3;

	// create a new thread for it
	vm_invoke_new( ptr_method, runnable_object, params );

	// need to store the caller into the local 0
	thread_instance()->locals[0] = runnable_object;

	// after this native call, new thread's pc is incremented in 3, so discount it here first!
	thread_get()->pc -= 3;

	// set the thread id
	runnable->thread_id = thread_get()->thread_id;
	runnable->thread = thread_get();

	return TRUE;
}

