#ifndef NATIVE_UTIL_TIMERTASK_H
#define NATIVE_UTIL_TIMERTASK_H

#ifdef	__cplusplus
extern "C" {
#endif

///////////////////////////////////////////////////////////////////////////

#include "datatypes.h"

///////////////////////////////////////////////////////////////////////////

// Class field implementation: UTIL_TIMERTASK_ENUM
enum
{
    NATIVE_FIELD_UTIL_TIMERTASK_DUMMY,
    NATIVE_UTIL_TIMERTASK_TOTAL_FIELDS
};

enum
{

    NATIVE_UTIL_TIMERTASK_INIT,                                                  // protected TimerTask()

    NATIVE_UTIL_TIMERTASK_CANCEL,                                                // boolean cancel()
    NATIVE_UTIL_TIMERTASK_RUN,                                                   // abstract  void run()
    NATIVE_UTIL_TIMERTASK_SCHEDULEDEXECUTIONTIME,                                // long scheduledExecutionTime()
};

///////////////////////////////////////////////////////////////////////////

object_t native_util_timertask_new( void );
void native_util_timertask_get_field(uint16_t mref);
void native_util_timertask_invoke(uint16_t mref);

///////////////////////////////////////////////////////////////////////////

#ifdef	__cplusplus
}
#endif

#endif // NATIVE_UTIL_TIMERTASK_H


