#include "exceptions.h"
#include "objects.h"
#include "application.h"
#include "heap.h"
#include "native.h"
#include "stack.h"
#include "methods.h"
#include "strings.h"
#include "vm.h"
#include "threads.h"

/////////////////////////////////////////////////////////////////////////////

#define EXCEPTION_UNHANDLED		-1

/////////////////////////////////////////////////////////////////////////////

const char * msg_throw_eof_reached =            "End of file";
const char * msg_throw_no_such_method =			"Unknown method";
const char * msg_throw_invalid_ref =			"Invalid object reference";
const char * msg_throw_out_of_bounds =			"Index out of bounds";
const char * msg_throw_divison_by_zero =		"Division by zero";
const char * msg_throw_unsupported_opcode =		"Unsupported opcode";
const char * msg_throw_class_not_found =		"Class not found";
const char * msg_throw_stack_underflow =		"Stack underflow";
const char * msg_throw_invalid_array_store =    "Array store type mismatch";
const char * msg_throw_illegal_argument =       "Invalid argument";
const char * msg_throw_no_such_element =        "No such element";
const char * msg_throw_null_pointer =           "Null pointer exception";
const char * msg_throw_unsupported_operation =  "Unsupported operation";

/////////////////////////////////////////////////////////////////////////////

enum
{
	THROW_FIELD_STRING,
	THROW_FIELD_DETAIL,
	THROW_FIELD_TEMP_STRING,

	THROW_TOTAL_FIELDS
};

/////////////////////////////////////////////////////////////////////////////

/*
Exception in thread "main" java.lang.ArrayIndexOutOfBoundsException: 49152 >= 139
        at java.util.Vector.elementAt(Unknown Source)
        at ConstPool.getEntryAtIndex(ConstPool.java:94)
        at ConstPool.constantRelocate(ConstPool.java:394)
        at CodeTranslator.translate(CodeTranslator.java:264)
        at UVMWriter.writeMethods(UVMWriter.java:419)
        at UVMWriter.binaryWrite(UVMWriter.java:502)
        at RuffusVMTool.main(RuffusVMTool.java:90)
*/

void throw_exception_init( void )
{
	// get object to call constructor
	object_t object = stack_pop();

	// get fields
	object_t * fields = object_get_fields_ptr( object );

	// setup empty string message and empty detail
	fields[ THROW_FIELD_STRING ] = 0;
	fields[ THROW_FIELD_DETAIL ] = 0;
}

void throw_exception_init_detail( void )
{
	// get object to call constructor
	object_t object = stack_pop();

	// get string with detail
	object_t detail = stack_pop();

	// get fields
	object_t * fields = object_get_fields_ptr( object );

	// setup empty string message and empty detail
	fields[ THROW_FIELD_STRING ] = 0;
	fields[ THROW_FIELD_DETAIL ] = detail;
}

void throw_exception_set_string( object_t object, object_t string )
{
	// get fields
	object_t * fields = object_get_fields_ptr( object );

	// setup string message
	fields[ THROW_FIELD_STRING ] = string;
}

object_t throw_get_string_exception( void )
{
	object_t object = stack_pop();
	object_t string_out = strings_create( "" );
	object_t * fields = object_get_fields_ptr( object );

	fields[ THROW_FIELD_TEMP_STRING ] = string_out;

	// setup string message
	strings_concat( string_out, "*** " );
	strings_concat( string_out, strings_get_text_ptr( fields[ THROW_FIELD_DETAIL ] ) );
	strings_concat( string_out, " at " );
	strings_concat( string_out, strings_get_text_ptr( fields[ THROW_FIELD_STRING ] ) );

	return( string_out );
}

void throw_exception_tostring( void )
{
	// get fields
	object_t object = stack_pop();
	object_t string_out = strings_create( "" );
	object_t * fields = object_get_fields_ptr( object );

	fields[ THROW_FIELD_TEMP_STRING ] = string_out;

	// setup string message
	strings_concat( string_out, "*** " );
	strings_concat( string_out, strings_get_text_ptr( fields[ THROW_FIELD_DETAIL ] ) );
	strings_concat( string_out, " at " );
	strings_concat( string_out, strings_get_text_ptr( fields[ THROW_FIELD_STRING ] ) );

	stack_push( string_out );
}

object_t throw_exception_new_object( uint32_t cref )
{
	return( object_create( GET_CLASS_REF( cref ), T_CLASS, THROW_TOTAL_FIELDS ) );
}

void native_throw_exception_invoke(u08_t mref) 
{
	switch( mref )
	{
		case NATIVE_THROW_EXCEPTION_INIT:				throw_exception_init();			break;
		case NATIVE_THROW_EXCEPTION_INIT_DETAIL:	    throw_exception_init_detail();	break;
		case NATIVE_THROW_EXCEPTION_TOSTRING:			throw_exception_tostring();		break;

		default:	exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );			break;

	}
}

