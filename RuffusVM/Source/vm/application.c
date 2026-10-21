#include "application.h"
#include "heap.h"
#include "stack.h"
#include "vm.h"
#include "board.h"
#include "methods.h"
#include "exceptions.h"
#include "native.h"
#include "threads.h"
#include "file_module.h"
#include "lang_class_lib.h"

///////////////////////////////////////////////////////////////////////////

app_data_t * app_data;

///////////////////////////////////////////////////////////////////////////

static app_data_t * first_app;
static app_data_t * last_app;

static uint16_t app_counter;

static bool_t app_debug_mode;

///////////////////////////////////////////////////////////////////////////

#define RUN_APPLICATION_CYCLES		10

///////////////////////////////////////////////////////////////////////////

void _app_add_to_list( app_data_t * vm_app )
{
	if( first_app == NULL )
	{
		first_app = vm_app;
	}
	else
	{
		last_app->next = vm_app;
	}

	last_app = vm_app;
	vm_app->next = NULL;
}

void _app_execute_init_code( app_data_t * vm_app )
{
	uint16_t counter;

	for( counter = 0; counter < vm_app->file_header->total_methods; counter++ )
	{
		if( vm_app->methods_ptr[counter].flags & FLAG_CLINIT )
		{
			vm_invoke_new( &vm_app->methods_ptr[counter], 0, NULL );	
            thread_get()->run_mode |= THREAD_ONE_OFF;

			while(vm_run() != APP_THREAD_END)
			{
			}
		}
	}
}

void * _app_get_method_pointer( app_data_t * vm_app )
{
    //vm_app->methods_ptr = ( app_method_t * )((( uint32_t )( vm_app->file_header )) + vm_app->file_header->method_offset);
    uint8_t * p_ret;
    
    p_ret = ( uint8_t * )( vm_app->file_header );
    p_ret = &p_ret[vm_app->file_header->method_offset];
    
    return p_ret;
}

void * _app_get_const_pointer( app_data_t * vm_app )
{
	//instance_set_const( ( uint32_t * )((( uint32_t )( vm_app->file_header )) + vm_app->file_header->constant_offset) );
    uint8_t * p_ret;
    
    p_ret = ( uint8_t * )vm_app->file_header;
    p_ret = &p_ret[vm_app->file_header->constant_offset];
    
    return p_ret;
}

uint16_t app_open_file( const char * filename )
{
    uint16_t ret_code = 0;
    uint8_t * buffer;
    app_data_t * app_data;

    file_stream_t fp;
    uint32_t size;

    // get file size
	if( vm_file_open( &fp, filename, vm_open_read ) == VM_FILE_OK )
    {
		size = vm_file_get_size( &fp );

        if( size < FILE_MAX_SIZE )
        {
			app_data = ( app_data_t * )malloc( sizeof( app_data_t ) );
			if( app_data == NULL ) 
			{
				vm_file_close( &fp );
				return 0;
			}

            // allocate memory and read file
            buffer = ( uint8_t * )malloc( size );
			if( buffer == NULL )
			{
				free( app_data );
				vm_file_close( &fp );
				return 0;
			}

            vm_file_read( buffer, size, 1, &fp );

            // load java application here
            ret_code = app_load( app_data, buffer, ( uint32_t )size, FALSE );
        }

        vm_file_close( &fp );
    }

    return ret_code;
}

void app_set_printk_mode( bool_t mode )
{
    app_debug_mode = mode;
}

void app_set_debug_mode( bool_t mode )
{
    app_debug_mode = mode;
}
void app_ruffus_init( void )
{
    vm_monitor_init();

	ms_timer_hw_init();
	rtc_driver_init();
    vm_filesystem_init();

	first_app = NULL;
	last_app = NULL;
    
    app_debug_mode = FALSE;

	app_counter = 0;
}

