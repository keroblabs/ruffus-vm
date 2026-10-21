#include "lang_character.h"
#include "heap.h"
#include "application.h"
#include "threads.h"
#include "exceptions.h"
#include "native.h"
#include "objects.h"
#include "stack.h"
#include "value_type.h"
#include "strings.h"

///////////////////////////////////////////////////////////////////////////

// use New method implementation to hold a method
// use New implementation to mark start block
// use End new implementation to mark end block to keep

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////

// static byte COMBINING_SPACING_MARK
#define NATIVE_FIELD_VALUE_LANG_CHARACTER_COMBINING_SPACING_MARK                 0

// static byte CONNECTOR_PUNCTUATION
#define NATIVE_FIELD_VALUE_LANG_CHARACTER_CONNECTOR_PUNCTUATION                  1

// static byte CONTROL
#define NATIVE_FIELD_VALUE_LANG_CHARACTER_CONTROL                                2

// static byte CURRENCY_SYMBOL
#define NATIVE_FIELD_VALUE_LANG_CHARACTER_CURRENCY_SYMBOL                        3

// static byte DASH_PUNCTUATION
#define NATIVE_FIELD_VALUE_LANG_CHARACTER_DASH_PUNCTUATION                       4

// static byte DECIMAL_DIGIT_NUMBER
#define NATIVE_FIELD_VALUE_LANG_CHARACTER_DECIMAL_DIGIT_NUMBER                   5

// static byte DIRECTIONALITY_ARABIC_NUMBER
#define NATIVE_FIELD_VALUE_LANG_CHARACTER_DIRECTIONALITY_ARABIC_NUMBER           6

// static byte DIRECTIONALITY_BOUNDARY_NEUTRAL
#define NATIVE_FIELD_VALUE_LANG_CHARACTER_DIRECTIONALITY_BOUNDARY_NEUTRAL        7

// static byte DIRECTIONALITY_COMMON_NUMBER_SEPARATOR
#define NATIVE_FIELD_VALUE_LANG_CHARACTER_DIRECTIONALITY_COMMON_NUMBER_SEPARATOR 8

// static byte DIRECTIONALITY_EUROPEAN_NUMBER
#define NATIVE_FIELD_VALUE_LANG_CHARACTER_DIRECTIONALITY_EUROPEAN_NUMBER         9

// static byte DIRECTIONALITY_EUROPEAN_NUMBER_SEPARATOR
#define NATIVE_FIELD_VALUE_LANG_CHARACTER_DIRECTIONALITY_EUROPEAN_NUMBER_SEPARATOR 10

// static byte DIRECTIONALITY_EUROPEAN_NUMBER_TERMINATOR
#define NATIVE_FIELD_VALUE_LANG_CHARACTER_DIRECTIONALITY_EUROPEAN_NUMBER_TERMINATOR 11

// static byte DIRECTIONALITY_LEFT_TO_RIGHT
#define NATIVE_FIELD_VALUE_LANG_CHARACTER_DIRECTIONALITY_LEFT_TO_RIGHT           12

// static byte DIRECTIONALITY_LEFT_TO_RIGHT_EMBEDDING
#define NATIVE_FIELD_VALUE_LANG_CHARACTER_DIRECTIONALITY_LEFT_TO_RIGHT_EMBEDDING 13

// static byte DIRECTIONALITY_LEFT_TO_RIGHT_OVERRIDE
#define NATIVE_FIELD_VALUE_LANG_CHARACTER_DIRECTIONALITY_LEFT_TO_RIGHT_OVERRIDE  14

// static byte DIRECTIONALITY_NONSPACING_MARK
#define NATIVE_FIELD_VALUE_LANG_CHARACTER_DIRECTIONALITY_NONSPACING_MARK         15

// static byte DIRECTIONALITY_OTHER_NEUTRALS
#define NATIVE_FIELD_VALUE_LANG_CHARACTER_DIRECTIONALITY_OTHER_NEUTRALS          16

// static byte DIRECTIONALITY_PARAGRAPH_SEPARATOR
#define NATIVE_FIELD_VALUE_LANG_CHARACTER_DIRECTIONALITY_PARAGRAPH_SEPARATOR     17

// static byte DIRECTIONALITY_POP_DIRECTIONAL_FORMAT
#define NATIVE_FIELD_VALUE_LANG_CHARACTER_DIRECTIONALITY_POP_DIRECTIONAL_FORMAT  18

// static byte DIRECTIONALITY_RIGHT_TO_LEFT
#define NATIVE_FIELD_VALUE_LANG_CHARACTER_DIRECTIONALITY_RIGHT_TO_LEFT           19

// static byte DIRECTIONALITY_RIGHT_TO_LEFT_ARABIC
#define NATIVE_FIELD_VALUE_LANG_CHARACTER_DIRECTIONALITY_RIGHT_TO_LEFT_ARABIC    20

// static byte DIRECTIONALITY_RIGHT_TO_LEFT_EMBEDDING
#define NATIVE_FIELD_VALUE_LANG_CHARACTER_DIRECTIONALITY_RIGHT_TO_LEFT_EMBEDDING 21

// static byte DIRECTIONALITY_RIGHT_TO_LEFT_OVERRIDE
#define NATIVE_FIELD_VALUE_LANG_CHARACTER_DIRECTIONALITY_RIGHT_TO_LEFT_OVERRIDE  22

// static byte DIRECTIONALITY_SEGMENT_SEPARATOR
#define NATIVE_FIELD_VALUE_LANG_CHARACTER_DIRECTIONALITY_SEGMENT_SEPARATOR       23

// static byte DIRECTIONALITY_UNDEFINED
#define NATIVE_FIELD_VALUE_LANG_CHARACTER_DIRECTIONALITY_UNDEFINED               24

// static byte DIRECTIONALITY_WHITESPACE
#define NATIVE_FIELD_VALUE_LANG_CHARACTER_DIRECTIONALITY_WHITESPACE              25

// static byte ENCLOSING_MARK
#define NATIVE_FIELD_VALUE_LANG_CHARACTER_ENCLOSING_MARK                         26

// static byte END_PUNCTUATION
#define NATIVE_FIELD_VALUE_LANG_CHARACTER_END_PUNCTUATION                        '.'

// static byte FINAL_QUOTE_PUNCTUATION
#define NATIVE_FIELD_VALUE_LANG_CHARACTER_FINAL_QUOTE_PUNCTUATION                28

// static byte FORMAT
#define NATIVE_FIELD_VALUE_LANG_CHARACTER_FORMAT                                 29

// static byte INITIAL_QUOTE_PUNCTUATION
#define NATIVE_FIELD_VALUE_LANG_CHARACTER_INITIAL_QUOTE_PUNCTUATION              30

// static byte LETTER_NUMBER
#define NATIVE_FIELD_VALUE_LANG_CHARACTER_LETTER_NUMBER                          31

// static byte LINE_SEPARATOR
#define NATIVE_FIELD_VALUE_LANG_CHARACTER_LINE_SEPARATOR                         32

// static byte LOWERCASE_LETTER
#define NATIVE_FIELD_VALUE_LANG_CHARACTER_LOWERCASE_LETTER                       33

// static byte MATH_SYMBOL
#define NATIVE_FIELD_VALUE_LANG_CHARACTER_MATH_SYMBOL                            34

// static int MAX_CODE_POINT
#define NATIVE_FIELD_VALUE_LANG_CHARACTER_MAX_CODE_POINT                         35

// static char MAX_HIGH_SURROGATE
#define NATIVE_FIELD_VALUE_LANG_CHARACTER_MAX_HIGH_SURROGATE                     'A'

// static char MAX_LOW_SURROGATE
#define NATIVE_FIELD_VALUE_LANG_CHARACTER_MAX_LOW_SURROGATE                      'A'

// static int MAX_RADIX
#define NATIVE_FIELD_VALUE_LANG_CHARACTER_MAX_RADIX                              16

// static char MAX_SURROGATE
#define NATIVE_FIELD_VALUE_LANG_CHARACTER_MAX_SURROGATE                          'A'

// static char MAX_VALUE
#define NATIVE_FIELD_VALUE_LANG_CHARACTER_MAX_VALUE                              'A'

// static int MIN_CODE_POINT
#define NATIVE_FIELD_VALUE_LANG_CHARACTER_MIN_CODE_POINT                         37

// static char MIN_HIGH_SURROGATE
#define NATIVE_FIELD_VALUE_LANG_CHARACTER_MIN_HIGH_SURROGATE                     'A'

// static char MIN_LOW_SURROGATE
#define NATIVE_FIELD_VALUE_LANG_CHARACTER_MIN_LOW_SURROGATE                      'A'

// static int MIN_RADIX
#define NATIVE_FIELD_VALUE_LANG_CHARACTER_MIN_RADIX                              2

// static int MIN_SUPPLEMENTARY_CODE_POINT
#define NATIVE_FIELD_VALUE_LANG_CHARACTER_MIN_SUPPLEMENTARY_CODE_POINT           39

// static char MIN_SURROGATE
#define NATIVE_FIELD_VALUE_LANG_CHARACTER_MIN_SURROGATE                          'A'

// static char MIN_VALUE
#define NATIVE_FIELD_VALUE_LANG_CHARACTER_MIN_VALUE                              ' '

// static byte MODIFIER_LETTER
#define NATIVE_FIELD_VALUE_LANG_CHARACTER_MODIFIER_LETTER                        40

// static byte MODIFIER_SYMBOL
#define NATIVE_FIELD_VALUE_LANG_CHARACTER_MODIFIER_SYMBOL                        41

// static byte NON_SPACING_MARK
#define NATIVE_FIELD_VALUE_LANG_CHARACTER_NON_SPACING_MARK                       42

// static byte OTHER_LETTER
#define NATIVE_FIELD_VALUE_LANG_CHARACTER_OTHER_LETTER                           43

// static byte OTHER_NUMBER
#define NATIVE_FIELD_VALUE_LANG_CHARACTER_OTHER_NUMBER                           44

// static byte OTHER_PUNCTUATION
#define NATIVE_FIELD_VALUE_LANG_CHARACTER_OTHER_PUNCTUATION                      45

// static byte OTHER_SYMBOL
#define NATIVE_FIELD_VALUE_LANG_CHARACTER_OTHER_SYMBOL                           46

// static byte PARAGRAPH_SEPARATOR
#define NATIVE_FIELD_VALUE_LANG_CHARACTER_PARAGRAPH_SEPARATOR                    47

