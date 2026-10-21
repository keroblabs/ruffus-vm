#include "lang_math.h"
#include "heap.h"
#include "application.h"
#include "threads.h"
#include "exceptions.h"
#include "native.h"
#include "objects.h"
#include "stack.h"
#include "value_type.h"
#include "strings.h"
#include <math.h>

///////////////////////////////////////////////////////////////////////////

// use New method implementation to hold a method
// use New implementation to mark start block
// use End new implementation to mark end block to keep

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////

// static double E
#define NATIVE_FIELD_VALUE_LANG_MATH_E                                           2.71828182

// static double PI
#define NATIVE_FIELD_VALUE_LANG_MATH_PI                                          3.14159265

///////////////////////////////////////////////////////////////////////////

object_t native_lang_math_new( void )
{
    return( object_create( GET_CLASS_REF( NATIVE_CLASS_LANG_MATH ), T_CLASS, NATIVE_LANG_MATH_TOTAL_FIELDS ) );
}

///////////////////////////////////////////////////////////////////////////

void native_method_lang_math_abs_double( void )
{
    // static double abs(double a)
    // Returns the absolute value of a double value. 
    // Implementation code: 9DE3F209
    object_t double_a;
    double ret_value = 0.0;

    double_a = stack_pop();

    // put your code here
    ret_value = value_get_double( double_a );
	if( ret_value < 0 ) ret_value *= -1;

    // return type: double
    stack_push_double( ret_value );
}

void native_method_lang_math_abs_float( void )
{
    // static float abs(float a)
    // Returns the absolute value of a float value. 
    // Implementation code: F297E7E0
    object_t float_a;
    float ret_value = 0.0;

    float_a = stack_pop();

    // put your code here
    ret_value = value_get_float( float_a );
	if( ret_value < 0 ) ret_value *= -1;

    // return type: float
    stack_push_float( ret_value );
}

void native_method_lang_math_abs_int( void )
{
    // static int abs(int a)
    // Returns the absolute value of an int value. 
    // Implementation code: A01615BA
    object_t int_a;
    int32_t ret_value = 0;

    int_a = stack_pop();

    // put your code here
    ret_value = value_get_int( int_a );
	if( ret_value < 0 ) ret_value *= -1;

    // return type: int
    stack_push_integer( ret_value );
}

void native_method_lang_math_abs_long( void )
{
    // static long abs(long a)
    // Returns the absolute value of a long value. 
    // Implementation code: 40CE686A
    object_t long_a;
    int64_t ret_value = 0L;

    long_a = stack_pop();

    // put your code here
    ret_value = value_get_long( long_a );
	if( ret_value < 0 ) ret_value *= -1;

    // return type: long
    stack_push_long( ret_value );
}

void native_method_lang_math_acos_double( void )
{
    // static double acos(double a)
    // Returns the arc cosine of a value; the returned angle is 
    // in the range 0.0 through pi. 
    // Implementation code: 9DC35385
    object_t double_a;
    double ret_value = 0.0;

    double_a = stack_pop();

    // put your code here
    ret_value = acos( value_get_double( double_a ) );

    // return type: double
    stack_push_double( ret_value );
}

void native_method_lang_math_asin_double( void )
{
    // static double asin(double a)
    // Returns the arc sine of a value; the returned angle is in 
    // the range -pi/2 through pi/2. 
    // Implementation code: A6BDB133
    object_t double_a;
    double ret_value = 0.0;

    double_a = stack_pop();

    // put your code here
    ret_value = asin( value_get_double( double_a ) );

    // return type: double
    stack_push_double( ret_value );
}

void native_method_lang_math_atan_double( void )
{
    // static double atan(double a)
    // Returns the arc tangent of a value; the returned angle is 
    // in the range -pi/2 through pi/2. 
    // Implementation code: 5F42EA5C
    object_t double_a;
    double ret_value = 0.0;

    double_a = stack_pop();

    // put your code here
    ret_value = atan( value_get_double( double_a ) );

    // return type: double
    stack_push_double( ret_value );
}

