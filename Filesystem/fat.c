#include "fs.h"

///////////////////////////////////////////////////////////////////////////////

uint32_t fat_getSectorAddressFatEntry(FileSystem *fs,uint32_t cluster_addr)
{ 
	uint32_t base = fs->volumeId.ReservedSectorCount,res;
	
	switch(fs->type){
		case FAT12:
			res=(cluster_addr*3/1024);
			if(res>=fs->FatSectorCount){
				return(0);
			}else{
				return(base+res);
			}
			break;
		case FAT16:
			res=cluster_addr/256;
			if(res>=fs->FatSectorCount){
				return(0);
			}else{
				return(base+res);
			}
			break;
		case FAT32:
			res=cluster_addr/128;
			if(res>=fs->FatSectorCount){
				return(0);
			}else{
				return(base+res);
			}
			break; 
	}
	return(0);
}

uint32_t fat_getNextClusterAddress(FileSystem *fs,uint32_t cluster_addr,uint16_t *linear)
{
	uint8_t *buf; 
	uint8_t hb,lb;
	uint16_t offset;
	uint32_t sector;
	uint32_t nextcluster=0;
	
	sector=fat_getSectorAddressFatEntry(fs,cluster_addr);
	if( (fs->FatSectorCount <= (sector-fs->volumeId.ReservedSectorCount)) || sector==0 )
	{
		return(0);
	}
	
	buf=part_getSect(&fs->part,sector,0);
		
	switch(fs->type)
	{
		case FAT12:
			offset = ( uint16_t )( (((cluster_addr%1024)*3/2)%512) & 0x0FFFF );
			hb = buf[offset];
			if(offset == 511){
				buf=part_getSect(&fs->part,sector+1,0);
				lb = buf[0];
			}else{
				lb = buf[offset + 1];
			}
			if(cluster_addr%2==0){
				nextcluster = ( ((lb&0x0F)<<8) + (hb) );
			}else{
				nextcluster = ( (lb<<4) + (hb>>4) );
			}
			break;
		case FAT16:
			offset=( uint16_t )( ( cluster_addr%256 ) & 0x0FFFF ) ;
			nextcluster = *((uint16_t *)buf + offset);
			break;
		case FAT32:
			offset=( uint16_t )( ( cluster_addr%128 ) & 0x0FFFF );
			nextcluster = *((uint32_t *)buf + offset);
			break;
	}
	
	
	return(nextcluster);
}

void fat_setNextClusterAddress(FileSystem *fs,uint32_t cluster_addr,uint32_t next_cluster_addr)
{
	uint8_t *buf,*buf2; 
	uint16_t offset;
	uint32_t sector;
	
	sector=fat_getSectorAddressFatEntry(fs,cluster_addr);
	
	if(( fs->FatSectorCount <= (sector - fs->volumeId.ReservedSectorCount )||(sector==0))){
	    return;
	}
	
	buf=part_getSect(&fs->part,sector,0);
		
	switch(fs->type){
		case FAT12:
			offset = ( uint16_t )( (((cluster_addr%1024)*3/2)%512 ) & 0x0FFFF );
			if(offset == 511){
				if(cluster_addr%2==0){
					buf[offset]=( uint8_t )( next_cluster_addr&0xFF );
				}else{
					buf[offset]=( uint8_t )( ( buf[offset]&0xF )+ ( ( next_cluster_addr << 4 ) & 0xF0 ) );
				}
				buf2=part_getSect(&fs->part,fat_getSectorAddressFatEntry(fs,cluster_addr)+1,0);
				if(cluster_addr%2==0){
					buf2[0]=( uint8_t )( ((buf2[0]&0xF0)+((next_cluster_addr>>8)&0xF)) & 0x0FF );
				}else{
					buf2[0]=( uint8_t )( (next_cluster_addr>>4)&0xFF );
				}
				part_writeBuf(&fs->part,fat_getSectorAddressFatEntry(fs,cluster_addr)+1,buf2);
			}else{
				if(cluster_addr%2==0){
					buf[offset]=( uint8_t )( next_cluster_addr&0xFF );
					buf[offset+1]=( uint8_t )( (buf[offset+1]&0xF0)+((next_cluster_addr>>8)&0xF));
				}else{
					buf[offset]=( uint8_t )((buf[offset]&0xF)+((next_cluster_addr<<4)&0xF0));
					buf[offset+1]=( uint8_t )((next_cluster_addr>>4)&0xFF );
				}
			}
			part_writeBuf(&fs->part,sector,buf);
			break;
		case FAT16:
			offset=( uint16_t )( ( cluster_addr%256 )& 0x0FFFF );
			*((uint16_t*)buf+offset)=( uint16_t )( next_cluster_addr & 0x0FFFF );
			part_writeBuf(&fs->part,sector,buf);
			break;
		case FAT32:
			offset=( uint16_t )( ( cluster_addr%128 ) & 0x0FFFF );
			*((uint32_t*)buf+offset)=( uint16_t )( next_cluster_addr & 0x0FFFF );
			part_writeBuf(&fs->part,sector,buf);
			break;
	}
	
}