// static byte PRIVATE_USE
#define NATIVE_FIELD_VALUE_LANG_CHARACTER_PRIVATE_USE                            48

// static int SIZE
#define NATIVE_FIELD_VALUE_LANG_CHARACTER_SIZE                                   1

// static byte SPACE_SEPARATOR
#define NATIVE_FIELD_VALUE_LANG_CHARACTER_SPACE_SEPARATOR                        0x20

// static byte START_PUNCTUATION
#define NATIVE_FIELD_VALUE_LANG_CHARACTER_START_PUNCTUATION                      51

// static byte SURROGATE
#define NATIVE_FIELD_VALUE_LANG_CHARACTER_SURROGATE                              52

// static byte TITLECASE_LETTER
#define NATIVE_FIELD_VALUE_LANG_CHARACTER_TITLECASE_LETTER                       53


// static byte UNASSIGNED
#define NATIVE_FIELD_VALUE_LANG_CHARACTER_UNASSIGNED                             54

// static byte UPPERCASE_LETTER
#define NATIVE_FIELD_VALUE_LANG_CHARACTER_UPPERCASE_LETTER                       55

///////////////////////////////////////////////////////////////////////////

// New method implementation
object_t native_lang_character_new_value( char value )
{
	object_t object;

    object = native_lang_character_new();
	LANG_NUMBER_VALUE_FIELD( object ) = value_create_character( value );

	return object;
}

object_t native_lang_character_new( void )
{
    return( object_create( GET_CLASS_REF( NATIVE_CLASS_LANG_CHARACTER ), T_CLASS, NATIVE_LANG_CHARACTER_TOTAL_FIELDS ) );
}

///////////////////////////////////////////////////////////////////////////

void native_method_lang_character_init_char( void )
{
    // Character(char value)
    // Constructs a newly allocated Character object that represents 
    // the specified char value. 
    // Implementation code: 6C3E7117
    object_t char_value;
    object_t object;

    char_value = stack_pop();
    object = stack_pop();

    // put your code here
	LANG_NUMBER_VALUE_FIELD( object ) = value_create_character( value_get_character( char_value ) );
}

///////////////////////////////////////////////////////////////////////////

void native_method_lang_character_charcount_int( void )
{
    // static int charCount(int codePoint)
    // Determines the number of char values needed to represent 
    // the specified character (Unicode code point). 
    // Implementation code: 79B0D6CB
    object_t int_codepoint;
    int32_t ret_value = 0;

    int_codepoint = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push( value_create( &ret_value, T_INT ) );
}

void native_method_lang_character_charvalue( void )
{
    // char charValue()
    // Returns the value of this Character object. 
    // Implementation code: 2EA7DC35
    object_t object;
    char ret_value = '?';

    object = stack_pop();

    // put your code here
    ret_value = value_get_character( LANG_NUMBER_VALUE_FIELD( object ) );

    // return type: char
    stack_push_character( ret_value );
}

void native_method_lang_character_codepointat_array_char_int( void )
{
    // static int codePointAt(char[] a, int index)
    // Returns the code point at the given index of the char array. 
    // Implementation code: F31E1724
    object_t char_array_a;
    object_t int_index;
    int32_t ret_value = 0;

    int_index = stack_pop();
    char_array_a = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push_integer( ret_value );
}

void native_method_lang_character_codepointat_array_char_int_int( void )
{
    // static int codePointAt(char[] a, int index, int limit)
    // Returns the code point at the given index of the char array, 
    // where only array elements with index less than limit can 
    // be used. 
    // Implementation code: 755ACCD1
    object_t char_array_a;
    object_t int_index;
    object_t int_limit;
    int32_t ret_value = 0;

    int_limit = stack_pop();
    int_index = stack_pop();
    char_array_a = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push( value_create( &ret_value, T_INT ) );
}

void native_method_lang_character_codepointat_charsequence_int( void )
{
    // static int codePointAt(CharSequence seq, int index)
    // Returns the code point at the given index of the CharSequence. 
    // Implementation code: 14E03CA7
    object_t charsequence_seq;
    object_t int_index;
    int32_t ret_value = 0;

    int_index = stack_pop();
    charsequence_seq = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push( value_create( &ret_value, T_INT ) );
}

void native_method_lang_character_codepointbefore_array_char_int( void )
{
    // static int codePointBefore(char[] a, int index)
    // Returns the code point preceding the given index of the 
    // char array. 
    // Implementation code: 845F6432
    object_t char_array_a;
    object_t int_index;
    int32_t ret_value = 0;

    int_index = stack_pop();
    char_array_a = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push( value_create( &ret_value, T_INT ) );
}

void native_method_lang_character_codepointbefore_array_char_int_int( void )
{
    // static int codePointBefore(char[] a, int index, int start)
    // Returns the code point preceding the given index of the 
    // char array, where only array elements with index greater 
    // than or equal to start can be used. 
    // Implementation code: 859A7709
    object_t char_array_a;
    object_t int_index;
    object_t int_start;
    int32_t ret_value = 0;

    int_start = stack_pop();
    int_index = stack_pop();
    char_array_a = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push( value_create( &ret_value, T_INT ) );
}

void native_method_lang_character_codepointbefore_charsequence_int( void )
{
    // static int codePointBefore(CharSequence seq, int index)
    // Returns the code point preceding the given index of the 
    // CharSequence. 
    // Implementation code: DF3362EB
    object_t charsequence_seq;
    object_t int_index;
    int32_t ret_value = 0;

    int_index = stack_pop();
    charsequence_seq = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push( value_create( &ret_value, T_INT ) );
}

void native_method_lang_character_codepointcount_array_char_int_int( void )
{
    // static int codePointCount(char[] a, int offset, int count)
    // Returns the number of Unicode code points in a subarray 
    // of the char array argument. 
    // Implementation code: AF002534
    object_t char_array_a;
    object_t int_offset;
    object_t int_count;
    int32_t ret_value = 0;

    int_count = stack_pop();
    int_offset = stack_pop();
    char_array_a = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push( value_create( &ret_value, T_INT ) );
}

void native_method_lang_character_codepointcount_charsequence_int_int( void )
{
    // static int codePointCount(CharSequence seq, int beginIndex, int endIndex)
    // Returns the number of Unicode code points in the text range 
    // of the specified char sequence. 
    // Implementation code: D9247A7B
    object_t charsequence_seq;
    object_t int_beginindex;
    object_t int_endindex;
    int32_t ret_value = 0;

    int_endindex = stack_pop();
    int_beginindex = stack_pop();
    charsequence_seq = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push( value_create( &ret_value, T_INT ) );
}

void native_method_lang_character_compareto_character( void )
{
    // int compareTo(Character anotherCharacter)
    // Compares two Character objects numerically. 
    // Implementation code: 950692B1
    lang_number_lib_compare_to();
}

void native_method_lang_character_digit_char_int( void )
{
    // static int digit(char ch, int radix)
    // Returns the numeric value of the character ch in the specified 
    // radix. 
    // Implementation code: 0E64D8E8
    object_t char_ch;
    object_t int_radix;
    int32_t ret_value = 0;

    int_radix = stack_pop();
    char_ch = stack_pop();

    // put your code here
    ret_value = ( int32_t )value_get_character( char_ch );

    // return type: int
    stack_push_integer( ret_value );
}

void native_method_lang_character_digit_int_int( void )
{
    // static int digit(int codePoint, int radix)
    // Returns the numeric value of the specified character (Unicode 
    // code point) in the specified radix. 
    // Implementation code: EA77330F
    object_t int_codepoint;
    object_t int_radix;
    int32_t ret_value = 0;

    int_radix = stack_pop();
    int_codepoint = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push( value_create( &ret_value, T_INT ) );
}

void native_method_lang_character_equals_object( void )
{
    // boolean equals(Object obj)
    // Compares this object against the specified object. 
    // Implementation code: 4048E6D8
    lang_number_lib_equals();
}

void native_method_lang_character_fordigit_int_int( void )
{
    // static char forDigit(int digit, int radix)
    // Determines the character representation for a specific digit 
    // in the specified radix. 
    // Implementation code: 39B7977F
    object_t int_digit;
    object_t int_radix;
    char ret_value = '?';

    int_radix = stack_pop();
    int_digit = stack_pop();

    // put your code here
    ret_value = ( char )value_get_int( int_digit );

    // return type: char
    stack_push_character( ret_value );
}

void native_method_lang_character_getdirectionality_char( void )
{
    // static byte getDirectionality(char ch)
    // Returns the Unicode directionality property for the given 
    // character. 
    // Implementation code: CC932E46
    object_t char_ch;
    uint8_t ret_value = 0;

    char_ch = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: byte
    stack_push( value_create( &ret_value, T_BYTE ) );
}

void native_method_lang_character_getdirectionality_int( void )
{
    // static byte getDirectionality(int codePoint)
    // Returns the Unicode directionality property for the given 
    // character (Unicode code point). 
    // Implementation code: F03C8228
    object_t int_codepoint;
    uint8_t ret_value = 0;

    int_codepoint = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: byte
    stack_push( value_create( &ret_value, T_BYTE ) );
}

void native_method_lang_character_getnumericvalue_char( void )
{
    // static int getNumericValue(char ch)
    // Returns the int value that the specified Unicode character 
    // represents. 
    // Implementation code: CAE8C26C
    object_t char_ch;
    int32_t ret_value = 0;

    char_ch = stack_pop();

    // put your code here
    ret_value = ( int32_t )value_get_character( char_ch );

    // return type: int
    stack_push_integer( ret_value );
}

void native_method_lang_character_getnumericvalue_int( void )
{
    // static int getNumericValue(int codePoint)
    // Returns the int value that the specified character (Unicode 
    // code point) represents. 
    // Implementation code: 5248FD54
    object_t int_codepoint;
    int32_t ret_value = 0;

    int_codepoint = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push_integer( ret_value );
}

void native_method_lang_character_gettype_char( void )
{
    // static int getType(char ch)
    // Returns a value indicating a character's general category. 
    // Implementation code: 248B7FC5
    object_t char_ch;
    int32_t ret_value = 0;

    char_ch = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push_integer( ret_value );
}

void native_method_lang_character_gettype_int( void )
{
    // static int getType(int codePoint)
    // Returns a value indicating a character's general category. 
    // Implementation code: 248B7FC5
    object_t char_ch;
    int32_t ret_value = 0;

    char_ch = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push_integer( ret_value );
}

