#include "lang_integer.h"
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

// static int MAX_VALUE
#define NATIVE_FIELD_VALUE_LANG_INTEGER_MAX_VALUE                                0

// static int MIN_VALUE
#define NATIVE_FIELD_VALUE_LANG_INTEGER_MIN_VALUE                                1

// static int SIZE
#define NATIVE_FIELD_VALUE_LANG_INTEGER_SIZE                                     4


///////////////////////////////////////////////////////////////////////////

// New method implementation
object_t native_lang_integer_new_value( int32_t value )
{
	object_t object;

    object = native_lang_integer_new();
	LANG_NUMBER_VALUE_FIELD( object ) = value_create_int( value );

	return object;
}

object_t native_lang_integer_new( void )
{
    return( object_create( GET_CLASS_REF( NATIVE_CLASS_LANG_INTEGER ), T_CLASS, NATIVE_LANG_INTEGER_TOTAL_FIELDS ) );
}

///////////////////////////////////////////////////////////////////////////

void native_method_lang_integer_init_int( void )
{
    // Integer(int value)
    // Constructs a newly allocated Integer object that represents 
    // the specified int value. 
    // Implementation code: 19A87700
    object_t int_value;
    object_t object;

    int_value = stack_pop();
    object = stack_pop();

    // put your code here
    LANG_NUMBER_VALUE_FIELD( object ) = value_create_int( value_get_int( int_value ) );
}

void native_method_lang_integer_init_string( void )
{
    // Integer(String s)
    // Constructs a newly allocated Integer object that represents 
    // the int value indicated by the String parameter. 
    // Implementation code: A4C3951B
    object_t string_s;
    object_t object;

    string_s = stack_pop();
    object = stack_pop();

    // put your code here
    LANG_NUMBER_VALUE_FIELD( object ) = value_create_int( strings_atoi( strings_get_text_ptr( string_s ), RADIX_DECIMAL ) );
}

///////////////////////////////////////////////////////////////////////////

void native_method_lang_integer_bitcount_int( void )
{
    // static int bitCount(int i)
    // Returns the number of one-bits in the two's complement binary 
    // representation of the specified int value. 
    // Implementation code: 964BBCA4
    object_t int_i;
    int32_t ret_value = 0;

    int_i = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push_integer( ret_value );
}

void native_method_lang_integer_bytevalue( void )
{
    // byte byteValue()
    // Returns the value of this Integer as a byte. 
    // Implementation code: B31C32AB
	native_lang_number_invoke( NATIVE_LANG_NUMBER_BYTEVALUE );
}

void native_method_lang_integer_compareto_integer( void )
{
    // int compareTo(Integer anotherInteger)
    // Compares two Integer objects numerically. 
    // Implementation code: 35A31745
	lang_number_lib_compare_to();
}

void native_method_lang_integer_decode_string( void )
{
    // static Integer decode(String nm)
    // Decodes a String into an Integer. 
    // Implementation code: 71B9F70E
    object_t string_nm;

    string_nm = stack_pop();

    // return type: Integer
	stack_push( native_lang_integer_new_value( strings_atoi( strings_get_text_ptr( string_nm ), 10 ) ) );
}

void native_method_lang_integer_doublevalue( void )
{
    // double doubleValue()
    // Returns the value of this Integer as a double. 
    // Implementation code: E31DB1FF
	native_lang_number_invoke( NATIVE_LANG_NUMBER_DOUBLEVALUE );
}

void native_method_lang_integer_equals_object( void )
{
    // boolean equals(Object obj)
    // Compares this object to the specified object. 
    // Implementation code: 07F3404B
	lang_number_lib_equals();
}

void native_method_lang_integer_floatvalue( void )
{
    // float floatValue()
    // Returns the value of this Integer as a float. 
    // Implementation code: A1C61068
	native_lang_number_invoke( NATIVE_LANG_NUMBER_FLOATVALUE );
}

