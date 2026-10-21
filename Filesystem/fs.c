#include "types.h"
#include "fs.h"
#include "fat.h"
#include "dir.h"
#include "file.h"

///////////////////////////////////////////////////////////////////////////////

#define RAW_FAT12                               0x3231
#define RAW_FAT16                               0x3631
#define RAW_FAT32                               0x3233

///////////////////////////////////////////////////////////////////////////////

int fs_initFs(FileSystem *fs,Partition *part)
{
    //DEBUG_PRINTK( "fs_initFs call\r\n" );
	if(!part_isValidFat(part))
	{
		return(-1);
	}
    //DEBUG_PRINTK( "fs_initFs\r\n" );
	fs_loadVolumeId(fs);
	if(!fs_verifySanity(fs))return(-2);
  	fs_countDataSectors(fs);
	fs_findFirstSectorRootDir(fs);
	fs_initCurrentDir(fs);
	return(0);
}

void fs_loadVolumeId(FileSystem *fs)
{
	uint8_t *buf;
    uint16_t fat_type;

	buf=part_getSect(&fs->part,0,0);

	fs->volumeId.BytesPerSector=ex_getb16(buf,0x0B);
	fs->volumeId.SectorsPerCluster=*((char*)(buf+0x0D));
	fs->volumeId.ReservedSectorCount=ex_getb16(buf,0x0E);
	fs->volumeId.NumberOfFats=*((char*)(buf+0x10));
	fs->volumeId.RootEntryCount=ex_getb16(buf,0x11);
	fs->volumeId.SectorCount16=ex_getb16(buf,0x13);
	fs->volumeId.FatSectorCount16=ex_getb16(buf,0x16);
	fs->volumeId.SectorCount32=ex_getb32(buf,0x20);
	fs->volumeId.FatSectorCount32=ex_getb32(buf,0x24);
	fs->volumeId.RootCluster=ex_getb32(buf,0x2C);

    // set the fat type
    fat_type = ex_getb16(buf,0x39);
    if( fat_type == RAW_FAT12 )
    {
        //DEBUG_PRINTK( "RAW_FAT12\r\n" );
        fs->type=FAT12;
    }
    else if( fat_type == RAW_FAT16 )
    {
        //DEBUG_PRINTK( "RAW_FAT16\r\n" );
        fs->type=FAT16;
    }
    else if( fat_type == RAW_FAT32 )
    {
        //DEBUG_PRINTK( "RAW_FAT32\r\n" );
        fs->type=FAT32;
    }
}

int fs_verifySanity(FileSystem *fs)
{
	int sane=1; /* Sane until proven otherwise */
	/* First check, BPS, we only support 512 */
	if(fs->volumeId.BytesPerSector!=512)sane=0;
	/* Check is SPC is valid (multiple of 2, and clustersize >=32KB */
	if(!((fs->volumeId.SectorsPerCluster == 1 ) |
	     (fs->volumeId.SectorsPerCluster == 2 ) |
	     (fs->volumeId.SectorsPerCluster == 4 ) |
	     (fs->volumeId.SectorsPerCluster == 8 ) |
	     (fs->volumeId.SectorsPerCluster == 16) |
	     (fs->volumeId.SectorsPerCluster == 32) |
	     (fs->volumeId.SectorsPerCluster == 64) ))sane=0;
	/* Any number of FAT's should be supported... (untested) */
	/* There should be at least 1 reserved sector */
	if(fs->volumeId.ReservedSectorCount==0)sane=0;
	if(fs->volumeId.FatSectorCount16 != 0){
		if(fs->volumeId.FatSectorCount16 > fs->part.partitions[fs->part.activePartition].numSectors)sane=0;
	}else{
		if(fs->volumeId.FatSectorCount32 > fs->part.partitions[fs->part.activePartition].numSectors)sane=0;
	}
	return(sane);
}

