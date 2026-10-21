#ifndef NATIVE_RUFFUS_GRAPHICS_DRAWING_H
#define NATIVE_RUFFUS_GRAPHICS_DRAWING_H

///////////////////////////////////////////////////////////////////////////

#include "datatypes.h"

///////////////////////////////////////////////////////////////////////////

enum
{
    NATIVE_GRAPHICS_DRAWING_INIT,
	NATIVE_GRAPHICS_DRAWING_GETINSTANCE,
	
    NATIVE_GRAPHICS_DRAWING_CLEAR,
	NATIVE_GRAPHICS_DRAWING_FILLBOX,
	NATIVE_GRAPHICS_DRAWING_DRAWBOX,
	NATIVE_GRAPHICS_DRAWING_DRAWLINE,
	NATIVE_GRAPHICS_DRAWING_DRAWLINE_TO,
    NATIVE_GRAPHICS_DRAWING_SETPIXEL,
};

enum
{
    NATIVE_FIELD_GRAPHICS_DRAWING_LCD_DRIVER,
    NATIVE_GRAPHICS_DRAWING_TOTAL_FIELDS
};

///////////////////////////////////////////////////////////////////////////

object_t native_graphics_drawing_new( void );

void native_graphics_drawing_get_field(uint16_t mref);
void native_graphics_drawing_invoke(uint16_t mref);

///////////////////////////////////////////////////////////////////////////

#endif // NATIVE_RUFFUS_GRAPHICS_DRAWING_H


