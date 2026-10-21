#include "lang_object.h"
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
#include "lang_class_lib.h"

///////////////////////////////////////////////////////////////////////////

// use New method implementation to hold a method
// use New implementation to mark start block
// use End new implementation to mark end block to keep

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////

object_t native_lang_object_new( void )
{
    return( object_create( GET_CLASS_REF( NATIVE_CLASS_LANG_OBJECT ), T_CLASS, NATIVE_LANG_OBJECT_TOTAL_FIELDS ) );
}

///////////////////////////////////////////////////////////////////////////

void native_method_lang_object_init( void )
{
    // Object()
    //  
    // Implementation code: 2D2816FE
    object_t object;

    object = stack_pop();
}

///////////////////////////////////////////////////////////////////////////

void native_method_lang_object_clone( void )
{
    // protected  Object clone()
    // Creates and returns a copy of this object. 
    // Implementation code: 83E10E77
    object_t object;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: Object
    stack_push( 0 );
}

void native_method_lang_object_equals_object( void )
{
    // boolean equals(Object obj)
    // Indicates whether some other object is "equal to" this one. 
    // Implementation code: 8D33E2D0
    object_t object_obj;
    object_t object;
    bool_t ret_value = 0;

    object_obj = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: boolean
    stack_push( value_create( &ret_value, T_BOOLEAN ) );
}

void native_method_lang_object_finalize( void )
{
    // protected  void finalize()
    // Called by the garbage collector on an object when garbage 
    // collection determines that there are no more references 
    // to the object. 
    // Implementation code: D38747C5
    object_t object;

    object = stack_pop();
}

void native_method_lang_object_get_class( void )
{
    //  Class<?> getClass() 
    // Returns the runtime class of this Object.
    // Implementation code: 00000000
    object_t object;
    object_t class_object;
    // object_t * fields;
    
    object = stack_peek(0);
	class_object = lang_class_lib_get_class( object );
    
    //class_object = native_lang_class_new();
    //fields = object_get_fields_ptr( class_object );
    //fields[NATIVE_FIELD_LANG_CLASS_CREF] = value_create_int( (int32_t)object_get_class_ref(object) );
    //fields[NATIVE_FIELD_LANG_CLASS_OBJECT] = object;
    //fields[NATIVE_FIELD_LANG_CLASS_INSTANCE] = value_create_int( (int32_t)instance_set_app(NULL) );
    
    stack_remove(1);
    stack_push( class_object );
}

void native_method_lang_object_hashcode( void )
{
    // int hashCode()
    // Returns a hash code value for the object. 
    // Implementation code: 401D2BED
    object_t object;
    int32_t ret_value = 0;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push( value_create( &ret_value, T_INT ) );
}

void native_method_lang_object_notify( void )
{
    // void notify()
    // Wakes up a single thread that is waiting on this object's 
    // monitor. 
    // Implementation code: EB6F1F30
    object_t object;

    object = stack_pop();

    // put your code here
	thread_set_notify( object, FALSE );
}

void native_method_lang_object_notifyall( void )
{
    // void notifyAll()
    // Wakes up all threads that are waiting on this object's monitor. 
    // Implementation code: AF37B8DF
    object_t object;

    object = stack_pop();

    // put your code here
	thread_set_notify( object, TRUE );
}

void native_method_lang_object_tostring( void )
{
    // String toString()
    // Returns a string representation of the object. 
    // Implementation code: 6E04664D
    object_t object;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: String
    stack_push( strings_create( "" ) );
}

void native_method_lang_object_wait( void )
{
    // void wait()
    // Causes the current thread to wait until another thread invokes 
    // the notify() method or the notifyAll() method for this object. 
    // Implementation code: FEEC5208
    object_t object;

    object = stack_pop();

	// get object who wants to wait
    thread_set_wait( object );
}

void native_method_lang_object_wait_long( void )
{
    // void wait(long timeout)
    // Causes the current thread to wait until either another thread 
    // invokes the notify() method or the notifyAll() method for 
    // this object, or a specified amount of time has elapsed. 
    // Implementation code: 2723FC81
    object_t long_timeout;
    object_t object;

    long_timeout = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_lang_object_wait_long_int( void )
{
    // void wait(long timeout, int nanos)
    // Causes the current thread to wait until another thread invokes 
    // the notify() method or the notifyAll() method for this object, 
    // or some other thread interrupts the current thread, or a 
    // certain amount of real time has elapsed. 
    // Implementation code: 4C9D24C8
    object_t long_timeout;
    object_t int_nanos;
    object_t object;

    int_nanos = stack_pop();
    long_timeout = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

///////////////////////////////////////////////////////////////////////////

uint32_t native_lang_object_get_superclass( void )
{
	return NEG_U32;
}

void native_lang_object_invoke(uint16_t mref)
{
    switch( mref )
    {
        case NATIVE_LANG_OBJECT_INIT:
            native_method_lang_object_init();
            break;

        case NATIVE_LANG_OBJECT_CLONE:
            native_method_lang_object_clone();
            break;

        case NATIVE_LANG_OBJECT_EQUALS_OBJECT:
            native_method_lang_object_equals_object();
            break;

        case NATIVE_LANG_OBJECT_FINALIZE:
            native_method_lang_object_finalize();
            break;
            
        case NATIVE_LANG_OBJECT_GET_CLASS:
            native_method_lang_object_get_class();
            break;

        case NATIVE_LANG_OBJECT_HASHCODE:
            native_method_lang_object_hashcode();
            break;

        case NATIVE_LANG_OBJECT_NOTIFY:
            native_method_lang_object_notify();
            break;

        case NATIVE_LANG_OBJECT_NOTIFYALL:
            native_method_lang_object_notifyall();
            break;

        case NATIVE_LANG_OBJECT_TOSTRING:
            native_method_lang_object_tostring();
            break;

        case NATIVE_LANG_OBJECT_WAIT:
            native_method_lang_object_wait();
            break;

        case NATIVE_LANG_OBJECT_WAIT_LONG:
            native_method_lang_object_wait_long();
            break;

        case NATIVE_LANG_OBJECT_WAIT_LONG_INT:
            native_method_lang_object_wait_long_int();
            break;

        default:
            exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
            break;

    }
}


