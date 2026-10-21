#ifndef __vm_file_h__
#define __vm_file_h__

///////////////////////////////////////////////////////////////

#include "types.h"

///////////////////////////////////////////////////////////////

#define VM_ENTRY_NOT_FOUND			0
#define VM_IS_FILE					1
#define VM_IS_DIRECTORY				2
#define VM_IS_ROOT_DIR				3
#define VM_IS_DEVICE				4
#define VM_IS_ROOT_SYSTEM			5
#define VM_IS_ROOT_DEVICE			6

#define VM_FILE_OK                  0
#define VM_FILE_EOF                 -1
#define VM_FILE_NOT_FOUND           -2
#define VM_FILE_ALREADY_EXIST       -3
#define VM_FILE_WRITE_ERROR         -4
#define VM_FILE_WRITE_INVALID       -5
#define VM_FILE_INVALID_MODE        -6
#define VM_FILE_INVALID_FS          -7
#define VM_FILE_INVALID_DEVICE      -8
#define VM_FILE_UNABLE_TO_WRITE     -9
#define VM_FILE_INTERNAL_ERROR      -10
#define VM_FILE_DIR_NOT_EMPTY		-11

///////////////////////////////////////////////////////////////

typedef enum
{
	vm_open_read,
	vm_open_random,
	vm_open_append,
	vm_open_write,
	vm_locate,
	vm_delete,

} file_mode_t;

///////////////////////////////////////////////////////////////

typedef struct _file_stream_t
{
	void * fp;
} file_stream_t;
    
typedef struct _fs_driver_t_
{
	void * ( *open )( const char * path, file_mode_t mode );
	uint32_t ( *read )( uint8_t* buf, uint32_t size, uint32_t count, void* file );
	uint32_t ( *write )( uint8_t* buf, uint32_t size, uint32_t count, void* file );

	void ( *flush )( void * file );
	void ( *close )( void * file );

	void ( *setpos )( uint32_t pos, void * file );
	uint32_t ( *getpos )( void * file );

	uint32_t ( *getsize )( void * file );

} fs_driver_t;

///////////////////////////////////////////////////////////////

void		vm_filesystem_init( void );

int			vm_file_open( file_stream_t * stream, const char * path, file_mode_t mode );
bool_t		vm_file_eof( file_stream_t * stream );
uint32_t	vm_file_write (uint8_t* buf,uint32_t size, uint32_t count, file_stream_t* stream);
uint32_t	vm_file_read(uint8_t *buf,uint32_t size, uint32_t count, file_stream_t *stream);
int			vm_file_getc(file_stream_t *stream);
uint8_t		vm_file_putc( uint8_t data, file_stream_t *stream );
uint32_t	vm_file_puts(const char * text, file_stream_t *stream );
char *		vm_file_gets(char *buf,uint32_t size, file_stream_t *stream);
void		vm_file_set_pos(file_stream_t *stream,uint32_t pos);
uint32_t	vm_file_get_pos(file_stream_t *stream);
uint32_t	vm_file_get_size(file_stream_t *stream);
void		vm_file_close(file_stream_t *stream);
void		vm_file_flush( file_stream_t *stream );

char        vm_file_locate_path( const char * full_filename );
bool_t      vm_file_is_directory( const char * full_filename );
bool_t      vm_file_exists( const char * full_filename );

char		vm_file_delete( char * filename);

///////////////////////////////////////////////////////////////

#endif // __vm_file_h__
