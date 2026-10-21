#include "lang_number.h"
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

object_t native_lang_number_new( void )
{
    return( object_create( GET_CLASS_REF( NATIVE_CLASS_LANG_NUMBER ), T_CLASS, NATIVE_LANG_NUMBER_TOTAL_FIELDS ) );
}

///////////////////////////////////////////////////////////////////////////

void native_method_lang_number_init( void )
{
    // Number()
    //  
    // Implementation code: 2D2816FE
    object_t object;

    object = stack_pop();
}

///////////////////////////////////////////////////////////////////////////

void native_method_lang_number_bytevalue( void )
{
    // byte byteValue()
    // Returns the value of the specified number as a byte. 
    // Implementation code: 7A722874
    object_t object;
    uint8_t ret_value = 0;

    object = stack_pop();

    // put your code here
    ret_value = ( uint8_t )value_get_as_integer( LANG_NUMBER_VALUE_FIELD( object ) );

    // return type: byte
    stack_push_byte( ret_value );
}

void native_method_lang_number_doublevalue( void )
{
    // abstract  double doubleValue()
    // Returns the value of the specified number as a double. 
    // Implementation code: 0732E91C
    object_t object;
    double ret_value = 0.0;

    object = stack_pop();

    // put your code here
    ret_value = ( double )value_get_as_double( LANG_NUMBER_VALUE_FIELD( object ) );

    // return type: double
    stack_push_double( ret_value );
}

void native_method_lang_number_floatvalue( void )
{
    // abstract  float floatValue()
    // Returns the value of the specified number as a float. 
    // Implementation code: 5BC05DAB
    object_t object;
    float ret_value = 0.0;

    object = stack_pop();

    // put your code here
    ret_value = ( float )value_get_as_float( LANG_NUMBER_VALUE_FIELD( object ) );

    // return type: float
    stack_push_float( ret_value );
}

void native_method_lang_number_intvalue( void )
{
    // abstract  int intValue()
    // Returns the value of the specified number as an int. 
    // Implementation code: 369ED819
    object_t object;
    int32_t ret_value = 0;

    object = stack_pop();

    // put your code here
    ret_value = ( int32_t )value_get_as_integer( LANG_NUMBER_VALUE_FIELD( object ) );

    // return type: int
    stack_push_integer( ret_value );
}

void native_method_lang_number_longvalue( void )
{
    // abstract  long longValue()
    // Returns the value of the specified number as a long. 
    // Implementation code: FC3B3F50
    object_t object;
    int64_t ret_value = 0L;

    object = stack_pop();

    // put your code here
    ret_value = ( int64_t )value_get_as_long( LANG_NUMBER_VALUE_FIELD( object ) );

    // return type: long
    stack_push_long( ret_value );
}

void native_method_lang_number_shortvalue( void )
{
    // short shortValue()
    // Returns the value of the specified number as a short. 
    // Implementation code: 9AF13264
    object_t object;
    int16_t ret_value = 0;

    object = stack_pop();

    // put your code here
    ret_value = ( int16_t )value_get_as_integer( LANG_NUMBER_VALUE_FIELD( object ) );

    // return type: short
    stack_push_short( ret_value );
}

///////////////////////////////////////////////////////////////////////////

uint32_t native_lang_number_get_superclass( void )
{
	return NATIVE_CLASS_LANG_OBJECT;
}

void native_lang_number_invoke(uint16_t mref)
{
    switch( mref )
    {
        case NATIVE_LANG_NUMBER_INIT:
            native_method_lang_number_init();
            break;

        case NATIVE_LANG_NUMBER_BYTEVALUE:
            native_method_lang_number_bytevalue();
            break;

        case NATIVE_LANG_NUMBER_DOUBLEVALUE:
            native_method_lang_number_doublevalue();
            break;

        case NATIVE_LANG_NUMBER_FLOATVALUE:
            native_method_lang_number_floatvalue();
            break;

        case NATIVE_LANG_NUMBER_INTVALUE:
            native_method_lang_number_intvalue();
            break;

        case NATIVE_LANG_NUMBER_LONGVALUE:
            native_method_lang_number_longvalue();
            break;

        case NATIVE_LANG_NUMBER_SHORTVALUE:
            native_method_lang_number_shortvalue();
            break;

        default:
            exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
            break;

    }
}


