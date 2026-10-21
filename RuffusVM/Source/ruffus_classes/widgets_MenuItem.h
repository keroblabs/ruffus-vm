#ifndef NATIVE_RUFFUS_WIDGETS_MENUITEM_H
#define NATIVE_RUFFUS_WIDGETS_MENUITEM_H

///////////////////////////////////////////////////////////////////////////

#include "datatypes.h"

///////////////////////////////////////////////////////////////////////////

enum
{
    NATIVE_WIDGETS_MENUITEM_INIT,
};

enum
{
	NATIVE_FIELD_WIDGETS_MENUITEM_INDEX,
    NATIVE_FIELD_WIDGETS_MENUITEM_CAPTION,
	NATIVE_FIELD_WIDGETS_MENUITEM_HANDLER,
	NATIVE_FIELD_WIDGETS_MENUITEM_MODE,
    NATIVE_WIDGETS_MENUITEM_TOTAL_FIELDS
};

///////////////////////////////////////////////////////////////////////////

object_t native_widgets_menuitem_new( void );

void native_widgets_menuitem_get_fields(uint16_t mref);
void native_widgets_menuitem_invoke(uint16_t mref);

///////////////////////////////////////////////////////////////////////////

#endif // NATIVE_RUFFUS_WIDGETS_MENUITEM_H


