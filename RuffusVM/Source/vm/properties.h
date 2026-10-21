#ifndef PLATFORM_PROPERTIES_H
#define PLATFORM_PROPERTIES_H

#ifdef	__cplusplus
extern "C" {
#endif

///////////////////////////////////////////////////////////////////////////

#include "types.h"

///////////////////////////////////////////////////////////////////////////

char * property_get( char * input );
char * property_list( bool_t is_first );

void property_set( char * input, char * value );
void property_delete( char * input );

///////////////////////////////////////////////////////////////////////////

#ifdef	__cplusplus
}
#endif

#endif // PLATFORM_PROPERTIES_H