void native_method_lang_character_hashcode( void )
{
    // int hashCode()
    // Returns a hash code for this Character. 
    // Implementation code: 6EF8B1E3
    lang_number_lib_hashcode();
}

void native_method_lang_character_isdefined_char( void )
{
    // static boolean isDefined(char ch)
    // Determines if a character is defined in Unicode. 
    // Implementation code: 842B82EB
    object_t char_ch;
    bool_t ret_value = 0;

    char_ch = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: boolean
    stack_push_boolean( ret_value );
}

void native_method_lang_character_isdefined_int( void )
{
    // static boolean isDefined(int codePoint)
    // Determines if a character (Unicode code point) is defined 
    // in Unicode. 
    // Implementation code: D54C2619
    object_t int_codepoint;
    bool_t ret_value = 0;

    int_codepoint = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: boolean
    stack_push_boolean( ret_value );
}

void native_method_lang_character_isdigit_char( void )
{
    // static boolean isDigit(char ch)
    // Determines if the specified character is a digit. 
    // Implementation code: AF626633
    object_t char_ch;
    bool_t ret_value = 0;
	char char_data;

    char_ch = stack_pop();

    // put your code here
    char_data = value_get_character( char_ch );
	if( ( char_data >= '0' ) && ( char_data <= '9' ) ) ret_value = 1;

    // return type: boolean
    stack_push_boolean( ret_value );
}

void native_method_lang_character_isdigit_int( void )
{
    // static boolean isDigit(int codePoint)
    // Determines if the specified character (Unicode code point) 
    // is a digit. 
    // Implementation code: FF61BE2F
    object_t int_codepoint;
    bool_t ret_value = 0;

    int_codepoint = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: boolean
    stack_push_boolean( ret_value );
}

void native_method_lang_character_ishighsurrogate_char( void )
{
    // static boolean isHighSurrogate(char ch)
    // Determines if the given char value is a high-surrogate code 
    // unit (also known as leading-surrogate code unit). 
    // Implementation code: 9416A530
    object_t char_ch;
    bool_t ret_value = 0;

    char_ch = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: boolean
    stack_push_boolean( ret_value );
}

void native_method_lang_character_isidentifierignorable_char( void )
{
    // static boolean isIdentifierIgnorable(char ch)
    // Determines if the specified character should be regarded 
    // as an ignorable character in a Java identifier or a Unicode 
    // identifier. 
    // Implementation code: C8F163E3
    object_t char_ch;
    bool_t ret_value = 0;

    char_ch = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: boolean
    stack_push_boolean( ret_value );
}

void native_method_lang_character_isidentifierignorable_int( void )
{
    // static boolean isIdentifierIgnorable(int codePoint)
    // Determines if the specified character (Unicode code point) 
    // should be regarded as an ignorable character in a Java identifier 
    // or a Unicode identifier. 
    // Implementation code: 5B06593F
    object_t int_codepoint;
    bool_t ret_value = 0;

    int_codepoint = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: boolean
    stack_push_boolean( ret_value );
}

void native_method_lang_character_isisocontrol_char( void )
{
    // static boolean isISOControl(char ch)
    // Determines if the specified character is an ISO control 
    // character. 
    // Implementation code: 60A08AAF
    object_t char_ch;
    bool_t ret_value = 0;

    char_ch = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: boolean
    stack_push_boolean( ret_value );
}

void native_method_lang_character_isisocontrol_int( void )
{
    // static boolean isISOControl(int codePoint)
    // Determines if the referenced character (Unicode code point) 
    // is an ISO control character. 
    // Implementation code: 3DCF38F3
    object_t int_codepoint;
    bool_t ret_value = 0;

    int_codepoint = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: boolean
    stack_push_boolean( ret_value );
}

void native_method_lang_character_isjavaidentifierpart_char( void )
{
    // static boolean isJavaIdentifierPart(char ch)
    // Determines if the specified character may be part of a Java 
    // identifier as other than the first character. 
    // Implementation code: E94F072E
    object_t char_ch;
    bool_t ret_value = 0;

    char_ch = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: boolean
    stack_push_boolean( ret_value );
}

void native_method_lang_character_isjavaidentifierpart_int( void )
{
    // static boolean isJavaIdentifierPart(int codePoint)
    // Determines if the character (Unicode code point) may be 
    // part of a Java identifier as other than the first character. 
    // Implementation code: 76B457B9
    object_t int_codepoint;
    bool_t ret_value = 0;

    int_codepoint = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: boolean
    stack_push_boolean( ret_value );
}

void native_method_lang_character_isjavaidentifierstart_char( void )
{
    // static boolean isJavaIdentifierStart(char ch)
    // Determines if the specified character is permissible as 
    // the first character in a Java identifier. 
    // Implementation code: F0447FFF
    object_t char_ch;
    bool_t ret_value = 0;

    char_ch = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: boolean
    stack_push_boolean( ret_value );
}

void native_method_lang_character_isjavaidentifierstart_int( void )
{
    // static boolean isJavaIdentifierStart(int codePoint)
    // Determines if the character (Unicode code point) is permissible 
    // as the first character in a Java identifier. 
    // Implementation code: 0092D64E
    object_t int_codepoint;
    bool_t ret_value = 0;

    int_codepoint = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: boolean
    stack_push_boolean( ret_value );
}

void native_method_lang_character_isjavaletter_char( void )
{
    // static boolean isJavaLetter(char ch)
    // Deprecated. Replaced by isJavaIdentifierStart(char). 
    // Implementation code: C5085EE3
    object_t char_ch;
    bool_t ret_value = 0;

    char_ch = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: boolean
    stack_push_boolean( ret_value );
}

void native_method_lang_character_isjavaletterordigit_char( void )
{
    // static boolean isJavaLetterOrDigit(char ch)
    // Deprecated. Replaced by isJavaIdentifierPart(char). 
    // Implementation code: 3FDD42F2
    object_t char_ch;
    bool_t ret_value = 0;

    char_ch = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: boolean
    stack_push_boolean( ret_value );
}

void native_method_lang_character_isletter_char( void )
{
    // static boolean isLetter(char ch)
    // Determines if the specified character is a letter. 
    // Implementation code: 34400902
    object_t char_ch;
    bool_t ret_value = 0;
	char char_data;

    char_ch = stack_pop();

    // put your code here
    char_data = value_get_character( char_ch );
	if( ( ( char_data >= 'A' ) && ( char_data <= 'Z' ) ) ||
	    ( ( char_data >= 'a' ) && ( char_data <= 'z' ) ) ) ret_value = 1;

    // return type: boolean
    stack_push_boolean( ret_value );
}

void native_method_lang_character_isletter_int( void )
{
    // static boolean isLetter(int codePoint)
    // Determines if the specified character (Unicode code point) 
    // is a letter. 
    // Implementation code: C997EB42
    object_t int_codepoint;
    bool_t ret_value = 0;

    int_codepoint = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: boolean
    stack_push_boolean( ret_value );
}

void native_method_lang_character_isletterordigit_char( void )
{
    // static boolean isLetterOrDigit(char ch)
    // Determines if the specified character is a letter or digit. 
    // Implementation code: A9DF3EFC
    object_t char_ch;
    bool_t ret_value = 0;
	char char_data;

    char_ch = stack_pop();

    // put your code here
    char_data = value_get_character( char_ch );
	if( ( ( char_data >= 'A' ) && ( char_data <= 'Z' ) ) ||
	    ( ( char_data >= 'a' ) && ( char_data <= 'z' ) ) ||
	    ( ( char_data >= '0' ) && ( char_data <= '9' ) ) ) ret_value = 1;

    // return type: boolean
    stack_push_boolean( ret_value );
}

void native_method_lang_character_isletterordigit_int( void )
{
    // static boolean isLetterOrDigit(int codePoint)
    // Determines if the specified character (Unicode code point) 
    // is a letter or digit. 
    // Implementation code: DE4906AB
    object_t int_codepoint;
    bool_t ret_value = 0;

    int_codepoint = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: boolean
    stack_push_boolean( ret_value );
}

void native_method_lang_character_islowercase_char( void )
{
    // static boolean isLowerCase(char ch)
    // Determines if the specified character is a lowercase character. 
    // Implementation code: BC3E2AC6
    object_t char_ch;
    bool_t ret_value = 0;
	char char_data;

    char_ch = stack_pop();

    // put your code here
    char_data = value_get_character( char_ch );
	if( ( char_data >= 'a' ) && ( char_data <= 'z' ) ) ret_value = 1;

    // return type: boolean
    stack_push_boolean( ret_value );
}

void native_method_lang_character_islowercase_int( void )
{
    // static boolean isLowerCase(int codePoint)
    // Determines if the specified character (Unicode code point) 
    // is a lowercase character. 
    // Implementation code: 149407E5
    object_t int_codepoint;
    bool_t ret_value = 0;

    int_codepoint = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: boolean
    stack_push_boolean( ret_value );
}

void native_method_lang_character_islowsurrogate_char( void )
{
    // static boolean isLowSurrogate(char ch)
    // Determines if the given char value is a low-surrogate code 
    // unit (also known as trailing-surrogate code unit). 
    // Implementation code: 6D405302
    object_t char_ch;
    bool_t ret_value = 0;

    char_ch = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: boolean
    stack_push_boolean( ret_value );
}

void native_method_lang_character_ismirrored_char( void )
{
    // static boolean isMirrored(char ch)
    // Determines whether the character is mirrored according to 
    // the Unicode specification. 
    // Implementation code: AE6AAB5A
    object_t char_ch;
    bool_t ret_value = 0;

    char_ch = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: boolean
    stack_push_boolean( ret_value );
}

void native_method_lang_character_ismirrored_int( void )
{
    // static boolean isMirrored(int codePoint)
    // Determines whether the specified character (Unicode code 
    // point) is mirrored according to the Unicode specification. 
    // Implementation code: F7A18779
    object_t int_codepoint;
    bool_t ret_value = 0;

    int_codepoint = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: boolean
    stack_push_boolean( ret_value );
}

void native_method_lang_character_isspace_char( void )
{
    // static boolean isSpace(char ch)
    // Deprecated. Replaced by isWhitespace(char). 
    // Implementation code: C29F7670
    object_t char_ch;
    bool_t ret_value = 0;
	char char_data;

    char_ch = stack_pop();

    // put your code here
    char_data = value_get_character( char_ch );
	if( char_data == ' ' ) ret_value = 1;

    // return type: boolean
    stack_push_boolean( ret_value );
}

