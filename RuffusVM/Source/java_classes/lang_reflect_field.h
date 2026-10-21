#ifndef NATIVE_LANG_REFLECT_FIELD_H
#define NATIVE_LANG_REFLECT_FIELD_H

///////////////////////////////////////////////////////////////////////////

#include "datatypes.h"

///////////////////////////////////////////////////////////////////////////

// Class field implementation: LANG_REFLECT_FIELD_ENUM
enum
{
    NATIVE_FIELD_LANG_REFLECT_FIELD_CREF,
    NATIVE_FIELD_LANG_REFLECT_FIELD_INDEX,
    NATIVE_FIELD_LANG_REFLECT_FIELD_OBJECT,
    NATIVE_FIELD_LANG_REFLECT_FIELD_INSTANCE,
    NATIVE_LANG_REFLECT_FIELD_TOTAL_FIELDS
};

enum
{

    NATIVE_LANG_REFLECT_FIELD_INIT,                                                      // Object()

    NATIVE_LANG_REFLECT_FIELD_GETNAME,                                                   // protected  Object clone()
    NATIVE_LANG_REFLECT_FIELD_GETDECLARINGCLASS,                                         // Class<?> getDeclaringClass()
};

///////////////////////////////////////////////////////////////////////////

object_t native_lang_reflect_field_new( void );
void native_lang_reflect_field_get_field(uint16_t mref);
void native_lang_reflect_field_invoke(uint16_t mref);

///////////////////////////////////////////////////////////////////////////

#endif // NATIVE_LANG_REFLECT_FIELD_H


