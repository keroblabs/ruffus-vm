#include "system_InputPointer.h"
#include "obj_handler.h"
#include "application.h"
#include "methods.h"
#include "threads.h"
#include "exceptions.h"
#include "native.h"

#ifdef TIMA_OS
#include "system.h"
#endif

#if defined WANT_GRAPHICS
#include "graphics.h"
#endif

///////////////////////////////////////////////////////////////////////////

object_t native_system_inputpointer_new( void )
{
	return( object_create( GET_CLASS_REF( NATIVE_CLASS_RUFFUS_SYSTEM_INPUTPOINTER ), T_CLASS, NATIVE_SYSTEM_INPUTPOINTER_TOTAL_FIELDS ) );
}

void native_system_inputpointer_init( void )
{
    object_t object;
    object_t * fields;
    
    // object = native_system_inputpointer_new();
    object = stack_peek(0);
    
    fields = object_get_fields_ptr( object );
    
    fields[ NATIVE_FIELD_SYSTEM_INPUTPOINTER_POSX ] = value_create_int( 0 );
    fields[ NATIVE_FIELD_SYSTEM_INPUTPOINTER_POSY ] = value_create_int( 0 );
    fields[ NATIVE_FIELD_SYSTEM_INPUTPOINTER_STATE ] = value_create_int( 0 );
    fields[ NATIVE_FIELD_SYSTEM_INPUTPOINTER_EVENT ] = value_create_int( 0 );
    
    // stack_push( object );
    stack_remove(1);
}

void native_system_inputpointer_read_tts( void )
{
    object_t object;

    #if defined WANT_GRAPHICS
    object_t * fields;
    
    uint8_t _event;
    uint8_t state = 0;
    uint16_t posx = 0;
    uint16_t posy = 0;
    
    object = stack_peek(0);
    
    _event = TTS_read( &state, &posx, &posy );
    
    if( _event == TRUE )
    {
        fields = object_get_fields_ptr( object );

        value_set_int( fields[ NATIVE_FIELD_SYSTEM_INPUTPOINTER_POSX ], posx );
        value_set_int( fields[ NATIVE_FIELD_SYSTEM_INPUTPOINTER_POSY ], posy );
        value_set_int( fields[ NATIVE_FIELD_SYSTEM_INPUTPOINTER_STATE ], state );
        value_set_int( fields[ NATIVE_FIELD_SYSTEM_INPUTPOINTER_EVENT ], _event );
    }
    
    stack_remove(1);
    stack_push_boolean( _event );
    #else
    object = stack_pop();
    stack_push_boolean( FALSE );
    #endif
}

void native_system_inputpointer_get_field(uint16_t mref)
{
    switch( mref )
    {
		default:
            exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
            break;            
    }
}

void native_system_inputpointer_invoke(uint16_t mref)
{
    switch( mref )
    {
        case NATIVE_SYSTEM_INPUTPOINTER_INIT:
        case NATIVE_SYSTEM_INPUTPOINTER_INITTTS:
            native_system_inputpointer_init();
            break;

        case NATIVE_SYSTEM_INPUTPOINTER_READTTS:
            native_system_inputpointer_read_tts();
            break;

		default:
            exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
            break;            
    }
}

