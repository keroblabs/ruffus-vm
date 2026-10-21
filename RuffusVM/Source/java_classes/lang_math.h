#ifndef NATIVE_LANG_MATH_H
#define NATIVE_LANG_MATH_H

#ifdef	__cplusplus
extern "C" {
#endif

///////////////////////////////////////////////////////////////////////////

#include "datatypes.h"

///////////////////////////////////////////////////////////////////////////

// Class field implementation: LANG_MATH_ENUM
enum
{
    NATIVE_FIELD_LANG_MATH_DUMMY,
    NATIVE_LANG_MATH_TOTAL_FIELDS
};

enum
{
    NATIVE_FIELD_LANG_MATH_E,                                                    // static double E
    NATIVE_FIELD_LANG_MATH_PI,                                                   // static double PI
};

enum
{
    NATIVE_LANG_MATH_ABS_DOUBLE,                                                 // static double abs(double a)
    NATIVE_LANG_MATH_ABS_FLOAT,                                                  // static float abs(float a)
    NATIVE_LANG_MATH_ABS_INT,                                                    // static int abs(int a)
    NATIVE_LANG_MATH_ABS_LONG,                                                   // static long abs(long a)
    NATIVE_LANG_MATH_ACOS_DOUBLE,                                                // static double acos(double a)
    NATIVE_LANG_MATH_ASIN_DOUBLE,                                                // static double asin(double a)
    NATIVE_LANG_MATH_ATAN_DOUBLE,                                                // static double atan(double a)
    NATIVE_LANG_MATH_ATAN2_DOUBLE_DOUBLE,                                        // static double atan2(double y, double x)
    NATIVE_LANG_MATH_CBRT_DOUBLE,                                                // static double cbrt(double a)
    NATIVE_LANG_MATH_CEIL_DOUBLE,                                                // static double ceil(double a)
    NATIVE_LANG_MATH_COPYSIGN_DOUBLE_DOUBLE,                                     // static double copySign(double magnitude, double sign)
    NATIVE_LANG_MATH_COPYSIGN_FLOAT_FLOAT,                                       // static float copySign(float magnitude, float sign)
    NATIVE_LANG_MATH_COS_DOUBLE,                                                 // static double cos(double a)
    NATIVE_LANG_MATH_COSH_DOUBLE,                                                // static double cosh(double x)
    NATIVE_LANG_MATH_EXP_DOUBLE,                                                 // static double exp(double a)
    NATIVE_LANG_MATH_EXPM1_DOUBLE,                                               // static double expm1(double x)
    NATIVE_LANG_MATH_FLOOR_DOUBLE,                                               // static double floor(double a)
    NATIVE_LANG_MATH_GETEXPONENT_DOUBLE,                                         // static int getExponent(double d)
    NATIVE_LANG_MATH_GETEXPONENT_FLOAT,                                          // static int getExponent(float f)
    NATIVE_LANG_MATH_HYPOT_DOUBLE_DOUBLE,                                        // static double hypot(double x, double y)
    NATIVE_LANG_MATH_IEEEREMAINDER_DOUBLE_DOUBLE,                                // static double IEEEremainder(double f1, double f2)
    NATIVE_LANG_MATH_LOG_DOUBLE,                                                 // static double log(double a)
    NATIVE_LANG_MATH_LOG10_DOUBLE,                                               // static double log10(double a)
    NATIVE_LANG_MATH_LOG1P_DOUBLE,                                               // static double log1p(double x)
    NATIVE_LANG_MATH_MAX_DOUBLE_DOUBLE,                                          // static double max(double a, double b)
    NATIVE_LANG_MATH_MAX_FLOAT_FLOAT,                                            // static float max(float a, float b)
    NATIVE_LANG_MATH_MAX_INT_INT,                                                // static int max(int a, int b)
    NATIVE_LANG_MATH_MAX_LONG_LONG,                                              // static long max(long a, long b)
    NATIVE_LANG_MATH_MIN_DOUBLE_DOUBLE,                                          // static double min(double a, double b)
    NATIVE_LANG_MATH_MIN_FLOAT_FLOAT,                                            // static float min(float a, float b)
    NATIVE_LANG_MATH_MIN_INT_INT,                                                // static int min(int a, int b)
    NATIVE_LANG_MATH_MIN_LONG_LONG,                                              // static long min(long a, long b)
    NATIVE_LANG_MATH_NEXTAFTER_DOUBLE_DOUBLE,                                    // static double nextAfter(double start, double direction)
    NATIVE_LANG_MATH_NEXTAFTER_FLOAT_DOUBLE,                                     // static float nextAfter(float start, double direction)
    NATIVE_LANG_MATH_NEXTUP_DOUBLE,                                              // static double nextUp(double d)
    NATIVE_LANG_MATH_NEXTUP_FLOAT,                                               // static float nextUp(float f)
    NATIVE_LANG_MATH_POW_DOUBLE_DOUBLE,                                          // static double pow(double a, double b)
    NATIVE_LANG_MATH_RANDOM,                                                     // static double random()
    NATIVE_LANG_MATH_RINT_DOUBLE,                                                // static double rint(double a)
    NATIVE_LANG_MATH_ROUND_DOUBLE,                                               // static long round(double a)
    NATIVE_LANG_MATH_ROUND_FLOAT,                                                // static int round(float a)
    NATIVE_LANG_MATH_SCALB_DOUBLE_INT,                                           // static double scalb(double d, int scaleFactor)
    NATIVE_LANG_MATH_SCALB_FLOAT_INT,                                            // static float scalb(float f, int scaleFactor)
    NATIVE_LANG_MATH_SIGNUM_DOUBLE,                                              // static double signum(double d)
    NATIVE_LANG_MATH_SIGNUM_FLOAT,                                               // static float signum(float f)
    NATIVE_LANG_MATH_SIN_DOUBLE,                                                 // static double sin(double a)
    NATIVE_LANG_MATH_SINH_DOUBLE,                                                // static double sinh(double x)
    NATIVE_LANG_MATH_SQRT_DOUBLE,                                                // static double sqrt(double a)
    NATIVE_LANG_MATH_TAN_DOUBLE,                                                 // static double tan(double a)
    NATIVE_LANG_MATH_TANH_DOUBLE,                                                // static double tanh(double x)
    NATIVE_LANG_MATH_TODEGREES_DOUBLE,                                           // static double toDegrees(double angrad)
    NATIVE_LANG_MATH_TORADIANS_DOUBLE,                                           // static double toRadians(double angdeg)
    NATIVE_LANG_MATH_ULP_DOUBLE,                                                 // static double ulp(double d)
    NATIVE_LANG_MATH_ULP_FLOAT,                                                  // static float ulp(float f)
};

///////////////////////////////////////////////////////////////////////////

object_t native_lang_math_new( void );
void native_lang_math_get_field(uint16_t mref);
void native_lang_math_invoke(uint16_t mref);

uint32_t native_lang_math_get_superclass( void );

///////////////////////////////////////////////////////////////////////////

#ifdef	__cplusplus
}
#endif

#endif // NATIVE_LANG_MATH_H


