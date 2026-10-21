#include "widgets_Widget.h"
#include "obj_handler.h"
#include "application.h"
#include "methods.h"
#include "threads.h"
#include "exceptions.h"
#include "native.h"

#ifdef TIMA_OS
#include "system.h"
#endif

#if defined WANT_GRAPHICS
#include "graphics.h"
#endif

///////////////////////////////////////////////////////////////////////////

typedef object_t ( *create_widget_t )( uint16_t width, uint16_t height, char * caption, uint32_t id );

///////////////////////////////////////////////////////////////////////////

object_t native_widgets_widget_new( void )
{
	return object_create( GET_CLASS_REF( NATIVE_CLASS_RUFFUS_WIDGETS_WIDGET ), T_CLASS, NATIVE_WIDGETS_WIDGET_TOTAL_FIELDS );
}

void native_widgets_widget_init( void )
{
	object_t object;
	
	object = stack_pop();
}

void native_widgets_widget_add_child( void )
{
    #if defined WANT_GRAPHICS
	object_t object;
    object_t obj_child;
    //object_t * fields;

	int posx;
	int posy;
	
    posy = stack_peek_integer(0);
    posx = stack_peek_integer(1);
    // obj_child = stack_peek(2);
	// object = stack_peek(3);
    obj_child = object_get_fields_ptr(stack_peek(2))[NATIVE_FIELD_WIDGETS_WIDGET_OBJECT];
    object = object_get_fields_ptr(stack_peek(3))[NATIVE_FIELD_WIDGETS_WIDGET_OBJECT];
    
    widget_add_to_parent( obj_child, object, ( uint16_t )posx, ( uint16_t )posy );
    #endif
    
    stack_remove(4);
}

void native_widgets_widget_set_colour( void )
{
    #if defined WANT_GRAPHICS
	object_t object;
    object_t * fields;
    
	int colour;
	int index;
	
    index = stack_peek_integer(0);
    colour = stack_peek_integer(1);
	object = stack_peek(2);
    
    fields = object_get_fields_ptr( object ); 
    widget_set_colour( fields[NATIVE_FIELD_WIDGETS_WIDGET_OBJECT], ( uint16_t )colour, index );
    #endif
    
    stack_remove(3);    
}

void native_widgets_widget_set_caption( void )
{
    #if defined WANT_GRAPHICS
	object_t object;
    object_t * fields;
	char * caption;
	
    caption = ( char * )stack_peek_addr(0);
	object = stack_peek(1);
    
    fields = object_get_fields_ptr( object );
    widget_set_caption( fields[NATIVE_FIELD_WIDGETS_WIDGET_OBJECT], caption ); 
    fields[NATIVE_FIELD_WIDGETS_WIDGET_CAPTION] = widget_get_caption( fields[NATIVE_FIELD_WIDGETS_WIDGET_OBJECT] );    
    #endif
    
    stack_remove(2);    
}

void native_widgets_widget_update( void )
{
    #if defined WANT_GRAPHICS
	object_t object;
	object_t * fields;
    
	object = stack_peek(0);
    
    fields = object_get_fields_ptr( object );
    widget_update( fields[NATIVE_FIELD_WIDGETS_WIDGET_OBJECT] );
    #endif
    
    stack_remove(1);      
}

void native_widgets_widget_set_position( void )
{
    #if defined WANT_GRAPHICS
	object_t object;
    object_t * fields;
	int posx;
	int posy;
	
    posy = stack_peek_integer(0);
    posx = stack_peek_integer(1);
	object = stack_peek(2);
    
    fields = object_get_fields_ptr( object );
    widget_set_position( fields[NATIVE_FIELD_WIDGETS_WIDGET_OBJECT], ( uint16_t )posx, ( uint16_t )posy );
    #endif
    
    stack_remove(3);    
}

