#include "util_stringtokenizer.h"
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

object_t native_util_stringtokenizer_new( void )
{
    return( object_create( GET_CLASS_REF( NATIVE_CLASS_UTIL_STRINGTOKENIZER ), T_CLASS, NATIVE_UTIL_STRINGTOKENIZER_TOTAL_FIELDS ) );
}

///////////////////////////////////////////////////////////////////////////

void native_method_util_stringtokenizer_init_string( void )
{
    // StringTokenizer(String str)
    // Constructs a string tokenizer for the specified string. 
    // Implementation code: D275C090
    object_t string_str;
    object_t object;
    token_data_t * token_data;
    object_t * fields;

    string_str = stack_peek(0);
    object = stack_peek(1);

    // put your code here
    object_create_extension( object, sizeof( token_data_t ) );
    token_data = ( token_data_t * )object_get_extension( object );
    
    fields = object_get_fields_ptr( object );
    fields[ NATIVE_FIELD_UTIL_STRINGTOKENIZER_STRING ] = strings_create( strings_get_text_ptr( string_str ) );
    fields[ NATIVE_FIELD_UTIL_STRINGTOKENIZER_DELIM_STRING ] = strings_create( " \r\t\n" );
            
    token_data->last_token = NULL;
    token_data->return_delim = FALSE;
    token_data->p_str_data = strings_get_text_ptr( fields[ NATIVE_FIELD_UTIL_STRINGTOKENIZER_STRING ] );
    token_data->p_str_delim = strings_get_text_ptr( fields[ NATIVE_FIELD_UTIL_STRINGTOKENIZER_DELIM_STRING ] );    
    token_data->input_data = token_data->p_str_data;
    
    if( strlen( token_data->p_str_data ) == 0 )
    {
        exception_new( NATIVE_CLASS_THROW_LANG_NULLPOINTEREXECPTION, msg_throw_null_pointer );
    }    
    
    stack_remove(2);
}

void native_method_util_stringtokenizer_init_string_string( void )
{
    // StringTokenizer(String str, String delim)
    // Constructs a string tokenizer for the specified string. 
    // Implementation code: D275C090
    object_t string_delim;
    object_t string_str;
    object_t object;
    token_data_t * token_data;
    object_t * fields;
    
    string_delim = stack_peek(0);
    string_str = stack_peek(1);
    object = stack_peek(2);

    // put your code here
    object_create_extension( object, sizeof( token_data_t ) );
    token_data = ( token_data_t * )object_get_extension( object );
    
    fields = object_get_fields_ptr( object );
    fields[ NATIVE_FIELD_UTIL_STRINGTOKENIZER_STRING ] = strings_create( strings_get_text_ptr( string_str ) );
    fields[ NATIVE_FIELD_UTIL_STRINGTOKENIZER_DELIM_STRING ] = strings_create( strings_get_text_ptr( string_delim ) );
            
    token_data->last_token = NULL;
    token_data->return_delim = FALSE;
    token_data->p_str_data = strings_get_text_ptr( fields[ NATIVE_FIELD_UTIL_STRINGTOKENIZER_STRING ] );
    token_data->p_str_delim = strings_get_text_ptr( fields[ NATIVE_FIELD_UTIL_STRINGTOKENIZER_DELIM_STRING ] );    
    token_data->input_data = token_data->p_str_data;
    
    if( strlen( token_data->p_str_data ) == 0 )
    {
        exception_new( NATIVE_CLASS_THROW_LANG_NULLPOINTEREXECPTION, msg_throw_null_pointer );
    }    
    
    stack_remove(3);
}

