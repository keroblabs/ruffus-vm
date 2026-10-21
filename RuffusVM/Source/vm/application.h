#ifndef APPLICATION_H
#define	APPLICATION_H

#ifdef	__cplusplus
extern "C" {
#endif

///////////////////////////////////////////////////////////////////////////

#include "datatypes.h"
#include "properties.h"
#include "board.h"

///////////////////////////////////////////////////////////////////////////

void app_ruffus_init( void );

uint16_t app_open_file( const char * filename );

uint16_t app_load( app_data_t * vm_app, uint8_t * buffer, uint32_t size, bool_t is_rom );

uint32_t app_class_total_fields( uint32_t class_ref );
uint32_t app_get_super_class( uint32_t class_ref );

app_data_t * app_get_vm( uint16_t index );
app_data_t * app_execute_vm( void );

void * app_get_file_buffer( app_data_t * app_data );

app_data_t * app_get_app_chain( app_data_t * app );

void app_error_heap_corrupted( void );
void app_error_memory_overflow( void );

void app_set_exit( app_data_t * app );

uint16_t app_get_count( void );
void     app_kill_all( void );
void     app_kill( uint16_t index );

void     app_set_printk_mode( bool_t mode );
void     app_set_debug_mode( bool_t mode );
uint16_t app_debug_set_state( uint8_t state );

app_instance_t * app_locate_java_method_by_class_name( char * class_name, char * method_name, app_java_call_t * call_env );
app_instance_t * app_locate_java_method_by_class( object_t class_object, char * method_name, app_java_call_t * call_env );
app_instance_t * app_locate_java_method_by_object( object_t object, char * method_name, app_java_call_t * call_env );

void     app_java_call_start( app_java_call_t * call_env );
void     app_java_call_add_param( app_java_call_t * call_env, object_t param );
void     app_java_call_finish( app_java_call_t * call_env );
object_t app_java_call_execute( object_t object, app_java_call_t * call_env );
char *   app_get_class_name( uint32_t cref );

///////////////////////////////////////////////////////////////////////////

#ifdef	__cplusplus
}
#endif

#endif	/* APPLICATION_H */

