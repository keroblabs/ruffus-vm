#include "properties.h"
#include <stdarg.h>

/////////////////////////////////////////////////////////////////////////////

typedef struct _property_t
{
    char * property;
    char * value;
    
    struct _property_t * next;
    
    char buf_property;
    char buf_value;
    
} property_t;

/////////////////////////////////////////////////////////////////////////////

static const char * dummy_property = "";

static property_t * first_property = NULL;
static property_t * last_property = NULL;
static property_t * cursor_property;

/////////////////////////////////////////////////////////////////////////////

char * property_list( bool_t is_first )
{
    char * ret;
    
    if( is_first == TRUE ) cursor_property = first_property;
    if( cursor_property == NULL ) return ( char * )dummy_property;
    
    ret = cursor_property->property;
    cursor_property = cursor_property->next;
    
    return ret;
}

char * property_get( char * input )
{
    property_t * search_property = first_property;
    
    while( search_property != NULL )
    {
        if( !strcmp( search_property->property, input ) )
        {
            return search_property->value;
        }
        
        search_property = search_property->next;
    }
    
    return ( char * )dummy_property;
}

void property_delete( char * input )
{
    property_t * search_property = first_property;
    property_t * prev_property = NULL;
    
    while( search_property != NULL )
    {
        if( !strcmp( search_property->property, input ) )
        {
            if( prev_property != NULL )
            {
                prev_property->next = search_property->next;
            }
            else
            {
                first_property = search_property->next;
            }
            
            if( search_property->next == NULL )
            {
                last_property = prev_property;
            }
            
            free( search_property );
            
            return;
        }
        
        prev_property = search_property;
        search_property = search_property->next;        
    }  
}

void property_set( char * input, char * value )
{
    property_t * search_property = first_property;
    uint32_t size;
    
    while( search_property != NULL )
    {
        if( ( !strcmp( search_property->property, input ) ) &&
            ( strlen( search_property->value ) == strlen( value ) ) )
        {
            strcpy( search_property->value, value );
            return;
        }
        
        search_property = search_property->next;        
    }    
    
    // it's a new property
    size = ( uint32_t )( sizeof( property_t ) + strlen( input ) + strlen( value ) );
    
    search_property = ( property_t * )malloc( size );
    if( search_property == NULL )
    {
        return;
    }
    
    // set new property
    search_property->property = &search_property->buf_property;
    strcpy( search_property->property, input );
    
    search_property->value = &search_property->buf_value + strlen( input );
    strcpy( search_property->value, value );
    
    // link property
    if( first_property == NULL )
    {
        first_property = search_property;
    }
    else
    {
        last_property->next = search_property;
    }
    
    last_property = search_property;
}

/////////////////////////////////////////////////////////////////////////////

