#ifndef NATIVE_LANG_BOOLEAN_H
#define NATIVE_LANG_BOOLEAN_H

#ifdef	__cplusplus
extern "C" {
#endif

///////////////////////////////////////////////////////////////////////////

#include "datatypes.h"

///////////////////////////////////////////////////////////////////////////

// Class field implementation: LANG_BOOLEAN_ENUM
enum
{
    NATIVE_FIELD_LANG_BOOLEAN_DUMMY,
    NATIVE_LANG_BOOLEAN_TOTAL_FIELDS
};

enum
{
    NATIVE_FIELD_LANG_BOOLEAN_FALSE,                                             // static Boolean FALSE
    NATIVE_FIELD_LANG_BOOLEAN_TRUE,                                              // static Boolean TRUE
};

enum
{
    NATIVE_LANG_BOOLEAN_INIT_BOOLEAN,                                            // Boolean(boolean value)
    NATIVE_LANG_BOOLEAN_INIT_STRING,                                             // Boolean(String s)

    NATIVE_LANG_BOOLEAN_BOOLEANVALUE,                                            // boolean booleanValue()
    NATIVE_LANG_BOOLEAN_COMPARETO_BOOLEAN,                                       // int compareTo(Boolean b)
    NATIVE_LANG_BOOLEAN_EQUALS_OBJECT,                                           // boolean equals(Object obj)
    NATIVE_LANG_BOOLEAN_GETBOOLEAN_STRING,                                       // static boolean getBoolean(String name)
    NATIVE_LANG_BOOLEAN_HASHCODE,                                                // int hashCode()
    NATIVE_LANG_BOOLEAN_PARSEBOOLEAN_STRING,                                     // static boolean parseBoolean(String s)
    NATIVE_LANG_BOOLEAN_TOSTRING,                                                // String toString()
    NATIVE_LANG_BOOLEAN_TOSTRING_BOOLEAN,                                        // static String toString(boolean b)
    NATIVE_LANG_BOOLEAN_VALUEOF_BOOLEAN,                                         // static Boolean valueOf(boolean b)
    NATIVE_LANG_BOOLEAN_VALUEOF_STRING,                                          // static Boolean valueOf(String s)
};

///////////////////////////////////////////////////////////////////////////

object_t native_lang_boolean_new( void );
void native_lang_boolean_get_field(uint16_t mref);
void native_lang_boolean_invoke(uint16_t mref);

uint32_t native_lang_boolean_get_superclass( void );

///////////////////////////////////////////////////////////////////////////

#ifdef	__cplusplus
}
#endif

#endif // NATIVE_LANG_BOOLEAN_H


