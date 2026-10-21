#include "io_printstream.h"
#include "heap.h"
#include "application.h"
#include "threads.h"
#include "exceptions.h"
#include "native.h"
#include "objects.h"
#include "stack.h"
#include "value_type.h"
#include "strings.h"
#include "file_module.h"

///////////////////////////////////////////////////////////////////////////

// use New method implementation to hold a method
// use New implementation to mark start block
// use End new implementation to mark end block to keep

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////

object_t native_io_printstream_new( void )
{
    return( object_create( GET_CLASS_REF( NATIVE_CLASS_IO_PRINTSTREAM ), T_CLASS, NATIVE_IO_PRINTSTREAM_TOTAL_FIELDS ) );
}

///////////////////////////////////////////////////////////////////////////

void native_method_io_printstream_init_file( void )
{
    // PrintStream(File file)
    // Creates a new print stream, without automatic line flushing, 
    // with the specified file. 
    // Implementation code: B936D4F7
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

void native_method_io_printstream_init_file_string( void )
{
    // PrintStream(File file, String csn)
    // Creates a new print stream, without automatic line flushing, 
    // with the specified file and charset. 
    // Implementation code: 124BF7A6
    object_t file_file;
    object_t string_csn;
    object_t object;

    string_csn = stack_pop();
    file_file = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_io_printstream_init_outputstream( void )
{
    // PrintStream(OutputStream out)
    // Creates a new print stream. 
    // Implementation code: 28130B56
    object_t outputstream_out;
    object_t object;

    outputstream_out = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_io_printstream_init_outputstream_boolean( void )
{
    // PrintStream(OutputStream out, boolean autoFlush)
    // Creates a new print stream. 
    // Implementation code: 28130B56
    object_t outputstream_out;
    object_t object;

    outputstream_out = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_io_printstream_init_outputstream_boolean_string( void )
{
    // PrintStream(OutputStream out, boolean autoFlush, String encoding)
    // Creates a new print stream. 
    // Implementation code: 28130B56
    object_t outputstream_out;
    object_t object;

    outputstream_out = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_io_printstream_init_string( void )
{
    // PrintStream(String fileName)
    // Creates a new print stream, without automatic line flushing, 
    // with the specified file name. 
    // Implementation code: 4E0517D3
    object_t string_filename;
    object_t object;
    char * path;    
	file_stream_t * fp_file;
    
    string_filename = stack_peek(0);
    object = stack_peek(1);

    // put your code here
    path = strings_get_text_ptr( string_filename );
    
	object_create_extension( object, sizeof( file_stream_t ) );
	fp_file = ( file_stream_t * )object_get_extension( object );
    
	if( vm_file_open( fp_file, path, vm_open_read ) != VM_FILE_OK )
    {
        exception_new( NATIVE_CLASS_THROW_IO_FILENOTFOUNDEXCEPTION, "File not found or unable to process" );
    }
    
    stack_remove(2);
}

void native_method_io_printstream_init_string_string( void )
{
    // PrintStream(String fileName, String csn)
    // Creates a new print stream, without automatic line flushing, 
    // with the specified file name and charset. 
    // Implementation code: 9A2E8D73
    object_t string_filename;
    object_t string_csn;
    object_t object;

    string_csn = stack_pop();
    string_filename = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

///////////////////////////////////////////////////////////////////////////

void native_method_io_printstream_append_char( void )
{
    // PrintStream append(char c)
    // Appends the specified character to this output stream. 
    // Implementation code: 11099661
    object_t char_c;
    object_t object;
    file_stream_t * fp_file;
	char tmp[4];

    char_c = stack_peek(0);
    object = stack_peek(1);

    // put your code here
    fp_file = ( file_stream_t * )object_get_extension( object );
	tmp[0] = value_get_decimal(char_c);
	tmp[1] = 0;
    
    if( fp_file->fp == NULL )
    {
    	DEBUG_CONSOLE( "%s", tmp);
    }
    else
    {
        vm_file_puts( tmp, fp_file );
    }
    
    // keep the object instance in stack
    stack_remove(1);
}

void native_method_io_printstream_append_charsequence( void )
{
    // PrintStream append(CharSequence csq)
    // Appends the specified character sequence to this output 
    // stream. 
    // Implementation code: 1E1185B7
    object_t charsequence_csq;
    object_t object;
    file_stream_t * fp_file;

    charsequence_csq = stack_peek(0);
    object = stack_peek(1);

    // put your code here
	fp_file = ( file_stream_t * )object_get_extension( object );
    
    if( fp_file->fp == NULL )
    {
    	DEBUG_CONSOLE( "%s", strings_get_text_ptr(charsequence_csq) );
    }
    else
    {
        vm_file_puts( strings_get_text_ptr(charsequence_csq), fp_file );
    }    
    
    // keep the object instance in stack
    stack_remove(1);    
}

void native_method_io_printstream_append_charsequence_int_int( void )
{
    // PrintStream append(CharSequence csq, int start, int end)
    // Appends a subsequence of the specified character sequence 
    // to this output stream. 
    // Implementation code: D54109FE
    object_t charsequence_csq;
    object_t int_start;
    object_t int_end;
    object_t object;

    int_end = stack_pop();
    int_start = stack_pop();
    charsequence_csq = stack_pop();
    object = stack_peek(0);

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_io_printstream_checkerror( void )
{
    // boolean checkError()
    // Flushes the stream and checks its error state. 
    // Implementation code: 37F2D2D2
    object_t object;
    object_t ret_object;
    bool_t ret_value = 0;

    object = stack_peek(0);

    // return type: boolean
    ret_object = value_create_boolean( ret_value );
    stack_remove(1);
    stack_push( ret_object );
}

void native_method_io_printstream_clearerror( void )
{
    // protected  void clearError()
    // Clears the internal error state of this stream. 
    // Implementation code: 6A8ACF2E
    object_t object;

    object = stack_pop();
}

void native_method_io_printstream_close( void )
{
    // void close()
    // Closes the stream. 
    // Implementation code: 21F130EF
    object_t object;
    file_stream_t * fp_file;

    object = stack_peek(0);
    
    fp_file = ( file_stream_t * )object_get_extension( object );
    
    if( fp_file->fp != NULL )
        vm_file_close( fp_file );
    
    stack_remove(1);
}

void native_method_io_printstream_flush( void )
{
    // void flush()
    // Flushes the stream. 
    // Implementation code: DE13F97C
    object_t object;
    file_stream_t * fp_file;
    
    object = stack_peek(0);
    
    fp_file = ( file_stream_t * )object_get_extension( object );
    
    if( fp_file->fp != NULL )
        vm_file_flush( fp_file );
    
    stack_remove(1);    
}

void native_method_io_printstream_print_boolean( void )
{
    // void print(boolean b)
    // Prints a boolean value. 
    // Implementation code: C923523C
    object_t boolean_b;
    object_t object;
    file_stream_t * fp_file;

    boolean_b = stack_peek(0);
    object = stack_peek(1);

    // put your code here
	fp_file = ( file_stream_t * )object_get_extension( object );
    
	if( fp_file->fp == NULL )
    {
    	DEBUG_CONSOLE( "%s", native_value_to_string( boolean_b ) );
    }
    else
    {
        vm_file_puts( native_value_to_string( boolean_b ), fp_file );
    }
    
    stack_remove(2);
}

void native_method_io_printstream_print_char( void )
{
    // void print(char c)
    // Prints a character. 
    // Implementation code: C12FBF76
    object_t char_c;
    object_t object;
    file_stream_t * fp_file;

    char_c = stack_peek(0);
    object = stack_peek(1);

    // put your code here
	fp_file = ( file_stream_t * )object_get_extension( object );
    
	if( fp_file->fp == NULL )
    {
    	DEBUG_CONSOLE( "%s", native_value_to_string( char_c ) );
    }
    else
    {
        vm_file_puts( native_value_to_string( char_c ), fp_file );
    }
    
    stack_remove(2);
}

void native_method_io_printstream_print_array_char( void )
{
    // void print(char[] s)
    // Prints an array of characters. 
    // Implementation code: 62E341CC
    object_t char_array_s;
    object_t object;
    file_stream_t * fp_file;

    char_array_s = stack_peek(0);
    object = stack_peek(1);

    // put your code here
	fp_file = ( file_stream_t * )object_get_extension( object );
    
	if( fp_file->fp == NULL )
    {
    	DEBUG_CONSOLE( "%s", strings_get_text_ptr(char_array_s) );
    }
    else
    {
        vm_file_puts( strings_get_text_ptr(char_array_s), fp_file );
    }
    
    stack_remove(2);
}

void native_method_io_printstream_print_double( void )
{
    // void print(double d)
    // Prints a double-precision floating-point number. 
    // Implementation code: 5749A506
    object_t double_d;
    object_t object;
    file_stream_t * fp_file;

    double_d = stack_peek(0);
    object = stack_peek(1);

    // put your code here
	fp_file = ( file_stream_t * )object_get_extension( object );
    
	if( fp_file->fp == NULL )
    {
    	DEBUG_CONSOLE( "%s", native_value_to_string( double_d ) );
    }
    else
    {
        vm_file_puts( native_value_to_string( double_d ), fp_file );
    }
    
    stack_remove(2);
}

void native_method_io_printstream_print_float( void )
{
    // void print(float f)
    // Prints a floating-point number. 
    // Implementation code: DE9004A9
    object_t float_f;
    object_t object;
    file_stream_t * fp_file;

    float_f = stack_peek(0);
    object = stack_peek(1);

    // put your code here
	fp_file = ( file_stream_t * )object_get_extension( object );
    
	if( fp_file->fp == NULL )
    {
    	DEBUG_CONSOLE( "%s", native_value_to_string( float_f ) );
    }
    else
    {
        vm_file_puts( native_value_to_string( float_f ), fp_file );
    }
    
    stack_remove(2);
}

void native_method_io_printstream_print_int( void )
{
    // void print(int i)
    // Prints an integer. 
    // Implementation code: 00A1934A
    object_t int_i;
    object_t object;
    file_stream_t * fp_file;

    int_i = stack_peek(0);
    object = stack_peek(1);

    // put your code here
	fp_file = ( file_stream_t * )object_get_extension( object );
    
	if( fp_file->fp == NULL )
    {
    	DEBUG_CONSOLE( "%s", native_value_to_string( int_i ) );
    }
    else
    {
        vm_file_puts( native_value_to_string( int_i ), fp_file );
    }
    
    stack_remove(2);
}

void native_method_io_printstream_print_long( void )
{
    // void print(long l)
    // Prints a long integer. 
    // Implementation code: 8A6BAD5B
    object_t long_l;
    object_t object;
    file_stream_t * fp_file;

    long_l = stack_peek(0);
    object = stack_peek(1);

    // put your code here
	fp_file = ( file_stream_t * )object_get_extension( object );
    
	if( fp_file->fp == NULL )
    {
    	DEBUG_CONSOLE( "%s", native_value_to_string( long_l ) );
    }
    else
    {
        vm_file_puts( native_value_to_string( long_l ), fp_file );
    }
    
    stack_remove(2);
}

void native_method_io_printstream_print_object( void )
{
    // void print(Object obj)
    // Prints an object. 
    // Implementation code: B002165A
    object_t object_obj;
    object_t object;

    object_obj = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_io_printstream_print_string( void )
{
    // void print(String s)
    // Prints a string. 
    // Implementation code: 3D4ED983
    object_t string_s;
    object_t object;
    file_stream_t * fp_file;

    string_s = stack_peek(0);
    object = stack_peek(1);

    // put your code here
	fp_file = ( file_stream_t * )object_get_extension( object );
    
	if( fp_file->fp == NULL )
    {
    	DEBUG_CONSOLE( "%s", strings_get_text_ptr(string_s) );
    }
    else
    {
        vm_file_puts( strings_get_text_ptr(string_s), fp_file );
    }
    
    stack_remove(2);
}



void native_method_io_printstream_println( void )
{
    // void println()
    // Terminates the current line by writing the line separator 
    // string. 
    // Implementation code: 8DA25E99
    object_t object;
    file_stream_t * fp_file;

    object = stack_peek(0);

    // put your code here
	fp_file = ( file_stream_t * )object_get_extension( object );
    
	if( fp_file->fp == NULL )
    {
    	DEBUG_CONSOLE( "\n" );
    }
    else
    {
        vm_file_puts( "\n", fp_file );
    }
    
    stack_remove(1);
}

void native_method_io_printstream_println_boolean( void )
{
    // void println(boolean x)
    // Prints a boolean and then terminate the line. 
    // Implementation code: A31D0FFC
    object_t boolean_x;
    object_t object;
    file_stream_t * fp_file;

    boolean_x = stack_peek(0);
    object = stack_peek(1);

    // put your code here
	fp_file = ( file_stream_t * )object_get_extension( object );
    
	if( fp_file->fp == NULL )
    {
    	DEBUG_CONSOLE( "%s\n", native_value_to_string( boolean_x ) );
    }
    else
    {
        vm_file_puts( native_value_to_string( boolean_x ), fp_file );
        vm_file_puts( "\n", fp_file );
    }
    
    stack_remove(2);
}

void native_method_io_printstream_println_char( void )
{
    // void println(char x)
    // Prints a character and then terminate the line. 
    // Implementation code: 869B7280
    object_t char_x;
    object_t object;
    file_stream_t * fp_file;

    char_x = stack_peek(0);
    object = stack_peek(1);

    // put your code here
	fp_file = ( file_stream_t * )object_get_extension( object );
    
	if( fp_file->fp == NULL )
    {
    	DEBUG_CONSOLE( "%s\n", native_value_to_string( char_x ) );
    }
    else
    {
        vm_file_puts( native_value_to_string( char_x ), fp_file );
        vm_file_puts( "\n", fp_file );
    }
    
    stack_remove(2);
}

void native_method_io_printstream_println_array_char( void )
{
    // void println(char[] x)
    // Prints an array of characters and then terminate the line. 
    // Implementation code: B4DDAE37
    object_t char_array_x;
    object_t object;
    file_stream_t * fp_file;

    char_array_x = stack_peek(0);
    object = stack_peek(1);

    // put your code here
	fp_file = ( file_stream_t * )object_get_extension( object );
    
	if( fp_file->fp == NULL )
    {
    	DEBUG_CONSOLE( "%s\n", strings_get_text_ptr( char_array_x ) );
    }
    else
    {
        vm_file_puts( strings_get_text_ptr( char_array_x ), fp_file );
        vm_file_puts( "\n", fp_file );
    }
    
    stack_remove(2);
}

void native_method_io_printstream_println_double( void )
{
    // void println(double x)
    // Prints a double and then terminate the line. 
    // Implementation code: F3E902BE
    object_t double_x;
    object_t object;
    file_stream_t * fp_file;

    double_x = stack_peek(0);
    object = stack_peek(1);

    // put your code here
	fp_file = ( file_stream_t * )object_get_extension( object );
    
	if( fp_file->fp == NULL )
    {
    	DEBUG_CONSOLE( "%s\n", native_value_to_string( double_x ) );
    }
    else
    {
        vm_file_puts( native_value_to_string( double_x ), fp_file );
        vm_file_puts( "\n", fp_file );
    }
    
    stack_remove(2);
}

void native_method_io_printstream_println_float( void )
{
    // void println(float x)
    // Prints a float and then terminate the line. 
    // Implementation code: B2D638DB
    object_t float_x;
    object_t object;
    file_stream_t * fp_file;

    float_x = stack_peek(0);
    object = stack_peek(1);

    // put your code here
	fp_file = ( file_stream_t * )object_get_extension( object );
    
	if( fp_file->fp == NULL )
    {
    	DEBUG_CONSOLE( "%s\n", native_value_to_string( float_x ) );
    }
    else
    {
        vm_file_puts( native_value_to_string( float_x ), fp_file );
        vm_file_puts( "\n", fp_file );
    }
    
    stack_remove(2);
}

void native_method_io_printstream_println_int( void )
{
    // void println(int x)
    // Prints an integer and then terminate the line. 
    // Implementation code: 323E4731
    object_t int_x;
    object_t object;
    file_stream_t * fp_file;

    int_x = stack_peek(0);
    object = stack_peek(1);

    // put your code here
	fp_file = ( file_stream_t * )object_get_extension( object );
    
	if( fp_file->fp == NULL )
    {
    	DEBUG_CONSOLE( "%s\n", native_value_to_string( int_x ) );
    }
    else
    {
        vm_file_puts( native_value_to_string( int_x ), fp_file );
        vm_file_puts( "\n", fp_file );
    }
    
    stack_remove(2);
}

void native_method_io_printstream_println_long( void )
{
    // void println(long x)
    // Prints a long and then terminate the line. 
    // Implementation code: 467E141A
    object_t long_x;
    object_t object;
    file_stream_t * fp_file;

    long_x = stack_peek(0);
    object = stack_peek(1);

    // put your code here
	fp_file = ( file_stream_t * )object_get_extension( object );
    
	if( fp_file->fp == NULL )
    {
    	DEBUG_CONSOLE( "%s\n", native_value_to_string( long_x ) );
    }
    else
    {
        vm_file_puts( native_value_to_string( long_x ), fp_file );
        vm_file_puts( "\n", fp_file );
    }
    
    stack_remove(2);
}

void native_method_io_printstream_println_object( void )
{
    // void println(Object x)
    // Prints an Object and then terminate the line. 
    // Implementation code: 4EC56B21
    object_t object_x;
    object_t object;

    object_x = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_io_printstream_println_string( void )
{
    // void println(String x)
    // Prints a String and then terminate the line. 
    // Implementation code: 2210190C
    object_t string_x;
    object_t object;
    file_stream_t * fp_file;

    string_x = stack_peek(0);
    object = stack_peek(1);

    // put your code here
	fp_file = ( file_stream_t * )object_get_extension( object );
    
	if( fp_file->fp == NULL )
    {
    	DEBUG_CONSOLE( "%s\n", strings_get_text_ptr( string_x ) );
    }
    else
    {
        vm_file_puts( strings_get_text_ptr( string_x ), fp_file );
        vm_file_puts( "\n", fp_file );
    }
    
    stack_remove(2);
}

void native_method_io_printstream_seterror( void )
{
    // protected  void setError()
    // Sets the error state of the stream to true. 
    // Implementation code: 33084334
    object_t object;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_io_printstream_write_array_byte( void )
{
    // void write(byte[] b)
    // Writes b.length bytes from the specified byte array to this 
    // file output stream. 
    // Implementation code: 07D85444
    object_t byte_array_b;
    object_t object;

    byte_array_b = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_io_printstream_write_array_byte_int_int( void )
{
    // void write(byte[] buf, int off, int len)
    // Writes len bytes from the specified byte array starting 
    // at offset off to this stream. 
    // Implementation code: 286BC0F4
    object_t byte_array_buf;
    object_t int_off;
    object_t int_len;
    object_t object;

    int_len = stack_pop();
    int_off = stack_pop();
    byte_array_buf = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_io_printstream_write_int( void )
{
    // void write(int b)
    // Writes the specified byte to this stream. 
    // Implementation code: 05FC52A3
    object_t int_b;
    object_t object;

    int_b = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

///////////////////////////////////////////////////////////////////////////

void native_io_printstream_invoke(uint16_t mref)
{
    switch( mref )
    {
        case NATIVE_IO_PRINTSTREAM_INIT_FILE:
            native_method_io_printstream_init_file();
            break;

        case NATIVE_IO_PRINTSTREAM_INIT_FILE_STRING:
            native_method_io_printstream_init_file_string();
            break;

        case NATIVE_IO_PRINTSTREAM_INIT_OUTPUTSTREAM:
            native_method_io_printstream_init_outputstream();
            break;

        case NATIVE_IO_PRINTSTREAM_INIT_OUTPUTSTREAM_BOOLEAN:
            native_method_io_printstream_init_outputstream_boolean();
            break;

        case NATIVE_IO_PRINTSTREAM_INIT_OUTPUTSTREAM_BOOLEAN_STRING:
            native_method_io_printstream_init_outputstream_boolean_string();
            break;

        case NATIVE_IO_PRINTSTREAM_INIT_STRING:
            native_method_io_printstream_init_string();
            break;

        case NATIVE_IO_PRINTSTREAM_INIT_STRING_STRING:
            native_method_io_printstream_init_string_string();
            break;

        case NATIVE_IO_PRINTSTREAM_APPEND_CHAR:
            native_method_io_printstream_append_char();
            break;

        case NATIVE_IO_PRINTSTREAM_APPEND_CHARSEQUENCE:
            native_method_io_printstream_append_charsequence();
            break;

        case NATIVE_IO_PRINTSTREAM_APPEND_CHARSEQUENCE_INT_INT:
            native_method_io_printstream_append_charsequence_int_int();
            break;

        case NATIVE_IO_PRINTSTREAM_CHECKERROR:
            native_method_io_printstream_checkerror();
            break;

        case NATIVE_IO_PRINTSTREAM_CLEARERROR:
            native_method_io_printstream_clearerror();
            break;

        case NATIVE_IO_PRINTSTREAM_CLOSE:
            native_method_io_printstream_close();
            break;

        case NATIVE_IO_PRINTSTREAM_FLUSH:
            native_method_io_printstream_flush();
            break;

        case NATIVE_IO_PRINTSTREAM_PRINT_BOOLEAN:
            native_method_io_printstream_print_boolean();
            break;

        case NATIVE_IO_PRINTSTREAM_PRINT_CHAR:
            native_method_io_printstream_print_char();
            break;

        case NATIVE_IO_PRINTSTREAM_PRINT_ARRAY_CHAR:
            native_method_io_printstream_print_array_char();
            break;

        case NATIVE_IO_PRINTSTREAM_PRINT_DOUBLE:
            native_method_io_printstream_print_double();
            break;

        case NATIVE_IO_PRINTSTREAM_PRINT_FLOAT:
            native_method_io_printstream_print_float();
            break;

        case NATIVE_IO_PRINTSTREAM_PRINT_INT:
            native_method_io_printstream_print_int();
            break;

        case NATIVE_IO_PRINTSTREAM_PRINT_LONG:
            native_method_io_printstream_print_long();
            break;

        case NATIVE_IO_PRINTSTREAM_PRINT_OBJECT:
            native_method_io_printstream_print_object();
            break;

        case NATIVE_IO_PRINTSTREAM_PRINT_STRING:
            native_method_io_printstream_print_string();
            break;

        case NATIVE_IO_PRINTSTREAM_PRINTLN:
            native_method_io_printstream_println();
            break;

        case NATIVE_IO_PRINTSTREAM_PRINTLN_BOOLEAN:
            native_method_io_printstream_println_boolean();
            break;

        case NATIVE_IO_PRINTSTREAM_PRINTLN_CHAR:
            native_method_io_printstream_println_char();
            break;

        case NATIVE_IO_PRINTSTREAM_PRINTLN_ARRAY_CHAR:
            native_method_io_printstream_println_array_char();
            break;

        case NATIVE_IO_PRINTSTREAM_PRINTLN_DOUBLE:
            native_method_io_printstream_println_double();
            break;

        case NATIVE_IO_PRINTSTREAM_PRINTLN_FLOAT:
            native_method_io_printstream_println_float();
            break;

        case NATIVE_IO_PRINTSTREAM_PRINTLN_INT:
            native_method_io_printstream_println_int();
            break;

        case NATIVE_IO_PRINTSTREAM_PRINTLN_LONG:
            native_method_io_printstream_println_long();
            break;

        case NATIVE_IO_PRINTSTREAM_PRINTLN_OBJECT:
            native_method_io_printstream_println_object();
            break;

        case NATIVE_IO_PRINTSTREAM_PRINTLN_STRING:
            native_method_io_printstream_println_string();
            break;

        case NATIVE_IO_PRINTSTREAM_SETERROR:
            native_method_io_printstream_seterror();
            break;

        case NATIVE_IO_PRINTSTREAM_WRITE_ARRAY_BYTE:
            native_method_io_printstream_write_array_byte();
            break;

        case NATIVE_IO_PRINTSTREAM_WRITE_ARRAY_BYTE_INT_INT:
            native_method_io_printstream_write_array_byte_int_int();
            break;

        case NATIVE_IO_PRINTSTREAM_WRITE_INT:
            native_method_io_printstream_write_int();
            break;

        default:
            exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
            break;

    }
}


