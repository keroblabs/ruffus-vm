#include "io_fileoutputstream.h"
#include "heap.h"
#include "application.h"
#include "threads.h"
#include "exceptions.h"
#include "native.h"
#include "objects.h"
#include "stack.h"
#include "value_type.h"
#include "arrays_type.h"
#include "strings.h"
#include "file_module.h"

///////////////////////////////////////////////////////////////////////////

// use New method implementation to hold a method
// use New implementation to mark start block
// use End new implementation to mark end block to keep

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////

object_t native_io_fileoutputstream_new( void )
{
    return( object_create( GET_CLASS_REF( NATIVE_CLASS_IO_FILEOUTPUTSTREAM ), T_CLASS, NATIVE_IO_FILEOUTPUTSTREAM_TOTAL_FIELDS ) );
}

///////////////////////////////////////////////////////////////////////////

void native_method_io_fileoutputstream_init_file( void )
{
    // FileOutputStream(File file)
    // Creates a file output stream to write to the file represented 
    // by the specified File object. 
    // Implementation code: 3532D96E
    object_t file_file;
    object_t object;
    object_t * fields_obj;
    char * path;    
	file_stream_t * fp_file;
    
    file_file = stack_peek(0);
    object = stack_peek(1);

    // put your code here
    fields_obj = object_get_fields_ptr( file_file );
    path = strings_get_text_ptr( fields_obj[ NATIVE_FIELD_IO_FILE_PATH ] );
    
    object_create_extension( object, sizeof( file_stream_t ) );
    fp_file = ( file_stream_t * )object_get_extension( object );
    
	if( vm_file_open( fp_file, path, vm_open_write ) != VM_FILE_OK )
    {
        exception_new( NATIVE_CLASS_THROW_IO_FILENOTFOUNDEXCEPTION, "File not found or unable to process" );
    }
    
    stack_remove(2);
}

void native_method_io_fileoutputstream_init_file_boolean( void )
{
    // FileOutputStream(File file, boolean append)
    // Creates a file output stream to write to the file represented 
    // by the specified File object. 
    // Implementation code: 3532D96E
    object_t file_file;
    object_t boolean_append;
    object_t object;
    object_t * fields_obj;
    char * path;    
	file_stream_t * fp_file;
    
    boolean_append = stack_peek(0);
    file_file = stack_peek(1);
    object = stack_peek(2);

    // put your code here
    // put your code here
    fields_obj = object_get_fields_ptr( file_file );
    path = strings_get_text_ptr( fields_obj[ NATIVE_FIELD_IO_FILE_PATH ] );
    
    object_create_extension( object, sizeof( file_stream_t ) );
	fp_file = ( file_stream_t * )object_get_extension( object );
    
	if( vm_file_open( fp_file, path, vm_open_write ) != VM_FILE_OK )
    {
        exception_new( NATIVE_CLASS_THROW_IO_FILENOTFOUNDEXCEPTION, "File not found or unable to process" );
    }
    
    stack_remove(3);
}