void native_method_lang_character_isspacechar_char( void )
{
    // static boolean isSpaceChar(char ch)
    // Determines if the specified character is a Unicode space 
    // character. 
    // Implementation code: E2BDAC34
    object_t char_ch;
    bool_t ret_value = 0;
	char char_data;

    char_ch = stack_pop();

    // put your code here
    char_data = value_get_character( char_ch );
	if( char_data == ' ' ) ret_value = 1;

    // return type: boolean
    stack_push_boolean( ret_value );
}

void native_method_lang_character_isspacechar_int( void )
{
    // static boolean isSpaceChar(int codePoint)
    // Determines if the specified character (Unicode code point) 
    // is a Unicode space character. 
    // Implementation code: 386EB887
    object_t int_codepoint;
    bool_t ret_value = 0;

    int_codepoint = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: boolean
    stack_push_boolean( ret_value );
}

void native_method_lang_character_issupplementarycodepoint_int( void )
{
    // static boolean isSupplementaryCodePoint(int codePoint)
    // Determines whether the specified character (Unicode code 
    // point) is in the supplementary character range. 
    // Implementation code: 33FFC8C9
    object_t int_codepoint;
    bool_t ret_value = 0;

    int_codepoint = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: boolean
    stack_push_boolean( ret_value );
}

void native_method_lang_character_issurrogatepair_char_char( void )
{
    // static boolean isSurrogatePair(char high, char low)
    // Determines whether the specified pair of char values is 
    // a valid surrogate pair. 
    // Implementation code: 01DF21DB
    object_t char_high;
    object_t char_low;
    bool_t ret_value = 0;

    char_low = stack_pop();
    char_high = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: boolean
    stack_push_boolean( ret_value );
}

void native_method_lang_character_istitlecase_char( void )
{
    // static boolean isTitleCase(char ch)
    // Determines if the specified character is a titlecase character. 
    // Implementation code: BE2C9135
    object_t char_ch;
    bool_t ret_value = 0;

    char_ch = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: boolean
    stack_push_boolean( ret_value );
}

void native_method_lang_character_istitlecase_int( void )
{
    // static boolean isTitleCase(int codePoint)
    // Determines if the specified character (Unicode code point) 
    // is a titlecase character. 
    // Implementation code: 973DD019
    object_t int_codepoint;
    bool_t ret_value = 0;

    int_codepoint = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: boolean
    stack_push_boolean( ret_value );
}

void native_method_lang_character_isunicodeidentifierpart_char( void )
{
    // static boolean isUnicodeIdentifierPart(char ch)
    // Determines if the specified character may be part of a Unicode 
    // identifier as other than the first character. 
    // Implementation code: 2F8064F5
    object_t char_ch;
    bool_t ret_value = 0;

    char_ch = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: boolean
    stack_push_boolean( ret_value );
}

void native_method_lang_character_isunicodeidentifierpart_int( void )
{
    // static boolean isUnicodeIdentifierPart(int codePoint)
    // Determines if the specified character (Unicode code point) 
    // may be part of a Unicode identifier as other than the first 
    // character. 
    // Implementation code: 81E36AB6
    object_t int_codepoint;
    bool_t ret_value = 0;

    int_codepoint = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: boolean
    stack_push_boolean( ret_value );
}

void native_method_lang_character_isunicodeidentifierstart_char( void )
{
    // static boolean isUnicodeIdentifierStart(char ch)
    // Determines if the specified character is permissible as 
    // the first character in a Unicode identifier. 
    // Implementation code: EE873163
    object_t char_ch;
    bool_t ret_value = 0;

    char_ch = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: boolean
    stack_push_boolean( ret_value );
}

void native_method_lang_character_isunicodeidentifierstart_int( void )
{
    // static boolean isUnicodeIdentifierStart(int codePoint)
    // Determines if the specified character (Unicode code point) 
    // is permissible as the first character in a Unicode identifier. 
    // Implementation code: F8A1CC66
    object_t int_codepoint;
    bool_t ret_value = 0;

    int_codepoint = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: boolean
    stack_push_boolean( ret_value );
}

void native_method_lang_character_isuppercase_char( void )
{
    // static boolean isUpperCase(char ch)
    // Determines if the specified character is an uppercase character. 
    // Implementation code: 3EFABD35
    object_t char_ch;
    bool_t ret_value = 0;
	char char_data;

    char_ch = stack_pop();

    // put your code here
    char_data = value_get_character( char_ch );
	if( ( char_data >= 'A' ) && ( char_data <= 'Z' ) ) ret_value = 1;

    // return type: boolean
    stack_push_boolean( ret_value );
}

void native_method_lang_character_isuppercase_int( void )
{
    // static boolean isUpperCase(int codePoint)
    // Determines if the specified character (Unicode code point) 
    // is an uppercase character. 
    // Implementation code: E39C4DDC
    object_t int_codepoint;
    bool_t ret_value = 0;

    int_codepoint = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: boolean
    stack_push_boolean( ret_value );
}

void native_method_lang_character_isvalidcodepoint_int( void )
{
    // static boolean isValidCodePoint(int codePoint)
    // Determines whether the specified code point is a valid Unicode 
    // code point value in the range of 0x0000 to 0x10FFFF inclusive. 
    // Implementation code: 6A16C135
    object_t int_codepoint;
    bool_t ret_value = 0;

    int_codepoint = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: boolean
    stack_push_boolean( ret_value );
}

void native_method_lang_character_iswhitespace_char( void )
{
    // static boolean isWhitespace(char ch)
    // Determines if the specified character is white space according 
    // to Java. 
    // Implementation code: 6DD0B4B7
    object_t char_ch;
    bool_t ret_value = 0;
	char char_data;

    char_ch = stack_pop();

    // put your code here
	char_data = value_get_character( char_ch );
	if( char_data == ' ' ) ret_value = 1;

    // return type: boolean
    stack_push_boolean( ret_value );
}

void native_method_lang_character_iswhitespace_int( void )
{
    // static boolean isWhitespace(int codePoint)
    // Determines if the specified character (Unicode code point) 
    // is white space according to Java. 
    // Implementation code: 3E8A3769
    object_t int_codepoint;
    bool_t ret_value = 0;

    int_codepoint = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: boolean
    stack_push_boolean( ret_value );
}

void native_method_lang_character_offsetbycodepoints_array_char_int_int_int_int( void )
{
    // static int offsetByCodePoints(char[] a, int start, int count, int index, int codePointOffset)
    // Returns the index within the given char subarray that is 
    // offset from the given index by codePointOffset code points. 
    // Implementation code: 507E0F73
    object_t char_array_a;
    object_t int_start;
    object_t int_count;
    object_t int_index;
    object_t int_codepointoffset;
    int32_t ret_value = 0;

    int_codepointoffset = stack_pop();
    int_index = stack_pop();
    int_count = stack_pop();
    int_start = stack_pop();
    char_array_a = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push_integer( ret_value );
}

void native_method_lang_character_offsetbycodepoints_charsequence_int_int( void )
{
    // static int offsetByCodePoints(CharSequence seq, int index, int codePointOffset)
    // Returns the index within the given char sequence that is 
    // offset from the given index by codePointOffset code points. 
    // Implementation code: 1C9B15B3
    object_t charsequence_seq;
    object_t int_index;
    object_t int_codepointoffset;
    int32_t ret_value = 0;

    int_codepointoffset = stack_pop();
    int_index = stack_pop();
    charsequence_seq = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push_integer( ret_value );
}

void native_method_lang_character_reversebytes_char( void )
{
    // static char reverseBytes(char ch)
    // Returns the value obtained by reversing the order of the 
    // bytes in the specified char value. 
    // Implementation code: FF589E67
    object_t char_ch;
    char ret_value = '?';

    char_ch = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: char
    stack_push_character( ret_value );
}

void native_method_lang_character_tochars_int( void )
{
    // static char[] toChars(int codePoint)
    // Converts the specified character (Unicode code point) to 
    // its UTF-16 representation stored in a char array. 
    // Implementation code: 0E992832
    object_t int_codepoint;

    int_codepoint = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: char[]
    stack_push( 0 );
}

void native_method_lang_character_tochars_int_array_char_int( void )
{
    // static int toChars(int codePoint, char[] dst, int dstIndex)
    // Converts the specified character (Unicode code point) to 
    // its UTF-16 representation. 
    // Implementation code: 97F1857B
    object_t int_codepoint;
    object_t char_array_dst;
    object_t int_dstindex;
    int32_t ret_value = 0;

    int_dstindex = stack_pop();
    char_array_dst = stack_pop();
    int_codepoint = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push_integer( ret_value );
}

void native_method_lang_character_tocodepoint_char_char( void )
{
    // static int toCodePoint(char high, char low)
    // Converts the specified surrogate pair to its supplementary 
    // code point value. 
    // Implementation code: 969AB77C
    object_t char_high;
    object_t char_low;
    int32_t ret_value = 0;

    char_low = stack_pop();
    char_high = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push_integer( ret_value );
}

void native_method_lang_character_tolowercase_char( void )
{
    // static char toLowerCase(char ch)
    // Converts the character argument to lowercase using case 
    // mapping information from the UnicodeData file. 
    // Implementation code: 57401EF3
    object_t char_ch;
    char ret_value = '?';

    char_ch = stack_pop();

    // put your code here
    ret_value = value_get_character( char_ch );
	if( ( ret_value >= 'A' ) && ( ret_value <= 'Z' ) ) ret_value |= 0x20;

    // return type: char
    stack_push_character( ret_value );
}

void native_method_lang_character_tolowercase_int( void )
{
    // static int toLowerCase(int codePoint)
    // Converts the character (Unicode code point) argument to 
    // lowercase using case mapping information from the UnicodeData 
    // file. 
    // Implementation code: 82612453
    object_t int_codepoint;
    int32_t ret_value = 0;

    int_codepoint = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push_integer( ret_value );
}

void native_method_lang_character_tostring( void )
{
    // String toString()
    // Returns a String object representing this Character's value. 
    // Implementation code: 16D69EF6
    lang_number_lib_object_tostring(RADIX_DECIMAL);
}

void native_method_lang_character_tostring_char( void )
{
    // static String toString(char c)
    // Returns a String object representing the specified char. 
    // Implementation code: FC2BAF3E
    lang_number_lib_value_tostring(RADIX_DECIMAL);
}