void native_method_lang_math_atan2_double_double( void )
{
    // static double atan2(double y, double x)
    // Returns the angle theta from the conversion of rectangular 
    // coordinates (x, y) to polar coordinates (r, theta). 
    // Implementation code: C417453F
    object_t double_y;
    object_t double_x;
    double ret_value = 0.0;

    double_x = stack_pop();
    double_y = stack_pop();

    // put your code here
    ret_value = atan2( value_get_double( double_y ), value_get_double( double_x ) );

    // return type: double
    stack_push_double( ret_value );
}

void native_method_lang_math_cbrt_double( void )
{
    // static double cbrt(double a)
    // Returns the cube root of a double value. 
    // Implementation code: 3A63483A
    object_t double_a;
    double ret_value = 0.0;

    double_a = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: double
    stack_push_double( ret_value );
}

void native_method_lang_math_ceil_double( void )
{
    // static double ceil(double a)
    // Returns the smallest (closest to negative infinity) double 
    // value that is greater than or equal to the argument and 
    // is equal to a mathematical integer. 
    // Implementation code: 60F1FE70
    object_t double_a;
    double ret_value = 0.0;

    double_a = stack_pop();

    // put your code here
    ret_value = ceil( value_get_double( double_a ) );

    // return type: double
    stack_push_double( ret_value );
}

void native_method_lang_math_copysign_double_double( void )
{
    // static double copySign(double magnitude, double sign)
    // Returns the first floating-point argument with the sign 
    // of the second floating-point argument. 
    // Implementation code: 1EAA3549
    object_t double_magnitude;
    object_t double_sign;
    double ret_value = 0.0;

    double_sign = stack_pop();
    double_magnitude = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: double
    stack_push_double( ret_value );
}

void native_method_lang_math_copysign_float_float( void )
{
    // static float copySign(float magnitude, float sign)
    // Returns the first floating-point argument with the sign 
    // of the second floating-point argument. 
    // Implementation code: 1EAA3549
    object_t double_magnitude;
    object_t double_sign;
    double ret_value = 0.0;

    double_sign = stack_pop();
    double_magnitude = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: double
    stack_push_double( ret_value );
}

void native_method_lang_math_cos_double( void )
{
    // static double cos(double a)
    // Returns the trigonometric cosine of an angle. 
    // Implementation code: 72254698
    object_t double_a;
    double ret_value = 0.0;

    double_a = stack_pop();

    // put your code here
    ret_value = cos( value_get_double( double_a ) );

    // return type: double
    stack_push_double( ret_value );
}

void native_method_lang_math_cosh_double( void )
{
    // static double cosh(double x)
    // Returns the hyperbolic cosine of a double value. 
    // Implementation code: 43561CF9
    object_t double_x;
    double ret_value = 0.0;

    double_x = stack_pop();

    // put your code here
    ret_value = cosh( value_get_double( double_x ) );

    // return type: double
    stack_push_double( ret_value );
}

void native_method_lang_math_exp_double( void )
{
    // static double exp(double a)
    // Returns Euler's number e raised to the power of a double 
    // value. 
    // Implementation code: 95B7314B
    object_t double_a;
    double ret_value = 0.0;

    double_a = stack_pop();

    // put your code here
    ret_value = exp( value_get_double( double_a ) );

    // return type: double
    stack_push_double( ret_value );
}

void native_method_lang_math_expm1_double( void )
{
    // static double expm1(double x)
    // Returns ex -1. 
    // Implementation code: C0143143
    object_t double_x;
    double ret_value = 0.0;

    double_x = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: double
    stack_push_double( ret_value );
}

void native_method_lang_math_floor_double( void )
{
    // static double floor(double a)
    // Returns the largest (closest to positive infinity) double 
    // value that is less than or equal to the argument and is 
    // equal to a mathematical integer. 
    // Implementation code: 902AEF37
    object_t double_a;
    double ret_value = 0.0;

    double_a = stack_pop();

    // put your code here
    ret_value = floor( value_get_double( double_a ) );

    // return type: double
    stack_push_double( ret_value );
}

