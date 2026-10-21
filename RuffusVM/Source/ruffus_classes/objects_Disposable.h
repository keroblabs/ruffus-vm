#ifndef NATIVE_RUFFUS_OBJECTS_DISPOSABLE_H
#define NATIVE_RUFFUS_OBJECTS_DISPOSABLE_H

///////////////////////////////////////////////////////////////////////////

#include "datatypes.h"

///////////////////////////////////////////////////////////////////////////

enum
{
    NATIVE_OBJECTS_DISPOSABLE_SET_DISPOSABLE,
	NATIVE_OBJECTS_DISPOSABLE_IS_DISPOSABLE,
	NATIVE_OBJECTS_DISPOSABLE_IS_DISPOSED,
	NATIVE_OBJECTS_DISPOSABLE_DISPOSE,
	NATIVE_OBJECTS_DISPOSABLE_DISPOSE_ALL,
    NATIVE_OBJECTS_DISPOSABLE_REDIRECT,
};

///////////////////////////////////////////////////////////////////////////

void native_objects_disposable_invoke(uint16_t mref);
void native_method_objects_disposable_init( void );

///////////////////////////////////////////////////////////////////////////

#endif // NATIVE_RUFFUS_OBJECTS_DISPOSABLE_H