void fs_countDataSectors(FileSystem *fs)
{
  uint32_t rootDirSectors,dataSectorCount;

  rootDirSectors=((fs->volumeId.RootEntryCount*32) +
                 (fs->volumeId.BytesPerSector - 1)) /
                 fs->volumeId.BytesPerSector;

  if(fs->volumeId.FatSectorCount16 != 0)
  {
    fs->FatSectorCount=fs->volumeId.FatSectorCount16;
    fs->volumeId.FatSectorCount32=0;
  }
  else
  {
    fs->FatSectorCount=fs->volumeId.FatSectorCount32;
    fs->volumeId.FatSectorCount16=0;
  }

  if(fs->volumeId.SectorCount16!=0)
  {
    fs->SectorCount=fs->volumeId.SectorCount16;
    fs->volumeId.SectorCount32=0;
  }
  else
  {
    fs->SectorCount=fs->volumeId.SectorCount32;
    fs->volumeId.SectorCount16=0;
  }

  dataSectorCount=fs->SectorCount - (
                  fs->volumeId.ReservedSectorCount +
                  (fs->volumeId.NumberOfFats * fs->FatSectorCount) +
                  rootDirSectors);

  fs->DataClusterCount=dataSectorCount/fs->volumeId.SectorsPerCluster;
}

void fs_findFirstSectorRootDir(FileSystem *fs)
{
	if(fs->type==FAT32)
		fs->FirstSectorRootDir = fs->volumeId.ReservedSectorCount +
		                         (fs->volumeId.NumberOfFats*fs->volumeId.FatSectorCount32) +
								 (fs->volumeId.RootCluster-2)*fs->volumeId.SectorsPerCluster;
	else
		fs->FirstSectorRootDir = fs->volumeId.ReservedSectorCount +
		                         (fs->volumeId.NumberOfFats*fs->volumeId.FatSectorCount16);
}

void fs_initCurrentDir(FileSystem *fs)
{
	fs->FirstClusterCurrentDir = fs_getFirstClusterRootDir(fs);
}

uint32_t fs_clusterToSector(FileSystem *fs,uint32_t cluster)
{
	uint32_t base;

	if(fs->type==FAT32)
	{
		base=
			fs->volumeId.ReservedSectorCount+
			fs->FatSectorCount*fs->volumeId.NumberOfFats;
	}
	else
	{
		base=
			fs->volumeId.ReservedSectorCount+
			fs->FatSectorCount*fs->volumeId.NumberOfFats+
			fs->volumeId.RootEntryCount/16;
	}
	return( base + (cluster-2)*fs->volumeId.SectorsPerCluster );
}

uint32_t fs_sectorToCluster(FileSystem *fs,uint32_t sector)
{
	uint32_t base;

	if(fs->type==FAT32)
	{
		base=
			fs->volumeId.ReservedSectorCount+
			fs->FatSectorCount*fs->volumeId.NumberOfFats;
	}
	else
	{
		base=
			fs->volumeId.ReservedSectorCount+
			fs->FatSectorCount*fs->volumeId.NumberOfFats+
			fs->volumeId.RootEntryCount/16;
	}
	return(((sector-base)-((sector-base)%fs->volumeId.SectorsPerCluster))/fs->volumeId.SectorsPerCluster+2 );
}

uint32_t fs_getNextFreeCluster(FileSystem *fs,uint32_t startingcluster)
{
	uint32_t r;

	while(startingcluster<fs->DataClusterCount){
		r=fat_getNextClusterAddress(fs,startingcluster,0);
		if(r==0){
			return(startingcluster);
		}
		startingcluster++;
	}
	return(0);
}

uint32_t fs_giveFreeClusterHint(FileSystem *fs)
{
	return(2); /* Now THIS is a hint ;) */
}