void native_method_lang_math_getexponent_double( void )
{
    // static int getExponent(double d)
    // Returns the unbiased exponent used in the representation 
    // of a double. 
    // Implementation code: FE386A95
    object_t double_d;
    int32_t ret_value = 0;

    double_d = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push_integer( ret_value );
}

void native_method_lang_math_getexponent_float( void )
{
    // static int getExponent(float f)
    // Returns the unbiased exponent used in the representation 
    // of a float. 
    // Implementation code: E6B311D7
    object_t float_f;
    int32_t ret_value = 0;

    float_f = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push_integer( ret_value );
}

void native_method_lang_math_hypot_double_double( void )
{
    // static double hypot(double x, double y)
    // Returns sqrt(x2 +y2) without intermediate overflow or underflow. 
    // Implementation code: FD07523E
    object_t double_x;
    object_t double_y;
    double ret_value = 0.0;

    double_y = stack_pop();
    double_x = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: double
    stack_push_double( ret_value );
}

void native_method_lang_math_ieeeremainder_double_double( void )
{
    // static double IEEEremainder(double f1, double f2)
    // Computes the remainder operation on two arguments as prescribed 
    // by the IEEE 754 standard. 
    // Implementation code: FD9A0B1E
    object_t double_f1;
    object_t double_f2;
    double ret_value = 0.0;

    double_f2 = stack_pop();
    double_f1 = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: double
    stack_push_double( ret_value );
}

void native_method_lang_math_log_double( void )
{
    // static double log(double a)
    // Returns the natural logarithm (base e) of a double value. 
    // Implementation code: 348CF9D6
    object_t double_a;
    double ret_value = 0.0;

    double_a = stack_pop();

    // put your code here
    ret_value = log( value_get_double( double_a ) );

    // return type: double
    stack_push_double( ret_value );
}

void native_method_lang_math_log10_double( void )
{
    // static double log10(double a)
    // Returns the base 10 logarithm of a double value. 
    // Implementation code: 723B0BAB
    object_t double_a;
    double ret_value = 0.0;

    double_a = stack_pop();

    // put your code here
    ret_value = log10( value_get_double( double_a ) );

    // return type: double
    stack_push_double( ret_value );
}

void native_method_lang_math_log1p_double( void )
{
    // static double log1p(double x)
    // Returns the natural logarithm of the sum of the argument 
    // and 1. 
    // Implementation code: F8CDCBC0
    object_t double_x;
    double ret_value = 0.0;

    double_x = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: double
    stack_push_double( ret_value );
}

void native_method_lang_math_max_double_double( void )
{
    // static double max(double a, double b)
    // Returns the greater of two double values. 
    // Implementation code: 913F0E74
    object_t double_a;
    object_t double_b;
    double ret_value = 0.0;
    double temp = 0.0;

    double_b = stack_pop();
    double_a = stack_pop();

    // put your code here
    ret_value = value_get_double( double_a );
	temp = value_get_double( double_b );
	if( ret_value < temp ) ret_value = temp;

    // return type: double
    stack_push_double( ret_value );
}

void native_method_lang_math_max_float_float( void )
{
    // static float max(float a, float b)
    // Returns the greater of two float values. 
    // Implementation code: 1837B6EB
    object_t float_a;
    object_t float_b;
    float ret_value = 0.0;
	float temp = 0.0;

    float_b = stack_pop();
    float_a = stack_pop();

    // put your code here
    ret_value = value_get_float( float_a );
	temp = value_get_float( float_b );
	if( ret_value < temp ) ret_value = temp;

    // return type: float
    stack_push_float( ret_value );
}

