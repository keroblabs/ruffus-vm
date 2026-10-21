#include "io_outputstream.h"
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

object_t native_io_outputstream_new( void )
{
    return( object_create( GET_CLASS_REF( NATIVE_CLASS_IO_OUTPUTSTREAM ), T_CLASS, NATIVE_IO_OUTPUTSTREAM_TOTAL_FIELDS ) );
}

///////////////////////////////////////////////////////////////////////////

void native_method_io_outputstream_init( void )
{
    // OutputStream()
    //  
    // Implementation code: 2D2816FE
    object_t object;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

///////////////////////////////////////////////////////////////////////////

void native_method_io_outputstream_close( void )
{
    // void close()
    // Closes this output stream and releases any system resources 
    // associated with this stream. 
    // Implementation code: 8A90D7EE
    object_t object;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_io_outputstream_flush( void )
{
    // void flush()
    // Flushes this output stream and forces any buffered output 
    // bytes to be written out. 
    // Implementation code: 86111919
    object_t object;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_io_outputstream_write_array_byte( void )
{
    // void write(byte[] b)
    // Writes b.length bytes from the specified byte array to this 
    // output stream. 
    // Implementation code: 03423335
    object_t byte_array_b;
    object_t object;

    byte_array_b = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_io_outputstream_write_array_byte_int_int( void )
{
    // void write(byte[] b, int off, int len)
    // Writes len bytes from the specified byte array starting 
    // at offset off to this output stream. 
    // Implementation code: F9AB34AF
    object_t byte_array_b;
    object_t int_off;
    object_t int_len;
    object_t object;

    int_len = stack_pop();
    int_off = stack_pop();
    byte_array_b = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_io_outputstream_write_int( void )
{
    // abstract  void write(int b)
    // Writes the specified byte to this output stream. 
    // Implementation code: E077107E
    object_t int_b;
    object_t object;

    int_b = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

///////////////////////////////////////////////////////////////////////////

void native_io_outputstream_invoke(uint16_t mref)
{
    switch( mref )
    {
        case NATIVE_IO_OUTPUTSTREAM_INIT:
            native_method_io_outputstream_init();
            break;

        case NATIVE_IO_OUTPUTSTREAM_CLOSE:
            native_method_io_outputstream_close();
            break;

        case NATIVE_IO_OUTPUTSTREAM_FLUSH:
            native_method_io_outputstream_flush();
            break;

        case NATIVE_IO_OUTPUTSTREAM_WRITE_ARRAY_BYTE:
            native_method_io_outputstream_write_array_byte();
            break;

        case NATIVE_IO_OUTPUTSTREAM_WRITE_ARRAY_BYTE_INT_INT:
            native_method_io_outputstream_write_array_byte_int_int();
            break;

        case NATIVE_IO_OUTPUTSTREAM_WRITE_INT:
            native_method_io_outputstream_write_int();
            break;

        default:
            exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
            break;

    }
}


