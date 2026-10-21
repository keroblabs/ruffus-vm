#include "lang_double.h"
#include "heap.h"
#include "application.h"
#include "threads.h"
#include "exceptions.h"
#include "native.h"
#include "objects.h"
#include "stack.h"
#include "value_type.h"
#include "strings.h"

///////////////////////////////////////////////////////////////////////////

// use New method implementation to hold a method
// use New implementation to mark start block
// use End new implementation to mark end block to keep

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////

// static int MAX_EXPONENT
#define NATIVE_FIELD_VALUE_LANG_DOUBLE_MAX_EXPONENT                              0

// static double MAX_VALUE
#define NATIVE_FIELD_VALUE_LANG_DOUBLE_MAX_VALUE                                 99999999999999.0

// static int MIN_EXPONENT
#define NATIVE_FIELD_VALUE_LANG_DOUBLE_MIN_EXPONENT                              0

// static double MIN_NORMAL
#define NATIVE_FIELD_VALUE_LANG_DOUBLE_MIN_NORMAL                                0.0

// static double MIN_VALUE
#define NATIVE_FIELD_VALUE_LANG_DOUBLE_MIN_VALUE                                 -99999999999999.0

// static double NaN
#define NATIVE_FIELD_VALUE_LANG_DOUBLE_NAN                                       0.0

// static double NEGATIVE_INFINITY
#define NATIVE_FIELD_VALUE_LANG_DOUBLE_NEGATIVE_INFINITY                         -99999999999999.0

// static double POSITIVE_INFINITY
#define NATIVE_FIELD_VALUE_LANG_DOUBLE_POSITIVE_INFINITY                         99999999999999.0

// static int SIZE
#define NATIVE_FIELD_VALUE_LANG_DOUBLE_SIZE                                      8


///////////////////////////////////////////////////////////////////////////

// New method implementation
object_t native_lang_double_new_value( double value )
{
	object_t object;

    object = native_lang_double_new();
	LANG_NUMBER_VALUE_FIELD( object ) = value_create_double( value );

	return object;
}

object_t native_lang_double_new( void )
{
    return( object_create( GET_CLASS_REF( NATIVE_CLASS_LANG_DOUBLE ), T_CLASS, NATIVE_LANG_DOUBLE_TOTAL_FIELDS ) );
}

///////////////////////////////////////////////////////////////////////////

void native_method_lang_double_init_double( void )
{
    // Double(double value)
    // Constructs a newly allocated Double object that represents 
    // the primitive double argument. 
    // Implementation code: 982B21E8
    object_t double_value;
    object_t object;

    double_value = stack_pop();
    object = stack_pop();

    // put your code here
    LANG_NUMBER_VALUE_FIELD( object ) = value_create_double( value_get_double( double_value ) );
}

void native_method_lang_double_init_string( void )
{
    // Double(String s)
    // Constructs a newly allocated Double object that represents 
    // the floating-point value of type double represented by the 
    // string. 
    // Implementation code: 287A3CEE
    object_t string_s;
    object_t object;

    string_s = stack_pop();
    object = stack_pop();

    // put your code here
    LANG_NUMBER_VALUE_FIELD( object ) = strings_create( native_value_to_string( string_s ) );
}

///////////////////////////////////////////////////////////////////////////

void native_method_lang_double_bytevalue( void )
{
    // byte byteValue()
    // Returns the value of this Double as a byte (by casting to 
    // a byte). 
    // Implementation code: A3EE15C1
	native_lang_number_invoke( NATIVE_LANG_NUMBER_BYTEVALUE );
}

void native_method_lang_double_compare_double_double( void )
{
    // static int compare(double d1, double d2)
    // Compares the two specified double values. 
    // Implementation code: B99A8016
    lang_number_lib_compare_to();
}

void native_method_lang_double_compareto_double( void )
{
    // int compareTo(Double anotherDouble)
    // Compares two Double objects numerically. 
    // Implementation code: A68EA178
    lang_number_lib_compare_to();
}

void native_method_lang_double_doubletolongbits_double( void )
{
    // static long doubleToLongBits(double value)
    // Returns a representation of the specified floating-point 
    // value according to the IEEE 754 floating-point "double format" 
    // bit layout. 
    // Implementation code: F64EEF71
    object_t double_value;
    int64_t ret_value = 0L;

    double_value = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: long
    stack_push_long( ret_value );
}