int fat_isEocMarker(FileSystem *fs,uint32_t fat_entry)
{
	switch(fs->type){
		case FAT12:
			if(fat_entry<0xFF8){
				return(0);
			}
			break;
		case FAT16:
			if(fat_entry<0xFFF8){
				return(0);
			}
			break;
		case FAT32:
			if((fat_entry&0x0FFFFFFF)<0xFFFFFF8){
				return(0);
			}
			break;
	}
	return(1);
}

uint32_t fat_giveEocMarker(FileSystem *fs)
{
	switch(fs->type)
	{
		case FAT12:
			return(0xFFF);
			break;
		case FAT16:
			return(0xFFFF);
			break;
		case FAT32:
			return(0x0FFFFFFF);
			break;
	}
	return(0);
}

uint32_t fat_getNextClusterAddressWBuf(FileSystem *fs,uint32_t cluster_addr, uint8_t* buf)
{
	uint8_t  *buf2; /* For FAT12 fallover only */
	uint8_t hb,lb;
	uint16_t offset;
	uint32_t nextcluster=0;
	
	switch(fs->type)
	{
		case FAT12:
			offset = ( uint16_t )( (((cluster_addr%1024)*3/2)%512) & 0x0FFFF );
			hb = buf[offset];
			if(offset == 511){
				buf2=part_getSect(&fs->part,fat_getSectorAddressFatEntry(fs,cluster_addr)+1,0);
				lb = buf2[0];
			}else{
				lb = buf[offset + 1];
			}
			if(cluster_addr%2==0){
				nextcluster = ( ((lb&0x0F)<<8) + (hb) );
			}else{
				nextcluster = ( (lb<<4) + (hb>>4) );
			}
			break;
		case FAT16:
			offset=( uint16_t )( (cluster_addr%256) & 0x0FFFF );
			nextcluster = *((uint16_t*)buf + offset);
			break;
		case FAT32:
			offset=( uint16_t )( (cluster_addr%128) & 0x0FFFF );
			nextcluster = *((uint32_t*)buf + offset);
			break;
	}
	return(nextcluster);
}

void fat_setNextClusterAddressWBuf(FileSystem *fs,uint32_t cluster_addr,uint32_t next_cluster_addr,uint8_t* buf)
{
	uint16_t offset;
	uint8_t *buf2;
		
	switch(fs->type)
	{
		case FAT12:
			offset = ( uint16_t )( (((cluster_addr%1024)*3/2)%512) & 0x0FFFF );
			if(offset == 511){
				if(cluster_addr%2==0){
					buf[offset]=( uint8_t )(next_cluster_addr&0xFF);
				}else{
					buf[offset]=( uint8_t )((buf[offset]&0xF)+((next_cluster_addr<<4)&0xF0));
				}
				buf2=part_getSect(&fs->part,fat_getSectorAddressFatEntry(fs,cluster_addr)+1,0);
				if(cluster_addr%2==0){
					buf2[0]=( uint8_t )((buf2[0]&0xF0)+((next_cluster_addr>>8)&0xF));
				}else{
					buf2[0]=( uint8_t )((next_cluster_addr>>4)&0xFF);
				}
				part_writeBuf(&fs->part,fat_getSectorAddressFatEntry(fs,cluster_addr)+1,buf2);
			}else{
				if(cluster_addr%2==0){
					buf[offset]=( uint8_t )(next_cluster_addr&0xFF);
					buf[offset+1]=( uint8_t )((buf[offset+1]&0xF0)+((next_cluster_addr>>8)&0xF));
				}else{
					buf[offset]=( uint8_t )((buf[offset]&0xF)+((next_cluster_addr<<4)&0xF0));
					buf[offset+1]=( uint8_t )((next_cluster_addr>>4)&0xFF);
				}
			}
			break;
		case FAT16:
			offset=( uint16_t )( (cluster_addr%256) & 0x0FFFF );
			*((uint16_t*)buf+offset)=( uint16_t )(next_cluster_addr&0x0FFFF );
			break;
		case FAT32:
			offset=( uint16_t )( (cluster_addr%128) & 0x0FFFF );
			*((uint32_t*)buf+offset)=next_cluster_addr;
			break;
	}
}

int fat_getNextClusterChain(FileSystem *fs, ClusterChain *Cache)
{
	uint32_t sect,lr,nlr,dc;
	int lin=0;
	uint8_t *buf;

	if(Cache->DiscCluster==0)
	{
		return(-1);
	}

	sect=fat_getSectorAddressFatEntry(fs,Cache->DiscCluster);
	buf=part_getSect(&fs->part,sect,0);
	dc=fat_getNextClusterAddressWBuf(fs,Cache->DiscCluster,buf);
	if(fat_isEocMarker(fs,dc))
	{
		Cache->LastCluster=Cache->DiscCluster;
		return(-1);
	}
	
	Cache->DiscCluster=dc;
	Cache->LogicCluster++;
		
	lr=Cache->DiscCluster-1;
	nlr=lr+1;
	
	while(nlr-1==lr && fat_getSectorAddressFatEntry(fs,nlr)==sect)
	{
		lr=nlr;
		nlr=fat_getNextClusterAddressWBuf(fs,lr,buf);
		lin++;	
	}
	
	Cache->Linear=lin-1<0?0:lin-1;
	
	return(0);
}

