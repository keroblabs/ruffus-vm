#include "file_module.h"
#include "vm.h"

///////////////////////////////////////////////////////////////

static char local_path[256];
static fs_driver_t * fs_driver;

///////////////////////////////////////////////////////////////

void vm_filesystem_init( void )
{
	extern const fs_driver_t board_fs_driver;
	fs_driver = ( fs_driver_t * )&board_fs_driver;
}

int vm_file_open( file_stream_t * stream, const char * path, file_mode_t mode )
{
	stream->fp = fs_driver->open( path, mode );
	if( stream->fp == NULL ) return VM_FILE_NOT_FOUND;

	return VM_FILE_OK;
}

bool_t vm_file_eof( file_stream_t * stream )
{
	if( fs_driver->getpos( stream->fp ) >= fs_driver->getsize( stream->fp ) ) return TRUE;
	return FALSE;
}

uint32_t vm_file_write (uint8_t* buf,uint32_t size, uint32_t count, file_stream_t* stream)
{
	return fs_driver->write( buf, size, count, stream->fp );
}

uint32_t vm_file_read(uint8_t *buf,uint32_t size, uint32_t count, file_stream_t *stream)
{
	return fs_driver->read( buf, size, count, stream->fp );
}

int vm_file_getc(file_stream_t *stream)
{
	uint8_t c;
	if( fs_driver->read( &c, 1, 1, stream->fp ) < 1 ) return -1;
	return c;
}

uint8_t vm_file_putc( uint8_t data, file_stream_t *stream )
{
	fs_driver->write( &data, 1, 1, stream->fp );
	return 1;
}

uint32_t vm_file_puts(const char * text, file_stream_t *stream )
{
	return fs_driver->write( ( uint8_t * )text, strlen( text ), 1, stream->fp );
}

char * vm_file_gets(char *buf,uint32_t size, file_stream_t *stream)
{
	int c;
	int index;

	index = 0;

	do
	{
		c = vm_file_getc( stream );
		if( c == -1 ) c = 0;

		buf[index++] = (char)c;

	} while( c != 0 );

	return buf;
}

void vm_file_set_pos(file_stream_t *stream,uint32_t pos)
{
	fs_driver->setpos( pos, stream->fp );
}

uint32_t vm_file_get_pos(file_stream_t *stream)
{
	return fs_driver->getpos( stream->fp );
}

uint32_t vm_file_get_size(file_stream_t *stream)
{
	return fs_driver->getsize( stream->fp );
}

void vm_file_close(file_stream_t *stream)
{
	fs_driver->close( stream->fp );
}

void vm_file_flush( file_stream_t *stream )
{
	fs_driver->flush( stream->fp );
}

char vm_file_locate_path( const char * full_filename )
{
	uint8_t * file;
	char type;

	file = (uint8_t *)fs_driver->open( full_filename, vm_locate );
	if( file == NULL ) return VM_FILE_NOT_FOUND;

	type = ( char )( *file );

	return type;
}

bool_t vm_file_is_directory( const char * full_filename )
{
	if( vm_file_locate_path( full_filename ) == VM_IS_DIRECTORY ) return TRUE;
	return FALSE;
}

bool_t vm_file_exists( const char * full_filename )
{
	if( vm_file_locate_path( full_filename ) == VM_ENTRY_NOT_FOUND ) return FALSE;
	return TRUE;
}

char vm_file_delete( char * filename)
{
	void * file;

	file = fs_driver->open( filename, vm_delete );
	if( file == NULL ) return VM_FILE_NOT_FOUND;

	return VM_FILE_OK;
}

