#ifndef NATIVE_LANG_SYSTEM_H
#define NATIVE_LANG_SYSTEM_H

#ifdef	__cplusplus
extern "C" {
#endif

///////////////////////////////////////////////////////////////////////////

#include "datatypes.h"

///////////////////////////////////////////////////////////////////////////

// Class field implementation: LANG_SYSTEM_ENUM
enum
{
    NATIVE_FIELD_LANG_SYSTEM_DUMMY,
    NATIVE_LANG_SYSTEM_TOTAL_FIELDS
};

enum
{
    NATIVE_FIELD_LANG_SYSTEM_ERR,                                                // static PrintStream err
    NATIVE_FIELD_LANG_SYSTEM_IN,                                                 // static InputStream in
    NATIVE_FIELD_LANG_SYSTEM_OUT,                                                // static PrintStream out
};

enum
{
    NATIVE_LANG_SYSTEM_ARRAYCOPY_OBJECT_INT_OBJECT_INT_INT,                      // static void arraycopy(Object src, int srcPos, Object dest, int destPos, int length)
    NATIVE_LANG_SYSTEM_CLEARPROPERTY_STRING,                                     // static String clearProperty(String key)
    NATIVE_LANG_SYSTEM_CONSOLE,                                                  // static Console console()
    NATIVE_LANG_SYSTEM_CURRENTTIMEMILLIS,                                        // static long currentTimeMillis()
    NATIVE_LANG_SYSTEM_EXIT_INT,                                                 // static void exit(int status)
    NATIVE_LANG_SYSTEM_GC,                                                       // static void gc()
    NATIVE_LANG_SYSTEM_GETENV_STRING,                                            // static String getenv(String name)
    NATIVE_LANG_SYSTEM_GETPROPERTIES,                                            // static Properties getProperties()
    NATIVE_LANG_SYSTEM_GETPROPERTY_STRING,                                       // static String getProperty(String key)
    NATIVE_LANG_SYSTEM_GETPROPERTY_STRING_STRING,                                // static String getProperty(String key, String def)
    NATIVE_LANG_SYSTEM_GETSECURITYMANAGER,                                       // static SecurityManager getSecurityManager()
    NATIVE_LANG_SYSTEM_IDENTITYHASHCODE_OBJECT,                                  // static int identityHashCode(Object x)
    NATIVE_LANG_SYSTEM_LOAD_STRING,                                              // static void load(String filename)
    NATIVE_LANG_SYSTEM_LOADLIBRARY_STRING,                                       // static void loadLibrary(String libname)
    NATIVE_LANG_SYSTEM_MAPLIBRARYNAME_STRING,                                    // static String mapLibraryName(String libname)
    NATIVE_LANG_SYSTEM_NANOTIME,                                                 // static long nanoTime()
    NATIVE_LANG_SYSTEM_RUNFINALIZATION,                                          // static void runFinalization()
    NATIVE_LANG_SYSTEM_RUNFINALIZERSONEXIT_BOOLEAN,                              // static void runFinalizersOnExit(boolean value)
    NATIVE_LANG_SYSTEM_SETERR_PRINTSTREAM,                                       // static void setErr(PrintStream err)
    NATIVE_LANG_SYSTEM_SETIN_INPUTSTREAM,                                        // static void setIn(InputStream in)
    NATIVE_LANG_SYSTEM_SETOUT_PRINTSTREAM,                                       // static void setOut(PrintStream out)
    NATIVE_LANG_SYSTEM_SETPROPERTIES_PROPERTIES,                                 // static void setProperties(Properties props)
    NATIVE_LANG_SYSTEM_SETPROPERTY_STRING_STRING,                                // static String setProperty(String key, String value)
    NATIVE_LANG_SYSTEM_SETSECURITYMANAGER_SECURITYMANAGER,                       // static void setSecurityManager(SecurityManager s)
};

///////////////////////////////////////////////////////////////////////////

object_t native_lang_system_new( void );
void native_lang_system_get_field(uint16_t mref);
void native_lang_system_invoke(uint16_t mref);

uint32_t native_lang_system_get_superclass( void );

///////////////////////////////////////////////////////////////////////////

#ifdef	__cplusplus
}
#endif

#endif // NATIVE_LANG_SYSTEM_H


