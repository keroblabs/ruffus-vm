#ifndef NATIVE_RUFFUS_SYSTEM_EVENTARGS_H
#define NATIVE_RUFFUS_SYSTEM_EVENTARGS_H

///////////////////////////////////////////////////////////////////////////

#include "datatypes.h"

///////////////////////////////////////////////////////////////////////////

enum
{
    NATIVE_SYSTEM_EVENTARGS_INIT,
};

enum
{
    NATIVE_FIELD_SYSTEM_EVENTARGS_EMPTY,
    NATIVE_SYSTEM_EVENTARGS_TOTAL_FIELDS
};

///////////////////////////////////////////////////////////////////////////

object_t native_system_eventargs_new( void );

void native_system_eventargs_get_field(uint16_t mref);
void native_system_eventargs_invoke(uint16_t mref);

///////////////////////////////////////////////////////////////////////////

#endif // NATIVE_RUFFUS_SYSTEM_EVENTARGS_H