void native_method_lang_integer_getinteger_string( void )
{
    // static Integer getInteger(String nm)
    // Determines the integer value of the system property with 
    // the specified name. 
    // Implementation code: 27A56C27
    object_t string_nm;
	int32_t ret_value;

    string_nm = stack_pop();

    // put your code here
    ret_value = strings_atoi( property_get( strings_get_text_ptr( string_nm ) ), 10 );

    // return type: Integer
    stack_push( native_lang_integer_new_value( ret_value ) );
}

void native_method_lang_integer_getinteger_string_int( void )
{
    // static Integer getInteger(String nm, int val)
    // Determines the integer value of the system property with 
    // the specified name. 
    // Implementation code: 27A56C27
    object_t string_nm;
	int32_t ret_value;

    string_nm = stack_pop();

    // put your code here
    ret_value = strings_atoi( property_get( strings_get_text_ptr( string_nm ) ), 10 );

    // return type: Integer
    stack_push( native_lang_integer_new_value( ret_value ) );
}

void native_method_lang_integer_getinteger_string_integer( void )
{
    // static Integer getInteger(String nm, Integer val)
    // Returns the integer value of the system property with the 
    // specified name. 
    // Implementation code: 7A7F1BB6
    object_t string_nm;
    object_t integer_val;
	int32_t ret_value;

    integer_val = stack_pop();
    string_nm = stack_pop();

    // put your code here
    ret_value = strings_atoi( property_get( strings_get_text_ptr( string_nm ) ), 10 );

    // return type: Integer
    stack_push( native_lang_integer_new_value( ret_value ) );
}

void native_method_lang_integer_hashcode( void )
{
    // int hashCode()
    // Returns a hash code for this Integer. 
    // Implementation code: E8AAE63C
    lang_number_lib_hashcode();
}

void native_method_lang_integer_highestonebit_int( void )
{
    // static int highestOneBit(int i)
    // Returns an int value with at most a single one-bit, in the 
    // position of the highest-order ("leftmost") one-bit in the 
    // specified int value. 
    // Implementation code: E5E92BA4
    object_t int_i;
    int32_t ret_value = 0;

    int_i = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push_integer( ret_value );
}

void native_method_lang_integer_intvalue( void )
{
    // int intValue()
    // Returns the value of this Integer as an int. 
    // Implementation code: 0BFEEAA6
    native_lang_number_invoke( NATIVE_LANG_NUMBER_INTVALUE );
}

void native_method_lang_integer_longvalue( void )
{
    // long longValue()
    // Returns the value of this Integer as a long. 
    // Implementation code: AB6D497F
    native_lang_number_invoke( NATIVE_LANG_NUMBER_LONGVALUE );
}

void native_method_lang_integer_lowestonebit_int( void )
{
    // static int lowestOneBit(int i)
    // Returns an int value with at most a single one-bit, in the 
    // position of the lowest-order ("rightmost") one-bit in the 
    // specified int value. 
    // Implementation code: 72D44B3F
    object_t int_i;
    int32_t ret_value = 0;

    int_i = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push_integer( ret_value );
}

void native_method_lang_integer_numberofleadingzeros_int( void )
{
    // static int numberOfLeadingZeros(int i)
    // Returns the number of zero bits preceding the highest-order 
    // ("leftmost") one-bit in the two's complement binary representation 
    // of the specified int value. 
    // Implementation code: E0D1051C
    object_t int_i;
    int32_t ret_value = 0;

    int_i = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push_integer( ret_value );
}

void native_method_lang_integer_numberoftrailingzeros_int( void )
{
    // static int numberOfTrailingZeros(int i)
    // Returns the number of zero bits following the lowest-order 
    // ("rightmost") one-bit in the two's complement binary representation 
    // of the specified int value. 
    // Implementation code: 89E79B8B
    object_t int_i;
    int32_t ret_value = 0;

    int_i = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push_integer( ret_value );
}

void native_method_lang_integer_parseint_string( void )
{
    // static int parseInt(String s)
    // Parses the string argument as a signed decimal integer. 
    // Implementation code: 1DC91E61
    object_t string_s;
    int32_t ret_value = 0;

    string_s = stack_pop();

    // put your code here
    ret_value = strings_atoi( strings_get_text_ptr( string_s ), RADIX_DECIMAL );

    // return type: int
    stack_push_integer( ret_value );
}