void native_method_lang_double_doubletorawlongbits_double( void )
{
    // static long doubleToRawLongBits(double value)
    // Returns a representation of the specified floating-point 
    // value according to the IEEE 754 floating-point "double format" 
    // bit layout, preserving Not-a-Number (NaN) values. 
    // Implementation code: 7FA9E1FD
    object_t double_value;
    int64_t ret_value = 0L;

    double_value = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: long
    stack_push_long( ret_value );
}

void native_method_lang_double_doublevalue( void )
{
    // double doubleValue()
    // Returns the double value of this Double object. 
    // Implementation code: BC7206FF
    native_lang_number_invoke( NATIVE_LANG_NUMBER_DOUBLEVALUE );
}

void native_method_lang_double_equals_object( void )
{
    // boolean equals(Object obj)
    // Compares this object against the specified object. 
    // Implementation code: 4048E6D8
    lang_number_lib_equals();
}

void native_method_lang_double_floatvalue( void )
{
    // float floatValue()
    // Returns the float value of this Double object. 
    // Implementation code: A3C8F652
    native_lang_number_invoke( NATIVE_LANG_NUMBER_FLOATVALUE );
}

void native_method_lang_double_hashcode( void )
{
    // int hashCode()
    // Returns a hash code for this Double object. 
    // Implementation code: B9F20257
    lang_number_lib_hashcode();
}

void native_method_lang_double_intvalue( void )
{
    // int intValue()
    // Returns the value of this Double as an int (by casting to 
    // type int). 
    // Implementation code: 5CC3D9BE
    native_lang_number_invoke( NATIVE_LANG_NUMBER_INTVALUE );
}

void native_method_lang_double_isinfinite( void )
{
    // boolean isInfinite()
    // Returns true if this Double value is infinitely large in 
    // magnitude, false otherwise. 
    // Implementation code: EC434D84
    object_t object;
    bool_t ret_value = 0;
	double obj_value;

    object = stack_pop();

    // put your code here
    obj_value = value_get_double( LANG_NUMBER_VALUE_FIELD( object ) );
	if( ( obj_value > NATIVE_FIELD_VALUE_LANG_DOUBLE_POSITIVE_INFINITY ) ||
		( obj_value < NATIVE_FIELD_VALUE_LANG_DOUBLE_NEGATIVE_INFINITY ) )
	{
		ret_value = 1;
	}

    // return type: boolean
    stack_push_boolean( ret_value );
}

void native_method_lang_double_isinfinite_double( void )
{
    // static boolean isInfinite(double v)
    // Returns true if the specified number is infinitely large 
    // in magnitude, false otherwise. 
    // Implementation code: 70465DF1
    object_t double_v;
    bool_t ret_value = 0;
	double obj_value;

    double_v = stack_pop();

    // put your code here
    obj_value = value_get_double( LANG_NUMBER_VALUE_FIELD( double_v ) );
	if( ( obj_value > NATIVE_FIELD_VALUE_LANG_DOUBLE_POSITIVE_INFINITY ) ||
		( obj_value < NATIVE_FIELD_VALUE_LANG_DOUBLE_NEGATIVE_INFINITY ) )
	{
		ret_value = 1;
	}

    // return type: boolean
    stack_push_boolean( ret_value );
}

void native_method_lang_double_isnan( void )
{
    // boolean isNaN()
    // Returns true if this Double value is a Not-a-Number (NaN), 
    // false otherwise. 
    // Implementation code: FB524F55
    object_t object;
    bool_t ret_value = 0;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: boolean
    stack_push_boolean( ret_value );
}

void native_method_lang_double_isnan_double( void )
{
    // static boolean isNaN(double v)
    // Returns true if the specified number is a Not-a-Number (NaN) 
    // value, false otherwise. 
    // Implementation code: 7529D566
    object_t double_v;
    bool_t ret_value = 0;

    double_v = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: boolean
    stack_push_boolean( ret_value );
}

void native_method_lang_double_longbitstodouble_long( void )
{
    // static double longBitsToDouble(long bits)
    // Returns the double value corresponding to a given bit representation. 
    // Implementation code: 4A020431
    object_t long_bits;
    double ret_value = 0.0;

    long_bits = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: double
    stack_push_double( ret_value );
}

void native_method_lang_double_longvalue( void )
{
    // long longValue()
    // Returns the value of this Double as a long (by casting to 
    // type long). 
    // Implementation code: BDFA64CF
    native_lang_number_invoke( NATIVE_LANG_NUMBER_LONGVALUE );
}

