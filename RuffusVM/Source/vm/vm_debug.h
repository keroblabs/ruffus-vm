/* 
 * File:   debug.h
 * Author: cherobim
 *
 * Created on February 28, 2013, 4:45 PM
 */

#ifndef __VM_DEBUG_H
#define	__VM_DEBUG_H

#ifdef	__cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////////////////////

#include "types.h"
#include "board.h"

/////////////////////////////////////////////////////////////////////////////

#define DBG8		"%02x"
#define DBG16		"%04x"
#define DBG32		"%08x"
#define DBG_INT		"0x" DBG32

/////////////////////////////////////////////////////////////////////////////

// debug keys
#define DEBUG_PRINT

#ifdef DEBUG_LOG_FILE
#undef DEBUG_LOG_FILE
#endif

//#define DEBUG_LOG_FILE "..\\..\\Projects\\ThreadDemo\\log1.txt"

//#define DEBUG_LEVEL_HEAP
//#define DEBUG_LEVEL_STACK
//#define DEBUG_LEVEL_METHOD
//#define DEBUG_LEVEL_INSTR
//#define DEBUG_LEVEL_INFO
//#define DEBUG_LEVEL_MSG
//#define DEBUG_LEVEL_WARN
//#define DEBUG_LEVEL_ERROR
#define DEBUG_LEVEL_BREAKPT
#define DEBUG_LEVEL_CONSOLE
#define DEBUG_LEVEL_GC
    
#define DEBUG_USE_MONITOR

#define VM_DEBUG_MODE TRUE

/////////////////////////////////////////////////////////////////////////////

#define LEVEL_METHOD        0x00001
#define LEVEL_STACK         0x00002
#define LEVEL_INSTR         0x00004
#define LEVEL_INFO          0x00008
#define LEVEL_MSG           0x00010
#define LEVEL_WARN          0x00020
#define LEVEL_ERROR         0x00040
#define LEVEL_HEAP          0x00080
#define LEVEL_GC            0x00100
#define LEVEL_THREAD        0x00200
#define LEVEL_CONSOLE       0x00400
#define LEVEL_BREAKPT       0x00800
#define LEVEL_STOP          0x01000
    
#define SET_LEVEL_HEAP		LEVEL_HEAP
#define SET_LEVEL_STACK		LEVEL_STACK
#define SET_LEVEL_THREAD	LEVEL_THREAD
#define SET_LEVEL_BREAKPT   LEVEL_BREAKPT
#define SET_LEVEL_STOP      LEVEL_STOP
    
//#ifndef DEBUG_LEVEL_HEAP
//#define SET_LEVEL_HEAP 0
//#else
//#define SET_LEVEL_HEAP LEVEL_HEAP
//#endif

//#ifndef DEBUG_LEVEL_STACK
//#define SET_LEVEL_STACK 0
//#else
//#define SET_LEVEL_STACK LEVEL_STACK
//#endif

#ifndef DEBUG_LEVEL_GC
#define SET_LEVEL_GC 0
#else
#define SET_LEVEL_GC LEVEL_GC
#endif

#ifndef DEBUG_LEVEL_CONSOLE
#define SET_LEVEL_CONSOLE 0
#else
#define SET_LEVEL_CONSOLE LEVEL_CONSOLE
#endif

#ifndef DEBUG_LEVEL_METHOD
#define SET_LEVEL_METHOD 0
#else
#define SET_LEVEL_METHOD LEVEL_METHOD
#endif

#ifndef DEBUG_LEVEL_INSTR
#define SET_LEVEL_INSTR 0
#else
#define SET_LEVEL_INSTR LEVEL_INSTR
#endif

#ifndef DEBUG_LEVEL_INFO
#define SET_LEVEL_INFO 0
#else
#define SET_LEVEL_INFO LEVEL_INFO
#endif

#ifndef DEBUG_LEVEL_MSG
#define SET_LEVEL_MSG 0
#else
#define SET_LEVEL_MSG LEVEL_MSG
#endif

#ifndef DEBUG_LEVEL_WARN
#define SET_LEVEL_WARN 0
#else
#define SET_LEVEL_WARN LEVEL_WARN
#endif

#ifndef DEBUG_LEVEL_ERROR
#define SET_LEVEL_ERROR 0
#else
#define SET_LEVEL_ERROR LEVEL_ERROR
#endif

