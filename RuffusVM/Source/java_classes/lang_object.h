#ifndef NATIVE_LANG_OBJECT_H
#define NATIVE_LANG_OBJECT_H

#ifdef	__cplusplus
extern "C" {
#endif

///////////////////////////////////////////////////////////////////////////

#include "datatypes.h"

///////////////////////////////////////////////////////////////////////////

// Class field implementation: LANG_OBJECT_ENUM
enum
{
    NATIVE_FIELD_LANG_OBJECT_DUMMY,
    NATIVE_LANG_OBJECT_TOTAL_FIELDS
};

enum
{

    NATIVE_LANG_OBJECT_INIT,                                                     // Object()

    NATIVE_LANG_OBJECT_CLONE,                                                    // protected  Object clone()
    NATIVE_LANG_OBJECT_EQUALS_OBJECT,                                            // boolean equals(Object obj)
    NATIVE_LANG_OBJECT_FINALIZE,                                                 // protected  void finalize()
    NATIVE_LANG_OBJECT_GET_CLASS,                                                // Class<?> getClass() 
    NATIVE_LANG_OBJECT_HASHCODE,                                                 // int hashCode()
    NATIVE_LANG_OBJECT_NOTIFY,                                                   // void notify()
    NATIVE_LANG_OBJECT_NOTIFYALL,                                                // void notifyAll()
    NATIVE_LANG_OBJECT_TOSTRING,                                                 // String toString()
    NATIVE_LANG_OBJECT_WAIT,                                                     // void wait()
    NATIVE_LANG_OBJECT_WAIT_LONG,                                                // void wait(long timeout)
    NATIVE_LANG_OBJECT_WAIT_LONG_INT,                                            // void wait(long timeout, int nanos)
};

///////////////////////////////////////////////////////////////////////////

object_t native_lang_object_new( void );
void native_lang_object_get_field(uint16_t mref);
void native_lang_object_invoke(uint16_t mref);

uint32_t native_lang_object_get_superclass( void );

///////////////////////////////////////////////////////////////////////////

#ifdef	__cplusplus
}
#endif

#endif // NATIVE_LANG_OBJECT_H