void native_method_lang_double_parsedouble_string( void )
{
    // static double parseDouble(String s)
    // Returns a new double initialized to the value represented 
    // by the specified String, as performed by the valueOf method 
    // of class Double. 
    // Implementation code: 9CA3AA2B
    object_t string_s;
    double ret_value = 0.0;

    string_s = stack_pop();

    // put your code here
    ret_value = strings_atof( strings_get_text_ptr( string_s ) );

    // return type: double
    stack_push_double( ret_value );
}

void native_method_lang_double_shortvalue( void )
{
    // short shortValue()
    // Returns the value of this Double as a short (by casting 
    // to a short). 
    // Implementation code: DFD0C0CE
    native_lang_number_invoke( NATIVE_LANG_NUMBER_SHORTVALUE );
}

void native_method_lang_double_tohexstring_double( void )
{
    // static String toHexString(double d)
    // Returns a hexadecimal string representation of the double 
    // argument. 
    // Implementation code: C0AC854B
	lang_number_lib_value_tostring( RADIX_HEXADECIMAL );
}

void native_method_lang_double_tostring( void )
{
    // String toString()
    // Returns a string representation of this Double object. 
    // Implementation code: AC985458
	lang_number_lib_object_tostring( RADIX_DECIMAL );
}

void native_method_lang_double_tostring_double( void )
{
    // static String toString(double d)
    // Returns a string representation of the double argument. 
    // Implementation code: 01B3CBD0
	lang_number_lib_value_tostring( RADIX_DECIMAL );
}

void native_method_lang_double_valueof_double( void )
{
    // static Double valueOf(double d)
    // Returns a Double instance representing the specified double 
    // value. 
    // Implementation code: 94EF162B
    object_t double_d;

    double_d = stack_pop();

    // return type: Double
    stack_push( native_lang_double_new_value( value_get_double( double_d ) ) );
}

void native_method_lang_double_valueof_string( void )
{
    // static Double valueOf(String s)
    // Returns a Double object holding the double value represented 
    // by the argument string s. 
    // Implementation code: 2B2E90DA
    object_t string_s;

    string_s = stack_pop();

    // return type: Double
    stack_push( native_lang_double_new_value( strings_atof( strings_get_text_ptr( string_s ) ) ) );
}

///////////////////////////////////////////////////////////////////////////

uint32_t native_lang_double_get_superclass( void )
{
	return NATIVE_CLASS_LANG_NUMBER;
}

void native_lang_double_get_field(uint16_t mref)
{
    switch( mref )
    {
        case NATIVE_FIELD_LANG_DOUBLE_MAX_EXPONENT:
            // static int MAX_EXPONENT
            // Implementation field read code: FIELD_READ_LANG_DOUBLE_MAX_EXPONENT
            stack_push( value_create_int( NATIVE_FIELD_VALUE_LANG_DOUBLE_MAX_EXPONENT ) );
            break;

        case NATIVE_FIELD_LANG_DOUBLE_MAX_VALUE:
            // static double MAX_VALUE
            // Implementation field read code: FIELD_READ_LANG_DOUBLE_MAX_VALUE
            stack_push( value_create_double( NATIVE_FIELD_VALUE_LANG_DOUBLE_MAX_VALUE ) );
            break;

        case NATIVE_FIELD_LANG_DOUBLE_MIN_EXPONENT:
            // static int MIN_EXPONENT
            // Implementation field read code: FIELD_READ_LANG_DOUBLE_MIN_EXPONENT
            stack_push( value_create_int( NATIVE_FIELD_VALUE_LANG_DOUBLE_MIN_EXPONENT ) );
            break;

        case NATIVE_FIELD_LANG_DOUBLE_MIN_NORMAL:
            // static double MIN_NORMAL
            // Implementation field read code: FIELD_READ_LANG_DOUBLE_MIN_NORMAL
            stack_push( value_create_double( NATIVE_FIELD_VALUE_LANG_DOUBLE_MIN_NORMAL ) );
            break;

        case NATIVE_FIELD_LANG_DOUBLE_MIN_VALUE:
            // static double MIN_VALUE
            // Implementation field read code: FIELD_READ_LANG_DOUBLE_MIN_VALUE
            stack_push( value_create_double( NATIVE_FIELD_VALUE_LANG_DOUBLE_MIN_VALUE ) );
            break;

        case NATIVE_FIELD_LANG_DOUBLE_NAN:
            // static double NaN
            // Implementation field read code: FIELD_READ_LANG_DOUBLE_NAN
            stack_push( value_create_double( NATIVE_FIELD_VALUE_LANG_DOUBLE_NAN ) );
            break;

        case NATIVE_FIELD_LANG_DOUBLE_NEGATIVE_INFINITY:
            // static double NEGATIVE_INFINITY
            // Implementation field read code: FIELD_READ_LANG_DOUBLE_NEGATIVE_INFINITY
            stack_push( value_create_double( NATIVE_FIELD_VALUE_LANG_DOUBLE_NEGATIVE_INFINITY ) );
            break;

        case NATIVE_FIELD_LANG_DOUBLE_POSITIVE_INFINITY:
            // static double POSITIVE_INFINITY
            // Implementation field read code: FIELD_READ_LANG_DOUBLE_POSITIVE_INFINITY
            stack_push( value_create_double( NATIVE_FIELD_VALUE_LANG_DOUBLE_POSITIVE_INFINITY ) );
            break;

        case NATIVE_FIELD_LANG_DOUBLE_SIZE:
            // static int SIZE
            // Implementation field read code: FIELD_READ_LANG_DOUBLE_SIZE
            stack_push( value_create_int( NATIVE_FIELD_VALUE_LANG_DOUBLE_SIZE ) );
            break;

        default: 
            exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
            break;
    }
}

