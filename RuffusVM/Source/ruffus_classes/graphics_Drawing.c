#include "graphics_Drawing.h"
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

///////////////////////////////////////////////////////////////////////////

object_t native_graphics_drawing_new( void )
{
    #if defined WANT_GRAPHICS
	return value_create_int(( int32_t )graphics_get_driver());
    #else
    return value_create_int(0);
    #endif
}

void native_method_graphics_drawing_init()
{
	object_t object;
	object = stack_pop();
}

void native_method_graphics_drawing_clear()
{
    #if defined WANT_GRAPHICS
	lcd_driver_api_t * lcd_driver;

	lcd_driver = ( lcd_driver_api_t * )stack_peek_integer(0);
	
    lcd_driver->clear();
    #endif

    stack_remove(1);    
}

void native_method_graphics_drawing_get_instance()
{
    object_t drawing_object;
    
    drawing_object = native_graphics_drawing_new();
	stack_push( drawing_object );
}

void native_method_graphics_drawing_fill_box()
{
    #if defined WANT_GRAPHICS
	lcd_driver_api_t * lcd_driver;
	uint16_t posx;
	uint16_t posy;
	uint16_t width;
	uint16_t height;
	uint16_t colour;

	colour = ( uint16_t )stack_peek_integer(0);
	height = ( uint16_t )stack_peek_integer(1);
	width = ( uint16_t )stack_peek_integer(2);
	posy = ( uint16_t )stack_peek_integer(3);
	posx = ( uint16_t )stack_peek_integer(4);
	lcd_driver = ( lcd_driver_api_t * )stack_peek_integer(5);
	
	graphics_fill_lcd_color( lcd_driver, posx, posy, width, height, colour );
    #endif

    stack_remove(6);
}

void native_method_graphics_drawing_draw_box()
{
    #if defined WANT_GRAPHICS
	lcd_driver_api_t * lcd_driver;
	uint16_t posx;
	uint16_t posy;
	uint16_t width;
	uint16_t height;
	uint16_t colour;

	colour = ( uint16_t )stack_peek_integer(0);
	height = ( uint16_t )stack_peek_integer(1);
	width = ( uint16_t )stack_peek_integer(2);
	posy = ( uint16_t )stack_peek_integer(3);
	posx = ( uint16_t )stack_peek_integer(4);
	lcd_driver = ( lcd_driver_api_t * )stack_peek_integer(5);
	
	graphics_lcd_line( lcd_driver, posx, posy, posx + width, posy, colour );
	graphics_lcd_line_to_xy( lcd_driver, posx + width, posy + height, colour );
	graphics_lcd_line_to_xy( lcd_driver, posx, posy + height, colour );
	graphics_lcd_line_to_xy( lcd_driver, posx, posy, colour );
    #endif

    stack_remove(6);    
}

void native_method_graphics_drawing_draw_line()
{
    #if defined WANT_GRAPHICS
	lcd_driver_api_t * lcd_driver;
	uint16_t posx1;
	uint16_t posy1;
	uint16_t posx2;
	uint16_t posy2;
	uint16_t colour;

	colour = ( uint16_t )stack_peek_integer(0);
	posy2 = ( uint16_t )stack_peek_integer(1);
	posx2 = ( uint16_t )stack_peek_integer(2);
	posy1 = ( uint16_t )stack_peek_integer(3);
	posx1 = ( uint16_t )stack_peek_integer(4);
	lcd_driver = ( lcd_driver_api_t * )stack_peek_integer(5);
	
	graphics_lcd_line( lcd_driver, posx1, posy1, posx2, posy2, colour );
    #endif

    stack_remove(6);
}

void native_method_graphics_drawing_draw_line_to()
{
    #if defined WANT_GRAPHICS
	lcd_driver_api_t * lcd_driver;
	uint16_t posx2;
	uint16_t posy2;
	uint16_t colour;

	colour = ( uint16_t )stack_peek_integer(0);
	posy2 = ( uint16_t )stack_peek_integer(1);
	posx2 = ( uint16_t )stack_peek_integer(2);
	lcd_driver = ( lcd_driver_api_t * )stack_peek_integer(3);
	
	graphics_lcd_line_to_xy( lcd_driver, posx2, posy2, colour );
    #endif

    stack_remove(4);
}

void native_method_graphics_drawing_set_pixel()
{
    #if defined WANT_GRAPHICS
	lcd_driver_api_t * lcd_driver;
	uint16_t posx;
	uint16_t posy;
	uint16_t colour;
    
    DEBUG_INSTR("set_pixel\r\n");

	colour = ( uint16_t )stack_peek_integer(0);
	posy = ( uint16_t )stack_peek_integer(1);
	posx = ( uint16_t )stack_peek_integer(2);
	lcd_driver = ( lcd_driver_api_t * )stack_peek_integer(3);
	
	graphics_set_pixel( lcd_driver, posx, posy, colour );
    #endif

    stack_remove(4);
}
			
void native_graphics_drawing_get_field(uint16_t mref)
{
}

void native_graphics_drawing_invoke(uint16_t mref)
{
    switch( mref )
    {
        case NATIVE_GRAPHICS_DRAWING_INIT:
            native_method_graphics_drawing_init();
            break;

        case NATIVE_GRAPHICS_DRAWING_GETINSTANCE:
            native_method_graphics_drawing_get_instance();
            break;
            
        case NATIVE_GRAPHICS_DRAWING_CLEAR:
            native_method_graphics_drawing_clear();
            break;

        case NATIVE_GRAPHICS_DRAWING_FILLBOX:
            native_method_graphics_drawing_fill_box();
            break;

        case NATIVE_GRAPHICS_DRAWING_DRAWBOX:
            native_method_graphics_drawing_draw_box();
            break;
            
        case NATIVE_GRAPHICS_DRAWING_DRAWLINE:
            native_method_graphics_drawing_draw_line();
            break;
            
        case NATIVE_GRAPHICS_DRAWING_DRAWLINE_TO:
            native_method_graphics_drawing_draw_line_to();
            break;

        case NATIVE_GRAPHICS_DRAWING_SETPIXEL:
            native_method_graphics_drawing_set_pixel();
            break;

		default:
            exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
            break;            
    }
}