void native_method_io_fileoutputstream_init_filedescriptor( void )
{
    // FileOutputStream(FileDescriptor fdObj)
    // Creates an output file stream to write to the specified 
    // file descriptor, which represents an existing connection 
    // to an actual file in the file system. 
    // Implementation code: A1C3BB73
    object_t filedescriptor_fdobj;
    object_t object;

    filedescriptor_fdobj = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_io_fileoutputstream_init_string( void )
{
    // FileOutputStream(String name)
    // Creates an output file stream to write to the file with 
    // the specified name. 
    // Implementation code: A0A3E05C
    object_t string_name;
    object_t object;
    char * path;
	file_stream_t * fp_file;

    string_name = stack_peek(0);
    object = stack_peek(1);

    // put your code here
    path = strings_get_text_ptr( string_name );
    
	object_create_extension( object, sizeof( file_stream_t ) );
	fp_file = ( file_stream_t * )object_get_extension( object );
    
	if( vm_file_open( fp_file, path, vm_open_write ) != VM_FILE_OK )
    {
        exception_new( NATIVE_CLASS_THROW_IO_FILENOTFOUNDEXCEPTION, "File not found or unable to process" );
    }
    
    stack_remove(2);
}

void native_method_io_fileoutputstream_init_string_boolean( void )
{
    // FileOutputStream(String name, boolean append)
    // Creates an output file stream to write to the file with 
    // the specified name. 
    // Implementation code: A0A3E05C
    object_t string_name;
    object_t boolean_append;
    object_t object;
    file_mode_t mode;
    char * path;
	file_stream_t * fp_file;
    
    boolean_append = stack_peek(0);
    string_name = stack_peek(1);
    object = stack_peek(2);

    // put your code here
    path = strings_get_text_ptr( string_name );
    
	object_create_extension( object, sizeof( file_stream_t ) );
	fp_file = ( file_stream_t * )object_get_extension( object );
    
    mode = vm_open_write;
    if( value_get_boolean( boolean_append ) == TRUE ) mode = vm_open_append;
    
	if( vm_file_open( fp_file, path, mode ) != VM_FILE_OK )
    {
        exception_new( NATIVE_CLASS_THROW_IO_FILENOTFOUNDEXCEPTION, "File not found or unable to process" );
    }
    
    stack_remove(2);
}

///////////////////////////////////////////////////////////////////////////

void native_method_io_fileoutputstream_close( void )
{
    // void close()
    // Closes this file output stream and releases any system resources 
    // associated with this stream. 
    // Implementation code: 63381F3B
    object_t object;
    file_stream_t * fp_file;
    
    object = stack_peek(0);

    // put your code here
    fp_file = ( file_stream_t * )object_get_extension( object );
    vm_file_close( fp_file );
    
    stack_remove(1);
}

void native_method_io_fileoutputstream_finalize( void )
{
    // protected  void finalize()
    // Cleans up the connection to the file, and ensures that the 
    // close method of this file output stream is called when there 
    // are no more references to this stream. 
    // Implementation code: 7FAE4497
    object_t object;
    file_stream_t * fp_file;
    
    object = stack_peek(0);

    // put your code here
    fp_file = ( file_stream_t * )object_get_extension( object );
    vm_file_close( fp_file );
    
    stack_remove(1);
}

void native_method_io_fileoutputstream_flush( void )
{
    // void flush()
    // Flushes this output stream and forces any buffered output 
    // bytes to be written out. 
	// for Tima system: this method only returns when buffer is flushed
    // Implementation code: 86111919
    object_t object;
    file_stream_t * fp_file;
    
    object = stack_peek(0);

    // put your code here
    fp_file = ( file_stream_t * )object_get_extension( object );
    vm_file_flush( fp_file );
    
    stack_remove(1);
}


void native_method_io_fileoutputstream_getfd( void )
{
    // FileDescriptor getFD()
    // Returns the file descriptor associated with this stream. 
    // Implementation code: 355EADD1
    object_t object;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: FileDescriptor
    stack_push( 0 );
}

void native_method_io_fileoutputstream_write_array_byte( void )
{
    // void write(byte[] b)
    // Writes b.length bytes from the specified byte array to this 
    // file output stream. 
    // Implementation code: 07D85444
    object_t byte_array_b;
    object_t object;
    file_stream_t * fp_file;
    uint8_t * buf;
    uint32_t len;
    
    byte_array_b = stack_peek(0);
    object = stack_peek(1);

    // put your code here
	fp_file = ( file_stream_t * )object_get_extension( object );  
    buf = object_get_ptr( byte_array_b );
    len = array_get_capacity( byte_array_b );
    vm_file_write( buf, len, 1, fp_file );
    
    stack_remove(2);
}

void native_method_io_fileoutputstream_write_array_byte_int_int( void )
{
    // void write(byte[] b, int off, int len)
    // Writes len bytes from the specified byte array starting 
    // at offset off to this file output stream. 
    // Implementation code: E6E4F2C7
    object_t byte_array_b;
    object_t int_off;
    object_t int_len;
    object_t object;
	file_stream_t * fp_file;
    uint8_t * buf;
    uint32_t len;
    int32_t int_off_val = 0;
    int32_t int_len_val = 0;    
    
    int_len = stack_peek(0);
    int_off = stack_peek(1);
    byte_array_b = stack_peek(2);
    object = stack_peek(3);

    // put your code here
	fp_file = ( file_stream_t * )object_get_extension( object );  
    buf = object_get_ptr( byte_array_b );
    len = array_get_capacity( byte_array_b );
    
    int_off_val = value_get_int( int_off );
    int_len_val = value_get_int( int_len );
    
    if( ( int_off_val + int_len_val ) >= ( int32_t )len )
    {
        exception_new( NATIVE_CLASS_THROW_LANG_ARRAYINDEXOUTOFBOUNDSEXCEPTION, msg_throw_out_of_bounds );
    }
    
    vm_file_write( &buf[int_off_val], int_len_val, 1, fp_file );
    
    stack_remove(4);
}

void native_method_io_fileoutputstream_write_int( void )
{
    // void write(int b)
    // Writes the specified byte to this file output stream. 
    // Implementation code: E7A1BE25
    object_t int_b;
    object_t object;
    file_stream_t * fp_file;
    
    int_b = stack_peek(0);
    object = stack_peek(1);

    // put your code here
    fp_file = ( file_stream_t * )object_get_extension( object );
    vm_file_putc( value_get_as_byte( int_b ), fp_file );
    
    stack_remove(2);
}

///////////////////////////////////////////////////////////////////////////

void native_io_fileoutputstream_invoke(uint16_t mref)
{
    switch( mref )
    {
        case NATIVE_IO_FILEOUTPUTSTREAM_INIT_FILE:
            native_method_io_fileoutputstream_init_file();
            break;

        case NATIVE_IO_FILEOUTPUTSTREAM_INIT_FILE_BOOLEAN:
            native_method_io_fileoutputstream_init_file_boolean();
            break;

        case NATIVE_IO_FILEOUTPUTSTREAM_INIT_FILEDESCRIPTOR:
            native_method_io_fileoutputstream_init_filedescriptor();
            break;

        case NATIVE_IO_FILEOUTPUTSTREAM_INIT_STRING:
            native_method_io_fileoutputstream_init_string();
            break;

        case NATIVE_IO_FILEOUTPUTSTREAM_INIT_STRING_BOOLEAN:
            native_method_io_fileoutputstream_init_string_boolean();
            break;

        case NATIVE_IO_FILEOUTPUTSTREAM_CLOSE:
            native_method_io_fileoutputstream_close();
            break;

        case NATIVE_IO_FILEOUTPUTSTREAM_FINALIZE:
            native_method_io_fileoutputstream_finalize();
            break;

        case NATIVE_IO_FILEOUTPUTSTREAM_FLUSH:
            native_method_io_fileoutputstream_flush();
            break;

        case NATIVE_IO_FILEOUTPUTSTREAM_GETFD:
            native_method_io_fileoutputstream_getfd();
            break;

        case NATIVE_IO_FILEOUTPUTSTREAM_WRITE_ARRAY_BYTE:
            native_method_io_fileoutputstream_write_array_byte();
            break;

        case NATIVE_IO_FILEOUTPUTSTREAM_WRITE_ARRAY_BYTE_INT_INT:
            native_method_io_fileoutputstream_write_array_byte_int_int();
            break;

        case NATIVE_IO_FILEOUTPUTSTREAM_WRITE_INT:
            native_method_io_fileoutputstream_write_int();
            break;

        default:
            exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
            break;

    }
}


