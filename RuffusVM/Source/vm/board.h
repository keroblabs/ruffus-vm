#ifndef __board_h__
#define __board_h__

///////////////////////////////////////////////////////////////

#include "types.h"

///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////

void ms_timer_hw_init( void );
void ms_timer_driver_init( uint32_t index );

uint32_t ms_timer_get_ms( void );

void rtc_driver_init( void );

void rtc_driver_get( time_t * p_value );
void rtc_driver_set( time_t * p_value );

void board_print( const char * text );

///////////////////////////////////////////////////////////////

#endif // __platform_h__
