#include "lang_long.h"
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

// static long MAX_VALUE
#define NATIVE_FIELD_VALUE_LANG_LONG_MAX_VALUE                                   0

// static long MIN_VALUE
#define NATIVE_FIELD_VALUE_LANG_LONG_MIN_VALUE                                   1

// static int SIZE
#define NATIVE_FIELD_VALUE_LANG_LONG_SIZE                                        8


///////////////////////////////////////////////////////////////////////////

// New method implementation
object_t native_lang_long_new_value( int64_t value )
{
	object_t object;

    object = native_lang_long_new();
	LANG_NUMBER_VALUE_FIELD( object ) = value_create_long( value );

	return object;
}

object_t native_lang_long_new( void )
{
    return( object_create( GET_CLASS_REF( NATIVE_CLASS_LANG_LONG ), T_CLASS, NATIVE_LANG_LONG_TOTAL_FIELDS ) );
}

///////////////////////////////////////////////////////////////////////////

void native_method_lang_long_init_long( void )
{
    // Long(long value)
    // Constructs a newly allocated Long object that represents 
    // the specified long argument. 
    // Implementation code: F37483B6
    object_t long_value;
    object_t object;

    long_value = stack_pop();
    object = stack_pop();

    // put your code here
    LANG_NUMBER_VALUE_FIELD( object ) = value_create_long( value_get_long( long_value ) );
}

void native_method_lang_long_init_string( void )
{
    // Long(String s)
    // Constructs a newly allocated Long object that represents 
    // the long value indicated by the String parameter. 
    // Implementation code: 1202398A
    object_t string_s;
    object_t object;

    string_s = stack_pop();
    object = stack_pop();

    // put your code here
    LANG_NUMBER_VALUE_FIELD( object ) = value_create_long( strings_atol( strings_get_text_ptr( string_s ), RADIX_DECIMAL ) );
}

///////////////////////////////////////////////////////////////////////////

void native_method_lang_long_bitcount_long( void )
{
    // static int bitCount(long i)
    // Returns the number of one-bits in the two's complement binary 
    // representation of the specified long value. 
    // Implementation code: 7D8B348D
    object_t long_i;
    int32_t ret_value = 0;

    long_i = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push( value_create( &ret_value, T_INT ) );
}

void native_method_lang_long_bytevalue( void )
{
    // byte byteValue()
    // Returns the value of this Long as a byte. 
    // Implementation code: 83A7E170
	native_lang_number_invoke( NATIVE_LANG_NUMBER_BYTEVALUE );
}

void native_method_lang_long_compareto_long( void )
{
    // int compareTo(Long anotherLong)
    // Compares two Long objects numerically. 
    // Implementation code: 124396C5
	lang_number_lib_compare_to();
}

void native_method_lang_long_decode_string( void )
{
    // static Long decode(String nm)
    // Decodes a String into a Long. 
    // Implementation code: 237D77E6
    object_t string_nm;

    string_nm = stack_pop();

    // put your code here
	stack_push( native_lang_long_new_value( strings_atol( strings_get_text_ptr( string_nm ), 10 ) ) );
}

void native_method_lang_long_doublevalue( void )
{
    // double doubleValue()
    // Returns the value of this Long as a double. 
    // Implementation code: A6B9428D
	native_lang_number_invoke( NATIVE_LANG_NUMBER_DOUBLEVALUE );
}

void native_method_lang_long_equals_object( void )
{
    // boolean equals(Object obj)
    // Compares this object to the specified object. 
    // Implementation code: 07F3404B
	lang_number_lib_equals();
}

void native_method_lang_long_floatvalue( void )
{
    // float floatValue()
    // Returns the value of this Long as a float. 
    // Implementation code: 3C1EB07D
	native_lang_number_invoke( NATIVE_LANG_NUMBER_FLOATVALUE );
}

void native_method_lang_long_getlong_string( void )
{
    // static Long getLong(String nm)
    // Determines the long value of the system property with the 
    // specified name. 
    // Implementation code: 3CC91143
    object_t string_nm;
	int64_t ret_value;

    string_nm = stack_pop();

    // put your code here
    ret_value = strings_atol( property_get( strings_get_text_ptr( string_nm ) ), 10 );

    // return type: Integer
    stack_push( native_lang_long_new_value( ret_value ) );
}

void native_method_lang_long_getlong_string_long( void )
{
    // static Long getLong(String nm, Long val)
    // Returns the long value of the system property with the specified 
    // name. 
    // Implementation code: 7CD70042
    object_t string_nm;
    object_t long_val;
	int64_t ret_value;

    long_val = stack_pop();
    string_nm = stack_pop();

    // put your code here
    ret_value = strings_atol( property_get( strings_get_text_ptr( string_nm ) ), 10 );

    // return type: Integer
    stack_push( native_lang_long_new_value( ret_value ) );
}