void native_method_lang_math_max_int_int( void )
{
    // static int max(int a, int b)
    // Returns the greater of two int values. 
    // Implementation code: E7127D84
    object_t int_a;
    object_t int_b;
    int32_t ret_value = 0;
	int32_t temp = 0;

    int_b = stack_pop();
    int_a = stack_pop();

    // put your code here
    ret_value = value_get_int( int_a );
	temp = value_get_int( int_b );
	if( ret_value < temp ) ret_value = temp;

    // return type: int
    stack_push_integer( ret_value );
}

void native_method_lang_math_max_long_long( void )
{
    // static long max(long a, long b)
    // Returns the greater of two long values. 
    // Implementation code: 63FF87B0
    object_t long_a;
    object_t long_b;
    int64_t ret_value = 0L;
	int64_t temp = 0;

    long_b = stack_pop();
    long_a = stack_pop();

    // put your code here
    ret_value = value_get_long( long_a );
	temp = value_get_long( long_b );
	if( ret_value < temp ) ret_value = temp;

    // return type: long
    stack_push_long( ret_value );
}

void native_method_lang_math_min_double_double( void )
{
    // static double min(double a, double b)
    // Returns the smaller of two double values. 
    // Implementation code: 58FCBC22
    object_t double_a;
    object_t double_b;
    double ret_value = 0.0;
	double temp = 0.0;

    double_b = stack_pop();
    double_a = stack_pop();

    // put your code here
    ret_value = value_get_double( double_a );
	temp = value_get_double( double_b );
	if( ret_value > temp ) ret_value = temp;

    // return type: double
    stack_push_double( ret_value );
}

void native_method_lang_math_min_float_float( void )
{
    // static float min(float a, float b)
    // Returns the smaller of two float values. 
    // Implementation code: 3F446BDB
    object_t float_a;
    object_t float_b;
    float ret_value = 0.0;
	float temp = 0.0;

    float_b = stack_pop();
    float_a = stack_pop();

    // put your code here
    ret_value = value_get_float( float_a );
	temp = value_get_float( float_b );
	if( ret_value > temp ) ret_value = temp;

    // return type: float
    stack_push_float( ret_value );
}

void native_method_lang_math_min_int_int( void )
{
    // static int min(int a, int b)
    // Returns the smaller of two int values. 
    // Implementation code: 74271C4E
    object_t int_a;
    object_t int_b;
    int32_t ret_value = 0;
	int32_t temp = 0;

    int_b = stack_pop();
    int_a = stack_pop();

    // put your code here
    ret_value = value_get_int( int_a );
	temp = value_get_int( int_b );
	if( ret_value > temp ) ret_value = temp;

    // return type: int
    stack_push_integer( ret_value );
}

void native_method_lang_math_min_long_long( void )
{
    // static long min(long a, long b)
    // Returns the smaller of two long values. 
    // Implementation code: F4DE1FC7
    object_t long_a;
    object_t long_b;
    int64_t ret_value = 0L;
	int64_t temp = 0;

    long_b = stack_pop();
    long_a = stack_pop();

    // put your code here
    ret_value = value_get_long( long_a );
	temp = value_get_long( long_b );
	if( ret_value > temp ) ret_value = temp;

    // return type: long
    stack_push_long( ret_value );
}

void native_method_lang_math_nextafter_double_double( void )
{
    // static double nextAfter(double start, double direction)
    // Returns the floating-point number adjacent to the first 
    // argument in the direction of the second argument. 
    // Implementation code: A67AC978
    object_t double_start;
    object_t double_direction;
    double ret_value = 0.0;

    double_direction = stack_pop();
    double_start = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: double
    stack_push_double( ret_value );
}

void native_method_lang_math_nextafter_float_double( void )
{
    // static float nextAfter(float start, double direction)
    // Returns the floating-point number adjacent to the first 
    // argument in the direction of the second argument. 
    // Implementation code: A67AC978
    object_t double_start;
    object_t double_direction;
    double ret_value = 0.0;

    double_direction = stack_pop();
    double_start = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: double
    stack_push_double( ret_value );
}

