#include "lang_string.h"
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


///////////////////////////////////////////////////////////////////////////

// New method implementation
object_t native_lang_string_new_value( char * value )
{
	object_t object;

    object = strings_create( value );

	return object;
}

object_t native_lang_string_new( void )
{
    // return( object_create( GET_CLASS_REF( NATIVE_CLASS_LANG_STRING ), T_CLASS, NATIVE_LANG_STRING_TOTAL_FIELDS ) );
	return( strings_create( "" ) );
}

///////////////////////////////////////////////////////////////////////////

void native_method_lang_string_init( void )
{
    // String()
    // Initializes a newly created String object so that it represents 
    // an empty character sequence. 
    // Implementation code: A1671954
    object_t object;

    object = stack_pop();

    // put your code here
	strings_copy( object, "" );
}

void native_method_lang_string_init_array_byte( void )
{
    // String(byte[] bytes)
    // Constructs a new String by decoding the specified array 
    // of bytes using the platform's default charset. 
    // Implementation code: 0FA85733
    object_t byte_array_bytes;
    object_t object;

    byte_array_bytes = stack_peek(0);
    object = stack_peek(1);

    // put your code here
	strings_copy( object, ( char * )object_get_ptr( byte_array_bytes ) );
    
    stack_remove(2);
}

