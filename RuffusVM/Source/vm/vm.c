#include "vm.h"
#include "objects.h"
#include "application.h"
#include "threads.h"
#include "native.h"
#include "stack.h"
#include "methods.h"
#include "heap.h"
#include "opcodes.h"
#include "exceptions.h"
#include "vm_debug.h"

////////////////////////////////////////////////////////////////////////////////////////

static lib_entry_t * lib_first = NULL;
static lib_entry_t * lib_last = NULL;
static uint32_t lib_id = 0;

////////////////////////////////////////////////////////////////////////////////////////

lib_entry_t * vm_search_lib( char * name )
{
    lib_entry_t * search = lib_first;
    
    while( search != NULL )
    {
        if( !strcmp( search->method_name, name ) )
        {
            return search;
        }
        
        search = search->next;
    }
    
    return NULL;
}

lib_native_t vm_search_lib_by_id( uint32_t id )
{
    lib_entry_t * search = lib_first;
    
    while( search != NULL )
    {
        if( search->lib_id == id )
        {
            return search->lib_call;
        }
        
        search = search->next;
    }
    
    return NULL;
}

void vm_add_lib( char * name, lib_native_t native_call )
{
    lib_entry_t * lib_entry = (lib_entry_t *)malloc( sizeof( lib_entry_t ) );
    if( lib_entry == NULL ) return;
    
    lib_entry->next = NULL;
    lib_entry->method_name = ( char * )malloc( strlen( name ) + 1 );
    if( lib_entry->method_name == NULL )
    {
        free( lib_entry );
        return;
    }
    
    strcpy( ( char * )lib_entry->method_name, name );
    lib_entry->lib_call = native_call;
    lib_entry->lib_id = lib_id++;
    
    if( lib_first == NULL )
    {
        lib_first = lib_entry;
    }
    else
    {
        lib_last->next = lib_entry;
    }
    
    lib_last = lib_entry;
}

uint16_t vm_get_java_pc( void )
{
    thread_t * curr_thread = thread_get();
    uint32_t addr = ( uint32_t )( ( uint8_t * )curr_thread->pc - ( uint8_t * )method_get_address( curr_thread->ptr_method ) );
    addr &= 0x0FFFF;
    
    return ( uint16_t )addr;
}

void vm_new( uint32_t cref )
{
	object_t object;
	uint32_t total_fields;

	if( cref < GET_CLASS_REF( NATIVE_CLASS_BASE ) ) 
	{
		// allocate object
		total_fields = app_class_total_fields( cref );
		object = object_create( cref, T_CLASS, total_fields );
	}
	else
	{
		// it's a native object
		object = native_new( cref );
	}

	stack_push( object );
}

void vm_invoke_new( app_method_t * ptr_method, object_t object, object_t * param_list )
{
	uint32_t counter;
    
	// create new thread
	thread_create_new();

	// prepare stack
	stack_init( STACKSIZE );

	// setup method pointer
	thread_get()->ptr_method = ptr_method;
	thread_get()->arg_ref_ptr = method_get_argref_ptr( ptr_method );

	// set new PC
	thread_get()->pc = method_get_address( ptr_method );

	// push parameters to stack
	for( counter = 0; counter < ptr_method->args; counter++ )
	{
		if( param_list != NULL )
		{
			stack_push( param_list[ counter ] );
		}
		else
		{
			stack_push( 0 );
		}
	}
    
    if( ( ptr_method->flags & FLAG_SYNCHRONIZED ) &&
        ( ( ptr_method->flags & FLAG_STATIC ) == 0 ) )
    {
        vm_enter_monitor( object );
    }    
    
    // set locals
    thread_instance()->locals = stack_get_sp() - ptr_method->args + 1;

	// open space for locals
	stack_add_sp( ptr_method->max_locals - ptr_method->args );
    
    // this method will never return, so return data is NULL
    stack_push( 0 );    

	// set stack base
	thread_instance()->stack_base = stack_get_sp();

	// reset timer
	thread_reset_timer();
}