void native_method_lang_math_nextup_double( void )
{
    // static double nextUp(double d)
    // Returns the floating-point value adjacent to d in the direction 
    // of positive infinity. 
    // Implementation code: C9D1C607
    object_t double_d;
    double ret_value = 0.0;

    double_d = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: double
    stack_push_double( ret_value );
}

void native_method_lang_math_nextup_float( void )
{
    // static float nextUp(float f)
    // Returns the floating-point value adjacent to f in the direction 
    // of positive infinity. 
    // Implementation code: 544AE620
    object_t float_f;
    float ret_value = 0.0;

    float_f = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: float
    stack_push_float( ret_value );
}

void native_method_lang_math_pow_double_double( void )
{
    // static double pow(double a, double b)
    // Returns the value of the first argument raised to the power 
    // of the second argument. 
    // Implementation code: 96EF8DCA
    object_t double_a;
    object_t double_b;
    double ret_value = 0.0;

    double_b = stack_pop();
    double_a = stack_pop();

    // put your code here
    ret_value = pow( value_get_double( double_a ), value_get_double( double_b ) );

    // return type: double
    stack_push_double( ret_value );
}

void native_method_lang_math_random( void )
{
    // static double random()
    // Returns a double value with a positive sign, greater than 
    // or equal to 0.0 and less than 1.0. 
    // Implementation code: 6222C84F
    double ret_value = 0.0;

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: double
    stack_push_double( ret_value );
}

void native_method_lang_math_rint_double( void )
{
    // static double rint(double a)
    // Returns the double value that is closest in value to the 
    // argument and is equal to a mathematical integer. 
    // Implementation code: 92D85CF9
    object_t double_a;
    double ret_value = 0.0;

    double_a = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: double
    stack_push_double( ret_value );
}

void native_method_lang_math_round_double( void )
{
    // static long round(double a)
    // Returns the closest long to the argument. 
    // Implementation code: 918B8DF4
    object_t double_a;
    int64_t ret_value = 0L;

    double_a = stack_pop();

    // put your code here
    ret_value = ( int64_t )value_get_double( double_a );

    // return type: long
    stack_push_long( ret_value );
}

void native_method_lang_math_round_float( void )
{
    // static int round(float a)
    // Returns the closest int to the argument. 
    // Implementation code: E5720A94
    object_t float_a;
    int32_t ret_value = 0;

    float_a = stack_pop();

    // put your code here
    ret_value = ( int32_t )value_get_float( float_a );

    // return type: int
    stack_push_integer( ret_value );
}

void native_method_lang_math_scalb_double_int( void )
{
    // static double scalb(double d, int scaleFactor)
    // Return d � 2scaleFactor rounded as if performed by a single 
    // correctly rounded floating-point multiply to a member of 
    // the double value set. 
    // Implementation code: 2E5FA94B
    object_t double_d;
    object_t int_scalefactor;
    double ret_value = 0.0;

    int_scalefactor = stack_pop();
    double_d = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: double
    stack_push_double( ret_value );
}

void native_method_lang_math_scalb_float_int( void )
{
    // static float scalb(float f, int scaleFactor)
    // Return f � 2scaleFactor rounded as if performed by a single 
    // correctly rounded floating-point multiply to a member of 
    // the float value set. 
    // Implementation code: 0F41A0CB
    object_t float_f;
    object_t int_scalefactor;
    float ret_value = 0.0;

    int_scalefactor = stack_pop();
    float_f = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: float
    stack_push_float( ret_value );
}

void native_method_lang_math_signum_double( void )
{
    // static double signum(double d)
    // Returns the signum function of the argument; zero if the 
    // argument is zero, 1.0 if the argument is greater than zero, 
    // -1.0 if the argument is less than zero. 
    // Implementation code: 98BCEADC
    object_t double_d;
    double ret_value = 0.0;

    double_d = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: double
    stack_push_double( ret_value );
}