/////////////////////////////////////////////////////////////////////////////

void exception_new( uint32_t cref, const char * detail )
{
	object_t throw_obj;
	object_t * fields;

	object_garbage_collection();

	// create object
	throw_obj = throw_exception_new_object( cref );

	// get fields
	fields = object_get_fields_ptr( throw_obj );

	// setup empty string message and empty detail
	fields[ THROW_FIELD_STRING ] = 0;
	fields[ THROW_FIELD_DETAIL ] = strings_create( ( char * )detail );

	// throw exception
	exception_throw( throw_obj );
}

void exception_throw( object_t object )
{
	uint16_t counter;
	uint16_t total_exception;
	uint16_t curr_pc_index;

	char line_str[6];

	object_t string_obj;
	object_t return_obj;
	return_t * return_data;

	exception_t * exception_ptr;
	app_method_t * curr_method;
	uint8_t * curr_pc;
	object_t * stack_base;
	object_t * locals;

	uint32_t cref;

	cref = object_get_class_ref( object );

	// start searching in the current call
	curr_method = thread_get()->ptr_method;
	curr_pc = thread_get()->pc;
	stack_base = thread_instance()->stack_base;
	locals = thread_instance()->locals;

	// create base string for exception
	string_obj = strings_create( method_get_name( curr_method ) );
	strings_concat( string_obj, ":" );
	strings_itoa( line_str, method_get_line( curr_method, curr_pc ), 10 );
	strings_concat( string_obj, line_str );

	throw_exception_set_string( object, string_obj );

	while( TRUE )
	{
		total_exception = curr_method->max_exception;
		exception_ptr = method_get_exception_ptr( curr_method );
		curr_pc_index = method_get_pc_index( curr_method, curr_pc );

		// check if current method has got exception
		for( counter = 0; counter < curr_method->max_exception; counter++ )
		{
			// now check if it's inside an exception
			if( ( curr_pc_index >= exception_ptr[ counter ].start_pc ) &&
				( curr_pc_index <= exception_ptr[ counter ].end_pc ) )
			{
				// found, throw exception
				if( exception_ptr[ counter ].class_id == GET_CLASS_INDEX( cref ) )
				{
					// go to exception handler code
					thread_get()->pc = &method_get_address( curr_method )[ exception_ptr[ counter ].handle_pc ];
					thread_instance()->sp = stack_base;
					thread_get()->ptr_method = curr_method;
					thread_instance()->locals = locals;

					// push objectref on the stack
					stack_push( object );
					longjmp(app_data->state, THREW_EXCEPTION);
					return;
				}
			}
		}

		// didnt find now, load previous call
		return_obj = *stack_base;

		if( return_obj == 0 )
		{
			// no more calls, unhandled exception
			stack_push( object );
			longjmp(app_data->state, UNHANDLED_EXCEPTION);
			return;
		}

		return_data = ( return_t * )object_get_ptr( return_obj );

		// get data of previous call
		curr_pc = return_data->saved_pc;
		curr_method = return_data->ptr_method;
		stack_base = return_data->stack_base;
		locals = return_data->ptr_locals;

		// add new string for exception
		strings_concat( string_obj, "; " );
		strings_concat( string_obj, method_get_name( curr_method ) );
	}
}

void exception_throw_error_invalid_ref( void )
{
	exception_new( NATIVE_CLASS_THROW_LANG_ILLEGALARGUMENTEXCEPTION, msg_throw_invalid_ref );
}

void exception_throw_error_out_of_bounds( void )
{
	exception_new( NATIVE_CLASS_THROW_LANG_INDEXOUTOFBOUNDSEXCEPTION, msg_throw_out_of_bounds );
}

void exception_throw_error_string_out_of_bounds( void )
{
	exception_new( NATIVE_CLASS_THROW_LANG_STRINGINDEXOUTOFBOUNDSEXCEPTION, msg_throw_out_of_bounds );
}

void exception_throw_error_array_out_of_bounds( void )
{
	exception_new( NATIVE_CLASS_THROW_LANG_ARRAYINDEXOUTOFBOUNDSEXCEPTION, msg_throw_out_of_bounds );
}

void exception_throw_error_arithmetic_division_by_zero( void )
{
	exception_new( NATIVE_CLASS_THROW_LANG_ARITHMETICEXCEPTION, msg_throw_divison_by_zero );
}

void exception_throw_error_negative_array( void )
{
	exception_new( NATIVE_CLASS_THROW_LANG_NEGATIVEARRAYSIZEEXCEPTION, msg_throw_out_of_bounds );
}