void native_lang_double_invoke(uint16_t mref)
{
    switch( mref )
    {
        case NATIVE_LANG_DOUBLE_INIT_DOUBLE:
            native_method_lang_double_init_double();
            break;

        case NATIVE_LANG_DOUBLE_INIT_STRING:
            native_method_lang_double_init_string();
            break;

        case NATIVE_LANG_DOUBLE_BYTEVALUE:
            native_method_lang_double_bytevalue();
            break;

        case NATIVE_LANG_DOUBLE_COMPARE_DOUBLE_DOUBLE:
            native_method_lang_double_compare_double_double();
            break;

        case NATIVE_LANG_DOUBLE_COMPARETO_DOUBLE:
            native_method_lang_double_compareto_double();
            break;

        case NATIVE_LANG_DOUBLE_DOUBLETOLONGBITS_DOUBLE:
            native_method_lang_double_doubletolongbits_double();
            break;

        case NATIVE_LANG_DOUBLE_DOUBLETORAWLONGBITS_DOUBLE:
            native_method_lang_double_doubletorawlongbits_double();
            break;

        case NATIVE_LANG_DOUBLE_DOUBLEVALUE:
            native_method_lang_double_doublevalue();
            break;

        case NATIVE_LANG_DOUBLE_EQUALS_OBJECT:
            native_method_lang_double_equals_object();
            break;

        case NATIVE_LANG_DOUBLE_FLOATVALUE:
            native_method_lang_double_floatvalue();
            break;

        case NATIVE_LANG_DOUBLE_HASHCODE:
            native_method_lang_double_hashcode();
            break;

        case NATIVE_LANG_DOUBLE_INTVALUE:
            native_method_lang_double_intvalue();
            break;

        case NATIVE_LANG_DOUBLE_ISINFINITE:
            native_method_lang_double_isinfinite();
            break;

        case NATIVE_LANG_DOUBLE_ISINFINITE_DOUBLE:
            native_method_lang_double_isinfinite_double();
            break;

        case NATIVE_LANG_DOUBLE_ISNAN:
            native_method_lang_double_isnan();
            break;

        case NATIVE_LANG_DOUBLE_ISNAN_DOUBLE:
            native_method_lang_double_isnan_double();
            break;

        case NATIVE_LANG_DOUBLE_LONGBITSTODOUBLE_LONG:
            native_method_lang_double_longbitstodouble_long();
            break;

        case NATIVE_LANG_DOUBLE_LONGVALUE:
            native_method_lang_double_longvalue();
            break;

        case NATIVE_LANG_DOUBLE_PARSEDOUBLE_STRING:
            native_method_lang_double_parsedouble_string();
            break;

        case NATIVE_LANG_DOUBLE_SHORTVALUE:
            native_method_lang_double_shortvalue();
            break;

        case NATIVE_LANG_DOUBLE_TOHEXSTRING_DOUBLE:
            native_method_lang_double_tohexstring_double();
            break;

        case NATIVE_LANG_DOUBLE_TOSTRING:
            native_method_lang_double_tostring();
            break;

        case NATIVE_LANG_DOUBLE_TOSTRING_DOUBLE:
            native_method_lang_double_tostring_double();
            break;

        case NATIVE_LANG_DOUBLE_VALUEOF_DOUBLE:
            native_method_lang_double_valueof_double();
            break;

        case NATIVE_LANG_DOUBLE_VALUEOF_STRING:
            native_method_lang_double_valueof_string();
            break;

        default:
            exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
            break;

    }
}


