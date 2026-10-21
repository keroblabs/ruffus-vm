#include "widgets_MenuItem.h"
#include "obj_handler.h"
#include "application.h"
#include "methods.h"
#include "threads.h"
#include "exceptions.h"
#include "native.h"
#include "menu.h"

///////////////////////////////////////////////////////////////////////////

object_t native_widgets_menuitem_new( void )
{
	//return object_create( GET_CLASS_REF( NATIVE_CLASS_RUFFUS_WIDGETS_MENUITEM ), T_CLASS, NATIVE_WIDGETS_MENUITEM_TOTAL_FIELDS );
	return 0;
}

void native_widgets_menuitem_get_fields(uint16_t mref)
{
}

void native_widgets_menuitem_invoke(uint16_t mref)
{
}