void native_method_lang_character_totitlecase_char( void )
{
    // static char toTitleCase(char ch)
    // Converts the character argument to titlecase using case 
    // mapping information from the UnicodeData file. 
    // Implementation code: 1BA57A5E
    object_t char_ch;
    char ret_value = '?';

    char_ch = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: char
    stack_push_character( ret_value );
}

void native_method_lang_character_totitlecase_int( void )
{
    // static int toTitleCase(int codePoint)
    // Converts the character (Unicode code point) argument to 
    // titlecase using case mapping information from the UnicodeData 
    // file. 
    // Implementation code: B448D87E
    object_t int_codepoint;
    int32_t ret_value = 0;

    int_codepoint = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push_integer( ret_value );
}

void native_method_lang_character_touppercase_char( void )
{
    // static char toUpperCase(char ch)
    // Converts the character argument to uppercase using case 
    // mapping information from the UnicodeData file. 
    // Implementation code: 17563109
    object_t char_ch;
    char ret_value = '?';

    char_ch = stack_pop();

    // put your code here
    ret_value = value_get_character( char_ch );
	if( ( ret_value >= 'a' ) && ( ret_value <= 'z' ) ) ret_value &= ~0x20;

    // return type: char
    stack_push_character( ret_value );
}

void native_method_lang_character_touppercase_int( void )
{
    // static int toUpperCase(int codePoint)
    // Converts the character (Unicode code point) argument to 
    // uppercase using case mapping information from the UnicodeData 
    // file. 
    // Implementation code: A963BBCC
    object_t int_codepoint;
    int32_t ret_value = 0;

    int_codepoint = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push_integer( ret_value );
}

void native_method_lang_character_valueof_char( void )
{
    // static Character valueOf(char c)
    // Returns a Character instance representing the specified 
    // char value. 
    // Implementation code: 078B6424
    object_t char_c;

    char_c = stack_pop();

    // return type: Character
    stack_push( native_lang_character_new_value( value_get_character( char_c ) ) );
}

///////////////////////////////////////////////////////////////////////////

uint32_t native_lang_character_get_superclass( void )
{
	return NATIVE_CLASS_LANG_OBJECT;
}

