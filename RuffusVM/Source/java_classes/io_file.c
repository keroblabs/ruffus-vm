#include "io_file.h"
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
#include "dir.h"

///////////////////////////////////////////////////////////////////////////

// use New method implementation to hold a method
// use New implementation to mark start block
// use End new implementation to mark end block to keep

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////

// static String pathSeparator
#define NATIVE_FIELD_VALUE_IO_FILE_PATHSEPARATOR                                 "/"

// static char pathSeparatorChar
#define NATIVE_FIELD_VALUE_IO_FILE_PATHSEPARATORCHAR                             '/'

// static String separator
#define NATIVE_FIELD_VALUE_IO_FILE_SEPARATOR                                     ";"

// static char separatorChar
#define NATIVE_FIELD_VALUE_IO_FILE_SEPARATORCHAR                                 ';'

///////////////////////////////////////////////////////////////////////////

object_t native_io_file_new( void )
{
    return( object_create( GET_CLASS_REF( NATIVE_CLASS_IO_FILE ), T_CLASS, NATIVE_IO_FILE_TOTAL_FIELDS ) );
}

///////////////////////////////////////////////////////////////////////////

void native_method_io_file_init_file_string( void )
{
    // File(File parent, String child)
    // Creates a new File instance from a parent abstract pathname 
    // and a child pathname string. 
    // Implementation code: 39FC7407
    object_t file_parent;
    object_t string_child;
    object_t object;

    string_child = stack_pop();
    file_parent = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_io_file_init_string( void )
{
    // File(String pathname)
    // Creates a new File instance by converting the given pathname 
    // string into an abstract pathname. 
    // Implementation code: C2432B9D
    object_t string_pathname;
    object_t * fields;
    object_t object;

    string_pathname = stack_peek(0);
    object = stack_peek(1);

    // put your code here
	fields = object_get_fields_ptr( object );
	fields[ NATIVE_FIELD_IO_FILE_PATH ] = strings_create( strings_get_text_ptr(string_pathname) );
    
    stack_remove(2);
}

void native_method_io_file_init_string_string( void )
{
    // File(String parent, String child)
    // Creates a new File instance from a parent pathname string 
    // and a child pathname string. 
    // Implementation code: C9AED879
    object_t string_parent;
    object_t string_child;
    object_t object;

    string_child = stack_pop();
    string_parent = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_io_file_init_uri( void )
{
    // File(URI uri)
    // Creates a new File instance by converting the given file: 
    // URI into an abstract pathname. 
    // Implementation code: FC65DF7F
    object_t uri_uri;
    object_t object;

    uri_uri = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

///////////////////////////////////////////////////////////////////////////

void native_method_io_file_canexecute( void )
{
    // boolean canExecute()
    // Tests whether the application can execute the file denoted 
    // by this abstract pathname. 
    // Implementation code: CEA53365
    object_t object;
    bool_t ret_value = 0;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: boolean
    stack_push( value_create( &ret_value, T_BOOLEAN ) );
}

void native_method_io_file_canread( void )
{
    // boolean canRead()
    // Tests whether the application can read the file denoted 
    // by this abstract pathname. 
    // Implementation code: FE3190F0
    object_t object;
    bool_t ret_value = 0;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: boolean
    stack_push( value_create( &ret_value, T_BOOLEAN ) );
}

void native_method_io_file_canwrite( void )
{
    // boolean canWrite()
    // Tests whether the application can modify the file denoted 
    // by this abstract pathname. 
    // Implementation code: F2C6B62D
    object_t object;
    bool_t ret_value = 0;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: boolean
    stack_push( value_create( &ret_value, T_BOOLEAN ) );
}

void native_method_io_file_compareto_file( void )
{
    // int compareTo(File pathname)
    // Compares two abstract pathnames lexicographically. 
    // Implementation code: F0753FAD
    object_t file_pathname;
    object_t object;
    object_t * fields_obj;
    object_t * fileds_param;
    int32_t ret_value = 0;

    file_pathname = stack_peek(0);
    object = stack_peek(1);

    // put your code here
    fields_obj = object_get_fields_ptr( object );
    fileds_param = object_get_fields_ptr( file_pathname );
    ret_value = strings_compare( fields_obj[ NATIVE_FIELD_IO_FILE_PATH ], strings_get_text_ptr( fileds_param[ NATIVE_FIELD_IO_FILE_PATH ] ) );

    // return type: int
    stack_remove(2);
    stack_push( value_create( &ret_value, T_INT ) );
}

void native_method_io_file_createnewfile( void )
{
    // boolean createNewFile()
    // Atomically creates a new, empty file named by this abstract 
    // pathname if and only if a file with this name does not yet 
    // exist. 
    // Implementation code: 6C530A15
    object_t object;
    object_t * fields_obj;
    char * path;
    file_stream_t create_file;
    
    object = stack_peek(0);

    // put your code here
    fields_obj = object_get_fields_ptr( object );
    path = strings_get_text_ptr( fields_obj[ NATIVE_FIELD_IO_FILE_PATH ] );
    
    if( vm_file_locate_path( path ) != VM_IS_FILE ) 
    {
        exception_new( NATIVE_CLASS_THROW_IO_IOEXCEPTION, "File already exists" );
    }
    else if( vm_file_exists( path ) == TRUE )
    {
        stack_push_boolean( FALSE );
        return;
    }

	if( vm_file_open( &create_file, path, vm_open_write ) != VM_FILE_OK )
    {
        exception_new( NATIVE_CLASS_THROW_IO_IOEXCEPTION, "Failed to create the file" );
    }
    
    vm_file_close( &create_file );

    // return type: boolean
    stack_remove(1);
    stack_push_boolean( TRUE );
}

void native_method_io_file_createtempfile_string_string( void )
{
    // static File createTempFile(String prefix, String suffix)
    // Creates an empty file in the default temporary-file directory, 
    // using the given prefix and suffix to generate its name. 
    // Implementation code: F8BD9783
    object_t string_prefix;
    object_t string_suffix;

    string_suffix = stack_pop();
    string_prefix = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: File
    stack_push( 0 );
}

void native_method_io_file_createtempfile_string_string_file( void )
{
    // static File createTempFile(String prefix, String suffix, File directory)
    // Creates a new empty file in the specified directory, using 
    // the given prefix and suffix strings to generate its name. 
    // Implementation code: 6485A408
    object_t string_prefix;
    object_t string_suffix;
    object_t file_directory;

    file_directory = stack_pop();
    string_suffix = stack_pop();
    string_prefix = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: File
    stack_push( 0 );
}

void native_method_io_file_delete( void )
{
    // boolean delete()
    // Deletes the file or directory denoted by this abstract pathname. 
    // Implementation code: 0DE7B396
    object_t object;
    object_t * fields_obj;
    char * path;
    bool_t ret_value = 0;

    object = stack_peek(0);

    // put your code here
    fields_obj = object_get_fields_ptr( object );
    path = strings_get_text_ptr( fields_obj[ NATIVE_FIELD_IO_FILE_PATH ] );
    
    ret_value = TRUE;
    
    if( vm_file_locate_path( path ) == VM_IS_DIRECTORY )
    {
        if( dir_isEmpty( path ) == FALSE )
        {
            ret_value = FALSE;
        }
    }
    else if( vm_file_exists( path ) == FALSE )
    {
        ret_value = FALSE;
    }
    
    if( ret_value == TRUE )
    {
        vm_file_delete( path );
    }

    // return type: boolean
    stack_remove(1);
    stack_push_boolean( ret_value );
}

void native_method_io_file_deleteonexit( void )
{
    // void deleteOnExit()
    // Requests that the file or directory denoted by this abstract 
    // pathname be deleted when the virtual machine terminates. 
    // Implementation code: 0D790A4B
    object_t object;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_io_file_equals_object( void )
{
    // boolean equals(Object obj)
    // Tests this abstract pathname for equality with the given 
    // object. 
    // Implementation code: CA32B4F3
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

void native_method_io_file_exists( void )
{
    // boolean exists()
    // Tests whether the file or directory denoted by this abstract 
    // pathname exists. 
    // Implementation code: 57DF13A2
    object_t object;
    object_t * fields_obj;
    char * path;
    bool_t ret_value = FALSE;

    object = stack_peek(0);

    // put your code here
    fields_obj = object_get_fields_ptr( object );
    path = strings_get_text_ptr( fields_obj[ NATIVE_FIELD_IO_FILE_PATH ] );
    
    if( vm_file_locate_path( path ) == VM_IS_DIRECTORY )
    {
        ret_value = TRUE;
    }
    else if( vm_file_exists( path ) == TRUE )
    {
        ret_value = TRUE;
    }
        
    // return type: boolean
    stack_remove(1);
    stack_push( value_create( &ret_value, T_BOOLEAN ) );
}

void native_method_io_file_getabsolutefile( void )
{
    // File getAbsoluteFile()
    // Returns the absolute form of this abstract pathname. 
    // Implementation code: 079C59C5
    object_t object;
    object_t new_object;
    object_t * fields_obj;
    object_t * fields_new;
    char * path;
    
    object = stack_peek(0);

    // put your code here
    fields_obj = object_get_fields_ptr( object );
    path = strings_get_text_ptr( fields_obj[ NATIVE_FIELD_IO_FILE_PATH ] );
    
    new_object = native_io_file_new();
    fields_new = object_get_fields_ptr( new_object );
    fields_new[ NATIVE_FIELD_IO_FILE_PATH ] = strings_create( path );

    // return type: File
    stack_remove(1);
    stack_push( new_object );
}

void native_method_io_file_getabsolutepath( void )
{
    // String getAbsolutePath()
    // Returns the absolute pathname string of this abstract pathname. 
    // Implementation code: C57999B0
    object_t object;
    object_t * fields_obj;
    char * path;
    
    object = stack_peek(0);

    // put your code here
    fields_obj = object_get_fields_ptr( object );
    path = strings_get_text_ptr( fields_obj[ NATIVE_FIELD_IO_FILE_PATH ] );

    // return type: String
    stack_remove(1);
    stack_push( strings_create( path ) );
}

void native_method_io_file_getcanonicalfile( void )
{
    // File getCanonicalFile()
    // Returns the canonical form of this abstract pathname. 
    // Implementation code: 90FD25E3
    object_t object;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: File
    stack_push( 0 );
}

void native_method_io_file_getcanonicalpath( void )
{
    // String getCanonicalPath()
    // Returns the canonical pathname string of this abstract pathname. 
    // Implementation code: 56D1916C
    object_t object;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: String
    stack_push( strings_create( "" ) );
}

void native_method_io_file_getfreespace( void )
{
    // long getFreeSpace()
    // Returns the number of unallocated bytes in the partition 
    // named by this abstract path name. 
    // Implementation code: 3460A120
    object_t object;
    int64_t ret_value = 0L;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: long
    stack_push( value_create( &ret_value, T_LONG ) );
}

void native_method_io_file_getname( void )
{
    // String getName()
    // Returns the name of the file or directory denoted by this 
    // abstract pathname. 
    // Implementation code: CFF1BA4F
    object_t object;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: String
    stack_push( strings_create( "" ) );
}

void native_method_io_file_getparent( void )
{
    // String getParent()
    // Returns the pathname string of this abstract pathname's 
    // parent, or null if this pathname does not name a parent 
    // directory. 
    // Implementation code: B94EE8A6
    object_t object;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: String
    stack_push( strings_create( "" ) );
}

void native_method_io_file_getparentfile( void )
{
    // File getParentFile()
    // Returns the abstract pathname of this abstract pathname's 
    // parent, or null if this pathname does not name a parent 
    // directory. 
    // Implementation code: 7241D290
    object_t object;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: File
    stack_push( 0 );
}

void native_method_io_file_getpath( void )
{
    // String getPath()
    // Converts this abstract pathname into a pathname string. 
    // Implementation code: 98D0A76E
    object_t object;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: String
    stack_push( strings_create( "" ) );
}

void native_method_io_file_gettotalspace( void )
{
    // long getTotalSpace()
    // Returns the size of the partition named by this abstract 
    // pathname. 
    // Implementation code: 40908FE5
    object_t object;
    int64_t ret_value = 0L;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: long
    stack_push( value_create( &ret_value, T_LONG ) );
}

void native_method_io_file_getusablespace( void )
{
    // long getUsableSpace()
    // Returns the number of bytes available to this virtual machine 
    // on the partition named by this abstract pathname. 
    // Implementation code: D54845DB
    object_t object;
    int64_t ret_value = 0L;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: long
    stack_push( value_create( &ret_value, T_LONG ) );
}

void native_method_io_file_hashcode( void )
{
    // int hashCode()
    // Computes a hash code for this abstract pathname. 
    // Implementation code: D78CC659
    object_t object;
    int32_t ret_value = 0;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push( value_create( &ret_value, T_INT ) );
}

void native_method_io_file_isabsolute( void )
{
    // boolean isAbsolute()
    // Tests whether this abstract pathname is absolute. 
    // Implementation code: 9D50E8BD
    object_t object;
    bool_t ret_value = 0;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: boolean
    stack_push( value_create( &ret_value, T_BOOLEAN ) );
}

void native_method_io_file_isdirectory( void )
{
    // boolean isDirectory()
    // Tests whether the file denoted by this abstract pathname 
    // is a directory. 
    // Implementation code: 092BCD34
    object_t object;
    object_t * fields_obj;
    char * path;
    bool_t ret_value = 0;

    object = stack_peek(0);

    // put your code here
    fields_obj = object_get_fields_ptr( object );
    path = strings_get_text_ptr( fields_obj[ NATIVE_FIELD_IO_FILE_PATH ] );
    
    if( vm_file_locate_path( path ) == VM_IS_DIRECTORY ) ret_value = TRUE;

    // return type: boolean
    stack_remove(1);
    stack_push_boolean( ret_value );
}

void native_method_io_file_isfile( void )
{
    // boolean isFile()
    // Tests whether the file denoted by this abstract pathname 
    // is a normal file. 
    // Implementation code: 6F2E828A
    object_t object;
    object_t * fields_obj;
    char * path;
    bool_t ret_value = 0;

    object = stack_peek(0);

    // put your code here
    fields_obj = object_get_fields_ptr( object );
    path = strings_get_text_ptr( fields_obj[ NATIVE_FIELD_IO_FILE_PATH ] );
    
    if( vm_file_locate_path( path ) == VM_IS_FILE ) ret_value = TRUE;

    // return type: boolean
    stack_remove(1);
    stack_push( value_create( &ret_value, T_BOOLEAN ) );
}

void native_method_io_file_ishidden( void )
{
    // boolean isHidden()
    // Tests whether the file named by this abstract pathname is 
    // a hidden file. 
    // Implementation code: 0FEFCAA4
    object_t object;
    bool_t ret_value = 0;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: boolean
    stack_push( value_create( &ret_value, T_BOOLEAN ) );
}

void native_method_io_file_lastmodified( void )
{
    // long lastModified()
    // Returns the time that the file denoted by this abstract 
    // pathname was last modified. 
    // Implementation code: B3833E3C
    object_t object;
    int64_t ret_value = 0L;
    
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_IO_IOEXCEPTION, "Method not implemented" );

    // return type: long
    stack_push( value_create( &ret_value, T_LONG ) );
}

void native_method_io_file_length( void )
{
    // long length()
    // Returns the length of the file denoted by this abstract 
    // pathname. 
    // Implementation code: 8CE58733
    object_t object;
    int64_t ret_value = 0L;
    object_t * fields_obj;
    char * path;
	file_stream_t fp_file;
    
    object = stack_peek(0);

    // put your code here
    fields_obj = object_get_fields_ptr( object );
    path = strings_get_text_ptr( fields_obj[ NATIVE_FIELD_IO_FILE_PATH ] );    
    
    if( vm_file_locate_path( path ) != VM_IS_FILE ) 
    {
        exception_new( NATIVE_CLASS_THROW_IO_IOEXCEPTION, "File does not exist" );
    }
    
	if( vm_file_open( &fp_file, path, vm_open_read ) != VM_FILE_OK )
	{
        exception_new( NATIVE_CLASS_THROW_IO_IOEXCEPTION, "File does not exist" );
	}

	ret_value = vm_file_get_size( &fp_file );
	vm_file_close( &fp_file );

    // return type: long
    stack_remove(1);
    stack_push_long( ret_value );
}

void native_method_io_file_list( void )
{
    // String[] list()
    // Returns an array of strings naming the files and directories 
    // in the directory denoted by this abstract pathname. 
    // Implementation code: 3E4FAE51
    object_t object;
    object_t new_object;
    object_t * fields_obj;
    object_t * fields_array;
    char * path;
    Directory * dir;
    int count;
    int index;
    file_info_t file_info;
    
    object = stack_peek(0);

    // put your code here
    fields_obj = object_get_fields_ptr( object );
    path = strings_get_text_ptr( fields_obj[ NATIVE_FIELD_IO_FILE_PATH ] ); 
    count = dir_getFileCount( path );
    
    if( count == -1 )
    {
        exception_new( NATIVE_CLASS_THROW_IO_IOEXCEPTION, "Directory does not exist" );
    }
    
    new_object = array_create( (uint32_t)count, T_CLASS );
    index = 0;
    
    dir = dir_openFileList( path );
    fields_array = object_get_fields_ptr( new_object );
    
    while( dir_readFileList( dir, &file_info ) != -1 )
    {
        fields_array[ index ] = strings_create( file_info.name );
        index++;
    }

    dir_closeFileList( dir );    
    
    // return type: String[]
    stack_remove(1);
    stack_push( new_object );
}

void native_method_io_file_list_filenamefilter( void )
{
    // String[] list(FilenameFilter filter)
    // Returns an array of strings naming the files and directories 
    // in the directory denoted by this abstract pathname that 
    // satisfy the specified filter. 
    // Implementation code: C52D46D2
    object_t filenamefilter_filter;
    object_t object;

    filenamefilter_filter = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: String[]
    stack_push( 0 );
}

void native_method_io_file_listfiles( void )
{
    // File[] listFiles()
    // Returns an array of abstract pathnames denoting the files 
    // in the directory denoted by this abstract pathname. 
    // Implementation code: 20ED0AD3
    object_t object;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: File[]
    stack_push( 0 );
}

void native_method_io_file_listfiles_filefilter( void )
{
    // File[] listFiles(FileFilter filter)
    // Returns an array of abstract pathnames denoting the files 
    // and directories in the directory denoted by this abstract 
    // pathname that satisfy the specified filter. 
    // Implementation code: F2B15A76
    object_t filefilter_filter;
    object_t object;

    filefilter_filter = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: File[]
    stack_push( 0 );
}

void native_method_io_file_listfiles_filenamefilter( void )
{
    // File[] listFiles(FilenameFilter filter)
    // Returns an array of abstract pathnames denoting the files 
    // and directories in the directory denoted by this abstract 
    // pathname that satisfy the specified filter. 
    // Implementation code: F2B15A76
    object_t filefilter_filter;
    object_t object;

    filefilter_filter = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: File[]
    stack_push( 0 );
}

void native_method_io_file_listroots( void )
{
    // static File[] listRoots()
    // List the available filesystem roots. 
    // Implementation code: 8F9ACED3

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: File[]
    stack_push( 0 );
}

void native_method_io_file_mkdir( void )
{
    // boolean mkdir()
    // Creates the directory named by this abstract pathname. 
    // Implementation code: 43E9928E
    object_t object;
    bool_t ret_value = 0;
    object_t * fields_obj;
    char * path;
    
    object = stack_peek(0);

    // put your code here
    fields_obj = object_get_fields_ptr( object );
    path = strings_get_text_ptr( fields_obj[ NATIVE_FIELD_IO_FILE_PATH ] );   
    
    if( dir_createDirectory( path ) == VM_FILE_OK ) ret_value = TRUE;

    // return type: boolean
    stack_remove(1);
    stack_push_boolean( ret_value );
}

void native_method_io_file_mkdirs( void )
{
    // boolean mkdirs()
    // Creates the directory named by this abstract pathname, including 
    // any necessary but nonexistent parent directories. 
    // Implementation code: BB77FDE3
    object_t object;
    bool_t ret_value = 0;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: boolean
    stack_push( value_create( &ret_value, T_BOOLEAN ) );
}

void native_method_io_file_renameto_file( void )
{
    // boolean renameTo(File dest)
    // Renames the file denoted by this abstract pathname. 
    // Implementation code: DFB0065A
    object_t file_dest;
    object_t object;
    bool_t ret_value = 0;

    file_dest = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: boolean
    stack_push( value_create( &ret_value, T_BOOLEAN ) );
}

void native_method_io_file_setexecutable_boolean( void )
{
    // boolean setExecutable(boolean executable)
    // A convenience method to set the owner's execute permission 
    // for this abstract pathname. 
    // Implementation code: 3B1BAC16
    object_t boolean_executable;
    object_t object;
    bool_t ret_value = 0;

    boolean_executable = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: boolean
    stack_push( value_create( &ret_value, T_BOOLEAN ) );
}

void native_method_io_file_setexecutable_boolean_boolean( void )
{
    // boolean setExecutable(boolean executable, boolean ownerOnly)
    // Sets the owner's or everybody's execute permission for this 
    // abstract pathname. 
    // Implementation code: 2634329F
    object_t boolean_executable;
    object_t boolean_owneronly;
    object_t object;
    bool_t ret_value = 0;

    boolean_owneronly = stack_pop();
    boolean_executable = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: boolean
    stack_push( value_create( &ret_value, T_BOOLEAN ) );
}

void native_method_io_file_setlastmodified_long( void )
{
    // boolean setLastModified(long time)
    // Sets the last-modified time of the file or directory named 
    // by this abstract pathname. 
    // Implementation code: 4E8C9E28
    object_t long_time;
    object_t object;
    bool_t ret_value = 0;

    long_time = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: boolean
    stack_push( value_create( &ret_value, T_BOOLEAN ) );
}

void native_method_io_file_setreadable_boolean( void )
{
    // boolean setReadable(boolean readable)
    // A convenience method to set the owner's read permission 
    // for this abstract pathname. 
    // Implementation code: 899A097F
    object_t boolean_readable;
    object_t object;
    bool_t ret_value = 0;

    boolean_readable = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: boolean
    stack_push( value_create( &ret_value, T_BOOLEAN ) );
}

void native_method_io_file_setreadable_boolean_boolean( void )
{
    // boolean setReadable(boolean readable, boolean ownerOnly)
    // Sets the owner's or everybody's read permission for this 
    // abstract pathname. 
    // Implementation code: 5CC49E15
    object_t boolean_readable;
    object_t boolean_owneronly;
    object_t object;
    bool_t ret_value = 0;

    boolean_owneronly = stack_pop();
    boolean_readable = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: boolean
    stack_push( value_create( &ret_value, T_BOOLEAN ) );
}

void native_method_io_file_setreadonly( void )
{
    // boolean setReadOnly()
    // Marks the file or directory named by this abstract pathname 
    // so that only read operations are allowed. 
    // Implementation code: 7AA16A1A
    object_t object;
    bool_t ret_value = 0;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: boolean
    stack_push( value_create( &ret_value, T_BOOLEAN ) );
}

void native_method_io_file_setwritable_boolean( void )
{
    // boolean setWritable(boolean writable)
    // A convenience method to set the owner's write permission 
    // for this abstract pathname. 
    // Implementation code: 5BBB9A84
    object_t boolean_writable;
    object_t object;
    bool_t ret_value = 0;

    boolean_writable = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: boolean
    stack_push( value_create( &ret_value, T_BOOLEAN ) );
}

void native_method_io_file_setwritable_boolean_boolean( void )
{
    // boolean setWritable(boolean writable, boolean ownerOnly)
    // Sets the owner's or everybody's write permission for this 
    // abstract pathname. 
    // Implementation code: 7B85B98B
    object_t boolean_writable;
    object_t boolean_owneronly;
    object_t object;
    bool_t ret_value = 0;

    boolean_owneronly = stack_pop();
    boolean_writable = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: boolean
    stack_push( value_create( &ret_value, T_BOOLEAN ) );
}

void native_method_io_file_tostring( void )
{
    // String toString()
    // Returns the pathname string of this abstract pathname. 
    // Implementation code: 4C604DBE
    object_t object;
    object_t new_object;
    object_t * fields_obj;
    object_t * fields_new;
    char * path;
    
    object = stack_peek(0);

    // put your code here
    fields_obj = object_get_fields_ptr( object );
    path = strings_get_text_ptr( fields_obj[ NATIVE_FIELD_IO_FILE_PATH ] );
    
    new_object = native_io_file_new();
    fields_new = object_get_fields_ptr( new_object );
    fields_new[ NATIVE_FIELD_IO_FILE_PATH ] = strings_create( path );

    // return type: File
    stack_remove(1);
    stack_push( new_object );
}



///////////////////////////////////////////////////////////////////////////

void native_io_file_get_field(uint16_t mref)
{
    switch( mref )
    {
        case NATIVE_FIELD_IO_FILE_PATHSEPARATOR:
            // static String pathSeparator
            // Implementation field read code: FIELD_READ_IO_FILE_PATHSEPARATOR
            stack_push( strings_create( NATIVE_FIELD_VALUE_IO_FILE_PATHSEPARATOR ) );
            break;

        case NATIVE_FIELD_IO_FILE_PATHSEPARATORCHAR:
            // static char pathSeparatorChar
            // Implementation field read code: FIELD_READ_IO_FILE_PATHSEPARATORCHAR
            stack_push( value_create_character( NATIVE_FIELD_VALUE_IO_FILE_PATHSEPARATORCHAR ) );
            break;

        case NATIVE_FIELD_IO_FILE_SEPARATOR:
            // static String separator
            // Implementation field read code: FIELD_READ_IO_FILE_SEPARATOR
            stack_push( strings_create( NATIVE_FIELD_VALUE_IO_FILE_SEPARATOR ) );
            break;

        case NATIVE_FIELD_IO_FILE_SEPARATORCHAR:
            // static char separatorChar
            // Implementation field read code: FIELD_READ_IO_FILE_SEPARATORCHAR
            stack_push( value_create_character( NATIVE_FIELD_VALUE_IO_FILE_SEPARATORCHAR ) );
            break;

        default: 
            exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
            break;
    }
}

void native_io_file_invoke(uint16_t mref)
{
    switch( mref )
    {
        case NATIVE_IO_FILE_INIT_FILE_STRING:
            native_method_io_file_init_file_string();
            break;

        case NATIVE_IO_FILE_INIT_STRING:
            native_method_io_file_init_string();
            break;

        case NATIVE_IO_FILE_INIT_STRING_STRING:
            native_method_io_file_init_string_string();
            break;

        case NATIVE_IO_FILE_INIT_URI:
            native_method_io_file_init_uri();
            break;

        case NATIVE_IO_FILE_CANEXECUTE:
            native_method_io_file_canexecute();
            break;

        case NATIVE_IO_FILE_CANREAD:
            native_method_io_file_canread();
            break;

        case NATIVE_IO_FILE_CANWRITE:
            native_method_io_file_canwrite();
            break;

        case NATIVE_IO_FILE_COMPARETO_FILE:
            native_method_io_file_compareto_file();
            break;

        case NATIVE_IO_FILE_CREATENEWFILE:
            native_method_io_file_createnewfile();
            break;

        case NATIVE_IO_FILE_CREATETEMPFILE_STRING_STRING:
            native_method_io_file_createtempfile_string_string();
            break;

        case NATIVE_IO_FILE_CREATETEMPFILE_STRING_STRING_FILE:
            native_method_io_file_createtempfile_string_string_file();
            break;

        case NATIVE_IO_FILE_DELETE:
            native_method_io_file_delete();
            break;

        case NATIVE_IO_FILE_DELETEONEXIT:
            native_method_io_file_deleteonexit();
            break;

        case NATIVE_IO_FILE_EQUALS_OBJECT:
            native_method_io_file_equals_object();
            break;

        case NATIVE_IO_FILE_EXISTS:
            native_method_io_file_exists();
            break;

        case NATIVE_IO_FILE_GETABSOLUTEFILE:
            native_method_io_file_getabsolutefile();
            break;

        case NATIVE_IO_FILE_GETABSOLUTEPATH:
            native_method_io_file_getabsolutepath();
            break;

        case NATIVE_IO_FILE_GETCANONICALFILE:
            native_method_io_file_getcanonicalfile();
            break;

        case NATIVE_IO_FILE_GETCANONICALPATH:
            native_method_io_file_getcanonicalpath();
            break;

        case NATIVE_IO_FILE_GETFREESPACE:
            native_method_io_file_getfreespace();
            break;

        case NATIVE_IO_FILE_GETNAME:
            native_method_io_file_getname();
            break;

        case NATIVE_IO_FILE_GETPARENT:
            native_method_io_file_getparent();
            break;

        case NATIVE_IO_FILE_GETPARENTFILE:
            native_method_io_file_getparentfile();
            break;

        case NATIVE_IO_FILE_GETPATH:
            native_method_io_file_getpath();
            break;

        case NATIVE_IO_FILE_GETTOTALSPACE:
            native_method_io_file_gettotalspace();
            break;

        case NATIVE_IO_FILE_GETUSABLESPACE:
            native_method_io_file_getusablespace();
            break;

        case NATIVE_IO_FILE_HASHCODE:
            native_method_io_file_hashcode();
            break;

        case NATIVE_IO_FILE_ISABSOLUTE:
            native_method_io_file_isabsolute();
            break;

        case NATIVE_IO_FILE_ISDIRECTORY:
            native_method_io_file_isdirectory();
            break;

        case NATIVE_IO_FILE_ISFILE:
            native_method_io_file_isfile();
            break;

        case NATIVE_IO_FILE_ISHIDDEN:
            native_method_io_file_ishidden();
            break;

        case NATIVE_IO_FILE_LASTMODIFIED:
            native_method_io_file_lastmodified();
            break;

        case NATIVE_IO_FILE_LENGTH:
            native_method_io_file_length();
            break;

        case NATIVE_IO_FILE_LIST:
            native_method_io_file_list();
            break;

        case NATIVE_IO_FILE_LIST_FILENAMEFILTER:
            native_method_io_file_list_filenamefilter();
            break;

        case NATIVE_IO_FILE_LISTFILES:
            native_method_io_file_listfiles();
            break;

        case NATIVE_IO_FILE_LISTFILES_FILEFILTER:
            native_method_io_file_listfiles_filefilter();
            break;

        case NATIVE_IO_FILE_LISTFILES_FILENAMEFILTER:
            native_method_io_file_listfiles_filenamefilter();
            break;

        case NATIVE_IO_FILE_LISTROOTS:
            native_method_io_file_listroots();
            break;

        case NATIVE_IO_FILE_MKDIR:
            native_method_io_file_mkdir();
            break;

        case NATIVE_IO_FILE_MKDIRS:
            native_method_io_file_mkdirs();
            break;

        case NATIVE_IO_FILE_RENAMETO_FILE:
            native_method_io_file_renameto_file();
            break;

        case NATIVE_IO_FILE_SETEXECUTABLE_BOOLEAN:
            native_method_io_file_setexecutable_boolean();
            break;

        case NATIVE_IO_FILE_SETEXECUTABLE_BOOLEAN_BOOLEAN:
            native_method_io_file_setexecutable_boolean_boolean();
            break;

        case NATIVE_IO_FILE_SETLASTMODIFIED_LONG:
            native_method_io_file_setlastmodified_long();
            break;

        case NATIVE_IO_FILE_SETREADABLE_BOOLEAN:
            native_method_io_file_setreadable_boolean();
            break;

        case NATIVE_IO_FILE_SETREADABLE_BOOLEAN_BOOLEAN:
            native_method_io_file_setreadable_boolean_boolean();
            break;

        case NATIVE_IO_FILE_SETREADONLY:
            native_method_io_file_setreadonly();
            break;

        case NATIVE_IO_FILE_SETWRITABLE_BOOLEAN:
            native_method_io_file_setwritable_boolean();
            break;

        case NATIVE_IO_FILE_SETWRITABLE_BOOLEAN_BOOLEAN:
            native_method_io_file_setwritable_boolean_boolean();
            break;

        case NATIVE_IO_FILE_TOSTRING:
            native_method_io_file_tostring();
            break;

        default:
            exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
            break;

    }
}


