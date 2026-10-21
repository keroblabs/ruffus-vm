#include "types.h"
#include "board.h"

///////////////////////////////////////////////////////////////////////////

static bool_t is_init = FALSE;

LARGE_INTEGER n_PerformanceFreq;

///////////////////////////////////////////////////////////////////////////

void ms_timer_hw_init( void )
{
	if( is_init == TRUE ) return;
	is_init = TRUE;

	if( QueryPerformanceFrequency( &n_PerformanceFreq ) == TRUE )
	{
		n_PerformanceFreq.QuadPart /= 1000;
	}
}

void ms_timer_driver_init( uint32_t index )
{
}

uint32_t ms_timer_get_ms( void )
{
	LARGE_INTEGER n_PerformanceCount;

	if( is_init == FALSE ) ms_timer_hw_init();
    
	if( QueryPerformanceCounter( &n_PerformanceCount ) == FALSE )
	{
		return( 0 );
	}

    return ( ( uint32_t )( n_PerformanceCount.LowPart / n_PerformanceFreq.QuadPart ) );
}