void native_method_lang_math_signum_float( void )
{
    // static float signum(float f)
    // Returns the signum function of the argument; zero if the 
    // argument is zero, 1.0f if the argument is greater than zero, 
    // -1.0f if the argument is less than zero. 
    // Implementation code: D1AF574A
    object_t float_f;
    float ret_value = 0.0;

    float_f = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: float
    stack_push_float( ret_value );
}

void native_method_lang_math_sin_double( void )
{
    // static double sin(double a)
    // Returns the trigonometric sine of an angle. 
    // Implementation code: EBD1561F
    object_t double_a;
    double ret_value = 0.0;

    double_a = stack_pop();

    // put your code here
    ret_value = sin( value_get_double( double_a ) );

    // return type: double
    stack_push_double( ret_value );
}

void native_method_lang_math_sinh_double( void )
{
    // static double sinh(double x)
    // Returns the hyperbolic sine of a double value. 
    // Implementation code: 64ACD618
    object_t double_x;
    double ret_value = 0.0;

    double_x = stack_pop();

    // put your code here
    ret_value = sinh( value_get_double( double_x ) );

    // return type: double
    stack_push_double( ret_value );
}

void native_method_lang_math_sqrt_double( void )
{
    // static double sqrt(double a)
    // Returns the correctly rounded positive square root of a 
    // double value. 
    // Implementation code: 07333C13
    object_t double_a;
    double ret_value = 0.0;

    double_a = stack_pop();

    // put your code here
    ret_value = sqrt( value_get_double( double_a ) );

    // return type: double
    stack_push_double( ret_value );
}

void native_method_lang_math_tan_double( void )
{
    // static double tan(double a)
    // Returns the trigonometric tangent of an angle. 
    // Implementation code: 255B8090
    object_t double_a;
    double ret_value = 0.0;

    double_a = stack_pop();

    // put your code here
    ret_value = tan( value_get_double( double_a ) );

    // return type: double
    stack_push_double( ret_value );
}

void native_method_lang_math_tanh_double( void )
{
    // static double tanh(double x)
    // Returns the hyperbolic tangent of a double value. 
    // Implementation code: 5D9DA03B
    object_t double_x;
    double ret_value = 0.0;

    double_x = stack_pop();

    // put your code here
    ret_value = tanh( value_get_double( double_x ) );

    // return type: double
    stack_push_double( ret_value );
}

void native_method_lang_math_todegrees_double( void )
{
    // static double toDegrees(double angrad)
    // Converts an angle measured in radians to an approximately 
    // equivalent angle measured in degrees. 
    // Implementation code: 9F90867A
    object_t double_angrad;
    double ret_value = 0.0;

    double_angrad = stack_pop();

    // put your code here
    ret_value = ( value_get_double( double_angrad ) / ( 2 * NATIVE_FIELD_VALUE_LANG_MATH_PI ) ) * 360.0;

    // return type: double
    stack_push_double( ret_value );
}

void native_method_lang_math_toradians_double( void )
{
    // static double toRadians(double angdeg)
    // Converts an angle measured in degrees to an approximately 
    // equivalent angle measured in radians. 
    // Implementation code: 94E8DDA5
    object_t double_angdeg;
    double ret_value = 0.0;

    double_angdeg = stack_pop();

    // put your code here
    ret_value = ( value_get_double( double_angdeg ) / 360.0 ) * ( 2 * NATIVE_FIELD_VALUE_LANG_MATH_PI );

    // return type: double
    stack_push_double( ret_value );
}

void native_method_lang_math_ulp_double( void )
{
    // static double ulp(double d)
    // Returns the size of an ulp of the argument. 
    // Implementation code: 8B222D45
    object_t double_d;
    double ret_value = 0.0;

    double_d = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: double
    stack_push_double( ret_value );
}

void native_method_lang_math_ulp_float( void )
{
    // static float ulp(float f)
    // Returns the size of an ulp of the argument. 
    // Implementation code: 8B222D45
    object_t double_d;
    double ret_value = 0.0;

    double_d = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: double
    stack_push_double( ret_value );
}

///////////////////////////////////////////////////////////////////////////

