#ifndef NATIVE_LANG_REFLECT_METHOD_H
#define NATIVE_LANG_REFLECT_METHOD_H

///////////////////////////////////////////////////////////////////////////

#include "datatypes.h"

///////////////////////////////////////////////////////////////////////////

// Class field implementation: LANG_REFLECT_FIELD_ENUM
enum
{
    NATIVE_FIELD_LANG_REFLECT_METHOD_CREF,
    NATIVE_FIELD_LANG_REFLECT_METHOD_INDEX,
    NATIVE_FIELD_LANG_REFLECT_METHOD_OBJECT,
    NATIVE_FIELD_LANG_REFLECT_METHOD_INSTANCE,
    NATIVE_LANG_REFLECT_METHOD_TOTAL_FIELDS
};

enum
{

    NATIVE_LANG_REFLECT_METHOD_INIT,                                                      // Object()

    NATIVE_LANG_REFLECT_METHOD_GETNAME,                                                   // protected  Object clone()
    NATIVE_LANG_REFLECT_METHOD_GETDECLARINGCLASS,                                         // Class<?> getDeclaringClass()
};

///////////////////////////////////////////////////////////////////////////

object_t native_lang_reflect_method_new( void );
void native_lang_reflect_method_get_field(uint16_t mref);
void native_lang_reflect_method_invoke(uint16_t mref);

///////////////////////////////////////////////////////////////////////////

#endif // NATIVE_LANG_REFLECT_METHOD_H


