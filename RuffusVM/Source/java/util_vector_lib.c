#include "util_vector_lib.h"
#include "util_vector.h"
#include "threads.h"
#include "objects.h"
#include "native.h"
#include "value_type.h"
#include "arrays_type.h"
#include "vm.h"
#include "stack.h"
#include "heap.h"
#include "application.h"
#include "exceptions.h"

/////////////////////////////////////////////////////////////////////////////

#define VECTOR_DEFAULT_SIZE				10
#define VECTOR_LAST_POSITION			0xFFFFFFFF

/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////

uint32_t native_vector_get_type( object_t object )
{
	vector_t * data;

	data = ( vector_t * )object_get_extension( object );

	return data->mode;
}

void native_vector_init_base( object_t object, uint32_t size, uint32_t incr )
{
	object_t * fields;
	vector_t * data;

	// Constructs an empty vector so that its internal data array 
	// has size 10 and its standard capacity increment is zero.

	// get class instance
	fields = object_get_fields_ptr( object );
	object_create_extension( object, sizeof( vector_t ) );
	data = ( vector_t * )object_get_extension( object );

	// create array used by the vector
	fields[ NATIVE_FIELD_UTIL_VECTOR_ARRAY ] = 0;
	fields[ NATIVE_FIELD_UTIL_VECTOR_DATA ] = 0;

	// initialize parameters
	data->curr_size = size;
	data->min_size = size;
	data->increment = incr + 1;
	data->count = 0;
	data->mode = 0;
}

void native_vector_add_base( object_t object, uint32_t index, object_t element )
{
	object_t * fields;
	vector_t * data;
	uint32_t mode = 0;
	uint32_t size = 0;
	uint8_t mode8 = 0;
	uint8_t buffer[8];

	// get class instance
	fields = object_get_fields_ptr( object );
	data = ( vector_t * )object_get_extension( object );
	if( index == NEG_U32 ) index = data->count;

	// get element information
	heap_object_locate( element, &size, &mode8 );
	mode = mode8;

	// create array if necessary
	if( fields[ NATIVE_FIELD_UTIL_VECTOR_ARRAY ] == 0 )
	{
		if( ( mode == T_CLASS ) || ( mode >= T_ARRAY ) ) fields[ NATIVE_FIELD_UTIL_VECTOR_ARRAY ] = array_create( data->min_size, T_CLASS );
		else fields[ NATIVE_FIELD_UTIL_VECTOR_ARRAY ] = array_create( data->min_size, mode );
		
		if( mode == T_CLASS ) data->mode = GET_CLASS_INDEX( object_get_class_ref( object ) );
		else data->mode = mode;
	}
	else
	{
		// check element type
		if( mode == T_CLASS ) mode = GET_CLASS_INDEX( object_get_class_ref( object ) );

		if( data->mode != mode )
		{
			exception_new( NATIVE_CLASS_THROW_LANG_ARRAYSTOREEXCEPTION, msg_throw_invalid_array_store );
			return;
		}
	}

	// resize?
	if( ++data->count >= data->curr_size )
	{
		data->curr_size += data->increment;
		array_insert( fields[ NATIVE_FIELD_UTIL_VECTOR_ARRAY ], index, NULL, 0, 1 );
	}

	if( ( mode == T_CLASS ) || ( mode >= T_ARRAY ) )
	{
		// it's an array of objects
		array_copy( fields[ NATIVE_FIELD_UTIL_VECTOR_ARRAY ], index, &element, 1 );
	}
	else
	{
		// it's an array of value
		memset( buffer, 0x00, sizeof( buffer ) );

		if( mode == T_DOUBLE ) *( ( double * )&buffer[0] ) = value_get_double( element );
		else if( mode == T_FLOAT ) *( ( float * )&buffer[0] ) = value_get_float( element );
		else if( mode == T_LONG ) *( ( int64_t * )&buffer[0] ) = value_get_long( element );
		else *( ( uint8_t * )&buffer[0] ) = value_get_decimal( element );

		array_copy( fields[ NATIVE_FIELD_UTIL_VECTOR_ARRAY ], index, &buffer[0], 1 );
	}
}

void * native_vector_get_array_ptr( object_t object )
{
	object_t * fields;

	fields = object_get_fields_ptr( object );
	return object_get_ptr( fields[NATIVE_FIELD_UTIL_VECTOR_ARRAY] );
}

