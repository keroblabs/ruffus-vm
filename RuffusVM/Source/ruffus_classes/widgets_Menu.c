#include "widgets_Menu.h"
#include "obj_handler.h"
#include "application.h"
#include "methods.h"
#include "threads.h"
#include "arrays_type.h"
#include "util_vector_lib.h"
#include "system_EventArgs.h"
#include "exceptions.h"
#include "native.h"

#ifdef TIMA_OS
#include "system.h"
#endif

#if defined WANT_GRAPHICS
#include "graphics.h"
#include "menu.h"
#endif

///////////////////////////////////////////////////////////////////////////

// use New method implementation to hold a method
// use New implementation to mark start block
// use End new implementation to mark end block to keep

///////////////////////////////////////////////////////////////////////////

#define MENU_EVENT_NONE			0
#define MENU_EVENT_ON_MOVE		1
#define MENU_EVENT_ON_CLICK		2

///////////////////////////////////////////////////////////////////////////

void _native_widgets_menu_on_event( void * p_menu, uint8_t mode )
{
	#if defined WANT_GRAPHICS
	object_t object_menu;
	menu_data_t * menu_data;
	object_t * fields;

	menu_data = ( menu_data_t * )p_menu;
	object_menu = ( object_t )menu_data->p_data;
	fields = object_get_fields_ptr(object_menu);

	value_set_int( fields[NATIVE_FIELD_WIDGETS_MENU_CURR_ITEM], menu_data->config->curr_menu_item );

	// get the menu object
	fields = object_get_fields_ptr( object_menu );

	if( mode == MENU_EVENT_ON_MOVE )
	{
		value_set_int( fields[NATIVE_FIELD_WIDGETS_MENU_CURR_MESSAGE], MENU_EVENT_ON_MOVE );
	}
	else
	{
		value_set_int( fields[NATIVE_FIELD_WIDGETS_MENU_CURR_MESSAGE], MENU_EVENT_ON_CLICK );
	}

#endif
}

void _native_widgets_menu_on_select( void * p_menu )
{
	_native_widgets_menu_on_event( p_menu, MENU_EVENT_ON_CLICK );
}

void _native_widgets_menu_on_move( void * p_menu )
{
	_native_widgets_menu_on_event( p_menu, MENU_EVENT_ON_MOVE );
}

///////////////////////////////////////////////////////////////////////////

object_t native_widgets_menu_new( void )
{
    return( object_create( GET_CLASS_REF( NATIVE_CLASS_RUFFUS_WIDGETS_MENU ), T_CLASS, NATIVE_WIDGETS_MENU_TOTAL_FIELDS ) );
}

void native_widgets_menu_init( void )
{
	stack_pop();
}

