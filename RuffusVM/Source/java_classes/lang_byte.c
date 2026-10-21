#include "lang_byte.h"
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

// static byte MAX_VALUE
#define NATIVE_FIELD_VALUE_LANG_BYTE_MAX_VALUE                                   255

// static byte MIN_VALUE
#define NATIVE_FIELD_VALUE_LANG_BYTE_MIN_VALUE                                   0

// static int SIZE
#define NATIVE_FIELD_VALUE_LANG_BYTE_SIZE                                        1


///////////////////////////////////////////////////////////////////////////

// New method implementation
object_t native_lang_byte_new_value( uint8_t value )
{
	object_t object;

    object = native_lang_byte_new();
	LANG_NUMBER_VALUE_FIELD( object ) = value_create_byte( value );

	return object;
}

object_t native_lang_byte_new( void )
{
    return( object_create( GET_CLASS_REF( NATIVE_CLASS_LANG_BYTE ), T_CLASS, NATIVE_LANG_BYTE_TOTAL_FIELDS ) );
}

///////////////////////////////////////////////////////////////////////////

void native_method_lang_byte_init_byte( void )
{
    // Byte(byte value)
    // Constructs a newly allocated Byte object that represents 
    // the specified byte value. 
    // Implementation code: C1BA4067
    object_t byte_value;
    object_t object;

    byte_value = stack_pop();
    object = stack_pop();

    // put your code here
	LANG_NUMBER_VALUE_FIELD( object ) = value_create_byte( value_get_byte( byte_value ) );
}

void native_method_lang_byte_init_string( void )
{
    // Byte(String s)
    // Constructs a newly allocated Byte object that represents 
    // the byte value indicated by the String parameter. 
    // Implementation code: 0DF529C6
    object_t string_s;
    object_t object;

    string_s = stack_pop();
    object = stack_pop();

    // put your code here
    LANG_NUMBER_VALUE_FIELD( object ) = value_create_byte( strings_atoi( strings_get_text_ptr( string_s ), RADIX_DECIMAL ) );
}

///////////////////////////////////////////////////////////////////////////

void native_method_lang_byte_bytevalue( void )
{
    // byte byteValue()
    // Returns the value of this Byte as a byte. 
    // Implementation code: EBC9F98A
	native_lang_number_invoke( NATIVE_LANG_NUMBER_BYTEVALUE );
}

void native_method_lang_byte_compareto_byte( void )
{
    // int compareTo(Byte anotherByte)
    // Compares two Byte objects numerically. 
    // Implementation code: 06271BC9
    lang_number_lib_compare_to();
}

void native_method_lang_byte_decode_string( void )
{
    // static Byte decode(String nm)
    // Decodes a String into a Byte. 
    // Implementation code: DA4E31B6
    object_t string_nm;

    string_nm = stack_pop();

    // return type: Byte
    stack_push( native_lang_byte_new_value( strings_atoi( strings_get_text_ptr( string_nm ), RADIX_DECIMAL ) ) );
}

void native_method_lang_byte_doublevalue( void )
{
    // double doubleValue()
    // Returns the value of this Byte as a double. 
    // Implementation code: 194FF3FF
    native_lang_number_invoke( NATIVE_LANG_NUMBER_DOUBLEVALUE );
}

void native_method_lang_byte_equals_object( void )
{
    // boolean equals(Object obj)
    // Compares this object to the specified object. 
    // Implementation code: 07F3404B
    lang_number_lib_equals();
}

void native_method_lang_byte_floatvalue( void )
{
    // float floatValue()
    // Returns the value of this Byte as a float. 
    // Implementation code: B4E4742D
    native_lang_number_invoke( NATIVE_LANG_NUMBER_FLOATVALUE );

}

void native_method_lang_byte_hashcode( void )
{
    // int hashCode()
    // Returns a hash code for this Byte. 
    // Implementation code: 07A86E2B
    lang_number_lib_hashcode();
}

void native_method_lang_byte_intvalue( void )
{
    // int intValue()
    // Returns the value of this Byte as an int. 
    // Implementation code: 98D2F65E
    native_lang_number_invoke( NATIVE_LANG_NUMBER_INTVALUE );
}

void native_method_lang_byte_longvalue( void )
{
    // long longValue()
    // Returns the value of this Byte as a long. 
    // Implementation code: CD960072
    native_lang_number_invoke( NATIVE_LANG_NUMBER_LONGVALUE );
}

void native_method_lang_byte_parsebyte_string( void )
{
    // static byte parseByte(String s)
    // Parses the string argument as a signed decimal byte. 
    // Implementation code: FED50A85
    object_t string_s;

    string_s = stack_pop();

    // return type: byte
    stack_push_byte( strings_atoi( strings_get_text_ptr( string_s ), RADIX_DECIMAL ) );
}

void native_method_lang_byte_parsebyte_string_int( void )
{
    // static byte parseByte(String s, int radix)
    // Parses the string argument as a signed byte in the radix 
    // specified by the second argument. 
    // Implementation code: EB4AA42B
    object_t string_s;
    object_t int_radix;
    uint8_t ret_value = 0;

    int_radix = stack_pop();
    string_s = stack_pop();

    // put your code here
    ret_value = strings_atoi( strings_get_text_ptr( string_s ), value_get_int( int_radix ) );

    // return type: byte
    stack_push_byte( ret_value );
}

void native_method_lang_byte_shortvalue( void )
{
    // short shortValue()
    // Returns the value of this Byte as a short. 
    // Implementation code: C88971D0
    native_lang_number_invoke( NATIVE_LANG_NUMBER_SHORTVALUE );
}