void native_method_lang_integer_parseint_string_int( void )
{
    // static int parseInt(String s, int radix)
    // Parses the string argument as a signed integer in the radix 
    // specified by the second argument. 
    // Implementation code: DA5C3625
    object_t string_s;
    object_t int_radix;
    int32_t ret_value = 0;

    int_radix = stack_pop();
    string_s = stack_pop();

    // put your code here
    ret_value = strings_atoi( strings_get_text_ptr( string_s ), value_get_int( int_radix ) );

    // return type: int
    stack_push_integer( ret_value );
}

void native_method_lang_integer_reverse_int( void )
{
    // static int reverse(int i)
    // Returns the value obtained by reversing the order of the 
    // bits in the two's complement binary representation of the 
    // specified int value. 
    // Implementation code: 46056B05
    object_t int_i;
    int32_t ret_value = 0;

    int_i = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push_integer( ret_value );
}

void native_method_lang_integer_reversebytes_int( void )
{
    // static int reverseBytes(int i)
    // Returns the value obtained by reversing the order of the 
    // bytes in the two's complement representation of the specified 
    // int value. 
    // Implementation code: 26ED82D7
    object_t int_i;
    int32_t ret_value = 0;

    int_i = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push_integer( ret_value );
}

void native_method_lang_integer_rotateleft_int_int( void )
{
    // static int rotateLeft(int i, int distance)
    // Returns the value obtained by rotating the two's complement 
    // binary representation of the specified int value left by 
    // the specified number of bits. 
    // Implementation code: 8A4D6840
    object_t int_i;
    object_t int_distance;
    int32_t ret_value = 0;

    int_distance = stack_pop();
    int_i = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push_integer( ret_value );
}

void native_method_lang_integer_rotateright_int_int( void )
{
    // static int rotateRight(int i, int distance)
    // Returns the value obtained by rotating the two's complement 
    // binary representation of the specified int value right by 
    // the specified number of bits. 
    // Implementation code: 5C552D11
    object_t int_i;
    object_t int_distance;
    int32_t ret_value = 0;

    int_distance = stack_pop();
    int_i = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push_integer( ret_value );
}

void native_method_lang_integer_shortvalue( void )
{
    // short shortValue()
    // Returns the value of this Integer as a short. 
    // Implementation code: 86916983
    native_lang_number_invoke( NATIVE_LANG_NUMBER_SHORTVALUE );
}

void native_method_lang_integer_signum_int( void )
{
    // static int signum(int i)
    // Returns the signum function of the specified int value. 
    // Implementation code: 616EDA6A
    object_t int_i;
    int32_t ret_value = 0;

    int_i = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push_integer( ret_value );
}

void native_method_lang_integer_tobinarystring_int( void )
{
    // static String toBinaryString(int i)
    // Returns a string representation of the integer argument 
    // as an unsigned integer in base 2. 
    // Implementation code: F1AE0E41
    object_t int_i;

    int_i = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: String
    stack_push_string( "" );
}

void native_method_lang_integer_tohexstring_int( void )
{
    // static String toHexString(int i)
    // Returns a string representation of the integer argument 
    // as an unsigned integer in base 16. 
    // Implementation code: 666B0E49
    object_t int_i;
    char temp_str[16];

    int_i = stack_pop();

    // put your code here
    strings_itoa( temp_str, value_get_int( int_i ), 16 );

    // return type: String
    stack_push_string(temp_str );
}

void native_method_lang_integer_tooctalstring_int( void )
{
    // static String toOctalString(int i)
    // Returns a string representation of the integer argument 
    // as an unsigned integer in base 8. 
    // Implementation code: 360C0E41
    object_t int_i;

    int_i = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: String
    stack_push_string( "" );
}

void native_method_lang_integer_tostring( void )
{
    // String toString()
    // Returns a String object representing this Integer's value. 
    // Implementation code: 3EC5AA6D
    lang_number_lib_object_tostring(RADIX_DECIMAL);
}