void native_widgets_menu_init_object( void )
{
	#if defined WANT_GRAPHICS
	object_t object_menu;
	object_t object_item;
	object_t item_array;
	object_t * fields;
	object_t * fields_item;
	menu_data_t * menu_data;
	menu_item_t * menu_item;
	menu_config_t * menu_config;
	File keypad_hdl;
	uint32_t counter;

	object_menu = stack_peek(0);

	// get object fields
	fields = object_get_fields_ptr( object_menu );

	// create menu data
	fields[NATIVE_FIELD_WIDGETS_MENU_DATA] = object_data_create( T_DATA, sizeof( menu_data_t ) );
	menu_data = ( menu_data_t * )object_get_ptr( fields[NATIVE_FIELD_WIDGETS_MENU_DATA] );
	menu_data->p_data = ( void * )object_menu;
	menu_data->on_menu_move = _native_widgets_menu_on_move;

	// create menu runtime configuration
	fields[NATIVE_FIELD_WIDGETS_MENU_CONFIG] = object_data_create( T_DATA, sizeof( menu_config_t ) );
	menu_config = ( menu_config_t * )object_get_ptr( fields[NATIVE_FIELD_WIDGETS_MENU_CONFIG] );
	menu_data->config = menu_config;

	// set menu information
	if( fields[NATIVE_FIELD_WIDGETS_MENU_SPACING_Y] == 0 )
	{
		fields[NATIVE_FIELD_WIDGETS_MENU_SPACING_Y] = value_create_int( -1 );
	}

	if( value_get_int(fields[NATIVE_FIELD_WIDGETS_MENU_SPACING_Y]) == -1 )
	{
		fields[NATIVE_FIELD_WIDGETS_MENU_START_X] = value_create_int( MENU_START_POSX );
		fields[NATIVE_FIELD_WIDGETS_MENU_START_Y] = value_create_int( MENU_START_POSY );
		fields[NATIVE_FIELD_WIDGETS_MENU_TITLE_X] = value_create_int( MENU_TITLE_POSX );
		fields[NATIVE_FIELD_WIDGETS_MENU_TITLE_Y] = value_create_int( MENU_TITLE_POSY );

		value_set_int( fields[NATIVE_FIELD_WIDGETS_MENU_SPACING_Y], MENU_Y_SPACING );
	}

	menu_data->start_x = value_get_int( fields[NATIVE_FIELD_WIDGETS_MENU_START_X] );
	menu_data->start_y = value_get_int( fields[NATIVE_FIELD_WIDGETS_MENU_START_Y] );
	menu_data->title_x = value_get_int( fields[NATIVE_FIELD_WIDGETS_MENU_TITLE_X] );
	menu_data->title_y = value_get_int( fields[NATIVE_FIELD_WIDGETS_MENU_TITLE_Y] );
	menu_data->spacing_y = value_get_int( fields[NATIVE_FIELD_WIDGETS_MENU_SPACING_Y] );

	menu_data->font_item = value_get_int( fields[NATIVE_FIELD_WIDGETS_MENU_FONT_ITEMS] );
	menu_data->font_title = value_get_int( fields[NATIVE_FIELD_WIDGETS_MENU_FONT_TITLE] );

	strcpy( menu_data->title, strings_get_text_ptr( fields[NATIVE_FIELD_WIDGETS_MENU_TITLE] ) );

	// get the keypad handler
	if( file_IsOpen( &menu_data->config->keypad_driver ) == FALSE )
	{
		if( file_fopen( &keypad_hdl, DEV_KEYPAD, FS_MODE_DEVICE ) != FILE_OK ) return;
	}

	// create list of items
	menu_data->total_items = native_vector_get_data( fields[NATIVE_FIELD_WIDGETS_MENU_ITEMS_VECTOR] )->count;
	fields[NATIVE_FIELD_WIDGETS_MENU_P_ITEMS] = object_data_create( T_DATA, sizeof( menu_item_t ) * menu_data->total_items );
	menu_item = ( menu_item_t * )object_get_ptr( fields[NATIVE_FIELD_WIDGETS_MENU_P_ITEMS] );
	item_array = object_get_fields_ptr( fields[NATIVE_FIELD_WIDGETS_MENU_ITEMS_VECTOR] )[ NATIVE_FIELD_UTIL_VECTOR_ARRAY ];

	if( value_get_boolean(fields[NATIVE_FIELD_WIDGETS_MENU_IS_CHECK_MENU]) == TRUE )
	{
		fields[NATIVE_FIELD_WIDGETS_MENU_P_CHECKS] = object_data_create( T_DATA, sizeof( bool_t ) * menu_data->total_items );
		menu_data->p_check = ( bool_t * )object_get_ptr( fields[NATIVE_FIELD_WIDGETS_MENU_P_CHECKS] );
	}

	for( counter = 0; counter < menu_data->total_items; counter++ )
	{
		array_get( item_array, counter, 1, &object_item );
		fields_item = object_get_fields_ptr( object_item );

		strcpy( menu_item[counter].title, strings_get_text_ptr( fields_item[NATIVE_FIELD_WIDGETS_MENUITEM_CAPTION] ) );
		menu_item[counter].handler = _native_widgets_menu_on_select;
		menu_item[counter].mode = ( item_mode_t )value_get_int( fields_item[NATIVE_FIELD_WIDGETS_MENUITEM_MODE] );
	}

	// set item array
	menu_data->items = menu_item;

	// init menu struct
	menu_init( menu_data, graphics_get_driver(), &keypad_hdl );
	#endif

	stack_remove(1);
}

void native_widgets_menu_display( void )
{
	#if defined WANT_GRAPHICS
	object_t object_menu;
	object_t * fields;
	menu_data_t * menu_data;

	object_menu = stack_peek(0);

	// get the menu object
	fields = object_get_fields_ptr( object_menu );
	menu_data = ( menu_data_t * )object_get_ptr( fields[NATIVE_FIELD_WIDGETS_MENU_DATA] );

	// update display
	menu_display( menu_data );
	#endif

	stack_remove(1);
}

///////////////////////////////////////////////////////////////////////////

void native_widgets_menu_get_field(uint16_t mref)
{
    switch( mref )
    {
		case NATIVE_FIELD_WIDGETS_MENU_CURR_MESSAGE:
            break;

		case NATIVE_FIELD_WIDGETS_MENU_IS_CHECK_MENU:
            break;

		case NATIVE_FIELD_WIDGETS_MENU_ITEMS_VECTOR:
            break;

		default:
            exception_new( NATIVE_CLASS_THROW_LANG_UNSUPPORTEDOPERATIONEXCEPTION, msg_throw_no_such_method );
            break;
	}
}

void native_widgets_menu_invoke(uint16_t mref)
{
    switch( mref )
    {
		case NATIVE_WIDGETS_MENU_INIT:
			native_widgets_menu_init();
            break;

		case NATIVE_WIDGETS_MENU_INIT_OBJECT:
			native_widgets_menu_init_object();
			break;

		case NATIVE_WIDGETS_MENU_DISPLAY:
			native_widgets_menu_display();
			break;

        default:
            exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
            break;
	}
}