void native_lang_character_get_field(uint16_t mref)
{
    switch( mref )
    {
        case NATIVE_FIELD_LANG_CHARACTER_COMBINING_SPACING_MARK:
            // static byte COMBINING_SPACING_MARK
            // Implementation field read code: FIELD_READ_LANG_CHARACTER_COMBINING_SPACING_MARK
            stack_push( value_create_byte( NATIVE_FIELD_VALUE_LANG_CHARACTER_COMBINING_SPACING_MARK ) );
            break;

        case NATIVE_FIELD_LANG_CHARACTER_CONNECTOR_PUNCTUATION:
            // static byte CONNECTOR_PUNCTUATION
            // Implementation field read code: FIELD_READ_LANG_CHARACTER_CONNECTOR_PUNCTUATION
            stack_push( value_create_byte( NATIVE_FIELD_VALUE_LANG_CHARACTER_CONNECTOR_PUNCTUATION ) );
            break;

        case NATIVE_FIELD_LANG_CHARACTER_CONTROL:
            // static byte CONTROL
            // Implementation field read code: FIELD_READ_LANG_CHARACTER_CONTROL
            stack_push( value_create_byte( NATIVE_FIELD_VALUE_LANG_CHARACTER_CONTROL ) );
            break;

        case NATIVE_FIELD_LANG_CHARACTER_CURRENCY_SYMBOL:
            // static byte CURRENCY_SYMBOL
            // Implementation field read code: FIELD_READ_LANG_CHARACTER_CURRENCY_SYMBOL
            stack_push( value_create_byte( NATIVE_FIELD_VALUE_LANG_CHARACTER_CURRENCY_SYMBOL ) );
            break;

        case NATIVE_FIELD_LANG_CHARACTER_DASH_PUNCTUATION:
            // static byte DASH_PUNCTUATION
            // Implementation field read code: FIELD_READ_LANG_CHARACTER_DASH_PUNCTUATION
            stack_push( value_create_byte( NATIVE_FIELD_VALUE_LANG_CHARACTER_DASH_PUNCTUATION ) );
            break;

        case NATIVE_FIELD_LANG_CHARACTER_DECIMAL_DIGIT_NUMBER:
            // static byte DECIMAL_DIGIT_NUMBER
            // Implementation field read code: FIELD_READ_LANG_CHARACTER_DECIMAL_DIGIT_NUMBER
            stack_push( value_create_byte( NATIVE_FIELD_VALUE_LANG_CHARACTER_DECIMAL_DIGIT_NUMBER ) );
            break;

        case NATIVE_FIELD_LANG_CHARACTER_DIRECTIONALITY_ARABIC_NUMBER:
            // static byte DIRECTIONALITY_ARABIC_NUMBER
            // Implementation field read code: FIELD_READ_LANG_CHARACTER_DIRECTIONALITY_ARABIC_NUMBER
            stack_push( value_create_byte( NATIVE_FIELD_VALUE_LANG_CHARACTER_DIRECTIONALITY_ARABIC_NUMBER ) );
            break;

        case NATIVE_FIELD_LANG_CHARACTER_DIRECTIONALITY_BOUNDARY_NEUTRAL:
            // static byte DIRECTIONALITY_BOUNDARY_NEUTRAL
            // Implementation field read code: FIELD_READ_LANG_CHARACTER_DIRECTIONALITY_BOUNDARY_NEUTRAL
            stack_push( value_create_byte( NATIVE_FIELD_VALUE_LANG_CHARACTER_DIRECTIONALITY_BOUNDARY_NEUTRAL ) );
            break;

        case NATIVE_FIELD_LANG_CHARACTER_DIRECTIONALITY_COMMON_NUMBER_SEPARATOR:
            // static byte DIRECTIONALITY_COMMON_NUMBER_SEPARATOR
            // Implementation field read code: FIELD_READ_LANG_CHARACTER_DIRECTIONALITY_COMMON_NUMBER_SEPARATOR
            stack_push( value_create_byte( NATIVE_FIELD_VALUE_LANG_CHARACTER_DIRECTIONALITY_COMMON_NUMBER_SEPARATOR ) );
            break;

        case NATIVE_FIELD_LANG_CHARACTER_DIRECTIONALITY_EUROPEAN_NUMBER:
            // static byte DIRECTIONALITY_EUROPEAN_NUMBER
            // Implementation field read code: FIELD_READ_LANG_CHARACTER_DIRECTIONALITY_EUROPEAN_NUMBER
            stack_push( value_create_byte( NATIVE_FIELD_VALUE_LANG_CHARACTER_DIRECTIONALITY_EUROPEAN_NUMBER ) );
            break;

        case NATIVE_FIELD_LANG_CHARACTER_DIRECTIONALITY_EUROPEAN_NUMBER_SEPARATOR:
            // static byte DIRECTIONALITY_EUROPEAN_NUMBER_SEPARATOR
            // Implementation field read code: FIELD_READ_LANG_CHARACTER_DIRECTIONALITY_EUROPEAN_NUMBER_SEPARATOR
            stack_push( value_create_byte( NATIVE_FIELD_VALUE_LANG_CHARACTER_DIRECTIONALITY_EUROPEAN_NUMBER_SEPARATOR ) );
            break;

        case NATIVE_FIELD_LANG_CHARACTER_DIRECTIONALITY_EUROPEAN_NUMBER_TERMINATOR:
            // static byte DIRECTIONALITY_EUROPEAN_NUMBER_TERMINATOR
            // Implementation field read code: FIELD_READ_LANG_CHARACTER_DIRECTIONALITY_EUROPEAN_NUMBER_TERMINATOR
            stack_push( value_create_byte( NATIVE_FIELD_VALUE_LANG_CHARACTER_DIRECTIONALITY_EUROPEAN_NUMBER_TERMINATOR ) );
            break;

        case NATIVE_FIELD_LANG_CHARACTER_DIRECTIONALITY_LEFT_TO_RIGHT:
            // static byte DIRECTIONALITY_LEFT_TO_RIGHT
            // Implementation field read code: FIELD_READ_LANG_CHARACTER_DIRECTIONALITY_LEFT_TO_RIGHT
            stack_push( value_create_byte( NATIVE_FIELD_VALUE_LANG_CHARACTER_DIRECTIONALITY_LEFT_TO_RIGHT ) );
            break;

        case NATIVE_FIELD_LANG_CHARACTER_DIRECTIONALITY_LEFT_TO_RIGHT_EMBEDDING:
            // static byte DIRECTIONALITY_LEFT_TO_RIGHT_EMBEDDING
            // Implementation field read code: FIELD_READ_LANG_CHARACTER_DIRECTIONALITY_LEFT_TO_RIGHT_EMBEDDING
            stack_push( value_create_byte( NATIVE_FIELD_VALUE_LANG_CHARACTER_DIRECTIONALITY_LEFT_TO_RIGHT_EMBEDDING ) );
            break;

        case NATIVE_FIELD_LANG_CHARACTER_DIRECTIONALITY_LEFT_TO_RIGHT_OVERRIDE:
            // static byte DIRECTIONALITY_LEFT_TO_RIGHT_OVERRIDE
            // Implementation field read code: FIELD_READ_LANG_CHARACTER_DIRECTIONALITY_LEFT_TO_RIGHT_OVERRIDE
            stack_push( value_create_byte( NATIVE_FIELD_VALUE_LANG_CHARACTER_DIRECTIONALITY_LEFT_TO_RIGHT_OVERRIDE ) );
            break;

        case NATIVE_FIELD_LANG_CHARACTER_DIRECTIONALITY_NONSPACING_MARK:
            // static byte DIRECTIONALITY_NONSPACING_MARK
            // Implementation field read code: FIELD_READ_LANG_CHARACTER_DIRECTIONALITY_NONSPACING_MARK
            stack_push( value_create_byte( NATIVE_FIELD_VALUE_LANG_CHARACTER_DIRECTIONALITY_NONSPACING_MARK ) );
            break;

        case NATIVE_FIELD_LANG_CHARACTER_DIRECTIONALITY_OTHER_NEUTRALS:
            // static byte DIRECTIONALITY_OTHER_NEUTRALS
            // Implementation field read code: FIELD_READ_LANG_CHARACTER_DIRECTIONALITY_OTHER_NEUTRALS
            stack_push( value_create_byte( NATIVE_FIELD_VALUE_LANG_CHARACTER_DIRECTIONALITY_OTHER_NEUTRALS ) );
            break;

        case NATIVE_FIELD_LANG_CHARACTER_DIRECTIONALITY_PARAGRAPH_SEPARATOR:
            // static byte DIRECTIONALITY_PARAGRAPH_SEPARATOR
            // Implementation field read code: FIELD_READ_LANG_CHARACTER_DIRECTIONALITY_PARAGRAPH_SEPARATOR
            stack_push( value_create_byte( NATIVE_FIELD_VALUE_LANG_CHARACTER_DIRECTIONALITY_PARAGRAPH_SEPARATOR ) );
            break;

        case NATIVE_FIELD_LANG_CHARACTER_DIRECTIONALITY_POP_DIRECTIONAL_FORMAT:
            // static byte DIRECTIONALITY_POP_DIRECTIONAL_FORMAT
            // Implementation field read code: FIELD_READ_LANG_CHARACTER_DIRECTIONALITY_POP_DIRECTIONAL_FORMAT
            stack_push( value_create_byte( NATIVE_FIELD_VALUE_LANG_CHARACTER_DIRECTIONALITY_POP_DIRECTIONAL_FORMAT ) );
            break;

        case NATIVE_FIELD_LANG_CHARACTER_DIRECTIONALITY_RIGHT_TO_LEFT:
            // static byte DIRECTIONALITY_RIGHT_TO_LEFT
            // Implementation field read code: FIELD_READ_LANG_CHARACTER_DIRECTIONALITY_RIGHT_TO_LEFT
            stack_push( value_create_byte( NATIVE_FIELD_VALUE_LANG_CHARACTER_DIRECTIONALITY_RIGHT_TO_LEFT ) );
            break;

        case NATIVE_FIELD_LANG_CHARACTER_DIRECTIONALITY_RIGHT_TO_LEFT_ARABIC:
            // static byte DIRECTIONALITY_RIGHT_TO_LEFT_ARABIC
            // Implementation field read code: FIELD_READ_LANG_CHARACTER_DIRECTIONALITY_RIGHT_TO_LEFT_ARABIC
            stack_push( value_create_byte( NATIVE_FIELD_VALUE_LANG_CHARACTER_DIRECTIONALITY_RIGHT_TO_LEFT_ARABIC ) );
            break;

        case NATIVE_FIELD_LANG_CHARACTER_DIRECTIONALITY_RIGHT_TO_LEFT_EMBEDDING:
            // static byte DIRECTIONALITY_RIGHT_TO_LEFT_EMBEDDING
            // Implementation field read code: FIELD_READ_LANG_CHARACTER_DIRECTIONALITY_RIGHT_TO_LEFT_EMBEDDING
            stack_push( value_create_byte( NATIVE_FIELD_VALUE_LANG_CHARACTER_DIRECTIONALITY_RIGHT_TO_LEFT_EMBEDDING ) );
            break;

        case NATIVE_FIELD_LANG_CHARACTER_DIRECTIONALITY_RIGHT_TO_LEFT_OVERRIDE:
            // static byte DIRECTIONALITY_RIGHT_TO_LEFT_OVERRIDE
            // Implementation field read code: FIELD_READ_LANG_CHARACTER_DIRECTIONALITY_RIGHT_TO_LEFT_OVERRIDE
            stack_push( value_create_byte( NATIVE_FIELD_VALUE_LANG_CHARACTER_DIRECTIONALITY_RIGHT_TO_LEFT_OVERRIDE ) );
            break;

        case NATIVE_FIELD_LANG_CHARACTER_DIRECTIONALITY_SEGMENT_SEPARATOR:
            // static byte DIRECTIONALITY_SEGMENT_SEPARATOR
            // Implementation field read code: FIELD_READ_LANG_CHARACTER_DIRECTIONALITY_SEGMENT_SEPARATOR
            stack_push( value_create_byte( NATIVE_FIELD_VALUE_LANG_CHARACTER_DIRECTIONALITY_SEGMENT_SEPARATOR ) );
            break;

        case NATIVE_FIELD_LANG_CHARACTER_DIRECTIONALITY_UNDEFINED:
            // static byte DIRECTIONALITY_UNDEFINED
            // Implementation field read code: FIELD_READ_LANG_CHARACTER_DIRECTIONALITY_UNDEFINED
            stack_push( value_create_byte( NATIVE_FIELD_VALUE_LANG_CHARACTER_DIRECTIONALITY_UNDEFINED ) );
            break;

        case NATIVE_FIELD_LANG_CHARACTER_DIRECTIONALITY_WHITESPACE:
            // static byte DIRECTIONALITY_WHITESPACE
            // Implementation field read code: FIELD_READ_LANG_CHARACTER_DIRECTIONALITY_WHITESPACE
            stack_push( value_create_byte( NATIVE_FIELD_VALUE_LANG_CHARACTER_DIRECTIONALITY_WHITESPACE ) );
            break;

        case NATIVE_FIELD_LANG_CHARACTER_ENCLOSING_MARK:
            // static byte ENCLOSING_MARK
            // Implementation field read code: FIELD_READ_LANG_CHARACTER_ENCLOSING_MARK
            stack_push( value_create_byte( NATIVE_FIELD_VALUE_LANG_CHARACTER_ENCLOSING_MARK ) );
            break;

        case NATIVE_FIELD_LANG_CHARACTER_END_PUNCTUATION:
            // static byte END_PUNCTUATION
            // Implementation field read code: FIELD_READ_LANG_CHARACTER_END_PUNCTUATION
            stack_push( value_create_byte( NATIVE_FIELD_VALUE_LANG_CHARACTER_END_PUNCTUATION ) );
            break;

        case NATIVE_FIELD_LANG_CHARACTER_FINAL_QUOTE_PUNCTUATION:
            // static byte FINAL_QUOTE_PUNCTUATION
            // Implementation field read code: FIELD_READ_LANG_CHARACTER_FINAL_QUOTE_PUNCTUATION
            stack_push( value_create_byte( NATIVE_FIELD_VALUE_LANG_CHARACTER_FINAL_QUOTE_PUNCTUATION ) );
            break;

        case NATIVE_FIELD_LANG_CHARACTER_FORMAT:
            // static byte FORMAT
            // Implementation field read code: FIELD_READ_LANG_CHARACTER_FORMAT
            stack_push( value_create_byte( NATIVE_FIELD_VALUE_LANG_CHARACTER_FORMAT ) );
            break;

        case NATIVE_FIELD_LANG_CHARACTER_INITIAL_QUOTE_PUNCTUATION:
            // static byte INITIAL_QUOTE_PUNCTUATION
            // Implementation field read code: FIELD_READ_LANG_CHARACTER_INITIAL_QUOTE_PUNCTUATION
            stack_push( value_create_byte( NATIVE_FIELD_VALUE_LANG_CHARACTER_INITIAL_QUOTE_PUNCTUATION ) );
            break;

        case NATIVE_FIELD_LANG_CHARACTER_LETTER_NUMBER:
            // static byte LETTER_NUMBER
            // Implementation field read code: FIELD_READ_LANG_CHARACTER_LETTER_NUMBER
            stack_push( value_create_byte( NATIVE_FIELD_VALUE_LANG_CHARACTER_LETTER_NUMBER ) );
            break;

        case NATIVE_FIELD_LANG_CHARACTER_LINE_SEPARATOR:
            // static byte LINE_SEPARATOR
            // Implementation field read code: FIELD_READ_LANG_CHARACTER_LINE_SEPARATOR
            stack_push( value_create_byte( NATIVE_FIELD_VALUE_LANG_CHARACTER_LINE_SEPARATOR ) );
            break;

        case NATIVE_FIELD_LANG_CHARACTER_LOWERCASE_LETTER:
            // static byte LOWERCASE_LETTER
            // Implementation field read code: FIELD_READ_LANG_CHARACTER_LOWERCASE_LETTER
            stack_push( value_create_byte( NATIVE_FIELD_VALUE_LANG_CHARACTER_LOWERCASE_LETTER ) );
            break;

        case NATIVE_FIELD_LANG_CHARACTER_MATH_SYMBOL:
            // static byte MATH_SYMBOL
            // Implementation field read code: FIELD_READ_LANG_CHARACTER_MATH_SYMBOL
            stack_push( value_create_byte( NATIVE_FIELD_VALUE_LANG_CHARACTER_MATH_SYMBOL ) );
            break;

        case NATIVE_FIELD_LANG_CHARACTER_MAX_CODE_POINT:
            // static int MAX_CODE_POINT
            // Implementation field read code: FIELD_READ_LANG_CHARACTER_MAX_CODE_POINT
            stack_push( value_create_int( NATIVE_FIELD_VALUE_LANG_CHARACTER_MAX_CODE_POINT ) );
            break;

        case NATIVE_FIELD_LANG_CHARACTER_MAX_HIGH_SURROGATE:
            // static char MAX_HIGH_SURROGATE
            // Implementation field read code: FIELD_READ_LANG_CHARACTER_MAX_HIGH_SURROGATE
            stack_push( value_create_character( NATIVE_FIELD_VALUE_LANG_CHARACTER_MAX_HIGH_SURROGATE ) );
            break;

        case NATIVE_FIELD_LANG_CHARACTER_MAX_LOW_SURROGATE:
            // static char MAX_LOW_SURROGATE
            // Implementation field read code: FIELD_READ_LANG_CHARACTER_MAX_LOW_SURROGATE
            stack_push( value_create_character( NATIVE_FIELD_VALUE_LANG_CHARACTER_MAX_LOW_SURROGATE ) );
            break;

        case NATIVE_FIELD_LANG_CHARACTER_MAX_RADIX:
            // static int MAX_RADIX
            // Implementation field read code: FIELD_READ_LANG_CHARACTER_MAX_RADIX
            stack_push( value_create_int( NATIVE_FIELD_VALUE_LANG_CHARACTER_MAX_RADIX ) );
            break;

        case NATIVE_FIELD_LANG_CHARACTER_MAX_SURROGATE:
            // static char MAX_SURROGATE
            // Implementation field read code: FIELD_READ_LANG_CHARACTER_MAX_SURROGATE
            stack_push( value_create_character( NATIVE_FIELD_VALUE_LANG_CHARACTER_MAX_SURROGATE ) );
            break;

        case NATIVE_FIELD_LANG_CHARACTER_MAX_VALUE:
            // static char MAX_VALUE
            // Implementation field read code: FIELD_READ_LANG_CHARACTER_MAX_VALUE
            stack_push( value_create_character( NATIVE_FIELD_VALUE_LANG_CHARACTER_MAX_VALUE ) );
            break;

        case NATIVE_FIELD_LANG_CHARACTER_MIN_CODE_POINT:
            // static int MIN_CODE_POINT
            // Implementation field read code: FIELD_READ_LANG_CHARACTER_MIN_CODE_POINT
            stack_push( value_create_int( NATIVE_FIELD_VALUE_LANG_CHARACTER_MIN_CODE_POINT ) );
            break;

        case NATIVE_FIELD_LANG_CHARACTER_MIN_HIGH_SURROGATE:
            // static char MIN_HIGH_SURROGATE
            // Implementation field read code: FIELD_READ_LANG_CHARACTER_MIN_HIGH_SURROGATE
            stack_push( value_create_character( NATIVE_FIELD_VALUE_LANG_CHARACTER_MIN_HIGH_SURROGATE ) );
            break;

        case NATIVE_FIELD_LANG_CHARACTER_MIN_LOW_SURROGATE:
            // static char MIN_LOW_SURROGATE
            // Implementation field read code: FIELD_READ_LANG_CHARACTER_MIN_LOW_SURROGATE
            stack_push( value_create_character( NATIVE_FIELD_VALUE_LANG_CHARACTER_MIN_LOW_SURROGATE ) );
            break;

        case NATIVE_FIELD_LANG_CHARACTER_MIN_RADIX:
            // static int MIN_RADIX
            // Implementation field read code: FIELD_READ_LANG_CHARACTER_MIN_RADIX
            stack_push( value_create_int( NATIVE_FIELD_VALUE_LANG_CHARACTER_MIN_RADIX ) );
            break;

        case NATIVE_FIELD_LANG_CHARACTER_MIN_SUPPLEMENTARY_CODE_POINT:
            // static int MIN_SUPPLEMENTARY_CODE_POINT
            // Implementation field read code: FIELD_READ_LANG_CHARACTER_MIN_SUPPLEMENTARY_CODE_POINT
            stack_push( value_create_int( NATIVE_FIELD_VALUE_LANG_CHARACTER_MIN_SUPPLEMENTARY_CODE_POINT ) );
            break;

        case NATIVE_FIELD_LANG_CHARACTER_MIN_SURROGATE:
            // static char MIN_SURROGATE
            // Implementation field read code: FIELD_READ_LANG_CHARACTER_MIN_SURROGATE
            stack_push( value_create_character( NATIVE_FIELD_VALUE_LANG_CHARACTER_MIN_SURROGATE ) );
            break;

        case NATIVE_FIELD_LANG_CHARACTER_MIN_VALUE:
            // static char MIN_VALUE
            // Implementation field read code: FIELD_READ_LANG_CHARACTER_MIN_VALUE
            stack_push( value_create_character( NATIVE_FIELD_VALUE_LANG_CHARACTER_MIN_VALUE ) );
            break;

        case NATIVE_FIELD_LANG_CHARACTER_MODIFIER_LETTER:
            // static byte MODIFIER_LETTER
            // Implementation field read code: FIELD_READ_LANG_CHARACTER_MODIFIER_LETTER
            stack_push( value_create_byte( NATIVE_FIELD_VALUE_LANG_CHARACTER_MODIFIER_LETTER ) );
            break;

        case NATIVE_FIELD_LANG_CHARACTER_MODIFIER_SYMBOL:
            // static byte MODIFIER_SYMBOL
            // Implementation field read code: FIELD_READ_LANG_CHARACTER_MODIFIER_SYMBOL
            stack_push( value_create_byte( NATIVE_FIELD_VALUE_LANG_CHARACTER_MODIFIER_SYMBOL ) );
            break;

        case NATIVE_FIELD_LANG_CHARACTER_NON_SPACING_MARK:
            // static byte NON_SPACING_MARK
            // Implementation field read code: FIELD_READ_LANG_CHARACTER_NON_SPACING_MARK
            stack_push( value_create_byte( NATIVE_FIELD_VALUE_LANG_CHARACTER_NON_SPACING_MARK ) );
            break;

        case NATIVE_FIELD_LANG_CHARACTER_OTHER_LETTER:
            // static byte OTHER_LETTER
            // Implementation field read code: FIELD_READ_LANG_CHARACTER_OTHER_LETTER
            stack_push( value_create_byte( NATIVE_FIELD_VALUE_LANG_CHARACTER_OTHER_LETTER ) );
            break;

        case NATIVE_FIELD_LANG_CHARACTER_OTHER_NUMBER:
            // static byte OTHER_NUMBER
            // Implementation field read code: FIELD_READ_LANG_CHARACTER_OTHER_NUMBER
            stack_push( value_create_byte( NATIVE_FIELD_VALUE_LANG_CHARACTER_OTHER_NUMBER ) );
            break;

        case NATIVE_FIELD_LANG_CHARACTER_OTHER_PUNCTUATION:
            // static byte OTHER_PUNCTUATION
            // Implementation field read code: FIELD_READ_LANG_CHARACTER_OTHER_PUNCTUATION
            stack_push( value_create_byte( NATIVE_FIELD_VALUE_LANG_CHARACTER_OTHER_PUNCTUATION ) );
            break;

        case NATIVE_FIELD_LANG_CHARACTER_OTHER_SYMBOL:
            // static byte OTHER_SYMBOL
            // Implementation field read code: FIELD_READ_LANG_CHARACTER_OTHER_SYMBOL
            stack_push( value_create_byte( NATIVE_FIELD_VALUE_LANG_CHARACTER_OTHER_SYMBOL ) );
            break;

        case NATIVE_FIELD_LANG_CHARACTER_PARAGRAPH_SEPARATOR:
            // static byte PARAGRAPH_SEPARATOR
            // Implementation field read code: FIELD_READ_LANG_CHARACTER_PARAGRAPH_SEPARATOR
            stack_push( value_create_byte( NATIVE_FIELD_VALUE_LANG_CHARACTER_PARAGRAPH_SEPARATOR ) );
            break;

        case NATIVE_FIELD_LANG_CHARACTER_PRIVATE_USE:
            // static byte PRIVATE_USE
            // Implementation field read code: FIELD_READ_LANG_CHARACTER_PRIVATE_USE
            stack_push( value_create_byte( NATIVE_FIELD_VALUE_LANG_CHARACTER_PRIVATE_USE ) );
            break;

        case NATIVE_FIELD_LANG_CHARACTER_SIZE:
            // static int SIZE
            // Implementation field read code: FIELD_READ_LANG_CHARACTER_SIZE
            stack_push( value_create_int( NATIVE_FIELD_VALUE_LANG_CHARACTER_SIZE ) );
            break;

        case NATIVE_FIELD_LANG_CHARACTER_SPACE_SEPARATOR:
            // static byte SPACE_SEPARATOR
            // Implementation field read code: FIELD_READ_LANG_CHARACTER_SPACE_SEPARATOR
            stack_push( value_create_byte( NATIVE_FIELD_VALUE_LANG_CHARACTER_SPACE_SEPARATOR ) );
            break;

        case NATIVE_FIELD_LANG_CHARACTER_START_PUNCTUATION:
            // static byte START_PUNCTUATION
            // Implementation field read code: FIELD_READ_LANG_CHARACTER_START_PUNCTUATION
            stack_push( value_create_byte( NATIVE_FIELD_VALUE_LANG_CHARACTER_START_PUNCTUATION ) );
            break;

        case NATIVE_FIELD_LANG_CHARACTER_SURROGATE:
            // static byte SURROGATE
            // Implementation field read code: FIELD_READ_LANG_CHARACTER_SURROGATE
            stack_push( value_create_byte( NATIVE_FIELD_VALUE_LANG_CHARACTER_SURROGATE ) );
            break;

        case NATIVE_FIELD_LANG_CHARACTER_TITLECASE_LETTER:
            // static byte TITLECASE_LETTER
            // Implementation field read code: FIELD_READ_LANG_CHARACTER_TITLECASE_LETTER
            stack_push( value_create_byte( NATIVE_FIELD_VALUE_LANG_CHARACTER_TITLECASE_LETTER ) );
            break;

        case NATIVE_FIELD_LANG_CHARACTER_UNASSIGNED:
            // static byte UNASSIGNED
            // Implementation field read code: FIELD_READ_LANG_CHARACTER_UNASSIGNED
            stack_push( value_create_byte( NATIVE_FIELD_VALUE_LANG_CHARACTER_UNASSIGNED ) );
            break;

        case NATIVE_FIELD_LANG_CHARACTER_UPPERCASE_LETTER:
            // static byte UPPERCASE_LETTER
            // Implementation field read code: FIELD_READ_LANG_CHARACTER_UPPERCASE_LETTER
            stack_push( value_create_byte( NATIVE_FIELD_VALUE_LANG_CHARACTER_UPPERCASE_LETTER ) );
            break;

        default: 
            exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
            break;
    }
}

