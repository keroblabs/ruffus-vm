#ifndef __file_h__
#define __file_h__

///////////////////////////////////////////////////////////////

#include "types.h"
#include "file_module.h"

///////////////////////////////////////////////////////////////

#if defined __MACH__
#define BASE_FILESYSTEM_PATH		"/Users/marciocherobim/Projects/GIT/ruffusvm/disc"
#else
#define BASE_FILESYSTEM_PATH		"C:\\Projects\\Inbox\\ruffusvm\\disc"
#endif

#define ROOT_DIRECTORY_PATH			"/local"

///////////////////////////////////////////////////////////////

#define FS_MODE_READ			0x72
#define FS_MODE_WRITE			0x77
#define FS_MODE_APPEND			0x61
#define FS_MODE_RANDOM			0x62
#define FS_MODE_DEVICE			0x30

#define FS_ENTRY_NOT_FOUND      0
#define FS_IS_FILE              1
#define FS_IS_DIRECTORY         2
#define FS_IS_ROOT_DIR          3
#define FS_IS_DEVICE            4
#define FS_IS_ROOT_SYSTEM       5
#define FS_IS_ROOT_DEVICE       6

#define FILE_OK                     0
#define FILE_EOF                    -1
#define FILE_NOT_FOUND              -2
#define FILE_ALREADY_EXIST          -3
#define FILE_WRITE_ERROR            -4
#define FILE_WRITE_INVALID          -5
#define FILE_INVALID_MODE           -6
#define FILE_INVALID_FS             -7
#define FILE_INVALID_DEVICE         -8
#define FILE_UNABLE_TO_WRITE        -9
#define FILE_INTERNAL_ERROR         -10
#define FILE_DIR_NOT_EMPTY			-11

///////////////////////////////////////////////////////////////

typedef FILE File;

///////////////////////////////////////////////////////////////

void *		file_fopen( const char* full_filename, file_mode_t mode );

char		file_feof(File *file);

uint32_t	file_fread(uint8_t *buf,uint32_t size, uint32_t count, void *file);
uint32_t	file_fwrite (uint8_t* buf,uint32_t size, uint32_t count, void* file); 

void		file_setPos(uint32_t pos, void *file);
uint32_t	file_getPos(void *file);
uint32_t	file_getSize(void *file);

void		file_fclose( void *file );
void        file_fflush( void * file );


///////////////////////////////////////////////////////////////

#endif // __file_h__
