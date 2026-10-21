#include "lang_boolean.h"
#include "heap.h"
#include "application.h"
#include "threads.h"
#include "exceptions.h"
#include "native.h"
#include "objects.h"
#include "stack.h"
#include "value_type.h"
#include "strings.h"
#include "properties.h"

///////////////////////////////////////////////////////////////////////////

// use New method implementation to hold a method
// use New implementation to mark start block
// use End new implementation to mark end block to keep

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////

// static Boolean FALSE
#define NATIVE_FIELD_VALUE_LANG_BOOLEAN_FALSE                                    0

// static Boolean TRUE
#define NATIVE_FIELD_VALUE_LANG_BOOLEAN_TRUE                                     1


///////////////////////////////////////////////////////////////////////////

// New implementation - constant strings
#define NATIVE_CONST_VALUE_LANG_BOOLEAN_FALSE                                    "false"
#define NATIVE_CONST_VALUE_LANG_BOOLEAN_TRUE                                     "true"
// End new implementation

// New method implementation
object_t native_lang_boolean_new_value( bool_t value )
{
	object_t object;

    object = native_lang_boolean_new();
	LANG_NUMBER_VALUE_FIELD( object ) = value_create_boolean( value );

	return object;
}

object_t native_lang_boolean_new( void )
{
    return( object_create( GET_CLASS_REF( NATIVE_CLASS_LANG_BOOLEAN ), T_CLASS, NATIVE_LANG_BOOLEAN_TOTAL_FIELDS ) );
}

///////////////////////////////////////////////////////////////////////////

void native_method_lang_boolean_init_boolean( void )
{
    // Boolean(boolean value)
    // Allocates a Boolean object representing the value argument. 
    // Implementation code: F0549100
    int32_t boolean_value;
    object_t object;

    boolean_value = stack_pop_boolean();
    object = stack_pop();

    // put your code here
	LANG_NUMBER_VALUE_FIELD( object ) = value_create_boolean( boolean_value );
}

void native_method_lang_boolean_init_string( void )
{
    // Boolean(String s)
    // Allocates a Boolean object representing the value true if 
    // the string argument is not null and is equal, ignoring case, 
    // to the string "true". 
    // Implementation code: F52AF9D8
    object_t string_s;
    object_t object;
	bool_t init_value;

    string_s = stack_pop();
    object = stack_pop();

	init_value = NATIVE_FIELD_VALUE_LANG_BOOLEAN_FALSE;

	if( strcmp( strings_get_text_ptr( string_s ), NATIVE_CONST_VALUE_LANG_BOOLEAN_TRUE ) == 0 )
	{
		init_value = NATIVE_FIELD_VALUE_LANG_BOOLEAN_TRUE;
	}

	LANG_NUMBER_VALUE_FIELD( object ) = value_create_boolean( init_value );
}

///////////////////////////////////////////////////////////////////////////

void native_method_lang_boolean_booleanvalue( void )
{
    // boolean booleanValue()
    // Returns the value of this Boolean object as a boolean primitive. 
    // Implementation code: 215042B5
    object_t object;
    bool_t ret_value = 0;

    object = stack_pop();

    // put your code here
    ret_value = value_get_boolean( LANG_NUMBER_VALUE_FIELD( object ) );

    // return type: boolean
    stack_push_boolean( ret_value );
}

void native_method_lang_boolean_compareto_boolean( void )
{
    // int compareTo(Boolean b)
    // Compares this Boolean instance with another. 
    // Implementation code: 8B8FCCD5
    lang_number_lib_compare_to();
}

void native_method_lang_boolean_equals_object( void )
{
    // boolean equals(Object obj)
    // Returns true if and only if the argument is not null and 
    // is a Boolean object that represents the same boolean value 
    // as this object. 
    // Implementation code: 515C3F80
    lang_number_lib_equals();
}

void native_method_lang_boolean_getboolean_string( void )
{
    // static boolean getBoolean(String name)
    // Returns true if and only if the system property named by 
    // the argument exists and is equal to the string "true". 
    // Implementation code: 87A8918F
    object_t string_name;
    bool_t ret_value = 0;

    string_name = stack_pop();

    // put your code here
	ret_value = NATIVE_FIELD_VALUE_LANG_BOOLEAN_FALSE;

	if( strcmp( property_get( strings_get_text_ptr( string_name ) ), NATIVE_CONST_VALUE_LANG_BOOLEAN_TRUE ) == 0 )
	{
		ret_value = NATIVE_FIELD_VALUE_LANG_BOOLEAN_TRUE;
	}

    // return type: boolean
    stack_push_boolean( ret_value );
}

void native_method_lang_boolean_hashcode( void )
{
    // int hashCode()
    // Returns a hash code for this Boolean object. 
    // Implementation code: B80B63D7
    lang_number_lib_hashcode();
}