void vm_enter_monitor( object_t object )
{
    // check if object is available
    if( thread_monitor_check( object ) == TRUE )
    {
        DEBUG_INFO( "thread %d takes ownership of object %08x\n", thread_get()->thread_id, object );
        // this thread gets the ownership of the object
        thread_instance()->sync_object = object;
    }
    else
    {
        DEBUG_INFO( "object %08x already taken, thread %d must wait\n", object, thread_get()->thread_id );
        // this thread tried to access an object already taken, put to wait
        thread_instance()->req_object = object;
        thread_get()->run_mode |= THREAD_MODE_LOCKED;
        thread_expire();
    }    
}

void vm_invoke_finalize( object_t object, uint8_t * data )
{
    app_method_t * ptr_method;
    uint32_t native_cref;
    
    ptr_method = method_find_by_name( object, FINALIZE_CLASS_METHOD_NAME, &native_cref );
    if( ( ptr_method == NULL ) && ( native_cref != 0 ) )
    {
        native_call_finalize( native_cref, object );
    }
    else if( ptr_method != NULL )
    {
        
    }
}

uint8_t vm_invoke( uint32_t cref, uint8_t mode )
{
	uint8_t pc_inc;

	app_method_t * ptr_method;
	return_t * return_data;
    lib_native_t native_lib;

	uint8_t offset = 0;
	object_t obj_return;

	char * method_name = NULL;

	if( cref < GET_CLASS_REF( NATIVE_CLASS_BASE )) 
	{
		// coming as method index
		ptr_method = method_get_data( cref );

        if( ptr_method->flags & FLAG_NATIVE )
        {
            if( ptr_method->id == 0xFFFFFFFF )
            {
                exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
            }
            else
            {
                native_lib = vm_search_lib_by_id(ptr_method->id);
                native_lib();
                pc_inc = 3;
            }
        }
        else
        {
            if(mode != OP_INVOKEINTERFACE)
            {
				// get method name
				method_name = method_get_name_by_index( cref );
	
				// point to the class instance for this call
				offset = ptr_method->args - 1;
            }
	
			// check for inheritance
			if(mode == OP_INVOKEVIRTUAL)
			{ 
				// get final method pointer
				ptr_method = method_find_by_name( stack_peek( offset ), method_name, NULL );
	
				// it cant be a native
				if( ptr_method == NULL )
				{
					exception_new( NATIVE_CLASS_THROW_LANG_ILLEGALARGUMENTEXCEPTION, msg_throw_invalid_ref );
					return FALSE;
				}
			}
            
            if( ( mode != OP_INVOKEINTERFACE ) &&
                ( ptr_method->flags & FLAG_SYNCHRONIZED ) &&
                ( ( ptr_method->flags & FLAG_STATIC ) == 0 ) )
            {
                vm_enter_monitor( stack_peek( offset ) );
            }
			
			// create return data
			obj_return = object_data_create( T_DATA, sizeof( return_t ) );
			return_data = ( return_t * )object_get_ptr( obj_return );
	
			// prepare return data: pc, locals and method ptr
			return_data->saved_pc = thread_get()->pc;
			return_data->ptr_locals = thread_instance()->locals;
			return_data->ptr_method = thread_get()->ptr_method;
			return_data->stack_base = thread_instance()->stack_base;
	
			// prepare for new call: new pc, new locals and method ptr
			thread_get()->pc = method_get_address( ptr_method );
			thread_instance()->locals = stack_get_sp() - ptr_method->args + 1;
			thread_get()->ptr_method = ptr_method;
			thread_get()->arg_ref_ptr = method_get_argref_ptr( ptr_method );
	
			// open space for locals
			stack_add_sp(thread_get()->ptr_method->max_locals - ptr_method->args);
	
			// and save the return data
			stack_push( obj_return );
	
			// set the stack base
			thread_instance()->stack_base = stack_get_sp();
	
			pc_inc = 0;
        }
	} 
	else 
	{ 
		// coming as class/method (id)
		native_invoke(cref);
		pc_inc = 3;
	}

	return( pc_inc );
}

