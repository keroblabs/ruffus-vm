#include "io_randomaccessfile.h"
#include "heap.h"
#include "application.h"
#include "threads.h"
#include "exceptions.h"
#include "native.h"
#include "objects.h"
#include "stack.h"
#include "value_type.h"
#include "strings.h"
#include "arrays_type.h"
#include "file_module.h"

///////////////////////////////////////////////////////////////////////////

// use New method implementation to hold a method
// use New implementation to mark start block
// use End new implementation to mark end block to keep

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////

object_t native_io_randomaccessfile_new( void )
{
    return( object_create( GET_CLASS_REF( NATIVE_CLASS_IO_RANDOMACCESSFILE ), T_CLASS, NATIVE_IO_RANDOMACCESSFILE_TOTAL_FIELDS ) );
}

///////////////////////////////////////////////////////////////////////////

void native_method_io_randomaccessfile_init_file_string( void )
{
    // RandomAccessFile(File file, String mode)
    // Creates a random access file stream to read from, and optionally 
    // to write to, the file specified by the File argument. 
    // Implementation code: CD0B4026
    object_t file_file;
    object_t string_mode;
    object_t object;
    object_t * fields_obj;
    char * path;    
	file_stream_t * fp_file;
    file_mode_t mode;
    char * mode_str;

    string_mode = stack_peek(0);
    file_file = stack_peek(1);
    object = stack_peek(2);

    // put your code here    
    // it's an instance of devired Thread class, needs an extension
    fields_obj = object_get_fields_ptr( file_file );
    path = strings_get_text_ptr( fields_obj[ NATIVE_FIELD_IO_FILE_PATH ] );
    
	object_create_extension( object, sizeof( file_stream_t ) );
    fp_file = ( file_stream_t * )object_get_extension( object );
    
    mode_str = strings_get_text_ptr( string_mode );
    
    #ifdef TIMA_OS
    if( vm_file_locate_path( path ) == FS_IS_DEVICE ) mode = FS_MODE_DEVICE;
    else
    #endif
		if( !strcmp( mode_str, "r" ) ) mode = vm_open_read;
		else if( !strcmp( mode_str, "rw" ) ) mode = vm_open_random;
    else if( !strcmp( mode_str, "w" ) ) mode = vm_open_write;
    else exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_illegal_argument );
    
	if( vm_file_open( fp_file, path, mode ) != VM_FILE_OK )
    {
        exception_new( NATIVE_CLASS_THROW_IO_FILENOTFOUNDEXCEPTION, "File not found or unable to process" );
    }
    
    stack_remove(3);
}

void native_method_io_randomaccessfile_init_string_string( void )
{
    // RandomAccessFile(String name, String mode)
    // Creates a random access file stream to read from, and optionally 
    // to write to, a file with the specified name. 
    // Implementation code: BA67736A
    object_t string_name;
    object_t string_mode;
    object_t object;
    char * path;    
    file_stream_t * fp_file;
    file_mode_t mode;
    char * mode_str;
    
    string_mode = stack_peek(0);
    string_name = stack_peek(1);
    object = stack_peek(2);

    // put your code here
    path = strings_get_text_ptr( string_name );
    
    object_create_extension( object, sizeof( file_stream_t ) );
    fp_file = ( file_stream_t * )object_get_extension( object );
    
    mode_str = strings_get_text_ptr( string_mode );
    
    #ifdef TIMA_OS
    if( vm_file_locate_path( path ) == FS_IS_DEVICE ) mode = FS_MODE_DEVICE;
    else
    #endif
        if( !strcmp( mode_str, "r" ) ) mode = vm_open_read;
    else if( !strcmp( mode_str, "rw" ) ) mode = vm_open_random;
    else if( !strcmp( mode_str, "w" ) ) mode = vm_open_write;
    else exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_illegal_argument );
    
	if( vm_file_open( fp_file, path, mode ) != VM_FILE_OK )
    {
        exception_new( NATIVE_CLASS_THROW_IO_FILENOTFOUNDEXCEPTION, "File not found or unable to process" );
    }
    
    stack_remove(3);
}

///////////////////////////////////////////////////////////////////////////

