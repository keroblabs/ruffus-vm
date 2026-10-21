#ifndef NATIVE_LANG_RUNTIME_H
#define NATIVE_LANG_RUNTIME_H

#ifdef	__cplusplus
extern "C" {
#endif

///////////////////////////////////////////////////////////////////////////

#include "datatypes.h"

///////////////////////////////////////////////////////////////////////////

// Class field implementation: LANG_RUNTIME_ENUM
enum
{
    NATIVE_FIELD_LANG_RUNTIME_DUMMY,
    NATIVE_LANG_RUNTIME_TOTAL_FIELDS
};

enum
{

    NATIVE_LANG_RUNTIME_ADDSHUTDOWNHOOK_THREAD,                                  // void addShutdownHook(Thread hook)
    NATIVE_LANG_RUNTIME_AVAILABLEPROCESSORS,                                     // int availableProcessors()
    NATIVE_LANG_RUNTIME_EXEC_STRING,                                             // Process exec(String command)
    NATIVE_LANG_RUNTIME_EXEC_ARRAY_STRING,                                       // Process exec(String[] cmdarray)
    NATIVE_LANG_RUNTIME_EXEC_ARRAY_STRING_ARRAY_STRING,                          // Process exec(String[] cmdarray, String[] envp)
    NATIVE_LANG_RUNTIME_EXEC_ARRAY_STRING_ARRAY_STRING_FILE,                     // Process exec(String[] cmdarray, String[] envp, File dir)
    NATIVE_LANG_RUNTIME_EXEC_STRING_ARRAY_STRING,                                // Process exec(String command, String[] envp)
    NATIVE_LANG_RUNTIME_EXEC_STRING_ARRAY_STRING_FILE,                           // Process exec(String command, String[] envp, File dir)
    NATIVE_LANG_RUNTIME_EXIT_INT,                                                // void exit(int status)
    NATIVE_LANG_RUNTIME_FREEMEMORY,                                              // long freeMemory()
    NATIVE_LANG_RUNTIME_GC,                                                      // void gc()
    NATIVE_LANG_RUNTIME_GETLOCALIZEDINPUTSTREAM_INPUTSTREAM,                     // InputStream getLocalizedInputStream(InputStream in)
    NATIVE_LANG_RUNTIME_GETLOCALIZEDOUTPUTSTREAM_OUTPUTSTREAM,                   // OutputStream getLocalizedOutputStream(OutputStream out)
    NATIVE_LANG_RUNTIME_GETRUNTIME,                                              // static Runtime getRuntime()
    NATIVE_LANG_RUNTIME_HALT_INT,                                                // void halt(int status)
    NATIVE_LANG_RUNTIME_LOAD_STRING,                                             // void load(String filename)
    NATIVE_LANG_RUNTIME_LOADLIBRARY_STRING,                                      // void loadLibrary(String libname)
    NATIVE_LANG_RUNTIME_MAXMEMORY,                                               // long maxMemory()
    NATIVE_LANG_RUNTIME_REMOVESHUTDOWNHOOK_THREAD,                               // boolean removeShutdownHook(Thread hook)
    NATIVE_LANG_RUNTIME_RUNFINALIZATION,                                         // void runFinalization()
    NATIVE_LANG_RUNTIME_RUNFINALIZERSONEXIT_BOOLEAN,                             // static void runFinalizersOnExit(boolean value)
    NATIVE_LANG_RUNTIME_TOTALMEMORY,                                             // long totalMemory()
    NATIVE_LANG_RUNTIME_TRACEINSTRUCTIONS_BOOLEAN,                               // void traceInstructions(boolean on)
    NATIVE_LANG_RUNTIME_TRACEMETHODCALLS_BOOLEAN,                                // void traceMethodCalls(boolean on)
};

///////////////////////////////////////////////////////////////////////////

object_t native_lang_runtime_new( void );
void native_lang_runtime_get_field(uint16_t mref);
void native_lang_runtime_invoke(uint16_t mref);

uint32_t native_lang_runtime_get_superclass( void );

///////////////////////////////////////////////////////////////////////////

#ifdef	__cplusplus
}
#endif

#endif // NATIVE_LANG_RUNTIME_H


