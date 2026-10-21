#include "methods.h"
#include "vm.h"
#include "objects.h"
#include "application.h"
#include "threads.h"
#include "native.h"
#include "stack.h"

/////////////////////////////////////////////////////////////////////////////

app_method_t * method_get_data( uint16_t index )
{
    app_method_t * ret_code = &app_data->methods_ptr[index];
    char * name;
    lib_entry_t * entry;
    
    // if it's a JNI type native call, search for entry point now
    if( ( ret_code->flags & FLAG_NATIVE ) && ( ret_code->id == 0xFFFFFFFF ) )
    {
        name = ( char * )method_get_address( ret_code );
        entry = vm_search_lib( name );
        
        if( entry != NULL ) ret_code->id = ( uint32_t )entry->lib_call;
    }
    
	return ret_code;
}

app_method_t * method_locate_by_class( uint32_t cref, char * name )
{
	uint32_t counter;
	app_method_t * ptr_method;
	bool_t is_stop = FALSE;

	for( counter = 0; counter < app_data->file_header->total_methods; counter++ )
	{
		// get method data
		ptr_method = &app_data->methods_ptr[counter];

		// check if class matches
		if( cref == GET_CLASS_ID( ptr_method->id ) )
		{
			// found the class range
			is_stop = TRUE;

			// check if method name matches
			if( strcmp( name, method_get_name_by_index( counter ) ) == 0 )
			{
				return ptr_method;
			}
		}
		else if( is_stop == TRUE )
		{
			break;
		}
	}

	return NULL;    
}

app_method_t * method_find_by_name( object_t object, const char * name, uint32_t * is_native )
{
	uint32_t counter;
	app_method_t * ptr_method;
	bool_t is_stop = FALSE;

	uint32_t class_ref = object_get_class_ref( object );

	for( counter = 0; counter < app_data->file_header->total_methods; counter++ )
	{
		// get method data
		ptr_method = &app_data->methods_ptr[counter];

		// check if class matches
		if( class_ref == GET_CLASS_ID( ptr_method->id ) )
		{
			// found the class range
			is_stop = TRUE;

			// check if method name matches
			if( strcmp( name, method_get_name_by_index( counter ) ) == 0 )
			{
                if( is_native != NULL ) *is_native = 0;
				return ptr_method;
			}
		}
		else if( is_stop == TRUE )
		{
			// if got here, didnt find in the class range, get super class
			class_ref = app_get_super_class( class_ref );

			// found a native, stop
			if( class_ref >= GET_CLASS_REF( NATIVE_CLASS_BASE ) )
            {
                if( is_native != NULL ) *is_native = class_ref;
                return NULL;
            }

			// start over again
			counter = ( uint32_t )-1;
			is_stop = FALSE;
		}
	}

    if( is_native != NULL ) *is_native = 0;
	return NULL;
}

char * method_get_name_by_index( uint16_t index )
{
	uint32_t const_index =  app_data->file_header->total_const
                            - app_data->file_header->total_classes
                            - app_data->file_header->total_methods
                            + index;
	return ( char * )object_get_ptr( CONST_OBJECT_ID + const_index );
}

char * method_get_name( app_method_t * ptr_method )
{
	return( method_get_name_by_index( ptr_method->index ) );
}

uint16_t method_get_pc_index( app_method_t * method, uint8_t * pc )
{
	uint32_t index;

	index = ( uint32_t )( ( uint8_t * )pc - ( uint8_t * )method_get_address( method ) );

	return ( uint16_t )( index & 0x0FFFF );
}

exception_t * method_get_exception_ptr( app_method_t * ptr_method )
{
	uint32_t index = 0;

	// code index
	index += ptr_method->code_index;

	return ( exception_t * )( ( uint8_t * )app_data->methods_ptr + index );
}

app_debug_t * method_get_debug_ptr( app_method_t * ptr_method )
{
	uint32_t index = 0;

	// code index
	index += ptr_method->code_index;

	// skip exception data
	index += (ptr_method->max_exception*8);

	return ( app_debug_t * )( ( uint8_t * )app_data->methods_ptr + index );
}

uint32_t * method_get_argref_ptr( app_method_t * ptr_method )
{
	uint32_t index = 0;

	// code index
	index += ptr_method->code_index;

	// skip exception data
	index += (ptr_method->max_exception*8);
	index += (ptr_method->max_debug*4);

	return ( uint32_t * )( ( uint8_t * )app_data->methods_ptr + index );
}

uint8_t * method_get_address( app_method_t * ptr_method )
{
	uint32_t index = 0;

	// code index
	index += ptr_method->code_index;

	// skip exception data and debug
	index += (ptr_method->max_exception*8);
	index += (ptr_method->max_debug*4);
	index += (ptr_method->max_argrefs*4);

	return ( uint8_t * )app_data->methods_ptr + index;
}

uint8_t * method_get_address_by_index( uint16_t index )
{
	return method_get_address( method_get_data( index ) );
}

uint16_t method_get_line( app_method_t * method, uint8_t * pc )
{
	uint16_t raw_pc;
	uint16_t counter;
	app_debug_t * debug;

	raw_pc = ( uint16_t )( ( ( uint8_t * )pc - ( uint8_t * )method_get_address( method ) ) ) & 0x0FFFF;
	debug = method_get_debug_ptr( method );

	for( counter = 0; counter < method->max_debug - 1; counter++ )
	{
		if( ( raw_pc >= debug[ counter ].pc ) && ( raw_pc < debug[ counter + 1 ].pc ) )
		{
			return debug[ counter ].line;
		}
	}

	return 0;
}