uint16_t app_load( app_data_t * vm_app, uint8_t * buffer, uint32_t size, bool_t is_rom )
{
	app_method_t * ptr_main;
    app_instance_t * prev_instance;
	//uint16_t constants;
	
	#if SET_LEVEL_METHOD
	uint32_t i;
	#endif

	if( size >= FILE_MAX_SIZE )
	{
		app_set_error( ERROR_VM_FILE_TOO_BIG );
		return 0;
	}

	memset( vm_app, 0x00, sizeof( app_data_t ) );

	app_data = vm_app;

	// set instance
	app_data->app_instance.error_invalid_ref = exception_throw_error_invalid_ref;
	app_data->app_instance.error_out_of_bounds = exception_throw_error_out_of_bounds;
	app_data->app_instance.error_string_out_of_bounds = exception_throw_error_string_out_of_bounds;
	app_data->app_instance.error_array_out_of_bounds = exception_throw_error_array_out_of_bounds;
	app_data->app_instance.error_division_by_zero = exception_throw_error_arithmetic_division_by_zero;
	app_data->app_instance.error_negative_array = exception_throw_error_negative_array;
	app_data->app_instance.error_memory_overflow = app_error_memory_overflow;
	app_data->app_instance.error_heap_corrupted = app_error_heap_corrupted;

	prev_instance = instance_set_app( &app_data->app_instance );

	// setup file pointer
	vm_app->file_header = ( app_header_t * )buffer;
	vm_app->size = size;
	vm_app->from_rom = is_rom;

	// load methods
	//vm_app->methods_ptr = ( app_method_t * )((( uint32_t )( vm_app->file_header )) + vm_app->file_header->method_offset);
    vm_app->methods_ptr = ( app_method_t * )_app_get_method_pointer(vm_app);
    
	// init heap
	heap_init( app_data->heap_mem, HEAPSIZE );

	// init debug
	vm_app->debug_mode = app_debug_mode;
    vm_app->debug_pause = FALSE;
    vm_app->debug_printk = TRUE;
    
	if( vm_app->debug_mode == TRUE )
	{
		vm_app->debug_pause = TRUE;
        vm_app->vm_state = MONITOR_PAUSE;
	}
    
    app_debug_mode = FALSE;

	// init statics and const (FIX_ME 64bit)
	instance_set_statics( vm_app->file_header->total_statics );
	//instance_set_const( ( uint32_t * )((( uint32_t )( vm_app->file_header )) + vm_app->file_header->constant_offset) );
    instance_set_const(( uint32_t * )_app_get_const_pointer(vm_app));
    
    vm_monitor_base_address( (uint32_t)vm_app->file_header );
    
    ruffus_native_init();

	// set app index
	vm_app->app_index = ++app_counter;
    vm_app->set_exit = FALSE;

	// execute init calls
	_app_execute_init_code( vm_app );

	// prepare main call
	ptr_main = method_get_data( vm_app->file_header->main );
	vm_invoke_new( ptr_main, 0, NULL );
    
	// set the thread as main
	vm_app->thread_obj->run_mode |= THREAD_TYPE_MAIN;

	#if SET_LEVEL_METHOD
    DEBUG_METHOD( "method list\n" );
	for(i=0;i<vm_app->file_header->total_methods;i++) 
	{
		app_method_t * method_hdr = &vm_app->methods_ptr[i];
		DEBUG_METHOD( "   [%2d] = 0x%04x - %s\n", i, method_hdr->id, method_get_name_by_index(i) );
	}
	#endif

	// add to the app list
	_app_add_to_list( vm_app );
    
    instance_set_app( prev_instance );
	return vm_app->app_index;
}

uint16_t app_get_count( void )
{
	app_data_t * ret_ptr = NULL;
    uint16_t cnt = 0;
    
    while( ( ret_ptr = app_get_app_chain( ret_ptr ) ) != NULL )
    {
        cnt++;
    }    
    
    return cnt;
}

uint16_t app_debug_set_state( uint8_t state )
{
	app_data_t * ret_ptr = NULL;
    
    while( ( ret_ptr = app_get_app_chain( ret_ptr ) ) != NULL )
    {
        if( ret_ptr->debug_mode == TRUE )
        {
            ret_ptr->vm_state = state;
            return ret_ptr->app_index;
        }
    }    
    
    return 0;
}

