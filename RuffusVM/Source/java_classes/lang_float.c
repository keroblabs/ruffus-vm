#include "lang_float.h"
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
#define NATIVE_FIELD_VALUE_LANG_FLOAT_MAX_EXPONENT                               0

// static float MAX_VALUE
#define NATIVE_FIELD_VALUE_LANG_FLOAT_MAX_VALUE                                  (float)99999999999.0

// static int MIN_EXPONENT
#define NATIVE_FIELD_VALUE_LANG_FLOAT_MIN_EXPONENT                               2

// static float MIN_NORMAL
#define NATIVE_FIELD_VALUE_LANG_FLOAT_MIN_NORMAL                                 3.0

// static float MIN_VALUE
#define NATIVE_FIELD_VALUE_LANG_FLOAT_MIN_VALUE                                  (float)-99999999999.0

// static float NaN
#define NATIVE_FIELD_VALUE_LANG_FLOAT_NAN                                        5.0

// static float NEGATIVE_INFINITY
#define NATIVE_FIELD_VALUE_LANG_FLOAT_NEGATIVE_INFINITY                          (float)-99999999999.0

// static float POSITIVE_INFINITY
#define NATIVE_FIELD_VALUE_LANG_FLOAT_POSITIVE_INFINITY                          (float)99999999999.0

// static int SIZE
#define NATIVE_FIELD_VALUE_LANG_FLOAT_SIZE                                       4


///////////////////////////////////////////////////////////////////////////

// New method implementation
object_t native_lang_float_new_value( float value )
{
	object_t object;

    object = native_lang_float_new();
	LANG_NUMBER_VALUE_FIELD( object ) = value_create_float( value );

	return object;
}

object_t native_lang_float_new( void )
{
    return( object_create( GET_CLASS_REF( NATIVE_CLASS_LANG_FLOAT ), T_CLASS, NATIVE_LANG_FLOAT_TOTAL_FIELDS ) );
}

///////////////////////////////////////////////////////////////////////////

void native_method_lang_float_init_double( void )
{
    // Float(double value)
    // Constructs a newly allocated Float object that represents 
    // the argument converted to type float. 
    // Implementation code: 498FE43E
    object_t double_value;
    object_t object;

    double_value = stack_pop();
    object = stack_pop();

    // put your code here
    LANG_NUMBER_VALUE_FIELD( object ) = value_create_float( ( float )value_get_double( double_value ) );
}

void native_method_lang_float_init_float( void )
{
    // Float(float value)
    // Constructs a newly allocated Float object that represents 
    // the primitive float argument. 
    // Implementation code: 01757B45
    object_t float_value;
    object_t object;

    float_value = stack_pop();
    object = stack_pop();

    // put your code here
    LANG_NUMBER_VALUE_FIELD( object ) = value_create_float( ( float )value_get_float( float_value ) );
}

void native_method_lang_float_init_string( void )
{
    // Float(String s)
    // Constructs a newly allocated Float object that represents 
    // the floating-point value of type float represented by the 
    // string. 
    // Implementation code: 5A461965
    object_t string_s;
    object_t object;

    string_s = stack_pop();
    object = stack_pop();

    // put your code here
    LANG_NUMBER_VALUE_FIELD( object ) = value_create_float( ( float )atof( strings_get_text_ptr( string_s ) ) );
}

///////////////////////////////////////////////////////////////////////////

void native_method_lang_float_bytevalue( void )
{
    // byte byteValue()
    // Returns the value of this Float as a byte (by casting to 
    // a byte). 
    // Implementation code: F09D7CAC
	native_lang_number_invoke( NATIVE_LANG_NUMBER_BYTEVALUE );
}

void native_method_lang_float_compare_float_float( void )
{
    // static int compare(float f1, float f2)
    // Compares the two specified float values. 
    // Implementation code: 3BEF196A
	lang_number_lib_compare_to();
}

void native_method_lang_float_compareto_float( void )
{
    // int compareTo(Float anotherFloat)
    // Compares two Float objects numerically. 
    // Implementation code: 35B16DE9
	lang_number_lib_compare_to();
}

void native_method_lang_float_doublevalue( void )
{
    // double doubleValue()
    // Returns the double value of this Float object. 
    // Implementation code: FAC3A87C
	native_lang_number_invoke( NATIVE_LANG_NUMBER_DOUBLEVALUE );
}

void native_method_lang_float_equals_object( void )
{
    // boolean equals(Object obj)
    // Compares this object against the specified object. 
    // Implementation code: 4048E6D8
	lang_number_lib_equals();
}