void native_method_util_stringtokenizer_init_string_string_boolean( void )
{
    // StringTokenizer(String str, String delim, boolean returnDelims)
    // Constructs a string tokenizer for the specified string. 
    // Implementation code: D275C090
    object_t boolean_returnDelims;
    object_t string_delim;
    object_t string_str;
    object_t object;
    token_data_t * token_data;
    object_t * fields;
    
    boolean_returnDelims = stack_peek(0);
    string_delim = stack_peek(1);
    string_str = stack_peek(2);
    object = stack_peek(3);

    // put your code here
    object_create_extension( object, sizeof( token_data_t ) );
    token_data = ( token_data_t * )object_get_extension( object );
    
    fields = object_get_fields_ptr( object );
    fields[ NATIVE_FIELD_UTIL_STRINGTOKENIZER_STRING ] = strings_create( strings_get_text_ptr( string_str ) );
    fields[ NATIVE_FIELD_UTIL_STRINGTOKENIZER_DELIM_STRING ] = strings_create( strings_get_text_ptr( string_delim ) );
            
    token_data->last_token = NULL;
    token_data->return_delim = value_get_boolean( boolean_returnDelims );
    token_data->p_str_data = strings_get_text_ptr( fields[ NATIVE_FIELD_UTIL_STRINGTOKENIZER_STRING ] );
    token_data->p_str_delim = strings_get_text_ptr( fields[ NATIVE_FIELD_UTIL_STRINGTOKENIZER_DELIM_STRING ] );    
    token_data->input_data = token_data->p_str_data;

    if( strlen( token_data->p_str_data ) == 0 )
    {
        exception_new( NATIVE_CLASS_THROW_LANG_NULLPOINTEREXECPTION, msg_throw_null_pointer );
    }    
    
    stack_remove(4);
}

///////////////////////////////////////////////////////////////////////////

void native_method_util_stringtokenizer_counttokens( void )
{
    // int countTokens()
    // Calculates the number of times that this tokenizer's nextToken 
    // method can be called before it generates an exception. 
    // Implementation code: CEFA3A05
    object_t object;
    object_t ret_object;
    int32_t ret_value = 0;
    token_data_t * token_data;
    char * str_temp;
    char * last_token;
    char * out;
    int size;

    object = stack_peek(0);

    // put your code here
    token_data = ( token_data_t * )object_get_extension( object );
    
    if( strlen( token_data->p_str_delim ) == 0 )
    {
        exception_new( NATIVE_CLASS_THROW_LANG_NULLPOINTEREXECPTION, msg_throw_null_pointer );
    }
    
    // save current position
    last_token = token_data->last_token;
    str_temp = token_data->input_data;
    
	while (strings_tokenizer(str_temp, ( const char ** )&out, &size, token_data->p_str_delim, &last_token)) 
	{
        ret_value++;
		str_temp = NULL;
	}    

    // return type: int
    ret_object = value_create_int( ret_value );
    stack_remove(1);
    stack_push( ret_object );    
}

void native_method_util_stringtokenizer_hasmoreelements( void )
{
    // boolean hasMoreElements()
    // Returns the same value as the hasMoreTokens method. 
    // Implementation code: 3FA09D8E
    object_t object;
    bool_t ret_value = 0;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: boolean
    stack_push( value_create( &ret_value, T_BOOLEAN ) );
}

void native_method_util_stringtokenizer_hasmoretokens( void )
{
    // boolean hasMoreTokens()
    // Tests if there are more tokens available from this tokenizer's 
    // string. 
    // Implementation code: 027B9673
    object_t object;
    object_t ret_object;
    bool_t ret_value = 0;
    token_data_t * token_data;
    char * str_temp;
    char * last_token;
    char * out;
    int size;
    
    object = stack_peek(0);

    // put your code here
    token_data = ( token_data_t * )object_get_extension( object );
    
    if( strlen( token_data->p_str_delim ) == 0 )
    {
        exception_new( NATIVE_CLASS_THROW_LANG_NULLPOINTEREXECPTION, msg_throw_null_pointer );
    }

    // save current position
    last_token = token_data->last_token;
    str_temp = token_data->input_data;
    
	if( strings_tokenizer( str_temp, ( const char ** )&out, &size, token_data->p_str_delim, &last_token ) ) 
	{
        ret_value = TRUE;
	}    
    
    // return type: boolean
    ret_object = value_create_boolean( ret_value );
    stack_remove(1);
    stack_push( ret_object );
}

void native_method_util_stringtokenizer_nextelement( void )
{
    // Object nextElement()
    // Returns the same value as the nextToken method, except that 
    // its declared return value is Object rather than String. 
    // Implementation code: 486A7515
    object_t object;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: Object
    stack_push( 0 );
}