void native_method_lang_long_hashcode( void )
{
    // int hashCode()
    // Returns a hash code for this Long. 
    // Implementation code: 3244CEA7
    lang_number_lib_hashcode();
}

void native_method_lang_long_highestonebit_long( void )
{
    // static long highestOneBit(long i)
    // Returns a long value with at most a single one-bit, in the 
    // position of the highest-order ("leftmost") one-bit in the 
    // specified long value. 
    // Implementation code: 41E7429E
    object_t long_i;
    int64_t ret_value = 0L;

    long_i = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: long
    stack_push( value_create( &ret_value, T_LONG ) );
}

void native_method_lang_long_intvalue( void )
{
    // int intValue()
    // Returns the value of this Long as an int. 
    // Implementation code: 3ED41D50
    native_lang_number_invoke( NATIVE_LANG_NUMBER_INTVALUE );
}

void native_method_lang_long_longvalue( void )
{
    // long longValue()
    // Returns the value of this Long as a long value. 
    // Implementation code: D0864535
    native_lang_number_invoke( NATIVE_LANG_NUMBER_LONGVALUE );
}

void native_method_lang_long_lowestonebit_long( void )
{
    // static long lowestOneBit(long i)
    // Returns a long value with at most a single one-bit, in the 
    // position of the lowest-order ("rightmost") one-bit in the 
    // specified long value. 
    // Implementation code: E651FF0A
    object_t long_i;
    int64_t ret_value = 0L;

    long_i = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: long
    stack_push( value_create( &ret_value, T_LONG ) );
}

void native_method_lang_long_numberofleadingzeros_long( void )
{
    // static int numberOfLeadingZeros(long i)
    // Returns the number of zero bits preceding the highest-order 
    // ("leftmost") one-bit in the two's complement binary representation 
    // of the specified long value. 
    // Implementation code: AABCC2C7
    object_t long_i;
    int32_t ret_value = 0;

    long_i = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push( value_create( &ret_value, T_INT ) );
}

void native_method_lang_long_numberoftrailingzeros_long( void )
{
    // static int numberOfTrailingZeros(long i)
    // Returns the number of zero bits following the lowest-order 
    // ("rightmost") one-bit in the two's complement binary representation 
    // of the specified long value. 
    // Implementation code: D7956DB1
    object_t long_i;
    int32_t ret_value = 0;

    long_i = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push( value_create( &ret_value, T_INT ) );
}

void native_method_lang_long_parselong_string( void )
{
    // static long parseLong(String s)
    // Parses the string argument as a signed decimal long. 
    // Implementation code: 3BB3F3CD
    object_t string_s;
    int64_t ret_value = 0L;

    string_s = stack_pop();

    // put your code here
    ret_value = strings_atol( strings_get_text_ptr( string_s ), RADIX_DECIMAL );

    // return type: long
    stack_push_long( ret_value );
}

void native_method_lang_long_parselong_string_int( void )
{
    // static long parseLong(String s, int radix)
    // Parses the string argument as a signed long in the radix 
    // specified by the second argument. 
    // Implementation code: B2CC9A47
    object_t string_s;
    object_t int_radix;
    int64_t ret_value = 0L;

    int_radix = stack_pop();
    string_s = stack_pop();

    // put your code here
    ret_value = strings_atol( strings_get_text_ptr( string_s ), value_get_int( int_radix ) );

    // return type: long
    stack_push_long( ret_value );
}

void native_method_lang_long_reverse_long( void )
{
    // static long reverse(long i)
    // Returns the value obtained by reversing the order of the 
    // bits in the two's complement binary representation of the 
    // specified long value. 
    // Implementation code: 3B7B42D9
    object_t long_i;
    int64_t ret_value = 0L;

    long_i = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: long
    stack_push( value_create( &ret_value, T_LONG ) );
}

void native_method_lang_long_reversebytes_long( void )
{
    // static long reverseBytes(long i)
    // Returns the value obtained by reversing the order of the 
    // bytes in the two's complement representation of the specified 
    // long value. 
    // Implementation code: 125B90F0
    object_t long_i;
    int64_t ret_value = 0L;

    long_i = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: long
    stack_push( value_create( &ret_value, T_LONG ) );
}

void native_method_lang_long_rotateleft_long_int( void )
{
    // static long rotateLeft(long i, int distance)
    // Returns the value obtained by rotating the two's complement 
    // binary representation of the specified long value left by 
    // the specified number of bits. 
    // Implementation code: 25BCC775
    object_t long_i;
    object_t int_distance;
    int64_t ret_value = 0L;

    int_distance = stack_pop();
    long_i = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: long
    stack_push( value_create( &ret_value, T_LONG ) );
}