void native_method_lang_byte_tostring( void )
{
    // String toString()
    // Returns a String object representing this Byte's value. 
    // Implementation code: 33665952
    lang_number_lib_object_tostring(RADIX_DECIMAL);
}

void native_method_lang_byte_tostring_byte( void )
{
    // static String toString(byte b)
    // Returns a new String object representing the specified byte. 
    // Implementation code: B0F7B05F
    lang_number_lib_value_tostring(RADIX_DECIMAL);
}

void native_method_lang_byte_valueof_byte( void )
{
    // static Byte valueOf(byte b)
    // Returns a Byte instance representing the specified byte 
    // value. 
    // Implementation code: BB7BF841
    object_t byte_b;

    byte_b = stack_pop();

    // return type: Byte
    stack_push( native_lang_byte_new_value( value_get_byte( byte_b ) ) );
}

void native_method_lang_byte_valueof_string( void )
{
    // static Byte valueOf(String s)
    // Returns a Byte object holding the value given by the specified 
    // String. 
    // Implementation code: 000E5251
    object_t string_s;

    string_s = stack_pop();

    // return type: Byte
    stack_push( native_lang_byte_new_value( ( uint8_t )strings_atoi( strings_get_text_ptr( string_s ), RADIX_DECIMAL ) ) );
}

void native_method_lang_byte_valueof_string_int( void )
{
    // static Byte valueOf(String s, int radix)
    // Returns a Byte object holding the value extracted from the 
    // specified String when parsed with the radix given by the 
    // second argument. 
    // Implementation code: 45E6B608
    object_t string_s;
    object_t int_radix;

    int_radix = stack_pop();
    string_s = stack_pop();

    // return type: Byte
    stack_push( native_lang_byte_new_value( ( uint8_t )strings_atoi( strings_get_text_ptr( string_s ), value_get_int( int_radix ) ) ) );
}

///////////////////////////////////////////////////////////////////////////

uint32_t native_lang_byte_get_superclass( void )
{
	return NATIVE_CLASS_LANG_NUMBER;
}

void native_lang_byte_get_field(uint16_t mref)
{
    switch( mref )
    {
        case NATIVE_FIELD_LANG_BYTE_MAX_VALUE:
            // static byte MAX_VALUE
            // Implementation field read code: FIELD_READ_LANG_BYTE_MAX_VALUE
            stack_push_byte( NATIVE_FIELD_VALUE_LANG_BYTE_MAX_VALUE );
            break;

        case NATIVE_FIELD_LANG_BYTE_MIN_VALUE:
            // static byte MIN_VALUE
            // Implementation field read code: FIELD_READ_LANG_BYTE_MIN_VALUE
            stack_push_byte( NATIVE_FIELD_VALUE_LANG_BYTE_MIN_VALUE );
            break;

        case NATIVE_FIELD_LANG_BYTE_SIZE:
            // static int SIZE
            // Implementation field read code: FIELD_READ_LANG_BYTE_SIZE
            stack_push_integer( NATIVE_FIELD_VALUE_LANG_BYTE_SIZE );
            break;

        default: 
            exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
            break;
    }
}

void native_lang_byte_invoke(uint16_t mref)
{
    switch( mref )
    {
        case NATIVE_LANG_BYTE_INIT_BYTE:
            native_method_lang_byte_init_byte();
            break;

        case NATIVE_LANG_BYTE_INIT_STRING:
            native_method_lang_byte_init_string();
            break;

        case NATIVE_LANG_BYTE_BYTEVALUE:
            native_method_lang_byte_bytevalue();
            break;

        case NATIVE_LANG_BYTE_COMPARETO_BYTE:
            native_method_lang_byte_compareto_byte();
            break;

        case NATIVE_LANG_BYTE_DECODE_STRING:
            native_method_lang_byte_decode_string();
            break;

        case NATIVE_LANG_BYTE_DOUBLEVALUE:
            native_method_lang_byte_doublevalue();
            break;

        case NATIVE_LANG_BYTE_EQUALS_OBJECT:
            native_method_lang_byte_equals_object();
            break;

        case NATIVE_LANG_BYTE_FLOATVALUE:
            native_method_lang_byte_floatvalue();
            break;

        case NATIVE_LANG_BYTE_HASHCODE:
            native_method_lang_byte_hashcode();
            break;

        case NATIVE_LANG_BYTE_INTVALUE:
            native_method_lang_byte_intvalue();
            break;

        case NATIVE_LANG_BYTE_LONGVALUE:
            native_method_lang_byte_longvalue();
            break;

        case NATIVE_LANG_BYTE_PARSEBYTE_STRING:
            native_method_lang_byte_parsebyte_string();
            break;

        case NATIVE_LANG_BYTE_PARSEBYTE_STRING_INT:
            native_method_lang_byte_parsebyte_string_int();
            break;

        case NATIVE_LANG_BYTE_SHORTVALUE:
            native_method_lang_byte_shortvalue();
            break;

        case NATIVE_LANG_BYTE_TOSTRING:
            native_method_lang_byte_tostring();
            break;

        case NATIVE_LANG_BYTE_TOSTRING_BYTE:
            native_method_lang_byte_tostring_byte();
            break;

        case NATIVE_LANG_BYTE_VALUEOF_BYTE:
            native_method_lang_byte_valueof_byte();
            break;

        case NATIVE_LANG_BYTE_VALUEOF_STRING:
            native_method_lang_byte_valueof_string();
            break;

        case NATIVE_LANG_BYTE_VALUEOF_STRING_INT:
            native_method_lang_byte_valueof_string_int();
            break;

        default:
            exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
            break;

    }
}


