#include "io_fileinputstream.h"
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

object_t native_io_fileinputstream_new( void )
{
    return( object_create( GET_CLASS_REF( NATIVE_CLASS_IO_FILEINPUTSTREAM ), T_CLASS, NATIVE_IO_FILEINPUTSTREAM_TOTAL_FIELDS ) );
}

///////////////////////////////////////////////////////////////////////////

void native_method_io_fileinputstream_init_file( void )
{
    // FileInputStream(File file)
    // Creates a FileInputStream by opening a connection to an 
    // actual file, the file named by the File object file in the 
    // file system. 
    // Implementation code: 52B2E8FF
    object_t file_file;
    object_t object;
    object_t * fields;
    object_t * fields_obj;
    char * path;    
    file_stream_t * fp_file;
    
    file_file = stack_peek(0);
    object = stack_peek(1);

    // put your code here
    fields_obj = object_get_fields_ptr( file_file );
    path = strings_get_text_ptr( fields_obj[ NATIVE_FIELD_IO_FILE_PATH ] );
    
    object_create_extension( object, sizeof( file_stream_t ) );
    fields = object_get_fields_ptr( object );
    fields[ NATIVE_FIELD_IO_FILEINPUTSTREAM_MARK ] = value_create_int( 0 );
    fp_file = ( file_stream_t * )object_get_extension( object );
    
	if( vm_file_open( fp_file, path, vm_open_read ) != VM_FILE_OK )
    {
        exception_new( NATIVE_CLASS_THROW_IO_FILENOTFOUNDEXCEPTION, "File not found or unable to process" );
    }
    
    stack_remove(2);
}

