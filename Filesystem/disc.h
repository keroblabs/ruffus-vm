#ifndef __DISC_H_
#define __DISC_H_

///////////////////////////////////////////////////////////////////////////////

#include "types.h"

///////////////////////////////////////////////////////////////////////////////

#define LBA_ADDR_MBR                0
#define PARTITION_TABLE_OFFSET      0x1BE
#define SIZE_PARTITION_FIELD        16

///////////////////////////////////////////////////////////////////////////////

int disc_InitDevice( uint8_t * lun, char * volume );

int disc_ReadSector( uint8_t lun, uint32_t address, uint8_t* buf );
int disc_WriteSector( uint8_t lun, uint32_t address, uint8_t* buf );

int disc_GetSectorCount( uint8_t lun );
int disc_GetSectorSize( uint8_t lun );

int disc_Format( uint8_t lun );

///////////////////////////////////////////////////////////////////////////////

#endif

