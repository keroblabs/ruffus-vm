#include "lang_class.h"
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

object_t native_lang_class_new( void )
{
    return( object_create( GET_CLASS_REF( NATIVE_CLASS_LANG_CLASS ), T_CLASS, NATIVE_LANG_CLASS_TOTAL_FIELDS ) );
}

///////////////////////////////////////////////////////////////////////////

void native_method_lang_class_init( void )
{
    // Class()
    //  
    // Implementation code: 00000000
    object_t object;

    object = stack_pop();
}

void native_method_lang_class_get_name( void )
{
    // String getName()
    // Returns the name of the entity (class, interface, array class, primitive type, or void) represented by this Class object, as a String. 
    // Implementation code: 00000000
    object_t object;
    object_t * fields;
    char * class_name;

    object = stack_pop();
    
    fields = object_get_fields_ptr( object );
    class_name = app_get_class_name( value_get_as_integer( fields[NATIVE_FIELD_LANG_CLASS_CREF] ) );

    // return type: String
    stack_push( strings_create( class_name ) );    
}

void native_method_lang_class_get_simple_name( void )
{
    // String getSimpleName()
    // Returns the simple name of the underlying class as given in the source code. 
    // Implementation code: 00000000
    object_t object;
    object_t * fields;
    char * class_name;
    char * simple_name;

    object = stack_pop();
    
    fields = object_get_fields_ptr( object );
    class_name = app_get_class_name( fields[NATIVE_FIELD_LANG_CLASS_CREF] );
    simple_name = strchr( class_name, '/' );
    if( simple_name != NULL ) class_name = simple_name + 1;

    // return type: String
    stack_push( strings_create( class_name ) );    
}

void native_method_lang_class_is_array( void )
{
    // boolean isArray()
    // Determines if this Class object represents an array class.
    // Implementation code: 00000000
    object_t object;
    bool_t ret_value = 0;

    object = stack_pop();

    // return type: boolean
    stack_push( value_create( &ret_value, T_BOOLEAN ) );
}

void native_lang_class_invoke(uint16_t mref)
{
    switch( mref )
    {
        case NATIVE_LANG_CLASS_INIT:
            native_method_lang_class_init();
            break;

        case NATIVE_LANG_CLASS_GETNAME:
            native_method_lang_class_get_name();
            break;

        case NATIVE_LANG_CLASS_GETSIMPLENAME:
            native_method_lang_class_get_simple_name();
            break;

        case NATIVE_LANG_CLASS_ISARRAY:
            native_method_lang_class_is_array();
            break;
            
        default:
            exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
            break;            
    }
}

