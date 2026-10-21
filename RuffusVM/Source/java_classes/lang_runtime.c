#include "lang_runtime.h"
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

object_t native_lang_runtime_new( void )
{
    return( object_create( GET_CLASS_REF( NATIVE_CLASS_LANG_RUNTIME ), T_CLASS, NATIVE_LANG_RUNTIME_TOTAL_FIELDS ) );
}

///////////////////////////////////////////////////////////////////////////

void native_method_lang_runtime_addshutdownhook_thread( void )
{
    // void addShutdownHook(Thread hook)
    // Registers a new virtual-machine shutdown hook. 
    // Implementation code: 1A5BEC2D
    object_t thread_hook;
    object_t object;

    thread_hook = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_lang_runtime_availableprocessors( void )
{
    // int availableProcessors()
    // Returns the number of processors available to the Java virtual 
    // machine. 
    // Implementation code: 04DB8B31
    object_t object;
    int32_t ret_value = 0;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push( value_create( &ret_value, T_INT ) );
}

void native_method_lang_runtime_exec_string( void )
{
    // Process exec(String command)
    // Executes the specified string command in a separate process. 
    // Implementation code: 746020CE
    object_t string_command;
    object_t object;

    string_command = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: Process
    stack_push( 0 );
}

void native_method_lang_runtime_exec_array_string( void )
{
    // Process exec(String[] cmdarray)
    // Executes the specified command and arguments in a separate 
    // process. 
    // Implementation code: 025F7401
    object_t string_array_cmdarray;
    object_t object;

    string_array_cmdarray = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: Process
    stack_push( 0 );
}

void native_method_lang_runtime_exec_array_string_array_string( void )
{
    // Process exec(String[] cmdarray, String[] envp)
    // Executes the specified command and arguments in a separate 
    // process with the specified environment. 
    // Implementation code: EB0BA07C
    object_t string_array_cmdarray;
    object_t string_array_envp;
    object_t object;

    string_array_envp = stack_pop();
    string_array_cmdarray = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: Process
    stack_push( 0 );
}

void native_method_lang_runtime_exec_array_string_array_string_file( void )
{
    // Process exec(String[] cmdarray, String[] envp, File dir)
    // Executes the specified command and arguments in a separate 
    // process with the specified environment and working directory. 
    // Implementation code: 30979C39
    object_t string_array_cmdarray;
    object_t string_array_envp;
    object_t file_dir;
    object_t object;

    file_dir = stack_pop();
    string_array_envp = stack_pop();
    string_array_cmdarray = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: Process
    stack_push( 0 );
}

void native_method_lang_runtime_exec_string_array_string( void )
{
    // Process exec(String command, String[] envp)
    // Executes the specified string command in a separate process 
    // with the specified environment. 
    // Implementation code: 24286FC0
    object_t string_command;
    object_t string_array_envp;
    object_t object;

    string_array_envp = stack_pop();
    string_command = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: Process
    stack_push( 0 );
}

void native_method_lang_runtime_exec_string_array_string_file( void )
{
    // Process exec(String command, String[] envp, File dir)
    // Executes the specified string command in a separate process 
    // with the specified environment and working directory. 
    // Implementation code: 9E0A79F6
    object_t string_command;
    object_t string_array_envp;
    object_t file_dir;
    object_t object;

    file_dir = stack_pop();
    string_array_envp = stack_pop();
    string_command = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: Process
    stack_push( 0 );
}

void native_method_lang_runtime_exit_int( void )
{
    // void exit(int status)
    // Terminates the currently running Java virtual machine by 
    // initiating its shutdown sequence. 
    // Implementation code: FE752441
    object_t int_status;
    object_t object;

    int_status = stack_pop();
    object = stack_pop();

    // put your code here
    longjmp(app_data->state, EXCEPTION_EXIT);
}

void native_method_lang_runtime_freememory( void )
{
    // long freeMemory()
    // Returns the amount of free memory in the Java Virtual Machine. 
    // Implementation code: 3BDA42CB
    object_t object;
    int64_t ret_value = 0L;

    object = stack_pop();

    // put your code here
	ret_value = heap_size() - heap_in_use();

    // return type: long
    stack_push( value_create( &ret_value, T_LONG ) );
}

void native_method_lang_runtime_gc( void )
{
    // void gc()
    // Runs the garbage collector. 
    // Implementation code: 1977279C
    object_t object;

    object = stack_pop();

    // put your code here
    object_garbage_collection();
}

void native_method_lang_runtime_getlocalizedinputstream_inputstream( void )
{
    // InputStream getLocalizedInputStream(InputStream in)
    // Deprecated. As of JDK 1.1, the preferred way to translate 
    // a byte stream in the local encoding into a character stream 
    // in Unicode is via the InputStreamReader and BufferedReader 
    // classes. 
    // Implementation code: 20240256
    object_t inputstream_in;
    object_t object;

    inputstream_in = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: InputStream
    stack_push( 0 );
}

void native_method_lang_runtime_getlocalizedoutputstream_outputstream( void )
{
    // OutputStream getLocalizedOutputStream(OutputStream out)
    // Deprecated. As of JDK 1.1, the preferred way to translate 
    // a Unicode character stream into a byte stream in the local 
    // encoding is via the OutputStreamWriter, BufferedWriter, 
    // and PrintWriter classes. 
    // Implementation code: B21500F7
    object_t outputstream_out;
    object_t object;

    outputstream_out = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: OutputStream
    stack_push( 0 );
}

void native_method_lang_runtime_getruntime( void )
{
    // static Runtime getRuntime()
    // Returns the runtime object associated with the current Java 
    // application. 
    // Implementation code: 4B5D1CFD

    // return type: Runtime
    stack_push( native_lang_runtime_new() );
}

void native_method_lang_runtime_halt_int( void )
{
    // void halt(int status)
    // Forcibly terminates the currently running Java virtual machine. 
    // Implementation code: 476C7DEE
    object_t int_status;
    object_t object;

    int_status = stack_pop();
    object = stack_pop();

    // put your code here
    longjmp(app_data->state, EXCEPTION_EXIT);
}

void native_method_lang_runtime_load_string( void )
{
    // void load(String filename)
    // Loads the specified filename as a dynamic library. 
    // Implementation code: 6F34F5B9
    object_t string_filename;
    object_t object;

    string_filename = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_lang_runtime_loadlibrary_string( void )
{
    // void loadLibrary(String libname)
    // Loads the dynamic library with the specified library name. 
    // Implementation code: DB70FC4E
    object_t string_libname;
    object_t object;

    string_libname = stack_pop();
    object = stack_pop();

    // put your code here
	app_open_file( strings_get_text_ptr( string_libname ) );
}

void native_method_lang_runtime_maxmemory( void )
{
    // long maxMemory()
    // Returns the maximum amount of memory that the Java virtual 
    // machine will attempt to use. 
    // Implementation code: EDB499DF
    object_t object;
    int64_t ret_value = 0L;

    object = stack_pop();

    // put your code here
	ret_value = heap_size();

    // return type: long
    stack_push( value_create( &ret_value, T_LONG ) );
}

void native_method_lang_runtime_removeshutdownhook_thread( void )
{
    // boolean removeShutdownHook(Thread hook)
    // De-registers a previously-registered virtual-machine shutdown 
    // hook. 
    // Implementation code: 83E44889
    object_t thread_hook;
    object_t object;
    bool_t ret_value = 0;

    thread_hook = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: boolean
    stack_push( value_create( &ret_value, T_BOOLEAN ) );
}

void native_method_lang_runtime_runfinalization( void )
{
    // void runFinalization()
    // Runs the finalization methods of any objects pending finalization. 
    // Implementation code: 04ECE372
    object_t object;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_lang_runtime_runfinalizersonexit_boolean( void )
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

void native_method_lang_runtime_totalmemory( void )
{
    // long totalMemory()
    // Returns the total amount of memory in the Java virtual machine. 
    // Implementation code: 9E57D841
    object_t object;
    int64_t ret_value = 0L;

    object = stack_pop();

    // put your code here
    ret_value = heap_size();

    // return type: long
    stack_push( value_create( &ret_value, T_LONG ) );
}

void native_method_lang_runtime_traceinstructions_boolean( void )
{
    // void traceInstructions(boolean on)
    // Enables/Disables tracing of instructions. 
    // Implementation code: 9927CAB7
    object_t boolean_on;
    object_t object;

    boolean_on = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_lang_runtime_tracemethodcalls_boolean( void )
{
    // void traceMethodCalls(boolean on)
    // Enables/Disables tracing of method calls. 
    // Implementation code: 4197B941
    object_t boolean_on;
    object_t object;

    boolean_on = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

///////////////////////////////////////////////////////////////////////////

uint32_t native_lang_runtime_get_superclass( void )
{
	return NATIVE_CLASS_LANG_OBJECT;
}

void native_lang_runtime_invoke(uint16_t mref)
{
    switch( mref )
    {
        case NATIVE_LANG_RUNTIME_ADDSHUTDOWNHOOK_THREAD:
            native_method_lang_runtime_addshutdownhook_thread();
            break;

        case NATIVE_LANG_RUNTIME_AVAILABLEPROCESSORS:
            native_method_lang_runtime_availableprocessors();
            break;

        case NATIVE_LANG_RUNTIME_EXEC_STRING:
            native_method_lang_runtime_exec_string();
            break;

        case NATIVE_LANG_RUNTIME_EXEC_ARRAY_STRING:
            native_method_lang_runtime_exec_array_string();
            break;

        case NATIVE_LANG_RUNTIME_EXEC_ARRAY_STRING_ARRAY_STRING:
            native_method_lang_runtime_exec_array_string_array_string();
            break;

        case NATIVE_LANG_RUNTIME_EXEC_ARRAY_STRING_ARRAY_STRING_FILE:
            native_method_lang_runtime_exec_array_string_array_string_file();
            break;

        case NATIVE_LANG_RUNTIME_EXEC_STRING_ARRAY_STRING:
            native_method_lang_runtime_exec_string_array_string();
            break;

        case NATIVE_LANG_RUNTIME_EXEC_STRING_ARRAY_STRING_FILE:
            native_method_lang_runtime_exec_string_array_string_file();
            break;

        case NATIVE_LANG_RUNTIME_EXIT_INT:
            native_method_lang_runtime_exit_int();
            break;

        case NATIVE_LANG_RUNTIME_FREEMEMORY:
            native_method_lang_runtime_freememory();
            break;

        case NATIVE_LANG_RUNTIME_GC:
            native_method_lang_runtime_gc();
            break;

        case NATIVE_LANG_RUNTIME_GETLOCALIZEDINPUTSTREAM_INPUTSTREAM:
            native_method_lang_runtime_getlocalizedinputstream_inputstream();
            break;

        case NATIVE_LANG_RUNTIME_GETLOCALIZEDOUTPUTSTREAM_OUTPUTSTREAM:
            native_method_lang_runtime_getlocalizedoutputstream_outputstream();
            break;

        case NATIVE_LANG_RUNTIME_GETRUNTIME:
            native_method_lang_runtime_getruntime();
            break;

        case NATIVE_LANG_RUNTIME_HALT_INT:
            native_method_lang_runtime_halt_int();
            break;

        case NATIVE_LANG_RUNTIME_LOAD_STRING:
            native_method_lang_runtime_load_string();
            break;

        case NATIVE_LANG_RUNTIME_LOADLIBRARY_STRING:
            native_method_lang_runtime_loadlibrary_string();
            break;

        case NATIVE_LANG_RUNTIME_MAXMEMORY:
            native_method_lang_runtime_maxmemory();
            break;

        case NATIVE_LANG_RUNTIME_REMOVESHUTDOWNHOOK_THREAD:
            native_method_lang_runtime_removeshutdownhook_thread();
            break;

        case NATIVE_LANG_RUNTIME_RUNFINALIZATION:
            native_method_lang_runtime_runfinalization();
            break;

        case NATIVE_LANG_RUNTIME_RUNFINALIZERSONEXIT_BOOLEAN:
            native_method_lang_runtime_runfinalizersonexit_boolean();
            break;

        case NATIVE_LANG_RUNTIME_TOTALMEMORY:
            native_method_lang_runtime_totalmemory();
            break;

        case NATIVE_LANG_RUNTIME_TRACEINSTRUCTIONS_BOOLEAN:
            native_method_lang_runtime_traceinstructions_boolean();
            break;

        case NATIVE_LANG_RUNTIME_TRACEMETHODCALLS_BOOLEAN:
            native_method_lang_runtime_tracemethodcalls_boolean();
            break;

        default:
            exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
            break;

    }
}


