#ifndef NATIVE_LANG_DOUBLE_H
#define NATIVE_LANG_DOUBLE_H

#ifdef	__cplusplus
extern "C" {
#endif

///////////////////////////////////////////////////////////////////////////

#include "datatypes.h"

///////////////////////////////////////////////////////////////////////////

// Class field implementation: LANG_DOUBLE_ENUM
enum
{
    NATIVE_FIELD_LANG_DOUBLE_DUMMY,
    NATIVE_LANG_DOUBLE_TOTAL_FIELDS
};

enum
{
    NATIVE_FIELD_LANG_DOUBLE_MAX_EXPONENT,                                       // static int MAX_EXPONENT
    NATIVE_FIELD_LANG_DOUBLE_MAX_VALUE,                                          // static double MAX_VALUE
    NATIVE_FIELD_LANG_DOUBLE_MIN_EXPONENT,                                       // static int MIN_EXPONENT
    NATIVE_FIELD_LANG_DOUBLE_MIN_NORMAL,                                         // static double MIN_NORMAL
    NATIVE_FIELD_LANG_DOUBLE_MIN_VALUE,                                          // static double MIN_VALUE
    NATIVE_FIELD_LANG_DOUBLE_NAN,                                                // static double NaN
    NATIVE_FIELD_LANG_DOUBLE_NEGATIVE_INFINITY,                                  // static double NEGATIVE_INFINITY
    NATIVE_FIELD_LANG_DOUBLE_POSITIVE_INFINITY,                                  // static double POSITIVE_INFINITY
    NATIVE_FIELD_LANG_DOUBLE_SIZE,                                               // static int SIZE
};

enum
{
    NATIVE_LANG_DOUBLE_INIT_DOUBLE,                                              // Double(double value)
    NATIVE_LANG_DOUBLE_INIT_STRING,                                              // Double(String s)

    NATIVE_LANG_DOUBLE_BYTEVALUE,                                                // byte byteValue()
    NATIVE_LANG_DOUBLE_COMPARE_DOUBLE_DOUBLE,                                    // static int compare(double d1, double d2)
    NATIVE_LANG_DOUBLE_COMPARETO_DOUBLE,                                         // int compareTo(Double anotherDouble)
    NATIVE_LANG_DOUBLE_DOUBLETOLONGBITS_DOUBLE,                                  // static long doubleToLongBits(double value)
    NATIVE_LANG_DOUBLE_DOUBLETORAWLONGBITS_DOUBLE,                               // static long doubleToRawLongBits(double value)
    NATIVE_LANG_DOUBLE_DOUBLEVALUE,                                              // double doubleValue()
    NATIVE_LANG_DOUBLE_EQUALS_OBJECT,                                            // boolean equals(Object obj)
    NATIVE_LANG_DOUBLE_FLOATVALUE,                                               // float floatValue()
    NATIVE_LANG_DOUBLE_HASHCODE,                                                 // int hashCode()
    NATIVE_LANG_DOUBLE_INTVALUE,                                                 // int intValue()
    NATIVE_LANG_DOUBLE_ISINFINITE,                                               // boolean isInfinite()
    NATIVE_LANG_DOUBLE_ISINFINITE_DOUBLE,                                        // static boolean isInfinite(double v)
    NATIVE_LANG_DOUBLE_ISNAN,                                                    // boolean isNaN()
    NATIVE_LANG_DOUBLE_ISNAN_DOUBLE,                                             // static boolean isNaN(double v)
    NATIVE_LANG_DOUBLE_LONGBITSTODOUBLE_LONG,                                    // static double longBitsToDouble(long bits)
    NATIVE_LANG_DOUBLE_LONGVALUE,                                                // long longValue()
    NATIVE_LANG_DOUBLE_PARSEDOUBLE_STRING,                                       // static double parseDouble(String s)
    NATIVE_LANG_DOUBLE_SHORTVALUE,                                               // short shortValue()
    NATIVE_LANG_DOUBLE_TOHEXSTRING_DOUBLE,                                       // static String toHexString(double d)
    NATIVE_LANG_DOUBLE_TOSTRING,                                                 // String toString()
    NATIVE_LANG_DOUBLE_TOSTRING_DOUBLE,                                          // static String toString(double d)
    NATIVE_LANG_DOUBLE_VALUEOF_DOUBLE,                                           // static Double valueOf(double d)
    NATIVE_LANG_DOUBLE_VALUEOF_STRING,                                           // static Double valueOf(String s)
};

///////////////////////////////////////////////////////////////////////////

object_t native_lang_double_new( void );
void native_lang_double_get_field(uint16_t mref);
void native_lang_double_invoke(uint16_t mref);

uint32_t native_lang_double_get_superclass( void );

///////////////////////////////////////////////////////////////////////////

#ifdef	__cplusplus
}
#endif

#endif // NATIVE_LANG_DOUBLE_H