void app_kill_all( void )
{
	app_data_t * ret_ptr = NULL;
    
    while( ( ret_ptr = app_get_app_chain( ret_ptr ) ) != NULL )
    {
        app_set_exit( ret_ptr );
    }
}

void app_kill( uint16_t index )
{
	app_data_t * ret_ptr = NULL;
    
    while( ( ret_ptr = app_get_app_chain( ret_ptr ) ) != NULL )
    {
        if( ret_ptr->app_index == index )
        {
            app_set_exit( ret_ptr );
            break;
        }
    }
}

void app_reset( void )
{
}

void app_set_exit( app_data_t * app )
{
    app->set_exit = TRUE;
}

void app_java_call_start( app_java_call_t * call_env )
{
    call_env->call_instance = instance_set_app( call_env->instance );
    if( call_env->is_static == FALSE ) call_env->param_index++;
}

void app_java_call_add_param( app_java_call_t * call_env, object_t param )
{
    if( call_env->call_instance == NULL ) return;
        
    if( call_env->param_index == call_env->param_cnt ) return;
    call_env->arg_list[ call_env->param_index++ ] = param;
}

void app_java_call_finish( app_java_call_t * call_env )
{
    if( call_env->call_instance != NULL )
    {
        instance_set_app( call_env->call_instance );        
        call_env->call_instance = NULL;
        call_env->param_index = 0;
        call_env->ret_object = 0;
    }
    
    return;
}

object_t app_java_call_execute( object_t object, app_java_call_t * call_env )
{
    // check if instance has been switched
    if( call_env->call_instance == NULL ) return 0;

    // check if there is valid object for non-static call
    if( call_env->is_static == FALSE )
    {
        if( call_env->call_object != 0 ) object = call_env->call_object;
        if( object == 0 ) return 0;
        call_env->arg_list[0] = object;
    }

    // clear return object
    thread_instance()->return_object = 0;
    
    vm_invoke_new( call_env->method, object, call_env->arg_list );
    
    return 0;
}

char * app_get_class_name( uint32_t cref )
{
    uint32_t index = GET_CLASS_INDEX(cref);
    uint32_t const_index = app_data->file_header->total_const - app_data->file_header->total_classes + index;
    return ( char * )object_get_ptr( CONST_OBJECT_ID + const_index );
}

app_instance_t * app_locate_java_method_by_class( object_t class_object, char * method_name, app_java_call_t * call_env )
{
	object_t call_object;
    app_instance_t * curr_instance;
    app_method_t * ptr_method;
    uint32_t cref;

    curr_instance = lang_class_lib_get_info( class_object, &call_object, &cref );
    
    ptr_method = method_locate_by_class( cref, method_name );
    
    if( ptr_method != NULL )
    {
        call_env->method = ptr_method;
        call_env->instance = curr_instance;
        call_env->is_static = ( ptr_method->flags & FLAG_STATIC ) ? TRUE : FALSE;
        call_env->param_cnt = ptr_method->args;
        call_env->call_instance = NULL;
        call_env->param_index = 0;
        call_env->ret_object = 0;
        call_env->call_object = call_object;

        return curr_instance;
    }    
    
    return NULL;
}

app_instance_t * app_locate_java_method_by_object( object_t object, char * method_name, app_java_call_t * call_env )
{
    return NULL;
}

