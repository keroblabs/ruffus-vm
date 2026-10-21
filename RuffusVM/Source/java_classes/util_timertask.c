#include "util_timertask.h"
#include "heap.h"
#include "application.h"
#include "threads.h"
#include "exceptions.h"
#include "native.h"
#include "objects.h"
#include "stack.h"
#include "value_type.h"
#include "strings.h"

///////////////////////////////////////////////////////////////////////////

// use New method implementation to hold a method
// use New implementation to mark start block
// use End new implementation to mark end block to keep

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////

object_t native_util_timertask_new( void )
{
    return( object_create( GET_CLASS_REF( NATIVE_CLASS_UTIL_TIMERTASK ), T_CLASS, NATIVE_UTIL_TIMERTASK_TOTAL_FIELDS ) );
}

///////////////////////////////////////////////////////////////////////////

void native_method_util_timertask_init( void )
{
    // protected TimerTask()
    // Creates a new timer task. 
    // Implementation code: 411AA072
    object_t object;

    object = stack_pop();

	// it's an instance of devired Thread class, needs an extension
	//object_garbage_collection();
	object_create_extension( object, sizeof( timertask_t ) );
}

///////////////////////////////////////////////////////////////////////////

void native_method_util_timertask_cancel( void )
{
    // boolean cancel()
    // Cancels this timer task. 
    // Implementation code: 24C33588
    object_t object;
	timertask_t * timer_data;
    bool_t ret_value = 0;

    object = stack_pop();

	timer_data = ( timertask_t * )object_get_extension( object );

	//self-termination
	if( ( thread_get() != NULL ) && 
		( timer_data->thread_id == thread_get()->thread_id ) )
	{
		// remove mark so it wont restart
		thread_get()->run_mode &= ~THREAD_MODE_TIMERTASK;

		// mark thead to be terminated
		thread_get()->run_mode |= THREAD_MARK_TERMINATE;
	}
	else
	{
		// terminate the timer thread
		thread_vm_terminate( timer_data->thread_id );
	}

    // return type: boolean
    stack_push( value_create( &ret_value, T_BOOLEAN ) );
}

void native_method_util_timertask_run( void )
{
    // abstract  void run()
    // The action to be performed by this timer task. 
    // Implementation code: EC876F15
    object_t object;

    object = stack_pop();
}

void native_method_util_timertask_scheduledexecutiontime( void )
{
    // long scheduledExecutionTime()
    // Returns the scheduled execution time of the most recent 
    // actual execution of this task. 
    // Implementation code: DDCB1D88
    object_t object;
    int64_t ret_value = 0L;

    object = stack_pop();

    // return type: long
    stack_push( value_create( &ret_value, T_LONG ) );
}

///////////////////////////////////////////////////////////////////////////

void native_util_timertask_invoke(uint16_t mref)
{
    switch( mref )
    {
        case NATIVE_UTIL_TIMERTASK_INIT:
            native_method_util_timertask_init();
            break;

        case NATIVE_UTIL_TIMERTASK_CANCEL:
            native_method_util_timertask_cancel();
            break;

        case NATIVE_UTIL_TIMERTASK_RUN:
            native_method_util_timertask_run();
            break;

        case NATIVE_UTIL_TIMERTASK_SCHEDULEDEXECUTIONTIME:
            native_method_util_timertask_scheduledexecutiontime();
            break;

        default:
            exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
            break;

    }
}