void native_widgets_widget_show( void )
{
    #if defined WANT_GRAPHICS
	object_t object;
    object_t * fields;
	int posx;
	int posy;
	
    posy = stack_peek_integer(0);
    posx = stack_peek_integer(1);
	object = stack_peek(2);
    
    fields = object_get_fields_ptr( object );
    widget_show( fields[NATIVE_FIELD_WIDGETS_WIDGET_OBJECT], ( uint16_t )posx, ( uint16_t )posy );
    #endif
    
    stack_remove(3);   
}

void native_widgets_widget_update_all( void )
{
    #if defined WANT_GRAPHICS
    widget_update_all();
    #endif
}

void native_widgets_widget_finalize( object_t object )
{
    #if defined WANT_GRAPHICS
    object_t * fields;

    fields = object_get_fields_ptr( object );
    widget_destroy( fields[NATIVE_FIELD_WIDGETS_WIDGET_OBJECT] );
    #endif
}

void native_widgets_custom_create( create_widget_t handler )
{
    #if defined WANT_GRAPHICS
    object_t object;
    object_t obj_widget;
    object_t * fields;
	int width;
	int heigth;
    char * caption;
	
    caption = ( char * )stack_peek_addr(0);
    heigth = stack_peek_integer(1);
    width = stack_peek_integer(2);
    
    object = handler( width, heigth, caption, 0 );
    
    obj_widget = native_widgets_widget_new();
    fields = object_get_fields_ptr( obj_widget );
    fields[NATIVE_FIELD_WIDGETS_WIDGET_OBJECT] = object;
    fields[NATIVE_FIELD_WIDGETS_WIDGET_CAPTION] = widget_get_caption( object );
    #endif
    
    stack_remove(3);

    #if defined WANT_GRAPHICS
    stack_push(obj_widget);
    #endif
}

void native_widget_custom_create_invoke( uint32_t mref )
{
    #if defined WANT_GRAPHICS
    switch( GET_CLASS_INDEX( mref ) )
    {
        case NATIVE_CLASS_RUFFUS_WIDGETS_BUTTON:
            native_widgets_custom_create( text_button_create );
            break;
            
        case NATIVE_CLASS_RUFFUS_WIDGETS_TEXT_BOX:
            native_widgets_custom_create( text_box_create );
            break;
            
        case NATIVE_CLASS_RUFFUS_WIDGETS_TEXT_LABEL:
            native_widgets_custom_create( text_label_create);
            break;
            
        case NATIVE_CLASS_RUFFUS_WIDGETS_FORM:
            native_widgets_custom_create( form_create );
            break;
    }
    #endif
}
	
void native_widgets_widget_invoke(uint16_t mref)
{
	switch( mref )
	{
		case NATIVE_WIDGETS_WIDGET_INIT:
            native_widgets_widget_init();
			break;
			
    	case NATIVE_WIDGETS_WIDGET_ADD_CHILD:
            native_widgets_widget_add_child();
			break;
			
    	case NATIVE_WIDGETS_WIDGET_SET_COLOUR:
            native_widgets_widget_set_colour();
			break;
			
		case NATIVE_WIDGETS_WIDGET_SET_CAPTION:
            native_widgets_widget_set_caption();
			break;
			
		case NATIVE_WIDGETS_WIDGET_UPDATE:
            native_widgets_widget_update();
			break;
			
		case NATIVE_WIDGETS_WIDGET_SET_POSITION:
            native_widgets_widget_set_position();
			break;
			
		case NATIVE_WIDGETS_WIDGET_SHOW:
            native_widgets_widget_show();
			break;
			
		case NATIVE_WIDGETS_WIDGET_UPDATE_ALL:
            native_widgets_widget_update_all();
			break;	
            
        case NATIVE_WIDGETS_WIDGET_FINALIZE:
            native_widgets_widget_finalize( stack_peek(0) );
            stack_remove(1);
            break;
		
		default:
			exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
			break;
	}
}