void native_method_lang_float_floattointbits_float( void )
{
    // static int floatToIntBits(float value)
    // Returns a representation of the specified floating-point 
    // value according to the IEEE 754 floating-point "single format" 
    // bit layout. 
    // Implementation code: 36AA7BD4
    object_t float_value;
    int32_t ret_value = 0;

    float_value = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push_integer( ret_value );
}

void native_method_lang_float_floattorawintbits_float( void )
{
    // static int floatToRawIntBits(float value)
    // Returns a representation of the specified floating-point 
    // value according to the IEEE 754 floating-point "single format" 
    // bit layout, preserving Not-a-Number (NaN) values. 
    // Implementation code: 2EF1EF34
    object_t float_value;
    int32_t ret_value = 0;

    float_value = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push_integer( ret_value );
}

void native_method_lang_float_floatvalue( void )
{
    // float floatValue()
    // Returns the float value of this Float object. 
    // Implementation code: EA716C55
	native_lang_number_invoke( NATIVE_LANG_NUMBER_FLOATVALUE );
}

void native_method_lang_float_hashcode( void )
{
    // int hashCode()
    // Returns a hash code for this Float object. 
    // Implementation code: 46E226ED
    lang_number_lib_hashcode();
}

void native_method_lang_float_intbitstofloat_int( void )
{
    // static float intBitsToFloat(int bits)
    // Returns the float value corresponding to a given bit representation. 
    // Implementation code: E590984E
    object_t int_bits;
    float ret_value = 0.0;

    int_bits = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: float
    stack_push_float( ret_value );
}

void native_method_lang_float_intvalue( void )
{
    // int intValue()
    // Returns the value of this Float as an int (by casting to 
    // type int). 
    // Implementation code: A6EA27E8
    native_lang_number_invoke( NATIVE_LANG_NUMBER_INTVALUE );
}

void native_method_lang_float_isinfinite( void )
{
    // boolean isInfinite()
    // Returns true if this Float value is infinitely large in 
    // magnitude, false otherwise. 
    // Implementation code: EF14ACA1
    object_t object;
    bool_t ret_value = 0;
	float obj_value;

    object = stack_pop();

    // put your code here
    obj_value = value_get_float( LANG_NUMBER_VALUE_FIELD( object ) );
	if( ( obj_value > NATIVE_FIELD_VALUE_LANG_FLOAT_POSITIVE_INFINITY ) ||
		( obj_value < NATIVE_FIELD_VALUE_LANG_FLOAT_NEGATIVE_INFINITY ) )
	{
		ret_value = 1;
	}

    // return type: boolean
    stack_push_boolean( ret_value );
}

void native_method_lang_float_isinfinite_float( void )
{
    // static boolean isInfinite(float v)
    // Returns true if the specified number is infinitely large 
    // in magnitude, false otherwise. 
    // Implementation code: 70465DF1
    object_t float_v;
    bool_t ret_value = 0;
	float obj_value;

    float_v = stack_pop();

    // put your code here
    obj_value = value_get_float( LANG_NUMBER_VALUE_FIELD( float_v ) );
	if( ( obj_value > NATIVE_FIELD_VALUE_LANG_FLOAT_POSITIVE_INFINITY ) ||
		( obj_value < NATIVE_FIELD_VALUE_LANG_FLOAT_NEGATIVE_INFINITY ) )
	{
		ret_value = 1;
	}

    // return type: boolean
    stack_push_boolean( ret_value );
}

void native_method_lang_float_isnan( void )
{
    // boolean isNaN()
    // Returns true if this Float value is a Not-a-Number (NaN), 
    // false otherwise. 
    // Implementation code: C8CAEE8A
    object_t object;
    bool_t ret_value = 0;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: boolean
    stack_push_boolean( ret_value );
}

void native_method_lang_float_isnan_float( void )
{
    // static boolean isNaN(float v)
    // Returns true if the specified number is a Not-a-Number (NaN) 
    // value, false otherwise. 
    // Implementation code: 7529D566
    object_t float_v;
    bool_t ret_value = 0;

    float_v = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: boolean
    stack_push_boolean( ret_value );
}

void native_method_lang_float_longvalue( void )
{
    // long longValue()
    // Returns value of this Float as a long (by casting to type 
    // long). 
    // Implementation code: 3E030399
	native_lang_number_invoke( NATIVE_LANG_NUMBER_LONGVALUE );
}

void native_method_lang_float_parsefloat_string( void )
{
    // static float parseFloat(String s)
    // Returns a new float initialized to the value represented 
    // by the specified String, as performed by the valueOf method 
    // of class Float. 
    // Implementation code: C92C7DED
    object_t string_s;
    float ret_value = 0.0;

    string_s = stack_pop();

    // put your code here
    ret_value = ( float )strings_atof( strings_get_text_ptr( string_s ) );

    // return type: float
    stack_push_float( ret_value );
}

