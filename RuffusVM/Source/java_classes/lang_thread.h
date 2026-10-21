#ifndef NATIVE_LANG_THREAD_H
#define NATIVE_LANG_THREAD_H

#ifdef	__cplusplus
extern "C" {
#endif

///////////////////////////////////////////////////////////////////////////

#include "datatypes.h"

///////////////////////////////////////////////////////////////////////////

enum
{
	RUNNABLE_FIELD_ID,
	RUNNABLE_TOTAL_FIELDS
};

///////////////////////////////////////////////////////////////////////////

// Class field implementation: LANG_THREAD_ENUM
enum
{
	NATIVE_FIELD_LANG_THREAD_ID,
	NATIVE_FIELD_LANG_THREAD_RUNNABLE,
    NATIVE_LANG_THREAD_TOTAL_FIELDS
};

enum
{
    NATIVE_FIELD_LANG_THREAD_MAX_PRIORITY,                                       // static int MAX_PRIORITY
    NATIVE_FIELD_LANG_THREAD_MIN_PRIORITY,                                       // static int MIN_PRIORITY
    NATIVE_FIELD_LANG_THREAD_NORM_PRIORITY,                                      // static int NORM_PRIORITY
};

enum
{
    NATIVE_LANG_THREAD_INIT,                                                     // Thread()
    NATIVE_LANG_THREAD_INIT_RUNNABLE,                                            // Thread(Runnable target)
    NATIVE_LANG_THREAD_INIT_RUNNABLE_STRING,                                     // Thread(Runnable target, String name)
    NATIVE_LANG_THREAD_INIT_STRING,                                              // Thread(String name)
    NATIVE_LANG_THREAD_INIT_THREADGROUP_RUNNABLE,                                // Thread(ThreadGroup group, Runnable target)
    NATIVE_LANG_THREAD_INIT_THREADGROUP_RUNNABLE_STRING,                         // Thread(ThreadGroup group, Runnable target, String name)
    NATIVE_LANG_THREAD_INIT_THREADGROUP_RUNNABLE_STRING_LONG,                    // Thread(ThreadGroup group, Runnable target, String name, long stackSize)
    NATIVE_LANG_THREAD_INIT_THREADGROUP_STRING,                                  // Thread(ThreadGroup group, String name)

    NATIVE_LANG_THREAD_ACTIVECOUNT,                                              // static int activeCount()
    NATIVE_LANG_THREAD_CHECKACCESS,                                              // void checkAccess()
    NATIVE_LANG_THREAD_CLONE,                                                    // protected  Object clone()
    NATIVE_LANG_THREAD_COUNTSTACKFRAMES,                                         // int countStackFrames()
    NATIVE_LANG_THREAD_CURRENTTHREAD,                                            // static Thread currentThread()
    NATIVE_LANG_THREAD_DESTROY,                                                  // void destroy()
    NATIVE_LANG_THREAD_DUMPSTACK,                                                // static void dumpStack()
    NATIVE_LANG_THREAD_ENUMERATE_ARRAY_THREAD,                                   // static int enumerate(Thread[] tarray)
    NATIVE_LANG_THREAD_GETCONTEXTCLASSLOADER,                                    // ClassLoader getContextClassLoader()
    NATIVE_LANG_THREAD_GETID,                                                    // long getId()
    NATIVE_LANG_THREAD_GETNAME,                                                  // String getName()
    NATIVE_LANG_THREAD_GETPRIORITY,                                              // int getPriority()
    NATIVE_LANG_THREAD_GETSTACKTRACE,                                            // StackTraceElement[] getStackTrace()
    NATIVE_LANG_THREAD_GETTHREADGROUP,                                           // ThreadGroup getThreadGroup()
    NATIVE_LANG_THREAD_HOLDSLOCK_OBJECT,                                         // static boolean holdsLock(Object obj)
    NATIVE_LANG_THREAD_INTERRUPT,                                                // void interrupt()
    NATIVE_LANG_THREAD_INTERRUPTED,                                              // static boolean interrupted()
    NATIVE_LANG_THREAD_ISALIVE,                                                  // boolean isAlive()
    NATIVE_LANG_THREAD_ISDAEMON,                                                 // boolean isDaemon()
    NATIVE_LANG_THREAD_ISINTERRUPTED,                                            // boolean isInterrupted()
    NATIVE_LANG_THREAD_JOIN,                                                     // void join()
    NATIVE_LANG_THREAD_JOIN_LONG,                                                // void join(long millis)
    NATIVE_LANG_THREAD_JOIN_LONG_INT,                                            // void join(long millis, int nanos)
    NATIVE_LANG_THREAD_RESUME,                                                   // void resume()
    NATIVE_LANG_THREAD_RUN,                                                      // void run()
    NATIVE_LANG_THREAD_SETCONTEXTCLASSLOADER_CLASSLOADER,                        // void setContextClassLoader(ClassLoader cl)
    NATIVE_LANG_THREAD_SETDAEMON_BOOLEAN,                                        // void setDaemon(boolean on)
    NATIVE_LANG_THREAD_SETNAME_STRING,                                           // void setName(String name)
    NATIVE_LANG_THREAD_SETPRIORITY_INT,                                          // void setPriority(int newPriority)
    NATIVE_LANG_THREAD_SLEEP_LONG,                                               // static void sleep(long millis)
    NATIVE_LANG_THREAD_SLEEP_LONG_INT,                                           // static void sleep(long millis, int nanos)
    NATIVE_LANG_THREAD_START,                                                    // void start()
    NATIVE_LANG_THREAD_STOP,                                                     // void stop()
    NATIVE_LANG_THREAD_STOP_THROWABLE,                                           // void stop(Throwable obj)
    NATIVE_LANG_THREAD_SUSPEND,                                                  // void suspend()
    NATIVE_LANG_THREAD_TOSTRING,                                                 // String toString()
    NATIVE_LANG_THREAD_YIELD,                                                    // static void yield()
};

///////////////////////////////////////////////////////////////////////////

object_t native_lang_thread_new( void );
void native_lang_thread_get_field(uint16_t mref);
void native_lang_thread_invoke(uint16_t mref);

uint32_t native_lang_thread_get_superclass( void );

///////////////////////////////////////////////////////////////////////////

#ifdef	__cplusplus
}
#endif

#endif // NATIVE_LANG_THREAD_H


