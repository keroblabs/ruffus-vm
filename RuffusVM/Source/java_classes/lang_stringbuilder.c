#include "lang_stringbuilder.h"
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

// New method implementation
object_t native_lang_stringbuilder_new_value( char * value )
{
	object_t object;

    object = strings_create( value );

	return object;
}

object_t native_lang_stringbuilder_new( void )
{
    // return( object_create( GET_CLASS_REF( NATIVE_CLASS_LANG_STRINGBUILDER ), T_CLASS, NATIVE_LANG_STRINGBUILDER_TOTAL_FIELDS ) );
	return( strings_create( "" ) );
}

///////////////////////////////////////////////////////////////////////////

void native_method_lang_stringbuilder_init( void )
{
    // StringBuilder()
    // Constructs a string builder with no characters in it and 
    // an initial capacity of 16 characters. 
    // Implementation code: 1040C365
    object_t object;

    object = stack_peek(0);

    // put your code here
	strings_copy( object, "" );

	stack_remove(1);
}

void native_method_lang_stringbuilder_init_charsequence( void )
{
    // StringBuilder(CharSequence seq)
    // Constructs a string builder that contains the same characters 
    // as the specified CharSequence. 
    // Implementation code: 7E699623
    object_t charsequence_seq;
    object_t object;

    charsequence_seq = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_lang_stringbuilder_init_int( void )
{
    // StringBuilder(int capacity)
    // Constructs a string builder with no characters in it and 
    // an initial capacity specified by the capacity argument. 
    // Implementation code: 25B38906
    object_t int_capacity;
    object_t object;

    int_capacity = stack_peek(0);
    object = stack_peek(1);

    // put your code here
	strings_copy( object, "" );

	stack_remove(2);
}

void native_method_lang_stringbuilder_init_string( void )
{
    // StringBuilder(String str)
    // Constructs a string builder initialized to the contents 
    // of the specified string. 
    // Implementation code: CFF9EAA4
    object_t string_str;
    object_t object;

    string_str = stack_peek(0);
    object = stack_peek(1);

    // put your code here
	strings_copy( object, strings_get_text_ptr( string_str ) );

	stack_remove(2);
}

///////////////////////////////////////////////////////////////////////////

void native_method_lang_stringbuilder_append_boolean( void )
{
    // StringBuilder append(boolean b)
    // Appends the string representation of the boolean argument 
    // to the sequence. 
    // Implementation code: 0962B598
    object_t boolean_b;
    object_t object;

    boolean_b = stack_peek(0);
    object = stack_peek(1);

    // put your code here
    strings_concat( object, native_value_to_string( boolean_b ) );

	// keep object in the stack
	stack_remove(1);
}

void native_method_lang_stringbuilder_append_char( void )
{
    // StringBuilder append(char c)
    // Appends the string representation of the char argument to 
    // this sequence. 
    // Implementation code: 51E9A9AC
    object_t char_c;
    object_t object;

    char_c = stack_peek(0);
    object = stack_peek(1);

    // put your code here
    strings_concat( object, native_value_to_string( char_c ) );

	// keep object in the stack
	stack_remove(1);
}

void native_method_lang_stringbuilder_append_array_char( void )
{
    // StringBuilder append(char[] str)
    // Appends the string representation of the char array argument 
    // to this sequence. 
    // Implementation code: 7A326420
    object_t char_array_str;
    object_t object;

    char_array_str = stack_peek(0);
    object = stack_peek(1);

    // put your code here
    strings_concat( object, strings_get_text_ptr( char_array_str ) );

	// keep object in the stack
	stack_remove(1);
}

void native_method_lang_stringbuilder_append_array_char_int_int( void )
{
    // StringBuilder append(char[] str, int offset, int len)
    // Appends the string representation of a subarray of the char 
    // array argument to this sequence. 
    // Implementation code: C97CB5AD
    object_t char_array_str;
    object_t int_offset;
    object_t int_len;
    object_t object;

    int_len = stack_pop();
    int_offset = stack_pop();
    char_array_str = stack_pop();
    object = stack_peek(0);

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_lang_stringbuilder_append_charsequence( void )
{
    // StringBuilder append(CharSequence s)
    // Appends the specified character sequence to this Appendable. 
    // Implementation code: D80398E0
    object_t charsequence_s;
    object_t object;

    charsequence_s = stack_pop();
    object = stack_peek(0);

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_lang_stringbuilder_append_charsequence_int_int( void )
{
    // StringBuilder append(CharSequence s, int start, int end)
    // Appends a subsequence of the specified CharSequence to this 
    // sequence. 
    // Implementation code: 50E66147
    object_t charsequence_s;
    object_t int_start;
    object_t int_end;
    object_t object;

    int_end = stack_pop();
    int_start = stack_pop();
    charsequence_s = stack_pop();
    object = stack_peek(0);

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_lang_stringbuilder_append_double( void )
{
    // StringBuilder append(double d)
    // Appends the string representation of the double argument 
    // to this sequence. 
    // Implementation code: 2F192ADA
    object_t double_d;
    object_t object;

    double_d = stack_peek(0);
    object = stack_peek(1);

    // put your code here
    strings_concat( object, native_value_to_string( double_d ) );

	// keep object in the stack
	stack_remove(1);
}

void native_method_lang_stringbuilder_append_float( void )
{
    // StringBuilder append(float f)
    // Appends the string representation of the float argument 
    // to this sequence. 
    // Implementation code: AAC1F19B
    object_t float_f;
    object_t object;

    float_f = stack_peek(0);
    object = stack_peek(1);

    // put your code here
    strings_concat( object, native_value_to_string( float_f ) );

	// keep object in the stack
	stack_remove(1);
}

void native_method_lang_stringbuilder_append_int( void )
{
    // StringBuilder append(int i)
    // Appends the string representation of the int argument to 
    // this sequence. 
    // Implementation code: 320079A0
    object_t int_i;
    object_t object;

    int_i = stack_peek(0);
    object = stack_peek(1);

    // put your code here
    strings_concat( object, native_value_to_string( int_i ) );

	// keep object in the stack
	stack_remove(1);
}

void native_method_lang_stringbuilder_append_long( void )
{
    // StringBuilder append(long lng)
    // Appends the string representation of the long argument to 
    // this sequence. 
    // Implementation code: 9C40B80F
    object_t long_lng;
    object_t object;

    long_lng = stack_peek(0);
    object = stack_peek(1);

    // put your code here
    strings_concat( object, native_value_to_string( long_lng ) );

	// keep object in the stack
	stack_remove(1);
}

void native_method_lang_stringbuilder_append_object( void )
{
    // StringBuilder append(Object obj)
    // Appends the string representation of the Object argument. 
    // Implementation code: 56E0E712
    object_t object_obj;
    object_t object;

    object_obj = stack_peek(0);
    object = stack_peek(1);

    // put your code here
    strings_concat( object, native_value_to_string( object_obj ) );

	// keep the object in stack
	stack_remove(1);
}

void native_method_lang_stringbuilder_append_string( void )
{
    // StringBuilder append(String str)
    // Appends the specified string to this character sequence. 
    // Implementation code: EFB059E6
    object_t string_str;
    object_t object;

    string_str = stack_peek(0);
    object = stack_peek(1);

    // put your code here
    strings_concat( object, strings_get_text_ptr( string_str ) );

	// keep object in the stack
	stack_remove(1);
}

void native_method_lang_stringbuilder_append_stringbuffer( void )
{
    // StringBuilder append(StringBuffer sb)
    // Appends the specified StringBuffer to this sequence. 
    // Implementation code: B7C818CC
    object_t stringbuffer_sb;
    object_t object;

    stringbuffer_sb = stack_peek(0);
    object = stack_peek(1);

    // put your code here
    strings_concat( object, strings_get_text_ptr( stringbuffer_sb ) );

	// keep object in the stack
	stack_remove(1);
}

void native_method_lang_stringbuilder_appendcodepoint_int( void )
{
    // StringBuilder appendCodePoint(int codePoint)
    // Appends the string representation of the codePoint argument 
    // to this sequence. 
    // Implementation code: 0AB9928B
    object_t int_codepoint;
    object_t object;

    int_codepoint = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: StringBuilder
    stack_push( 0 );
}

void native_method_lang_stringbuilder_capacity( void )
{
    // int capacity()
    // Returns the current capacity. 
    // Implementation code: 96356A39
    object_t object;
    object_t ret_value;

    object = stack_peek(0);

    // put your code here
	ret_value = value_create_int( strings_get_capacity( object ) );

    // return type: int
	stack_remove(1);
	stack_push( ret_value );
}

void native_method_lang_stringbuilder_charat_int( void )
{
    // char charAt(int index)
    // Returns the char value in this sequence at the specified 
    // index. 
    // Implementation code: 5B298044
    object_t int_index;
    object_t object;
    object_t ret_value;

    int_index = stack_peek(0);
    object = stack_peek(1);

    // return type: char
	ret_value = native_string_char_at( object, value_get_int( int_index ) );

	stack_remove(2);
	stack_push( ret_value );
}

void native_method_lang_stringbuilder_codepointat_int( void )
{
    // int codePointAt(int index)
    // Returns the character (Unicode code point) at the specified 
    // index. 
    // Implementation code: E742ED13
    object_t int_index;
    object_t object;
    int32_t ret_value = 0;

    int_index = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push( value_create( &ret_value, T_INT ) );
}

void native_method_lang_stringbuilder_codepointbefore_int( void )
{
    // int codePointBefore(int index)
    // Returns the character (Unicode code point) before the specified 
    // index. 
    // Implementation code: 7FD47668
    object_t int_index;
    object_t object;
    int32_t ret_value = 0;

    int_index = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push( value_create( &ret_value, T_INT ) );
}

void native_method_lang_stringbuilder_codepointcount_int_int( void )
{
    // int codePointCount(int beginIndex, int endIndex)
    // Returns the number of Unicode code points in the specified 
    // text range of this sequence. 
    // Implementation code: 15BA578A
    object_t int_beginindex;
    object_t int_endindex;
    object_t object;
    int32_t ret_value = 0;

    int_endindex = stack_pop();
    int_beginindex = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push( value_create( &ret_value, T_INT ) );
}

void native_method_lang_stringbuilder_delete_int_int( void )
{
    // StringBuilder delete(int start, int end)
    // Removes the characters in a substring of this sequence. 
    // Implementation code: 41C0649B
    object_t int_start;
    object_t int_end;
    object_t object;

    int_end = stack_peek(0);
    int_start = stack_peek(1);
    object = stack_peek(2);

    // put your code here
    strings_delete( object, value_get_int( int_start ), value_get_int( int_end ) );

	// keep object in the stack
	stack_remove(2);
}

void native_method_lang_stringbuilder_deletecharat_int( void )
{
    // StringBuilder deleteCharAt(int index)
    // Removes the char at the specified position in this sequence. 
    // Implementation code: 53ED73F3
    object_t int_index;
    object_t object;

    int_index = stack_peek(0);
    object = stack_peek(1);

    // put your code here
    strings_delete( object, value_get_int( int_index ), 1 );

	// keep object in the stack
	stack_remove(1);
}

void native_method_lang_stringbuilder_ensurecapacity_int( void )
{
    // void ensureCapacity(int minimumCapacity)
    // Ensures that the capacity is at least equal to the specified 
    // minimum. 
    // Implementation code: E59E4A22
    object_t int_minimumcapacity;
    object_t object;

    int_minimumcapacity = stack_pop();
    object = stack_pop();

    // put your code here
    //exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_lang_stringbuilder_getchars_int_int_array_char_int( void )
{
    // void getChars(int srcBegin, int srcEnd, char[] dst, int dstBegin)
    // Characters are copied from this sequence into the destination 
    // character array dst. 
    // Implementation code: E61D07E7
    object_t int_srcbegin;
    object_t int_srcend;
    object_t char_array_dst;
    object_t int_dstbegin;
    object_t object;

    int_dstbegin = stack_pop();
    char_array_dst = stack_pop();
    int_srcend = stack_pop();
    int_srcbegin = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_lang_stringbuilder_indexof_string( void )
{
    // int indexOf(String str)
    // Returns the index within this string of the first occurrence 
    // of the specified substring. 
    // Implementation code: AFB9EE59
    object_t string_str;
    object_t object;
    int32_t ret_value = 0;

    string_str = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push( value_create( &ret_value, T_INT ) );
}

void native_method_lang_stringbuilder_indexof_string_int( void )
{
    // int indexOf(String str, int fromIndex)
    // Returns the index within this string of the first occurrence 
    // of the specified substring, starting at the specified index. 
    // Implementation code: 6C7FA701
    object_t string_str;
    object_t int_fromindex;
    object_t object;
    int32_t ret_value = 0;

    int_fromindex = stack_pop();
    string_str = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push( value_create( &ret_value, T_INT ) );
}

void native_method_lang_stringbuilder_insert_int_boolean( void )
{
    // StringBuilder insert(int offset, boolean b)
    // Inserts the string representation of the boolean argument 
    // into this sequence. 
    // Implementation code: 3151CC81
    object_t int_offset;
    object_t boolean_b;
    object_t object;

    boolean_b = stack_peek(0);
    int_offset = stack_peek(1);
    object = stack_peek(2);

    // put your code here
    strings_insert( object, value_get_int( int_offset ), native_value_to_string( boolean_b ), 0, NEG_U32 );

	// keep object in the stack
	stack_remove(2);
}

void native_method_lang_stringbuilder_insert_int_char( void )
{
    // StringBuilder insert(int offset, char c)
    // Inserts the string representation of the char argument into 
    // this sequence. 
    // Implementation code: B8A0F464
    object_t int_offset;
    object_t char_c;
    object_t object;

    char_c = stack_peek(0);
    int_offset = stack_peek(1);
    object = stack_peek(2);

    // put your code here
    strings_insert( object, value_get_int( int_offset ), native_value_to_string( char_c ), 0, NEG_U32 );

	// keep object in the stack
	stack_remove(2);
}

void native_method_lang_stringbuilder_insert_int_array_char( void )
{
    // StringBuilder insert(int offset, char[] str)
    // Inserts the string representation of the char array argument 
    // into this sequence. 
    // Implementation code: DE49A3B9
    object_t int_offset;
    object_t char_array_str;
    object_t object;

    char_array_str = stack_peek(0);
    int_offset = stack_peek(1);
    object = stack_peek(2);

    // put your code here
    strings_insert( object, value_get_int( int_offset ), strings_get_text_ptr( char_array_str ), 0, NEG_U32 );

	// keep object in the stack
	stack_remove(2);
}

void native_method_lang_stringbuilder_insert_int_array_char_int_int( void )
{
    // StringBuilder insert(int index, char[] str, int offset, int len)
    // Inserts the string representation of a subarray of the str 
    // array argument into this sequence. 
    // Implementation code: C0CDCFCA
    object_t int_index;
    object_t char_array_str;
    object_t int_offset;
    object_t int_len;
    object_t object;

    int_len = stack_peek(0);
    int_offset = stack_peek(1);
    char_array_str = stack_peek(2);
    int_index = stack_peek(3);
    object = stack_peek(4);

    // put your code here
    strings_insert( object, value_get_int( int_offset ), 
						    strings_get_text_ptr( char_array_str ), 
							value_get_int( int_offset ), 
							value_get_int( int_len ) );

	// keep object in the stack
	stack_remove(4);
}

void native_method_lang_stringbuilder_insert_int_charsequence( void )
{
    // StringBuilder insert(int dstOffset, CharSequence s)
    // Inserts the specified CharSequence into this sequence. 
    // Implementation code: 670C61C7
    object_t int_dstoffset;
    object_t charsequence_s;
    object_t object;

    charsequence_s = stack_peek(0);
    int_dstoffset = stack_peek(1);
    object = stack_peek(2);

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_lang_stringbuilder_insert_int_charsequence_int_int( void )
{
    // StringBuilder insert(int dstOffset, CharSequence s, int start, int end)
    // Inserts a subsequence of the specified CharSequence into 
    // this sequence. 
    // Implementation code: 96098691
    object_t int_dstoffset;
    object_t charsequence_s;
    object_t int_start;
    object_t int_end;
    object_t object;

    int_end = stack_pop();
    int_start = stack_pop();
    charsequence_s = stack_pop();
    int_dstoffset = stack_pop();
    object = stack_peek(0);

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_lang_stringbuilder_insert_int_double( void )
{
    // StringBuilder insert(int offset, double d)
    // Inserts the string representation of the double argument 
    // into this sequence. 
    // Implementation code: F97A21AC
    object_t int_offset;
    object_t double_d;
    object_t object;

    double_d = stack_peek(0);
    int_offset = stack_peek(1);
    object = stack_peek(2);

    // put your code here
    strings_insert( object, value_get_int( int_offset ), native_value_to_string( double_d ), 0, NEG_U32 );

	// keep object in the stack
	stack_remove(2);
}

void native_method_lang_stringbuilder_insert_int_float( void )
{
    // StringBuilder insert(int offset, float f)
    // Inserts the string representation of the float argument 
    // into this sequence. 
    // Implementation code: 3ACC4FE9
    object_t int_offset;
    object_t float_f;
    object_t object;

    float_f = stack_peek(0);
    int_offset = stack_peek(1);
    object = stack_peek(2);

    // put your code here
    strings_insert( object, value_get_int( int_offset ), native_value_to_string( float_f ), 0, NEG_U32 );

	// keep object in the stack
	stack_remove(2);
}

void native_method_lang_stringbuilder_insert_int_int( void )
{
    // StringBuilder insert(int offset, int i)
    // Inserts the string representation of the second int argument 
    // into this sequence. 
    // Implementation code: 6B67155F
    object_t int_offset;
    object_t int_i;
    object_t object;

    int_i = stack_peek(0);
    int_offset = stack_peek(1);
    object = stack_peek(2);

    // put your code here
    strings_insert( object, value_get_int( int_offset ), native_value_to_string( int_i ), 0, NEG_U32 );

	// keep object in the stack
	stack_remove(2);
}

void native_method_lang_stringbuilder_insert_int_long( void )
{
    // StringBuilder insert(int offset, long l)
    // Inserts the string representation of the long argument into 
    // this sequence. 
    // Implementation code: 15A15EFF
    object_t int_offset;
    object_t long_l;
    object_t object;

    long_l = stack_peek(0);
    int_offset = stack_peek(1);
    object = stack_peek(2);

    // put your code here
    strings_insert( object, value_get_int( int_offset ), native_value_to_string( long_l ), 0, NEG_U32 );

	// keep object in the stack
	stack_remove(2);
}

void native_method_lang_stringbuilder_insert_int_object( void )
{
    // StringBuilder insert(int offset, Object obj)
    // Inserts the string representation of the Object argument 
    // into this character sequence. 
    // Implementation code: 4232F5EC
    object_t int_offset;
    object_t object_obj;
    object_t object;

    object_obj = stack_pop();
    int_offset = stack_pop();
    object = stack_peek(0);

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_lang_stringbuilder_insert_int_string( void )
{
    // StringBuilder insert(int offset, String str)
    // Inserts the string into this character sequence. 
    // Implementation code: D9BBE6E1
    object_t int_offset;
    object_t string_str;
    object_t object;

    string_str = stack_peek(0);
    int_offset = stack_peek(1);
    object = stack_peek(2);

    // put your code here
    strings_insert( object, value_get_int( int_offset ), strings_get_text_ptr( string_str ), 0, NEG_U32 );

	// keep object in the stack
	stack_remove(2);
}

void native_method_lang_stringbuilder_lastindexof_string( void )
{
    // int lastIndexOf(String str)
    // Returns the index within this string of the rightmost occurrence 
    // of the specified substring. 
    // Implementation code: 2DB76A78
    object_t string_str;
    object_t object;
    int32_t ret_value = 0;

    string_str = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push( value_create( &ret_value, T_INT ) );
}

void native_method_lang_stringbuilder_lastindexof_string_int( void )
{
    // int lastIndexOf(String str, int fromIndex)
    // Returns the index within this string of the last occurrence 
    // of the specified substring. 
    // Implementation code: 35CFC847
    object_t string_str;
    object_t int_fromindex;
    object_t object;
    int32_t ret_value = 0;

    int_fromindex = stack_pop();
    string_str = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push( value_create( &ret_value, T_INT ) );
}

void native_method_lang_stringbuilder_length( void )
{
    // int length()
    // Returns the length (character count). 
    // Implementation code: 9960E43E
    object_t object;
    object_t ret_value;

    object = stack_peek(0);

    // put your code here
    ret_value = value_create_int( (int)strlen( strings_get_text_ptr( object ) ) );

    // return type: int
	stack_remove(1);
    stack_push( ret_value );
}

void native_method_lang_stringbuilder_offsetbycodepoints_int_int( void )
{
    // int offsetByCodePoints(int index, int codePointOffset)
    // Returns the index within this sequence that is offset from 
    // the given index by codePointOffset code points. 
    // Implementation code: 51DE981F
    object_t int_index;
    object_t int_codepointoffset;
    object_t object;
    int32_t ret_value = 0;

    int_codepointoffset = stack_pop();
    int_index = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push( value_create( &ret_value, T_INT ) );
}

void native_method_lang_stringbuilder_replace_int_int_string( void )
{
    // StringBuilder replace(int start, int end, String str)
    // Replaces the characters in a substring of this sequence 
    // with characters in the specified String. 
    // Implementation code: 41450B5D
    object_t int_start;
    object_t int_end;
    object_t string_str;
    object_t object;

    string_str = stack_pop();
    int_end = stack_pop();
    int_start = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: StringBuilder
    stack_push( 0 );
}

void native_method_lang_stringbuilder_reverse( void )
{
    // StringBuilder reverse()
    // Causes this character sequence to be replaced by the reverse 
    // of the sequence. 
    // Implementation code: AD08DE63
    object_t object;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: StringBuilder
    stack_push( 0 );
}

void native_method_lang_stringbuilder_setcharat_int_char( void )
{
    // void setCharAt(int index, char ch)
    // The character at the specified index is set to ch. 
    // Implementation code: DF04A3F8
    object_t int_index;
    object_t char_ch;
    object_t object;

    char_ch = stack_peek(0);
    int_index = stack_peek(1);
    object = stack_peek(2);

    // put your code here
	native_string_set_char_at( object, value_get_int( int_index ), value_get_character( char_ch ) );

	// keep object in the stack
	stack_remove(3);
}

void native_method_lang_stringbuilder_setlength_int( void )
{
    // void setLength(int newLength)
    // Sets the length of the character sequence. 
    // Implementation code: 9C325DFE
    object_t int_newlength;
    object_t object;

    int_newlength = stack_pop();
    object = stack_pop();

    // put your code here
    // exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_lang_stringbuilder_subsequence_int_int( void )
{
    // CharSequence subSequence(int start, int end)
    // Returns a new character sequence that is a subsequence of 
    // this sequence. 
    // Implementation code: B2424B67
    object_t int_start;
    object_t int_end;
    object_t object;
	object_t ret_obj;

    int_end = stack_peek(0);
    int_start = stack_peek(1);
    object = stack_peek(2);

	// return type: CharSequence
    ret_obj = strings_get_substring( object, value_get_int( int_start ), NEG_U32 );

	stack_remove(3);
	stack_push( ret_obj );
}

void native_method_lang_stringbuilder_substring_int( void )
{
    // String substring(int start)
    // Returns a new String that contains a subsequence of characters 
    // currently contained in this character sequence. 
    // Implementation code: BA34231C
    object_t int_start;
    object_t object;
	object_t ret_obj;

    int_start = stack_peek(0);
    object = stack_peek(1);

    // return type: String
    ret_obj = strings_get_substring( object, value_get_int( int_start ), NEG_U32 );

	stack_remove(2);
	stack_push( ret_obj );
}

void native_method_lang_stringbuilder_substring_int_int( void )
{
    // String substring(int start, int end)
    // Returns a new String that contains a subsequence of characters 
    // currently contained in this sequence. 
    // Implementation code: 08570B2A
    object_t int_start;
    object_t int_end;
    object_t object;
	object_t ret_obj;

    int_end = stack_peek(0);
    int_start = stack_peek(1);
    object = stack_peek(2);

    // return type: String
    ret_obj = strings_get_substring( object, value_get_int( int_start ), value_get_int( int_end ) );

	stack_remove(3);
	stack_push( ret_obj );
}

void native_method_lang_stringbuilder_tostring( void )
{
    // String toString()
    // Returns a string representing the data in this sequence. 
    // Implementation code: 355B48B0
    object_t object;
	object_t ret_obj;

    object = stack_peek(0);

    // return type: String
    ret_obj = strings_create( strings_get_text_ptr( object ) );

	stack_remove(1);
	stack_push( ret_obj );
}

void native_method_lang_stringbuilder_trimtosize( void )
{
    // void trimToSize()
    // Attempts to reduce storage used for the character sequence. 
    // Implementation code: 2D2369D0
    object_t object;

    object = stack_pop();

    // put your code here
    // exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

///////////////////////////////////////////////////////////////////////////

uint32_t native_lang_stringbuilder_get_superclass( void )
{
	return NATIVE_CLASS_LANG_OBJECT;
}

void native_lang_stringbuilder_invoke(uint16_t mref)
{
    switch( mref )
    {
        case NATIVE_LANG_STRINGBUILDER_INIT:
            native_method_lang_stringbuilder_init();
            break;

        case NATIVE_LANG_STRINGBUILDER_INIT_CHARSEQUENCE:
            native_method_lang_stringbuilder_init_charsequence();
            break;

        case NATIVE_LANG_STRINGBUILDER_INIT_INT:
            native_method_lang_stringbuilder_init_int();
            break;

        case NATIVE_LANG_STRINGBUILDER_INIT_STRING:
            native_method_lang_stringbuilder_init_string();
            break;

        case NATIVE_LANG_STRINGBUILDER_APPEND_BOOLEAN:
            native_method_lang_stringbuilder_append_boolean();
            break;

        case NATIVE_LANG_STRINGBUILDER_APPEND_CHAR:
            native_method_lang_stringbuilder_append_char();
            break;

        case NATIVE_LANG_STRINGBUILDER_APPEND_ARRAY_CHAR:
            native_method_lang_stringbuilder_append_array_char();
            break;

        case NATIVE_LANG_STRINGBUILDER_APPEND_ARRAY_CHAR_INT_INT:
            native_method_lang_stringbuilder_append_array_char_int_int();
            break;

        case NATIVE_LANG_STRINGBUILDER_APPEND_CHARSEQUENCE:
            native_method_lang_stringbuilder_append_charsequence();
            break;

        case NATIVE_LANG_STRINGBUILDER_APPEND_CHARSEQUENCE_INT_INT:
            native_method_lang_stringbuilder_append_charsequence_int_int();
            break;

        case NATIVE_LANG_STRINGBUILDER_APPEND_DOUBLE:
            native_method_lang_stringbuilder_append_double();
            break;

        case NATIVE_LANG_STRINGBUILDER_APPEND_FLOAT:
            native_method_lang_stringbuilder_append_float();
            break;

        case NATIVE_LANG_STRINGBUILDER_APPEND_INT:
            native_method_lang_stringbuilder_append_int();
            break;

        case NATIVE_LANG_STRINGBUILDER_APPEND_LONG:
            native_method_lang_stringbuilder_append_long();
            break;

        case NATIVE_LANG_STRINGBUILDER_APPEND_OBJECT:
            native_method_lang_stringbuilder_append_object();
            break;

        case NATIVE_LANG_STRINGBUILDER_APPEND_STRING:
            native_method_lang_stringbuilder_append_string();
            break;

        case NATIVE_LANG_STRINGBUILDER_APPEND_STRINGBUFFER:
            native_method_lang_stringbuilder_append_stringbuffer();
            break;

        case NATIVE_LANG_STRINGBUILDER_APPENDCODEPOINT_INT:
            native_method_lang_stringbuilder_appendcodepoint_int();
            break;

        case NATIVE_LANG_STRINGBUILDER_CAPACITY:
            native_method_lang_stringbuilder_capacity();
            break;

        case NATIVE_LANG_STRINGBUILDER_CHARAT_INT:
            native_method_lang_stringbuilder_charat_int();
            break;

        case NATIVE_LANG_STRINGBUILDER_CODEPOINTAT_INT:
            native_method_lang_stringbuilder_codepointat_int();
            break;

        case NATIVE_LANG_STRINGBUILDER_CODEPOINTBEFORE_INT:
            native_method_lang_stringbuilder_codepointbefore_int();
            break;

        case NATIVE_LANG_STRINGBUILDER_CODEPOINTCOUNT_INT_INT:
            native_method_lang_stringbuilder_codepointcount_int_int();
            break;

        case NATIVE_LANG_STRINGBUILDER_DELETE_INT_INT:
            native_method_lang_stringbuilder_delete_int_int();
            break;

        case NATIVE_LANG_STRINGBUILDER_DELETECHARAT_INT:
            native_method_lang_stringbuilder_deletecharat_int();
            break;

        case NATIVE_LANG_STRINGBUILDER_ENSURECAPACITY_INT:
            native_method_lang_stringbuilder_ensurecapacity_int();
            break;

        case NATIVE_LANG_STRINGBUILDER_GETCHARS_INT_INT_ARRAY_CHAR_INT:
            native_method_lang_stringbuilder_getchars_int_int_array_char_int();
            break;

        case NATIVE_LANG_STRINGBUILDER_INDEXOF_STRING:
            native_method_lang_stringbuilder_indexof_string();
            break;

        case NATIVE_LANG_STRINGBUILDER_INDEXOF_STRING_INT:
            native_method_lang_stringbuilder_indexof_string_int();
            break;

        case NATIVE_LANG_STRINGBUILDER_INSERT_INT_BOOLEAN:
            native_method_lang_stringbuilder_insert_int_boolean();
            break;

        case NATIVE_LANG_STRINGBUILDER_INSERT_INT_CHAR:
            native_method_lang_stringbuilder_insert_int_char();
            break;

        case NATIVE_LANG_STRINGBUILDER_INSERT_INT_ARRAY_CHAR:
            native_method_lang_stringbuilder_insert_int_array_char();
            break;

        case NATIVE_LANG_STRINGBUILDER_INSERT_INT_ARRAY_CHAR_INT_INT:
            native_method_lang_stringbuilder_insert_int_array_char_int_int();
            break;

        case NATIVE_LANG_STRINGBUILDER_INSERT_INT_CHARSEQUENCE:
            native_method_lang_stringbuilder_insert_int_charsequence();
            break;

        case NATIVE_LANG_STRINGBUILDER_INSERT_INT_CHARSEQUENCE_INT_INT:
            native_method_lang_stringbuilder_insert_int_charsequence_int_int();
            break;

        case NATIVE_LANG_STRINGBUILDER_INSERT_INT_DOUBLE:
            native_method_lang_stringbuilder_insert_int_double();
            break;

        case NATIVE_LANG_STRINGBUILDER_INSERT_INT_FLOAT:
            native_method_lang_stringbuilder_insert_int_float();
            break;

        case NATIVE_LANG_STRINGBUILDER_INSERT_INT_INT:
            native_method_lang_stringbuilder_insert_int_int();
            break;

        case NATIVE_LANG_STRINGBUILDER_INSERT_INT_LONG:
            native_method_lang_stringbuilder_insert_int_long();
            break;

        case NATIVE_LANG_STRINGBUILDER_INSERT_INT_OBJECT:
            native_method_lang_stringbuilder_insert_int_object();
            break;

        case NATIVE_LANG_STRINGBUILDER_INSERT_INT_STRING:
            native_method_lang_stringbuilder_insert_int_string();
            break;

        case NATIVE_LANG_STRINGBUILDER_LASTINDEXOF_STRING:
            native_method_lang_stringbuilder_lastindexof_string();
            break;

        case NATIVE_LANG_STRINGBUILDER_LASTINDEXOF_STRING_INT:
            native_method_lang_stringbuilder_lastindexof_string_int();
            break;

        case NATIVE_LANG_STRINGBUILDER_LENGTH:
            native_method_lang_stringbuilder_length();
            break;

        case NATIVE_LANG_STRINGBUILDER_OFFSETBYCODEPOINTS_INT_INT:
            native_method_lang_stringbuilder_offsetbycodepoints_int_int();
            break;

        case NATIVE_LANG_STRINGBUILDER_REPLACE_INT_INT_STRING:
            native_method_lang_stringbuilder_replace_int_int_string();
            break;

        case NATIVE_LANG_STRINGBUILDER_REVERSE:
            native_method_lang_stringbuilder_reverse();
            break;

        case NATIVE_LANG_STRINGBUILDER_SETCHARAT_INT_CHAR:
            native_method_lang_stringbuilder_setcharat_int_char();
            break;

        case NATIVE_LANG_STRINGBUILDER_SETLENGTH_INT:
            native_method_lang_stringbuilder_setlength_int();
            break;

        case NATIVE_LANG_STRINGBUILDER_SUBSEQUENCE_INT_INT:
            native_method_lang_stringbuilder_subsequence_int_int();
            break;

        case NATIVE_LANG_STRINGBUILDER_SUBSTRING_INT:
            native_method_lang_stringbuilder_substring_int();
            break;

        case NATIVE_LANG_STRINGBUILDER_SUBSTRING_INT_INT:
            native_method_lang_stringbuilder_substring_int_int();
            break;

        case NATIVE_LANG_STRINGBUILDER_TOSTRING:
            native_method_lang_stringbuilder_tostring();
            break;

        case NATIVE_LANG_STRINGBUILDER_TRIMTOSIZE:
            native_method_lang_stringbuilder_trimtosize();
            break;

        default:
            exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
            break;

    }
}


