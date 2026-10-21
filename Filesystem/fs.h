#ifndef __FS_H_
#define __FS_H_

///////////////////////////////////////////////////////////////////////////////

#include "types.h"
#include "partition.h"
#include "fs_time.h"

///////////////////////////////////////////////////////////////////////////////

#define FAT12               1
#define FAT16               2
#define FAT32               3
#define SYS_DEVICE          16
#define SYS_ROOT            17
#define SYS_DEVICE_LIST     18

#define FS_INFO_SECTOR 1
#define FSINFO_MAGIC_BEGIN 0x41615252
#define FSINFO_MAGIC_END   0xAA550000

#define FS_ENTRY_NOT_FOUND      0
#define FS_IS_FILE              1
#define FS_IS_DIRECTORY         2
#define FS_IS_ROOT_DIR          3
#define FS_IS_DEVICE            4
#define FS_IS_ROOT_SYSTEM       5
#define FS_IS_ROOT_DEVICE       6

///////////////////////////////////////////////////////////////////////////////

typedef struct _VolumeId
{
	uint16_t BytesPerSector;
	uint8_t SectorsPerCluster;
	uint16_t ReservedSectorCount;
	uint8_t NumberOfFats;
	uint16_t RootEntryCount;
	uint16_t SectorCount16;
	uint16_t FatSectorCount16;
	uint32_t SectorCount32;
	uint32_t FatSectorCount32;
	uint32_t RootCluster;

} VolumeId;

///////////////////////////////////////////////////////////////////////////////

typedef struct _FileSystem
{
	Partition part;
	VolumeId volumeId;

	uint32_t DataClusterCount;
	uint32_t FatSectorCount;
	uint32_t SectorCount;
	uint32_t FirstSectorRootDir;
	uint32_t FirstClusterCurrentDir;
	uint32_t FreeClusterCount;
	uint32_t NextFreeCluster;
	uint8_t type;

} FileSystem;

///////////////////////////////////////////////////////////////////////////////

typedef struct _FileLocation
{
    uint32_t firstSector;
	uint32_t Sector;
	uint8_t Offset;
	uint8_t attrib;

} FileLocation;

///////////////////////////////////////////////////////////////////////////////

typedef struct ClusterChain
{
	uint8_t Linear;
	uint32_t LogicCluster;
	uint32_t DiscCluster;
	uint32_t FirstCluster;
	uint32_t LastCluster;
	uint32_t ClusterCount;

} ClusterChain;

///////////////////////////////////////////////////////////////////////////////

typedef struct FileRecord
{
	uint8_t FileName[11];
	uint8_t Attribute;
	uint8_t NTReserved;
	uint8_t MilliSecTimeStamp;
	uint16_t CreatedTime;
	uint16_t CreatedDate;
	uint16_t AccessDate;
	uint16_t FirstClusterHigh;
	uint16_t WriteTime;
	uint16_t WriteDate;
	uint16_t FirstClusterLow;
	uint32_t FileSize;

} FileRecord;

typedef struct _LongFileRecord
{
	uint8_t long_entry_cnt;
	uint8_t long_name_1[ 10 ];
	uint8_t Attribute;
	uint8_t reserved1;
	uint8_t checksum;
	uint8_t long_name_2[ 12 ];
	uint8_t reserved2[ 2 ];
	uint8_t long_name_3[ 4 ];
    
} LongFileRecord;

///////////////////////////////////////////////////////////////////////////////

int		fs_initFs(FileSystem *fs,Partition *part);
void	fs_loadVolumeId(FileSystem *fs);
int		fs_verifySanity(FileSystem *fs);
void	fs_countDataSectors(FileSystem *fs);
void	fs_findFirstSectorRootDir(FileSystem *fs);
void	fs_initCurrentDir(FileSystem *fs);

char    fs_fileDelete(FileSystem *fs,uint8_t* filename);

uint32_t fs_getSectorAddressRootDir(FileSystem *fs,uint32_t secref);
uint32_t fs_clusterToSector(FileSystem *fs,uint32_t cluster);
uint32_t fs_sectorToCluster(FileSystem *fs,uint32_t sector);
uint32_t fs_getNextFreeCluster(FileSystem *fs,uint32_t startingcluster);
uint32_t fs_giveFreeClusterHint(FileSystem *fs);

int		fs_findFreeFile(FileSystem *fs,char* filename,FileLocation *loc,uint8_t mode);
char	fs_findFile(FileSystem *fs,char* filename,FileLocation *loc,uint32_t *lastDir);
char	fs_findFile_broken(FileSystem *fs,char* filename,FileLocation *loc);

uint32_t fs_getLastCluster(FileSystem *fs,ClusterChain *Cache);
uint32_t fs_getFirstClusterRootDir(FileSystem *fs);

void fs_setFirstClusterInDirEntry(FileRecord *rec,uint32_t cluster_addr);
void fs_initClusterChain(FileSystem *fs,ClusterChain *cache,uint32_t cluster_addr);
char fs_clearCluster(FileSystem *fs,uint32_t cluster);
char fs_getFsInfo(FileSystem *fs,uint8_t force_update);
char fs_setFsInfo(FileSystem *fs);

///////////////////////////////////////////////////////////////////////////////

#endif

