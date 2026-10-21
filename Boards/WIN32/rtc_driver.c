#include "types.h"
#include "board.h"

///////////////////////////////////////////////////////////////////////////

static time_t start_time;

///////////////////////////////////////////////////////////////////////////

void rtc_driver_init( void )
{
    time( ( time_t * )&start_time );
    start_time = start_time - ( time_t )( ms_timer_get_ms() / 1000 );
}

void rtc_driver_get( time_t * p_value )
{
	*p_value = start_time + ( long )( ms_timer_get_ms() / 1000 );
}

void rtc_driver_set( time_t * p_value )
{
	start_time = *p_value - ( long )( ms_timer_get_ms() / 1000 );
}

///////////////////////////////////////////////////////////////////////////

