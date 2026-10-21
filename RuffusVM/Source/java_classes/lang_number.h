#ifndef NATIVE_LANG_NUMBER_H
#define NATIVE_LANG_NUMBER_H

#ifdef	__cplusplus
extern "C" {
#endif

///////////////////////////////////////////////////////////////////////////

#include "datatypes.h"

///////////////////////////////////////////////////////////////////////////

// Class field implementation: LANG_NUMBER_ENUM
enum
{
    NATIVE_FIELD_LANG_NUMBER_VALUE,
    NATIVE_LANG_NUMBER_TOTAL_FIELDS
};

enum
{
    NATIVE_LANG_NUMBER_INIT,                                                     // Number()

    NATIVE_LANG_NUMBER_BYTEVALUE,                                                // byte byteValue()
    NATIVE_LANG_NUMBER_DOUBLEVALUE,                                              // abstract  double doubleValue()
    NATIVE_LANG_NUMBER_FLOATVALUE,                                               // abstract  float floatValue()
    NATIVE_LANG_NUMBER_INTVALUE,                                                 // abstract  int intValue()
    NATIVE_LANG_NUMBER_LONGVALUE,                                                // abstract  long longValue()
    NATIVE_LANG_NUMBER_SHORTVALUE,                                               // short shortValue()
};

///////////////////////////////////////////////////////////////////////////

object_t native_lang_number_new( void );
void native_lang_number_get_field(uint16_t mref);
void native_lang_number_invoke(uint16_t mref);

uint32_t native_lang_number_get_superclass( void );

///////////////////////////////////////////////////////////////////////////

#ifdef	__cplusplus
}
#endif

#endif // NATIVE_LANG_NUMBER_H


