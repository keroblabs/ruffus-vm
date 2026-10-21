#ifndef NATIVE_LANG_STRINGBUILDER_H
#define NATIVE_LANG_STRINGBUILDER_H

#ifdef	__cplusplus
extern "C" {
#endif

///////////////////////////////////////////////////////////////////////////

#include "datatypes.h"

///////////////////////////////////////////////////////////////////////////

// Class field implementation: LANG_STRINGBUILDER_ENUM
enum
{
    NATIVE_FIELD_LANG_STRINGBUILDER_DUMMY,
    NATIVE_LANG_STRINGBUILDER_TOTAL_FIELDS
};

enum
{

    NATIVE_LANG_STRINGBUILDER_INIT,                                              // StringBuilder()
    NATIVE_LANG_STRINGBUILDER_INIT_CHARSEQUENCE,                                 // StringBuilder(CharSequence seq)
    NATIVE_LANG_STRINGBUILDER_INIT_INT,                                          // StringBuilder(int capacity)
    NATIVE_LANG_STRINGBUILDER_INIT_STRING,                                       // StringBuilder(String str)

    NATIVE_LANG_STRINGBUILDER_APPEND_BOOLEAN,                                    // StringBuilder append(boolean b)
    NATIVE_LANG_STRINGBUILDER_APPEND_CHAR,                                       // StringBuilder append(char c)
    NATIVE_LANG_STRINGBUILDER_APPEND_ARRAY_CHAR,                                 // StringBuilder append(char[] str)
    NATIVE_LANG_STRINGBUILDER_APPEND_ARRAY_CHAR_INT_INT,                         // StringBuilder append(char[] str, int offset, int len)
    NATIVE_LANG_STRINGBUILDER_APPEND_CHARSEQUENCE,                               // StringBuilder append(CharSequence s)
    NATIVE_LANG_STRINGBUILDER_APPEND_CHARSEQUENCE_INT_INT,                       // StringBuilder append(CharSequence s, int start, int end)
    NATIVE_LANG_STRINGBUILDER_APPEND_DOUBLE,                                     // StringBuilder append(double d)
    NATIVE_LANG_STRINGBUILDER_APPEND_FLOAT,                                      // StringBuilder append(float f)
    NATIVE_LANG_STRINGBUILDER_APPEND_INT,                                        // StringBuilder append(int i)
    NATIVE_LANG_STRINGBUILDER_APPEND_LONG,                                       // StringBuilder append(long lng)
    NATIVE_LANG_STRINGBUILDER_APPEND_OBJECT,                                     // StringBuilder append(Object obj)
    NATIVE_LANG_STRINGBUILDER_APPEND_STRING,                                     // StringBuilder append(String str)
    NATIVE_LANG_STRINGBUILDER_APPEND_STRINGBUFFER,                               // StringBuilder append(StringBuffer sb)
    NATIVE_LANG_STRINGBUILDER_APPENDCODEPOINT_INT,                               // StringBuilder appendCodePoint(int codePoint)
    NATIVE_LANG_STRINGBUILDER_CAPACITY,                                          // int capacity()
    NATIVE_LANG_STRINGBUILDER_CHARAT_INT,                                        // char charAt(int index)
    NATIVE_LANG_STRINGBUILDER_CODEPOINTAT_INT,                                   // int codePointAt(int index)
    NATIVE_LANG_STRINGBUILDER_CODEPOINTBEFORE_INT,                               // int codePointBefore(int index)
    NATIVE_LANG_STRINGBUILDER_CODEPOINTCOUNT_INT_INT,                            // int codePointCount(int beginIndex, int endIndex)
    NATIVE_LANG_STRINGBUILDER_DELETE_INT_INT,                                    // StringBuilder delete(int start, int end)
    NATIVE_LANG_STRINGBUILDER_DELETECHARAT_INT,                                  // StringBuilder deleteCharAt(int index)
    NATIVE_LANG_STRINGBUILDER_ENSURECAPACITY_INT,                                // void ensureCapacity(int minimumCapacity)
    NATIVE_LANG_STRINGBUILDER_GETCHARS_INT_INT_ARRAY_CHAR_INT,                   // void getChars(int srcBegin, int srcEnd, char[] dst, int dstBegin)
    NATIVE_LANG_STRINGBUILDER_INDEXOF_STRING,                                    // int indexOf(String str)
    NATIVE_LANG_STRINGBUILDER_INDEXOF_STRING_INT,                                // int indexOf(String str, int fromIndex)
    NATIVE_LANG_STRINGBUILDER_INSERT_INT_BOOLEAN,                                // StringBuilder insert(int offset, boolean b)
    NATIVE_LANG_STRINGBUILDER_INSERT_INT_CHAR,                                   // StringBuilder insert(int offset, char c)
    NATIVE_LANG_STRINGBUILDER_INSERT_INT_ARRAY_CHAR,                             // StringBuilder insert(int offset, char[] str)
    NATIVE_LANG_STRINGBUILDER_INSERT_INT_ARRAY_CHAR_INT_INT,                     // StringBuilder insert(int index, char[] str, int offset, int len)
    NATIVE_LANG_STRINGBUILDER_INSERT_INT_CHARSEQUENCE,                           // StringBuilder insert(int dstOffset, CharSequence s)
    NATIVE_LANG_STRINGBUILDER_INSERT_INT_CHARSEQUENCE_INT_INT,                   // StringBuilder insert(int dstOffset, CharSequence s, int start, int end)
    NATIVE_LANG_STRINGBUILDER_INSERT_INT_DOUBLE,                                 // StringBuilder insert(int offset, double d)
    NATIVE_LANG_STRINGBUILDER_INSERT_INT_FLOAT,                                  // StringBuilder insert(int offset, float f)
    NATIVE_LANG_STRINGBUILDER_INSERT_INT_INT,                                    // StringBuilder insert(int offset, int i)
    NATIVE_LANG_STRINGBUILDER_INSERT_INT_LONG,                                   // StringBuilder insert(int offset, long l)
    NATIVE_LANG_STRINGBUILDER_INSERT_INT_OBJECT,                                 // StringBuilder insert(int offset, Object obj)
    NATIVE_LANG_STRINGBUILDER_INSERT_INT_STRING,                                 // StringBuilder insert(int offset, String str)
    NATIVE_LANG_STRINGBUILDER_LASTINDEXOF_STRING,                                // int lastIndexOf(String str)
    NATIVE_LANG_STRINGBUILDER_LASTINDEXOF_STRING_INT,                            // int lastIndexOf(String str, int fromIndex)
    NATIVE_LANG_STRINGBUILDER_LENGTH,                                            // int length()
    NATIVE_LANG_STRINGBUILDER_OFFSETBYCODEPOINTS_INT_INT,                        // int offsetByCodePoints(int index, int codePointOffset)
    NATIVE_LANG_STRINGBUILDER_REPLACE_INT_INT_STRING,                            // StringBuilder replace(int start, int end, String str)
    NATIVE_LANG_STRINGBUILDER_REVERSE,                                           // StringBuilder reverse()
    NATIVE_LANG_STRINGBUILDER_SETCHARAT_INT_CHAR,                                // void setCharAt(int index, char ch)
    NATIVE_LANG_STRINGBUILDER_SETLENGTH_INT,                                     // void setLength(int newLength)
    NATIVE_LANG_STRINGBUILDER_SUBSEQUENCE_INT_INT,                               // CharSequence subSequence(int start, int end)
    NATIVE_LANG_STRINGBUILDER_SUBSTRING_INT,                                     // String substring(int start)
    NATIVE_LANG_STRINGBUILDER_SUBSTRING_INT_INT,                                 // String substring(int start, int end)
    NATIVE_LANG_STRINGBUILDER_TOSTRING,                                          // String toString()
    NATIVE_LANG_STRINGBUILDER_TRIMTOSIZE,                                        // void trimToSize()
};

///////////////////////////////////////////////////////////////////////////

object_t native_lang_stringbuilder_new( void );
void native_lang_stringbuilder_get_field(uint16_t mref);
void native_lang_stringbuilder_invoke(uint16_t mref);

uint32_t native_lang_stringbuilder_get_superclass( void );

///////////////////////////////////////////////////////////////////////////

#ifdef	__cplusplus
}
#endif

#endif // NATIVE_LANG_STRINGBUILDER_H


