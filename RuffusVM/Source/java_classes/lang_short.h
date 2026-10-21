#ifndef NATIVE_LANG_SHORT_H
#define NATIVE_LANG_SHORT_H

#ifdef	__cplusplus
extern "C" {
#endif

///////////////////////////////////////////////////////////////////////////

#include "datatypes.h"

///////////////////////////////////////////////////////////////////////////

// Class field implementation: LANG_SHORT_ENUM
enum
{
    NATIVE_FIELD_LANG_SHORT_DUMMY,
    NATIVE_LANG_SHORT_TOTAL_FIELDS
};

enum
{
    NATIVE_FIELD_LANG_SHORT_MAX_VALUE,                                           // static short MAX_VALUE
    NATIVE_FIELD_LANG_SHORT_MIN_VALUE,                                           // static short MIN_VALUE
    NATIVE_FIELD_LANG_SHORT_SIZE,                                                // static int SIZE
};

enum
{
    NATIVE_LANG_SHORT_INIT_SHORT,                                                // Short(short value)
    NATIVE_LANG_SHORT_INIT_STRING,                                               // Short(String s)

    NATIVE_LANG_SHORT_BYTEVALUE,                                                 // byte byteValue()
    NATIVE_LANG_SHORT_COMPARETO_SHORT,                                           // int compareTo(Short anotherShort)
    NATIVE_LANG_SHORT_DECODE_STRING,                                             // static Short decode(String nm)
    NATIVE_LANG_SHORT_DOUBLEVALUE,                                               // double doubleValue()
    NATIVE_LANG_SHORT_EQUALS_OBJECT,                                             // boolean equals(Object obj)
    NATIVE_LANG_SHORT_FLOATVALUE,                                                // float floatValue()
    NATIVE_LANG_SHORT_HASHCODE,                                                  // int hashCode()
    NATIVE_LANG_SHORT_INTVALUE,                                                  // int intValue()
    NATIVE_LANG_SHORT_LONGVALUE,                                                 // long longValue()
    NATIVE_LANG_SHORT_PARSESHORT_STRING,                                         // static short parseShort(String s)
    NATIVE_LANG_SHORT_PARSESHORT_STRING_INT,                                     // static short parseShort(String s, int radix)
    NATIVE_LANG_SHORT_REVERSEBYTES_SHORT,                                        // static short reverseBytes(short i)
    NATIVE_LANG_SHORT_SHORTVALUE,                                                // short shortValue()
    NATIVE_LANG_SHORT_TOSTRING,                                                  // String toString()
    NATIVE_LANG_SHORT_TOSTRING_SHORT,                                            // static String toString(short s)
    NATIVE_LANG_SHORT_VALUEOF_SHORT,                                             // static Short valueOf(short s)
    NATIVE_LANG_SHORT_VALUEOF_STRING,                                            // static Short valueOf(String s)
    NATIVE_LANG_SHORT_VALUEOF_STRING_INT,                                        // static Short valueOf(String s, int radix)
};

///////////////////////////////////////////////////////////////////////////

object_t native_lang_short_new( void );
void native_lang_short_get_field(uint16_t mref);
void native_lang_short_invoke(uint16_t mref);

uint32_t native_lang_short_get_superclass( void );

///////////////////////////////////////////////////////////////////////////

#ifdef	__cplusplus
}
#endif

#endif // NATIVE_LANG_SHORT_H