void native_method_io_fileinputstream_init_filedescriptor( void )
{
    // FileInputStream(FileDescriptor fdObj)
    // Creates a FileInputStream by using the file descriptor fdObj, 
    // which represents an existing connection to an actual file 
    // in the file system. 
    // Implementation code: 06091689
    object_t filedescriptor_fdobj;
    object_t object;

    filedescriptor_fdobj = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_io_fileinputstream_init_string( void )
{
    // FileInputStream(String name)
    // Creates a FileInputStream by opening a connection to an 
    // actual file, the file named by the path name name in the 
    // file system. 
    // Implementation code: 607D6838
    object_t string_name;
    object_t object;
    object_t * fields;
    char * path;
    file_stream_t * fp_file;

    string_name = stack_peek(0);
    object = stack_peek(1);

    // put your code here
    path = strings_get_text_ptr( string_name );
    
    object_create_extension( object, sizeof( file_stream_t ) );
    fields = object_get_fields_ptr( object );
    fields[ NATIVE_FIELD_IO_FILEINPUTSTREAM_MARK ] = value_create_int( 0 );
    fp_file = ( file_stream_t * )object_get_extension( object );
    
	if( vm_file_open( fp_file, path, vm_open_read ) != VM_FILE_OK )
    {
        exception_new( NATIVE_CLASS_THROW_IO_FILENOTFOUNDEXCEPTION, "File not found or unable to process" );
    }
    
    stack_remove(2);
}

///////////////////////////////////////////////////////////////////////////

void native_method_io_fileinputstream_available( void )
{
    // int available()
    // Returns an estimate of the number of remaining bytes that 
    // can be read (or skipped over) from this input stream without 
    // blocking by the next invocation of a method for this input 
    // stream. 
    // Implementation code: 08764544
    object_t object;
    object_t ret_object;
    int32_t ret_value = 0;
	file_stream_t * fp_file;
    
    object = stack_peek(0);

    // put your code here
	fp_file = ( file_stream_t * )object_get_extension( object );
	ret_value = vm_file_get_size( fp_file );
	ret_value -= vm_file_get_pos( fp_file );

    // return type: int
    ret_object = value_create( &ret_value, T_INT );
    stack_remove(1);
    stack_push( ret_object );
}

void native_method_io_fileinputstream_close( void )
{
    // void close()
    // Closes this file input stream and releases any system resources 
    // associated with the stream. 
    // Implementation code: 33F85D00
    object_t object;
    file_stream_t * fp_file;
    
    object = stack_peek(0);

    // put your code here
    fp_file = ( file_stream_t * )object_get_extension( object );
    vm_file_close( fp_file );
    stack_remove(1);
}

void native_method_io_fileinputstream_finalize( void )
{
    // protected  void finalize()
    // Ensures that the close method of this file input stream 
    // is called when there are no more references to it. 
    // Implementation code: C8776443
    object_t object;
    file_stream_t * fp_file;
    
    object = stack_peek(0);

    // put your code here
    fp_file = ( file_stream_t * )object_get_extension( object );
    vm_file_close( fp_file );
    stack_remove(1);
}


void native_method_io_fileinputstream_getfd( void )
{
    // FileDescriptor getFD()
    // Returns the FileDescriptor object that represents the connection 
    // to the actual file in the file system being used by this 
    // FileInputStream. 
    // Implementation code: 648AE499
    object_t object;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: FileDescriptor
    stack_push( 0 );
}

void native_method_io_fileinputstream_mark_int( void )
{
    // void mark(int readlimit)
    // Marks the current position in this input stream. 
    // Implementation code: B04DFFA1
    object_t int_readlimit;
    object_t object;
    object_t * fields;
    file_stream_t * fp_file;

    int_readlimit = stack_peek(0);
    object = stack_peek(1);

    // put your code here
    fp_file = ( file_stream_t * )object_get_extension( object );    
    fields = object_get_fields_ptr( object );
    fields[ NATIVE_FIELD_IO_FILEINPUTSTREAM_MARK ] = value_create_int( value_get_int( vm_file_get_pos( fp_file ) ) );
    
    stack_remove(2);
}

void native_method_io_fileinputstream_marksupported( void )
{
    // boolean markSupported()
    // Tests if this input stream supports the mark and reset methods. 
    // Implementation code: 4BD1CFAA
    object_t object;
    object_t ret_object;
    bool_t ret_value = 0;
    file_stream_t * fp_file;
    
    object = stack_peek(0);

    // put your code here
    fp_file = ( file_stream_t * )object_get_extension( object );
    
    #ifdef TIMA_OS
    if( fp_file->fs->type != SYS_DEVICE ) ret_value = TRUE;
    #endif
    
    ret_object = value_create_boolean( ret_value );
    stack_remove(1);
    stack_push( ret_object );
}

void native_method_io_fileinputstream_read( void )
{
    // int read()
    // Reads a byte of data from this input stream. 
    // Implementation code: 6001AE9B
    object_t object;
    object_t ret_object;
    int32_t ret_value = 0;
    file_stream_t * fp_file;
    
    object = stack_peek(0);

    // put your code here
    fp_file = ( file_stream_t * )object_get_extension( object );
    ret_value = vm_file_getc( fp_file );

    // return type: byte
    ret_object = value_create_int( ret_value );
    stack_remove(1);
    stack_push( ret_object );    
}

void native_method_io_fileinputstream_read_array_byte( void )
{
    // int read(byte[] b)
    // Reads up to b.length bytes of data from this input stream 
    // into an array of bytes. 
    // Implementation code: C865CFAF
    object_t byte_array_b;
    object_t object;
    object_t ret_object;    
    int32_t ret_value = 0;
    file_stream_t * fp_file;
    uint8_t * buf;
    uint32_t len;

    byte_array_b = stack_peek(0);
    object = stack_peek(1);

    // put your code here
    fp_file = ( file_stream_t * )object_get_extension( object );  
    buf = object_get_ptr( byte_array_b );
    len = array_get_capacity( byte_array_b );
    ret_value = (int32_t)vm_file_read( buf, len, 1, fp_file );

    // return type: int
    ret_object = value_create_int( ret_value );
    stack_remove(2);
    stack_push( ret_object );    
}

void native_method_io_fileinputstream_read_array_byte_int_int( void )
{
    // int read(byte[] b, int off, int len)
    // Reads up to len bytes of data from this input stream into 
    // an array of bytes. 
    // Implementation code: 9A2700CB
    object_t byte_array_b;
    object_t int_off;
    object_t int_len;
    object_t object;
    object_t ret_object;  
    int32_t ret_value = 0;
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
    
    ret_value = (int32_t)vm_file_read( &buf[int_off_val], int_len_val, 1, fp_file );

    // return type: int
    ret_object = value_create_int( ret_value );
    stack_remove(4);
    stack_push( ret_object );  
}

void native_method_io_fileinputstream_reset( void )
{
    // void reset()
    // Repositions this stream to the position at the time the 
    // mark method was last called on this input stream. 
    // Implementation code: 1E4823AB
    object_t object;
    object_t * fields;
    file_stream_t * fp_file;

    object = stack_peek(0);

    // put your code here
    fp_file = ( file_stream_t * )object_get_extension( object );    
    fields = object_get_fields_ptr( object );
    vm_file_set_pos( fp_file, value_get_int( fields[ NATIVE_FIELD_IO_FILEINPUTSTREAM_MARK ] ) );
    stack_remove(1);
}

void native_method_io_fileinputstream_skip_long( void )
{
    // long skip(long n)
    // Skips over and discards n bytes of data from the input stream. 
    // Implementation code: EBEBAF37
    object_t long_n;
    object_t object;
    object_t ret_object;
    int64_t ret_value = 0L;
    file_stream_t * fp_file;
    int32_t file_pos;
    int32_t skip_n;
    
    long_n = stack_peek(0);
    object = stack_peek(1);

    // put your code here
    fp_file = ( file_stream_t * )object_get_extension( object );    
    skip_n = value_get_as_integer( long_n );
    file_pos = (int32_t)vm_file_get_pos( fp_file );
    vm_file_set_pos( fp_file, file_pos + skip_n );
    ret_value = vm_file_get_pos( fp_file ) - file_pos;
    
    // return type: int
    ret_object = value_create_long( ret_value );
    stack_remove(2);
    stack_push( ret_object );      
}

///////////////////////////////////////////////////////////////////////////

void native_io_fileinputstream_invoke(uint16_t mref)
{
    switch( mref )
    {
        case NATIVE_IO_FILEINPUTSTREAM_INIT_FILE:
            native_method_io_fileinputstream_init_file();
            break;

        case NATIVE_IO_FILEINPUTSTREAM_INIT_FILEDESCRIPTOR:
            native_method_io_fileinputstream_init_filedescriptor();
            break;

        case NATIVE_IO_FILEINPUTSTREAM_INIT_STRING:
            native_method_io_fileinputstream_init_string();
            break;

        case NATIVE_IO_FILEINPUTSTREAM_AVAILABLE:
            native_method_io_fileinputstream_available();
            break;

        case NATIVE_IO_FILEINPUTSTREAM_CLOSE:
            native_method_io_fileinputstream_close();
            break;

        case NATIVE_IO_FILEINPUTSTREAM_FINALIZE:
            native_method_io_fileinputstream_finalize();
            break;

        case NATIVE_IO_FILEINPUTSTREAM_GETFD:
            native_method_io_fileinputstream_getfd();
            break;

        case NATIVE_IO_FILEINPUTSTREAM_MARK_INT:
            native_method_io_fileinputstream_mark_int();
            break;

        case NATIVE_IO_FILEINPUTSTREAM_MARKSUPPORTED:
            native_method_io_fileinputstream_marksupported();
            break;

        case NATIVE_IO_FILEINPUTSTREAM_READ:
            native_method_io_fileinputstream_read();
            break;

        case NATIVE_IO_FILEINPUTSTREAM_READ_ARRAY_BYTE:
            native_method_io_fileinputstream_read_array_byte();
            break;

        case NATIVE_IO_FILEINPUTSTREAM_READ_ARRAY_BYTE_INT_INT:
            native_method_io_fileinputstream_read_array_byte_int_int();
            break;

        case NATIVE_IO_FILEINPUTSTREAM_RESET:
            native_method_io_fileinputstream_reset();
            break;

        case NATIVE_IO_FILEINPUTSTREAM_SKIP_LONG:
            native_method_io_fileinputstream_skip_long();
            break;

        default:
            exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
            break;

    }
}


