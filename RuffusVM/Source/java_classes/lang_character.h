#ifndef NATIVE_LANG_CHARACTER_H
#define NATIVE_LANG_CHARACTER_H

#ifdef	__cplusplus
extern "C" {
#endif

///////////////////////////////////////////////////////////////////////////

#include "datatypes.h"

///////////////////////////////////////////////////////////////////////////

// Class field implementation: LANG_CHARACTER_ENUM
enum
{
    NATIVE_FIELD_LANG_CHARACTER_DUMMY,
    NATIVE_LANG_CHARACTER_TOTAL_FIELDS
};

enum
{
    NATIVE_FIELD_LANG_CHARACTER_COMBINING_SPACING_MARK,                          // static byte COMBINING_SPACING_MARK
    NATIVE_FIELD_LANG_CHARACTER_CONNECTOR_PUNCTUATION,                           // static byte CONNECTOR_PUNCTUATION
    NATIVE_FIELD_LANG_CHARACTER_CONTROL,                                         // static byte CONTROL
    NATIVE_FIELD_LANG_CHARACTER_CURRENCY_SYMBOL,                                 // static byte CURRENCY_SYMBOL
    NATIVE_FIELD_LANG_CHARACTER_DASH_PUNCTUATION,                                // static byte DASH_PUNCTUATION
    NATIVE_FIELD_LANG_CHARACTER_DECIMAL_DIGIT_NUMBER,                            // static byte DECIMAL_DIGIT_NUMBER
    NATIVE_FIELD_LANG_CHARACTER_DIRECTIONALITY_ARABIC_NUMBER,                    // static byte DIRECTIONALITY_ARABIC_NUMBER
    NATIVE_FIELD_LANG_CHARACTER_DIRECTIONALITY_BOUNDARY_NEUTRAL,                 // static byte DIRECTIONALITY_BOUNDARY_NEUTRAL
    NATIVE_FIELD_LANG_CHARACTER_DIRECTIONALITY_COMMON_NUMBER_SEPARATOR,          // static byte DIRECTIONALITY_COMMON_NUMBER_SEPARATOR
    NATIVE_FIELD_LANG_CHARACTER_DIRECTIONALITY_EUROPEAN_NUMBER,                  // static byte DIRECTIONALITY_EUROPEAN_NUMBER
    NATIVE_FIELD_LANG_CHARACTER_DIRECTIONALITY_EUROPEAN_NUMBER_SEPARATOR,        // static byte DIRECTIONALITY_EUROPEAN_NUMBER_SEPARATOR
    NATIVE_FIELD_LANG_CHARACTER_DIRECTIONALITY_EUROPEAN_NUMBER_TERMINATOR,       // static byte DIRECTIONALITY_EUROPEAN_NUMBER_TERMINATOR
    NATIVE_FIELD_LANG_CHARACTER_DIRECTIONALITY_LEFT_TO_RIGHT,                    // static byte DIRECTIONALITY_LEFT_TO_RIGHT
    NATIVE_FIELD_LANG_CHARACTER_DIRECTIONALITY_LEFT_TO_RIGHT_EMBEDDING,          // static byte DIRECTIONALITY_LEFT_TO_RIGHT_EMBEDDING
    NATIVE_FIELD_LANG_CHARACTER_DIRECTIONALITY_LEFT_TO_RIGHT_OVERRIDE,           // static byte DIRECTIONALITY_LEFT_TO_RIGHT_OVERRIDE
    NATIVE_FIELD_LANG_CHARACTER_DIRECTIONALITY_NONSPACING_MARK,                  // static byte DIRECTIONALITY_NONSPACING_MARK
    NATIVE_FIELD_LANG_CHARACTER_DIRECTIONALITY_OTHER_NEUTRALS,                   // static byte DIRECTIONALITY_OTHER_NEUTRALS
    NATIVE_FIELD_LANG_CHARACTER_DIRECTIONALITY_PARAGRAPH_SEPARATOR,              // static byte DIRECTIONALITY_PARAGRAPH_SEPARATOR
    NATIVE_FIELD_LANG_CHARACTER_DIRECTIONALITY_POP_DIRECTIONAL_FORMAT,           // static byte DIRECTIONALITY_POP_DIRECTIONAL_FORMAT
    NATIVE_FIELD_LANG_CHARACTER_DIRECTIONALITY_RIGHT_TO_LEFT,                    // static byte DIRECTIONALITY_RIGHT_TO_LEFT
    NATIVE_FIELD_LANG_CHARACTER_DIRECTIONALITY_RIGHT_TO_LEFT_ARABIC,             // static byte DIRECTIONALITY_RIGHT_TO_LEFT_ARABIC
    NATIVE_FIELD_LANG_CHARACTER_DIRECTIONALITY_RIGHT_TO_LEFT_EMBEDDING,          // static byte DIRECTIONALITY_RIGHT_TO_LEFT_EMBEDDING
    NATIVE_FIELD_LANG_CHARACTER_DIRECTIONALITY_RIGHT_TO_LEFT_OVERRIDE,           // static byte DIRECTIONALITY_RIGHT_TO_LEFT_OVERRIDE
    NATIVE_FIELD_LANG_CHARACTER_DIRECTIONALITY_SEGMENT_SEPARATOR,                // static byte DIRECTIONALITY_SEGMENT_SEPARATOR
    NATIVE_FIELD_LANG_CHARACTER_DIRECTIONALITY_UNDEFINED,                        // static byte DIRECTIONALITY_UNDEFINED
    NATIVE_FIELD_LANG_CHARACTER_DIRECTIONALITY_WHITESPACE,                       // static byte DIRECTIONALITY_WHITESPACE
    NATIVE_FIELD_LANG_CHARACTER_ENCLOSING_MARK,                                  // static byte ENCLOSING_MARK
    NATIVE_FIELD_LANG_CHARACTER_END_PUNCTUATION,                                 // static byte END_PUNCTUATION
    NATIVE_FIELD_LANG_CHARACTER_FINAL_QUOTE_PUNCTUATION,                         // static byte FINAL_QUOTE_PUNCTUATION
    NATIVE_FIELD_LANG_CHARACTER_FORMAT,                                          // static byte FORMAT
    NATIVE_FIELD_LANG_CHARACTER_INITIAL_QUOTE_PUNCTUATION,                       // static byte INITIAL_QUOTE_PUNCTUATION
    NATIVE_FIELD_LANG_CHARACTER_LETTER_NUMBER,                                   // static byte LETTER_NUMBER
    NATIVE_FIELD_LANG_CHARACTER_LINE_SEPARATOR,                                  // static byte LINE_SEPARATOR
    NATIVE_FIELD_LANG_CHARACTER_LOWERCASE_LETTER,                                // static byte LOWERCASE_LETTER
    NATIVE_FIELD_LANG_CHARACTER_MATH_SYMBOL,                                     // static byte MATH_SYMBOL
    NATIVE_FIELD_LANG_CHARACTER_MAX_CODE_POINT,                                  // static int MAX_CODE_POINT
    NATIVE_FIELD_LANG_CHARACTER_MAX_HIGH_SURROGATE,                              // static char MAX_HIGH_SURROGATE
    NATIVE_FIELD_LANG_CHARACTER_MAX_LOW_SURROGATE,                               // static char MAX_LOW_SURROGATE
    NATIVE_FIELD_LANG_CHARACTER_MAX_RADIX,                                       // static int MAX_RADIX
    NATIVE_FIELD_LANG_CHARACTER_MAX_SURROGATE,                                   // static char MAX_SURROGATE
    NATIVE_FIELD_LANG_CHARACTER_MAX_VALUE,                                       // static char MAX_VALUE
    NATIVE_FIELD_LANG_CHARACTER_MIN_CODE_POINT,                                  // static int MIN_CODE_POINT
    NATIVE_FIELD_LANG_CHARACTER_MIN_HIGH_SURROGATE,                              // static char MIN_HIGH_SURROGATE
    NATIVE_FIELD_LANG_CHARACTER_MIN_LOW_SURROGATE,                               // static char MIN_LOW_SURROGATE
    NATIVE_FIELD_LANG_CHARACTER_MIN_RADIX,                                       // static int MIN_RADIX
    NATIVE_FIELD_LANG_CHARACTER_MIN_SUPPLEMENTARY_CODE_POINT,                    // static int MIN_SUPPLEMENTARY_CODE_POINT
    NATIVE_FIELD_LANG_CHARACTER_MIN_SURROGATE,                                   // static char MIN_SURROGATE
    NATIVE_FIELD_LANG_CHARACTER_MIN_VALUE,                                       // static char MIN_VALUE
    NATIVE_FIELD_LANG_CHARACTER_MODIFIER_LETTER,                                 // static byte MODIFIER_LETTER
    NATIVE_FIELD_LANG_CHARACTER_MODIFIER_SYMBOL,                                 // static byte MODIFIER_SYMBOL
    NATIVE_FIELD_LANG_CHARACTER_NON_SPACING_MARK,                                // static byte NON_SPACING_MARK
    NATIVE_FIELD_LANG_CHARACTER_OTHER_LETTER,                                    // static byte OTHER_LETTER
    NATIVE_FIELD_LANG_CHARACTER_OTHER_NUMBER,                                    // static byte OTHER_NUMBER
    NATIVE_FIELD_LANG_CHARACTER_OTHER_PUNCTUATION,                               // static byte OTHER_PUNCTUATION
    NATIVE_FIELD_LANG_CHARACTER_OTHER_SYMBOL,                                    // static byte OTHER_SYMBOL
    NATIVE_FIELD_LANG_CHARACTER_PARAGRAPH_SEPARATOR,                             // static byte PARAGRAPH_SEPARATOR
    NATIVE_FIELD_LANG_CHARACTER_PRIVATE_USE,                                     // static byte PRIVATE_USE
    NATIVE_FIELD_LANG_CHARACTER_SIZE,                                            // static int SIZE
    NATIVE_FIELD_LANG_CHARACTER_SPACE_SEPARATOR,                                 // static byte SPACE_SEPARATOR
    NATIVE_FIELD_LANG_CHARACTER_START_PUNCTUATION,                               // static byte START_PUNCTUATION
    NATIVE_FIELD_LANG_CHARACTER_SURROGATE,                                       // static byte SURROGATE
    NATIVE_FIELD_LANG_CHARACTER_TITLECASE_LETTER,                                // static byte TITLECASE_LETTER
    NATIVE_FIELD_LANG_CHARACTER_UNASSIGNED,                                      // static byte UNASSIGNED
    NATIVE_FIELD_LANG_CHARACTER_UPPERCASE_LETTER,                                // static byte UPPERCASE_LETTER
};

enum
{
    NATIVE_LANG_CHARACTER_INIT_CHAR,                                             // Character(char value)

    NATIVE_LANG_CHARACTER_CHARCOUNT_INT,                                         // static int charCount(int codePoint)
    NATIVE_LANG_CHARACTER_CHARVALUE,                                             // char charValue()
    NATIVE_LANG_CHARACTER_CODEPOINTAT_ARRAY_CHAR_INT,                            // static int codePointAt(char[] a, int index)
    NATIVE_LANG_CHARACTER_CODEPOINTAT_ARRAY_CHAR_INT_INT,                        // static int codePointAt(char[] a, int index, int limit)
    NATIVE_LANG_CHARACTER_CODEPOINTAT_CHARSEQUENCE_INT,                          // static int codePointAt(CharSequence seq, int index)
    NATIVE_LANG_CHARACTER_CODEPOINTBEFORE_ARRAY_CHAR_INT,                        // static int codePointBefore(char[] a, int index)
    NATIVE_LANG_CHARACTER_CODEPOINTBEFORE_ARRAY_CHAR_INT_INT,                    // static int codePointBefore(char[] a, int index, int start)
    NATIVE_LANG_CHARACTER_CODEPOINTBEFORE_CHARSEQUENCE_INT,                      // static int codePointBefore(CharSequence seq, int index)
    NATIVE_LANG_CHARACTER_CODEPOINTCOUNT_ARRAY_CHAR_INT_INT,                     // static int codePointCount(char[] a, int offset, int count)
    NATIVE_LANG_CHARACTER_CODEPOINTCOUNT_CHARSEQUENCE_INT_INT,                   // static int codePointCount(CharSequence seq, int beginIndex, int endIndex)
    NATIVE_LANG_CHARACTER_COMPARETO_CHARACTER,                                   // int compareTo(Character anotherCharacter)
    NATIVE_LANG_CHARACTER_DIGIT_CHAR_INT,                                        // static int digit(char ch, int radix)
    NATIVE_LANG_CHARACTER_DIGIT_INT_INT,                                         // static int digit(int codePoint, int radix)
    NATIVE_LANG_CHARACTER_EQUALS_OBJECT,                                         // boolean equals(Object obj)
    NATIVE_LANG_CHARACTER_FORDIGIT_INT_INT,                                      // static char forDigit(int digit, int radix)
    NATIVE_LANG_CHARACTER_GETDIRECTIONALITY_CHAR,                                // static byte getDirectionality(char ch)
    NATIVE_LANG_CHARACTER_GETDIRECTIONALITY_INT,                                 // static byte getDirectionality(int codePoint)
    NATIVE_LANG_CHARACTER_GETNUMERICVALUE_CHAR,                                  // static int getNumericValue(char ch)
    NATIVE_LANG_CHARACTER_GETNUMERICVALUE_INT,                                   // static int getNumericValue(int codePoint)
    NATIVE_LANG_CHARACTER_GETTYPE_CHAR,                                          // static int getType(char ch)
    NATIVE_LANG_CHARACTER_GETTYPE_INT,                                           // static int getType(int codePoint)
    NATIVE_LANG_CHARACTER_HASHCODE,                                              // int hashCode()
    NATIVE_LANG_CHARACTER_ISDEFINED_CHAR,                                        // static boolean isDefined(char ch)
    NATIVE_LANG_CHARACTER_ISDEFINED_INT,                                         // static boolean isDefined(int codePoint)
    NATIVE_LANG_CHARACTER_ISDIGIT_CHAR,                                          // static boolean isDigit(char ch)
    NATIVE_LANG_CHARACTER_ISDIGIT_INT,                                           // static boolean isDigit(int codePoint)
    NATIVE_LANG_CHARACTER_ISHIGHSURROGATE_CHAR,                                  // static boolean isHighSurrogate(char ch)
    NATIVE_LANG_CHARACTER_ISIDENTIFIERIGNORABLE_CHAR,                            // static boolean isIdentifierIgnorable(char ch)
    NATIVE_LANG_CHARACTER_ISIDENTIFIERIGNORABLE_INT,                             // static boolean isIdentifierIgnorable(int codePoint)
    NATIVE_LANG_CHARACTER_ISISOCONTROL_CHAR,                                     // static boolean isISOControl(char ch)
    NATIVE_LANG_CHARACTER_ISISOCONTROL_INT,                                      // static boolean isISOControl(int codePoint)
    NATIVE_LANG_CHARACTER_ISJAVAIDENTIFIERPART_CHAR,                             // static boolean isJavaIdentifierPart(char ch)
    NATIVE_LANG_CHARACTER_ISJAVAIDENTIFIERPART_INT,                              // static boolean isJavaIdentifierPart(int codePoint)
    NATIVE_LANG_CHARACTER_ISJAVAIDENTIFIERSTART_CHAR,                            // static boolean isJavaIdentifierStart(char ch)
    NATIVE_LANG_CHARACTER_ISJAVAIDENTIFIERSTART_INT,                             // static boolean isJavaIdentifierStart(int codePoint)
    NATIVE_LANG_CHARACTER_ISJAVALETTER_CHAR,                                     // static boolean isJavaLetter(char ch)
    NATIVE_LANG_CHARACTER_ISJAVALETTERORDIGIT_CHAR,                              // static boolean isJavaLetterOrDigit(char ch)
    NATIVE_LANG_CHARACTER_ISLETTER_CHAR,                                         // static boolean isLetter(char ch)
    NATIVE_LANG_CHARACTER_ISLETTER_INT,                                          // static boolean isLetter(int codePoint)
    NATIVE_LANG_CHARACTER_ISLETTERORDIGIT_CHAR,                                  // static boolean isLetterOrDigit(char ch)
    NATIVE_LANG_CHARACTER_ISLETTERORDIGIT_INT,                                   // static boolean isLetterOrDigit(int codePoint)
    NATIVE_LANG_CHARACTER_ISLOWERCASE_CHAR,                                      // static boolean isLowerCase(char ch)
    NATIVE_LANG_CHARACTER_ISLOWERCASE_INT,                                       // static boolean isLowerCase(int codePoint)
    NATIVE_LANG_CHARACTER_ISLOWSURROGATE_CHAR,                                   // static boolean isLowSurrogate(char ch)
    NATIVE_LANG_CHARACTER_ISMIRRORED_CHAR,                                       // static boolean isMirrored(char ch)
    NATIVE_LANG_CHARACTER_ISMIRRORED_INT,                                        // static boolean isMirrored(int codePoint)
    NATIVE_LANG_CHARACTER_ISSPACE_CHAR,                                          // static boolean isSpace(char ch)
    NATIVE_LANG_CHARACTER_ISSPACECHAR_CHAR,                                      // static boolean isSpaceChar(char ch)
    NATIVE_LANG_CHARACTER_ISSPACECHAR_INT,                                       // static boolean isSpaceChar(int codePoint)
    NATIVE_LANG_CHARACTER_ISSUPPLEMENTARYCODEPOINT_INT,                          // static boolean isSupplementaryCodePoint(int codePoint)
    NATIVE_LANG_CHARACTER_ISSURROGATEPAIR_CHAR_CHAR,                             // static boolean isSurrogatePair(char high, char low)
    NATIVE_LANG_CHARACTER_ISTITLECASE_CHAR,                                      // static boolean isTitleCase(char ch)
    NATIVE_LANG_CHARACTER_ISTITLECASE_INT,                                       // static boolean isTitleCase(int codePoint)
    NATIVE_LANG_CHARACTER_ISUNICODEIDENTIFIERPART_CHAR,                          // static boolean isUnicodeIdentifierPart(char ch)
    NATIVE_LANG_CHARACTER_ISUNICODEIDENTIFIERPART_INT,                           // static boolean isUnicodeIdentifierPart(int codePoint)
    NATIVE_LANG_CHARACTER_ISUNICODEIDENTIFIERSTART_CHAR,                         // static boolean isUnicodeIdentifierStart(char ch)
    NATIVE_LANG_CHARACTER_ISUNICODEIDENTIFIERSTART_INT,                          // static boolean isUnicodeIdentifierStart(int codePoint)
    NATIVE_LANG_CHARACTER_ISUPPERCASE_CHAR,                                      // static boolean isUpperCase(char ch)
    NATIVE_LANG_CHARACTER_ISUPPERCASE_INT,                                       // static boolean isUpperCase(int codePoint)
    NATIVE_LANG_CHARACTER_ISVALIDCODEPOINT_INT,                                  // static boolean isValidCodePoint(int codePoint)
    NATIVE_LANG_CHARACTER_ISWHITESPACE_CHAR,                                     // static boolean isWhitespace(char ch)
    NATIVE_LANG_CHARACTER_ISWHITESPACE_INT,                                      // static boolean isWhitespace(int codePoint)
    NATIVE_LANG_CHARACTER_OFFSETBYCODEPOINTS_ARRAY_CHAR_INT_INT_INT_INT,         // static int offsetByCodePoints(char[] a, int start, int count, int index, int codePointOffset)
    NATIVE_LANG_CHARACTER_OFFSETBYCODEPOINTS_CHARSEQUENCE_INT_INT,               // static int offsetByCodePoints(CharSequence seq, int index, int codePointOffset)
    NATIVE_LANG_CHARACTER_REVERSEBYTES_CHAR,                                     // static char reverseBytes(char ch)
    NATIVE_LANG_CHARACTER_TOCHARS_INT,                                           // static char[] toChars(int codePoint)
    NATIVE_LANG_CHARACTER_TOCHARS_INT_ARRAY_CHAR_INT,                            // static int toChars(int codePoint, char[] dst, int dstIndex)
    NATIVE_LANG_CHARACTER_TOCODEPOINT_CHAR_CHAR,                                 // static int toCodePoint(char high, char low)
    NATIVE_LANG_CHARACTER_TOLOWERCASE_CHAR,                                      // static char toLowerCase(char ch)
    NATIVE_LANG_CHARACTER_TOLOWERCASE_INT,                                       // static int toLowerCase(int codePoint)
    NATIVE_LANG_CHARACTER_TOSTRING,                                              // String toString()
    NATIVE_LANG_CHARACTER_TOSTRING_CHAR,                                         // static String toString(char c)
    NATIVE_LANG_CHARACTER_TOTITLECASE_CHAR,                                      // static char toTitleCase(char ch)
    NATIVE_LANG_CHARACTER_TOTITLECASE_INT,                                       // static int toTitleCase(int codePoint)
    NATIVE_LANG_CHARACTER_TOUPPERCASE_CHAR,                                      // static char toUpperCase(char ch)
    NATIVE_LANG_CHARACTER_TOUPPERCASE_INT,                                       // static int toUpperCase(int codePoint)
    NATIVE_LANG_CHARACTER_VALUEOF_CHAR,                                          // static Character valueOf(char c)
};

///////////////////////////////////////////////////////////////////////////

object_t native_lang_character_new( void );
void native_lang_character_get_field(uint16_t mref);
void native_lang_character_invoke(uint16_t mref);

uint32_t native_lang_character_get_superclass( void );

///////////////////////////////////////////////////////////////////////////

#ifdef	__cplusplus
}
#endif

#endif // NATIVE_LANG_CHARACTER_H


