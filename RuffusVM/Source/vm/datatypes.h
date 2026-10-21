#ifndef DATATYPES_H
#define	DATATYPES_H

///////////////////////////////////////////////////////////////////////////

#include "types.h"
#include "vm_debug.h"
#include "error.h"
#include "instance.h"
#include <setjmp.h>

///////////////////////////////////////////////////////////////////////////

#define THREAD_MODE_WAIT				0x0001		// thread called wait()
#define THREAD_MODE_SLEEP				0x0002		// thread sleeping until...
#define THREAD_MODE_INTERRUPT			0x0004		// interrupt flag (as per Java spec)
#define THREAD_MODE_LOCKED				0x0008		// thread locked by a lock monitor
#define THREAD_WAIT_TIMERTASK			0x0010		// thread waiting to be started
#define THREAD_MODE_TIMERTASK			0x0020		// thread must restart when terminated
#define THREAD_MARK_TERMINATE			0x0040		// mark this thread to be terminated
#define THREAD_INTERRUPT_FLAG			0x0080		// interrupt flag
#define THREAD_WAIT_PROPERTY            0x0100      // wait for property
#define THREAD_ONE_OFF                  0x4000      // this thread run isolated from the VM
#define THREAD_TYPE_MAIN				0x8000		// this is the main thread, when terminated, aplication is closed

#define THREAD_TIME_SLICE				20

#define MAX_BKP							16

#define JAVA_CALL_MAX_ARGS              10

#define FILE_MAX_SIZE					(32000)

#define GET_CLASS_ID(a)					( a & ~0x0FFFF )
#define GET_CLASS_REF(a)				( a << 16 )
#define GET_CLASS_INDEX(a)				( a >> 16 )

#define GET_METHOD_ID(a)				( a & 0x00FFFF )
#define CREATE_ID(a,b)					( ( a << 16 ) | b )

#define NATIVE_CLASS_BASE				8192

#define THREAD_CLASS_METHOD_NAME		"run:()V"
#define EVENTABLE_CLASS_METHOD_NAME		"onRun:(Ljava/lang/Object;Lruffus/system/EventArgs;)V"
#define FINALIZE_CLASS_METHOD_NAME      "finalize:()V"
    
#define APP_RUN_YIELD                   0
#define APP_RUN_CONTINUE                1
#define APP_RUN_EXIT                    2
#define APP_THREAD_END                  3
	
#define HEAPSIZE						(8192)
#define STACKSIZE						(64)

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////

typedef void( *lib_native_t )( void );

typedef struct _lib_entry_t
{
    uint32_t lib_id;
    const char * method_name;
    lib_native_t lib_call;
    
    struct _lib_entry_t * next;
    
} lib_entry_t;
    
typedef struct 
{
	uint16_t super;
	uint16_t fields;

} app_class_t;

typedef struct
{
	uint16_t pc;
	uint16_t line;

} app_debug_t;

typedef struct 
{
	uint32_t  code_index;
	uint32_t  id;           // class and method id
	uint16_t  index;
	uint8_t   flags;
	uint8_t   args;
	int8_t    max_locals;
	uint8_t   max_stack;
	uint8_t   max_exception;
	uint8_t   max_debug;
	uint8_t   max_argrefs;
	uint8_t   reserved1;
	uint16_t  code_size;

} app_method_t;

typedef struct _app_exception_t
{
	uint16_t start_pc;
	uint16_t end_pc;
	uint16_t handle_pc;

	uint16_t class_id;

} exception_t;

typedef struct _method_return_t
{
	uint8_t *		saved_pc;
	app_method_t *	ptr_method;
	object_t *		ptr_locals;
	object_t *      stack_base;

} return_t;

typedef struct 
{
	uint16_t  total_methods;    // number of methods in this file
	uint16_t  total_const;	    // number of string in this file
	uint16_t  total_classes;
	uint16_t  total_statics;
    uint16_t  reserved;

	uint16_t  main;             // index of main method

	uint32_t  constant_offset;
	uint32_t  method_offset;

	app_class_t class_list[];

} app_header_t;

typedef struct
{
    app_method_t * method;
    app_instance_t * instance;
    app_instance_t * call_instance;
    
    uint16_t param_cnt;
    uint16_t param_index;
    
    object_t call_object;
    object_t ret_object;
    
    object_t arg_list[ JAVA_CALL_MAX_ARGS ];
    
    bool_t is_static;

} app_java_call_t;

typedef struct _thread_t
{
	uint16_t thread_id;				// thread id
	uint16_t run_mode;				// bitmask for the running mode

	uint32_t slice_ms;				// time when this thread has its execution expired
	uint32_t sleep_ms;				// for how long this thread should sleep

	uint32_t * arg_ref_ptr;

	uint8_t * pc;
	app_method_t * ptr_method;

} thread_t;

typedef struct _app_data_t
{
	// heap memory
	uint8_t heap_mem[ HEAPSIZE ];

	// debug mode
	bool_t debug_mode;
	bool_t debug_pause;
	bool_t debug_step;
    bool_t set_exit;
    bool_t debug_printk;
    uint8_t vm_state;
	uint8_t * debug_bkp[MAX_BKP];
	uint8_t * stop_addr;
	jmp_buf state;

	// thread data
	thread_t * thread_obj;

	// instance of this application
	app_instance_t app_instance;

	// file pointer
	app_header_t * file_header;
	uint8_t   from_rom;
	uint32_t  size;

	// methods
    app_method_t * methods_ptr;

	// application indexes
	uint16_t app_index;
	uint16_t global_thread_index;

	// link to next one
	struct _app_data_t * next;

} app_data_t;

///////////////////////////////////////////////////////////////////////////

extern app_data_t * app_data;

///////////////////////////////////////////////////////////////////////////

#endif	/* DATATYPES_H */

