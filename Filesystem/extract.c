#include "extract.h"

///////////////////////////////////////////////////////////////////////////////

#ifdef FS_USE_BYTE_ALIGNMENT

///////////////////////////////////////////////////////////////////////////////

uint16_t ex_getb16(uint8_t* buf,uint32_t offset)
{
	return(ltb_end16(*((uint16_t*)(buf+offset))));
}

uint32_t ex_getb32(uint8_t* buf,uint32_t offset)
{
	return(ltb_end32(*((uint32_t*)(buf+offset))));
}

void ex_setb16(uint8_t* buf,uint32_t offset,uint16_t data)
{
	*((uint16_t*)(buf+offset)) = btl_end16(data);
}

void ex_setb32(uint8_t* buf,uint32_t offset,uint32_t data)
{
	*((uint32_t*)(buf+offset)) = btl_end32(data);
}

void ex_getPartitionField(uint8_t* buf,PartitionField* pf, uint32_t offset)
{
	*pf=*((PartitionField*)(buf+offset));
}

void ex_setPartitionField(uint8_t* buf,PartitionField* pf, uint32_t offset)
{

}

#else

uint16_t ex_getb16(uint8_t* buf,uint32_t offset)
{
	return(ltb_end16(((*(buf+offset+1))<<8) + ((*(buf+offset+0))<<0)));
}

uint32_t ex_getb32(uint8_t* buf,uint32_t offset)
{
	return(ltb_end32(((uint32_t)buf[offset+3]<<24)+
	      ((uint32_t)buf[offset+2]<<16)+
	      ((uint32_t)buf[offset+1]<<8)+
	      ((uint32_t)buf[offset+0]<<0)));
}

void ex_setb16(uint8_t* buf,uint32_t offset,uint16_t data)
{
#ifdef FS_USE_BIG_ENDIAN
	*(buf+offset+1) = data>>0;
	*(buf+offset+0) = data>>8;
#else
	*(buf+offset+0) = data>>0;
	*(buf+offset+1) = data>>8;
#endif
}

void ex_setb32(uint8_t* buf,uint32_t offset,uint32_t data)
{
#ifdef FS_USE_BIG_ENDIAN
	*(buf+offset+3) = data>> 0;
	*(buf+offset+2) = data>> 8;
	*(buf+offset+1) = data>>16;
	*(buf+offset+0) = data>>24;
#else
	*(buf+offset+0) = ( uint8_t )( ( data>> 0 ) & 0x0FF );
	*(buf+offset+1) = ( uint8_t )( ( data>> 8 ) & 0x0FF );
	*(buf+offset+2) = ( uint8_t )( ( data>>16 ) & 0x0FF );
	*(buf+offset+3) = ( uint8_t )( ( data>>24 ) & 0x0FF );
#endif
}

void ex_getPartitionField(uint8_t* buf,PartitionField* pf, uint32_t offset)
{
	pf->bootFlag       = *(buf + offset);
	pf->CHS_begin[0]   = *(buf + offset + 1);
	pf->CHS_begin[1]   = *(buf + offset + 2);
	pf->CHS_begin[2]   = *(buf + offset + 3);
	pf->type           = *(buf + offset + 4);
	pf->CHS_end[0]     = *(buf + offset + 5);
	pf->CHS_end[1]     = *(buf + offset + 6);
	pf->CHS_end[2]     = *(buf + offset + 7);
	pf->LBA_begin      = ex_getb32(buf + offset,8);
	pf->numSectors     = ex_getb32(buf + offset,12);
}

void ex_setPartitionField(uint8_t* buf,PartitionField* pf, uint32_t offset)
{

}

#endif