void native_method_io_randomaccessfile_close( void )
{
    // void close()
    // Closes this random access file stream and releases any system 
    // resources associated with the stream. 
    // Implementation code: 938A4316
    object_t object;
    file_stream_t * fp_file;
    
    object = stack_peek(0);

    // put your code here
    fp_file = ( file_stream_t * )object_get_extension( object );
    vm_file_close( fp_file );
    
    stack_remove(1);
}



void native_method_io_randomaccessfile_getfilepointer( void )
{
    // long getFilePointer()
    // Returns the current offset in this file. 
    // Implementation code: 7BBF9F85
    object_t object;
    object_t ret_object;
    int64_t ret_value = 0L;
    file_stream_t * fp_file;
    
    object = stack_peek(0);

    // put your code here
    fp_file = ( file_stream_t * )object_get_extension( object );
    ret_value = vm_file_get_pos( fp_file );

    // return type: long
    ret_object = value_create_long( ret_value );
    stack_remove(1);
    stack_push( ret_object );
}

void native_method_io_randomaccessfile_length( void )
{
    // long length()
    // Returns the length of this file. 
    // Implementation code: D163F41E
    object_t object;
    object_t ret_object;
    int64_t ret_value = 0L;
    file_stream_t * fp_file;
    
    object = stack_peek(0);

    // put your code here
    fp_file = ( file_stream_t * )object_get_extension( object );
    ret_value = vm_file_get_size( fp_file );

    // return type: long
    ret_object = value_create_long( ret_value );
    stack_remove(1);
    stack_push( ret_object );
}

void native_method_io_randomaccessfile_read( void )
{
    // int read()
    // Reads a byte of data from this file. 
    // Implementation code: 647C4063
    object_t object;
    object_t ret_object;
    int32_t ret_value = 0;
    file_stream_t * fp_file;
    
    object = stack_peek(0);

    // put your code here
    fp_file = ( file_stream_t * )object_get_extension( object );
    ret_value = vm_file_getc( fp_file );

    // return type: int
    ret_object = value_create_int( ret_value );
    stack_remove(1);
    stack_push( ret_object );    
}

void native_method_io_randomaccessfile_read_array_byte( void )
{
    // int read(byte[] b)
    // Reads up to b.length bytes of data from this file into an 
    // array of bytes. 
    // Implementation code: 0E524866
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
    stack_remove(1);
    stack_push( ret_object ); 
}

