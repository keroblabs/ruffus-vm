#include "partition.h"
#include "types.h"

///////////////////////////////////////////////////////////////////////////////

static uint8_t sbuffer[512];

///////////////////////////////////////////////////////////////////////////////

void part_initPartition(Partition *part, uint8_t refDisc)
{
	int c;

	part->disc = refDisc;
	part->activePartition=-1; /* No partition selected */

	part_loadMBR( part );

	for(c=3;c>=0;c--)
	{
		if(part_isFatPart(part->partitions[c].type))
			part->activePartition=c;
	}
}

int part_isValidFat(Partition *part)
{
	uint8_t *buf;

	buf=part_getSect(part,0,0); /* Load Volume label */
	if( ex_getb16(buf,0x1FE) != 0xAA55 )
	{
		return (0);
	}
	return(1);
}

int part_isFatPart(uint8_t type)
{
	if( ( type == PT_FAT12  ) ||
	    ( type == PT_FAT16A ) ||
	    ( type == PT_FAT16  ) ||
	    ( type == PT_FAT32  ) ||
	    ( type == PT_FAT32A ) ||
	    ( type == PT_FAT16B )  )
	{
		return(1);
	}
	return(0);
}

char part_directSectorRead(Partition *part, uint32_t address, uint8_t* buf)
{
	return( disc_ReadSector(part->disc,part_getRealLBA(part,address), buf) );
}

int part_writeBuf(Partition *part,uint32_t address,uint8_t* buf)
{
	return(disc_WriteSector(part->disc,part_getRealLBA(part,address),buf));
}

uint32_t part_getRealLBA(Partition *part,uint32_t address)
{
	return(part->partitions[part->activePartition].LBA_begin+address);
}

uint8_t* part_getSect(Partition *part, uint32_t address, uint8_t mode)
{
	disc_ReadSector(part->disc, part_getRealLBA(part,address), sbuffer);
	return( sbuffer );
}

void part_loadMBR(Partition *part)
{
	uint32_t x;

	disc_ReadSector( part->disc, 0x00, sbuffer );

#if 0 // def DEBUG
    for( x = 0; x < 512; x++ )
    {
        if( ( ( x & 0x1f ) == 0 ) && ( x != 0 ) ) DEBUG_PRINTK( "\n" );
        DEBUG_PRINTK( "%02X ", part->sbuffer[x] );
    }
    DEBUG_PRINTK( "\n" );
#endif

    if( ( ( sbuffer[ 0 ] == 0 ) && ( sbuffer[ 1 ] == 0 ) && ( sbuffer[ 2 ] == 0 ) &&
          ( sbuffer[ 510 ] == 0 ) && ( sbuffer[ 511 ] == 0 ) ) ||
        ( ( sbuffer[ 510 ] == 255 ) && ( sbuffer[ 511 ] == 255 ) ) )
    {
        // unit is not formated
        disc_Format( part->disc );
    
        disc_ReadSector( part->disc, 0x00, sbuffer );
    }
    
    if( ( sbuffer[ 0x1bc ] == 0 ) && ( sbuffer[ 0x1bd ] == 0 ) )
    {
    	for(x=0;x<4;x++)
        {
    		ex_getPartitionField(sbuffer, &(part->partitions[x]),PARTITION_TABLE_OFFSET+(x*SIZE_PARTITION_FIELD));

            /*
            DEBUG_PRINTK( "Partition %d: 0x%08X, %d 0x%02x\r\n", x,
                                                                 part->partitions[x].LBA_begin,
                                                                 part->partitions[x].numSectors,
                                                                 part->partitions[x].type );  */
    	}

    }
    else
    {
        if( ( sbuffer[ 510 ] != 0x55 ) || ( sbuffer[ 511 ] != 0xAA ) )
        {
            // unit is not formated
            disc_Format( part->disc );

            disc_ReadSector( part->disc, 0x00, sbuffer );
        }
        
        memset( part->partitions, 0x00, sizeof( part->partitions ) );

        part->partitions[0].bootFlag = 0x00;
        part->partitions[0].type = 0x01;
   		part->partitions[0].LBA_begin = 0;
        part->partitions[0].numSectors = ( uint32_t )disc_GetSectorCount( part->disc );
    }
}

char part_directSectorWrite(Partition *part,uint32_t address, uint8_t* buf)
{
	disc_WriteSector(part->disc, part_getRealLBA(part,address),buf);
	return( 0 );
}

