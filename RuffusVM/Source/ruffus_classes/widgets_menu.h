#ifndef NATIVE_RUFFUS_WIDGETS_MENU_H
#define NATIVE_RUFFUS_WIDGETS_MENU_H

///////////////////////////////////////////////////////////////////////////

#include "datatypes.h"

///////////////////////////////////////////////////////////////////////////

enum
{
    NATIVE_WIDGETS_MENU_INIT,
	NATIVE_WIDGETS_MENU_INIT_OBJECT,
	NATIVE_WIDGETS_MENU_DISPLAY,
};

enum
{
	NATIVE_FIELD_WIDGETS_MENUITEM_INDEX,
    NATIVE_FIELD_WIDGETS_MENUITEM_CAPTION,
	NATIVE_FIELD_WIDGETS_MENUITEM_HANDLER,
	NATIVE_FIELD_WIDGETS_MENUITEM_MODE,
    NATIVE_WIDGETS_MENUITEM_TOTAL_FIELDS
};

enum
{
	NATIVE_FIELD_WIDGETS_MENU_TITLE,
	NATIVE_FIELD_WIDGETS_MENU_CURR_MESSAGE,
	NATIVE_FIELD_WIDGETS_MENU_CURR_ITEM,
	NATIVE_FIELD_WIDGETS_MENU_IS_CHECK_MENU,
    NATIVE_FIELD_WIDGETS_MENU_ITEMS_VECTOR,

	NATIVE_FIELD_WIDGETS_MENU_START_X,
	NATIVE_FIELD_WIDGETS_MENU_START_Y,
	NATIVE_FIELD_WIDGETS_MENU_TITLE_X,
	NATIVE_FIELD_WIDGETS_MENU_TITLE_Y,
	NATIVE_FIELD_WIDGETS_MENU_SPACING_Y,

	NATIVE_FIELD_WIDGETS_MENU_P_ITEMS,
	NATIVE_FIELD_WIDGETS_MENU_P_CHECKS,
	NATIVE_FIELD_WIDGETS_MENU_DATA,
	NATIVE_FIELD_WIDGETS_MENU_CONFIG,

	NATIVE_FIELD_WIDGETS_MENU_FONT_ITEMS,
	NATIVE_FIELD_WIDGETS_MENU_FONT_TITLE,

    NATIVE_WIDGETS_MENU_TOTAL_FIELDS
};

///////////////////////////////////////////////////////////////////////////

object_t native_widgets_menu_new( void );

void native_widgets_menu_get_field(uint16_t mref);
void native_widgets_menu_invoke(uint16_t mref);

///////////////////////////////////////////////////////////////////////////

#endif // NATIVE_RUFFUS_WIDGETS_MENU_H
