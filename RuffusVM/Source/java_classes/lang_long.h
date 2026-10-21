#ifndef NATIVE_LANG_LONG_H
#define NATIVE_LANG_LONG_H

#ifdef	__cplusplus
extern "C" {
#endif

///////////////////////////////////////////////////////////////////////////

#include "datatypes.h"

///////////////////////////////////////////////////////////////////////////

// Class field implementation: LANG_LONG_ENUM
enum
{
    NATIVE_FIELD_LANG_LONG_DUMMY,
    NATIVE_LANG_LONG_TOTAL_FIELDS
};

enum
{
    NATIVE_FIELD_LANG_LONG_MAX_VALUE,                                            // static long MAX_VALUE
    NATIVE_FIELD_LANG_LONG_MIN_VALUE,                                            // static long MIN_VALUE
    NATIVE_FIELD_LANG_LONG_SIZE,                                                 // static int SIZE
};

enum
{
    NATIVE_LANG_LONG_INIT_LONG,                                                  // Long(long value)
    NATIVE_LANG_LONG_INIT_STRING,                                                // Long(String s)

    NATIVE_LANG_LONG_BITCOUNT_LONG,                                              // static int bitCount(long i)
    NATIVE_LANG_LONG_BYTEVALUE,                                                  // byte byteValue()
    NATIVE_LANG_LONG_COMPARETO_LONG,                                             // int compareTo(Long anotherLong)
    NATIVE_LANG_LONG_DECODE_STRING,                                              // static Long decode(String nm)
    NATIVE_LANG_LONG_DOUBLEVALUE,                                                // double doubleValue()
    NATIVE_LANG_LONG_EQUALS_OBJECT,                                              // boolean equals(Object obj)
    NATIVE_LANG_LONG_FLOATVALUE,                                                 // float floatValue()
    NATIVE_LANG_LONG_GETLONG_STRING,                                             // static Long getLong(String nm)
    NATIVE_LANG_LONG_GETLONG_STRING_LONG,                                        // static Long getLong(String nm, Long val)
    NATIVE_LANG_LONG_HASHCODE,                                                   // int hashCode()
    NATIVE_LANG_LONG_HIGHESTONEBIT_LONG,                                         // static long highestOneBit(long i)
    NATIVE_LANG_LONG_INTVALUE,                                                   // int intValue()
    NATIVE_LANG_LONG_LONGVALUE,                                                  // long longValue()
    NATIVE_LANG_LONG_LOWESTONEBIT_LONG,                                          // static long lowestOneBit(long i)
    NATIVE_LANG_LONG_NUMBEROFLEADINGZEROS_LONG,                                  // static int numberOfLeadingZeros(long i)
    NATIVE_LANG_LONG_NUMBEROFTRAILINGZEROS_LONG,                                 // static int numberOfTrailingZeros(long i)
    NATIVE_LANG_LONG_PARSELONG_STRING,                                           // static long parseLong(String s)
    NATIVE_LANG_LONG_PARSELONG_STRING_INT,                                       // static long parseLong(String s, int radix)
    NATIVE_LANG_LONG_REVERSE_LONG,                                               // static long reverse(long i)
    NATIVE_LANG_LONG_REVERSEBYTES_LONG,                                          // static long reverseBytes(long i)
    NATIVE_LANG_LONG_ROTATELEFT_LONG_INT,                                        // static long rotateLeft(long i, int distance)
    NATIVE_LANG_LONG_ROTATERIGHT_LONG_INT,                                       // static long rotateRight(long i, int distance)
    NATIVE_LANG_LONG_SHORTVALUE,                                                 // short shortValue()
    NATIVE_LANG_LONG_SIGNUM_LONG,                                                // static int signum(long i)
    NATIVE_LANG_LONG_TOBINARYSTRING_LONG,                                        // static String toBinaryString(long i)
    NATIVE_LANG_LONG_TOHEXSTRING_LONG,                                           // static String toHexString(long i)
    NATIVE_LANG_LONG_TOOCTALSTRING_LONG,                                         // static String toOctalString(long i)
    NATIVE_LANG_LONG_TOSTRING,                                                   // String toString()
    NATIVE_LANG_LONG_TOSTRING_LONG,                                              // static String toString(long i)
    NATIVE_LANG_LONG_TOSTRING_LONG_INT,                                          // static String toString(long i, int radix)
    NATIVE_LANG_LONG_VALUEOF_LONG,                                               // static Long valueOf(long l)
    NATIVE_LANG_LONG_VALUEOF_STRING,                                             // static Long valueOf(String s)
    NATIVE_LANG_LONG_VALUEOF_STRING_INT,                                         // static Long valueOf(String s, int radix)
};

///////////////////////////////////////////////////////////////////////////

object_t native_lang_long_new( void );
void native_lang_long_get_field(uint16_t mref);
void native_lang_long_invoke(uint16_t mref);

uint32_t native_lang_long_get_superclass( void );

///////////////////////////////////////////////////////////////////////////

#ifdef	__cplusplus
}
#endif

#endif // NATIVE_LANG_LONG_H


