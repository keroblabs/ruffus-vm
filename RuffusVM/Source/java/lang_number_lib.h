#ifndef NATIVE_LANG_NUMBER_LIB_H
#define NATIVE_LANG_NUMBER_LIB_H

#ifdef	__cplusplus
extern "C" {
#endif

///////////////////////////////////////////////////////////////////////////

#include "datatypes.h"

///////////////////////////////////////////////////////////////////////////

#define LANG_NUMBER_VALUE_FIELD(a)			object_get_fields_ptr( a )[ NATIVE_FIELD_LANG_NUMBER_VALUE ]

///////////////////////////////////////////////////////////////////////////

void lang_number_lib_compare_to( void );
void lang_number_lib_equals( void );
void lang_number_lib_hashcode( void );
void lang_number_lib_object_tostring( uint32_t radix );
void lang_number_lib_value_tostring( uint32_t radix );

object_t lang_number_lib_cast_value( object_t object );

uint32_t lang_number_generate_random( int64_t * seed );
        
void lang_rand_generate( void );
void lang_rand_get_seed( int64_t * seed );
uint32_t lang_rand_get_next( int64_t * seed );

///////////////////////////////////////////////////////////////////////////

#ifdef	__cplusplus
}
#endif

#endif // NATIVE_LANG_NUMBER_LIB_H


