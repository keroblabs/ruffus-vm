#include "types.h"
#include "board.h"

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////

void ms_timer_hw_init( void )
{
}

void ms_timer_driver_init( uint32_t index )
{
}

uint32_t ms_timer_get_ms( void )
{
    return ( uint32_t )( clock() / ( CLOCKS_PER_SEC / 1000 ) );
}