void native_method_lang_long_rotateright_long_int( void )
{
    // static long rotateRight(long i, int distance)
    // Returns the value obtained by rotating the two's complement 
    // binary representation of the specified long value right 
    // by the specified number of bits. 
    // Implementation code: C0ED9ABC
    object_t long_i;
    object_t int_distance;
    int64_t ret_value = 0L;

    int_distance = stack_pop();
    long_i = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: long
    stack_push( value_create( &ret_value, T_LONG ) );
}

void native_method_lang_long_shortvalue( void )
{
    // short shortValue()
    // Returns the value of this Long as a short. 
    // Implementation code: E41BAEEA
    native_lang_number_invoke( NATIVE_LANG_NUMBER_SHORTVALUE );
}

void native_method_lang_long_signum_long( void )
{
    // static int signum(long i)
    // Returns the signum function of the specified long value. 
    // Implementation code: 8A063ED4
    object_t long_i;
    int32_t ret_value = 0;

    long_i = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push( value_create( &ret_value, T_INT ) );
}

void native_method_lang_long_tobinarystring_long( void )
{
    // static String toBinaryString(long i)
    // Returns a string representation of the long argument as 
    // an unsigned integer in base 2. 
    // Implementation code: A5EE31DA
    object_t long_i;

    long_i = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: String
    stack_push( strings_create( "" ) );
}

void native_method_lang_long_tohexstring_long( void )
{
    // static String toHexString(long i)
    // Returns a string representation of the long argument as 
    // an unsigned integer in base 16. 
    // Implementation code: 8A9DDF18
    object_t long_i;

    long_i = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: String
    stack_push( strings_create( "" ) );
}

void native_method_lang_long_tooctalstring_long( void )
{
    // static String toOctalString(long i)
    // Returns a string representation of the long argument as 
    // an unsigned integer in base 8. 
    // Implementation code: A5EE31D0
    object_t long_i;

    long_i = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: String
    stack_push( strings_create( "" ) );
}

void native_method_lang_long_tostring( void )
{
    // String toString()
    // Returns a String object representing this Long's value. 
    // Implementation code: B287DE37
    lang_number_lib_object_tostring(RADIX_DECIMAL);
}

void native_method_lang_long_tostring_long( void )
{
    // static String toString(long i)
    // Returns a String object representing the specified long. 
    // Implementation code: D5EDB1E6
    lang_number_lib_value_tostring(RADIX_DECIMAL);
}

void native_method_lang_long_tostring_long_int( void )
{
    // static String toString(long i, int radix)
    // Returns a string representation of the first argument in 
    // the radix specified by the second argument. 
    // Implementation code: 66D27283
    object_t long_i;
    object_t int_radix;

    int_radix = stack_pop();
    long_i = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: String
    stack_push( strings_create( "" ) );
}

void native_method_lang_long_valueof_long( void )
{
    // static Long valueOf(long l)
    // Returns a Long instance representing the specified long 
    // value. 
    // Implementation code: 5E835E3A
    object_t long_l;

    long_l = stack_pop();

    // return type: Long
    stack_push( native_lang_long_new_value( value_get_long( long_l ) ) );
}

void native_method_lang_long_valueof_string( void )
{
    // static Long valueOf(String s)
    // Returns a Long object holding the value of the specified 
    // String. 
    // Implementation code: 70303F65
    object_t string_s;

    string_s = stack_pop();

    // return type: Long
    stack_push( native_lang_long_new_value( strings_atol( strings_get_text_ptr( string_s ), 10 ) ) );
}

void native_method_lang_long_valueof_string_int( void )
{
    // static Long valueOf(String s, int radix)
    // Returns a Long object holding the value extracted from the 
    // specified String when parsed with the radix given by the 
    // second argument. 
    // Implementation code: 479A30F4
    object_t string_s;
    object_t int_radix;

    int_radix = stack_pop();
    string_s = stack_pop();

    // return type: Long
    stack_push( native_lang_long_new_value( strings_atol( strings_get_text_ptr( string_s ), value_get_int( int_radix ) ) ) );
}

///////////////////////////////////////////////////////////////////////////

uint32_t native_lang_long_get_superclass( void )
{
	return NATIVE_CLASS_LANG_NUMBER;
}

void native_lang_long_get_field(uint16_t mref)
{
    switch( mref )
    {
        case NATIVE_FIELD_LANG_LONG_MAX_VALUE:
            // static long MAX_VALUE
            // Implementation field read code: FIELD_READ_LANG_LONG_MAX_VALUE
            stack_push( value_create_long( 0 ) );
            break;

        case NATIVE_FIELD_LANG_LONG_MIN_VALUE:
            // static long MIN_VALUE
            // Implementation field read code: FIELD_READ_LANG_LONG_MIN_VALUE
            stack_push( value_create_long( 0 ) );
            break;

        case NATIVE_FIELD_LANG_LONG_SIZE:
            // static int SIZE
            // Implementation field read code: FIELD_READ_LANG_LONG_SIZE
            stack_push( value_create_int( NATIVE_FIELD_VALUE_LANG_LONG_SIZE ) );
            break;

        default: 
            exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
            break;
    }
}

