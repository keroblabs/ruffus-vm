#include "lang_void.h"
#include "heap.h"
#include "application.h"
#include "exceptions.h"
#include "native.h"
#include "objects.h"
#include "stack.h"
#include "value_type.h"
#include "strings.h"

#if 0

///////////////////////////////////////////////////////////////////////////

// Class field implementation: LANG_VOID_ENUM
enum
{
    NATIVE_FIELD_LANG_VOID_DUMMY,
    NATIVE_LANG_VOID_TOTAL_FIELDS
};

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////

object_t native_lang_void_new( void )
{
    return( object_create( GET_CLASS_REF( NATIVE_CLASS_LANG_VOID ), T_CLASS, NATIVE_LANG_VOID_TOTAL_FIELDS ) );
}

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////

void native_lang_void_get_field(uint16_t mref)
{
    switch( mref )
    {
        default: 
            exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
            break;
    }
}

void native_lang_void_invoke(uint16_t mref)
{
    switch( mref )
    {
        default:
            exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
            break;

    }
}

#endif