void native_lang_character_invoke(uint16_t mref)
{
    switch( mref )
    {
        case NATIVE_LANG_CHARACTER_INIT_CHAR:
            native_method_lang_character_init_char();
            break;

        case NATIVE_LANG_CHARACTER_CHARCOUNT_INT:
            native_method_lang_character_charcount_int();
            break;

        case NATIVE_LANG_CHARACTER_CHARVALUE:
            native_method_lang_character_charvalue();
            break;

        case NATIVE_LANG_CHARACTER_CODEPOINTAT_ARRAY_CHAR_INT:
            native_method_lang_character_codepointat_array_char_int();
            break;

        case NATIVE_LANG_CHARACTER_CODEPOINTAT_ARRAY_CHAR_INT_INT:
            native_method_lang_character_codepointat_array_char_int_int();
            break;

        case NATIVE_LANG_CHARACTER_CODEPOINTAT_CHARSEQUENCE_INT:
            native_method_lang_character_codepointat_charsequence_int();
            break;

        case NATIVE_LANG_CHARACTER_CODEPOINTBEFORE_ARRAY_CHAR_INT:
            native_method_lang_character_codepointbefore_array_char_int();
            break;

        case NATIVE_LANG_CHARACTER_CODEPOINTBEFORE_ARRAY_CHAR_INT_INT:
            native_method_lang_character_codepointbefore_array_char_int_int();
            break;

        case NATIVE_LANG_CHARACTER_CODEPOINTBEFORE_CHARSEQUENCE_INT:
            native_method_lang_character_codepointbefore_charsequence_int();
            break;

        case NATIVE_LANG_CHARACTER_CODEPOINTCOUNT_ARRAY_CHAR_INT_INT:
            native_method_lang_character_codepointcount_array_char_int_int();
            break;

        case NATIVE_LANG_CHARACTER_CODEPOINTCOUNT_CHARSEQUENCE_INT_INT:
            native_method_lang_character_codepointcount_charsequence_int_int();
            break;

        case NATIVE_LANG_CHARACTER_COMPARETO_CHARACTER:
            native_method_lang_character_compareto_character();
            break;

        case NATIVE_LANG_CHARACTER_DIGIT_CHAR_INT:
            native_method_lang_character_digit_char_int();
            break;

        case NATIVE_LANG_CHARACTER_DIGIT_INT_INT:
            native_method_lang_character_digit_int_int();
            break;

        case NATIVE_LANG_CHARACTER_EQUALS_OBJECT:
            native_method_lang_character_equals_object();
            break;

        case NATIVE_LANG_CHARACTER_FORDIGIT_INT_INT:
            native_method_lang_character_fordigit_int_int();
            break;

        case NATIVE_LANG_CHARACTER_GETDIRECTIONALITY_CHAR:
            native_method_lang_character_getdirectionality_char();
            break;

        case NATIVE_LANG_CHARACTER_GETDIRECTIONALITY_INT:
            native_method_lang_character_getdirectionality_int();
            break;

        case NATIVE_LANG_CHARACTER_GETNUMERICVALUE_CHAR:
            native_method_lang_character_getnumericvalue_char();
            break;

        case NATIVE_LANG_CHARACTER_GETNUMERICVALUE_INT:
            native_method_lang_character_getnumericvalue_int();
            break;

        case NATIVE_LANG_CHARACTER_GETTYPE_CHAR:
            native_method_lang_character_gettype_char();
            break;

        case NATIVE_LANG_CHARACTER_GETTYPE_INT:
            native_method_lang_character_gettype_int();
            break;

        case NATIVE_LANG_CHARACTER_HASHCODE:
            native_method_lang_character_hashcode();
            break;

        case NATIVE_LANG_CHARACTER_ISDEFINED_CHAR:
            native_method_lang_character_isdefined_char();
            break;

        case NATIVE_LANG_CHARACTER_ISDEFINED_INT:
            native_method_lang_character_isdefined_int();
            break;

        case NATIVE_LANG_CHARACTER_ISDIGIT_CHAR:
            native_method_lang_character_isdigit_char();
            break;

        case NATIVE_LANG_CHARACTER_ISDIGIT_INT:
            native_method_lang_character_isdigit_int();
            break;

        case NATIVE_LANG_CHARACTER_ISHIGHSURROGATE_CHAR:
            native_method_lang_character_ishighsurrogate_char();
            break;

        case NATIVE_LANG_CHARACTER_ISIDENTIFIERIGNORABLE_CHAR:
            native_method_lang_character_isidentifierignorable_char();
            break;

        case NATIVE_LANG_CHARACTER_ISIDENTIFIERIGNORABLE_INT:
            native_method_lang_character_isidentifierignorable_int();
            break;

        case NATIVE_LANG_CHARACTER_ISISOCONTROL_CHAR:
            native_method_lang_character_isisocontrol_char();
            break;

        case NATIVE_LANG_CHARACTER_ISISOCONTROL_INT:
            native_method_lang_character_isisocontrol_int();
            break;

        case NATIVE_LANG_CHARACTER_ISJAVAIDENTIFIERPART_CHAR:
            native_method_lang_character_isjavaidentifierpart_char();
            break;

        case NATIVE_LANG_CHARACTER_ISJAVAIDENTIFIERPART_INT:
            native_method_lang_character_isjavaidentifierpart_int();
            break;

        case NATIVE_LANG_CHARACTER_ISJAVAIDENTIFIERSTART_CHAR:
            native_method_lang_character_isjavaidentifierstart_char();
            break;

        case NATIVE_LANG_CHARACTER_ISJAVAIDENTIFIERSTART_INT:
            native_method_lang_character_isjavaidentifierstart_int();
            break;

        case NATIVE_LANG_CHARACTER_ISJAVALETTER_CHAR:
            native_method_lang_character_isjavaletter_char();
            break;

        case NATIVE_LANG_CHARACTER_ISJAVALETTERORDIGIT_CHAR:
            native_method_lang_character_isjavaletterordigit_char();
            break;

        case NATIVE_LANG_CHARACTER_ISLETTER_CHAR:
            native_method_lang_character_isletter_char();
            break;

        case NATIVE_LANG_CHARACTER_ISLETTER_INT:
            native_method_lang_character_isletter_int();
            break;

        case NATIVE_LANG_CHARACTER_ISLETTERORDIGIT_CHAR:
            native_method_lang_character_isletterordigit_char();
            break;

        case NATIVE_LANG_CHARACTER_ISLETTERORDIGIT_INT:
            native_method_lang_character_isletterordigit_int();
            break;

        case NATIVE_LANG_CHARACTER_ISLOWERCASE_CHAR:
            native_method_lang_character_islowercase_char();
            break;

        case NATIVE_LANG_CHARACTER_ISLOWERCASE_INT:
            native_method_lang_character_islowercase_int();
            break;

        case NATIVE_LANG_CHARACTER_ISLOWSURROGATE_CHAR:
            native_method_lang_character_islowsurrogate_char();
            break;

        case NATIVE_LANG_CHARACTER_ISMIRRORED_CHAR:
            native_method_lang_character_ismirrored_char();
            break;

        case NATIVE_LANG_CHARACTER_ISMIRRORED_INT:
            native_method_lang_character_ismirrored_int();
            break;

        case NATIVE_LANG_CHARACTER_ISSPACE_CHAR:
            native_method_lang_character_isspace_char();
            break;

        case NATIVE_LANG_CHARACTER_ISSPACECHAR_CHAR:
            native_method_lang_character_isspacechar_char();
            break;

        case NATIVE_LANG_CHARACTER_ISSPACECHAR_INT:
            native_method_lang_character_isspacechar_int();
            break;

        case NATIVE_LANG_CHARACTER_ISSUPPLEMENTARYCODEPOINT_INT:
            native_method_lang_character_issupplementarycodepoint_int();
            break;

        case NATIVE_LANG_CHARACTER_ISSURROGATEPAIR_CHAR_CHAR:
            native_method_lang_character_issurrogatepair_char_char();
            break;

        case NATIVE_LANG_CHARACTER_ISTITLECASE_CHAR:
            native_method_lang_character_istitlecase_char();
            break;

        case NATIVE_LANG_CHARACTER_ISTITLECASE_INT:
            native_method_lang_character_istitlecase_int();
            break;

        case NATIVE_LANG_CHARACTER_ISUNICODEIDENTIFIERPART_CHAR:
            native_method_lang_character_isunicodeidentifierpart_char();
            break;

        case NATIVE_LANG_CHARACTER_ISUNICODEIDENTIFIERPART_INT:
            native_method_lang_character_isunicodeidentifierpart_int();
            break;

        case NATIVE_LANG_CHARACTER_ISUNICODEIDENTIFIERSTART_CHAR:
            native_method_lang_character_isunicodeidentifierstart_char();
            break;

        case NATIVE_LANG_CHARACTER_ISUNICODEIDENTIFIERSTART_INT:
            native_method_lang_character_isunicodeidentifierstart_int();
            break;

        case NATIVE_LANG_CHARACTER_ISUPPERCASE_CHAR:
            native_method_lang_character_isuppercase_char();
            break;

        case NATIVE_LANG_CHARACTER_ISUPPERCASE_INT:
            native_method_lang_character_isuppercase_int();
            break;

        case NATIVE_LANG_CHARACTER_ISVALIDCODEPOINT_INT:
            native_method_lang_character_isvalidcodepoint_int();
            break;

        case NATIVE_LANG_CHARACTER_ISWHITESPACE_CHAR:
            native_method_lang_character_iswhitespace_char();
            break;

        case NATIVE_LANG_CHARACTER_ISWHITESPACE_INT:
            native_method_lang_character_iswhitespace_int();
            break;

        case NATIVE_LANG_CHARACTER_OFFSETBYCODEPOINTS_ARRAY_CHAR_INT_INT_INT_INT:
            native_method_lang_character_offsetbycodepoints_array_char_int_int_int_int();
            break;

        case NATIVE_LANG_CHARACTER_OFFSETBYCODEPOINTS_CHARSEQUENCE_INT_INT:
            native_method_lang_character_offsetbycodepoints_charsequence_int_int();
            break;

        case NATIVE_LANG_CHARACTER_REVERSEBYTES_CHAR:
            native_method_lang_character_reversebytes_char();
            break;

        case NATIVE_LANG_CHARACTER_TOCHARS_INT:
            native_method_lang_character_tochars_int();
            break;

        case NATIVE_LANG_CHARACTER_TOCHARS_INT_ARRAY_CHAR_INT:
            native_method_lang_character_tochars_int_array_char_int();
            break;

        case NATIVE_LANG_CHARACTER_TOCODEPOINT_CHAR_CHAR:
            native_method_lang_character_tocodepoint_char_char();
            break;

        case NATIVE_LANG_CHARACTER_TOLOWERCASE_CHAR:
            native_method_lang_character_tolowercase_char();
            break;

        case NATIVE_LANG_CHARACTER_TOLOWERCASE_INT:
            native_method_lang_character_tolowercase_int();
            break;

        case NATIVE_LANG_CHARACTER_TOSTRING:
            native_method_lang_character_tostring();
            break;

        case NATIVE_LANG_CHARACTER_TOSTRING_CHAR:
            native_method_lang_character_tostring_char();
            break;

        case NATIVE_LANG_CHARACTER_TOTITLECASE_CHAR:
            native_method_lang_character_totitlecase_char();
            break;

        case NATIVE_LANG_CHARACTER_TOTITLECASE_INT:
            native_method_lang_character_totitlecase_int();
            break;

        case NATIVE_LANG_CHARACTER_TOUPPERCASE_CHAR:
            native_method_lang_character_touppercase_char();
            break;

        case NATIVE_LANG_CHARACTER_TOUPPERCASE_INT:
            native_method_lang_character_touppercase_int();
            break;

        case NATIVE_LANG_CHARACTER_VALUEOF_CHAR:
            native_method_lang_character_valueof_char();
            break;

        default:
            exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
            break;

    }
}


