#include "io_inputstream.h"
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

object_t native_io_inputstream_new( void )
{
    return( object_create( GET_CLASS_REF( NATIVE_CLASS_IO_INPUTSTREAM ), T_CLASS, NATIVE_IO_INPUTSTREAM_TOTAL_FIELDS ) );
}

///////////////////////////////////////////////////////////////////////////

void native_method_io_inputstream_init( void )
{
    // InputStream()
    //  
    // Implementation code: 2D2816FE
    object_t object;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

///////////////////////////////////////////////////////////////////////////

void native_method_io_inputstream_available( void )
{
    // int available()
    // Returns an estimate of the number of bytes that can be read 
    // (or skipped over) from this input stream without blocking 
    // by the next invocation of a method for this input stream. 
    // Implementation code: 23E35803
    object_t object;
    object_t ret_object;
    int32_t ret_value = 0;

    object = stack_peek(0);

    // return type: int
    ret_object = value_create_int( ret_value );
    stack_remove(1);
    stack_push( ret_object );
}

void native_method_io_inputstream_close( void )
{
    // void close()
    // Closes this input stream and releases any system resources 
    // associated with the stream. 
    // Implementation code: 88FD9DE0
    object_t object;

    object = stack_pop();
}

void native_method_io_inputstream_mark_int( void )
{
    // void mark(int readlimit)
    // Marks the current position in this input stream. 
    // Implementation code: B04DFFA1
    object_t int_readlimit;
    object_t object;

    int_readlimit = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_io_inputstream_marksupported( void )
{
    // boolean markSupported()
    // Tests if this input stream supports the mark and reset methods. 
    // Implementation code: 4BD1CFAA
    object_t object;
    bool_t ret_value = 0;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: boolean
    stack_push( value_create( &ret_value, T_BOOLEAN ) );
}

void native_method_io_inputstream_read( void )
{
    // abstract  int read()
    // Reads the next byte of data from the input stream. 
    // Implementation code: 8AE21265
    object_t object;
    object_t ret_object;
    int32_t ret_value = 0;

    object = stack_peek(0);

    // return type: int
    ret_object = value_create_int( ret_value );
    stack_remove(1);
    stack_push( ret_object );    
}

void native_method_io_inputstream_read_array_byte( void )
{
    // int read(byte[] b)
    // Reads some number of bytes from the input stream and stores 
    // them into the buffer array b. 
    // Implementation code: 82AD6EE5
    object_t byte_array_b;
    object_t object;
    int32_t ret_value = 0;

    byte_array_b = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push( value_create( &ret_value, T_INT ) );
}

void native_method_io_inputstream_read_array_byte_int_int( void )
{
    // int read(byte[] b, int off, int len)
    // Reads up to len bytes of data from the input stream into 
    // an array of bytes. 
    // Implementation code: 36761C4D
    object_t byte_array_b;
    object_t int_off;
    object_t int_len;
    object_t object;
    int32_t ret_value = 0;

    int_len = stack_pop();
    int_off = stack_pop();
    byte_array_b = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push( value_create( &ret_value, T_INT ) );
}

void native_method_io_inputstream_reset( void )
{
    // void reset()
    // Repositions this stream to the position at the time the 
    // mark method was last called on this input stream. 
    // Implementation code: 1E4823AB
    object_t object;

    object = stack_pop();
}

void native_method_io_inputstream_skip_long( void )
{
    // long skip(long n)
    // Skips over and discards n bytes of data from this input 
    // stream. 
    // Implementation code: 6993CAFC
    object_t long_n;
    object_t object;
    int64_t ret_value = 0L;

    long_n = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: long
    stack_push( value_create( &ret_value, T_LONG ) );
}

///////////////////////////////////////////////////////////////////////////

void native_io_inputstream_invoke(uint16_t mref)
{
    switch( mref )
    {
        case NATIVE_IO_INPUTSTREAM_INIT:
            native_method_io_inputstream_init();
            break;

        case NATIVE_IO_INPUTSTREAM_AVAILABLE:
            native_method_io_inputstream_available();
            break;

        case NATIVE_IO_INPUTSTREAM_CLOSE:
            native_method_io_inputstream_close();
            break;

        case NATIVE_IO_INPUTSTREAM_MARK_INT:
            native_method_io_inputstream_mark_int();
            break;

        case NATIVE_IO_INPUTSTREAM_MARKSUPPORTED:
            native_method_io_inputstream_marksupported();
            break;

        case NATIVE_IO_INPUTSTREAM_READ:
            native_method_io_inputstream_read();
            break;

        case NATIVE_IO_INPUTSTREAM_READ_ARRAY_BYTE:
            native_method_io_inputstream_read_array_byte();
            break;

        case NATIVE_IO_INPUTSTREAM_READ_ARRAY_BYTE_INT_INT:
            native_method_io_inputstream_read_array_byte_int_int();
            break;

        case NATIVE_IO_INPUTSTREAM_RESET:
            native_method_io_inputstream_reset();
            break;

        case NATIVE_IO_INPUTSTREAM_SKIP_LONG:
            native_method_io_inputstream_skip_long();
            break;

        default:
            exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
            break;

    }
}


