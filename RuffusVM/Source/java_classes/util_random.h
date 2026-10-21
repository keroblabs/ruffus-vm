#ifndef NATIVE_UTIL_RANDOM_H
#define NATIVE_UTIL_RANDOM_H

#ifdef	__cplusplus
extern "C" {
#endif

///////////////////////////////////////////////////////////////////////////

#include "datatypes.h"

///////////////////////////////////////////////////////////////////////////

// Class field implementation: UTIL_RANDOM_ENUM
enum
{
    NATIVE_FIELD_UTIL_RANDOM_SEED,
    NATIVE_UTIL_RANDOM_TOTAL_FIELDS
};

enum
{

    NATIVE_UTIL_RANDOM_INIT,                                                     // Random()
    NATIVE_UTIL_RANDOM_INIT_LONG,                                                // Random(long seed)

    NATIVE_UTIL_RANDOM_NEXT_INT,                                                 // protected  int next(int bits)
    NATIVE_UTIL_RANDOM_NEXTBOOLEAN,                                              // boolean nextBoolean()
    NATIVE_UTIL_RANDOM_NEXTBYTES_ARRAY_BYTE,                                     // void nextBytes(byte[] bytes)
    NATIVE_UTIL_RANDOM_NEXTDOUBLE,                                               // double nextDouble()
    NATIVE_UTIL_RANDOM_NEXTFLOAT,                                                // float nextFloat()
    NATIVE_UTIL_RANDOM_NEXTGAUSSIAN,                                             // double nextGaussian()
    NATIVE_UTIL_RANDOM_NEXTINT,                                                  // int nextInt()
    NATIVE_UTIL_RANDOM_NEXTINT_INT,                                              // int nextInt(int n)
    NATIVE_UTIL_RANDOM_NEXTLONG,                                                 // long nextLong()
    NATIVE_UTIL_RANDOM_SETSEED_LONG,                                             // void setSeed(long seed)
};

///////////////////////////////////////////////////////////////////////////

object_t native_util_random_new( void );
void native_util_random_get_field(uint16_t mref);
void native_util_random_invoke(uint16_t mref);

///////////////////////////////////////////////////////////////////////////

#ifdef	__cplusplus
}
#endif

#endif // NATIVE_UTIL_RANDOM_H


