#ifndef NATIVE_LANG_CLASS_H
#define NATIVE_LANG_CLASS_H

///////////////////////////////////////////////////////////////////////////

#include "datatypes.h"

///////////////////////////////////////////////////////////////////////////

// Class field implementation: LANG_CLASS_ENUM
enum
{
    NATIVE_FIELD_LANG_CLASS_CREF,
    NATIVE_FIELD_LANG_CLASS_OBJECT,
    NATIVE_FIELD_LANG_CLASS_INSTANCE,
    NATIVE_LANG_CLASS_TOTAL_FIELDS
};

enum
{

    NATIVE_LANG_CLASS_INIT,                                                      // Object()

    NATIVE_LANG_CLASS_GETNAME,                                                   // protected  Object clone()
    NATIVE_LANG_CLASS_GETSIMPLENAME,                                             // boolean equals(Object obj)
    NATIVE_LANG_CLASS_ISARRAY,                                                   // protected  void finalize()
};

///////////////////////////////////////////////////////////////////////////

object_t native_lang_class_new( void );
void native_lang_class_invoke(uint16_t mref);

///////////////////////////////////////////////////////////////////////////

#endif // NATIVE_LANG_CLASS_H


