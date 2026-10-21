#ifndef __dir_h__
#define __dir_h__

///////////////////////////////////////////////////////////////

#include "types.h"
#include "file.h"

///////////////////////////////////////////////////////////////

#define MAX_LONG_FILENAME_LENGHT		64

#define ATTR_READ_ONLY  0x01
#define ATTR_HIDDEN     0x02
#define ATTR_SYSTEM     0x04
#define ATTR_VOLUME_ID  0x08
#define ATTR_DIRECTORY  0x10
#define ATTR_ARCHIVE    0x20
#define ATTR_DEVICE     ( 0x80 | ATTR_ARCHIVE | ATTR_DIRECTORY | ATTR_VOLUME_ID )

///////////////////////////////////////////////////////////////

typedef struct _Directory
{
    File * dir_file;
    uint8_t mode;
    uint32_t index;
    
} Directory;

typedef struct
{
	char name[ MAX_LONG_FILENAME_LENGHT ];
	// char fat_name[ 12 ];
	char extension[ 5 ];
	uint8_t attribute;
    
    uint16_t date;
    uint16_t time;
    
    uint32_t size;

} file_info_t;

///////////////////////////////////////////////////////////////

Directory * dir_openFileList( char * path );
int         dir_readFileList( Directory * dir, file_info_t * file_info );
void        dir_closeFileList( Directory * dir );

char        dir_createDirectory( char * full_dirname );



char		dir_locateFile( char * path, file_info_t * file_info );

void		dir_decodeFileEntry( char * entry, file_info_t * file_info );

void		dir_convertFilename( char * path_in, char * path_out );

bool_t		dir_isEmpty( char * path );
int			dir_getFileCount( char * path );

///////////////////////////////////////////////////////////////

#endif // __dir_h__
