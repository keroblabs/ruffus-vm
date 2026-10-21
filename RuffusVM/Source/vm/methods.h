#ifndef _METHODS_H_
#define _METHODS_H_

#ifdef	__cplusplus
extern "C" {
#endif
    
///////////////////////////////////////////////////////////////////////////

#include "datatypes.h"

//////////////////////////////////////////////////////////////////////////

#define FLAG_CLINIT					0x80
#define FLAG_NATIVE                 0x40
#define FLAG_STATIC                 0x20
#define FLAG_SYNCHRONIZED           0x10

//////////////////////////////////////////////////////////////////////////

app_method_t * method_find_by_name( object_t object, const char * name, uint32_t * is_native );
app_method_t * method_locate_by_class( uint32_t cref, char * name );

app_method_t * method_get_data( uint16_t index );
char *         method_get_name( app_method_t * ptr_method );

char *         method_get_name_by_index( uint16_t index );

uint8_t *      method_get_address( app_method_t * ptr_method );
uint8_t *      method_get_address_by_index( uint16_t index );

exception_t *  method_get_exception_ptr( app_method_t * ptr_method );
app_debug_t *  method_get_debug_ptr( app_method_t * ptr_method );
uint32_t *	   method_get_argref_ptr( app_method_t * ptr_method );

uint16_t       method_get_line( app_method_t * method, uint8_t * pc );
uint16_t	   method_get_pc_index( app_method_t * method, uint8_t * pc );

//////////////////////////////////////////////////////////////////////////

#ifdef	__cplusplus
}
#endif

#endif // _METHODS_H_
