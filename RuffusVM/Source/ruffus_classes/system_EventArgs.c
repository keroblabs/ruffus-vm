#include "system_EventArgs.h"
#include "obj_handler.h"
#include "application.h"
#include "methods.h"
#include "threads.h"
#include "exceptions.h"
#include "native.h"

///////////////////////////////////////////////////////////////////////////

object_t native_system_eventargs_new( void )
{
	return object_create( GET_CLASS_REF( NATIVE_CLASS_RUFFUS_SYSTEM_EVENTARGS ), T_CLASS, NATIVE_SYSTEM_EVENTARGS_TOTAL_FIELDS );
}

void native_system_eventargs_get_field(uint16_t mref)
{
	object_t object;
	
	if( mref == NATIVE_FIELD_SYSTEM_EVENTARGS_EMPTY )
	{
		object = native_system_eventargs_new();
		stack_push( object );
	}
	else
	{
		exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
	}
}

void native_system_eventargs_invoke(uint16_t mref)
{
	if( mref == NATIVE_SYSTEM_EVENTARGS_INIT )
	{
		stack_pop();
	}
	else
	{
		exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
	}
}

