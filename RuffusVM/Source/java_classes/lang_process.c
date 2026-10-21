#include "lang_process.h"
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

object_t native_lang_process_new( void )
{
    return( object_create( GET_CLASS_REF( NATIVE_CLASS_LANG_PROCESS ), T_CLASS, NATIVE_LANG_PROCESS_TOTAL_FIELDS ) );
}

///////////////////////////////////////////////////////////////////////////

void native_method_lang_process_init( void )
{
    // Process()
    //  
    // Implementation code: 2D2816FE
    object_t object;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

///////////////////////////////////////////////////////////////////////////

void native_method_lang_process_destroy( void )
{
    // abstract  void destroy()
    // Kills the subprocess. 
    // Implementation code: 3B065574
    object_t object;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_lang_process_exitvalue( void )
{
    // abstract  int exitValue()
    // Returns the exit value for the subprocess. 
    // Implementation code: 74FAA7D3
    object_t object;
    int32_t ret_value = 0;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push( value_create( &ret_value, T_INT ) );
}

void native_method_lang_process_geterrorstream( void )
{
    // abstract  InputStream getErrorStream()
    // Gets the error stream of the subprocess. 
    // Implementation code: 675DE1B2
    object_t object;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: InputStream
    stack_push( 0 );
}

void native_method_lang_process_getinputstream( void )
{
    // abstract  InputStream getInputStream()
    // Gets the input stream of the subprocess. 
    // Implementation code: 482213C5
    object_t object;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: InputStream
    stack_push( 0 );
}

void native_method_lang_process_getoutputstream( void )
{
    // abstract  OutputStream getOutputStream()
    // Gets the output stream of the subprocess. 
    // Implementation code: 8FD38B1F
    object_t object;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: OutputStream
    stack_push( 0 );
}

void native_method_lang_process_waitfor( void )
{
    // abstract  int waitFor()
    // causes the current thread to wait, if necessary, until the 
    // process represented by this Process object has terminated. 
    // Implementation code: BC74C959
    object_t object;
    int32_t ret_value = 0;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push( value_create( &ret_value, T_INT ) );
}

///////////////////////////////////////////////////////////////////////////

uint32_t native_lang_process_get_superclass( void )
{
	return NATIVE_CLASS_LANG_OBJECT;
}

void native_lang_process_invoke(uint16_t mref)
{
    switch( mref )
    {
        case NATIVE_LANG_PROCESS_INIT:
            native_method_lang_process_init();
            break;

        case NATIVE_LANG_PROCESS_DESTROY:
            native_method_lang_process_destroy();
            break;

        case NATIVE_LANG_PROCESS_EXITVALUE:
            native_method_lang_process_exitvalue();
            break;

        case NATIVE_LANG_PROCESS_GETERRORSTREAM:
            native_method_lang_process_geterrorstream();
            break;

        case NATIVE_LANG_PROCESS_GETINPUTSTREAM:
            native_method_lang_process_getinputstream();
            break;

        case NATIVE_LANG_PROCESS_GETOUTPUTSTREAM:
            native_method_lang_process_getoutputstream();
            break;

        case NATIVE_LANG_PROCESS_WAITFOR:
            native_method_lang_process_waitfor();
            break;

        default:
            exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
            break;

    }
}