void native_method_lang_string_init_array_byte_charset( void )
{
    // String(byte[] bytes, Charset charset)
    // Constructs a new String by decoding the specified array 
    // of bytes using the specified charset. 
    // Implementation code: 5BFBE126
    object_t byte_array_bytes;
    object_t charset_charset;
    object_t object;

    charset_charset = stack_pop();
    byte_array_bytes = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_lang_string_init_array_byte_int( void )
{
    // String(byte[] ascii, int hibyte)
    // Deprecated. This method does not properly convert bytes 
    // into characters. As of JDK 1.1, the preferred way to do 
    // this is via the String constructors that take a Charset, 
    // charset name, or that use the platform's default charset. 
    // Implementation code: EBCD75EE
    object_t byte_array_ascii;
    object_t int_hibyte;
    object_t object;

    int_hibyte = stack_pop();
    byte_array_ascii = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_lang_string_init_array_byte_int_int( void )
{
    // String(byte[] bytes, int offset, int length)
    // Constructs a new String by decoding the specified subarray 
    // of bytes using the platform's default charset. 
    // Implementation code: 6CB8E99B
    object_t byte_array_bytes;
    object_t int_offset;
    object_t int_length;
    object_t object;

    int_length = stack_peek(0);
    int_offset = stack_peek(1);
    byte_array_bytes = stack_peek(2);
    object = stack_peek(3);

    // put your code here
	strings_copy( object, "" );
	strings_insert( object, 0, ( char * )object_get_ptr( byte_array_bytes ), value_get_int( int_offset ), value_get_int( int_length ) );
    
    stack_remove(4);
}

void native_method_lang_string_init_array_byte_int_int_charset( void )
{
    // String(byte[] bytes, int offset, int length, Charset charset)
    // Constructs a new String by decoding the specified subarray 
    // of bytes using the specified charset. 
    // Implementation code: DD82EFD7
    object_t byte_array_bytes;
    object_t int_offset;
    object_t int_length;
    object_t charset_charset;
    object_t object;

    charset_charset = stack_pop();
    int_length = stack_pop();
    int_offset = stack_pop();
    byte_array_bytes = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_lang_string_init_array_byte_int_int_int( void )
{
    // String(byte[] ascii, int hibyte, int offset, int count)
    // Deprecated. This method does not properly convert bytes 
    // into characters. As of JDK 1.1, the preferred way to do 
    // this is via the String constructors that take a Charset, 
    // charset name, or that use the platform's default charset. 
    // Implementation code: EBCD75EE
    object_t byte_array_ascii;
    object_t int_hibyte;
    object_t object;

    int_hibyte = stack_pop();
    byte_array_ascii = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_lang_string_init_array_byte_int_int_string( void )
{
    // String(byte[] bytes, int offset, int length, String charsetName)
    // Constructs a new String by decoding the specified subarray 
    // of bytes using the specified charset. 
    // Implementation code: DD82EFD7
    object_t byte_array_bytes;
    object_t int_offset;
    object_t int_length;
    object_t charset_charset;
    object_t object;

    charset_charset = stack_pop();
    int_length = stack_pop();
    int_offset = stack_pop();
    byte_array_bytes = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_lang_string_init_array_byte_string( void )
{
    // String(byte[] bytes, String charsetName)
    // Constructs a new String by decoding the specified array 
    // of bytes using the specified charset. 
    // Implementation code: 5BFBE126
    object_t byte_array_bytes;
    object_t charset_charset;
    object_t object;

    charset_charset = stack_pop();
    byte_array_bytes = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_lang_string_init_array_char( void )
{
    // String(char[] value)
    // Allocates a new String so that it represents the sequence 
    // of characters currently contained in the character array 
    // argument. 
    // Implementation code: 66E1B7F6
    object_t char_array_value;
    object_t object;

    char_array_value = stack_peek(0);
    object = stack_peek(1);

    // put your code here
	strings_copy( object, ( char * )object_get_ptr( char_array_value ) );
    stack_remove(2);
}

void native_method_lang_string_init_array_char_int_int( void )
{
    // String(char[] value, int offset, int count)
    // Allocates a new String that contains characters from a subarray 
    // of the character array argument. 
    // Implementation code: 0109CE07
    object_t char_array_value;
    object_t int_offset;
    object_t int_count;
    object_t object;

    int_count = stack_peek(0);
    int_offset = stack_peek(1);
    char_array_value = stack_peek(2);
    object = stack_peek(3);

    // put your code here
	strings_copy( object, "" );
	strings_insert( object, 0, ( char * )object_get_ptr( char_array_value ), value_get_int( int_offset ), value_get_int( int_count ) );
    
    stack_remove(4);
}

void native_method_lang_string_init_array_int_int_int( void )
{
    // String(int[] codePoints, int offset, int count)
    // Allocates a new String that contains characters from a subarray 
    // of the Unicode code point array argument. 
    // Implementation code: DE729C00
    object_t int_array_codepoints;
    object_t int_offset;
    object_t int_count;
    object_t object;

    int_count = stack_pop();
    int_offset = stack_pop();
    int_array_codepoints = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_lang_string_init_string( void )
{
    // String(String original)
    // Initializes a newly created String object so that it represents 
    // the same sequence of characters as the argument; in other 
    // words, the newly created string is a copy of the argument 
    // string. 
    // Implementation code: 76FA2260
    object_t string_original;
    object_t object;

    string_original = stack_peek(0);
    object = stack_peek(1);

    // put your code here
	strings_copy( object, ( char * )object_get_ptr( string_original ) );
    
    stack_remove(2);
}

void native_method_lang_string_init_stringbuffer( void )
{
    // String(StringBuffer buffer)
    // Allocates a new string that contains the sequence of characters 
    // currently contained in the string buffer argument. 
    // Implementation code: 1130F295
    object_t stringbuffer_buffer;
    object_t object;

    stringbuffer_buffer = stack_peek(0);
    object = stack_peek(1);

    // put your code here
	strings_copy( object, ( char * )object_get_ptr( stringbuffer_buffer ) );
    
    stack_remove(2);
}

void native_method_lang_string_init_stringbuilder( void )
{
    // String(StringBuilder builder)
    // Allocates a new string that contains the sequence of characters 
    // currently contained in the string builder argument. 
    // Implementation code: A9AF9223
    object_t stringbuilder_builder;
    object_t object;

    stringbuilder_builder = stack_peek(0);
    object = stack_peek(1);

    // put your code here
	strings_copy( object, ( char * )object_get_ptr( stringbuilder_builder ) );
    
    stack_remove(2);
}

///////////////////////////////////////////////////////////////////////////

void native_method_lang_string_charat_int( void )
{
    // char charAt(int index)
    // Returns the char value at the specified index. 
    // Implementation code: FF71BAFD
    object_t int_index;
    object_t object;
    object_t ret_object;

    int_index = stack_peek(0);
    object = stack_peek(1);

    // return type: char
    ret_object = native_string_char_at( object, value_get_int( int_index ) );
    stack_remove(2);
    stack_push( ret_object );
}

void native_method_lang_string_codepointat_int( void )
{
    // int codePointAt(int index)
    // Returns the character (Unicode code point) at the specified 
    // index. 
    // Implementation code: E742ED13
    object_t int_index;
    object_t object;
    int32_t ret_value = 0;

    int_index = stack_peek(0);
    object = stack_peek(1);

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push( value_create( &ret_value, T_INT ) );
}

void native_method_lang_string_codepointbefore_int( void )
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

void native_method_lang_string_codepointcount_int_int( void )
{
    // int codePointCount(int beginIndex, int endIndex)
    // Returns the number of Unicode code points in the specified 
    // text range of this String. 
    // Implementation code: 2932A018
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

void native_method_lang_string_compareto_string( void )
{
    // int compareTo(String anotherString)
    // Compares two strings lexicographically. 
    // Implementation code: 1D7D390E
    // return type: int
    object_t ret_object;
    
    ret_object = value_create_int( native_lang_string_compare( FALSE ) );
    stack_remove(2);
	stack_push( ret_object );
}

void native_method_lang_string_comparetoignorecase_string( void )
{
    // int compareToIgnoreCase(String str)
    // Compares two strings lexicographically, ignoring case differences. 
    // Implementation code: DA29B82F
    // return type: int
	object_t ret_object;
    
    ret_object = value_create_int( native_lang_string_compare( TRUE ) );
    stack_remove(2);
	stack_push( ret_object );    
}

void native_method_lang_string_concat_string( void )
{
    // String concat(String str)
    // Concatenates the specified string to the end of this string. 
    // Implementation code: 2E8D6345
    object_t string_str;
    object_t object;
	object_t new_string;

    string_str = stack_peek(0);
    object = stack_peek(1);

    // put your code here
	new_string = strings_duplicate( object );
	strings_concat( new_string, ( char * )object_get_ptr( string_str ) );

    // return type: String
    stack_remove(2);
    stack_push( new_string );
}

void native_method_lang_string_contains_charsequence( void )
{
    // boolean contains(CharSequence s)
    // Returns true if and only if this string contains the specified 
    // sequence of char values. 
    // Implementation code: B0E6C075
    object_t charsequence_s;
    object_t object;
    bool_t ret_value = 0;

    charsequence_s = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: boolean
    stack_push( value_create( &ret_value, T_BOOLEAN ) );
}

void native_method_lang_string_contentequals_charsequence( void )
{
    // boolean contentEquals(CharSequence cs)
    // Compares this string to the specified CharSequence. 
    // Implementation code: 0A3F4628
    object_t charsequence_cs;
    object_t object;
    bool_t ret_value = 0;

    charsequence_cs = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: boolean
    stack_push( value_create( &ret_value, T_BOOLEAN ) );
}

void native_method_lang_string_contentequals_stringbuffer( void )
{
    // boolean contentEquals(StringBuffer sb)
    // Compares this string to the specified StringBuffer. 
    // Implementation code: BCD8F84C
    bool_t ret_value = 0;
    object_t ret_object;

	if( native_lang_string_compare( FALSE ) == 0 )
	{
		ret_value = TRUE;
	}

    ret_object = value_create_boolean( ret_value );
    stack_remove(2);
	stack_push( ret_object );
}

void native_method_lang_string_copyvalueof_array_char( void )
{
    // static String copyValueOf(char[] data)
    // Returns a String that represents the character sequence 
    // in the array specified. 
    // Implementation code: 156B942C
    object_t char_array_data;
    object_t ret_object;

    char_array_data = stack_peek(0);

    // return type: String
    ret_object = strings_create( ( char * )object_get_ptr( char_array_data ) );
    stack_remove(1);
    stack_push( ret_object );
}

void native_method_lang_string_copyvalueof_array_char_int_int( void )
{
    // static String copyValueOf(char[] data, int offset, int count)
    // Returns a String that represents the character sequence 
    // in the array specified. 
    // Implementation code: 156B942C
    object_t char_array_data;
    object_t int_offset;
    object_t int_count;
	object_t object;
    object_t ret_object;

    int_count = stack_peek(0);
    int_offset = stack_peek(1);
    char_array_data = stack_peek(2);
    object = stack_peek(3);

    // return type: String
    ret_object = strings_create_index( ( char * )object_get_ptr( char_array_data ), value_get_int( int_offset ), value_get_int( int_count ) );
    stack_remove(4);
    stack_push( ret_object );
}

void native_method_lang_string_endswith_string( void )
{
    // boolean endsWith(String suffix)
    // Tests if this string ends with the specified suffix. 
    // Implementation code: 1062B572
    object_t string_suffix;
    object_t object;
    bool_t ret_value = 0;

    string_suffix = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: boolean
    stack_push( value_create( &ret_value, T_BOOLEAN ) );
}

void native_method_lang_string_equals_object( void )
{
    // boolean equals(Object anObject)
    // Compares this string to the specified object. 
    // Implementation code: 0F0CB39D
    bool_t ret_value = 0;
    object_t ret_object;

    // put your code here
    if( native_lang_string_compare( FALSE ) == 0 ) ret_value = 1;

    // return type: boolean
    ret_object = value_create_boolean( ret_value );
    stack_remove(2);
    stack_push( ret_object );
}

void native_method_lang_string_equalsignorecase_string( void )
{
    // boolean equalsIgnoreCase(String anotherString)
    // Compares this String to another String, ignoring case considerations. 
    // Implementation code: 2D6E68C0
    bool_t ret_value = 0;
    object_t ret_object;
    
    // put your code here
    if( native_lang_string_compare( TRUE ) == 0 ) ret_value = 1;

    // return type: boolean
    ret_object = value_create_boolean( ret_value );
    stack_remove(2);
    stack_push( ret_object );
}

void native_method_lang_string_getbytes( void )
{
    // byte[] getBytes()
    // Encodes this String into a sequence of bytes using the platform's 
    // default charset, storing the result into a new byte array. 
    // Implementation code: B10D8EDB
    object_t object;
    object_t ret_object;

    object = stack_peek(0);

    // return type: byte[]
    ret_object = native_string_to_array( object, T_BYTE );
    stack_remove(1);
    stack_push( ret_object );
}

void native_method_lang_string_getbytes_charset( void )
{
    // byte[] getBytes(Charset charset)
    // Encodes this String into a sequence of bytes using the given 
    // charset, storing the result into a new byte array. 
    // Implementation code: 145A5A87
    object_t charset_charset;
    object_t object;

    charset_charset = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: byte[]
    stack_push( 0 );
}

void native_method_lang_string_getbytes_int_int_array_byte_int( void )
{
    // void getBytes(int srcBegin, int srcEnd, byte[] dst, int dstBegin)
    // Deprecated. This method does not properly convert characters 
    // into bytes. As of JDK 1.1, the preferred way to do this 
    // is via the getBytes() method, which uses the platform's 
    // default charset. 
    // Implementation code: 2F8C3773
    object_t int_srcbegin;
    object_t int_srcend;
    object_t byte_array_dst;
    object_t int_dstbegin;
    object_t object;

    int_dstbegin = stack_pop();
    byte_array_dst = stack_pop();
    int_srcend = stack_pop();
    int_srcbegin = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_lang_string_getbytes_string( void )
{
    // byte[] getBytes(String charsetName)
    // Encodes this String into a sequence of bytes using the named 
    // charset, storing the result into a new byte array. 
    // Implementation code: 9C8EB5EA
    object_t string_charsetname;
    object_t object;

    string_charsetname = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: byte[]
    stack_push( 0 );
}

void native_method_lang_string_getchars_int_int_array_char_int( void )
{
    // void getChars(int srcBegin, int srcEnd, char[] dst, int dstBegin)
    // Copies characters from this string into the destination 
    // character array. 
    // Implementation code: 7DFE1F47
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

void native_method_lang_string_hashcode( void )
{
    // int hashCode()
    // Returns a hash code for this string. 
    // Implementation code: 1B41AF8D
    object_t object;
    int32_t ret_value = 0;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push( value_create( &ret_value, T_INT ) );
}

void native_method_lang_string_indexof_int( void )
{
    // int indexOf(int ch)
    // Returns the index within this string of the first occurrence 
    // of the specified character. 
    // Implementation code: B1D36028
    object_t int_ch;
    object_t object;
    int32_t ret_value = 0;

    int_ch = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push( value_create( &ret_value, T_INT ) );
}

void native_method_lang_string_indexof_int_int( void )
{
    // int indexOf(int ch, int fromIndex)
    // Returns the index within this string of the first occurrence 
    // of the specified character, starting the search at the specified 
    // index. 
    // Implementation code: 4D9F13DB
    object_t int_ch;
    object_t int_fromindex;
    object_t object;
    int32_t ret_value = 0;

    int_fromindex = stack_pop();
    int_ch = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push( value_create( &ret_value, T_INT ) );
}

void native_method_lang_string_indexof_string( void )
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

void native_method_lang_string_indexof_string_int( void )
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

void native_method_lang_string_intern( void )
{
    // String intern()
    // Returns a canonical representation for the string object. 
    // Implementation code: 1DBDF32D
    object_t object;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: String
    stack_push( strings_create( "" ) );
}

void native_method_lang_string_isempty( void )
{
    // boolean isEmpty()
    // Returns true if, and only if, length() is 0. 
    // Implementation code: 121E2FEC
    object_t object;
    object_t ret_object;
    bool_t ret_value = 0;

    object = stack_peek(0);

    // put your code here
    if( strlen( strings_get_text_ptr( object ) ) == 0 ) ret_value = 1;

    // return type: boolean
    ret_object = value_create_boolean( ret_value );
    stack_remove(1);
    stack_push( ret_object );
}

void native_method_lang_string_lastindexof_int( void )
{
    // int lastIndexOf(int ch)
    // Returns the index within this string of the last occurrence 
    // of the specified character. 
    // Implementation code: 2048AE4F
    object_t int_ch;
    object_t object;
    int32_t ret_value = 0;

    int_ch = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push( value_create( &ret_value, T_INT ) );
}

void native_method_lang_string_lastindexof_int_int( void )
{
    // int lastIndexOf(int ch, int fromIndex)
    // Returns the index within this string of the last occurrence 
    // of the specified character, searching backward starting 
    // at the specified index. 
    // Implementation code: 8DD1EF92
    object_t int_ch;
    object_t int_fromindex;
    object_t object;
    int32_t ret_value = 0;

    int_fromindex = stack_pop();
    int_ch = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push( value_create( &ret_value, T_INT ) );
}

void native_method_lang_string_lastindexof_string( void )
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

void native_method_lang_string_lastindexof_string_int( void )
{
    // int lastIndexOf(String str, int fromIndex)
    // Returns the index within this string of the last occurrence 
    // of the specified substring, searching backward starting 
    // at the specified index. 
    // Implementation code: AEC9AACD
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

void native_method_lang_string_length( void )
{
    // int length()
    // Returns the length of this string. 
    // Implementation code: 26E07C68
    object_t object;
    object_t ret_object;
    int32_t ret_value = 0;

    object = stack_peek(0);

    // put your code here
    ret_value = ( uint32_t )strlen( strings_get_text_ptr( object ) );

    // return type: int
    ret_object = value_create_int( ret_value );
    stack_remove(1);
    stack_push( ret_object );
}

void native_method_lang_string_matches_string( void )
{
    // boolean matches(String regex)
    // Tells whether or not this string matches the given regular 
    // expression. 
    // Implementation code: 48ABF120
    object_t string_regex;
    object_t object;
    bool_t ret_value = 0;

    string_regex = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: boolean
    stack_push( value_create( &ret_value, T_BOOLEAN ) );
}

void native_method_lang_string_offsetbycodepoints_int_int( void )
{
    // int offsetByCodePoints(int index, int codePointOffset)
    // Returns the index within this String that is offset from 
    // the given index by codePointOffset code points. 
    // Implementation code: CFA277B0
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

void native_method_lang_string_regionmatches_boolean_int_string_int_int( void )
{
    // boolean regionMatches(boolean ignoreCase, int toffset, String other, int ooffset, int len)
    // Tests if two string regions are equal. 
    // Implementation code: 7109630B
    object_t boolean_ignorecase;
    object_t int_toffset;
    object_t string_other;
    object_t int_ooffset;
    object_t int_len;
    object_t object;
    bool_t ret_value = 0;

    int_len = stack_pop();
    int_ooffset = stack_pop();
    string_other = stack_pop();
    int_toffset = stack_pop();
    boolean_ignorecase = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: boolean
    stack_push( value_create( &ret_value, T_BOOLEAN ) );
}

void native_method_lang_string_regionmatches_int_string_int_int( void )
{
    // boolean regionMatches(int toffset, String other, int ooffset, int len)
    // Tests if two string regions are equal. 
    // Implementation code: 7109630B
    object_t boolean_ignorecase;
    object_t int_toffset;
    object_t string_other;
    object_t int_ooffset;
    object_t int_len;
    object_t object;
    bool_t ret_value = 0;

    int_len = stack_pop();
    int_ooffset = stack_pop();
    string_other = stack_pop();
    int_toffset = stack_pop();
    boolean_ignorecase = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: boolean
    stack_push( value_create( &ret_value, T_BOOLEAN ) );
}

void native_method_lang_string_replace_char_char( void )
{
    // String replace(char oldChar, char newChar)
    // Returns a new string resulting from replacing all occurrences 
    // of oldChar in this string with newChar. 
    // Implementation code: FA08DB48
    object_t char_oldchar;
    object_t char_newchar;
    object_t object;

    char_newchar = stack_pop();
    char_oldchar = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: String
    stack_push( strings_create( "" ) );
}

void native_method_lang_string_replace_charsequence_charsequence( void )
{
    // String replace(CharSequence target, CharSequence replacement)
    // Replaces each substring of this string that matches the 
    // literal target sequence with the specified literal replacement 
    // sequence. 
    // Implementation code: 1D32B4E5
    object_t charsequence_target;
    object_t charsequence_replacement;
    object_t object;

    charsequence_replacement = stack_pop();
    charsequence_target = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: String
    stack_push( strings_create( "" ) );
}

void native_method_lang_string_replaceall_string_string( void )
{
    // String replaceAll(String regex, String replacement)
    // Replaces each substring of this string that matches the 
    // given regular expression with the given replacement. 
    // Implementation code: E14925FF
    object_t string_regex;
    object_t string_replacement;
    object_t object;

    string_replacement = stack_pop();
    string_regex = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: String
    stack_push( strings_create( "" ) );
}

void native_method_lang_string_replacefirst_string_string( void )
{
    // String replaceFirst(String regex, String replacement)
    // Replaces the first substring of this string that matches 
    // the given regular expression with the given replacement. 
    // Implementation code: CA02F212
    object_t string_regex;
    object_t string_replacement;
    object_t object;

    string_replacement = stack_pop();
    string_regex = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: String
    stack_push( strings_create( "" ) );
}

void native_method_lang_string_split_string( void )
{
    // String[] split(String regex)
    // Splits this string around matches of the given regular expression. 
    // Implementation code: 8CCEE56B
    object_t string_regex;
    object_t object;

    string_regex = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: String[]
    stack_push( 0 );
}

void native_method_lang_string_split_string_int( void )
{
    // String[] split(String regex, int limit)
    // Splits this string around matches of the given regular expression. 
    // Implementation code: 8CCEE56B
    object_t string_regex;
    object_t object;

    string_regex = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: String[]
    stack_push( 0 );
}

void native_method_lang_string_startswith_string( void )
{
    // boolean startsWith(String prefix)
    // Tests if this string starts with the specified prefix. 
    // Implementation code: BAC44478
    object_t string_prefix;
    object_t object;
    bool_t ret_value = 0;

    string_prefix = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: boolean
    stack_push( value_create( &ret_value, T_BOOLEAN ) );
}

void native_method_lang_string_startswith_string_int( void )
{
    // boolean startsWith(String prefix, int toffset)
    // Tests if the substring of this string beginning at the specified 
    // index starts with the specified prefix. 
    // Implementation code: 1D054530
    object_t string_prefix;
    object_t int_toffset;
    object_t object;
    bool_t ret_value = 0;

    int_toffset = stack_pop();
    string_prefix = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: boolean
    stack_push( value_create( &ret_value, T_BOOLEAN ) );
}

void native_method_lang_string_subsequence_int_int( void )
{
    // CharSequence subSequence(int beginIndex, int endIndex)
    // Returns a new character sequence that is a subsequence of 
    // this sequence. 
    // Implementation code: B2424B67
    object_t int_beginindex;
    object_t int_endindex;
    object_t object;

    int_endindex = stack_pop();
    int_beginindex = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: CharSequence
    stack_push( 0 );
}

void native_method_lang_string_substring_int( void )
{
    // String substring(int beginIndex)
    // Returns a new string that is a substring of this string. 
    // Implementation code: 81478283
    object_t int_beginindex;
    object_t object;

    int_beginindex = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: String
    stack_push( strings_create( "" ) );
}

void native_method_lang_string_substring_int_int( void )
{
    // String substring(int beginIndex, int endIndex)
    // Returns a new string that is a substring of this string. 
    // Implementation code: 81478283
    object_t int_beginindex;
    object_t object;

    int_beginindex = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: String
    stack_push( strings_create( "" ) );
}

void native_method_lang_string_tochararray( void )
{
    // char[] toCharArray()
    // Converts this string to a new character array. 
    // Implementation code: DBB202F5
    object_t object;
    object_t ret_object;

    object = stack_peek(0);

    // return type: char[]
    ret_object = native_string_to_array( object, T_CHAR ); 
    stack_remove(1);
    stack_push( ret_object );
}

void native_method_lang_string_tolowercase( void )
{
    // String toLowerCase()
    // Converts all of the characters in this String to lower case 
    // using the rules of the default locale. 
    // Implementation code: 6B622351
    object_t object;
    object_t ret_object;

    object = stack_peek(0);

    // return type: String
    ret_object = native_string_modify( object, STRING_TOLOWER );
    stack_remove(1);
    stack_push( ret_object );
}

void native_method_lang_string_tolowercase_locale( void )
{
    // String toLowerCase(Locale locale)
    // Converts all of the characters in this String to lower case 
    // using the rules of the given Locale. 
    // Implementation code: 92FF018E
    object_t locale_locale;
    object_t object;

    locale_locale = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: String
    stack_push( strings_create( "" ) );
}

void native_method_lang_string_tostring( void )
{
    // String toString()
    // This object (which is already a string!) is itself returned. 
    // Implementation code: D6774FAF
    object_t object;
    object_t ret_object;

    object = stack_peek(0);

    // return type: String
    ret_object = native_string_modify( object, STRING_DUPLICATE );
    stack_remove(1);
    stack_push( ret_object );
}

void native_method_lang_string_touppercase( void )
{
    // String toUpperCase()
    // Converts all of the characters in this String to upper case 
    // using the rules of the default locale. 
    // Implementation code: 736BE601
    object_t object;
    object_t ret_object;

    object = stack_peek(0);

    // return type: String
    ret_object = native_string_modify( object, STRING_TOUPPER );
    stack_remove(1);
    stack_push( ret_object );    
}

void native_method_lang_string_touppercase_locale( void )
{
    // String toUpperCase(Locale locale)
    // Converts all of the characters in this String to upper case 
    // using the rules of the given Locale. 
    // Implementation code: 52219973
    object_t locale_locale;
    object_t object;

    locale_locale = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: String
    stack_push( strings_create( "" ) );
}

void native_method_lang_string_trim( void )
{
    // String trim()
    // Returns a copy of the string, with leading and trailing 
    // whitespace omitted. 
    // Implementation code: FBBA08BD
    object_t object;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: String
    stack_push( strings_create( "" ) );
}

void native_method_lang_string_valueof_boolean( void )
{
    // static String valueOf(boolean b)
    // Returns the string representation of the boolean argument. 
    // Implementation code: F11973F6
    object_t boolean_b;
    object_t ret_object;

    boolean_b = stack_peek(0);

    // return type: String
    ret_object = strings_create( native_value_to_string( boolean_b ) );
    stack_remove(1);
    stack_push( ret_object );
}

void native_method_lang_string_valueof_char( void )
{
    // static String valueOf(char c)
    // Returns the string representation of the char argument. 
    // Implementation code: 0E02FB09
    object_t char_c;
    object_t ret_object;

    char_c = stack_peek(0);

    // return type: String
    ret_object = strings_create( native_value_to_string( char_c ) );
    stack_remove(1);
    stack_push( ret_object );    
}

void native_method_lang_string_valueof_array_char( void )
{
    // static String valueOf(char[] data)
    // Returns the string representation of the char array argument. 
    // Implementation code: 627F236D
    object_t char_array_data;

    char_array_data = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: String
    stack_push_string( ( char * )object_get_ptr( char_array_data ) );
}

void native_method_lang_string_valueof_array_char_int_int( void )
{
    // static String valueOf(char[] data, int offset, int count)
    // Returns the string representation of a specific subarray 
    // of the char array argument. 
    // Implementation code: 23BE7628
    object_t char_array_data;
    object_t int_offset;
    object_t int_count;

    int_count = stack_pop();
    int_offset = stack_pop();
    char_array_data = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: String
    stack_push( strings_create( "" ) );
}

void native_method_lang_string_valueof_double( void )
{
    // static String valueOf(double d)
    // Returns the string representation of the double argument. 
    // Implementation code: D6AAAE31
    object_t double_d;
    object_t ret_object;

    double_d = stack_peek(0);

    // return type: String
    ret_object = strings_create( native_value_to_string( double_d ) );
    stack_remove(1);
    stack_push( ret_object );
}

void native_method_lang_string_valueof_float( void )
{
    // static String valueOf(float f)
    // Returns the string representation of the float argument. 
    // Implementation code: 7C59DE24
    object_t float_f;
    object_t ret_object;

    float_f = stack_peek(0);

    // return type: String
    ret_object = strings_create( native_value_to_string( float_f ) );
    stack_remove(1);
    stack_push( ret_object );    
}

void native_method_lang_string_valueof_int( void )
{
    // static String valueOf(int i)
    // Returns the string representation of the int argument. 
    // Implementation code: D1526AB1
    object_t int_i;
    object_t ret_object;

    int_i = stack_pop();

    // return type: String
    ret_object = strings_create( native_value_to_string( int_i ) );
    stack_remove(1);
    stack_push( ret_object );       
}

void native_method_lang_string_valueof_long( void )
{
    // static String valueOf(long l)
    // Returns the string representation of the long argument. 
    // Implementation code: 390866F5
    object_t long_l;
    object_t ret_object;

    long_l = stack_pop();

    // return type: String
    ret_object = strings_create( native_value_to_string( long_l ) );
    stack_remove(1);
    stack_push( ret_object );        
}

void native_method_lang_string_valueof_object( void )
{
    // static String valueOf(Object obj)
    // Returns the string representation of the Object argument. 
    // Implementation code: 2E9FCE0C
    object_t object_obj;

    object_obj = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: String
    stack_push( strings_create( "" ) );
}

///////////////////////////////////////////////////////////////////////////

uint32_t native_lang_string_get_superclass( void )
{
	return NATIVE_CLASS_LANG_OBJECT;
}

void native_lang_string_get_field(uint16_t mref)
{
    switch( mref )
    {
        default: 
            exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
            break;
    }
}

void native_lang_string_invoke(uint16_t mref)
{
    switch( mref )
    {
        case NATIVE_LANG_STRING_INIT:
            native_method_lang_string_init();
            break;

        case NATIVE_LANG_STRING_INIT_ARRAY_BYTE:
            native_method_lang_string_init_array_byte();
            break;

        case NATIVE_LANG_STRING_INIT_ARRAY_BYTE_CHARSET:
            native_method_lang_string_init_array_byte_charset();
            break;

        case NATIVE_LANG_STRING_INIT_ARRAY_BYTE_INT:
            native_method_lang_string_init_array_byte_int();
            break;

        case NATIVE_LANG_STRING_INIT_ARRAY_BYTE_INT_INT:
            native_method_lang_string_init_array_byte_int_int();
            break;

        case NATIVE_LANG_STRING_INIT_ARRAY_BYTE_INT_INT_CHARSET:
            native_method_lang_string_init_array_byte_int_int_charset();
            break;

        case NATIVE_LANG_STRING_INIT_ARRAY_BYTE_INT_INT_INT:
            native_method_lang_string_init_array_byte_int_int_int();
            break;

        case NATIVE_LANG_STRING_INIT_ARRAY_BYTE_INT_INT_STRING:
            native_method_lang_string_init_array_byte_int_int_string();
            break;

        case NATIVE_LANG_STRING_INIT_ARRAY_BYTE_STRING:
            native_method_lang_string_init_array_byte_string();
            break;

        case NATIVE_LANG_STRING_INIT_ARRAY_CHAR:
            native_method_lang_string_init_array_char();
            break;

        case NATIVE_LANG_STRING_INIT_ARRAY_CHAR_INT_INT:
            native_method_lang_string_init_array_char_int_int();
            break;

        case NATIVE_LANG_STRING_INIT_ARRAY_INT_INT_INT:
            native_method_lang_string_init_array_int_int_int();
            break;

        case NATIVE_LANG_STRING_INIT_STRING:
            native_method_lang_string_init_string();
            break;

        case NATIVE_LANG_STRING_INIT_STRINGBUFFER:
            native_method_lang_string_init_stringbuffer();
            break;

        case NATIVE_LANG_STRING_INIT_STRINGBUILDER:
            native_method_lang_string_init_stringbuilder();
            break;

        case NATIVE_LANG_STRING_CHARAT_INT:
            native_method_lang_string_charat_int();
            break;

        case NATIVE_LANG_STRING_CODEPOINTAT_INT:
            native_method_lang_string_codepointat_int();
            break;

        case NATIVE_LANG_STRING_CODEPOINTBEFORE_INT:
            native_method_lang_string_codepointbefore_int();
            break;

        case NATIVE_LANG_STRING_CODEPOINTCOUNT_INT_INT:
            native_method_lang_string_codepointcount_int_int();
            break;

        case NATIVE_LANG_STRING_COMPARETO_STRING:
            native_method_lang_string_compareto_string();
            break;

        case NATIVE_LANG_STRING_COMPARETOIGNORECASE_STRING:
            native_method_lang_string_comparetoignorecase_string();
            break;

        case NATIVE_LANG_STRING_CONCAT_STRING:
            native_method_lang_string_concat_string();
            break;

        case NATIVE_LANG_STRING_CONTAINS_CHARSEQUENCE:
            native_method_lang_string_contains_charsequence();
            break;

        case NATIVE_LANG_STRING_CONTENTEQUALS_CHARSEQUENCE:
            native_method_lang_string_contentequals_charsequence();
            break;

        case NATIVE_LANG_STRING_CONTENTEQUALS_STRINGBUFFER:
            native_method_lang_string_contentequals_stringbuffer();
            break;

        case NATIVE_LANG_STRING_COPYVALUEOF_ARRAY_CHAR:
            native_method_lang_string_copyvalueof_array_char();
            break;

        case NATIVE_LANG_STRING_COPYVALUEOF_ARRAY_CHAR_INT_INT:
            native_method_lang_string_copyvalueof_array_char_int_int();
            break;

        case NATIVE_LANG_STRING_ENDSWITH_STRING:
            native_method_lang_string_endswith_string();
            break;

        case NATIVE_LANG_STRING_EQUALS_OBJECT:
            native_method_lang_string_equals_object();
            break;

        case NATIVE_LANG_STRING_EQUALSIGNORECASE_STRING:
            native_method_lang_string_equalsignorecase_string();
            break;

        case NATIVE_LANG_STRING_GETBYTES:
            native_method_lang_string_getbytes();
            break;

        case NATIVE_LANG_STRING_GETBYTES_CHARSET:
            native_method_lang_string_getbytes_charset();
            break;

        case NATIVE_LANG_STRING_GETBYTES_INT_INT_ARRAY_BYTE_INT:
            native_method_lang_string_getbytes_int_int_array_byte_int();
            break;

        case NATIVE_LANG_STRING_GETBYTES_STRING:
            native_method_lang_string_getbytes_string();
            break;

        case NATIVE_LANG_STRING_GETCHARS_INT_INT_ARRAY_CHAR_INT:
            native_method_lang_string_getchars_int_int_array_char_int();
            break;

        case NATIVE_LANG_STRING_HASHCODE:
            native_method_lang_string_hashcode();
            break;

        case NATIVE_LANG_STRING_INDEXOF_INT:
            native_method_lang_string_indexof_int();
            break;

        case NATIVE_LANG_STRING_INDEXOF_INT_INT:
            native_method_lang_string_indexof_int_int();
            break;

        case NATIVE_LANG_STRING_INDEXOF_STRING:
            native_method_lang_string_indexof_string();
            break;

        case NATIVE_LANG_STRING_INDEXOF_STRING_INT:
            native_method_lang_string_indexof_string_int();
            break;

        case NATIVE_LANG_STRING_INTERN:
            native_method_lang_string_intern();
            break;

        case NATIVE_LANG_STRING_ISEMPTY:
            native_method_lang_string_isempty();
            break;

        case NATIVE_LANG_STRING_LASTINDEXOF_INT:
            native_method_lang_string_lastindexof_int();
            break;

        case NATIVE_LANG_STRING_LASTINDEXOF_INT_INT:
            native_method_lang_string_lastindexof_int_int();
            break;

        case NATIVE_LANG_STRING_LASTINDEXOF_STRING:
            native_method_lang_string_lastindexof_string();
            break;

        case NATIVE_LANG_STRING_LASTINDEXOF_STRING_INT:
            native_method_lang_string_lastindexof_string_int();
            break;

        case NATIVE_LANG_STRING_LENGTH:
            native_method_lang_string_length();
            break;

        case NATIVE_LANG_STRING_MATCHES_STRING:
            native_method_lang_string_matches_string();
            break;

        case NATIVE_LANG_STRING_OFFSETBYCODEPOINTS_INT_INT:
            native_method_lang_string_offsetbycodepoints_int_int();
            break;

        case NATIVE_LANG_STRING_REGIONMATCHES_BOOLEAN_INT_STRING_INT_INT:
            native_method_lang_string_regionmatches_boolean_int_string_int_int();
            break;

        case NATIVE_LANG_STRING_REGIONMATCHES_INT_STRING_INT_INT:
            native_method_lang_string_regionmatches_int_string_int_int();
            break;

        case NATIVE_LANG_STRING_REPLACE_CHAR_CHAR:
            native_method_lang_string_replace_char_char();
            break;

        case NATIVE_LANG_STRING_REPLACE_CHARSEQUENCE_CHARSEQUENCE:
            native_method_lang_string_replace_charsequence_charsequence();
            break;

        case NATIVE_LANG_STRING_REPLACEALL_STRING_STRING:
            native_method_lang_string_replaceall_string_string();
            break;

        case NATIVE_LANG_STRING_REPLACEFIRST_STRING_STRING:
            native_method_lang_string_replacefirst_string_string();
            break;

        case NATIVE_LANG_STRING_SPLIT_STRING:
            native_method_lang_string_split_string();
            break;

        case NATIVE_LANG_STRING_SPLIT_STRING_INT:
            native_method_lang_string_split_string_int();
            break;

        case NATIVE_LANG_STRING_STARTSWITH_STRING:
            native_method_lang_string_startswith_string();
            break;

        case NATIVE_LANG_STRING_STARTSWITH_STRING_INT:
            native_method_lang_string_startswith_string_int();
            break;

        case NATIVE_LANG_STRING_SUBSEQUENCE_INT_INT:
            native_method_lang_string_subsequence_int_int();
            break;

        case NATIVE_LANG_STRING_SUBSTRING_INT:
            native_method_lang_string_substring_int();
            break;

        case NATIVE_LANG_STRING_SUBSTRING_INT_INT:
            native_method_lang_string_substring_int_int();
            break;

        case NATIVE_LANG_STRING_TOCHARARRAY:
            native_method_lang_string_tochararray();
            break;

        case NATIVE_LANG_STRING_TOLOWERCASE:
            native_method_lang_string_tolowercase();
            break;

        case NATIVE_LANG_STRING_TOLOWERCASE_LOCALE:
            native_method_lang_string_tolowercase_locale();
            break;

        case NATIVE_LANG_STRING_TOSTRING:
            native_method_lang_string_tostring();
            break;

        case NATIVE_LANG_STRING_TOUPPERCASE:
            native_method_lang_string_touppercase();
            break;

        case NATIVE_LANG_STRING_TOUPPERCASE_LOCALE:
            native_method_lang_string_touppercase_locale();
            break;

        case NATIVE_LANG_STRING_TRIM:
            native_method_lang_string_trim();
            break;

        case NATIVE_LANG_STRING_VALUEOF_BOOLEAN:
            native_method_lang_string_valueof_boolean();
            break;

        case NATIVE_LANG_STRING_VALUEOF_CHAR:
            native_method_lang_string_valueof_char();
            break;

        case NATIVE_LANG_STRING_VALUEOF_ARRAY_CHAR:
            native_method_lang_string_valueof_array_char();
            break;

        case NATIVE_LANG_STRING_VALUEOF_ARRAY_CHAR_INT_INT:
            native_method_lang_string_valueof_array_char_int_int();
            break;

        case NATIVE_LANG_STRING_VALUEOF_DOUBLE:
            native_method_lang_string_valueof_double();
            break;

        case NATIVE_LANG_STRING_VALUEOF_FLOAT:
            native_method_lang_string_valueof_float();
            break;

        case NATIVE_LANG_STRING_VALUEOF_INT:
            native_method_lang_string_valueof_int();
            break;

        case NATIVE_LANG_STRING_VALUEOF_LONG:
            native_method_lang_string_valueof_long();
            break;

        case NATIVE_LANG_STRING_VALUEOF_OBJECT:
            native_method_lang_string_valueof_object();
            break;

        default:
            exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
            break;

    }
}