void native_method_lang_boolean_parseboolean_string( void )
{
    // static boolean parseBoolean(String s)
    // Parses the string argument as a boolean. 
    // Implementation code: B41DD77C
    object_t string_s;
    bool_t ret_value = 0;

    string_s = stack_pop();

    // put your code here
	ret_value = NATIVE_FIELD_VALUE_LANG_BOOLEAN_FALSE;

	if( strcmp( strings_get_text_ptr( string_s ), NATIVE_CONST_VALUE_LANG_BOOLEAN_TRUE ) == 0 )
	{
		ret_value = NATIVE_FIELD_VALUE_LANG_BOOLEAN_TRUE;
	}

    // return type: boolean
    stack_push_boolean( ret_value );
}

void native_method_lang_boolean_tostring( void )
{
    // String toString()
    // Returns a String object representing this Boolean's value. 
    // Implementation code: F4E205F6
    lang_number_lib_object_tostring(RADIX_DECIMAL);
}

void native_method_lang_boolean_tostring_boolean( void )
{
    // static String toString(boolean b)
    // Returns a String object representing the specified boolean. 
    // Implementation code: 3E7196A2
    lang_number_lib_value_tostring(RADIX_DECIMAL);
}

void native_method_lang_boolean_valueof_boolean( void )
{
    // static Boolean valueOf(boolean b)
    // Returns a Boolean instance representing the specified boolean 
    // value. 
    // Implementation code: A1EBBC89
    object_t boolean_b;

    boolean_b = stack_pop();

    // return type: Boolean
    stack_push( native_lang_boolean_new_value( value_get_boolean( boolean_b ) ) );
}

void native_method_lang_boolean_valueof_string( void )
{
    // static Boolean valueOf(String s)
    // Returns a Boolean with a value represented by the specified 
    // string. 
    // Implementation code: A91BFD36
    object_t string_s;

    string_s = stack_pop();

    // put your code here
	if( strcmp( strings_get_text_ptr( string_s ), NATIVE_CONST_VALUE_LANG_BOOLEAN_TRUE ) == 0 )
	{
		stack_push( native_lang_boolean_new_value( NATIVE_FIELD_VALUE_LANG_BOOLEAN_TRUE ) );
	}
	else
	{
		stack_push( native_lang_boolean_new_value( NATIVE_FIELD_VALUE_LANG_BOOLEAN_FALSE ) );
	}
}

///////////////////////////////////////////////////////////////////////////

uint32_t native_lang_boolean_get_superclass( void )
{
	return NATIVE_CLASS_LANG_NUMBER;
}

void native_lang_boolean_get_field(uint16_t mref)
{
    switch( mref )
    {
        case NATIVE_FIELD_LANG_BOOLEAN_FALSE:
            // static Boolean FALSE
            // Implementation field read code: FIELD_READ_LANG_BOOLEAN_FALSE
            stack_push( native_lang_boolean_new_value( NATIVE_FIELD_VALUE_LANG_BOOLEAN_FALSE ) );
            break;

        case NATIVE_FIELD_LANG_BOOLEAN_TRUE:
            // static Boolean TRUE
            // Implementation field read code: FIELD_READ_LANG_BOOLEAN_TRUE
            stack_push( native_lang_boolean_new_value( NATIVE_FIELD_VALUE_LANG_BOOLEAN_TRUE ) );
            break;

        default: 
            exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
            break;
    }
}

void native_lang_boolean_invoke(uint16_t mref)
{
    switch( mref )
    {
        case NATIVE_LANG_BOOLEAN_INIT_BOOLEAN:
            native_method_lang_boolean_init_boolean();
            break;

        case NATIVE_LANG_BOOLEAN_INIT_STRING:
            native_method_lang_boolean_init_string();
            break;

        case NATIVE_LANG_BOOLEAN_BOOLEANVALUE:
            native_method_lang_boolean_booleanvalue();
            break;

        case NATIVE_LANG_BOOLEAN_COMPARETO_BOOLEAN:
            native_method_lang_boolean_compareto_boolean();
            break;

        case NATIVE_LANG_BOOLEAN_EQUALS_OBJECT:
            native_method_lang_boolean_equals_object();
            break;

        case NATIVE_LANG_BOOLEAN_GETBOOLEAN_STRING:
            native_method_lang_boolean_getboolean_string();
            break;

        case NATIVE_LANG_BOOLEAN_HASHCODE:
            native_method_lang_boolean_hashcode();
            break;

        case NATIVE_LANG_BOOLEAN_PARSEBOOLEAN_STRING:
            native_method_lang_boolean_parseboolean_string();
            break;

        case NATIVE_LANG_BOOLEAN_TOSTRING:
            native_method_lang_boolean_tostring();
            break;

        case NATIVE_LANG_BOOLEAN_TOSTRING_BOOLEAN:
            native_method_lang_boolean_tostring_boolean();
            break;

        case NATIVE_LANG_BOOLEAN_VALUEOF_BOOLEAN:
            native_method_lang_boolean_valueof_boolean();
            break;

        case NATIVE_LANG_BOOLEAN_VALUEOF_STRING:
            native_method_lang_boolean_valueof_string();
            break;

        default:
            exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
            break;

    }
}