char fs_fileDelete(FileSystem *fs,uint8_t* filename)
{
	FileLocation loc;
	ClusterChain cache;
	uint8_t* buf;
	uint32_t firstCluster=0;
    char is_found;
    uint16_t true_offset;
    
    is_found = fs_findFile(fs,(char*)filename,&loc,0);
    
	if( ( is_found == FS_IS_FILE ) || ( is_found == FS_IS_DIRECTORY ) )
	{
		buf=part_getSect(&fs->part,loc.Sector,0);
		firstCluster = ex_getb16(buf,loc.Offset*32+20);
		firstCluster <<= 16;
		firstCluster += ex_getb16(buf,loc.Offset*32+26);
        
        // mark as deleted file
		*(buf+(loc.Offset*32)+0) = 0xE5;
        
        // check for long name entries
        true_offset = ( ( loc.Sector - loc.firstSector ) * 16 ) + loc.Offset;

        while( true_offset > 1 )
        {
            true_offset--;
            if( loc.Offset > 0 ) loc.Offset--;
            else 
            {
                part_writeBuf(&fs->part,loc.Sector,buf);
                loc.Offset = 15;
                loc.Sector--;
                buf=part_getSect(&fs->part,loc.Sector,0);
            }
            
            if( ( ( *(buf+(loc.Offset*32)+0) ) >= 0x41 ) &&
                  ( ( *(buf+(loc.Offset*32)+0) ) <= 0x49 ) )
            {
                *(buf+(loc.Offset*32)+0) = 0xE5;
                *(buf+(loc.Offset*32)+11) = 0x00;
            }
            else
            {
                break;
            }
        }
        
		part_writeBuf(&fs->part,loc.Sector,buf);
		cache.DiscCluster = cache.LastCluster = cache.LogicCluster = cache.Linear = 0;
		cache.FirstCluster = firstCluster;
 		fat_unlinkClusterChain(fs,&cache);
        
		return(FILE_OK);
	}
    
	return(FILE_NOT_FOUND);
}

char fs_findFile(FileSystem *fs,char* filename,FileLocation *loc,uint32_t *lastDir)
{
	static char ffname[128];
	uint32_t fccd,tmpclus;
    char *next,it=0,filefound=0;

	memset( ffname, 0x00, 128 );

	if(*filename=='/'){
		fccd = fs_getFirstClusterRootDir(fs);
        loc->Sector = loc->firstSector = fs->FirstSectorRootDir;
		filename++;
		if(lastDir)*lastDir=fccd;
		if(!*filename){
			return(FS_IS_DIRECTORY);
		}
	}else{
		fccd = fs->FirstClusterCurrentDir;
		if(lastDir)*lastDir=fccd;
	}

	while((next=file_normalToFatName2(filename,ffname))!=0)
	{
		// if((tmpclus=dir_findinDir(fs,filename,fccd,loc,DIRFIND_FILE))==0)
		if((tmpclus=dir_findinDir(fs,ffname,fccd,loc,DIRFIND_FILE))==0)
		{
			/* We didn't find what we wanted */
			/* We should check, to see if there is more after it, so that
			 * we can invalidate lastDir
			 */
			if((file_normalToFatName(next,ffname))!=0)
            {
				if(lastDir)*lastDir=0;
			}
			return(FS_ENTRY_NOT_FOUND);
		}
		it++;
		if(loc->attrib&ATTR_DIRECTORY){
			fccd = tmpclus;
			filename = next;
			if(lastDir)*lastDir=fccd;
			if(filefound)*lastDir=0;
		}else{
			filefound=1;
			if((file_normalToFatName(next,ffname))!=0){
				if(lastDir)*lastDir=0;
				return(FS_ENTRY_NOT_FOUND);
			}else{
				filename=next;
			}
		}
	}

	if(it==0) return(FS_ENTRY_NOT_FOUND);
	if(loc->attrib&ATTR_DIRECTORY || !filefound) return(FS_IS_DIRECTORY);
	return(FS_IS_FILE);
}

