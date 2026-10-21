#ifndef __EXTRACT_H_
#define __EXTRACT_H_

///////////////////////////////////////////////////////////////////////////////

#include "partition.h"
#include "types.h"

///////////////////////////////////////////////////////////////////////////////

#ifdef FS_USE_BIG_ENDIAN

#define ltb_end16(x)  ((((uint16_t)(x) & 0xff00) >> 8) | \
                      (((uint16_t)(x) & 0x00ff) << 8))
#define ltb_end32(x)  ((((uint32_t)(x) & 0xff000000) >> 24) | \
                       (((uint32_t)(x) & 0x00ff0000) >> 8)  | \
                       (((uint32_t)(x) & 0x0000ff00) << 8)  | \
                       (((uint32_t)(x) & 0x000000ff) << 24))

#else

#define ltb_end16(x)  (x)
#define ltb_end32(x)  (x)

#endif

#define btl_end16 ltb_end16
#define btl_end32 ltb_end32


///////////////////////////////////////////////////////////////////////////////

uint16_t ex_getb16(uint8_t* buf,uint32_t offset);
void     ex_setb16(uint8_t* buf,uint32_t offset,uint16_t data);

uint32_t ex_getb32(uint8_t* buf,uint32_t offset);
void     ex_setb32(uint8_t* buf,uint32_t offset,uint32_t data);

void     ex_getPartitionField(uint8_t* buf,PartitionField* pf, uint32_t offset);
void     ex_setPartitionField(uint8_t* buf,PartitionField* pf, uint32_t offset);

///////////////////////////////////////////////////////////////////////////////

#endif

