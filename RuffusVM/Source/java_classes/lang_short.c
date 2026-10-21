#include "lang_short.h"
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

// static short MAX_VALUE
#define NATIVE_FIELD_VALUE_LANG_SHORT_MAX_VALUE                                  0

// static short MIN_VALUE
#define NATIVE_FIELD_VALUE_LANG_SHORT_MIN_VALUE                                  1

// static int SIZE
#define NATIVE_FIELD_VALUE_LANG_SHORT_SIZE                                       2


///////////////////////////////////////////////////////////////////////////

// New method implementation
object_t native_lang_short_new_value( int16_t value )
{
	object_t object;

    object = native_lang_byte_new();
	LANG_NUMBER_VALUE_FIELD( object ) = value_create_short( value );

	return object;
}

object_t native_lang_short_new( void )
{
    return( object_create( GET_CLASS_REF( NATIVE_CLASS_LANG_SHORT ), T_CLASS, NATIVE_LANG_SHORT_TOTAL_FIELDS ) );
}

///////////////////////////////////////////////////////////////////////////

void native_method_lang_short_init_short( void )
{
    // Short(short value)
    // Constructs a newly allocated Short object that represents 
    // the specified short value. 
    // Implementation code: 96E8C2FC
    object_t short_value;
    object_t object;

    short_value = stack_pop();
    object = stack_pop();

    // put your code here
    LANG_NUMBER_VALUE_FIELD( object ) = value_create_short( value_get_short( short_value ) );
}

void native_method_lang_short_init_string( void )
{
    // Short(String s)
    // Constructs a newly allocated Short object that represents 
    // the short value indicated by the String parameter. 
    // Implementation code: A434024C
    object_t string_s;
    object_t object;

    string_s = stack_pop();
    object = stack_pop();

    // put your code here
    LANG_NUMBER_VALUE_FIELD( object ) = value_create_short( strings_atoi( strings_get_text_ptr( string_s ), 10 ) );

}

///////////////////////////////////////////////////////////////////////////

void native_method_lang_short_bytevalue( void )
{
    // byte byteValue()
    // Returns the value of this Short as a byte. 
    // Implementation code: DBB5A8A7
	native_lang_number_invoke( NATIVE_LANG_NUMBER_BYTEVALUE );
}

void native_method_lang_short_compareto_short( void )
{
    // int compareTo(Short anotherShort)
    // Compares two Short objects numerically. 
    // Implementation code: 0348E3E9
    lang_number_lib_compare_to();
}

void native_method_lang_short_decode_string( void )
{
    // static Short decode(String nm)
    // Decodes a String into a Short. 
    // Implementation code: DA06E8A4
    object_t string_nm;

    string_nm = stack_pop();

    // return type: Short
    stack_push( native_lang_short_new_value( strings_atoi( strings_get_text_ptr( string_nm ), 10 ) ) );
}

void native_method_lang_short_doublevalue( void )
{
    // double doubleValue()
    // Returns the value of this Short as a double. 
    // Implementation code: 079A7D10
	native_lang_number_invoke( NATIVE_LANG_NUMBER_DOUBLEVALUE );
}

void native_method_lang_short_equals_object( void )
{
    // boolean equals(Object obj)
    // Compares this object to the specified object. 
    // Implementation code: 07F3404B
    lang_number_lib_equals();
}

void native_method_lang_short_floatvalue( void )
{
    // float floatValue()
    // Returns the value of this Short as a float. 
    // Implementation code: D8EBCC15
	native_lang_number_invoke( NATIVE_LANG_NUMBER_FLOATVALUE );
}

void native_method_lang_short_hashcode( void )
{
    // int hashCode()
    // Returns a hash code for this Short. 
    // Implementation code: 1CD3BA07
    lang_number_lib_hashcode();
}

void native_method_lang_short_intvalue( void )
{
    // int intValue()
    // Returns the value of this Short as an int. 
    // Implementation code: 266CF97C
	native_lang_number_invoke( NATIVE_LANG_NUMBER_INTVALUE );

}

void native_method_lang_short_longvalue( void )
{
    // long longValue()
    // Returns the value of this Short as a long. 
    // Implementation code: 75CFDB8B
	native_lang_number_invoke( NATIVE_LANG_NUMBER_LONGVALUE );
}

void native_method_lang_short_parseshort_string( void )
{
    // static short parseShort(String s)
    // Parses the string argument as a signed decimal short. 
    // Implementation code: D3654C83
    object_t string_s;
    int16_t ret_value = 0;

    string_s = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: short
    stack_push( value_create( &ret_value, T_SHORT ) );
}

void native_method_lang_short_parseshort_string_int( void )
{
    // static short parseShort(String s, int radix)
    // Parses the string argument as a signed short in the radix 
    // specified by the second argument. 
    // Implementation code: 252606BF
    object_t string_s;
    object_t int_radix;
    int16_t ret_value = 0;

    int_radix = stack_pop();
    string_s = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: short
    stack_push( value_create( &ret_value, T_SHORT ) );
}

void native_method_lang_short_reversebytes_short( void )
{
    // static short reverseBytes(short i)
    // Returns the value obtained by reversing the order of the 
    // bytes in the two's complement representation of the specified 
    // short value. 
    // Implementation code: 83F15BCD
    object_t short_i;
    int16_t ret_value = 0;

    short_i = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: short
    stack_push( value_create( &ret_value, T_SHORT ) );
}

void native_method_lang_short_shortvalue( void )
{
    // short shortValue()
    // Returns the value of this Short as a short. 
    // Implementation code: 1162510E
    native_lang_number_invoke( NATIVE_LANG_NUMBER_SHORTVALUE );
}

