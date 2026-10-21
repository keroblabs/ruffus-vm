#ifndef NATIVE_LANG_INTEGER_H
#define NATIVE_LANG_INTEGER_H

#ifdef	__cplusplus
extern "C" {
#endif

///////////////////////////////////////////////////////////////////////////

#include "datatypes.h"

///////////////////////////////////////////////////////////////////////////

// Class field implementation: LANG_INTEGER_ENUM
enum
{
    NATIVE_FIELD_LANG_INTEGER_DUMMY,
    NATIVE_LANG_INTEGER_TOTAL_FIELDS
};

enum
{
    NATIVE_FIELD_LANG_INTEGER_MAX_VALUE,                                         // static int MAX_VALUE
    NATIVE_FIELD_LANG_INTEGER_MIN_VALUE,                                         // static int MIN_VALUE
    NATIVE_FIELD_LANG_INTEGER_SIZE,                                              // static int SIZE
};

enum
{
    NATIVE_LANG_INTEGER_INIT_INT,                                                // Integer(int value)
    NATIVE_LANG_INTEGER_INIT_STRING,                                             // Integer(String s)

    NATIVE_LANG_INTEGER_BITCOUNT_INT,                                            // static int bitCount(int i)
    NATIVE_LANG_INTEGER_BYTEVALUE,                                               // byte byteValue()
    NATIVE_LANG_INTEGER_COMPARETO_INTEGER,                                       // int compareTo(Integer anotherInteger)
    NATIVE_LANG_INTEGER_DECODE_STRING,                                           // static Integer decode(String nm)
    NATIVE_LANG_INTEGER_DOUBLEVALUE,                                             // double doubleValue()
    NATIVE_LANG_INTEGER_EQUALS_OBJECT,                                           // boolean equals(Object obj)
    NATIVE_LANG_INTEGER_FLOATVALUE,                                              // float floatValue()
    NATIVE_LANG_INTEGER_GETINTEGER_STRING,                                       // static Integer getInteger(String nm)
    NATIVE_LANG_INTEGER_GETINTEGER_STRING_INT,                                   // static Integer getInteger(String nm, int val)
    NATIVE_LANG_INTEGER_GETINTEGER_STRING_INTEGER,                               // static Integer getInteger(String nm, Integer val)
    NATIVE_LANG_INTEGER_HASHCODE,                                                // int hashCode()
    NATIVE_LANG_INTEGER_HIGHESTONEBIT_INT,                                       // static int highestOneBit(int i)
    NATIVE_LANG_INTEGER_INTVALUE,                                                // int intValue()
    NATIVE_LANG_INTEGER_LONGVALUE,                                               // long longValue()
    NATIVE_LANG_INTEGER_LOWESTONEBIT_INT,                                        // static int lowestOneBit(int i)
    NATIVE_LANG_INTEGER_NUMBEROFLEADINGZEROS_INT,                                // static int numberOfLeadingZeros(int i)
    NATIVE_LANG_INTEGER_NUMBEROFTRAILINGZEROS_INT,                               // static int numberOfTrailingZeros(int i)
    NATIVE_LANG_INTEGER_PARSEINT_STRING,                                         // static int parseInt(String s)
    NATIVE_LANG_INTEGER_PARSEINT_STRING_INT,                                     // static int parseInt(String s, int radix)
    NATIVE_LANG_INTEGER_REVERSE_INT,                                             // static int reverse(int i)
    NATIVE_LANG_INTEGER_REVERSEBYTES_INT,                                        // static int reverseBytes(int i)
    NATIVE_LANG_INTEGER_ROTATELEFT_INT_INT,                                      // static int rotateLeft(int i, int distance)
    NATIVE_LANG_INTEGER_ROTATERIGHT_INT_INT,                                     // static int rotateRight(int i, int distance)
    NATIVE_LANG_INTEGER_SHORTVALUE,                                              // short shortValue()
    NATIVE_LANG_INTEGER_SIGNUM_INT,                                              // static int signum(int i)
    NATIVE_LANG_INTEGER_TOBINARYSTRING_INT,                                      // static String toBinaryString(int i)
    NATIVE_LANG_INTEGER_TOHEXSTRING_INT,                                         // static String toHexString(int i)
    NATIVE_LANG_INTEGER_TOOCTALSTRING_INT,                                       // static String toOctalString(int i)
    NATIVE_LANG_INTEGER_TOSTRING,                                                // String toString()
    NATIVE_LANG_INTEGER_TOSTRING_INT,                                            // static String toString(int i)
    NATIVE_LANG_INTEGER_TOSTRING_INT_INT,                                        // static String toString(int i, int radix)
    NATIVE_LANG_INTEGER_VALUEOF_INT,                                             // static Integer valueOf(int i)
    NATIVE_LANG_INTEGER_VALUEOF_STRING,                                          // static Integer valueOf(String s)
    NATIVE_LANG_INTEGER_VALUEOF_STRING_INT,                                      // static Integer valueOf(String s, int radix)
};

///////////////////////////////////////////////////////////////////////////

object_t native_lang_integer_new( void );
void native_lang_integer_get_field(uint16_t mref);
void native_lang_integer_invoke(uint16_t mref);

uint32_t native_lang_integer_get_superclass( void );

///////////////////////////////////////////////////////////////////////////

#ifdef	__cplusplus
}
#endif

#endif // NATIVE_LANG_INTEGER_H