void native_method_lang_integer_tostring_int( void )
{
    // static String toString(int i)
    // Returns a String object representing the specified integer. 
    // Implementation code: 26617E1C
    lang_number_lib_value_tostring(RADIX_DECIMAL);
}

void native_method_lang_integer_tostring_int_int( void )
{
    // static String toString(int i, int radix)
    // Returns a string representation of the first argument in 
    // the radix specified by the second argument. 
    // Implementation code: 66D27283
    lang_number_lib_object_tostring(RADIX_DECIMAL);
}

void native_method_lang_integer_valueof_int( void )
{
    // static Integer valueOf(int i)
    // Returns a Integer instance representing the specified int 
    // value. 
    // Implementation code: 0D62141F
    object_t int_i;

    int_i = stack_pop();

    // return type: Integer
    stack_push( native_lang_integer_new_value( value_get_int( int_i ) ) );
}

void native_method_lang_integer_valueof_string( void )
{
    // static Integer valueOf(String s)
    // Returns an Integer object holding the value of the specified 
    // String. 
    // Implementation code: 45ACC996
    object_t string_s;

    string_s = stack_pop();

    // return type: Integer
    stack_push( native_lang_integer_new_value( strings_atoi( strings_get_text_ptr( string_s ), 10 ) ) );
}

void native_method_lang_integer_valueof_string_int( void )
{
    // static Integer valueOf(String s, int radix)
    // Returns an Integer object holding the value extracted from 
    // the specified String when parsed with the radix given by 
    // the second argument. 
    // Implementation code: 665DFFD9
    object_t string_s;
    object_t int_radix;

    int_radix = stack_pop();
    string_s = stack_pop();

    // put your code here
    stack_push( native_lang_integer_new_value( strings_atoi( strings_get_text_ptr( string_s ), value_get_int( int_radix ) ) ) );
}

///////////////////////////////////////////////////////////////////////////

uint32_t native_lang_integer_get_superclass( void )
{
	return NATIVE_CLASS_LANG_NUMBER;
}

void native_lang_integer_get_field(uint16_t mref)
{
    switch( mref )
    {
        case NATIVE_FIELD_LANG_INTEGER_MAX_VALUE:
            // static int MAX_VALUE
            // Implementation field read code: FIELD_READ_LANG_INTEGER_MAX_VALUE
            stack_push( value_create_int( NATIVE_FIELD_VALUE_LANG_INTEGER_MAX_VALUE ) );
            break;

        case NATIVE_FIELD_LANG_INTEGER_MIN_VALUE:
            // static int MIN_VALUE
            // Implementation field read code: FIELD_READ_LANG_INTEGER_MIN_VALUE
            stack_push( value_create_int( NATIVE_FIELD_VALUE_LANG_INTEGER_MIN_VALUE ) );
            break;

        case NATIVE_FIELD_LANG_INTEGER_SIZE:
            // static int SIZE
            // Implementation field read code: FIELD_READ_LANG_INTEGER_SIZE
            stack_push( value_create_int( NATIVE_FIELD_VALUE_LANG_INTEGER_SIZE ) );
            break;

        default: 
            exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
            break;
    }
}

