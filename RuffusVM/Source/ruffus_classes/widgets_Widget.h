#ifndef NATIVE_RUFFUS_WIDGETS_WIDGET_H
#define NATIVE_RUFFUS_WIDGETS_WIDGET_H

///////////////////////////////////////////////////////////////////////////

#include "datatypes.h"

///////////////////////////////////////////////////////////////////////////

enum
{
    NATIVE_WIDGETS_WIDGET_INIT,
    NATIVE_WIDGETS_WIDGET_ADD_CHILD,
    NATIVE_WIDGETS_WIDGET_SET_COLOUR,
	NATIVE_WIDGETS_WIDGET_SET_CAPTION,
	NATIVE_WIDGETS_WIDGET_UPDATE,
	NATIVE_WIDGETS_WIDGET_SET_POSITION,
	NATIVE_WIDGETS_WIDGET_SHOW,
	NATIVE_WIDGETS_WIDGET_UPDATE_ALL,
    NATIVE_WIDGETS_WIDGET_FINALIZE,
};

enum
{
    NATIVE_FIELD_WIDGETS_WIDGET_OBJECT,
    NATIVE_FIELD_WIDGETS_WIDGET_CAPTION,
    NATIVE_WIDGETS_WIDGET_TOTAL_FIELDS
};

///////////////////////////////////////////////////////////////////////////

object_t native_widgets_widget_new( void );

void native_widgets_widget_invoke(uint16_t mref);
void native_widget_custom_create_invoke( uint32_t mref );
void native_widgets_widget_finalize( object_t object );

///////////////////////////////////////////////////////////////////////////

#endif // NATIVE_RUFFUS_WIDGETS_WIDGET_H


