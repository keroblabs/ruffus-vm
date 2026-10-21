
#ifndef __PARTITION_H__
#define __PARTITION_H__

///////////////////////////////////////////////////////////////////////////////

#include "disc.h"
#include "types.h"

///////////////////////////////////////////////////////////////////////////////

#define PT_FAT12  0x01
#define PT_FAT16A 0x04
#define PT_FAT16  0x06
#define PT_FAT32  0x0B
#define PT_FAT32A 0x5C
#define PT_FAT16B 0x5E

///////////////////////////////////////////////////////////////////////////////

typedef struct _PartitionField
{
	uint8_t bootFlag;
	uint8_t CHS_begin[3];
	uint8_t type;
	uint8_t CHS_end[3];
	uint32_t LBA_begin;
	uint32_t numSectors;

} PartitionField;

typedef struct _Partition
{
	uint8_t disc;
 	int activePartition;
	PartitionField partitions[4];

} Partition;

///////////////////////////////////////////////////////////////////////////////

int			part_isValidFat(Partition *part);
void		part_initPartition(Partition *part, uint8_t refDisc);
int			part_isFatPart(uint8_t type);
char		part_directSectorRead(Partition *part, uint32_t address, uint8_t* buf);
char		part_readPartBuf(Partition *part, uint32_t address, uint8_t* buf, uint32_t offset, uint16_t len);
int			part_writeBuf(Partition *part,uint32_t address,uint8_t* buf);
uint8_t*	part_getSect(Partition *part, uint32_t address,uint8_t mode);
char		part_directSectorWrite(Partition *part, uint32_t address, uint8_t* buf);
uint32_t	part_getRealLBA(Partition *part,uint32_t address);
void		part_loadMBR(Partition *part);

///////////////////////////////////////////////////////////////////////////////

#include "extract.h"

///////////////////////////////////////////////////////////////////////////////

#endif