void native_lang_long_invoke(uint16_t mref)
{
    switch( mref )
    {
        case NATIVE_LANG_LONG_INIT_LONG:
            native_method_lang_long_init_long();
            break;

        case NATIVE_LANG_LONG_INIT_STRING:
            native_method_lang_long_init_string();
            break;

        case NATIVE_LANG_LONG_BITCOUNT_LONG:
            native_method_lang_long_bitcount_long();
            break;

        case NATIVE_LANG_LONG_BYTEVALUE:
            native_method_lang_long_bytevalue();
            break;

        case NATIVE_LANG_LONG_COMPARETO_LONG:
            native_method_lang_long_compareto_long();
            break;

        case NATIVE_LANG_LONG_DECODE_STRING:
            native_method_lang_long_decode_string();
            break;

        case NATIVE_LANG_LONG_DOUBLEVALUE:
            native_method_lang_long_doublevalue();
            break;

        case NATIVE_LANG_LONG_EQUALS_OBJECT:
            native_method_lang_long_equals_object();
            break;

        case NATIVE_LANG_LONG_FLOATVALUE:
            native_method_lang_long_floatvalue();
            break;

        case NATIVE_LANG_LONG_GETLONG_STRING:
            native_method_lang_long_getlong_string();
            break;

        case NATIVE_LANG_LONG_GETLONG_STRING_LONG:
            native_method_lang_long_getlong_string_long();
            break;

        case NATIVE_LANG_LONG_HASHCODE:
            native_method_lang_long_hashcode();
            break;

        case NATIVE_LANG_LONG_HIGHESTONEBIT_LONG:
            native_method_lang_long_highestonebit_long();
            break;

        case NATIVE_LANG_LONG_INTVALUE:
            native_method_lang_long_intvalue();
            break;

        case NATIVE_LANG_LONG_LONGVALUE:
            native_method_lang_long_longvalue();
            break;

        case NATIVE_LANG_LONG_LOWESTONEBIT_LONG:
            native_method_lang_long_lowestonebit_long();
            break;

        case NATIVE_LANG_LONG_NUMBEROFLEADINGZEROS_LONG:
            native_method_lang_long_numberofleadingzeros_long();
            break;

        case NATIVE_LANG_LONG_NUMBEROFTRAILINGZEROS_LONG:
            native_method_lang_long_numberoftrailingzeros_long();
            break;

        case NATIVE_LANG_LONG_PARSELONG_STRING:
            native_method_lang_long_parselong_string();
            break;

        case NATIVE_LANG_LONG_PARSELONG_STRING_INT:
            native_method_lang_long_parselong_string_int();
            break;

        case NATIVE_LANG_LONG_REVERSE_LONG:
            native_method_lang_long_reverse_long();
            break;

        case NATIVE_LANG_LONG_REVERSEBYTES_LONG:
            native_method_lang_long_reversebytes_long();
            break;

        case NATIVE_LANG_LONG_ROTATELEFT_LONG_INT:
            native_method_lang_long_rotateleft_long_int();
            break;

        case NATIVE_LANG_LONG_ROTATERIGHT_LONG_INT:
            native_method_lang_long_rotateright_long_int();
            break;

        case NATIVE_LANG_LONG_SHORTVALUE:
            native_method_lang_long_shortvalue();
            break;

        case NATIVE_LANG_LONG_SIGNUM_LONG:
            native_method_lang_long_signum_long();
            break;

        case NATIVE_LANG_LONG_TOBINARYSTRING_LONG:
            native_method_lang_long_tobinarystring_long();
            break;

        case NATIVE_LANG_LONG_TOHEXSTRING_LONG:
            native_method_lang_long_tohexstring_long();
            break;

        case NATIVE_LANG_LONG_TOOCTALSTRING_LONG:
            native_method_lang_long_tooctalstring_long();
            break;

        case NATIVE_LANG_LONG_TOSTRING:
            native_method_lang_long_tostring();
            break;

        case NATIVE_LANG_LONG_TOSTRING_LONG:
            native_method_lang_long_tostring_long();
            break;

        case NATIVE_LANG_LONG_TOSTRING_LONG_INT:
            native_method_lang_long_tostring_long_int();
            break;

        case NATIVE_LANG_LONG_VALUEOF_LONG:
            native_method_lang_long_valueof_long();
            break;

        case NATIVE_LANG_LONG_VALUEOF_STRING:
            native_method_lang_long_valueof_string();
            break;

        case NATIVE_LANG_LONG_VALUEOF_STRING_INT:
            native_method_lang_long_valueof_string_int();
            break;

        default:
            exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
            break;

    }
}