void native_vector_add_collection_base( object_t object, uint32_t index, object_t collection )
{
	object_t * fields;
	vector_t * data;
	uint8_t mode = 0;
	uint32_t size = 0;
	void * ptr_data;
	uint32_t collection_len;
	uint32_t new_size;

	// get class instance
	fields = object_get_fields_ptr( object );
	data = ( vector_t * )object_get_extension( object );
	if( index == NEG_U32 ) index = data->count;

	// get element information
	heap_object_locate( collection, &size, &mode );

	// check elements from collection
	if( mode == T_ARRAY )
	{
		mode = array_get_type( collection );
		ptr_data = object_get_ptr( collection );
		collection_len = array_get_capacity( collection );
	}
	else if( ( mode == T_CLASS ) && ( GET_CLASS_INDEX( object_get_class_ref( collection ) ) == NATIVE_CLASS_UTIL_VECTOR ) )
	{
		mode = ( ( vector_t * )object_get_extension( collection ) )->mode;
		ptr_data = object_get_ptr( ( ( object_t * )object_get_fields_ptr( collection ) )[ NATIVE_FIELD_UTIL_VECTOR_ARRAY ] );
		collection_len = ( ( vector_t * )object_get_extension( collection ) )->count;
	}
	else
	{
		exception_new( NATIVE_CLASS_THROW_LANG_ARRAYSTOREEXCEPTION, msg_throw_invalid_array_store );
		return;
	}

	// create array if necessary
	if( fields[ NATIVE_FIELD_UTIL_VECTOR_ARRAY ] == 0 )
	{
		new_size = ( collection_len / data->min_size ) + 1;
		new_size *= data->min_size;
		fields[ NATIVE_FIELD_UTIL_VECTOR_ARRAY ] = array_create( new_size, mode );
		data->mode = mode;
	}
	else
	{
		if( data->mode != mode )
		{
			exception_new( NATIVE_CLASS_THROW_LANG_ARRAYSTOREEXCEPTION, msg_throw_invalid_array_store );
			return;
		}
	}

	array_copy( fields[ NATIVE_FIELD_UTIL_VECTOR_ARRAY ], index, ptr_data, collection_len );
}

vector_t * native_vector_get_data( object_t object )
{
	return ( vector_t * )object_get_extension( object );
}

bool_t native_vector_array_contains( object_t object, object_t element )
{
	uint32_t size = 0;
	uint8_t * _array;
	uint8_t mode = 0;
	uint32_t counter;
	uint32_t cref;

	uint8_t mode_element;
	uint8_t * ptr_element;

	if( element == 0 )
	{
		exception_new( NATIVE_CLASS_THROW_LANG_ILLEGALARGUMENTEXCEPTION, msg_throw_invalid_ref );
		return FALSE;
	}

	// get everything to determine new size
	_array = ( uint8_t * )heap_object_locate( object, &size, &mode );

	if( mode < T_ARRAY )
	{
		exception_new( NATIVE_CLASS_THROW_LANG_ILLEGALARGUMENTEXCEPTION, msg_throw_invalid_ref );
		return FALSE;
	}

	if( size == 0 )
	{
		return FALSE;
	}

	mode -= T_ARRAY;

	// get element data
	ptr_element = ( uint8_t * )heap_object_locate( element, NULL, &mode_element );

	if( mode_element != mode )
	{
		exception_new( NATIVE_CLASS_THROW_LANG_ILLEGALARGUMENTEXCEPTION, msg_throw_invalid_ref );
		return FALSE;
	}

	if( mode_element == T_CLASS )
	{
		// it's a vector of classes
		cref = object_get_class_ref( element );

		// check if we are comparing same class
		if( cref != object_get_class_ref( *( ( object_t * )_array ) ) )
		{
			exception_new( NATIVE_CLASS_THROW_LANG_ILLEGALARGUMENTEXCEPTION, msg_throw_invalid_ref );
			return FALSE;
		}

		for( counter = 0; counter < size; counter += array_get_element_size(mode) )
		{
			if( *( ( object_t * )&_array[ counter ] ) == 0 ) continue;

			switch( GET_CLASS_INDEX( cref ) )
			{
				case NATIVE_CLASS_LANG_BOOLEAN:             // java/lang/Boolean
				case NATIVE_CLASS_LANG_BYTE:                // java/lang/Byte
				case NATIVE_CLASS_LANG_CHARACTER:           // java/lang/Character
				case NATIVE_CLASS_LANG_SHORT:               // java/lang/Short
				case NATIVE_CLASS_LANG_INTEGER:             // java/lang/Integer
				case NATIVE_CLASS_LANG_LONG:                // java/lang/Long
				case NATIVE_CLASS_LANG_FLOAT:               // java/lang/Float
				case NATIVE_CLASS_LANG_DOUBLE:              // java/lang/Double
					if( value_compare( LANG_NUMBER_VALUE_FIELD( element ), LANG_NUMBER_VALUE_FIELD( *( ( object_t * )&_array[ counter ] ) ) ) == 0 ) return TRUE;	   
					break;

				default:
					if( element == _array[ counter ] ) return TRUE;
					break;
			}
		}
	}
	else
	{
		// search element
		for( counter = 0; counter < size; counter += array_get_element_size(mode) )
		{
			if( memcmp( ptr_element, &_array[ counter ], array_get_element_size(mode) ) == 0 )
			{
				return TRUE;
			}
		}
	}

	return FALSE;
}
