#ifndef NATIVE_LANG_BYTE_H
#define NATIVE_LANG_BYTE_H

#ifdef	__cplusplus
extern "C" {
#endif

///////////////////////////////////////////////////////////////////////////

#include "datatypes.h"

///////////////////////////////////////////////////////////////////////////

// Class field implementation: LANG_BYTE_ENUM
enum
{
    NATIVE_FIELD_LANG_BYTE_DUMMY,
    NATIVE_LANG_BYTE_TOTAL_FIELDS
};

enum
{
    NATIVE_FIELD_LANG_BYTE_MAX_VALUE,                                            // static byte MAX_VALUE
    NATIVE_FIELD_LANG_BYTE_MIN_VALUE,                                            // static byte MIN_VALUE
    NATIVE_FIELD_LANG_BYTE_SIZE,                                                 // static int SIZE
};

enum
{
    NATIVE_LANG_BYTE_INIT_BYTE,                                                  // Byte(byte value)
    NATIVE_LANG_BYTE_INIT_STRING,                                                // Byte(String s)

    NATIVE_LANG_BYTE_BYTEVALUE,                                                  // byte byteValue()
    NATIVE_LANG_BYTE_COMPARETO_BYTE,                                             // int compareTo(Byte anotherByte)
    NATIVE_LANG_BYTE_DECODE_STRING,                                              // static Byte decode(String nm)
    NATIVE_LANG_BYTE_DOUBLEVALUE,                                                // double doubleValue()
    NATIVE_LANG_BYTE_EQUALS_OBJECT,                                              // boolean equals(Object obj)
    NATIVE_LANG_BYTE_FLOATVALUE,                                                 // float floatValue()
    NATIVE_LANG_BYTE_HASHCODE,                                                   // int hashCode()
    NATIVE_LANG_BYTE_INTVALUE,                                                   // int intValue()
    NATIVE_LANG_BYTE_LONGVALUE,                                                  // long longValue()
    NATIVE_LANG_BYTE_PARSEBYTE_STRING,                                           // static byte parseByte(String s)
    NATIVE_LANG_BYTE_PARSEBYTE_STRING_INT,                                       // static byte parseByte(String s, int radix)
    NATIVE_LANG_BYTE_SHORTVALUE,                                                 // short shortValue()
    NATIVE_LANG_BYTE_TOSTRING,                                                   // String toString()
    NATIVE_LANG_BYTE_TOSTRING_BYTE,                                              // static String toString(byte b)
    NATIVE_LANG_BYTE_VALUEOF_BYTE,                                               // static Byte valueOf(byte b)
    NATIVE_LANG_BYTE_VALUEOF_STRING,                                             // static Byte valueOf(String s)
    NATIVE_LANG_BYTE_VALUEOF_STRING_INT,                                         // static Byte valueOf(String s, int radix)
};

///////////////////////////////////////////////////////////////////////////

object_t native_lang_byte_new( void );
void native_lang_byte_get_field(uint16_t mref);
void native_lang_byte_invoke(uint16_t mref);

uint32_t native_lang_byte_get_superclass( void );

///////////////////////////////////////////////////////////////////////////

#ifdef	__cplusplus
}
#endif

#endif // NATIVE_LANG_BYTE_H