void native_method_lang_float_shortvalue( void )
{
    // short shortValue()
    // Returns the value of this Float as a short (by casting to 
    // a short). 
    // Implementation code: 1E7BDB38
    object_t object;
    int16_t ret_value = 0;

    object = stack_pop();

    // put your code here
	ret_value = ( int16_t )value_get_float( LANG_NUMBER_VALUE_FIELD( object ) );

    // return type: short
    stack_push_short( ret_value );
}

void native_method_lang_float_tohexstring_float( void )
{
    // static String toHexString(float f)
    // Returns a hexadecimal string representation of the float 
    // argument. 
    // Implementation code: F2D99970
    object_t float_f;

    float_f = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: String
    stack_push_string( "" );
}

void native_method_lang_float_tostring( void )
{
    // String toString()
    // Returns a string representation of this Float object. 
    // Implementation code: 9643CC7C
    object_t object;
	char str_float[ 16 ];
	float val_float;

    object = stack_pop();

    // put your code here
	val_float = value_get_float( LANG_NUMBER_VALUE_FIELD( object ) );
	strings_ftoa( str_float, val_float );

    // return type: String
    stack_push_string( str_float );
}

void native_method_lang_float_tostring_float( void )
{
    // static String toString(float f)
    // Returns a string representation of the float argument. 
    // Implementation code: 9C59D7C6
    object_t float_f;
	char str_float[ 16 ];
	float val_float;

    float_f = stack_pop();

    // put your code here
	val_float = value_get_float( LANG_NUMBER_VALUE_FIELD( float_f ) );
	strings_ftoa( str_float, val_float );

    // return type: String
    stack_push_string( str_float );
}

void native_method_lang_float_valueof_float( void )
{
    // static Float valueOf(float f)
    // Returns a Float instance representing the specified float 
    // value. 
    // Implementation code: 40B01751
    object_t float_f;

    float_f = stack_pop();

    // return type: Float
    stack_push( native_lang_float_new_value( value_get_float( float_f ) ) );
}

void native_method_lang_float_valueof_string( void )
{
    // static Float valueOf(String s)
    // Returns a Float object holding the float value represented 
    // by the argument string s. 
    // Implementation code: A7F56CB4
    object_t string_s;
	float val_float;

    string_s = stack_pop();

    // put your code here
    val_float = ( float )atof( strings_get_text_ptr( string_s ) );

    // return type: Float
    stack_push( native_lang_float_new_value( val_float ) );
}

///////////////////////////////////////////////////////////////////////////

uint32_t native_lang_float_get_superclass( void )
{
	return NATIVE_CLASS_LANG_NUMBER;
}

void native_lang_float_get_field(uint16_t mref)
{
    switch( mref )
    {
        case NATIVE_FIELD_LANG_FLOAT_MAX_EXPONENT:
            // static int MAX_EXPONENT
            // Implementation field read code: FIELD_READ_LANG_FLOAT_MAX_EXPONENT
            stack_push( value_create_int( NATIVE_FIELD_VALUE_LANG_FLOAT_MAX_EXPONENT ) );
            break;

        case NATIVE_FIELD_LANG_FLOAT_MAX_VALUE:
            // static float MAX_VALUE
            // Implementation field read code: FIELD_READ_LANG_FLOAT_MAX_VALUE
            stack_push( value_create_float( NATIVE_FIELD_VALUE_LANG_FLOAT_MAX_VALUE ) );
            break;

        case NATIVE_FIELD_LANG_FLOAT_MIN_EXPONENT:
            // static int MIN_EXPONENT
            // Implementation field read code: FIELD_READ_LANG_FLOAT_MIN_EXPONENT
            stack_push( value_create_int( NATIVE_FIELD_VALUE_LANG_FLOAT_MIN_EXPONENT ) );
            break;

        case NATIVE_FIELD_LANG_FLOAT_MIN_NORMAL:
            // static float MIN_NORMAL
            // Implementation field read code: FIELD_READ_LANG_FLOAT_MIN_NORMAL
            stack_push( value_create_float( NATIVE_FIELD_VALUE_LANG_FLOAT_MIN_NORMAL ) );
            break;

        case NATIVE_FIELD_LANG_FLOAT_MIN_VALUE:
            // static float MIN_VALUE
            // Implementation field read code: FIELD_READ_LANG_FLOAT_MIN_VALUE
            stack_push( value_create_float( NATIVE_FIELD_VALUE_LANG_FLOAT_MIN_VALUE ) );
            break;

        case NATIVE_FIELD_LANG_FLOAT_NAN:
            // static float NaN
            // Implementation field read code: FIELD_READ_LANG_FLOAT_NAN
            stack_push( value_create_float( NATIVE_FIELD_VALUE_LANG_FLOAT_NAN ) );
            break;

        case NATIVE_FIELD_LANG_FLOAT_NEGATIVE_INFINITY:
            // static float NEGATIVE_INFINITY
            // Implementation field read code: FIELD_READ_LANG_FLOAT_NEGATIVE_INFINITY
            stack_push( value_create_float( NATIVE_FIELD_VALUE_LANG_FLOAT_NEGATIVE_INFINITY ) );
            break;

        case NATIVE_FIELD_LANG_FLOAT_POSITIVE_INFINITY:
            // static float POSITIVE_INFINITY
            // Implementation field read code: FIELD_READ_LANG_FLOAT_POSITIVE_INFINITY
            stack_push( value_create_float( NATIVE_FIELD_VALUE_LANG_FLOAT_POSITIVE_INFINITY ) );
            break;

        case NATIVE_FIELD_LANG_FLOAT_SIZE:
            // static int SIZE
            // Implementation field read code: FIELD_READ_LANG_FLOAT_SIZE
            stack_push( value_create_int( NATIVE_FIELD_VALUE_LANG_FLOAT_SIZE ) );
            break;

        default: 
            exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
            break;
    }
}