app_instance_t * app_locate_java_method_by_class_name( char * class_name, char * method_name, app_java_call_t * call_env )
{
    app_data_t * vm_app;
    app_instance_t * curr_instance;
    app_method_t * ptr_method;
    uint32_t index;
    uint32_t cref;
    
    if( first_app == NULL ) return NULL;
    
    // save the current instance
    curr_instance = instance_set_app(NULL);
    
    vm_app = first_app;
    
    while( vm_app != NULL )
    {
        // set up the app
        app_data = vm_app;
        vm_app = vm_app->next;
        
        instance_set_app( &app_data->app_instance );
        
        for( index = 0; index < app_data->file_header->total_classes; index++ )
        {
            // locate class that contains the method
            if( !strcmp( app_get_class_name( GET_CLASS_REF( index ) ), class_name ) )
            {
                // check if this class contains the method
                cref = GET_CLASS_REF( index );
                ptr_method = method_locate_by_class( cref, method_name );
                
                if( ptr_method != NULL )
                {
                    call_env->method = ptr_method;
                    call_env->instance = &app_data->app_instance;
                    call_env->is_static = ( ptr_method->flags & FLAG_STATIC ) ? TRUE : FALSE;
                    call_env->param_cnt = ptr_method->args;
                    call_env->call_instance = NULL;
                    call_env->param_index = 0;
                    call_env->ret_object = 0;
                    call_env->call_object = 0;
                    
                    instance_set_app( curr_instance );
                    return curr_instance;
                }
            }
        }
    }
    
    instance_set_app( curr_instance );
    return NULL;
}

app_data_t * app_get_vm( uint16_t index )
{
    app_data_t * vm_app;
    
    vm_app = first_app;
    
    while( vm_app != NULL )
    {
        if( vm_app->app_index == index ) return vm_app;
        vm_app = vm_app->next;
    }
    
    return NULL;
}

app_data_t * app_execute_vm( void )
{
	app_data_t * vm_app;
	app_data_t * ret_ptr = NULL;

    uint8_t ret;
	uint8_t cycles;
	bool_t stopped = FALSE;

	// no applications to run
	if( first_app == NULL ) return NULL;

	// get and unlink first from the list
	vm_app = first_app;
	first_app = vm_app->next;
	if( first_app == NULL ) last_app = NULL;
    
	// set as current application
	app_data = vm_app;
    instance_set_app( &app_data->app_instance );
    
	// execute for a number of cycles
	for( cycles = 0; cycles < RUN_APPLICATION_CYCLES; cycles++ )
	{
		lang_rand_generate();

        ret = vm_run();
        
		if( ret == APP_RUN_EXIT )
		{
			// close application
			// app_destroy( vm_app );
			ret_ptr = vm_app;

			// indicate that stopped
			stopped = TRUE;
            
            // release static objects
            instance_delete_statics();
            
            // do a garbage collection, that will release everything
            // 1) there is no stack
            // 2) there is no statics
            object_garbage_collection();

			break;
		}
        else if( ret == APP_RUN_YIELD )
        {
            break;
        }
	}

	if( stopped == FALSE )
	{
		// link the application again
		_app_add_to_list( vm_app );
	}

	return ret_ptr;
}

app_data_t * app_get_app_chain( app_data_t * app )
{
	static app_data_t * _app_first;

	if( app == NULL ) 
	{
		_app_first = first_app;
	}
	else
	{
		_app_first = _app_first->next;
	}

	return _app_first;
}

void * app_get_file_buffer( app_data_t * app_data )
{
	return app_data->file_header;
}

uint32_t app_class_total_fields( uint32_t class_ref )
{
	uint32_t class_index = GET_CLASS_INDEX( class_ref );
	return app_data->file_header->class_list[ class_index ].fields;
}

void app_set_error( uint32_t error )
{
	if( ( error != 0 ) && ( error != ERROR_HEAP_CORRUPTED ) )
	{
		DEBUG_INFO( "\n\nException occured: %d\n", error );
		stack_dump();
		heap_dump();
	}

	longjmp(app_data->state, EXCEPTION_EXIT);
}

uint32_t app_get_super_class( uint32_t class_ref )
{
	uint32_t class_index = GET_CLASS_INDEX( class_ref );

	// search super class of a native class
	if( class_index >= NATIVE_CLASS_BASE )
	{
		return native_superclass( class_ref );
	}

	return GET_CLASS_REF( app_data->file_header->class_list[ class_index ].super );
}

void app_error_heap_corrupted( void )
{
	app_set_error(ERROR_HEAP_CORRUPTED);   
}

void app_error_memory_overflow( void )
{
	app_set_error(ERROR_HEAP_MEMORY_OVERFLOW);   
}
