#ifndef NATIVE_LANG_STRING_LIB_H
#define NATIVE_LANG_STRING_LIB_H

#ifdef	__cplusplus
extern "C" {
#endif

///////////////////////////////////////////////////////////////////////////

#include "datatypes.h"

///////////////////////////////////////////////////////////////////////////

enum
{
	STRING_TOLOWER,
	STRING_TOUPPER,

	STRING_DUPLICATE
};

///////////////////////////////////////////////////////////////////////////

typedef struct _token_data_t
{
    bool_t return_delim;
    char * last_token;
    char * input_data;
    
    char * p_str_data;
    char * p_str_delim;
    
} token_data_t;

///////////////////////////////////////////////////////////////////////////

object_t native_string_to_array( object_t object, uint8_t mode );
object_t native_string_char_at( object_t object, uint32_t pos );
object_t native_string_modify( object_t object, uint8_t modifier );

void native_string_set_char_at( object_t object, uint32_t pos, char ch );

int native_lang_string_compare( bool_t no_case );

char * native_value_to_string( object_t object );

///////////////////////////////////////////////////////////////////////////

#ifdef	__cplusplus
}
#endif

#endif // NATIVE_LANG_STRING_LIB_H