void native_method_io_randomaccessfile_read_array_byte_int_int( void )
{
    // int read(byte[] b, int off, int len)
    // Reads up to len bytes of data from this file into an array 
    // of bytes. 
    // Implementation code: A6B2B85A
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

void native_method_io_randomaccessfile_readboolean( void )
{
    // boolean readBoolean()
    // Reads a boolean from this file. 
    // Implementation code: E828467B
    object_t object;
    object_t ret_object;
    bool_t ret_value = 0;
	file_stream_t * fp_file;
    
    object = stack_peek(0);
    
    // put your code here
	fp_file = ( file_stream_t * )object_get_extension( object );
    if( vm_file_eof( fp_file ) == TRUE ) 
    {
        exception_new( NATIVE_CLASS_THROW_IO_EOFEXCEPTION, msg_throw_eof_reached );
    }
    
    ret_value = vm_file_getc( fp_file );

    // return type: boolean
    ret_object = value_create_boolean( ret_value );
    stack_remove(1);
    stack_push( ret_object );     
}

void native_method_io_randomaccessfile_readbyte( void )
{
    // byte readByte()
    // Reads a signed eight-bit value from this file. 
    // Implementation code: 318BF506
    object_t object;
    object_t ret_object;
    uint8_t ret_value = 0;
	file_stream_t * fp_file;
    
    object = stack_peek(0);

    // put your code here
	fp_file = ( file_stream_t * )object_get_extension( object );
    if( vm_file_eof( fp_file ) == TRUE ) 
    {
        exception_new( NATIVE_CLASS_THROW_IO_EOFEXCEPTION, msg_throw_eof_reached );
    }
    
    ret_value = vm_file_getc( fp_file );

    // return type: byte
    ret_object = value_create_byte( ret_value );
    stack_remove(1);
    stack_push( ret_object );      
}

void native_method_io_randomaccessfile_readchar( void )
{
    // char readChar()
    // Reads a character from this file. 
    // Implementation code: 512FA53E
    object_t object;
    object_t ret_object;
    char ret_value = '?';
	file_stream_t * fp_file;
    
    object = stack_peek(0);

    // put your code here
	fp_file = ( file_stream_t * )object_get_extension( object );
    if( vm_file_eof( fp_file ) == TRUE ) 
    {
        exception_new( NATIVE_CLASS_THROW_IO_EOFEXCEPTION, msg_throw_eof_reached );
    }
    
    ret_value = vm_file_getc( fp_file );

    // return type: char
    ret_object = value_create_character( ret_value );
    stack_remove(1);
    stack_push( ret_object );     
}

void native_method_io_randomaccessfile_readdouble( void )
{
    // double readDouble()
    // Reads a double from this file. 
    // Implementation code: C2066558
    object_t object;
    object_t ret_object;
    double ret_value = 0.0;
	file_stream_t * fp_file;
    
    object = stack_peek(0);

    // put your code here
    fp_file = ( file_stream_t * )object_get_extension( object );
    if( vm_file_eof( fp_file ) == TRUE ) 
    {
        exception_new( NATIVE_CLASS_THROW_IO_EOFEXCEPTION, msg_throw_eof_reached );
    }
    
    vm_file_read( ( uint8_t * )&ret_value, sizeof( ret_value ), 1, fp_file );

    // return type: double
    ret_object = value_create_double( ret_value );
    stack_remove(1);
    stack_push( ret_object );     
}

void native_method_io_randomaccessfile_readfloat( void )
{
    // float readFloat()
    // Reads a float from this file. 
    // Implementation code: AB7E1857
    object_t object;
    object_t ret_object;
    float ret_value = 0.0;
    file_stream_t * fp_file;
    
    object = stack_peek(0);

    // put your code here
    fp_file = ( file_stream_t * )object_get_extension( object );
    if( vm_file_eof( fp_file ) == TRUE ) 
    {
        exception_new( NATIVE_CLASS_THROW_IO_EOFEXCEPTION, msg_throw_eof_reached );
    }
    
    vm_file_read( ( uint8_t * )&ret_value, sizeof( ret_value ), 1, fp_file );

    // return type: float
    ret_object = value_create_float( ret_value );
    stack_remove(1);
    stack_push( ret_object );  
}

void native_method_io_randomaccessfile_readfully_array_byte( void )
{
    // void readFully(byte[] b)
    // Reads b.length bytes from this file into the byte array, 
    // starting at the current file pointer. 
    // Implementation code: CB769DF7
    object_t byte_array_b;
    object_t object;

    byte_array_b = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_io_randomaccessfile_readfully_array_byte_int_int( void )
{
    // void readFully(byte[] b, int off, int len)
    // Reads exactly len bytes from this file into the byte array, 
    // starting at the current file pointer. 
    // Implementation code: 1D26F067
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

void native_method_io_randomaccessfile_readint( void )
{
    // int readInt()
    // Reads a signed 32-bit integer from this file. 
    // Implementation code: 80BCCE63
    object_t object;
    object_t ret_object;
    int32_t ret_value = 0;
	file_stream_t * fp_file;
    
    object = stack_peek(0);

    // put your code here
	fp_file = ( file_stream_t * )object_get_extension( object );
    if( vm_file_eof( fp_file ) == TRUE ) 
    {
        exception_new( NATIVE_CLASS_THROW_IO_EOFEXCEPTION, msg_throw_eof_reached );
    }
    
    vm_file_read( ( uint8_t * )&ret_value, sizeof( ret_value ), 1, fp_file );

    // return type: int
    ret_object = value_create_int( ret_value );
    stack_remove(1);
    stack_push( ret_object );     
}


void native_method_io_randomaccessfile_readlong( void )
{
    // long readLong()
    // Reads a signed 64-bit integer from this file. 
    // Implementation code: 7229927E
    object_t object;
    object_t ret_object;
    int64_t ret_value = 0L;
	file_stream_t * fp_file;
    
    object = stack_peek(0);

    // put your code here
	fp_file = ( file_stream_t * )object_get_extension( object );
    if( vm_file_eof( fp_file ) == TRUE ) 
    {
        exception_new( NATIVE_CLASS_THROW_IO_EOFEXCEPTION, msg_throw_eof_reached );
    }
    
    vm_file_read( ( uint8_t * )&ret_value, sizeof( ret_value ), 1, fp_file );

    // return type: long
    ret_object = value_create_long( ret_value );
    stack_remove(1);
    stack_push( ret_object );     
}

void native_method_io_randomaccessfile_readshort( void )
{
    // short readShort()
    // Reads a signed 16-bit number from this file. 
    // Implementation code: 58993D00
    object_t object;
    object_t ret_object;
    int16_t ret_value = 0;
    file_stream_t * fp_file;
    
    object = stack_peek(0);

    // put your code here
	fp_file = ( file_stream_t * )object_get_extension( object );
    if( vm_file_eof( fp_file ) == TRUE ) 
    {
        exception_new( NATIVE_CLASS_THROW_IO_EOFEXCEPTION, msg_throw_eof_reached );
    }
    
    vm_file_read( ( uint8_t * )&ret_value, sizeof( ret_value ), 1, fp_file );

    // return type: short
    ret_object = value_create_short( ret_value );
    stack_remove(1);
    stack_push( ret_object );     
}

void native_method_io_randomaccessfile_readunsignedbyte( void )
{
    // int readUnsignedByte()
    // Reads an unsigned eight-bit number from this file. 
    // Implementation code: 13737A17
    object_t object;
    object_t ret_object;
    int32_t ret_value = 0;
    file_stream_t * fp_file;
    
    object = stack_peek(0);

    // put your code here
    fp_file = ( file_stream_t * )object_get_extension( object );
    if( vm_file_eof( fp_file ) == TRUE ) 
    {
        exception_new( NATIVE_CLASS_THROW_IO_EOFEXCEPTION, msg_throw_eof_reached );
    }
    
    ret_value = vm_file_getc( fp_file );

    // return type: int
    ret_object = value_create_int( ret_value );
    stack_remove(1);
    stack_push( ret_object );  
}

void native_method_io_randomaccessfile_readunsignedshort( void )
{
    // int readUnsignedShort()
    // Reads an unsigned 16-bit number from this file. 
    // Implementation code: B74B3BBE
    object_t object;
    object_t ret_object;
    int32_t ret_value = 0;
    file_stream_t * fp_file;
    
    object = stack_peek(0);

    // put your code here
    fp_file = ( file_stream_t * )object_get_extension( object );
    if( vm_file_eof( fp_file ) == TRUE ) 
    {
        exception_new( NATIVE_CLASS_THROW_IO_EOFEXCEPTION, msg_throw_eof_reached );
    }
    
    vm_file_read( ( uint8_t * )&ret_value, 2, 1, fp_file );

    // return type: int
    ret_object = value_create_int( ret_value );
    stack_remove(1);
    stack_push( ret_object );  
}


void native_method_io_randomaccessfile_seek_long( void )
{
    // void seek(long pos)
    // Sets the file-pointer offset, measured from the beginning 
    // of this file, at which the next read or write occurs. 
    // Implementation code: BD41B264
    object_t long_pos;
    object_t object;
    file_stream_t * fp_file;
    
    long_pos = stack_peek(0);
    object = stack_peek(1);

    // put your code here
    fp_file = ( file_stream_t * )object_get_extension( object );
    vm_file_set_pos( fp_file, (uint32_t)value_get_long( long_pos ) );
    
    stack_remove(2);
}

void native_method_io_randomaccessfile_setlength_long( void )
{
    // void setLength(long newLength)
    // Sets the length of this file. 
    // Implementation code: E18249F3
    object_t long_newlength;
    object_t object;

    long_newlength = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_io_randomaccessfile_skipbytes_int( void )
{
    // int skipBytes(int n)
    // Attempts to skip over n bytes of input discarding the skipped 
    // bytes. 
    // Implementation code: 46549FCF
    object_t int_n;
    object_t object;
    object_t ret_object;
    int32_t ret_value = 0;
    file_stream_t * fp_file;
    int32_t file_pos;
    int32_t skip_n;
    
    int_n = stack_peek(0);
    object = stack_peek(1);

    // put your code here
    fp_file = ( file_stream_t * )object_get_extension( object );    
    skip_n = value_get_int( int_n );
    file_pos = (int32_t)vm_file_get_pos( fp_file );
    vm_file_set_pos( fp_file, file_pos + skip_n );
    ret_value = vm_file_get_pos( fp_file ) - file_pos;
    
    // return type: int
    ret_object = value_create_int( ret_value );
    stack_remove(2);
    stack_push( ret_object );      
}

void native_method_io_randomaccessfile_write_array_byte( void )
{
    // void write(byte[] b)
    // Writes b.length bytes from the specified byte array to this 
    // file, starting at the current file pointer. 
    // Implementation code: CE580697
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

void native_method_io_randomaccessfile_write_array_byte_int_int( void )
{
    // void write(byte[] b, int off, int len)
    // Writes len bytes from the specified byte array starting 
    // at offset off to this file. 
    // Implementation code: 0746A321
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

void native_method_io_randomaccessfile_write_int( void )
{
    // void write(int b)
    // Writes the specified byte to this file. 
    // Implementation code: A089DFEA
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

void native_method_io_randomaccessfile_writeboolean_boolean( void )
{
    // void writeBoolean(boolean v)
    // Writes a boolean to the file as a one-byte value. 
    // Implementation code: DD6ABE44
    object_t boolean_v;
    object_t object;
    file_stream_t * fp_file;

    boolean_v = stack_peek(0);
    object = stack_peek(1);

    // put your code here
    fp_file = ( file_stream_t * )object_get_extension( object );
    vm_file_putc( value_get_boolean( boolean_v ), fp_file );
    
    stack_remove(2);
}

void native_method_io_randomaccessfile_writebyte_int( void )
{
    // void writeByte(int v)
    // Writes a byte to the file as a one-byte value. 
    // Implementation code: D9F1D629
    object_t int_v;
    object_t object;
    file_stream_t * fp_file;

    int_v = stack_peek(0);
    object = stack_peek(1);

    // put your code here
    fp_file = ( file_stream_t * )object_get_extension( object );
    vm_file_putc( value_get_as_byte( int_v ), fp_file );
    
    stack_remove(2);
}

void native_method_io_randomaccessfile_writebytes_string( void )
{
    // void writeBytes(String s)
    // Writes the string to the file as a sequence of bytes. 
    // Implementation code: A68C467A
    object_t string_s;
    object_t object;
    file_stream_t * fp_file;

    string_s = stack_peek(0);
    object = stack_peek(1);
    
    // put your code here
    fp_file = ( file_stream_t * )object_get_extension( object );
    vm_file_puts( strings_get_text_ptr( string_s ), fp_file );
    
    stack_remove(2);
}

void native_method_io_randomaccessfile_writechar_int( void )
{
    // void writeChar(int v)
    // Writes a char to the file as a two-byte value, high byte 
    // first. 
    // Implementation code: 77A08A41
    object_t int_v;
    object_t object;
	file_stream_t * fp_file;
    int16_t value_v;
    
    int_v = stack_peek(0);
    object = stack_peek(1);

    // put your code here
	fp_file = ( file_stream_t * )object_get_extension( object );
    value_v = value_get_as_short( int_v );
    vm_file_write( ( uint8_t * )&value_v, sizeof( value_v ), 1, fp_file );
    
    stack_remove(2);
}

void native_method_io_randomaccessfile_writechars_string( void )
{
    // void writeChars(String s)
    // Writes a string to the file as a sequence of characters. 
    // Implementation code: 4C5604CF
    object_t string_s;
    object_t object;
    file_stream_t * fp_file;

    string_s = stack_peek(0);
    object = stack_peek(1);

    // put your code here
    fp_file = ( file_stream_t * )object_get_extension( object );
    vm_file_puts( strings_get_text_ptr( string_s ), fp_file );
    
    stack_remove(2);
}

void native_method_io_randomaccessfile_writedouble_double( void )
{
    // void writeDouble(double v)
    // Converts the double argument to a long using the doubleToLongBits 
    // method in class Double, and then writes that long value 
    // to the file as an eight-byte quantity, high byte first. 
    // Implementation code: C178F45F
    object_t double_v;
    object_t object;
    double value_v;
	file_stream_t * fp_file;
    
    double_v = stack_peek(0);
    object = stack_peek(1);

    // put your code here
	fp_file = ( file_stream_t * )object_get_extension( object );
    value_v = value_get_double( double_v );
    vm_file_write( ( uint8_t * )&value_v, sizeof( value_v ), 1, fp_file );
    
    stack_remove(2);
}

void native_method_io_randomaccessfile_writefloat_float( void )
{
    // void writeFloat(float v)
    // Converts the float argument to an int using the floatToIntBits 
    // method in class Float, and then writes that int value to 
    // the file as a four-byte quantity, high byte first. 
    // Implementation code: 160F6C03
    object_t float_v;
    object_t object;
    float value_v;
    file_stream_t * fp_file;
    
    float_v = stack_peek(0);
    object = stack_peek(1);

    // put your code here
    fp_file = ( file_stream_t * )object_get_extension( object );
    value_v = ( float )value_get_double( float_v );
    vm_file_write( ( uint8_t * )&value_v, sizeof( value_v ), 1, fp_file );
    
    stack_remove(2);
}

void native_method_io_randomaccessfile_writeint_int( void )
{
    // void writeInt(int v)
    // Writes an int to the file as four bytes, high byte first. 
    // Implementation code: 7710927F
    object_t int_v;
    object_t object;
	file_stream_t * fp_file;
    int32_t value_v;

    int_v = stack_peek(0);
    object = stack_peek(1);

    // put your code here
	fp_file = ( file_stream_t * )object_get_extension( object );
    value_v = value_get_int( int_v );
    vm_file_write( ( uint8_t * )&value_v, sizeof( value_v ), 1, fp_file );
    
    stack_remove(2);
}

void native_method_io_randomaccessfile_writelong_long( void )
{
    // void writeLong(long v)
    // Writes a long to the file as eight bytes, high byte first. 
    // Implementation code: 2225EE25
    object_t long_v;
    object_t object;
    file_stream_t * fp_file;
    int64_t value_v;
    
    long_v = stack_peek(0);
    object = stack_peek(1);

    // put your code here
    fp_file = ( file_stream_t * )object_get_extension( object );
    value_v = value_get_long( long_v );
    vm_file_write( ( uint8_t * )&value_v, sizeof( value_v ), 1, fp_file );
    
    stack_remove(2);
}

void native_method_io_randomaccessfile_writeshort_int( void )
{
    // void writeShort(int v)
    // Writes a short to the file as two bytes, high byte first. 
    // Implementation code: 7D131057
    object_t int_v;
    object_t object;
	file_stream_t * fp_file;
    int16_t value_v;
    
    int_v = stack_peek(0);
    object = stack_peek(1);

    // put your code here
    fp_file = ( file_stream_t * )object_get_extension( object );
    value_v = value_get_short( int_v );
    vm_file_write( ( uint8_t * )&value_v, sizeof( value_v ), 1, fp_file );
    
    stack_remove(2);
}

void native_method_io_randomaccessfile_writeutf_string( void )
{
    // void writeUTF(String str)
    // Writes a string to the file using modified UTF-8 encoding 
    // in a machine-independent manner. 
    // Implementation code: CEAD402E
    object_t string_str;
    object_t object;

    string_str = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

///////////////////////////////////////////////////////////////////////////

void native_io_randomaccessfile_invoke(uint16_t mref)
{
    switch( mref )
    {
        case NATIVE_IO_RANDOMACCESSFILE_INIT_FILE_STRING:
            native_method_io_randomaccessfile_init_file_string();
            break;

        case NATIVE_IO_RANDOMACCESSFILE_INIT_STRING_STRING:
            native_method_io_randomaccessfile_init_string_string();
            break;

        case NATIVE_IO_RANDOMACCESSFILE_CLOSE:
            native_method_io_randomaccessfile_close();
            break;

        case NATIVE_IO_RANDOMACCESSFILE_GETFILEPOINTER:
            native_method_io_randomaccessfile_getfilepointer();
            break;

        case NATIVE_IO_RANDOMACCESSFILE_LENGTH:
            native_method_io_randomaccessfile_length();
            break;

        case NATIVE_IO_RANDOMACCESSFILE_READ:
            native_method_io_randomaccessfile_read();
            break;

        case NATIVE_IO_RANDOMACCESSFILE_READ_ARRAY_BYTE:
            native_method_io_randomaccessfile_read_array_byte();
            break;

        case NATIVE_IO_RANDOMACCESSFILE_READ_ARRAY_BYTE_INT_INT:
            native_method_io_randomaccessfile_read_array_byte_int_int();
            break;

        case NATIVE_IO_RANDOMACCESSFILE_READBOOLEAN:
            native_method_io_randomaccessfile_readboolean();
            break;

        case NATIVE_IO_RANDOMACCESSFILE_READBYTE:
            native_method_io_randomaccessfile_readbyte();
            break;

        case NATIVE_IO_RANDOMACCESSFILE_READCHAR:
            native_method_io_randomaccessfile_readchar();
            break;

        case NATIVE_IO_RANDOMACCESSFILE_READDOUBLE:
            native_method_io_randomaccessfile_readdouble();
            break;

        case NATIVE_IO_RANDOMACCESSFILE_READFLOAT:
            native_method_io_randomaccessfile_readfloat();
            break;

        case NATIVE_IO_RANDOMACCESSFILE_READFULLY_ARRAY_BYTE:
            native_method_io_randomaccessfile_readfully_array_byte();
            break;

        case NATIVE_IO_RANDOMACCESSFILE_READFULLY_ARRAY_BYTE_INT_INT:
            native_method_io_randomaccessfile_readfully_array_byte_int_int();
            break;

        case NATIVE_IO_RANDOMACCESSFILE_READINT:
            native_method_io_randomaccessfile_readint();
            break;

        case NATIVE_IO_RANDOMACCESSFILE_READLONG:
            native_method_io_randomaccessfile_readlong();
            break;

        case NATIVE_IO_RANDOMACCESSFILE_READSHORT:
            native_method_io_randomaccessfile_readshort();
            break;

        case NATIVE_IO_RANDOMACCESSFILE_READUNSIGNEDBYTE:
            native_method_io_randomaccessfile_readunsignedbyte();
            break;

        case NATIVE_IO_RANDOMACCESSFILE_READUNSIGNEDSHORT:
            native_method_io_randomaccessfile_readunsignedshort();
            break;

        case NATIVE_IO_RANDOMACCESSFILE_SEEK_LONG:
            native_method_io_randomaccessfile_seek_long();
            break;

        case NATIVE_IO_RANDOMACCESSFILE_SETLENGTH_LONG:
            native_method_io_randomaccessfile_setlength_long();
            break;

        case NATIVE_IO_RANDOMACCESSFILE_SKIPBYTES_INT:
            native_method_io_randomaccessfile_skipbytes_int();
            break;

        case NATIVE_IO_RANDOMACCESSFILE_WRITE_ARRAY_BYTE:
            native_method_io_randomaccessfile_write_array_byte();
            break;

        case NATIVE_IO_RANDOMACCESSFILE_WRITE_ARRAY_BYTE_INT_INT:
            native_method_io_randomaccessfile_write_array_byte_int_int();
            break;

        case NATIVE_IO_RANDOMACCESSFILE_WRITE_INT:
            native_method_io_randomaccessfile_write_int();
            break;

        case NATIVE_IO_RANDOMACCESSFILE_WRITEBOOLEAN_BOOLEAN:
            native_method_io_randomaccessfile_writeboolean_boolean();
            break;

        case NATIVE_IO_RANDOMACCESSFILE_WRITEBYTE_INT:
            native_method_io_randomaccessfile_writebyte_int();
            break;

        case NATIVE_IO_RANDOMACCESSFILE_WRITEBYTES_STRING:
            native_method_io_randomaccessfile_writebytes_string();
            break;

        case NATIVE_IO_RANDOMACCESSFILE_WRITECHAR_INT:
            native_method_io_randomaccessfile_writechar_int();
            break;

        case NATIVE_IO_RANDOMACCESSFILE_WRITECHARS_STRING:
            native_method_io_randomaccessfile_writechars_string();
            break;

        case NATIVE_IO_RANDOMACCESSFILE_WRITEDOUBLE_DOUBLE:
            native_method_io_randomaccessfile_writedouble_double();
            break;

        case NATIVE_IO_RANDOMACCESSFILE_WRITEFLOAT_FLOAT:
            native_method_io_randomaccessfile_writefloat_float();
            break;

        case NATIVE_IO_RANDOMACCESSFILE_WRITEINT_INT:
            native_method_io_randomaccessfile_writeint_int();
            break;

        case NATIVE_IO_RANDOMACCESSFILE_WRITELONG_LONG:
            native_method_io_randomaccessfile_writelong_long();
            break;

        case NATIVE_IO_RANDOMACCESSFILE_WRITESHORT_INT:
            native_method_io_randomaccessfile_writeshort_int();
            break;

        case NATIVE_IO_RANDOMACCESSFILE_WRITEUTF_STRING:
            native_method_io_randomaccessfile_writeutf_string();
            break;

        default:
            exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
            break;

    }
}


