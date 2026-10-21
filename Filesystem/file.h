#ifndef __FILE_H_
#define __FILE_H_

///////////////////////////////////////////////////////////////////////////////

#include "types.h"
#include "fs_time.h"
#include "fs.h"
#include "dir.h"
#include "fat.h"

///////////////////////////////////////////////////////////////////////////////

#define FS_MODE_READ    0x72
#define FS_MODE_WRITE   0x77
#define FS_MODE_APPEND  0x61
#define FS_MODE_RANDOM  0x62
#define FS_MODE_DEVICE  0x30

#define FILE_STATUS_OPEN    0
#define FILE_STATUS_WRITE   1
#define FILE_STATUS_HEAP    2

#define SEEK_CUR    1
#define SEEK_END    2
#define SEEK_SET    0

#define MAX_LONG_FILENAME_LENGHT		64

///////////////////////////////////////////////////////////////////////////////

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

#define DIR_MODE_ROOT               0
#define DIR_MODE_DIR                1
#define DIR_MODE_SYSTEM             2
#define DIR_MODE_DEVICE             3

#ifndef TIMA_OS
#define SYSCALL_FILE_FOPEN()
#define SYSCALL_FILE_FREAD()
#define SYSCALL_FILE_FWRITE()
#define SYSCALL_FILE_FGETS()
#define SYSCALL_FILE_FIOCTRL()
#define SYSCALL_FILE_FCLOSE()
#define SYSCALL_FILE_FEOF()
#define SYSCALL_FILE_FDELETE()
#define SYSCALL_FILE_LOCATE()
#define SYSCALL_FILE_IS_OPEN()
#endif

///////////////////////////////////////////////////////////////////////////////

typedef struct _device_data_t
{
    const char * name;

    bool_t * in_use;

    void ( *init )( uint32_t index );
    void ( *disable )( uint32_t index );
    void ( *trig_tx )( uint32_t index );
    bool_t ( *validate )( uint32_t index );
    int ( *get_index )( char * param );
    uint32_t ( *io_ctrl )( uint32_t index, uint32_t param, void * value );
    bool_t ( *is_open )( uint32_t index );

    uint8_t dev_mode;

    // for buffer use
    void * rx_channel;
    void * tx_channel;

} device_data_t;

typedef struct
{
	char name[ MAX_LONG_FILENAME_LENGHT ];
	// char fat_name[ 12 ];
	char extension[ 5 ];
	uint8_t attribute;
    
    uint16_t date;
    uint16_t time;
    
    uint32_t size;

} tFileInformation;

typedef struct _device_location_t
{
    device_data_t * device_ptr;
    uint32_t device_index;
    
} DevLocation;

typedef struct _File
{
	FileRecord DirEntry;
	FileLocation Location; /* Location in directory!! */
    DevLocation DevInfo;   /* used for device */
	FileSystem *fs;
	ClusterChain Cache;
	uint8_t	FileStatus;
	uint32_t FilePtr;
	uint32_t FileSize;

} File;

typedef struct _Directory
{
    File dir_file;
    uint8_t mode;
    uint32_t index;
    
} Directory;

///////////////////////////////////////////////////////////////////////////////

char		file_fopen(File* file,char* full_filename,char mode);
char		file_fclose(File *file);
void        file_flush( File * file );

uint32_t	file_fread(uint8_t *buf,uint32_t size,File *file);
uint32_t	file_fwrite (uint8_t* buf,uint32_t size,File* file); 

void		file_setPos(File *file,uint32_t pos);
char		file_feof(File *file);
uint32_t	file_getPos(File *file);

bool_t      file_IsDirectory( const char * full_filename );
bool_t      file_Exists( const char * full_filename );
bool_t      file_isRoot( const char * full_filename );

uint32_t	file_read(uint8_t *buf, uint32_t size, uint32_t offset, File *file);
uint32_t	file_write(uint8_t* buf,uint32_t size,uint32_t offset,File* file);

char*		file_normalToFatName(char* filename,char* fatfilename);
char*		file_normalToFatName2(char* filename,char* fatfilename);

void		file_setAttr(File* file,uint8_t attribute,uint8_t val);
uint8_t		file_getAttr(File* file,uint8_t attribute);
int			file_fputs(File *file, const char * text );
uint32_t	file_fgets(char *buf,uint32_t size,File *file);
int         file_fgetc(File *file);
void        file_fputc( File *file, uint8_t data );
int         file_fprintk( File *file, const char *fmt, ... );
char *		file_getVolume( const char * full_filename, char * volume );

uint32_t    file_get_size( File *file );
uint32_t	file_getSize( const char *file );
char		file_delete( char * filename);

char        file_locatePath( const char * full_filename );

bool_t      file_IsOpen( File * file );

char        dir_openFileList( Directory * dir, char * path );
int         dir_readFileList( Directory * dir, tFileInformation * file_info );
void        dir_closeFileList( Directory * dir );

char        dir_createDirectory( char * full_dirname );

uint32_t	file_fioctrl( File * file, uint32_t param, void * data );

///////////////////////////////////////////////////////////////////////////////


#endif

