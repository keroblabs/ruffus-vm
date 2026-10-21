#include "util_timer.h"
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

object_t native_util_timer_new( void )
{
    return( object_create( GET_CLASS_REF( NATIVE_CLASS_UTIL_TIMER ), T_CLASS, NATIVE_UTIL_TIMER_TOTAL_FIELDS ) );
}

///////////////////////////////////////////////////////////////////////////

void native_method_util_timer_init( void )
{
    // Timer()
    // Creates a new timer. 
    // Implementation code: 1E05D666
    object_t object;

    object = stack_pop();
}

void native_method_util_timer_init_boolean( void )
{
    // Timer(boolean isDaemon)
    // Creates a new timer whose associated thread may be specified 
    // to run as a daemon. 
    // Implementation code: 9D813371
    object_t boolean_isdaemon;
    object_t object;

    boolean_isdaemon = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_util_timer_init_string( void )
{
    // Timer(String name)
    // Creates a new timer whose associated thread has the specified 
    // name. 
    // Implementation code: 1E7032C1
    object_t string_name;
    object_t object;

    string_name = stack_pop();
    object = stack_pop();

    // put your code here
    // exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_util_timer_init_string_boolean( void )
{
    // Timer(String name, boolean isDaemon)
    // Creates a new timer whose associated thread has the specified 
    // name, and may be specified to run as a daemon. 
    // Implementation code: E6741D9E
    object_t string_name;
    object_t boolean_isdaemon;
    object_t object;

    boolean_isdaemon = stack_pop();
    string_name = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

///////////////////////////////////////////////////////////////////////////

void native_method_util_timer_cancel( void )
{
    // void cancel()
    // Terminates this timer, discarding any currently scheduled 
    // tasks. 
    // Implementation code: 7637B928
    object_t object;
	object_t timer_task;
	timertask_t * fields;

    object = stack_pop();

	// pop object reference
	timer_task = object_get_fields_ptr( object )[ NATIVE_FIELD_UTIL_TIMER_TIMERTASK_OBJ ];
	fields = ( timertask_t * )object_get_extension( timer_task );

	//self-termination
	if( ( thread_get() != NULL ) && 
		( fields->thread_id == thread_get()->thread_id ) )
	{
		// remove mark so it wont restart
		thread_get()->run_mode &= ~THREAD_MODE_TIMERTASK;

		// mark thead to be terminated
		thread_get()->run_mode |= THREAD_MARK_TERMINATE;
	}
	else
	{
		// terminate the timer thread
		thread_vm_terminate( fields->thread_id );
	}
}

void native_method_util_timer_purge( void )
{
    // int purge()
    // Removes all cancelled tasks from this timer's task queue. 
    // Implementation code: C63890AC
    object_t object;
    int32_t ret_value = 0;

    object = stack_pop();

    // put your code here
    // exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push( value_create( &ret_value, T_INT ) );
}

void native_method_util_timer_schedule_timertask_date( void )
{
    // void schedule(TimerTask task, Date time)
    // Schedules the specified task for execution at the specified 
    // time. 
    // Implementation code: D400FEB2
    object_t timertask_task;
    object_t date_time;
    object_t object;

    date_time = stack_pop();
    timertask_task = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_util_timer_schedule_timertask_date_long( void )
{
    // void schedule(TimerTask task, Date firstTime, long period)
    // Schedules the specified task for repeated fixed-delay execution, 
    // beginning at the specified time. 
    // Implementation code: 3DA7F3F0
    object_t timertask_task;
    object_t date_firsttime;
    object_t long_period;
    object_t object;

    long_period = stack_pop();
    date_firsttime = stack_pop();
    timertask_task = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_util_timer_schedule_timertask_long( void )
{
    // void schedule(TimerTask task, long delay)
    // Schedules the specified task for execution after the specified 
    // delay. 
    // Implementation code: 31FCB2F5
    object_t timertask_task;
    object_t long_delay;
    object_t object;

    long_delay = stack_pop();
    timertask_task = stack_pop();
    object = stack_pop();

    // put your code here
	timer_schedule_start( object, 0, ( uint32_t )value_get_long( long_delay ), timertask_task );
}

void native_method_util_timer_schedule_timertask_long_long( void )
{
    // void schedule(TimerTask task, long delay, long period)
    // Schedules the specified task for repeated fixed-delay execution, 
    // beginning after the specified delay. 
    // Implementation code: 90D692A2
    object_t timertask_task;
    object_t long_delay;
    object_t long_period;
    object_t object;

    long_period = stack_pop();
    long_delay = stack_pop();
    timertask_task = stack_pop();
    object = stack_pop();

    // put your code here
	timer_schedule_start( object, ( uint32_t )value_get_long( long_period ), ( uint32_t )value_get_long( long_delay ), timertask_task );
}

void native_method_util_timer_scheduleatfixedrate_timertask_date_long( void )
{
    // void scheduleAtFixedRate(TimerTask task, Date firstTime, long period)
    // Schedules the specified task for repeated fixed-rate execution, 
    // beginning at the specified time. 
    // Implementation code: D78C8C96
    object_t timertask_task;
    object_t date_firsttime;
    object_t long_period;
    object_t object;

    long_period = stack_pop();
    date_firsttime = stack_pop();
    timertask_task = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_util_timer_scheduleatfixedrate_timertask_long_long( void )
{
    // void scheduleAtFixedRate(TimerTask task, long delay, long period)
    // Schedules the specified task for repeated fixed-rate execution, 
    // beginning after the specified delay. 
    // Implementation code: BE17B961
    object_t timertask_task;
    object_t long_delay;
    object_t long_period;
    object_t object;

    long_period = stack_pop();
    long_delay = stack_pop();
    timertask_task = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

///////////////////////////////////////////////////////////////////////////

void native_util_timer_invoke(uint16_t mref)
{
    switch( mref )
    {
        case NATIVE_UTIL_TIMER_INIT:
            native_method_util_timer_init();
            break;

        case NATIVE_UTIL_TIMER_INIT_BOOLEAN:
            native_method_util_timer_init_boolean();
            break;

        case NATIVE_UTIL_TIMER_INIT_STRING:
            native_method_util_timer_init_string();
            break;

        case NATIVE_UTIL_TIMER_INIT_STRING_BOOLEAN:
            native_method_util_timer_init_string_boolean();
            break;

        case NATIVE_UTIL_TIMER_CANCEL:
            native_method_util_timer_cancel();
            break;

        case NATIVE_UTIL_TIMER_PURGE:
            native_method_util_timer_purge();
            break;

        case NATIVE_UTIL_TIMER_SCHEDULE_TIMERTASK_DATE:
            native_method_util_timer_schedule_timertask_date();
            break;

        case NATIVE_UTIL_TIMER_SCHEDULE_TIMERTASK_DATE_LONG:
            native_method_util_timer_schedule_timertask_date_long();
            break;

        case NATIVE_UTIL_TIMER_SCHEDULE_TIMERTASK_LONG:
            native_method_util_timer_schedule_timertask_long();
            break;

        case NATIVE_UTIL_TIMER_SCHEDULE_TIMERTASK_LONG_LONG:
            native_method_util_timer_schedule_timertask_long_long();
            break;

        case NATIVE_UTIL_TIMER_SCHEDULEATFIXEDRATE_TIMERTASK_DATE_LONG:
            native_method_util_timer_scheduleatfixedrate_timertask_date_long();
            break;

        case NATIVE_UTIL_TIMER_SCHEDULEATFIXEDRATE_TIMERTASK_LONG_LONG:
            native_method_util_timer_scheduleatfixedrate_timertask_long_long();
            break;

        default:
            exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
            break;

    }
}


