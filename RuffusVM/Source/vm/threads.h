#ifndef _THREADS_H_
#define _THREADS_H_

#ifdef	__cplusplus
extern "C" {
#endif
    
///////////////////////////////////////////////////////////////////////////

#include "datatypes.h"
#include "thread_lib.h"

//////////////////////////////////////////////////////////////////////////

typedef struct _runnable_t
{
	uint32_t thread_id; // need to be first to be treated as runnable
	thread_t * thread;  // need to be second to be treated as runnable

} runnable_t;

//////////////////////////////////////////////////////////////////////////

static INLINE instance_t * thread_instance( void )
{
	return instance_get_current();
}

//////////////////////////////////////////////////////////////////////////

bool_t thread_monitor_check( object_t object );

void thread_set( thread_t * thread );
thread_t * thread_get( void );

void thread_set_notify( object_t object, bool_t is_all );
void thread_vm_yield(void);
void thread_expire( void );
void thread_set_wait( object_t object );
void thread_never_expires( void );

uint8_t thread_is_expired( void );

void thread_reset_timer( void );
void thread_create_new( void );

thread_t * thread_get_next( void );

void thread_vm_terminate( uint16_t id );
bool_t thread_destroy( void );

void thread_dump( void );

//////////////////////////////////////////////////////////////////////////

#ifdef	__cplusplus
}
#endif

#endif // _THREADS_H_
