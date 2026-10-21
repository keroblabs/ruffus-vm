#include "file.h"
#include "dir.h"

///////////////////////////////////////////////////////////////

static char local_path[256];
static uint8_t locate_mode;

///////////////////////////////////////////////////////////////

const fs_driver_t board_fs_driver = 
{
	file_fopen,
	file_fread,
	file_fwrite,
	file_fflush,
	file_fclose,

	file_setPos,
	file_getPos,
	file_getSize
};

///////////////////////////////////////////////////////////////

void * file_fopen( const char* full_filename, file_mode_t mode )
{
	char str_mode[5];
	FILE * fp;

	str_mode[0] = 0;

	switch( mode )
	{
		case vm_locate:
		case vm_delete:
		case vm_open_read: strcpy( str_mode, "rb" ); break;
		case vm_open_write: strcpy( str_mode, "wb" ); break;
		case vm_open_append: strcpy( str_mode, "a+b" ); break;
		case vm_open_random: strcpy( str_mode, "w+b" ); break;
		default: return NULL;
	}

	dir_convertFilename( (char*)full_filename, local_path );

	fp = fopen( local_path, str_mode );
	if( fp == NULL ) return NULL;

	if( mode == vm_delete )
	{
		fclose( fp );
		remove( local_path );
		return ( void * )full_filename;
	}

	if( mode == vm_locate )
	{
		locate_mode = VM_IS_FILE;
		fclose( fp );
		return ( void * )&locate_mode;
	}

	return fp;
}

char file_feof(File *file)
{
	return ( char )feof( file );
}

uint32_t file_fwrite (uint8_t* buf,uint32_t size, uint32_t count, void * file)
{
	return (uint32_t)fwrite( buf, size, count, (FILE*)file );
}

uint32_t file_fread(uint8_t *buf,uint32_t size, uint32_t count, void * file)
{
	return (uint32_t)fread( buf, size, count, (FILE*)file );
}

void file_setPos(uint32_t pos, void *file)
{
	long fpos = ( long )pos;
	fseek( (FILE*)file, fpos, SEEK_SET );
}

uint32_t file_getPos(void *file)
{
	long fpos;
	fpos = ftell( (FILE*)file );
	return (uint32_t)fpos;
}

uint32_t file_getSize(void *file)
{
	long fpos;
	long len;

	fpos = ftell( (FILE*)file );
	fseek( (FILE*)file, 0L, SEEK_END );
	len = ftell( (FILE*)file );
	fseek( (FILE*)file, fpos, SEEK_SET );

	return (uint32_t)len;
}

void file_fclose(void *file)
{
	fclose((FILE*)file);
}

void file_fflush( void * file )
{
	fflush((FILE*)file);
}

