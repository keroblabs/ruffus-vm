#include "objects_Disposable.h"
#include "obj_handler.h"
#include "application.h"
#include "methods.h"
#include "threads.h"
#include "exceptions.h"
#include "native.h"

///////////////////////////////////////////////////////////////////////////

void native_method_objects_disposable_event( object_t object, uint8_t * data )
{
    // reload the object before calling longjmp
    app_java_call_t * java_call;
    
    java_call = ( app_java_call_t * )data;

    // create the thread that will reload the object
    app_java_call_start( java_call );
    app_java_call_add_param( java_call, object );
    app_java_call_execute( 0, java_call );
    app_java_call_finish( java_call );    
    
    longjmp(app_data->state, EXCEPTION_DISPOSED);
}

void native_method_objects_disposable_init( void )
{
    object_set_on_disposed_event( native_method_objects_disposable_event );
}

void native_method_objects_disposable_redirect( void )
{
    object_t src_object;
    object_t dest_object;
    
    dest_object = stack_peek(0);
    src_object = stack_peek(1);
    
    object_redirect( src_object, dest_object );

    stack_remove(2);
    stack_push( dest_object );
}

void native_method_objects_disposable_set_disposable( void )
{
    object_t object;
    object_t class_object;
    app_instance_t * p_instance;
    app_java_call_t native_java_call;
    
    object = stack_peek(0);
    class_object = stack_peek(1);
    
    p_instance = app_locate_java_method_by_class( class_object, "OnDisposed:(Ljava/lang/Object;)V", &native_java_call );
    if( p_instance != NULL )
    {
        object_set_disposable( object, ( uint8_t * )&native_java_call, sizeof( native_java_call ) );
    }

    stack_remove(2); 
}

void native_method_objects_disposable_is_disposable( void )
{
    object_t object;
    bool_t ret_val;

    object = stack_pop();
    
    ret_val = object_is_disposable( object );

    // return type: String
    stack_push( value_create_boolean( ret_val ) );    
}

void native_method_objects_disposable_is_disposed( void )
{
    object_t object;
    bool_t ret_val;

    object = stack_pop();
    
    ret_val = object_is_disposed( object );

    // return type: String
    stack_push( value_create_boolean( ret_val ) ); 
}

void native_method_objects_disposable_dispose( void )
{
    object_t object;

    object = stack_pop();
    
    object_dispose( object );
}

void native_objects_disposable_invoke(uint16_t mref)
{
    switch( mref )
    {
        case NATIVE_OBJECTS_DISPOSABLE_SET_DISPOSABLE:
            native_method_objects_disposable_set_disposable();
            break;

        case NATIVE_OBJECTS_DISPOSABLE_IS_DISPOSABLE:
            native_method_objects_disposable_is_disposable();
            break;

        case NATIVE_OBJECTS_DISPOSABLE_IS_DISPOSED:
            native_method_objects_disposable_is_disposed();
            break;

        case NATIVE_OBJECTS_DISPOSABLE_DISPOSE:
            native_method_objects_disposable_dispose();
            break;
            
        case NATIVE_OBJECTS_DISPOSABLE_REDIRECT:
            native_method_objects_disposable_redirect();
            break;
            
        default:
            exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
            break;            
    }
}