bool_t vm_return( bool_t is_return )
{
	return_t * return_data;
	object_t ret_value = 0;
	object_t ret_object;
	
	// get returned value first
	if( is_return == TRUE ) 
	{
		ret_value = stack_pop();     // save result
	}

	// check stack
	if( stack_get_sp() != thread_instance()->stack_base )
	{
		exception_new( NATIVE_CLASS_THROW_UTIL_EMPTYSTACKEXCEPTION, msg_throw_stack_underflow );
		return FALSE;
	}

	// get return data
	ret_object = stack_pop();

	// restore stack first
	stack_add_sp( -thread_get()->ptr_method->max_locals );

	// if the return data is null, it's the main call or end of a thread
	if( ret_object == 0 )
	{
        if( is_return == TRUE ) thread_instance()->return_object = ret_value;
		return FALSE;
	}

	// get return data
	return_data = ( return_t * )object_get_ptr( ret_object );
    
    if( ( return_data->ptr_method->flags & FLAG_SYNCHRONIZED ) != 0 )
    {
        thread_instance()->sync_object = 0;
    }
    
    // it has got a return data indeed, check what is in there
    if( return_data->saved_pc == NULL )
    {
        // there is no saved PC, so it's end of a thread
        if( is_return == TRUE ) thread_instance()->return_object = ret_value;
		object_delete( ret_object );
		return FALSE;        
    }

	// then restore previous call
	thread_get()->pc = return_data->saved_pc;
	thread_instance()->locals = return_data->ptr_locals;
	thread_get()->ptr_method = return_data->ptr_method;
	thread_instance()->stack_base = return_data->stack_base;
	thread_get()->arg_ref_ptr = method_get_argref_ptr( thread_get()->ptr_method );

	if( is_return == TRUE )
	{
		// put return value back
		stack_push( ret_value );
	}

	// clean up heap
	object_delete( ret_object );
	// object_garbage_collection();

	return( TRUE );
}

bool_t vm_cast_check( uint32_t cref, object_t object )
{
	uint32_t obj_cref;
	uint8_t mode = 0;

	heap_object_locate( object, NULL, &mode );

	if( mode == T_CLASS )
	{
		obj_cref = object_get_class_ref( object );

		while( obj_cref != NEG_U32 )
		{
			if( obj_cref == cref ) return( TRUE );

			obj_cref = app_get_super_class( obj_cref );
		}
	}

	return FALSE;
}

bool_t vm_invoke_interface(object_t object, char * method_name)
{
    app_method_t * ptr_method;
    
    ptr_method = method_find_by_name( object, method_name, NULL );
    if( ptr_method == NULL )
    {
        // exception_new( NATIVE_CLASS_THROW_LANG_ILLEGALARGUMENTEXCEPTION, msg_throw_invalid_ref );
        return FALSE;
    }        

    vm_invoke( ptr_method->index, OP_INVOKEINTERFACE );
    
    return TRUE;
}

void vm_disposed_object_event( object_t object, uint8_t * data )
{
    // reload the object before calling longjmp
    app_java_call_t * java_call;
    
    java_call = ( app_java_call_t * )data;
    
    // create the thread that will reload the object
    app_java_call_start( java_call );
    app_java_call_add_param( java_call, object );
    app_java_call_execute( 0, java_call );
    app_java_call_finish( java_call );    
    
    thread_never_expires();   
    longjmp(app_data->state, EXCEPTION_DISPOSED);
}

