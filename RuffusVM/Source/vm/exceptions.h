#ifndef _EXCEPTIONS_H_
#define _EXCEPTIONS_H_

///////////////////////////////////////////////////////////////////////////

#include "datatypes.h"

/////////////////////////////////////////////////////////////////////////////

#define THREW_EXCEPTION			1
#define UNHANDLED_EXCEPTION		2
#define EXCEPTION_EXIT			3
#define EXCEPTION_DISPOSED      4

/////////////////////////////////////////////////////////////////////////////

enum
{ 
	NATIVE_THROW_EXCEPTION_INIT			,	// InterruptedException()
	NATIVE_THROW_EXCEPTION_INIT_DETAIL	,	// InterruptedException( String s )
	NATIVE_THROW_EXCEPTION_TOSTRING		 	// String toString() 
};

/////////////////////////////////////////////////////////////////////////////

void exception_throw( object_t object );

void exception_new( uint32_t cref, const char * detail );

void throw_exception_init( void );
void throw_exception_init_detail( void );
void throw_exception_set_string( object_t object, object_t string );
void throw_exception_tostring( void );

void native_throw_exception_invoke(u08_t mref);

object_t throw_exception_new_object( uint32_t cref );
object_t throw_get_string_exception( void );

//////////////////////////////////////////////////////////////////////////

void exception_throw_error_invalid_ref( void );
void exception_throw_error_out_of_bounds( void );
void exception_throw_error_string_out_of_bounds( void );
void exception_throw_error_array_out_of_bounds( void );
void exception_throw_error_arithmetic_division_by_zero( void );
void exception_throw_error_negative_array( void );

//////////////////////////////////////////////////////////////////////////

#endif // _EXCEPTIONS_H_