void native_method_lang_short_tostring( void )
{
    // String toString()
    // Returns a String object representing this Short's value. 
    // Implementation code: 0078B70C
    lang_number_lib_object_tostring(RADIX_DECIMAL);
}

void native_method_lang_short_tostring_short( void )
{
    // static String toString(short s)
    // Returns a new String object representing the specified short. 
    // Implementation code: 439C6641
    lang_number_lib_value_tostring(RADIX_DECIMAL);
}

void native_method_lang_short_valueof_short( void )
{
    // static Short valueOf(short s)
    // Returns a Short instance representing the specified short 
    // value. 
    // Implementation code: 37042880
    object_t short_s;

    short_s = stack_pop();

    // return type: Short
    stack_push( native_lang_short_new_value( value_get_short( short_s ) ) );
}

void native_method_lang_short_valueof_string( void )
{
    // static Short valueOf(String s)
    // Returns a Short object holding the value given by the specified 
    // String. 
    // Implementation code: F6066143
    object_t string_s;

    string_s = stack_pop();

    // return type: Short
    stack_push( native_lang_short_new_value( ( int16_t )strings_atoi( strings_get_text_ptr( string_s ), 10 ) ) );
}

void native_method_lang_short_valueof_string_int( void )
{
    // static Short valueOf(String s, int radix)
    // Returns a Short object holding the value extracted from 
    // the specified String when parsed with the radix given by 
    // the second argument. 
    // Implementation code: BB716597
    object_t string_s;
    object_t int_radix;

    int_radix = stack_pop();
    string_s = stack_pop();

    // return type: Short
    stack_push( native_lang_short_new_value( ( int16_t )strings_atoi( strings_get_text_ptr( string_s ), value_get_int( int_radix ) ) ) );
}

///////////////////////////////////////////////////////////////////////////

uint32_t native_lang_short_get_superclass( void )
{
	return NATIVE_CLASS_LANG_NUMBER;
}

void native_lang_short_get_field(uint16_t mref)
{
    switch( mref )
    {
        case NATIVE_FIELD_LANG_SHORT_MAX_VALUE:
            // static short MAX_VALUE
            // Implementation field read code: FIELD_READ_LANG_SHORT_MAX_VALUE
            stack_push( value_create_short( NATIVE_FIELD_VALUE_LANG_SHORT_MAX_VALUE ) );
            break;

        case NATIVE_FIELD_LANG_SHORT_MIN_VALUE:
            // static short MIN_VALUE
            // Implementation field read code: FIELD_READ_LANG_SHORT_MIN_VALUE
            stack_push( value_create_short( NATIVE_FIELD_VALUE_LANG_SHORT_MIN_VALUE ) );
            break;

        case NATIVE_FIELD_LANG_SHORT_SIZE:
            // static int SIZE
            // Implementation field read code: FIELD_READ_LANG_SHORT_SIZE
            stack_push( value_create_int( NATIVE_FIELD_VALUE_LANG_SHORT_SIZE ) );
            break;

        default: 
            exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
            break;
    }
}

void native_lang_short_invoke(uint16_t mref)
{
    switch( mref )
    {
        case NATIVE_LANG_SHORT_INIT_SHORT:
            native_method_lang_short_init_short();
            break;

        case NATIVE_LANG_SHORT_INIT_STRING:
            native_method_lang_short_init_string();
            break;

        case NATIVE_LANG_SHORT_BYTEVALUE:
            native_method_lang_short_bytevalue();
            break;

        case NATIVE_LANG_SHORT_COMPARETO_SHORT:
            native_method_lang_short_compareto_short();
            break;

        case NATIVE_LANG_SHORT_DECODE_STRING:
            native_method_lang_short_decode_string();
            break;

        case NATIVE_LANG_SHORT_DOUBLEVALUE:
            native_method_lang_short_doublevalue();
            break;

        case NATIVE_LANG_SHORT_EQUALS_OBJECT:
            native_method_lang_short_equals_object();
            break;

        case NATIVE_LANG_SHORT_FLOATVALUE:
            native_method_lang_short_floatvalue();
            break;

        case NATIVE_LANG_SHORT_HASHCODE:
            native_method_lang_short_hashcode();
            break;

        case NATIVE_LANG_SHORT_INTVALUE:
            native_method_lang_short_intvalue();
            break;

        case NATIVE_LANG_SHORT_LONGVALUE:
            native_method_lang_short_longvalue();
            break;

        case NATIVE_LANG_SHORT_PARSESHORT_STRING:
            native_method_lang_short_parseshort_string();
            break;

        case NATIVE_LANG_SHORT_PARSESHORT_STRING_INT:
            native_method_lang_short_parseshort_string_int();
            break;

        case NATIVE_LANG_SHORT_REVERSEBYTES_SHORT:
            native_method_lang_short_reversebytes_short();
            break;

        case NATIVE_LANG_SHORT_SHORTVALUE:
            native_method_lang_short_shortvalue();
            break;

        case NATIVE_LANG_SHORT_TOSTRING:
            native_method_lang_short_tostring();
            break;

        case NATIVE_LANG_SHORT_TOSTRING_SHORT:
            native_method_lang_short_tostring_short();
            break;

        case NATIVE_LANG_SHORT_VALUEOF_SHORT:
            native_method_lang_short_valueof_short();
            break;

        case NATIVE_LANG_SHORT_VALUEOF_STRING:
            native_method_lang_short_valueof_string();
            break;

        case NATIVE_LANG_SHORT_VALUEOF_STRING_INT:
            native_method_lang_short_valueof_string_int();
            break;

        default:
            exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
            break;

    }
}


