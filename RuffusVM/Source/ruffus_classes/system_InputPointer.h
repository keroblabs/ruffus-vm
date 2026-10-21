#ifndef NATIVE_RUFFUS_SYSTEM_INPUTPOINTER_H
#define NATIVE_RUFFUS_SYSTEM_INPUTPOINTER_H

///////////////////////////////////////////////////////////////////////////

#include "datatypes.h"

///////////////////////////////////////////////////////////////////////////

enum
{
    NATIVE_SYSTEM_INPUTPOINTER_INIT,
    NATIVE_SYSTEM_INPUTPOINTER_INITTTS,
	NATIVE_SYSTEM_INPUTPOINTER_READTTS,
};

enum
{
    NATIVE_FIELD_SYSTEM_INPUTPOINTER_POSX,
    NATIVE_FIELD_SYSTEM_INPUTPOINTER_POSY,
    NATIVE_FIELD_SYSTEM_INPUTPOINTER_STATE,
    NATIVE_FIELD_SYSTEM_INPUTPOINTER_EVENT,
    NATIVE_SYSTEM_INPUTPOINTER_TOTAL_FIELDS
};

///////////////////////////////////////////////////////////////////////////

object_t native_system_inputpointer_new( void );

void native_system_inputpointer_get_field(uint16_t mref);
void native_system_inputpointer_invoke(uint16_t mref);

///////////////////////////////////////////////////////////////////////////

#endif // NATIVE_RUFFUS_SYSTEM_INPUTPOINTER_H


