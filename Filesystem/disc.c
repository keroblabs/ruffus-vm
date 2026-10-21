
#include "disc.h"
#include "mass_mal.h"

///////////////////////////////////////////////////////////////////////////////

int disc_InitDevice( uint8_t * lun, char * volume )
{
    // 0 = success
    *lun = MAL_GetLun( volume );
    if( *lun != LUN_NOT_FOUND ) return 0;
    return 1;
}

int disc_ReadSector( uint8_t lun, uint32_t address, uint8_t* buf )
{
    // 0 = success
    return MAL_Read( lun, address, buf, 512 );
}

int disc_WriteSector( uint8_t lun, uint32_t address, uint8_t* buf )
{
    // 0 = success
    return MAL_Write( lun, address, buf, 512 );
}

int disc_GetSectorCount( uint8_t lun )
{
    return (int)MAL_GetBlockCount( lun );
}

int disc_GetSectorSize( uint8_t lun )
{
    return (int)MAL_GetBlockSize( lun );
}

int disc_Format( uint8_t lun )
{
    return MAL_Format( lun );
}