int fs_findFreeFile(FileSystem *fs,char* filename,FileLocation *loc,uint8_t mode)
{
	uint32_t targetdir=0;
	char ffname[11];

	if(fs_findFile(fs,filename,loc,&targetdir))return(0);
	if(!dir_getFatFileName(filename,ffname))return(0);
	if(dir_findinDir(fs,ffname,targetdir,loc,DIRFIND_FREE)){
		return(1);
	}else{
		if(dir_addCluster(fs,targetdir)){
			return(0);
		}else{
			if(dir_findinDir(fs,ffname,targetdir,loc,DIRFIND_FREE)){
				return(1);
			}
		}
	}

	return(0);
}

uint32_t fs_getLastCluster(FileSystem *fs,ClusterChain *Cache)
{
	if(Cache->DiscCluster==0){
		Cache->DiscCluster=Cache->FirstCluster;
		Cache->LogicCluster=0;
	}

	if(Cache->LastCluster==0)
	{
		while(fat_getNextClusterChain(fs, Cache)==0)
		{
			Cache->LogicCluster+=Cache->Linear;
			Cache->DiscCluster+=Cache->Linear;
			Cache->Linear=0;
		}
	}
	return(Cache->LastCluster);
}

uint32_t fs_getFirstClusterRootDir(FileSystem *fs)
{
	switch(fs->type){
		case FAT32:
			return(fs->volumeId.RootCluster);
			break;
		default:
				return(1);
				break;
	}
}

void fs_initClusterChain(FileSystem *fs,ClusterChain *cache,uint32_t cluster_addr)
{
	cache->FirstCluster=cluster_addr;
	cache->DiscCluster=cluster_addr;
	cache->LogicCluster=0;
	cache->LastCluster=0; /* Warning flag here */
	cache->Linear=0;
	cache->ClusterCount=0; /* 0 means NOT known */
}

void fs_setFirstClusterInDirEntry(FileRecord *rec,uint32_t cluster_addr)
{
	rec->FirstClusterHigh=( uint16_t )( (cluster_addr>>16) & 0x0FFFF );
	rec->FirstClusterLow=( uint16_t )(cluster_addr&0xFFFF);
}

char fs_clearCluster(FileSystem *fs,uint32_t cluster)
{
	uint16_t c;
	uint8_t* buf;

	for(c=0;c<(fs->volumeId.SectorsPerCluster);c++){
		buf = part_getSect(&fs->part,fs_clusterToSector(fs,cluster)+c,0);
		memset(buf,0x00,512);
		part_writeBuf(&fs->part,fs_clusterToSector(fs,cluster)+c,buf);
	}
	return(0);
}

char fs_getFsInfo(FileSystem *fs,uint8_t force_update)
{
	uint8_t *buf;

 	if(fs->type!=FAT32)return(0);
	buf = part_getSect(&fs->part,FS_INFO_SECTOR,0);
	if(ex_getb32(buf,0)!=FSINFO_MAGIC_BEGIN || ex_getb32(buf,508)!=FSINFO_MAGIC_END){
		return(-1);
	}
	fs->FreeClusterCount = ex_getb32(buf,488);
	fs->NextFreeCluster  = ex_getb32(buf,492);
	if(force_update){
		fs->FreeClusterCount=fat_countFreeClusters(fs);
	}
	return(0);
}

char fs_setFsInfo(FileSystem *fs)
{
	uint8_t* buf;

	if(fs->type!=FAT32)return(0);
	buf = part_getSect(&fs->part,FS_INFO_SECTOR,0);
	if(ex_getb32(buf,0)!=FSINFO_MAGIC_BEGIN || ex_getb32(buf,508)!=FSINFO_MAGIC_END){
		part_writeBuf(&fs->part,FS_INFO_SECTOR,buf);
		return(-1);
	}
	ex_setb32(buf,488,fs->FreeClusterCount);
	ex_setb32(buf,492,fs->NextFreeCluster);
	part_writeBuf(&fs->part,FS_INFO_SECTOR,buf);
	return(0);
}