void native_lang_float_invoke(uint16_t mref)
{
    switch( mref )
    {
        case NATIVE_LANG_FLOAT_INIT_DOUBLE:
            native_method_lang_float_init_double();
            break;

        case NATIVE_LANG_FLOAT_INIT_FLOAT:
            native_method_lang_float_init_float();
            break;

        case NATIVE_LANG_FLOAT_INIT_STRING:
            native_method_lang_float_init_string();
            break;

        case NATIVE_LANG_FLOAT_BYTEVALUE:
            native_method_lang_float_bytevalue();
            break;

        case NATIVE_LANG_FLOAT_COMPARE_FLOAT_FLOAT:
            native_method_lang_float_compare_float_float();
            break;

        case NATIVE_LANG_FLOAT_COMPARETO_FLOAT:
            native_method_lang_float_compareto_float();
            break;

        case NATIVE_LANG_FLOAT_DOUBLEVALUE:
            native_method_lang_float_doublevalue();
            break;

        case NATIVE_LANG_FLOAT_EQUALS_OBJECT:
            native_method_lang_float_equals_object();
            break;

        case NATIVE_LANG_FLOAT_FLOATTOINTBITS_FLOAT:
            native_method_lang_float_floattointbits_float();
            break;

        case NATIVE_LANG_FLOAT_FLOATTORAWINTBITS_FLOAT:
            native_method_lang_float_floattorawintbits_float();
            break;

        case NATIVE_LANG_FLOAT_FLOATVALUE:
            native_method_lang_float_floatvalue();
            break;

        case NATIVE_LANG_FLOAT_HASHCODE:
            native_method_lang_float_hashcode();
            break;

        case NATIVE_LANG_FLOAT_INTBITSTOFLOAT_INT:
            native_method_lang_float_intbitstofloat_int();
            break;

        case NATIVE_LANG_FLOAT_INTVALUE:
            native_method_lang_float_intvalue();
            break;

        case NATIVE_LANG_FLOAT_ISINFINITE:
            native_method_lang_float_isinfinite();
            break;

        case NATIVE_LANG_FLOAT_ISINFINITE_FLOAT:
            native_method_lang_float_isinfinite_float();
            break;

        case NATIVE_LANG_FLOAT_ISNAN:
            native_method_lang_float_isnan();
            break;

        case NATIVE_LANG_FLOAT_ISNAN_FLOAT:
            native_method_lang_float_isnan_float();
            break;

        case NATIVE_LANG_FLOAT_LONGVALUE:
            native_method_lang_float_longvalue();
            break;

        case NATIVE_LANG_FLOAT_PARSEFLOAT_STRING:
            native_method_lang_float_parsefloat_string();
            break;

        case NATIVE_LANG_FLOAT_SHORTVALUE:
            native_method_lang_float_shortvalue();
            break;

        case NATIVE_LANG_FLOAT_TOHEXSTRING_FLOAT:
            native_method_lang_float_tohexstring_float();
            break;

        case NATIVE_LANG_FLOAT_TOSTRING:
            native_method_lang_float_tostring();
            break;

        case NATIVE_LANG_FLOAT_TOSTRING_FLOAT:
            native_method_lang_float_tostring_float();
            break;

        case NATIVE_LANG_FLOAT_VALUEOF_FLOAT:
            native_method_lang_float_valueof_float();
            break;

        case NATIVE_LANG_FLOAT_VALUEOF_STRING:
            native_method_lang_float_valueof_string();
            break;

        default:
            exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
            break;

    }
}