#define DEBUG_LEVEL		 ( SET_LEVEL_METHOD	  | \
						   SET_LEVEL_STACK	  | \
						   SET_LEVEL_INSTR	  | \
						   SET_LEVEL_CONSOLE  | \
						   SET_LEVEL_BREAKPT  | \
                           SET_LEVEL_STOP     | \
						   SET_LEVEL_INFO	  | \
						   SET_LEVEL_MSG	  | \
						   SET_LEVEL_WARN	  | \
						   SET_LEVEL_HEAP	  | \
						   SET_LEVEL_GC 	  | \
						   SET_LEVEL_THREAD	  | \
						   SET_LEVEL_ERROR )

#ifdef DEBUG_INFO
#undef DEBUG_INFO
#endif

#ifdef DEBUG_HEAP
#undef DEBUG_HEAP
#endif

#ifdef DEBUG_STACK
#undef DEBUG_STACK
#endif

#ifdef DEBUG_INSTR
#undef DEBUG_INSTR
#endif

#ifdef DEBUG_METHOD
#undef DEBUG_METHOD
#endif

#ifdef DEBUG_WARN
#undef DEBUG_WARN
#endif

#ifdef DEBUG_ERROR
#undef DEBUG_ERROR
#endif

#ifdef DEBUG_CONSOLE
#undef DEBUG_CONSOLE
#endif

#ifdef DEBUG_GC
#undef DEBUG_GC
#endif

#ifndef VM_DEBUG_MODE
#define VM_DEBUG_MODE  FALSE
#endif

// void monitor_debug_printf(int level, const char * fmt, ...);
void vm_printk(int level, const char * fmt, ...);

//#ifdef DEBUG_USE_MONITOR
//#define CONSOLE_DEBUG	monitor_debug_printf
//#else
//#define CONSOLE_DEBUG	console_debug
//#endif
#define CONSOLE_DEBUG       vm_printk

#ifdef DEBUG_PRINT
#define DEBUGF(...)         CONSOLE_DEBUG( LEVEL_MSG,      __VA_ARGS__ )
#define DEBUG_INSTR(...)    CONSOLE_DEBUG( LEVEL_INSTR,    __VA_ARGS__ )
#define DEBUG_WARN(...)     CONSOLE_DEBUG( LEVEL_WARN,     __VA_ARGS__ )
#define DEBUG_ERROR(...)    CONSOLE_DEBUG( LEVEL_ERROR,    __VA_ARGS__ )
#define DEBUG_INFO(...)     CONSOLE_DEBUG( LEVEL_INFO,     __VA_ARGS__ )
#define DEBUG_METHOD(...)   CONSOLE_DEBUG( LEVEL_METHOD,   __VA_ARGS__ )
#define DEBUG_CONSOLE(...)  CONSOLE_DEBUG( LEVEL_CONSOLE,  __VA_ARGS__ )
#define DEBUG_STOP(...)     CONSOLE_DEBUG( LEVEL_STOP,     __VA_ARGS__ )

#define DEBUG_HEAP(...)     CONSOLE_DEBUG( LEVEL_HEAP,   __VA_ARGS__ )
#define DEBUG_STACK(...)    CONSOLE_DEBUG( LEVEL_STACK,  __VA_ARGS__ )
#define DEBUG_THREAD(...)   CONSOLE_DEBUG( LEVEL_THREAD, __VA_ARGS__ )
#define DEBUG_GC(...)       CONSOLE_DEBUG( LEVEL_GC,     __VA_ARGS__ )
#else

#ifdef DEBUG_LEVEL
#undef DEBUG_LEVEL
#endif

#define VM_DEBUG_MODE FALSE

#define DEBUG_LEVEL 0

#define DEBUG_METHOD(...)
#define DEBUG_STACK(...)
#define DEBUG_INSTR(...)
#define DEBUG_INFO(...)
#define DEBUG_WARN(...)
#define DEBUG_ERROR(...)
#define DEBUG_HEAP(...)
#define DEBUG_GC(...)
#endif

///////////////////////////////////////////////////////////////////////////

enum
{
	MONITOR_NONE,
	MONITOR_PAUSE,
	MONITOR_STEP,
	MONITOR_STACK,
	MONITOR_HEAP,
	MONITOR_GC,
	MONITOR_THREAD,

	// from here it holds the state until press enter
	MONITOR_HOLD,

	MONITOR_RUN,
	MONITOR_SHOW,

	MONITOR_MAX
};

///////////////////////////////////////////////////////////////////////////

typedef void (*vm_console_t)( char * message );

///////////////////////////////////////////////////////////////////////////

uint16_t vm_monitor_process( void );
void 	 vm_monitor_init( void );
void     vm_monitor_breakpoint( bool_t is_break );
void     vm_monitor_base_address( uint32_t address );

vm_console_t vm_debug_set_console( vm_console_t new_hdl );

///////////////////////////////////////////////////////////////////////////

#ifdef	__cplusplus
}
#endif

#endif	/* DEBUG_H */