uint32_t native_lang_math_get_superclass( void )
{
	return NATIVE_CLASS_LANG_OBJECT;
}

void native_lang_math_get_field(uint16_t mref)
{
    switch( mref )
    {
        case NATIVE_FIELD_LANG_MATH_E:
            // static double E
            // Implementation field read code: FIELD_READ_LANG_MATH_E
            stack_push( value_create_double( NATIVE_FIELD_VALUE_LANG_MATH_E ) );
            break;

        case NATIVE_FIELD_LANG_MATH_PI:
            // static double PI
            // Implementation field read code: FIELD_READ_LANG_MATH_PI
            stack_push( value_create_double( NATIVE_FIELD_VALUE_LANG_MATH_PI ) );
            break;

        default: 
            exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
            break;
    }
}

void native_lang_math_invoke(uint16_t mref)
{
    switch( mref )
    {
        case NATIVE_LANG_MATH_ABS_DOUBLE:
            native_method_lang_math_abs_double();
            break;

        case NATIVE_LANG_MATH_ABS_FLOAT:
            native_method_lang_math_abs_float();
            break;

        case NATIVE_LANG_MATH_ABS_INT:
            native_method_lang_math_abs_int();
            break;

        case NATIVE_LANG_MATH_ABS_LONG:
            native_method_lang_math_abs_long();
            break;

        case NATIVE_LANG_MATH_ACOS_DOUBLE:
            native_method_lang_math_acos_double();
            break;

        case NATIVE_LANG_MATH_ASIN_DOUBLE:
            native_method_lang_math_asin_double();
            break;

        case NATIVE_LANG_MATH_ATAN_DOUBLE:
            native_method_lang_math_atan_double();
            break;

        case NATIVE_LANG_MATH_ATAN2_DOUBLE_DOUBLE:
            native_method_lang_math_atan2_double_double();
            break;

        case NATIVE_LANG_MATH_CBRT_DOUBLE:
            native_method_lang_math_cbrt_double();
            break;

        case NATIVE_LANG_MATH_CEIL_DOUBLE:
            native_method_lang_math_ceil_double();
            break;

        case NATIVE_LANG_MATH_COPYSIGN_DOUBLE_DOUBLE:
            native_method_lang_math_copysign_double_double();
            break;

        case NATIVE_LANG_MATH_COPYSIGN_FLOAT_FLOAT:
            native_method_lang_math_copysign_float_float();
            break;

        case NATIVE_LANG_MATH_COS_DOUBLE:
            native_method_lang_math_cos_double();
            break;

        case NATIVE_LANG_MATH_COSH_DOUBLE:
            native_method_lang_math_cosh_double();
            break;

        case NATIVE_LANG_MATH_EXP_DOUBLE:
            native_method_lang_math_exp_double();
            break;

        case NATIVE_LANG_MATH_EXPM1_DOUBLE:
            native_method_lang_math_expm1_double();
            break;

        case NATIVE_LANG_MATH_FLOOR_DOUBLE:
            native_method_lang_math_floor_double();
            break;

        case NATIVE_LANG_MATH_GETEXPONENT_DOUBLE:
            native_method_lang_math_getexponent_double();
            break;

        case NATIVE_LANG_MATH_GETEXPONENT_FLOAT:
            native_method_lang_math_getexponent_float();
            break;

        case NATIVE_LANG_MATH_HYPOT_DOUBLE_DOUBLE:
            native_method_lang_math_hypot_double_double();
            break;

        case NATIVE_LANG_MATH_IEEEREMAINDER_DOUBLE_DOUBLE:
            native_method_lang_math_ieeeremainder_double_double();
            break;

        case NATIVE_LANG_MATH_LOG_DOUBLE:
            native_method_lang_math_log_double();
            break;

        case NATIVE_LANG_MATH_LOG10_DOUBLE:
            native_method_lang_math_log10_double();
            break;

        case NATIVE_LANG_MATH_LOG1P_DOUBLE:
            native_method_lang_math_log1p_double();
            break;

        case NATIVE_LANG_MATH_MAX_DOUBLE_DOUBLE:
            native_method_lang_math_max_double_double();
            break;

        case NATIVE_LANG_MATH_MAX_FLOAT_FLOAT:
            native_method_lang_math_max_float_float();
            break;

        case NATIVE_LANG_MATH_MAX_INT_INT:
            native_method_lang_math_max_int_int();
            break;

        case NATIVE_LANG_MATH_MAX_LONG_LONG:
            native_method_lang_math_max_long_long();
            break;

        case NATIVE_LANG_MATH_MIN_DOUBLE_DOUBLE:
            native_method_lang_math_min_double_double();
            break;

        case NATIVE_LANG_MATH_MIN_FLOAT_FLOAT:
            native_method_lang_math_min_float_float();
            break;

        case NATIVE_LANG_MATH_MIN_INT_INT:
            native_method_lang_math_min_int_int();
            break;

        case NATIVE_LANG_MATH_MIN_LONG_LONG:
            native_method_lang_math_min_long_long();
            break;

        case NATIVE_LANG_MATH_NEXTAFTER_DOUBLE_DOUBLE:
            native_method_lang_math_nextafter_double_double();
            break;

        case NATIVE_LANG_MATH_NEXTAFTER_FLOAT_DOUBLE:
            native_method_lang_math_nextafter_float_double();
            break;

        case NATIVE_LANG_MATH_NEXTUP_DOUBLE:
            native_method_lang_math_nextup_double();
            break;

        case NATIVE_LANG_MATH_NEXTUP_FLOAT:
            native_method_lang_math_nextup_float();
            break;

        case NATIVE_LANG_MATH_POW_DOUBLE_DOUBLE:
            native_method_lang_math_pow_double_double();
            break;

        case NATIVE_LANG_MATH_RANDOM:
            native_method_lang_math_random();
            break;

        case NATIVE_LANG_MATH_RINT_DOUBLE:
            native_method_lang_math_rint_double();
            break;

        case NATIVE_LANG_MATH_ROUND_DOUBLE:
            native_method_lang_math_round_double();
            break;

        case NATIVE_LANG_MATH_ROUND_FLOAT:
            native_method_lang_math_round_float();
            break;

        case NATIVE_LANG_MATH_SCALB_DOUBLE_INT:
            native_method_lang_math_scalb_double_int();
            break;

        case NATIVE_LANG_MATH_SCALB_FLOAT_INT:
            native_method_lang_math_scalb_float_int();
            break;

        case NATIVE_LANG_MATH_SIGNUM_DOUBLE:
            native_method_lang_math_signum_double();
            break;

        case NATIVE_LANG_MATH_SIGNUM_FLOAT:
            native_method_lang_math_signum_float();
            break;

        case NATIVE_LANG_MATH_SIN_DOUBLE:
            native_method_lang_math_sin_double();
            break;

        case NATIVE_LANG_MATH_SINH_DOUBLE:
            native_method_lang_math_sinh_double();
            break;

        case NATIVE_LANG_MATH_SQRT_DOUBLE:
            native_method_lang_math_sqrt_double();
            break;

        case NATIVE_LANG_MATH_TAN_DOUBLE:
            native_method_lang_math_tan_double();
            break;

        case NATIVE_LANG_MATH_TANH_DOUBLE:
            native_method_lang_math_tanh_double();
            break;

        case NATIVE_LANG_MATH_TODEGREES_DOUBLE:
            native_method_lang_math_todegrees_double();
            break;

        case NATIVE_LANG_MATH_TORADIANS_DOUBLE:
            native_method_lang_math_toradians_double();
            break;

        case NATIVE_LANG_MATH_ULP_DOUBLE:
            native_method_lang_math_ulp_double();
            break;

        case NATIVE_LANG_MATH_ULP_FLOAT:
            native_method_lang_math_ulp_float();
            break;

        default:
            exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
            break;

    }
}


