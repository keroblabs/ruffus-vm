#include "lang_string_lib.h"
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

static char _to_string_temp[ 16 ];

///////////////////////////////////////////////////////////////////////////

object_t native_string_to_array( object_t object, uint8_t mode )
{
	object_t output;
	uint32_t length;

	if( ( mode != T_BYTE ) && ( mode != T_CHAR ) ) return 0;

	// get string length
	length = strings_get_capacity( object );

	// create byte array
	output = object_data_create( mode + T_ARRAY, length );

	// copy array
	memcpy( object_get_ptr( output ), object_get_ptr( object ), length );

	return output;
}

object_t native_string_char_at( object_t object, uint32_t pos )
{
	uint8_t mode = 0;
	uint32_t size = 0;
	char * text;

	// get string
	text = ( char * )heap_object_locate( object, &size, &mode );
	if( mode != T_STRING )
	{
		exception_new( NATIVE_CLASS_THROW_LANG_ILLEGALARGUMENTEXCEPTION, msg_throw_invalid_ref );
		return 0;
	}

	// check position
	if( pos >= size )
	{
		exception_new( NATIVE_CLASS_THROW_LANG_STRINGINDEXOUTOFBOUNDSEXCEPTION, msg_throw_out_of_bounds );
		return 0;
	}

	return value_create_character( text[ pos ] );
}

void native_string_set_char_at( object_t object, uint32_t pos, char ch )
{
	uint8_t mode = 0;
	uint32_t size = 0;
	char * text;

	// get string
	text = ( char * )heap_object_locate( object, &size, &mode );
	if( mode != T_STRING )
	{
		exception_new( NATIVE_CLASS_THROW_LANG_ILLEGALARGUMENTEXCEPTION, msg_throw_invalid_ref );
		return;
	}

	// check position
	if( pos >= size )
	{
		exception_new( NATIVE_CLASS_THROW_LANG_STRINGINDEXOUTOFBOUNDSEXCEPTION, msg_throw_out_of_bounds );
		return;
	}

	text[ pos ] = ch;
}

int native_lang_string_compare( bool_t no_case )
{
	object_t string_1;
	object_t string_obj;

	char * str_1;
	char * str_obj;

	string_1 = stack_peek(0);
	string_obj = stack_peek(1);

	str_1 = ( char * )object_get_ptr( string_1 );
	str_obj = ( char * )object_get_ptr( string_obj );

	if( no_case == TRUE )
	{
		exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
		return 0;
	}

	return strcmp( str_obj, str_1 );
}

object_t native_string_modify( object_t object, uint8_t modifier )
{
	object_t ret_object;

	ret_object = strings_duplicate( object );
	
	switch( modifier )
	{
		case STRING_TOLOWER:
			strings_tolower( ret_object );
			break;

		case STRING_TOUPPER:
			strings_toupper( ret_object );
			break;
	}

	return ret_object;
}

char * native_value_to_string( object_t object )
{
	void * obj_ptr;
	//char * str_out;
	uint32_t size = 0;
	uint8_t mode = 0;
	uint32_t cref;

	// get object
	if( object >= CONST_OBJECT_ID )
	{
		obj_ptr = object_get_constant(object - CONST_OBJECT_ID, &size, &mode );
	}
	else
	{
		obj_ptr = heap_object_locate( object, &size, &mode );
	}

	// decode object
	switch( mode )
	{
		case T_CHAR:
			_to_string_temp[0] = ( *( ( int32_t * )obj_ptr ) ) & 0x0FF;
			_to_string_temp[1] = 0;
			break;

		case T_BOOLEAN:
			if( *( ( int32_t * )obj_ptr ) != 0 ) strcpy( _to_string_temp, "true" );
			else strcpy( _to_string_temp, "false" );
			break;

		case T_BYTE:
		case T_SHORT:
		case T_INT:
			strings_itoa( _to_string_temp, *( ( int32_t * )obj_ptr ), RADIX_DECIMAL );
			break;

		case T_LONG:
			strings_ltoa( _to_string_temp, *( ( int64_t * )obj_ptr ), RADIX_DECIMAL );
			break;

		case T_FLOAT:
			strings_ftoa( _to_string_temp, *( ( float * )obj_ptr ) );
			break;

		case T_DOUBLE:
			strings_ftoa( _to_string_temp, ( float )( *( ( double * )obj_ptr ) ) );
			break;

		case (T_ARRAY + T_CHAR):
			return strings_get_text_ptr( object );

		default:
			//size = object_get_class_ref( object );
			//exception_new( NATIVE_CLASS_THROW_LANG_ILLEGALARGUMENTEXCEPTION, msg_throw_invalid_ref );
			cref = object_get_class_ref( object );

			switch( GET_CLASS_INDEX( cref ) )
			{
				case NATIVE_CLASS_LANG_BOOLEAN:             // java/lang/Boolean
				case NATIVE_CLASS_LANG_BYTE:                // java/lang/Byte
				case NATIVE_CLASS_LANG_CHARACTER:           // java/lang/Character
				case NATIVE_CLASS_LANG_SHORT:               // java/lang/Short
				case NATIVE_CLASS_LANG_INTEGER:             // java/lang/Integer
				case NATIVE_CLASS_LANG_LONG:                // java/lang/Long
				case NATIVE_CLASS_LANG_FLOAT:               // java/lang/Float
					break;

				default:
					exception_new( NATIVE_CLASS_THROW_LANG_ILLEGALARGUMENTEXCEPTION, msg_throw_invalid_ref );
					return NULL;
			}

			return native_value_to_string( LANG_NUMBER_VALUE_FIELD( object ) );
			break;
	}

	return _to_string_temp;
}
