#include "lang_thread.h"
#include "heap.h"
#include "application.h"
#include "threads.h"
#include "exceptions.h"
#include "native.h"
#include "objects.h"
#include "stack.h"
#include "value_type.h"
#include "strings.h"

#include "vm.h"
#include "methods.h"

///////////////////////////////////////////////////////////////////////////

// use New method implementation to hold a method
// use New implementation to mark start block
// use End new implementation to mark end block to keep

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////

// static int MAX_PRIORITY
#define NATIVE_FIELD_VALUE_LANG_THREAD_MAX_PRIORITY                              0

// static int MIN_PRIORITY
#define NATIVE_FIELD_VALUE_LANG_THREAD_MIN_PRIORITY                              1

// static int NORM_PRIORITY
#define NATIVE_FIELD_VALUE_LANG_THREAD_NORM_PRIORITY                             2

///////////////////////////////////////////////////////////////////////////

object_t native_lang_thread_new( void )
{
    return( object_create( GET_CLASS_REF( NATIVE_CLASS_LANG_THREAD ), T_CLASS, NATIVE_LANG_THREAD_TOTAL_FIELDS ) );
}

///////////////////////////////////////////////////////////////////////////

void native_method_lang_thread_init( void )
{
    // Thread()
    // Allocates a new Thread object. 
    // Implementation code: 41473140
    object_t object;
	runnable_t * runnable;
	object_t * fields;

    object = stack_peek(0);

	// check if it's Thread class or from Runnable
	if( object_get_class_ref( object ) == GET_CLASS_REF( NATIVE_CLASS_LANG_THREAD ) )
	{
		// it's an instance of a native class
		fields = object_get_fields_ptr( object );

		// runnable is null
		fields[ NATIVE_FIELD_LANG_THREAD_RUNNABLE ] = 0;

		// set the thread id, not defined yet
		fields[ NATIVE_FIELD_LANG_THREAD_ID ] = value_create_decimal( 0 );
	}
	else
	{
		// it's an instance of devired Thread class, needs an extension
		object_create_extension( object, sizeof( runnable_t ) );
		runnable = ( runnable_t * )object_get_extension( object );

		// set the thread id, not defined yet
		runnable->thread = NULL;
		runnable->thread_id = 0;
	}

	stack_remove(1);
}

void native_method_lang_thread_init_runnable( void )
{
    // Thread(Runnable target)
    // Allocates a new Thread object. 
    // Implementation code: 41473140
	object_t obj_runnable;
    object_t object;
	runnable_t * runnable;
	object_t * fields;

	obj_runnable = stack_peek(0);
    object = stack_peek(1);

	// get fields
	fields = ( object_t * )object_get_fields_ptr( object );

	// set the thread id, not defined yet
	fields[ NATIVE_FIELD_LANG_THREAD_ID ] = value_create_decimal( 0 );

	// native Thread class calling a Runnable, object must be stored into the local field
	fields[ NATIVE_FIELD_LANG_THREAD_RUNNABLE ] = obj_runnable;

	// create thread id for runnable and add to runnable as data extension
	object_create_extension( obj_runnable, sizeof( runnable_t ) );
	runnable = ( runnable_t * )object_get_extension( obj_runnable );
	runnable->thread = NULL;
	runnable->thread_id = 0;

	stack_remove(2);
}

void native_method_lang_thread_init_runnable_string( void )
{
    // Thread(Runnable target, String name)
    // Allocates a new Thread object. 
    // Implementation code: 41473140
    stack_pop();
	native_method_lang_thread_init_runnable();
}

void native_method_lang_thread_init_string( void )
{
    // Thread(String name)
    // Allocates a new Thread object. 
    // Implementation code: 41473140
    stack_pop();
	native_method_lang_thread_init();
}