uint8_t vm_run(void)
{
	thread_t * next_thread;
	opcode_t instr;
	bool_t is_continue;
	int exception_error;
	int counter;
    
    if( app_data->set_exit == TRUE ) 
    {
        return APP_RUN_EXIT;
    }

	// exception control
	if( ( exception_error = setjmp( app_data->state ) ) != 0 )
	{
		switch( exception_error )
		{
			case UNHANDLED_EXCEPTION:
				// take exception object from stack and print the string
                vm_printk( LEVEL_CONSOLE, "%s\n", strings_get_text_ptr( throw_get_string_exception() ) );
                vm_printk( LEVEL_STOP, "Application %d has exited\r\n", app_data->app_index );
				return APP_RUN_EXIT;

			case EXCEPTION_EXIT:
                vm_printk( LEVEL_STOP, "Application %d has exited\r\n", app_data->app_index );
				return APP_RUN_EXIT;
                
            case EXCEPTION_DISPOSED:
                // this came from the thread creator where the disposed
                // object will be reloaded, so the current thread where the
                // disposed object was tried to access should be
                // expired to allow the loading thread to run
                break;
		}
	}

	// debug mode
	if( app_data->debug_mode == TRUE )
	{
		// implement debug features
		switch( vm_monitor_process() )
		{
			case MONITOR_RUN:
				app_data->debug_pause = FALSE;
				app_data->debug_step = FALSE;
				break;

			case MONITOR_STEP:
				app_data->debug_pause = FALSE;
				app_data->debug_step = TRUE;
				break;

			// case MONITOR_NONE:
			case MONITOR_PAUSE:
				vm_monitor_breakpoint(TRUE);
				app_data->debug_pause = TRUE;
				break;

			case MONITOR_HEAP:
				heap_dump();
				break;

			case MONITOR_STACK:
				stack_dump();
				break;

			case MONITOR_THREAD:
				thread_dump();
				break;

			case MONITOR_GC:
				object_garbage_collection();
				break;
		}

		if( app_data->debug_pause == TRUE )
		{
			return APP_RUN_YIELD;
		}
	}

	// search for a thread to execute
	if( ( thread_get() == NULL ) || ( thread_is_expired() == TRUE ) )
	{
		// system is in sleep - keep search for threads
		next_thread = thread_get_next();
		if( next_thread == NULL ) return APP_RUN_YIELD;

		// finally found a thread
		thread_set( next_thread );

		// reset time slice
		thread_reset_timer();
	}

	#ifdef DEBUG_LEVEL_STACK
	stack_dump();
	#endif

	// debug mode
	if( app_data->debug_mode == TRUE )
	{
		if( app_data->debug_step == TRUE )
		{
			if( app_data->debug_pause == FALSE )
			{
				app_data->debug_pause = TRUE;
				vm_monitor_breakpoint(TRUE);
			}
		}

		if( app_data->stop_addr == thread_get()->pc )
		{
			if( app_data->debug_pause == TRUE ) return APP_RUN_YIELD;
			app_data->stop_addr = NULL;
			vm_monitor_breakpoint(FALSE);
		}
		else
		{
			for( counter = 0; counter < MAX_BKP; counter++ )
			{
				if( app_data->debug_bkp[counter] == NULL ) continue;

				if( thread_get()->pc == app_data->debug_bkp[counter] )
				{
					if( app_data->stop_addr != thread_get()->pc )
					{
						app_data->debug_pause = TRUE;
						app_data->stop_addr = thread_get()->pc;
						vm_monitor_breakpoint(TRUE);
					}
					return APP_RUN_YIELD;
				}
			}
		}
	}

	// execute bytecode (pc incremented inside)
	instr = (opcode_t)( *thread_get()->pc );
	is_continue = vm_run_java( instr );

	// after every instruction, check heap - ONLY FOR DEBUG!!
    if( app_data->debug_mode == TRUE )
    {
        heap_check();
    }

	// it's a return without caller, it's a thread or main
	if( is_continue == FALSE )
	{
		if( thread_get()->run_mode & THREAD_MODE_TIMERTASK )
		{
			// this is a timertask, restart the thread
			timer_restart_thread( thread_instance()->task_object );
		}
		else if( thread_get()->run_mode & THREAD_TYPE_MAIN )
		{
			// terminate application
            vm_printk( LEVEL_STOP, "Application %d has exited\r\n", app_data->app_index );
			return APP_RUN_EXIT;
		}
		else if( thread_get()->run_mode & THREAD_ONE_OFF )
        {
            return APP_THREAD_END;
        }
		else
		{
   			// now destroy this thread, it will switch to next thread
   			thread_destroy();
		}
	}

	return APP_RUN_CONTINUE;
}

