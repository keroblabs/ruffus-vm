#include "dir.h"

///////////////////////////////////////////////////////////////

static char local_path[256];
static char local_line[256];

static char attribute[20];
static int ls_index;
static char ls_user1[50];
static char ls_user2[50];
static int file_len;
static char date_month[10];
static int date_day;
static char date_time[10];
static char filename[100];

static const char ls_mon[][4] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun","Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

///////////////////////////////////////////////////////////////

uint16_t _dir_time_from_string( char * str_in )
{
    // input format short is GCC format:
    // time is 21:06
    uint8_t m,h;
    
    m = ( ( str_in[3] & 0x0F ) * 10 ) + ( str_in[4] & 0x0F );
    h = ( ( str_in[0] & 0x0F ) * 10 ) + ( str_in[1] & 0x0F );
    
	return(
		(h>23?0:(h&0x1F)<<11) |
		(m>59?0:(m&0x3F)<<5)
	);    
}

uint16_t _dir_date_from_string( int d, int y, char * str_month )
{
	uint16_t m;
    
    for( m = 1; m <= 12; m++ )
    {
        if( !strncmp( str_month, ls_mon[m-1], 3) )
        {
            break;
        }
    }
    
	return(
		(y>127?127<<9:(y&0x3F)<<9)   |
		((m==0||m>12)?1:(m&0xF)<<5)  |
		((d==0||d>31)?1:(d&0x1F))
	);    
}

void dir_convertFilename( char * path_in, char * path_out )
{
	#ifdef WIN32
	char * p_name;
	#endif

	if( !strncmp( path_in, ROOT_DIRECTORY_PATH, strlen( ROOT_DIRECTORY_PATH ) ) )
	{
		strcpy( path_out, BASE_FILESYSTEM_PATH );
		strcat( path_out, &path_in[strlen(ROOT_DIRECTORY_PATH)] );

		#ifdef WIN32
		while( ( p_name = strchr( path_out, '/' ) ) != NULL )
		{
			*p_name = '\\';
		}
		#endif
	}

}

char dir_locateFile( char * path, file_info_t * file_info )
{
	File * fp;

	strcpy( local_path, "ls -all  " );
	dir_convertFilename( path, &local_path[9] );

	fp = popen( local_path, "rt" );
	if( fp == NULL ) return -1;

	fgets( local_line, sizeof( local_line ), fp );
	if( !strncmp( local_line, "ls:", 3 ) ) return -2;

	dir_decodeFileEntry( local_line, file_info );
	return 0;
}

Directory * dir_openFileList( char * path )
{
	Directory * dir;

	dir = ( Directory * )malloc( sizeof( Directory ) );
	if( dir == NULL ) return NULL;

	strcpy( local_path, "ls -all  " );
	dir_convertFilename( path, &local_path[9] );

	dir->dir_file = popen( local_path, "rt" );
	if( dir->dir_file == NULL ) 
	{
		free( dir );
		return NULL;
	}

	// skip first line
	fgets( local_line, sizeof( local_line ), dir->dir_file );

	return dir;
}

void dir_decodeFileEntry( char * entry, file_info_t * file_info )
{
	sscanf( entry, "%s %d %s %s %d %s %d %s %s", attribute,
												 &ls_index,
												 ls_user1,
												 ls_user2,
												 &file_len,
												 date_month,
												 &date_day,
												 date_time,
												 filename );

	file_info->time = _dir_time_from_string( date_time );
	file_info->date = _dir_date_from_string( date_day, 2015, date_month );

	if( attribute[0] == 'd' ) file_info->attribute = ATTR_DIRECTORY;
	else file_info->attribute = 0;

	file_info->date = 0;
	file_info->time = 0;
	strcpy( file_info->name, filename );
	file_info->size = (uint32_t) file_len;
	strcpy( file_info->extension, "-" );
}

int dir_readFileList( Directory * dir, file_info_t * file_info )
{
	if( feof( dir->dir_file ) ) return -1;
	fgets( local_line, sizeof( local_line ), dir->dir_file );
	dir_decodeFileEntry( local_line, file_info );

	dir->index++;
	return dir->index;
}

void dir_closeFileList( Directory * dir )
{
	pclose( dir->dir_file );
	free( dir );
}

char dir_createDirectory( char * full_dirname )
{
	return 0;
}

bool_t dir_isEmpty( char * path )
{
	return TRUE;
}

int	dir_getFileCount( char * path )
{
	return 0;
}


