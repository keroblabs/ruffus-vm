#include "lang_reflect_field.h"
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

object_t native_lang_reflect_field_new( void )
{
    return( object_create( GET_CLASS_REF( NATIVE_CLASS_LANG_REFLECT_FIELD ), T_CLASS, NATIVE_LANG_REFLECT_FIELD_TOTAL_FIELDS ) );
}

///////////////////////////////////////////////////////////////////////////

void native_method_lang_reflect_field_init( void )
{
    // Class()
    //  
    // Implementation code: 00000000
    object_t object;

    object = stack_pop();
}

void native_method_lang_reflect_field_get_name( void )
{
    // String getName()
    // Returns the name of the entity (class, interface, array class, primitive 
	// type, or void) represented by this Class object, as a String. 
    // Implementation code: 00000000
    //object_t object;

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: String
    stack_push( strings_create( "" ) );    
}

void native_method_lang_reflect_field_get_declaring_class( void )
{
    // Class<?> getDeclaringClass()
    // Returns the Class object representing the class or interface that declares 
	// the field represented by this Field object.
    // Implementation code: 00000000
	//object_t object;

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: Object
    stack_push( 0 );
}

void native_lang_reflect_field_get_field(uint16_t mref)
{
}

void native_lang_reflect_field_invoke(uint16_t mref)
{
    switch( mref )
    {
        case NATIVE_LANG_REFLECT_FIELD_INIT:
            native_method_lang_reflect_field_init();
            break;

        case NATIVE_LANG_REFLECT_FIELD_GETNAME:
            native_method_lang_reflect_field_get_name();
            break;

		case NATIVE_LANG_REFLECT_FIELD_GETDECLARINGCLASS:
			native_method_lang_reflect_field_get_declaring_class();
			return;
            
        default:
            exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
            break;            
    }
}

