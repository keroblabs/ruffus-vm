#include "lang_number_lib.h"
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

static uint32_t rand_seed = 27854263;

///////////////////////////////////////////////////////////////////////////

void lang_number_lib_compare_to( void )
{
    // int compareTo(Byte anotherByte)
    // Compares two Number objects numerically. 
    object_t obj1;
    object_t obj2;

    bool_t ret_value = 0;

    obj2 = stack_pop();
    obj1 = stack_pop();


	ret_value = value_compare( LANG_NUMBER_VALUE_FIELD( obj1 ),
							   LANG_NUMBER_VALUE_FIELD( obj2 ) );

    // return type: int
    stack_push_integer( ret_value );
}

void lang_number_lib_equals( void )
{
    // boolean equals(Object obj)
    // Compares this object to the specified object. 
    object_t obj2;
    object_t obj1;
    bool_t ret_value = 0;

    obj2 = stack_pop();
    obj1 = stack_pop();

	ret_value = value_compare( LANG_NUMBER_VALUE_FIELD( obj1 ),
							   LANG_NUMBER_VALUE_FIELD( obj2 ) );

	if( ret_value == 0 ) ret_value = 1;
	else ret_value = 0;

    // return type: int
    stack_push_boolean( ret_value );
}

void lang_number_lib_hashcode( void )
{
    // int hashCode()
    // Returns a hash code for this Number object. 
    object_t object;
    int32_t ret_value = 0;

    object = stack_pop();

    // put your code here
    ret_value = 1;

    // return type: int
    stack_push_integer( ret_value );
}

void lang_number_lib_object_tostring( uint32_t radix )
{
    // String toString()
    // Returns a String object representing this object's value. 
    object_t object;

    object = stack_pop();

    // return type: String
    stack_push_string( native_value_to_string( LANG_NUMBER_VALUE_FIELD( object ) ) );
}

void lang_number_lib_value_tostring( uint32_t radix )
{
    // Returns a new String object representing the specified byte. 
    object_t object;

    object = stack_pop();

    // return type: String
    stack_push_string( native_value_to_string( object ) );
}

object_t lang_number_lib_cast_value( object_t object )
{
	uint8_t mode = 0;
	uint32_t cref;

	if( object == 0 )
	{
		exception_new( NATIVE_CLASS_THROW_LANG_ILLEGALARGUMENTEXCEPTION, msg_throw_invalid_ref );
		return FALSE;
	}

	// get everything to determine the object
	heap_object_locate( object, NULL, &mode );

	if( mode == T_CLASS )
	{
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
			case NATIVE_CLASS_LANG_DOUBLE:              // java/lang/Double
				return LANG_NUMBER_VALUE_FIELD( object );

			default:
				break;
		}
	}

	return 0;
}

uint32_t lang_number_generate_random( int64_t * seed )
{
    uint32_t * seed_32 = ( uint32_t * )seed;
    
    if( ( seed_32[0] == 0 ) || ( seed_32[1] == 0 ) )
    {
        lang_rand_get_seed( seed );
        
        if( seed_32[0] == 0 ) seed_32[0]++;
        if( seed_32[1] == 0 ) seed_32[1]++;
    }
    
    seed_32[0] = 36969 * (seed_32[0] & 65535) + (seed_32[0] >> 16);
    seed_32[1] = 18000 * (seed_32[1] & 65535) + (seed_32[1] >> 16);
    
    return( ( seed_32[0] << 16 ) + ( seed_32[1] & 0x0FFFF ) );
}

void lang_rand_generate( void )
{
    rand_seed = (rand_seed * 32719 + 3) % 32768;
}

void lang_rand_get_seed( int64_t * seed )
{
    int cnt;
    uint8_t * seed_8 = ( uint8_t * )seed;

    for( cnt = 0; cnt < 8; cnt++ )
    {
        lang_rand_generate();
        seed_8[cnt] = rand_seed % 0xff;

        if( seed_8[cnt] == 0 ) seed_8[cnt]++;
    }
}

uint32_t lang_rand_get_next( int64_t * seed )
{
    uint32_t * seed_32 = ( uint32_t * )seed;

    if( ( seed_32[0] == 0 ) || ( seed_32[1] == 0 ) )
    {
        lang_rand_get_seed( seed );

        if( seed_32[0] == 0 ) seed_32[0]++;
        if( seed_32[1] == 0 ) seed_32[1]++;
    }

    seed_32[0] = 36969 * (seed_32[0] & 65535) + (seed_32[0] >> 16);
    seed_32[1] = 18000 * (seed_32[1] & 65535) + (seed_32[1] >> 16);

    return( ( seed_32[0] << 16 ) + ( seed_32[1] & 0x0FFFF ) );
}
