#ifndef NATIVE_UTIL_VECTOR_LIB_H
#define NATIVE_UTIL_VECTOR_LIB_H

#ifdef	__cplusplus
extern "C" {
#endif

///////////////////////////////////////////////////////////////////////////

#include "datatypes.h"

///////////////////////////////////////////////////////////////////////////

#define VECTOR_DEFAULT_SIZE				10
#define VECTOR_LAST_POSITION			0xFFFFFFFF

///////////////////////////////////////////////////////////////////////////

typedef struct _vector_data_t
{
	uint32_t min_size;
	uint32_t curr_size;
	uint32_t increment;
	uint32_t count;
	uint32_t mode;

} vector_t;

///////////////////////////////////////////////////////////////////////////
	
uint32_t native_vector_get_type( object_t object );

void native_vector_init_base( object_t object, uint32_t size, uint32_t incr );
void native_vector_add_base( object_t object, uint32_t index, object_t element );
void native_vector_add_collection_base( object_t object, uint32_t index, object_t collection );

vector_t * native_vector_get_data( object_t object );

void * native_vector_get_array_ptr( object_t object );

bool_t native_vector_array_contains( object_t object, object_t element );

///////////////////////////////////////////////////////////////////////////

#ifdef	__cplusplus
}
#endif

#endif // NATIVE_UTIL_VECTOR_LIB_H