void native_method_lang_thread_init_threadgroup_runnable( void )
{
    // Thread(ThreadGroup group, Runnable target)
    // Allocates a new Thread object. 
    // Implementation code: 41473140
    object_t object;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_lang_thread_init_threadgroup_runnable_string( void )
{
    // Thread(ThreadGroup group, Runnable target, String name)
    // Allocates a new Thread object so that it has target as its 
    // run object, has the specified name as its name, and belongs 
    // to the thread group referred to by group. 
    // Implementation code: BF1D190C
    object_t threadgroup_group;
    object_t runnable_target;
    object_t string_name;
    object_t object;

    string_name = stack_pop();
    runnable_target = stack_pop();
    threadgroup_group = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_lang_thread_init_threadgroup_runnable_string_long( void )
{
    // Thread(ThreadGroup group, Runnable target, String name, long stackSize)
    // Allocates a new Thread object so that it has target as its 
    // run object, has the specified name as its name, belongs 
    // to the thread group referred to by group, and has the specified 
    // stack size. 
    // Implementation code: 286CDFE6
    object_t threadgroup_group;
    object_t runnable_target;
    object_t string_name;
    object_t long_stacksize;
    object_t object;

    long_stacksize = stack_pop();
    string_name = stack_pop();
    runnable_target = stack_pop();
    threadgroup_group = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_lang_thread_init_threadgroup_string( void )
{
    // Thread(ThreadGroup group, String name)
    // Allocates a new Thread object. 
    // Implementation code: 41473140
    object_t object;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

///////////////////////////////////////////////////////////////////////////

void native_method_lang_thread_activecount( void )
{
    // static int activeCount()
    // Returns the number of active threads in the current thread's 
    // thread group. 
    // Implementation code: 6D0C55A4
    int32_t ret_value = 0;

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push( value_create( &ret_value, T_INT ) );
}

void native_method_lang_thread_checkaccess( void )
{
    // void checkAccess()
    // Determines if the currently running thread has permission 
    // to modify this thread. 
    // Implementation code: 4925053A
    object_t object;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_lang_thread_clone( void )
{
    // protected  Object clone()
    // Returns a clone if the class of this object is Cloneable. 
    // Implementation code: ABE9DCD2
    object_t object;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: Object
    stack_push( 0 );
}

void native_method_lang_thread_countstackframes( void )
{
    // int countStackFrames()
    // Deprecated. The definition of this call depends on suspend(), 
    // which is deprecated. Further, the results of this call were 
    // never well-defined. 
    // Implementation code: 30A34282
    object_t object;
    int32_t ret_value = 0;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push( value_create( &ret_value, T_INT ) );
}

void native_method_lang_thread_currentthread( void )
{
    // static Thread currentThread()
    // Returns a reference to the currently executing thread object. 
    // Implementation code: EFF8DF43

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: Thread
    stack_push( 0 );
}

void native_method_lang_thread_destroy( void )
{
    // void destroy()
    // Deprecated. This method was originally designed to destroy 
    // this thread without any cleanup. Any monitors it held would 
    // have remained locked. However, the method was never implemented. 
    // If if were to be implemented, it would be deadlock-prone 
    // in much the manner of suspend(). If the target thread held 
    // a lock protecting a critical system resource when it was 
    // destroyed, no thread could ever access this resource again. 
    // If another thread ever attempted to lock this resource, 
    // deadlock would result. Such deadlocks typically manifest 
    // themselves as "frozen" processes. For more information, 
    // see Why are Thread.stop, Thread.suspend and Thread.resume 
    // Deprecated?. 
    // Implementation code: 41ED172B
    object_t object;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_lang_thread_dumpstack( void )
{
    // static void dumpStack()
    // Prints a stack trace of the current thread to the standard 
    // error stream. 
    // Implementation code: 18881F6A

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_lang_thread_enumerate_array_thread( void )
{
    // static int enumerate(Thread[] tarray)
    // Copies into the specified array every active thread in the 
    // current thread's thread group and its subgroups. 
    // Implementation code: 4BFAD4E6
    object_t thread_array_tarray;
    int32_t ret_value = 0;

    thread_array_tarray = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push( value_create( &ret_value, T_INT ) );
}


void native_method_lang_thread_getcontextclassloader( void )
{
    // ClassLoader getContextClassLoader()
    // Returns the context ClassLoader for this Thread. 
    // Implementation code: 26BE3A15
    object_t object;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: ClassLoader
    stack_push( 0 );
}


void native_method_lang_thread_getid( void )
{
    // long getId()
    // Returns the identifier of this Thread. 
    // Implementation code: 5519B54E
    object_t object;
	object_t ret_obj;
	runnable_t * runnable;
    int64_t ret_value = 0L;

    object = stack_peek(0);

	// check if it's Thread class or from Runnable
	if( object_get_class_ref( object ) >= GET_CLASS_REF( NATIVE_CLASS_LANG_THREAD ) )
	{
		// return the current thread ID
		ret_value = thread_get()->thread_id;
	}
	else
	{
		// it's an derived instance of Thread class, get from extension
		runnable = ( runnable_t * )object_get_extension( object );

		if( ( runnable != NULL ) && ( runnable->thread != NULL ) )
			ret_value = runnable->thread_id;
	}

    // return type: long
    ret_obj = value_create_long( ret_value );
	stack_remove(1);
	stack_push( ret_obj );
}

void native_method_lang_thread_getname( void )
{
    // String getName()
    // Returns this thread's name. 
    // Implementation code: 18993A9D
    object_t object;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: String
    stack_push( strings_create( "" ) );
}

void native_method_lang_thread_getpriority( void )
{
    // int getPriority()
    // Returns this thread's priority. 
    // Implementation code: AA879C9E
    object_t object;
    int32_t ret_value = 0;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push( value_create( &ret_value, T_INT ) );
}

void native_method_lang_thread_getstacktrace( void )
{
    // StackTraceElement[] getStackTrace()
    // Returns an array of stack trace elements representing the 
    // stack dump of this thread. 
    // Implementation code: A8136621
    object_t object;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: StackTraceElement[]
    stack_push( 0 );
}


void native_method_lang_thread_getthreadgroup( void )
{
    // ThreadGroup getThreadGroup()
    // Returns the thread group to which this thread belongs. 
    // Implementation code: 0EBD74AA
    object_t object;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: ThreadGroup
    stack_push( 0 );
}


void native_method_lang_thread_holdslock_object( void )
{
    // static boolean holdsLock(Object obj)
    // Returns true if and only if the current thread holds the 
    // monitor lock on the specified object. 
    // Implementation code: D7780DB2
    object_t object_obj;
    bool_t ret_value = 0;

    object_obj = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: boolean
    stack_push( value_create( &ret_value, T_BOOLEAN ) );
}

void native_method_lang_thread_interrupt( void )
{
    // void interrupt()
    // Interrupts this thread. 
    // Implementation code: 723100F0
    object_t object;
	runnable_t * runnable;

    object = stack_pop();

	// it's an derived instance of Thread class, get extension
	runnable = ( runnable_t * )object_get_extension( object );

	// is it interruptable?
	if( runnable->thread->run_mode & ( THREAD_MODE_LOCKED | THREAD_MODE_WAIT | THREAD_MODE_SLEEP ) )
	{
		// remove wait state
		runnable->thread->run_mode &= ~( THREAD_MODE_LOCKED | THREAD_MODE_WAIT | THREAD_MODE_SLEEP );

		// indicate interruption
		runnable->thread->run_mode |= THREAD_MODE_INTERRUPT;
	}
}

void native_method_lang_thread_interrupted( void )
{
    // static boolean interrupted()
    // Tests whether the current thread has been interrupted. 
    // Implementation code: 3D2E4E1C
    bool_t ret_value = 0;

	// indicate interruption
	if( thread_get()->run_mode | THREAD_INTERRUPT_FLAG )
	{
		ret_value = 1;
	}

	// clear interrupt flag after reading (java spec)
	thread_get()->run_mode &= ~THREAD_INTERRUPT_FLAG;

    // return type: boolean
    stack_push( value_create( &ret_value, T_BOOLEAN ) );
}

void native_method_lang_thread_isalive( void )
{
    // boolean isAlive()
    // Tests if this thread is alive. 
    // Implementation code: 719CC7EA
    object_t object;
    bool_t ret_value = 0;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: boolean
    stack_push( value_create( &ret_value, T_BOOLEAN ) );
}

void native_method_lang_thread_isdaemon( void )
{
    // boolean isDaemon()
    // Tests if this thread is a daemon thread. 
    // Implementation code: 1D4F85BF
    object_t object;
    bool_t ret_value = 0;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: boolean
    stack_push( value_create( &ret_value, T_BOOLEAN ) );
}

void native_method_lang_thread_isinterrupted( void )
{
    // boolean isInterrupted()
    // Tests whether this thread has been interrupted. 
    // Implementation code: 6B3B7B93
	runnable_t * runnable;
    object_t object;
	object_t ret_obj;
    bool_t ret_value = 0;

    object = stack_peek(0);

	// it's an derived instance of Thread class, get extension
	runnable = ( runnable_t * )object_get_extension( object );

	// indicate interruption
	if( runnable->thread->run_mode | THREAD_INTERRUPT_FLAG )
	{
		ret_value = TRUE;
	}

    // return type: boolean
    ret_obj = value_create_boolean( ret_value );
	stack_remove(1);
	stack_push( ret_obj );
}

void native_method_lang_thread_join( void )
{
    // void join()
    // Waits for this thread to die. 
    // Implementation code: F0D6FD2D
    object_t object;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_lang_thread_join_long( void )
{
    // void join(long millis)
    // Waits at most millis milliseconds for this thread to die. 
    // Implementation code: 0F993E32
    object_t long_millis;
    object_t object;

    long_millis = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_lang_thread_join_long_int( void )
{
    // void join(long millis, int nanos)
    // Waits at most millis milliseconds plus nanos nanoseconds 
    // for this thread to die. 
    // Implementation code: 29369E54
    object_t long_millis;
    object_t int_nanos;
    object_t object;

    int_nanos = stack_pop();
    long_millis = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_lang_thread_resume( void )
{
    // void resume()
    // Deprecated. This method exists solely for use with suspend(), 
    // which has been deprecated because it is deadlock-prone. 
    // For more information, see Why are Thread.stop, Thread.suspend 
    // and Thread.resume Deprecated?. 
    // Implementation code: 9B5363A4
    object_t object;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_lang_thread_run( void )
{
    // void run()
    // If this thread was constructed using a separate Runnable 
    // run object, then that Runnable object's run method is called; 
    // otherwise, this method does nothing and returns. 
    // Implementation code: 7AB74857
    object_t object;

    object = stack_pop();
}

void native_method_lang_thread_setcontextclassloader_classloader( void )
{
    // void setContextClassLoader(ClassLoader cl)
    // Sets the context ClassLoader for this Thread. 
    // Implementation code: 66375543
    object_t classloader_cl;
    object_t object;

    classloader_cl = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_lang_thread_setdaemon_boolean( void )
{
    // void setDaemon(boolean on)
    // Marks this thread as either a daemon thread or a user thread. 
    // Implementation code: 0A09DF1C
    object_t boolean_on;
    object_t object;

    boolean_on = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}


void native_method_lang_thread_setname_string( void )
{
    // void setName(String name)
    // Changes the name of this thread to be equal to the argument 
    // name. 
    // Implementation code: 22C0E2AB
    object_t string_name;
    object_t object;

    string_name = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_lang_thread_setpriority_int( void )
{
    // void setPriority(int newPriority)
    // Changes the priority of this thread. 
    // Implementation code: 819A65C0
    object_t int_newpriority;
    object_t object;

    int_newpriority = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}


void native_method_lang_thread_sleep_long( void )
{
    // static void sleep(long millis)
    // Causes the currently executing thread to sleep (temporarily 
    // cease execution) for the specified number of milliseconds, 
    // subject to the precision and accuracy of system timers and 
    // schedulers. 
    // Implementation code: C7305B0C
    object_t long_millis;

    long_millis = stack_pop();

	// set sleep mode
	thread_get()->sleep_ms = ( uint32_t )value_get_long( long_millis ) + ms_timer_get_ms();
	thread_get()->run_mode |= THREAD_MODE_SLEEP;

	// expire this thread
	thread_expire();

	// yield
	thread_vm_yield();
}

void native_method_lang_thread_sleep_long_int( void )
{
    // static void sleep(long millis, int nanos)
    // Causes the currently executing thread to sleep (cease execution) 
    // for the specified number of milliseconds plus the specified 
    // number of nanoseconds, subject to the precision and accuracy 
    // of system timers and schedulers. 
    // Implementation code: 3F61943A
    object_t int_nanos;

    int_nanos = stack_pop();
	native_method_lang_thread_sleep_long();
}

void native_method_lang_thread_start( void )
{
    // void start()
    // Causes this thread to begin execution; the Java Virtual 
    // Machine calls the run method of this thread. 
    // Implementation code: D2FC3677
    object_t object;

    object = stack_pop();

    // put your code here
    if( native_thread_start( object, THREAD_CLASS_METHOD_NAME, NULL ) == FALSE )
	{
		exception_new( NATIVE_CLASS_THROW_LANG_ILLEGALARGUMENTEXCEPTION, msg_throw_invalid_ref );
	}
}

void native_method_lang_thread_stop( void )
{
    // void stop()
    // Deprecated. This method is inherently unsafe. Stopping a 
    // thread with Thread.stop causes it to unlock all of the monitors 
    // that it has locked (as a natural consequence of the unchecked 
    // ThreadDeath exception propagating up the stack). If any 
    // of the objects previously protected by these monitors were 
    // in an inconsistent state, the damaged objects become visible 
    // to other threads, potentially resulting in arbitrary behavior. 
    // Many uses of stop should be replaced by code that simply 
    // modifies some variable to indicate that the target thread 
    // should stop running. The target thread should check this 
    // variable regularly, and return from its run method in an 
    // orderly fashion if the variable indicates that it is to 
    // stop running. If the target thread waits for long periods 
    // (on a condition variable, for example), the interrupt method 
    // should be used to interrupt the wait. For more information, 
    // see Why are Thread.stop, Thread.suspend and Thread.resume 
    // Deprecated?. 
    // Implementation code: 05E1DEA3
    object_t object;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_lang_thread_stop_throwable( void )
{
    // void stop(Throwable obj)
    // Deprecated. This method is inherently unsafe. See stop() 
    // for details. An additional danger of this method is that 
    // it may be used to generate exceptions that the target thread 
    // is unprepared to handle (including checked exceptions that 
    // the thread could not possibly throw, were it not for this 
    // method). For more information, see Why are Thread.stop, 
    // Thread.suspend and Thread.resume Deprecated?. 
    // Implementation code: 7AC2E3D3
    object_t throwable_obj;
    object_t object;

    throwable_obj = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_lang_thread_suspend( void )
{
    // void suspend()
    // Deprecated. This method has been deprecated, as it is inherently 
    // deadlock-prone. If the target thread holds a lock on the 
    // monitor protecting a critical system resource when it is 
    // suspended, no thread can access this resource until the 
    // target thread is resumed. If the thread that would resume 
    // the target thread attempts to lock this monitor prior to 
    // calling resume, deadlock results. Such deadlocks typically 
    // manifest themselves as "frozen" processes. For more information, 
    // see Why are Thread.stop, Thread.suspend and Thread.resume 
    // Deprecated?. 
    // Implementation code: CF3C3E3A
    object_t object;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_lang_thread_tostring( void )
{
    // String toString()
    // Returns a string representation of this thread, including 
    // the thread's name, priority, and thread group. 
    // Implementation code: 4419EAC6
    object_t object;
	object_t ret_obj;
	runnable_t * runnable;
	uint32_t thread_id;
	char thread_str[20];

    object = stack_peek(0);

	// check if it's Thread class or from Runnable
	if( object_get_class_ref( object ) >= GET_CLASS_REF( NATIVE_CLASS_LANG_THREAD ) )
	{
		// return the current thread ID
		thread_id = thread_get()->thread_id;
	}
	else
	{
		// it's an derived instance of Thread class, get from extension
		runnable = ( runnable_t * )object_get_extension( object );

		// set the thread id, not defined yet
		thread_id = runnable->thread_id;
	}

	// create string
	sprintf( thread_str, "Thread id %d", thread_id );

    // return type: String
    ret_obj = strings_create( thread_str );
	stack_remove(1);
	stack_push( ret_obj );
}

void native_method_lang_thread_yield( void )
{
    // static void yield()
    // Causes the currently executing thread object to temporarily 
    // pause and allow other threads to execute. 
    // Implementation code: 44FAB6CA

    // put your code here
	thread_vm_yield();
}

///////////////////////////////////////////////////////////////////////////

uint32_t native_lang_thread_get_superclass( void )
{
	return NATIVE_CLASS_LANG_OBJECT;
}

void native_lang_thread_get_field(uint16_t mref)
{
    switch( mref )
    {
        case NATIVE_FIELD_LANG_THREAD_MAX_PRIORITY:
            // static int MAX_PRIORITY
            // Implementation field read code: FIELD_READ_LANG_THREAD_MAX_PRIORITY
            stack_push( value_create_int( NATIVE_FIELD_VALUE_LANG_THREAD_MAX_PRIORITY ) );
            break;

        case NATIVE_FIELD_LANG_THREAD_MIN_PRIORITY:
            // static int MIN_PRIORITY
            // Implementation field read code: FIELD_READ_LANG_THREAD_MIN_PRIORITY
            stack_push( value_create_int( NATIVE_FIELD_VALUE_LANG_THREAD_MIN_PRIORITY ) );
            break;

        case NATIVE_FIELD_LANG_THREAD_NORM_PRIORITY:
            // static int NORM_PRIORITY
            // Implementation field read code: FIELD_READ_LANG_THREAD_NORM_PRIORITY
            stack_push( value_create_int( NATIVE_FIELD_VALUE_LANG_THREAD_NORM_PRIORITY ) );
            break;

        default: 
            exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
            break;
    }
}

void native_lang_thread_invoke(uint16_t mref)
{
    switch( mref )
    {
        case NATIVE_LANG_THREAD_INIT:
            native_method_lang_thread_init();
            break;

        case NATIVE_LANG_THREAD_INIT_RUNNABLE:
            native_method_lang_thread_init_runnable();
            break;

        case NATIVE_LANG_THREAD_INIT_RUNNABLE_STRING:
            native_method_lang_thread_init_runnable_string();
            break;

        case NATIVE_LANG_THREAD_INIT_STRING:
            native_method_lang_thread_init_string();
            break;

        case NATIVE_LANG_THREAD_INIT_THREADGROUP_RUNNABLE:
            native_method_lang_thread_init_threadgroup_runnable();
            break;

        case NATIVE_LANG_THREAD_INIT_THREADGROUP_RUNNABLE_STRING:
            native_method_lang_thread_init_threadgroup_runnable_string();
            break;

        case NATIVE_LANG_THREAD_INIT_THREADGROUP_RUNNABLE_STRING_LONG:
            native_method_lang_thread_init_threadgroup_runnable_string_long();
            break;

        case NATIVE_LANG_THREAD_INIT_THREADGROUP_STRING:
            native_method_lang_thread_init_threadgroup_string();
            break;

        case NATIVE_LANG_THREAD_ACTIVECOUNT:
            native_method_lang_thread_activecount();
            break;

        case NATIVE_LANG_THREAD_CHECKACCESS:
            native_method_lang_thread_checkaccess();
            break;

        case NATIVE_LANG_THREAD_CLONE:
            native_method_lang_thread_clone();
            break;

        case NATIVE_LANG_THREAD_COUNTSTACKFRAMES:
            native_method_lang_thread_countstackframes();
            break;

        case NATIVE_LANG_THREAD_CURRENTTHREAD:
            native_method_lang_thread_currentthread();
            break;

        case NATIVE_LANG_THREAD_DESTROY:
            native_method_lang_thread_destroy();
            break;

        case NATIVE_LANG_THREAD_DUMPSTACK:
            native_method_lang_thread_dumpstack();
            break;

        case NATIVE_LANG_THREAD_ENUMERATE_ARRAY_THREAD:
            native_method_lang_thread_enumerate_array_thread();
            break;

        case NATIVE_LANG_THREAD_GETCONTEXTCLASSLOADER:
            native_method_lang_thread_getcontextclassloader();
            break;

        case NATIVE_LANG_THREAD_GETID:
            native_method_lang_thread_getid();
            break;

        case NATIVE_LANG_THREAD_GETNAME:
            native_method_lang_thread_getname();
            break;

        case NATIVE_LANG_THREAD_GETPRIORITY:
            native_method_lang_thread_getpriority();
            break;

        case NATIVE_LANG_THREAD_GETSTACKTRACE:
            native_method_lang_thread_getstacktrace();
            break;

        case NATIVE_LANG_THREAD_GETTHREADGROUP:
            native_method_lang_thread_getthreadgroup();
            break;

        case NATIVE_LANG_THREAD_HOLDSLOCK_OBJECT:
            native_method_lang_thread_holdslock_object();
            break;

        case NATIVE_LANG_THREAD_INTERRUPT:
            native_method_lang_thread_interrupt();
            break;

        case NATIVE_LANG_THREAD_INTERRUPTED:
            native_method_lang_thread_interrupted();
            break;

        case NATIVE_LANG_THREAD_ISALIVE:
            native_method_lang_thread_isalive();
            break;

        case NATIVE_LANG_THREAD_ISDAEMON:
            native_method_lang_thread_isdaemon();
            break;

        case NATIVE_LANG_THREAD_ISINTERRUPTED:
            native_method_lang_thread_isinterrupted();
            break;

        case NATIVE_LANG_THREAD_JOIN:
            native_method_lang_thread_join();
            break;

        case NATIVE_LANG_THREAD_JOIN_LONG:
            native_method_lang_thread_join_long();
            break;

        case NATIVE_LANG_THREAD_JOIN_LONG_INT:
            native_method_lang_thread_join_long_int();
            break;

        case NATIVE_LANG_THREAD_RESUME:
            native_method_lang_thread_resume();
            break;

        case NATIVE_LANG_THREAD_RUN:
            native_method_lang_thread_run();
            break;

        case NATIVE_LANG_THREAD_SETCONTEXTCLASSLOADER_CLASSLOADER:
            native_method_lang_thread_setcontextclassloader_classloader();
            break;

        case NATIVE_LANG_THREAD_SETDAEMON_BOOLEAN:
            native_method_lang_thread_setdaemon_boolean();
            break;

        case NATIVE_LANG_THREAD_SETNAME_STRING:
            native_method_lang_thread_setname_string();
            break;

        case NATIVE_LANG_THREAD_SETPRIORITY_INT:
            native_method_lang_thread_setpriority_int();
            break;

        case NATIVE_LANG_THREAD_SLEEP_LONG:
            native_method_lang_thread_sleep_long();
            break;

        case NATIVE_LANG_THREAD_SLEEP_LONG_INT:
            native_method_lang_thread_sleep_long_int();
            break;

        case NATIVE_LANG_THREAD_START:
            native_method_lang_thread_start();
            break;

        case NATIVE_LANG_THREAD_STOP:
            native_method_lang_thread_stop();
            break;

        case NATIVE_LANG_THREAD_STOP_THROWABLE:
            native_method_lang_thread_stop_throwable();
            break;

        case NATIVE_LANG_THREAD_SUSPEND:
            native_method_lang_thread_suspend();
            break;

        case NATIVE_LANG_THREAD_TOSTRING:
            native_method_lang_thread_tostring();
            break;

        case NATIVE_LANG_THREAD_YIELD:
            native_method_lang_thread_yield();
            break;

        default:
            exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
            break;

    }
}


