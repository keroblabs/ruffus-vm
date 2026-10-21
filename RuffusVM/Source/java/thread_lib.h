#ifndef NATIVE_THREAD_LIB_H
#define NATIVE_THREAD_LIB_H

#ifdef	__cplusplus
extern "C" {
#endif

///////////////////////////////////////////////////////////////////////////

#include "datatypes.h"

///////////////////////////////////////////////////////////////////////////

typedef struct _timertask_fields_t
{
	uint32_t thread_id; // need to be first to be treated as runnable
	thread_t * thread;  // need to be second to be treated as runnable

	uint32_t expire_ms;
	uint32_t reload_ms;
	object_t * stack_base;
	uint8_t * start_pc;

} timertask_t;

///////////////////////////////////////////////////////////////////////////
	
bool_t timer_check_expired( object_t object );
bool_t native_thread_start( object_t object, const char * name, object_t * params );

void timer_restart_thread( object_t timer_task );
void timer_schedule_start( object_t object, uint32_t period_ms, uint32_t delay_ms, object_t timer_task );

///////////////////////////////////////////////////////////////////////////

#ifdef	__cplusplus
}
#endif

#endif // NATIVE_THREAD_LIB_H

