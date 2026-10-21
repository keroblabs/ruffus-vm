#include "lang_system.h"
#include "heap.h"
#include "application.h"
#include "threads.h"
#include "exceptions.h"
#include "native.h"
#include "objects.h"
#include "stack.h"
#include "value_type.h"
#include "strings.h"
#include "file.h"

///////////////////////////////////////////////////////////////////////////

// use New method implementation to hold a method
// use New implementation to mark start block
// use End new implementation to mark end block to keep

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////

// static PrintStream err
#define NATIVE_FIELD_VALUE_LANG_SYSTEM_ERR                                       1

// static InputStream in
#define NATIVE_FIELD_VALUE_LANG_SYSTEM_IN                                        2

// static PrintStream out
#define NATIVE_FIELD_VALUE_LANG_SYSTEM_OUT                                       3

///////////////////////////////////////////////////////////////////////////

object_t native_lang_system_new( void )
{
    return( object_create( GET_CLASS_REF( NATIVE_CLASS_LANG_SYSTEM ), T_CLASS, NATIVE_LANG_SYSTEM_TOTAL_FIELDS ) );
}

///////////////////////////////////////////////////////////////////////////

void native_method_lang_system_arraycopy_object_int_object_int_int( void )
{
    // static void arraycopy(Object src, int srcPos, Object dest, int destPos, int length)
    // Copies an array from the specified source array, beginning 
    // at the specified position, to the specified position of 
    // the destination array. 
    // Implementation code: 5743591D
    object_t object_src;
    object_t int_srcpos;
    object_t object_dest;
    object_t int_destpos;
    object_t int_length;

    int_length = stack_pop();
    int_destpos = stack_pop();
    object_dest = stack_pop();
    int_srcpos = stack_pop();
    object_src = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_lang_system_clearproperty_string( void )
{
    // static String clearProperty(String key)
    // Removes the system property indicated by the specified key. 
    // Implementation code: 2F3A3E90
    object_t string_key;

    string_key = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: String
    stack_push( strings_create( "" ) );
}

void native_method_lang_system_console( void )
{
    // static Console console()
    // Returns the unique Console object associated with the current 
    // Java virtual machine, if any. 
    // Implementation code: 5BFFFC29

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: Console
    stack_push( 0 );
}

void native_method_lang_system_currenttimemillis( void )
{
    // static long currentTimeMillis()
    // Returns the current time in milliseconds. 
    // Implementation code: 0DDFF940
    int64_t ret_value = 0L;

    // put your code here
	rtc_driver_get( &ret_value );

    // return type: long
    stack_push_long( ret_value );
}

void native_method_lang_system_exit_int( void )
{
    // static void exit(int status)
    // Terminates the currently running Java Virtual Machine. 
    // Implementation code: 633D9BD5
    object_t int_status;

    int_status = stack_pop();

    // put your code here
    longjmp(app_data->state, EXCEPTION_EXIT);
}

void native_method_lang_system_gc( void )
{
    // static void gc()
    // Runs the garbage collector. 
    // Implementation code: 1977279C

    // put your code here
    object_garbage_collection();
}


void native_method_lang_system_getenv_string( void )
{
    // static String getenv(String name)
    // Gets the value of the specified environment variable. 
    // Implementation code: CF46F4FA
    object_t string_name;

    string_name = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: String
    stack_push( strings_create( "" ) );
}

void native_method_lang_system_getproperties( void )
{
    // static Properties getProperties()
    // Determines the current system properties. 
    // Implementation code: A327077D

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: Properties
    stack_push( 0 );
}

void native_method_lang_system_getproperty_string( void )
{
    // static String getProperty(String key)
    // Gets the system property indicated by the specified key. 
    // Implementation code: 84485CB0
    object_t string_key;

    string_key = stack_pop();

    // return type: String
    stack_push( strings_create( property_get( strings_get_text_ptr( string_key ) ) ) );
}

void native_method_lang_system_getproperty_string_string( void )
{
    // static String getProperty(String key, String def)
    // Gets the system property indicated by the specified key. 
    // Implementation code: 84485CB0
    object_t string_key;
    object_t string_def;
	char * string_property;

    string_def = stack_pop();
    string_key = stack_pop();

    // put your code here
	string_property = property_get( strings_get_text_ptr( string_key ) );
	if( strlen( string_property ) == 0 )
	{
		stack_push( string_def );
		return;
	}

    // return type: String
    stack_push( strings_create( string_property ) );
}

void native_method_lang_system_getsecuritymanager( void )
{
    // static SecurityManager getSecurityManager()
    // Gets the system security interface. 
    // Implementation code: EB62A8E0

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: SecurityManager
    stack_push( 0 );
}

void native_method_lang_system_identityhashcode_object( void )
{
    // static int identityHashCode(Object x)
    // Returns the same hash code for the given object as would 
    // be returned by the default method hashCode(), whether or 
    // not the given object's class overrides hashCode(). 
    // Implementation code: 9F5E30C8
    object_t object_x;
    int32_t ret_value = 0;

    object_x = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push( value_create( &ret_value, T_INT ) );
}


void native_method_lang_system_load_string( void )
{
    // static void load(String filename)
    // Loads a code file with the specified filename from the local 
    // file system as a dynamic library. 
    // Implementation code: F4DEAB4E
    object_t string_filename;

    string_filename = stack_pop();

    // put your code here
	app_open_file( strings_get_text_ptr( string_filename ) );
}

void native_method_lang_system_loadlibrary_string( void )
{
    // static void loadLibrary(String libname)
    // Loads the system library specified by the libname argument. 
    // Implementation code: 6948AC08
    object_t string_libname;

    string_libname = stack_pop();

    // put your code here
	app_open_file( strings_get_text_ptr( string_libname ) );
}

void native_method_lang_system_maplibraryname_string( void )
{
    // static String mapLibraryName(String libname)
    // Maps a library name into a platform-specific string representing 
    // a native library. 
    // Implementation code: 0EDA664E
    object_t string_libname;

    string_libname = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: String
    stack_push( strings_create( "" ) );
}

void native_method_lang_system_nanotime( void )
{
    // static long nanoTime()
    // Returns the current value of the most precise available 
    // system timer, in nanoseconds. 
    // Implementation code: DD4B0E85
    int64_t ret_value = 0L;

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: long
    stack_push( value_create( &ret_value, T_LONG ) );
}

void native_method_lang_system_runfinalization( void )
{
    // static void runFinalization()
    // Runs the finalization methods of any objects pending finalization. 
    // Implementation code: 04ECE372

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_lang_system_runfinalizersonexit_boolean( void )
{
    // static void runFinalizersOnExit(boolean value)
    // Deprecated. This method is inherently unsafe. It may result 
    // in finalizers being called on live objects while other threads 
    // are concurrently manipulating those objects, resulting in 
    // erratic behavior or deadlock. 
    // Implementation code: E4551A05
    object_t boolean_value;

    boolean_value = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_lang_system_seterr_printstream( void )
{
    // static void setErr(PrintStream err)
    // Reassigns the "standard" error output stream. 
    // Implementation code: 7CC25273
    object_t printstream_err;

    printstream_err = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_lang_system_setin_inputstream( void )
{
    // static void setIn(InputStream in)
    // Reassigns the "standard" input stream. 
    // Implementation code: 973ED13E
    object_t inputstream_in;

    inputstream_in = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_lang_system_setout_printstream( void )
{
    // static void setOut(PrintStream out)
    // Reassigns the "standard" output stream. 
    // Implementation code: BC34E453
    object_t printstream_out;

    printstream_out = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_lang_system_setproperties_properties( void )
{
    // static void setProperties(Properties props)
    // Sets the system properties to the Properties argument. 
    // Implementation code: 721870DE
    object_t properties_props;

    properties_props = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_lang_system_setproperty_string_string( void )
{
    // static String setProperty(String key, String value)
    // Sets the system property indicated by the specified key. 
    // Implementation code: 8EB8FBFB
    object_t string_key;
    object_t string_value;
	object_t prev_property;

    string_value = stack_peek(0);
    string_key = stack_peek(1);

    // put your code here
	prev_property = strings_create( property_get( strings_get_text_ptr( string_key ) ) );
    property_set( strings_get_text_ptr( string_key ), strings_get_text_ptr( string_value ) );

    // return type: String
    stack_remove(2);
    stack_push( prev_property );
}

void native_method_lang_system_setsecuritymanager_securitymanager( void )
{
    // static void setSecurityManager(SecurityManager s)
    // Sets the System security. 
    // Implementation code: 5326F991
    object_t securitymanager_s;

    securitymanager_s = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

///////////////////////////////////////////////////////////////////////////

uint32_t native_lang_system_get_superclass( void )
{
	return NATIVE_CLASS_LANG_OBJECT;
}

void native_lang_system_get_field(uint16_t mref)
{
    object_t stream_obj;
    File * fp_file;
    uint16_t new_index;
    
    switch( mref )
    {
        case NATIVE_FIELD_LANG_SYSTEM_ERR:
            // static PrintStream err
            // Implementation field read code: FIELD_READ_LANG_SYSTEM_ERR
            stack_push( 0 );
            break;

        case NATIVE_FIELD_LANG_SYSTEM_IN:
            // static InputStream in
            // Implementation field read code: FIELD_READ_LANG_SYSTEM_IN
            stack_push( 0 );
            break;

        case NATIVE_FIELD_LANG_SYSTEM_OUT:
            // static PrintStream out
            // Implementation field read code: FIELD_READ_LANG_SYSTEM_OUT
            stream_obj = instance_locate_native_static( CREATE_ID( NATIVE_CLASS_IO_PRINTSTREAM, NATIVE_FIELD_VALUE_LANG_SYSTEM_OUT ) );
            if( stream_obj == 0 )
            {
                stream_obj = native_io_printstream_new();
                object_update_class_ref( stream_obj, NATIVE_FIELD_VALUE_LANG_SYSTEM_OUT );
                object_create_extension( stream_obj, sizeof( File ) );
                fp_file = ( File * )object_get_extension( stream_obj );  
                memset( fp_file, 0x00, sizeof( File ) );
                
                new_index = instance_resize_statics( 1 );
                instance_get_statics()[ new_index ] = stream_obj;                
            }
            stack_push( stream_obj );
            break;

        default: 
            exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
            break;
    }
}

void native_lang_system_invoke(uint16_t mref)
{
    switch( mref )
    {
        case NATIVE_LANG_SYSTEM_ARRAYCOPY_OBJECT_INT_OBJECT_INT_INT:
            native_method_lang_system_arraycopy_object_int_object_int_int();
            break;

        case NATIVE_LANG_SYSTEM_CLEARPROPERTY_STRING:
            native_method_lang_system_clearproperty_string();
            break;

        case NATIVE_LANG_SYSTEM_CONSOLE:
            native_method_lang_system_console();
            break;

        case NATIVE_LANG_SYSTEM_CURRENTTIMEMILLIS:
            native_method_lang_system_currenttimemillis();
            break;

        case NATIVE_LANG_SYSTEM_EXIT_INT:
            native_method_lang_system_exit_int();
            break;

        case NATIVE_LANG_SYSTEM_GC:
            native_method_lang_system_gc();
            break;

        case NATIVE_LANG_SYSTEM_GETENV_STRING:
            native_method_lang_system_getenv_string();
            break;

        case NATIVE_LANG_SYSTEM_GETPROPERTIES:
            native_method_lang_system_getproperties();
            break;

        case NATIVE_LANG_SYSTEM_GETPROPERTY_STRING:
            native_method_lang_system_getproperty_string();
            break;

        case NATIVE_LANG_SYSTEM_GETPROPERTY_STRING_STRING:
            native_method_lang_system_getproperty_string_string();
            break;

        case NATIVE_LANG_SYSTEM_GETSECURITYMANAGER:
            native_method_lang_system_getsecuritymanager();
            break;

        case NATIVE_LANG_SYSTEM_IDENTITYHASHCODE_OBJECT:
            native_method_lang_system_identityhashcode_object();
            break;

        case NATIVE_LANG_SYSTEM_LOAD_STRING:
            native_method_lang_system_load_string();
            break;

        case NATIVE_LANG_SYSTEM_LOADLIBRARY_STRING:
            native_method_lang_system_loadlibrary_string();
            break;

        case NATIVE_LANG_SYSTEM_MAPLIBRARYNAME_STRING:
            native_method_lang_system_maplibraryname_string();
            break;

        case NATIVE_LANG_SYSTEM_NANOTIME:
            native_method_lang_system_nanotime();
            break;

        case NATIVE_LANG_SYSTEM_RUNFINALIZATION:
            native_method_lang_system_runfinalization();
            break;

        case NATIVE_LANG_SYSTEM_RUNFINALIZERSONEXIT_BOOLEAN:
            native_method_lang_system_runfinalizersonexit_boolean();
            break;

        case NATIVE_LANG_SYSTEM_SETERR_PRINTSTREAM:
            native_method_lang_system_seterr_printstream();
            break;

        case NATIVE_LANG_SYSTEM_SETIN_INPUTSTREAM:
            native_method_lang_system_setin_inputstream();
            break;

        case NATIVE_LANG_SYSTEM_SETOUT_PRINTSTREAM:
            native_method_lang_system_setout_printstream();
            break;

        case NATIVE_LANG_SYSTEM_SETPROPERTIES_PROPERTIES:
            native_method_lang_system_setproperties_properties();
            break;

        case NATIVE_LANG_SYSTEM_SETPROPERTY_STRING_STRING:
            native_method_lang_system_setproperty_string_string();
            break;

        case NATIVE_LANG_SYSTEM_SETSECURITYMANAGER_SECURITYMANAGER:
            native_method_lang_system_setsecuritymanager_securitymanager();
            break;

        default:
            exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
            break;

    }
}


