#ifndef NATIVE_UTIL_TIMER_H
#define NATIVE_UTIL_TIMER_H

#ifdef	__cplusplus
extern "C" {
#endif

///////////////////////////////////////////////////////////////////////////

#include "datatypes.h"

///////////////////////////////////////////////////////////////////////////

// Class field implementation: UTIL_TIMER_ENUM
enum
{
	NATIVE_FIELD_UTIL_TIMER_TIMERTASK_OBJ,
    NATIVE_UTIL_TIMER_TOTAL_FIELDS
};

enum
{

    NATIVE_UTIL_TIMER_INIT,                                                      // Timer()
    NATIVE_UTIL_TIMER_INIT_BOOLEAN,                                              // Timer(boolean isDaemon)
    NATIVE_UTIL_TIMER_INIT_STRING,                                               // Timer(String name)
    NATIVE_UTIL_TIMER_INIT_STRING_BOOLEAN,                                       // Timer(String name, boolean isDaemon)

    NATIVE_UTIL_TIMER_CANCEL,                                                    // void cancel()
    NATIVE_UTIL_TIMER_PURGE,                                                     // int purge()
    NATIVE_UTIL_TIMER_SCHEDULE_TIMERTASK_DATE,                                   // void schedule(TimerTask task, Date time)
    NATIVE_UTIL_TIMER_SCHEDULE_TIMERTASK_DATE_LONG,                              // void schedule(TimerTask task, Date firstTime, long period)
    NATIVE_UTIL_TIMER_SCHEDULE_TIMERTASK_LONG,                                   // void schedule(TimerTask task, long delay)
    NATIVE_UTIL_TIMER_SCHEDULE_TIMERTASK_LONG_LONG,                              // void schedule(TimerTask task, long delay, long period)
    NATIVE_UTIL_TIMER_SCHEDULEATFIXEDRATE_TIMERTASK_DATE_LONG,                   // void scheduleAtFixedRate(TimerTask task, Date firstTime, long period)
    NATIVE_UTIL_TIMER_SCHEDULEATFIXEDRATE_TIMERTASK_LONG_LONG,                   // void scheduleAtFixedRate(TimerTask task, long delay, long period)
};

///////////////////////////////////////////////////////////////////////////

object_t native_util_timer_new( void );
void native_util_timer_get_field(uint16_t mref);
void native_util_timer_invoke(uint16_t mref);

///////////////////////////////////////////////////////////////////////////

#ifdef	__cplusplus
}
#endif

#endif // NATIVE_UTIL_TIMER_H