void native_lang_integer_invoke(uint16_t mref)
{
    switch( mref )
    {
        case NATIVE_LANG_INTEGER_INIT_INT:
            native_method_lang_integer_init_int();
            break;

        case NATIVE_LANG_INTEGER_INIT_STRING:
            native_method_lang_integer_init_string();
            break;

        case NATIVE_LANG_INTEGER_BITCOUNT_INT:
            native_method_lang_integer_bitcount_int();
            break;

        case NATIVE_LANG_INTEGER_BYTEVALUE:
            native_method_lang_integer_bytevalue();
            break;

        case NATIVE_LANG_INTEGER_COMPARETO_INTEGER:
            native_method_lang_integer_compareto_integer();
            break;

        case NATIVE_LANG_INTEGER_DECODE_STRING:
            native_method_lang_integer_decode_string();
            break;

        case NATIVE_LANG_INTEGER_DOUBLEVALUE:
            native_method_lang_integer_doublevalue();
            break;

        case NATIVE_LANG_INTEGER_EQUALS_OBJECT:
            native_method_lang_integer_equals_object();
            break;

        case NATIVE_LANG_INTEGER_FLOATVALUE:
            native_method_lang_integer_floatvalue();
            break;

        case NATIVE_LANG_INTEGER_GETINTEGER_STRING:
            native_method_lang_integer_getinteger_string();
            break;

        case NATIVE_LANG_INTEGER_GETINTEGER_STRING_INT:
            native_method_lang_integer_getinteger_string_int();
            break;

        case NATIVE_LANG_INTEGER_GETINTEGER_STRING_INTEGER:
            native_method_lang_integer_getinteger_string_integer();
            break;

        case NATIVE_LANG_INTEGER_HASHCODE:
            native_method_lang_integer_hashcode();
            break;

        case NATIVE_LANG_INTEGER_HIGHESTONEBIT_INT:
            native_method_lang_integer_highestonebit_int();
            break;

        case NATIVE_LANG_INTEGER_INTVALUE:
            native_method_lang_integer_intvalue();
            break;

        case NATIVE_LANG_INTEGER_LONGVALUE:
            native_method_lang_integer_longvalue();
            break;

        case NATIVE_LANG_INTEGER_LOWESTONEBIT_INT:
            native_method_lang_integer_lowestonebit_int();
            break;

        case NATIVE_LANG_INTEGER_NUMBEROFLEADINGZEROS_INT:
            native_method_lang_integer_numberofleadingzeros_int();
            break;

        case NATIVE_LANG_INTEGER_NUMBEROFTRAILINGZEROS_INT:
            native_method_lang_integer_numberoftrailingzeros_int();
            break;

        case NATIVE_LANG_INTEGER_PARSEINT_STRING:
            native_method_lang_integer_parseint_string();
            break;

        case NATIVE_LANG_INTEGER_PARSEINT_STRING_INT:
            native_method_lang_integer_parseint_string_int();
            break;

        case NATIVE_LANG_INTEGER_REVERSE_INT:
            native_method_lang_integer_reverse_int();
            break;

        case NATIVE_LANG_INTEGER_REVERSEBYTES_INT:
            native_method_lang_integer_reversebytes_int();
            break;

        case NATIVE_LANG_INTEGER_ROTATELEFT_INT_INT:
            native_method_lang_integer_rotateleft_int_int();
            break;

        case NATIVE_LANG_INTEGER_ROTATERIGHT_INT_INT:
            native_method_lang_integer_rotateright_int_int();
            break;

        case NATIVE_LANG_INTEGER_SHORTVALUE:
            native_method_lang_integer_shortvalue();
            break;

        case NATIVE_LANG_INTEGER_SIGNUM_INT:
            native_method_lang_integer_signum_int();
            break;

        case NATIVE_LANG_INTEGER_TOBINARYSTRING_INT:
            native_method_lang_integer_tobinarystring_int();
            break;

        case NATIVE_LANG_INTEGER_TOHEXSTRING_INT:
            native_method_lang_integer_tohexstring_int();
            break;

        case NATIVE_LANG_INTEGER_TOOCTALSTRING_INT:
            native_method_lang_integer_tooctalstring_int();
            break;

        case NATIVE_LANG_INTEGER_TOSTRING:
            native_method_lang_integer_tostring();
            break;

        case NATIVE_LANG_INTEGER_TOSTRING_INT:
            native_method_lang_integer_tostring_int();
            break;

        case NATIVE_LANG_INTEGER_TOSTRING_INT_INT:
            native_method_lang_integer_tostring_int_int();
            break;

        case NATIVE_LANG_INTEGER_VALUEOF_INT:
            native_method_lang_integer_valueof_int();
            break;

        case NATIVE_LANG_INTEGER_VALUEOF_STRING:
            native_method_lang_integer_valueof_string();
            break;

        case NATIVE_LANG_INTEGER_VALUEOF_STRING_INT:
            native_method_lang_integer_valueof_string_int();
            break;

        default:
            exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
            break;

    }
}