void native_method_util_stringtokenizer_nexttoken( void )
{
    // String nextToken()
    // Returns the next token from this string tokenizer. 
    // Implementation code: 07B96349
    object_t object;
    object_t object_out;
    token_data_t * token_data;
    char * out;
    int size;
    char * str_out;
    
    object = stack_peek(0);

    // put your code here
    token_data = ( token_data_t * )object_get_extension( object );
    
    if( strlen( token_data->p_str_delim ) == 0 )
    {
        exception_new( NATIVE_CLASS_THROW_LANG_NULLPOINTEREXECPTION, msg_throw_null_pointer );
    }
    
	if( strings_tokenizer( token_data->input_data, ( const char ** )&out, &size, token_data->p_str_delim, &token_data->last_token ) == FALSE ) 
	{
        exception_new( NATIVE_CLASS_THROW_UTIL_NOSUCHELEMENTEXCEPTION, msg_throw_no_such_element );
	}  
    
    token_data->input_data = NULL;
    
    if( size == 0 )
    {
        object_out = strings_create( "" );
    }
    else
    {
        object_out = strings_create_capacity( size + 1 );
        str_out = strings_get_text_ptr( object_out );
        strncpy( str_out, out, size );
		str_out[size] = 0;
    }

    // return type: String
    stack_remove(1);
    stack_push( object_out );
}

void native_method_util_stringtokenizer_nexttoken_string( void )
{
    // String nextToken(String delim)
    // Returns the next token in this string tokenizer's string. 
    // Implementation code: FCA3BD57
    object_t string_delim;
    object_t object;
    object_t object_out;
    token_data_t * token_data;
    char * out;
    int size;
    char * str_out;
    char * str_delim;
    
    string_delim = stack_peek(0);
    object = stack_peek(1);

    // put your code here
    token_data = ( token_data_t * )object_get_extension( object );
    str_delim = strings_get_text_ptr( string_delim );
    
    if( strlen( str_delim ) == 0 )
    {
        exception_new( NATIVE_CLASS_THROW_LANG_NULLPOINTEREXECPTION, msg_throw_null_pointer );
    }
    
	if( strings_tokenizer( token_data->input_data, ( const char ** )&out, &size, str_delim, &token_data->last_token ) == FALSE ) 
	{
        exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
	}  
    
    if( size == 0 )
    {
        object_out = strings_create( "" );
    }
    else
    {
        object_out = strings_create_capacity( size + 1 );
        str_out = strings_get_text_ptr( object_out );
        strncpy( str_out, out, size );
		str_out[size] = 0;
    }

    // return type: String
    stack_remove(2);
    stack_push( object_out );
}

///////////////////////////////////////////////////////////////////////////

void native_util_stringtokenizer_invoke(uint16_t mref)
{
    switch( mref )
    {
        case NATIVE_UTIL_STRINGTOKENIZER_INIT_STRING:
            native_method_util_stringtokenizer_init_string();
            break;

        case NATIVE_UTIL_STRINGTOKENIZER_INIT_STRING_STRING:
            native_method_util_stringtokenizer_init_string_string();
            break;

        case NATIVE_UTIL_STRINGTOKENIZER_INIT_STRING_STRING_BOOLEAN:
            native_method_util_stringtokenizer_init_string_string_boolean();
            break;

        case NATIVE_UTIL_STRINGTOKENIZER_COUNTTOKENS:
            native_method_util_stringtokenizer_counttokens();
            break;

        case NATIVE_UTIL_STRINGTOKENIZER_HASMOREELEMENTS:
            native_method_util_stringtokenizer_hasmoreelements();
            break;

        case NATIVE_UTIL_STRINGTOKENIZER_HASMORETOKENS:
            native_method_util_stringtokenizer_hasmoretokens();
            break;

        case NATIVE_UTIL_STRINGTOKENIZER_NEXTELEMENT:
            native_method_util_stringtokenizer_nextelement();
            break;

        case NATIVE_UTIL_STRINGTOKENIZER_NEXTTOKEN:
            native_method_util_stringtokenizer_nexttoken();
            break;

        case NATIVE_UTIL_STRINGTOKENIZER_NEXTTOKEN_STRING:
            native_method_util_stringtokenizer_nexttoken_string();
            break;

        default:
            exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
            break;

    }
}