int fat_LogicToDiscCluster(FileSystem *fs, ClusterChain *Cache,uint32_t logiccluster)
{
	if(logiccluster<Cache->LogicCluster || Cache->DiscCluster==0){
		Cache->LogicCluster=0;
		Cache->DiscCluster=Cache->FirstCluster;
		Cache->Linear=0;
	}
	
	if(Cache->LogicCluster==logiccluster){
		return(0);
	}
	
	while(Cache->LogicCluster!=logiccluster)
	{
		if(Cache->Linear!=0)
		{
			Cache->Linear--;
			Cache->LogicCluster++;
			Cache->DiscCluster++;
		}
		else
		{
			if((fat_getNextClusterChain(fs,Cache))!=0){
				return(-1);
			}
		}
	}
	return(0);
}

int fat_allocClusterChain(FileSystem *fs,ClusterChain *Cache,uint32_t num_clusters)
{
	uint32_t cc,ncl=num_clusters,lc;
	uint8_t *bufa=0,*bufb=0;
	uint8_t  overflow=0;

	if(Cache->FirstCluster<=1)return(num_clusters);
	
	lc=fs_getLastCluster(fs,Cache);
	cc=lc;
	
	while(ncl > 0){
		cc++;
		if(cc>=fs->DataClusterCount+1){
			if(overflow){
				bufa=part_getSect(&fs->part,fat_getSectorAddressFatEntry(fs,lc),0);
				fat_setNextClusterAddressWBuf(fs,lc,fat_giveEocMarker(fs),bufa);
				Cache->LastCluster=lc;
				part_writeBuf(&fs->part,fat_getSectorAddressFatEntry(fs,lc),bufa);
				fs->FreeClusterCount-=num_clusters-ncl;
				return(num_clusters-ncl);
			}
			cc=2;
			overflow++;
		}
		bufa=part_getSect(&fs->part,fat_getSectorAddressFatEntry(fs,cc),0);
		if(fat_getNextClusterAddressWBuf(fs,cc,bufa)==0){
			bufb=part_getSect(&fs->part,fat_getSectorAddressFatEntry(fs,lc),0);
			fat_setNextClusterAddressWBuf(fs,lc,cc,bufb);
			part_writeBuf(&fs->part,fat_getSectorAddressFatEntry(fs,lc),bufb);
			ncl--;
			lc=cc;
		}
		if(ncl==0){
			bufa=part_getSect(&fs->part,fat_getSectorAddressFatEntry(fs,lc),0);
			fat_setNextClusterAddressWBuf(fs,lc,fat_giveEocMarker(fs),bufa);
			Cache->LastCluster=lc;
			part_writeBuf(&fs->part,fat_getSectorAddressFatEntry(fs,lc),bufa);
		}
	}
	if(Cache->ClusterCount)Cache->ClusterCount+=num_clusters;
	return(0);
}


int fat_unlinkClusterChain(FileSystem *fs,ClusterChain *Cache)
{
	uint32_t c,tbd=0;
	
	Cache->LogicCluster=0;
	Cache->DiscCluster=Cache->FirstCluster;
	
	c=0;
	
	while(!fat_LogicToDiscCluster(fs,Cache,c++)){
		if(tbd!=0){
			fat_setNextClusterAddress(fs,tbd,0);
		}
		tbd=Cache->DiscCluster;
	}
	fat_setNextClusterAddress(fs,Cache->DiscCluster,0);
	fs->FreeClusterCount+=c;	
 	return(0);
}

uint32_t fat_countClustersInChain(FileSystem *fs,uint32_t firstcluster)
{
	ClusterChain cache;
	uint32_t c=0;
	
	if(firstcluster<=1)return(0);
	
	cache.DiscCluster = cache.LogicCluster = cache.LastCluster = cache.Linear = 0;
	cache.FirstCluster = firstcluster;
	
	while(!(fat_LogicToDiscCluster(fs,&cache,c++)));
	
	return(c-1);
}

uint32_t fat_DiscToLogicCluster(FileSystem *fs,uint32_t firstcluster,uint32_t disccluster)
{
	ClusterChain cache;
	uint32_t c=0,r=0;
	
	cache.DiscCluster = cache.LogicCluster = cache.LastCluster = cache.Linear = 0;
	cache.FirstCluster = firstcluster;
	
	while(!(fat_LogicToDiscCluster(fs,&cache,c++)) && !r){
		if(cache.DiscCluster == disccluster){
			r = cache.LogicCluster;
		}
	}
	return(r);
}

uint32_t fat_countFreeClusters(FileSystem *fs)
{
	uint32_t c=2,fc=0;
	
	while(c<=fs->DataClusterCount+1){
		if(fat_getNextClusterAddress(fs,c,0)==0)fc++;
		c++;
	}
	return(fc);
}

