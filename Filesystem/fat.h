#ifndef __FAT_H_
#define __FAT_H_

///////////////////////////////////////////////////////////////////////////////

#include "types.h"
#include "fs.h"

///////////////////////////////////////////////////////////////////////////////

uint32_t fat_getSectorAddressFatEntry(FileSystem *fs,uint32_t cluster_addr);
uint32_t fat_getNextClusterAddress(FileSystem *fs,	uint32_t cluster_addr, uint16_t *linear);
void fat_setNextClusterAddress(FileSystem *fs,uint32_t cluster_addr,uint32_t next_cluster_addr);
int fat_isEocMarker(FileSystem *fs,uint32_t fat_entry);
uint32_t fat_giveEocMarker(FileSystem *fs);
uint32_t fat_findClusterAddress(FileSystem *fs,uint32_t cluster,uint32_t offset, uint8_t *linear);
uint32_t fat_getNextClusterAddressWBuf(FileSystem *fs,uint32_t cluster_addr, uint8_t * buf);
void fat_setNextClusterAddressWBuf(FileSystem *fs,uint32_t cluster_addr,uint32_t next_cluster_addr,uint8_t * buf);
int fat_getNextClusterChain(FileSystem *fs, ClusterChain *Cache);
int fat_LogicToDiscCluster(FileSystem *fs, ClusterChain *Cache,uint32_t logiccluster);
int fat_allocClusterChain(FileSystem *fs,ClusterChain *Cache,uint32_t num_clusters);
int fat_unlinkClusterChain(FileSystem *fs,ClusterChain *Cache);
uint32_t fat_countClustersInChain(FileSystem *fs,uint32_t firstcluster);
uint32_t fat_DiscToLogicCluster(FileSystem *fs,uint32_t firstcluster,uint32_t disccluster);
uint32_t fat_countFreeClusters(FileSystem *fs);

///////////////////////////////////////////////////////////////////////////////


#endif
