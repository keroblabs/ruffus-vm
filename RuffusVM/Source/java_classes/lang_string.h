#ifndef NATIVE_LANG_STRING_H
#define NATIVE_LANG_STRING_H

#ifdef	__cplusplus
extern "C" {
#endif

///////////////////////////////////////////////////////////////////////////

#include "datatypes.h"

///////////////////////////////////////////////////////////////////////////

// Class field implementation: LANG_STRING_ENUM
enum
{
    NATIVE_FIELD_LANG_STRING_DUMMY,
    NATIVE_LANG_STRING_TOTAL_FIELDS
};

enum
{
    NATIVE_LANG_STRING_INIT,                                                     // String()
    NATIVE_LANG_STRING_INIT_ARRAY_BYTE,                                          // String(byte[] bytes)
    NATIVE_LANG_STRING_INIT_ARRAY_BYTE_CHARSET,                                  // String(byte[] bytes, Charset charset)
    NATIVE_LANG_STRING_INIT_ARRAY_BYTE_INT,                                      // String(byte[] ascii, int hibyte)
    NATIVE_LANG_STRING_INIT_ARRAY_BYTE_INT_INT,                                  // String(byte[] bytes, int offset, int length)
    NATIVE_LANG_STRING_INIT_ARRAY_BYTE_INT_INT_CHARSET,                          // String(byte[] bytes, int offset, int length, Charset charset)
    NATIVE_LANG_STRING_INIT_ARRAY_BYTE_INT_INT_INT,                              // String(byte[] ascii, int hibyte, int offset, int count)
    NATIVE_LANG_STRING_INIT_ARRAY_BYTE_INT_INT_STRING,                           // String(byte[] bytes, int offset, int length, String charsetName)
    NATIVE_LANG_STRING_INIT_ARRAY_BYTE_STRING,                                   // String(byte[] bytes, String charsetName)
    NATIVE_LANG_STRING_INIT_ARRAY_CHAR,                                          // String(char[] value)
    NATIVE_LANG_STRING_INIT_ARRAY_CHAR_INT_INT,                                  // String(char[] value, int offset, int count)
    NATIVE_LANG_STRING_INIT_ARRAY_INT_INT_INT,                                   // String(int[] codePoints, int offset, int count)
    NATIVE_LANG_STRING_INIT_STRING,                                              // String(String original)
    NATIVE_LANG_STRING_INIT_STRINGBUFFER,                                        // String(StringBuffer buffer)
    NATIVE_LANG_STRING_INIT_STRINGBUILDER,                                       // String(StringBuilder builder)

    NATIVE_LANG_STRING_CHARAT_INT,                                               // char charAt(int index)
    NATIVE_LANG_STRING_CODEPOINTAT_INT,                                          // int codePointAt(int index)
    NATIVE_LANG_STRING_CODEPOINTBEFORE_INT,                                      // int codePointBefore(int index)
    NATIVE_LANG_STRING_CODEPOINTCOUNT_INT_INT,                                   // int codePointCount(int beginIndex, int endIndex)
    NATIVE_LANG_STRING_COMPARETO_STRING,                                         // int compareTo(String anotherString)
    NATIVE_LANG_STRING_COMPARETOIGNORECASE_STRING,                               // int compareToIgnoreCase(String str)
    NATIVE_LANG_STRING_CONCAT_STRING,                                            // String concat(String str)
    NATIVE_LANG_STRING_CONTAINS_CHARSEQUENCE,                                    // boolean contains(CharSequence s)
    NATIVE_LANG_STRING_CONTENTEQUALS_CHARSEQUENCE,                               // boolean contentEquals(CharSequence cs)
    NATIVE_LANG_STRING_CONTENTEQUALS_STRINGBUFFER,                               // boolean contentEquals(StringBuffer sb)
    NATIVE_LANG_STRING_COPYVALUEOF_ARRAY_CHAR,                                   // static String copyValueOf(char[] data)
    NATIVE_LANG_STRING_COPYVALUEOF_ARRAY_CHAR_INT_INT,                           // static String copyValueOf(char[] data, int offset, int count)
    NATIVE_LANG_STRING_ENDSWITH_STRING,                                          // boolean endsWith(String suffix)
    NATIVE_LANG_STRING_EQUALS_OBJECT,                                            // boolean equals(Object anObject)
    NATIVE_LANG_STRING_EQUALSIGNORECASE_STRING,                                  // boolean equalsIgnoreCase(String anotherString)
    NATIVE_LANG_STRING_GETBYTES,                                                 // byte[] getBytes()
    NATIVE_LANG_STRING_GETBYTES_CHARSET,                                         // byte[] getBytes(Charset charset)
    NATIVE_LANG_STRING_GETBYTES_INT_INT_ARRAY_BYTE_INT,                          // void getBytes(int srcBegin, int srcEnd, byte[] dst, int dstBegin)
    NATIVE_LANG_STRING_GETBYTES_STRING,                                          // byte[] getBytes(String charsetName)
    NATIVE_LANG_STRING_GETCHARS_INT_INT_ARRAY_CHAR_INT,                          // void getChars(int srcBegin, int srcEnd, char[] dst, int dstBegin)
    NATIVE_LANG_STRING_HASHCODE,                                                 // int hashCode()
    NATIVE_LANG_STRING_INDEXOF_INT,                                              // int indexOf(int ch)
    NATIVE_LANG_STRING_INDEXOF_INT_INT,                                          // int indexOf(int ch, int fromIndex)
    NATIVE_LANG_STRING_INDEXOF_STRING,                                           // int indexOf(String str)
    NATIVE_LANG_STRING_INDEXOF_STRING_INT,                                       // int indexOf(String str, int fromIndex)
    NATIVE_LANG_STRING_INTERN,                                                   // String intern()
    NATIVE_LANG_STRING_ISEMPTY,                                                  // boolean isEmpty()
    NATIVE_LANG_STRING_LASTINDEXOF_INT,                                          // int lastIndexOf(int ch)
    NATIVE_LANG_STRING_LASTINDEXOF_INT_INT,                                      // int lastIndexOf(int ch, int fromIndex)
    NATIVE_LANG_STRING_LASTINDEXOF_STRING,                                       // int lastIndexOf(String str)
    NATIVE_LANG_STRING_LASTINDEXOF_STRING_INT,                                   // int lastIndexOf(String str, int fromIndex)
    NATIVE_LANG_STRING_LENGTH,                                                   // int length()
    NATIVE_LANG_STRING_MATCHES_STRING,                                           // boolean matches(String regex)
    NATIVE_LANG_STRING_OFFSETBYCODEPOINTS_INT_INT,                               // int offsetByCodePoints(int index, int codePointOffset)
    NATIVE_LANG_STRING_REGIONMATCHES_BOOLEAN_INT_STRING_INT_INT,                 // boolean regionMatches(boolean ignoreCase, int toffset, String other, int ooffset, int len)
    NATIVE_LANG_STRING_REGIONMATCHES_INT_STRING_INT_INT,                         // boolean regionMatches(int toffset, String other, int ooffset, int len)
    NATIVE_LANG_STRING_REPLACE_CHAR_CHAR,                                        // String replace(char oldChar, char newChar)
    NATIVE_LANG_STRING_REPLACE_CHARSEQUENCE_CHARSEQUENCE,                        // String replace(CharSequence target, CharSequence replacement)
    NATIVE_LANG_STRING_REPLACEALL_STRING_STRING,                                 // String replaceAll(String regex, String replacement)
    NATIVE_LANG_STRING_REPLACEFIRST_STRING_STRING,                               // String replaceFirst(String regex, String replacement)
    NATIVE_LANG_STRING_SPLIT_STRING,                                             // String[] split(String regex)
    NATIVE_LANG_STRING_SPLIT_STRING_INT,                                         // String[] split(String regex, int limit)
    NATIVE_LANG_STRING_STARTSWITH_STRING,                                        // boolean startsWith(String prefix)
    NATIVE_LANG_STRING_STARTSWITH_STRING_INT,                                    // boolean startsWith(String prefix, int toffset)
    NATIVE_LANG_STRING_SUBSEQUENCE_INT_INT,                                      // CharSequence subSequence(int beginIndex, int endIndex)
    NATIVE_LANG_STRING_SUBSTRING_INT,                                            // String substring(int beginIndex)
    NATIVE_LANG_STRING_SUBSTRING_INT_INT,                                        // String substring(int beginIndex, int endIndex)
    NATIVE_LANG_STRING_TOCHARARRAY,                                              // char[] toCharArray()
    NATIVE_LANG_STRING_TOLOWERCASE,                                              // String toLowerCase()
    NATIVE_LANG_STRING_TOLOWERCASE_LOCALE,                                       // String toLowerCase(Locale locale)
    NATIVE_LANG_STRING_TOSTRING,                                                 // String toString()
    NATIVE_LANG_STRING_TOUPPERCASE,                                              // String toUpperCase()
    NATIVE_LANG_STRING_TOUPPERCASE_LOCALE,                                       // String toUpperCase(Locale locale)
    NATIVE_LANG_STRING_TRIM,                                                     // String trim()
    NATIVE_LANG_STRING_VALUEOF_BOOLEAN,                                          // static String valueOf(boolean b)
    NATIVE_LANG_STRING_VALUEOF_CHAR,                                             // static String valueOf(char c)
    NATIVE_LANG_STRING_VALUEOF_ARRAY_CHAR,                                       // static String valueOf(char[] data)
    NATIVE_LANG_STRING_VALUEOF_ARRAY_CHAR_INT_INT,                               // static String valueOf(char[] data, int offset, int count)
    NATIVE_LANG_STRING_VALUEOF_DOUBLE,                                           // static String valueOf(double d)
    NATIVE_LANG_STRING_VALUEOF_FLOAT,                                            // static String valueOf(float f)
    NATIVE_LANG_STRING_VALUEOF_INT,                                              // static String valueOf(int i)
    NATIVE_LANG_STRING_VALUEOF_LONG,                                             // static String valueOf(long l)
    NATIVE_LANG_STRING_VALUEOF_OBJECT,                                           // static String valueOf(Object obj)
};

///////////////////////////////////////////////////////////////////////////

object_t native_lang_string_new( void );
void native_lang_string_get_field(uint16_t mref);
void native_lang_string_invoke(uint16_t mref);

uint32_t native_lang_string_get_superclass( void );

///////////////////////////////////////////////////////////////////////////

#ifdef	__cplusplus
}
#endif

#endif // NATIVE_LANG_STRING_H


