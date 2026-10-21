#ifndef NATIVE_UTIL_STRINGTOKENIZER_H
#define NATIVE_UTIL_STRINGTOKENIZER_H

#ifdef	__cplusplus
extern "C" {
#endif

///////////////////////////////////////////////////////////////////////////

#include "datatypes.h"

///////////////////////////////////////////////////////////////////////////

// Class field implementation: UTIL_STRINGTOKENIZER_ENUM
enum
{
    NATIVE_FIELD_UTIL_STRINGTOKENIZER_STRING,
    NATIVE_FIELD_UTIL_STRINGTOKENIZER_DELIM_STRING,
    NATIVE_UTIL_STRINGTOKENIZER_TOTAL_FIELDS
};

enum
{

    NATIVE_UTIL_STRINGTOKENIZER_INIT_STRING,                                     // StringTokenizer(String str)
    NATIVE_UTIL_STRINGTOKENIZER_INIT_STRING_STRING,                              // StringTokenizer(String str, String delim)
    NATIVE_UTIL_STRINGTOKENIZER_INIT_STRING_STRING_BOOLEAN,                      // StringTokenizer(String str, String delim, boolean returnDelims)

    NATIVE_UTIL_STRINGTOKENIZER_COUNTTOKENS,                                     // int countTokens()
    NATIVE_UTIL_STRINGTOKENIZER_HASMOREELEMENTS,                                 // boolean hasMoreElements()
    NATIVE_UTIL_STRINGTOKENIZER_HASMORETOKENS,                                   // boolean hasMoreTokens()
    NATIVE_UTIL_STRINGTOKENIZER_NEXTELEMENT,                                     // Object nextElement()
    NATIVE_UTIL_STRINGTOKENIZER_NEXTTOKEN,                                       // String nextToken()
    NATIVE_UTIL_STRINGTOKENIZER_NEXTTOKEN_STRING,                                // String nextToken(String delim)
};

///////////////////////////////////////////////////////////////////////////

object_t native_util_stringtokenizer_new( void );
void native_util_stringtokenizer_get_field(uint16_t mref);
void native_util_stringtokenizer_invoke(uint16_t mref);

///////////////////////////////////////////////////////////////////////////

#ifdef	__cplusplus
}
#endif

#endif // NATIVE_UTIL_STRINGTOKENIZER_H


