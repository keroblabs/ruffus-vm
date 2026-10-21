#ifndef NATIVE_LANG_FLOAT_H
#define NATIVE_LANG_FLOAT_H

#ifdef	__cplusplus
extern "C" {
#endif

///////////////////////////////////////////////////////////////////////////

#include "datatypes.h"

///////////////////////////////////////////////////////////////////////////

// Class field implementation: LANG_FLOAT_ENUM
enum
{
    NATIVE_FIELD_LANG_FLOAT_DUMMY,
    NATIVE_LANG_FLOAT_TOTAL_FIELDS
};

enum
{
    NATIVE_FIELD_LANG_FLOAT_MAX_EXPONENT,                                        // static int MAX_EXPONENT
    NATIVE_FIELD_LANG_FLOAT_MAX_VALUE,                                           // static float MAX_VALUE
    NATIVE_FIELD_LANG_FLOAT_MIN_EXPONENT,                                        // static int MIN_EXPONENT
    NATIVE_FIELD_LANG_FLOAT_MIN_NORMAL,                                          // static float MIN_NORMAL
    NATIVE_FIELD_LANG_FLOAT_MIN_VALUE,                                           // static float MIN_VALUE
    NATIVE_FIELD_LANG_FLOAT_NAN,                                                 // static float NaN
    NATIVE_FIELD_LANG_FLOAT_NEGATIVE_INFINITY,                                   // static float NEGATIVE_INFINITY
    NATIVE_FIELD_LANG_FLOAT_POSITIVE_INFINITY,                                   // static float POSITIVE_INFINITY
    NATIVE_FIELD_LANG_FLOAT_SIZE,                                                // static int SIZE
};

enum
{
    NATIVE_LANG_FLOAT_INIT_DOUBLE,                                               // Float(double value)
    NATIVE_LANG_FLOAT_INIT_FLOAT,                                                // Float(float value)
    NATIVE_LANG_FLOAT_INIT_STRING,                                               // Float(String s)

    NATIVE_LANG_FLOAT_BYTEVALUE,                                                 // byte byteValue()
    NATIVE_LANG_FLOAT_COMPARE_FLOAT_FLOAT,                                       // static int compare(float f1, float f2)
    NATIVE_LANG_FLOAT_COMPARETO_FLOAT,                                           // int compareTo(Float anotherFloat)
    NATIVE_LANG_FLOAT_DOUBLEVALUE,                                               // double doubleValue()
    NATIVE_LANG_FLOAT_EQUALS_OBJECT,                                             // boolean equals(Object obj)
    NATIVE_LANG_FLOAT_FLOATTOINTBITS_FLOAT,                                      // static int floatToIntBits(float value)
    NATIVE_LANG_FLOAT_FLOATTORAWINTBITS_FLOAT,                                   // static int floatToRawIntBits(float value)
    NATIVE_LANG_FLOAT_FLOATVALUE,                                                // float floatValue()
    NATIVE_LANG_FLOAT_HASHCODE,                                                  // int hashCode()
    NATIVE_LANG_FLOAT_INTBITSTOFLOAT_INT,                                        // static float intBitsToFloat(int bits)
    NATIVE_LANG_FLOAT_INTVALUE,                                                  // int intValue()
    NATIVE_LANG_FLOAT_ISINFINITE,                                                // boolean isInfinite()
    NATIVE_LANG_FLOAT_ISINFINITE_FLOAT,                                          // static boolean isInfinite(float v)
    NATIVE_LANG_FLOAT_ISNAN,                                                     // boolean isNaN()
    NATIVE_LANG_FLOAT_ISNAN_FLOAT,                                               // static boolean isNaN(float v)
    NATIVE_LANG_FLOAT_LONGVALUE,                                                 // long longValue()
    NATIVE_LANG_FLOAT_PARSEFLOAT_STRING,                                         // static float parseFloat(String s)
    NATIVE_LANG_FLOAT_SHORTVALUE,                                                // short shortValue()
    NATIVE_LANG_FLOAT_TOHEXSTRING_FLOAT,                                         // static String toHexString(float f)
    NATIVE_LANG_FLOAT_TOSTRING,                                                  // String toString()
    NATIVE_LANG_FLOAT_TOSTRING_FLOAT,                                            // static String toString(float f)
    NATIVE_LANG_FLOAT_VALUEOF_FLOAT,                                             // static Float valueOf(float f)
    NATIVE_LANG_FLOAT_VALUEOF_STRING,                                            // static Float valueOf(String s)
};

///////////////////////////////////////////////////////////////////////////

object_t native_lang_float_new( void );
void native_lang_float_get_field(uint16_t mref);
void native_lang_float_invoke(uint16_t mref);

uint32_t native_lang_float_get_superclass( void );

///////////////////////////////////////////////////////////////////////////

#ifdef	__cplusplus
}
#endif

#endif // NATIVE_LANG_FLOAT_H


