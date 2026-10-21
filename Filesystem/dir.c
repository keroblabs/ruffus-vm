//#include <string.h>
#include "dir.h"
#include "file.h"
#include "efs.h"
//#include "syscall.h"
//#include "system.h"

///////////////////////////////////////////////////////////////////////////////

uint8_t create_longname_entry( char *filename, LongFileRecord * file_entry, unsigned char checksum );
unsigned char calculate_checksum( char * filename );
int strcmp_scs( char *str1, char *str2 );

///////////////////////////////////////////////////////////////////////////////

static uint8_t is_long = FALSE;

///////////////////////////////////////////////////////////////////////////////

#define CLUSTER_PREALLOC_DIRECTORY      0

#define READ_ENTRY_NONE                 0
#define READ_ENTRY_LONG                 1
#define READ_ENTRY_NORMAL               2

///////////////////////////////////////////////////////////////////////////////

uint8_t is_long_name_needed( char *filename )
{
	uint16_t string_lenght = strlen( filename );
	uint16_t counter;
	uint8_t c;
	uint8_t dot_found = FALSE;

	for( counter = 0; counter < string_lenght; counter++ )
	{
		c = filename[ counter ];

		if( c == '.' )
		{
			dot_found = TRUE;

			if( ( counter > 8 ) ||
				( counter == 0 ) ||
				( strlen( &filename[ counter ] ) > 4 ) ) return( TRUE );
		}

		if ( ( c < 0x20 ) || 
			 ( ( c > 0x39 ) && ( c < 0x41 ) ) || 
			 ( ( c > 0x20 ) && ( c < 0x30 ) && ( c != '-' ) ) || 
			 ( ( c > 0x5A ) && ( c < 0x61 ) && ( c != '_' ) ) ||
			 ( ( c > 0x7A ) && ( c < 0x80 ) && ( c != '~' ) ) )
		{
			return( TRUE );
		}
	}

	if( ( dot_found == FALSE ) && ( string_lenght > 8 ) ) return( TRUE );

	return( FALSE );
}

uint8_t create_longname_entry( char *filename, LongFileRecord * file_entry, unsigned char checksum )
{
	char local_filename[ MAX_LONG_FILENAME_LENGHT ];
	// char read_filename[ 15 ];
	uint16_t counter = 0;
	uint16_t counter2 = 0;
	uint16_t out_counter = 0;
	uint8_t is_finished = FALSE;

	if( is_long_name_needed( filename ) == FALSE ) return( 0 );

	memset( local_filename, 0xFF, MAX_LONG_FILENAME_LENGHT );
	strncpy( local_filename, filename, MAX_LONG_FILENAME_LENGHT - 1 );

	for( counter = 0; counter < 5; counter++ )
	{
		memset( &file_entry[ counter ], 0x00, sizeof( LongFileRecord ) );

		file_entry[ counter ].Attribute = 0x0F;
		file_entry[ counter ].long_entry_cnt = counter + 1;
		file_entry[ counter ].checksum = checksum;

		for( counter2 = 0; counter2 < 5; counter2++ )
		{
			if( local_filename[ out_counter ] == 0 ) is_finished = TRUE;
			file_entry[ counter ].long_name_1[ counter2 << 1 ] = local_filename[ out_counter ];
			out_counter++;
		}
		
		if( is_finished == FALSE )
		{
			for( counter2 = 0; counter2 < 6; counter2++ )
			{
				if( local_filename[ out_counter ] == 0 ) is_finished = TRUE;
				file_entry[ counter ].long_name_2[ counter2 << 1 ] = local_filename[ out_counter ];
				out_counter++;
			}
		}

		if( is_finished == FALSE )
		{
			file_entry[ counter ].long_name_3[ 0 ] = local_filename[ out_counter++ ];
			file_entry[ counter ].long_name_3[ 2 ] = local_filename[ out_counter++ ];
		}

		if( ( is_finished == TRUE ) || 
			( file_entry[ counter ].long_name_3[ 0 ] == 0 ) ||
			( file_entry[ counter ].long_name_3[ 2 ] == 0 ) )
		{
			file_entry[ counter ].long_entry_cnt |= 0x40;
			break;
		}
	}

	return( counter + 1 );
}

unsigned char calculate_checksum( char * filename )
{
	uint16_t counter;
	unsigned char check_sum = 0;

	for( counter = 0; counter < 1; counter++ )
	{
		check_sum = ( ( check_sum & 0x01 ) ? 0x80 : 0 ) + ( check_sum >> 1 ) + filename[ counter ];
	}

	return( check_sum );
}

char dir_create_new(FileSystem *fs,char* dirname)
{
	FileLocation loc;
	FileRecord direntry;
	uint32_t nc,parentdir;
	uint8_t* buf;
	char ffname[11];
	
	// uint32_t name support
	uint8_t long_count;
	uint8_t counter;
	LongFileRecord long_record[ 5 ];
	unsigned char check_sum;
    
    // need to remove the last /
    if( dirname[strlen(dirname)-1] == '/' )
    {
        dirname[strlen(dirname)-1] = 0;
    }

	if( fs_findFile(fs,dirname,&loc,&parentdir) )
    {
		return(FILE_INVALID_MODE);
	}
	if(parentdir==0)return(FILE_WRITE_ERROR);
	
	if(!fs_findFreeFile(fs,dirname,&loc,0))return(FILE_WRITE_ERROR);
	
	/* You may never search for a free cluster, and the call
	 * functions that may cause changes to the FAT table, that
	 * is why getNextFreeCluster has to be called AFTER calling
	 * fs_findFreeFile, which may have to expand a directory in
	 * order to store the new filerecord !! 
	 */
	
	nc = fs_getNextFreeCluster(fs,fs_giveFreeClusterHint(fs));
	if(nc==0)return(FILE_OK);
	
	fs_clearCluster(fs,nc);
	
	buf = part_getSect(&fs->part,loc.Sector,0);

	dir_getFatFileName(dirname,ffname);

	// long name support
	check_sum = calculate_checksum( ffname );
	long_count = create_longname_entry( dirname, &long_record[ 0 ], check_sum );

	for( counter = 0; counter < long_count; counter++ )
	{
		memcpy( buf+(32*loc.Offset), &long_record[ long_count - counter - 1 ], 32 );
		loc.Offset++;

		if( loc.Offset == 0x10 )
		{
			part_writeBuf(&fs->part,loc.Sector,buf);
			loc.Offset = 0;
			loc.Sector++;
			buf = part_getSect(&fs->part,loc.Sector,0);
		}
	}

	memset(&direntry,0x00,sizeof(direntry));
	memcpy(&direntry,ffname,11);
	direntry.FileSize = 0;
	direntry.FirstClusterHigh=( uint16_t )( ( nc>>16 ) & 0x0FFFF );
	direntry.FirstClusterLow=( uint16_t )( nc & 0xFFFF );
	direntry.Attribute = ATTR_DIRECTORY;
    direntry.WriteDate = direntry.CreatedDate = direntry.AccessDate = fs_makeDate();
    direntry.WriteTime = direntry.CreatedTime = fs_makeTime();
	memcpy(buf+(32*loc.Offset),&direntry,32);
		
	part_writeBuf(&fs->part,loc.Sector,buf);
	
	buf = part_getSect(&fs->part,fs_clusterToSector(fs,nc),0);
	
	memset(&direntry,0x00,sizeof(direntry));
	memcpy(&direntry,".          ",11);
	direntry.Attribute = ATTR_DIRECTORY;
	direntry.FileSize = 0;
	direntry.FirstClusterHigh=( uint16_t )( ( nc>>16 ) & 0x0FFFF );
	direntry.FirstClusterLow=( uint16_t )( nc&0xFFFF );
    direntry.WriteDate = direntry.CreatedDate = direntry.AccessDate = fs_makeDate();
    direntry.WriteTime = direntry.CreatedTime = fs_makeTime();
	memcpy(buf,&direntry,32);
	
	if(fs->type == FAT32 && parentdir == fs->volumeId.RootCluster)
    {
		parentdir = 0;
	}
	if(fs->type != FAT32 && parentdir<=1)
    {
		parentdir = 0;
	} 
	
	memset(&direntry,0x00,sizeof(direntry));
	memcpy(&direntry,"..         ",11);
	direntry.Attribute = ATTR_DIRECTORY;
	direntry.FileSize = 0;
	direntry.FirstClusterHigh=( uint16_t )( ( parentdir>>16 ) & 0x0FFFF );
	direntry.FirstClusterLow=( uint16_t )( parentdir&0xFFFF );
    direntry.WriteDate = direntry.CreatedDate = direntry.AccessDate = fs_makeDate();
    direntry.WriteTime = direntry.CreatedTime = fs_makeTime();
	memcpy(buf+32,&direntry,32);

	part_writeBuf(&fs->part,fs_clusterToSector(fs,nc),buf);
	
	fat_setNextClusterAddress(fs,nc,fat_giveEocMarker(fs));

	return(FILE_OK);
}

static void _ui_add_filename( char *filename, LongFileRecord * file_entry )
{
	char local_filename[ MAX_LONG_FILENAME_LENGHT ];
	char read_filename[ 15 ];
	uint16_t counter = 0;
	uint16_t out_counter = 0;

	memset( local_filename, 0x00, sizeof( local_filename ) );
	memset( read_filename, 0x00, sizeof( read_filename ) );

	// extract name
	out_counter = 0;

	for( counter = 0; counter < 5; counter++ )
	{
		read_filename[ out_counter ] = file_entry->long_name_1[ counter << 1 ];
		out_counter++;
	}

	for( counter = 0; counter < 6; counter++ )
	{
		read_filename[ out_counter ] = file_entry->long_name_2[ counter << 1 ];
		if( ( uint8_t )read_filename[ out_counter ] == 0xFF ) read_filename[ out_counter ] = 0;
		out_counter++;
	}

	read_filename[ out_counter++ ] = file_entry->long_name_3[ 0 ];
	read_filename[ out_counter++ ] = file_entry->long_name_3[ 2 ];
	read_filename[ out_counter++ ] = 0;

	// shift name
	strncpy( local_filename, read_filename, MAX_LONG_FILENAME_LENGHT - 1 );
	strncat( local_filename, filename, MAX_LONG_FILENAME_LENGHT - 1 );
	strncpy( filename, local_filename, MAX_LONG_FILENAME_LENGHT - 1 );
}

static void _ui_copy_filename( char * filename, FileRecord * file_entry )
{
	uint16_t counter;
	uint16_t counter2;

	for( counter = 0; counter < 8; counter++ )
	{
		if( file_entry->FileName[ counter ] == 0x20 ) break;

		if( ( file_entry->FileName[ counter ] >= 0x41 ) && 
			( file_entry->FileName[ counter ] <= 0x5A ) )
		{
			filename[ counter ] = file_entry->FileName[ counter ] | 0x20;
		}
		else
		{
			filename[ counter ] = file_entry->FileName[ counter ];
		}
	}

	// counter++;

	if( ( file_entry->Attribute & 0x20 ) == 0 )
	{
		filename[ counter ] = 0;
		return;
	}

	filename[ counter ] = '.';
	counter2 = counter + 1;

	for( counter = 8; counter < 11; counter++ )
	{
		if( file_entry->FileName[ counter ] == 0x20 )
		{
			filename[ counter2 ] = 0;
			break;
		}

		if( ( file_entry->FileName[ counter ] >= 0x41 ) && 
			( file_entry->FileName[ counter ] <= 0x5A ) )
		{
			filename[ counter2 ] = file_entry->FileName[ counter ] | 0x20;
		}
		else
		{
			filename[ counter2 ] = file_entry->FileName[ counter ];
		}

		counter2++;
	}
}

uint8_t ReadFileEntry( void * buffer, tFileInformation *file_info, uint8_t is_chain )
{
    LongFileRecord * long_file_entry = ( LongFileRecord * ) buffer;
    FileRecord * file_entry = ( FileRecord * ) buffer;
    uint8_t entry_status = *( ( uint8_t * )( buffer ) );
    // uint8_t is_long_name = FALSE;
    // uint8_t counter = 0;

    // shouldnt do it here!
    // memset( file_info, 0x00, sizeof( tFileInformation ) );

    if( entry_status == 0x00 ) return( READ_ENTRY_NONE );
    if( entry_status == 0xFF ) return( READ_ENTRY_NONE );

    if( entry_status == 0xE5 ) return( READ_ENTRY_NONE );

    if( ( long_file_entry->Attribute == 0x0F ) && 
		( ( ( long_file_entry->long_entry_cnt & 0xF0 ) == 0x40 ) || ( is_chain == TRUE ) ) )
    {
        if( ( long_file_entry->long_entry_cnt & 0xF0 ) == 0x40 )
        {
            memset( file_info, 0x00, sizeof( tFileInformation ) );
        }
        _ui_add_filename( file_info->name, long_file_entry );
        return( READ_ENTRY_LONG );            
    }
    else
    {
        if( is_chain == FALSE )
        {
            memset( file_info, 0x00, sizeof( tFileInformation ) );
            _ui_copy_filename( file_info->name, file_entry );
        }
        
        // strncpy( file_info->fat_name, ( char * )file_entry->FileName, 8 );
        
        // file_info->fat_name[ 8 ] = 0;
        file_info->attribute = long_file_entry->Attribute;
        file_info->size = file_entry->FileSize;
        file_info->date = file_entry->WriteDate;
        file_info->time = file_entry->WriteTime;

        if( ( long_file_entry->Attribute & 0x20 ) == 0x20 )
        {
            strncpy( file_info->extension, ( char * )&file_entry->FileName[ 8 ], 3 );
            file_info->extension[ 3 ] = 0;
        }
    }

    return( READ_ENTRY_NORMAL );
}

int strcmp_scs( char *str1, char *str2 )
{
	int len_str1 = ( int )strlen( str1 );
	int len_str2 = ( int )strlen( str2 );
	int length;
	int counter;

	char cmp_str1;
	char cmp_str2;

	if( len_str1 > len_str2 ) length = len_str1;
	else length = len_str2;

	for( counter = 0; counter < length; counter++ )
	{
		if( ( str1[ counter ] >= 'A' ) && ( str1[ counter ] <= 'Z' ) )
		{
			cmp_str1 = str1[ counter ] | 0x20;
		}
		else
		{
			cmp_str1 = str1[ counter ];
		}

		if( ( str2[ counter ] >= 'A' ) && ( str2[ counter ] <= 'Z' ) )
		{
			cmp_str2 = str2[ counter ] | 0x20;
		}
		else
		{
			cmp_str2 = str2[ counter ];
		}

		if( cmp_str1 == 0 ) return( -1 ); // return( 0 );
		if( cmp_str2 == 0 ) return( 1 ); // return( 0 );

		if( ( cmp_str1 > cmp_str2 ) || ( cmp_str1 < cmp_str2 ) ) return( cmp_str1 - cmp_str2 );
	}

	return( 0 );
}

///////////////////////////////////////////////////////////////////////////////

char dir_createDirectory( char * path )
{
	char * volume;
	char * dirname;
	FileSystem * fs;
    static char ui_volume[32];
    
    SYSCALL_DIR_CREATE();

	dirname = file_getVolume( path, ui_volume );
	volume = path;
	
    fs = efs_get_filesystem( ui_volume );
	if( fs == NULL ) return( FILE_INVALID_FS );
	
    return( dir_create_new( fs, dirname + 1 ) );
}

void dir_getFileStructure(FileSystem *fs,FileRecord *filerec,FileLocation *loc)
{
	uint8_t *buf;

	buf=part_getSect(&fs->part,loc->Sector,0);
	*filerec=*(((FileRecord*)buf)+loc->Offset);
}

void dir_create_empty_entry( FileRecord * empty_record )
{
	memset( empty_record, 0x00, sizeof( FileRecord ) );
	empty_record->FileName[ 0 ] = 0xE5;
	empty_record->Attribute = 0xFF;
}

void dir_createDirectoryEntry(FileSystem *fs,FileRecord *filerec,FileLocation *loc, char * long_filename, char * fullname )
{
	uint8_t *buf;
	uint8_t long_count;
	uint8_t counter;
	LongFileRecord long_record[ 5 ];
	unsigned char check_sum;
	FileRecord empty_record;

	buf = part_getSect(&fs->part,loc->Sector,0);

	check_sum = calculate_checksum( ( char * )filerec->FileName );
	long_count = create_longname_entry( long_filename, &long_record[ 0 ], check_sum );

	if( ( long_count + loc->Offset ) > 0x0F )
	{
		dir_create_empty_entry( &empty_record );
		for( counter = loc->Offset; counter < 0x10; counter++ )
		{
			memcpy( buf + ( counter * sizeof( *filerec ) ), &empty_record, sizeof( FileRecord ) );
		}

		part_writeBuf(&fs->part,loc->Sector,buf);
		fs_findFreeFile( fs, fullname, loc, 0 );
		// loc->Offset = 0;
		// loc->Sector++;
		buf = part_getSect(&fs->part,loc->Sector,0);
	}

	for( counter = 0; counter < long_count; counter++ )
	{
		memcpy( buf+(loc->Offset*sizeof(*filerec)), &long_record[ long_count - counter - 1 ], sizeof( LongFileRecord ) );
		loc->Offset++;
	}

	memcpy(buf+(loc->Offset*sizeof(*filerec)),filerec,sizeof(*filerec));
	part_writeBuf(&fs->part,loc->Sector,buf);
}

void dir_createDefaultEntry(FileSystem *fs,FileRecord *filerec,char* fatfilename)
{
	memcpy(filerec->FileName,fatfilename,11);
	filerec->Attribute=0x00;
	filerec->NTReserved=0x00;
	filerec->MilliSecTimeStamp=0x00;
	filerec->CreatedTime=fs_makeTime();
	filerec->CreatedDate=fs_makeDate();
	filerec->AccessDate=filerec->CreatedDate;
	filerec->FirstClusterHigh=0x0000;
	filerec->WriteTime=filerec->CreatedTime;
	filerec->WriteDate=filerec->CreatedDate;
	filerec->FirstClusterLow=0x0000;
	filerec->FileSize=0x00000000;
}

void dir_setFirstCluster(FileSystem *fs,FileLocation *loc,uint32_t cluster_addr)
{
	uint8_t *buf;

 	buf = part_getSect(&fs->part,loc->Sector,0);
	(((FileRecord*)buf)+loc->Offset)->FirstClusterHigh=( uint16_t )( ( cluster_addr>>16 ) & 0x0FFFF );
	(((FileRecord*)buf)+loc->Offset)->FirstClusterLow= ( uint16_t )( cluster_addr&0xFFFF );
	part_writeBuf(&fs->part,loc->Sector,buf);
}

void dir_setFileSize(FileSystem *fs, FileLocation *loc,uint32_t numbytes)
{
	uint8_t *buf;

	buf = part_getSect(&fs->part,loc->Sector,0);
	(((FileRecord*)buf)+loc->Offset)->FileSize=numbytes;
	part_writeBuf(&fs->part,loc->Sector,buf);
}

char dir_updateDirectoryEntry(FileSystem *fs,FileRecord *entry,FileLocation *loc)
{
	uint8_t *buf;

	buf = part_getSect(&fs->part,loc->Sector,0);
	memcpy(buf+(loc->Offset*sizeof(*entry)),entry,sizeof(*entry));
	part_writeBuf(&fs->part,loc->Sector,buf);
	return(0);
}

uint32_t dir_findFileinBuf(uint8_t *buf, char *filename, FileLocation *loc)
{
	FileRecord fileEntry;
	uint8_t c;
    tFileInformation file_info;
	memset( &file_info, 0x00, sizeof( tFileInformation ) );

	for( c = 0; c < 16; c++ )
	{
	    uint8_t read_state = ReadFileEntry( (((FileRecord*)buf) + c), &file_info, is_long );
        if( read_state == READ_ENTRY_LONG ) is_long = TRUE;
        else is_long = FALSE;

        if( read_state == READ_ENTRY_NORMAL )
        {
            if( strcmp_scs( file_info.name, filename ) == 0 )
            {
				/* The entry has been found, return the location in the dir */
				fileEntry = *(((FileRecord*)buf) + c);

				if( loc ) loc->Offset = c;
				if( loc ) loc->attrib = fileEntry.Attribute;

				if( ( ( ( ( uint32_t )fileEntry.FirstClusterHigh ) << 16 ) + fileEntry.FirstClusterLow ) == 0 )
                {
					return( 1 ); /* Lie about cluster, 0 means not found! */
				}
                else
                {
					return( ( ( ( uint32_t )fileEntry.FirstClusterHigh ) << 16 ) + fileEntry.FirstClusterLow );
				}
            }
			is_long = FALSE;
			memset( &file_info, 0x00, sizeof( tFileInformation ) );
        }

	}
	return( 0 );
}

uint32_t dir_findFreeEntryinBuf(uint8_t* buf, FileLocation *loc)
{
	FileRecord fileEntry;
    uint8_t c;

	for(c=0;c<16;c++)
    {
		fileEntry = *(((FileRecord*)buf) + c);
		if( !( (fileEntry.Attribute & 0x0F) == 0x0F ) )
        {
			if( ( ( fileEntry.FileName[0] == 0x00 ) ||
			      ( fileEntry.FileName[0] == 0xE5 ) ) &&
			    ( fileEntry.Attribute != 0xFF ) )
			{
				if(loc)loc->Offset=c;
				return(1);
			}
		}
	}
	return(0);
}

uint32_t  dir_findinBuf(uint8_t *buf, char *fatname, FileLocation *loc, uint8_t mode)
{
	switch(mode)
    {
		case DIRFIND_FILE:
			return(dir_findFileinBuf(buf,fatname,loc));

		case DIRFIND_FREE:
			return(dir_findFreeEntryinBuf(buf,loc));

		default:
			return(0);
	}

	return(0);
}

uint32_t dir_findinCluster(FileSystem *fs,uint32_t cluster,char *fatname, FileLocation *loc, uint8_t mode)
{
    uint8_t c,*buf=0;
    uint32_t fclus;

	for(c=0;c<fs->volumeId.SectorsPerCluster;c++)
    {
		buf = part_getSect(&fs->part,fs_clusterToSector(fs,cluster)+c,0);

		if((fclus=dir_findinBuf(buf,fatname,loc,mode)))
        {
			if(loc)
            {
                loc->firstSector = fs_clusterToSector(fs,cluster);
                loc->Sector=fs_clusterToSector(fs,cluster)+c;
            }
			return(fclus);
		}
	}
	return(0);
}

uint32_t dir_findinDir(FileSystem *fs, char* fatname,uint32_t firstcluster, FileLocation *loc, uint8_t mode)
{
    uint32_t c=0,cluster;
	ClusterChain Cache;

	Cache.DiscCluster = Cache.FirstCluster = firstcluster;
	Cache.LogicCluster = Cache.LastCluster = Cache.Linear = 0;

	if(firstcluster <= 1)
    {
		return(dir_findinRootArea(fs,fatname,loc,mode));
	}

	while(!fat_LogicToDiscCluster(fs,&Cache,c++))
    {
		if((cluster=dir_findinCluster(fs,Cache.DiscCluster,fatname,loc,mode)))
        {
			return(cluster);
		}
	}
	return(0);
}

uint32_t dir_findinRootArea(FileSystem *fs,char* fatname, FileLocation *loc, uint8_t mode)
{
    uint32_t c,fclus;
    uint8_t *buf=0;

	if((fs->type != FAT12) && (fs->type != FAT16))return(0);

	for(c=fs->FirstSectorRootDir;c<(fs->FirstSectorRootDir+fs->volumeId.RootEntryCount/32);c++)
    {
		buf = part_getSect(&fs->part,c,0);

		if((fclus=dir_findinBuf(buf,fatname,loc,mode)))
        {
			if(loc)
            {
                loc->firstSector = fs->FirstSectorRootDir;
                loc->Sector=c;
            }
			return(fclus);
		}
	}
	return(0);
}

char dir_getFatFileName(char* filename, char* fatfilename)
{
	char ffnamec[11],*next,nn=0;

	memset(ffnamec, 0x00, 11);
    memset(fatfilename,0x00, 11);
	next = filename;

	if(*filename=='/')next++;

	while((next=file_normalToFatName(next,ffnamec)))
    {
		memcpy(fatfilename,ffnamec,11);
		nn++;
	}

	if(nn)return(1);

	return(0);
}

char dir_getFatFileName_Long(char* filename, char* fatfilename)
{
	char ffnamec[128],*next,nn=0;

	// memset(ffnamec,0x00,11);
    // memset(fatfilename,0x00,11);
    ffnamec[ 0 ] = 0;
    fatfilename[ 0 ] = 0;
	next = filename;

	if(*filename=='/')next++;

	while((next=file_normalToFatName2(next,ffnamec)))
    {
		// memCpy(ffnamec,fatfilename,11);
		strcpy( fatfilename, ffnamec );
		nn++;
	}

	if(nn)return(1);

	return(0);
}

char dir_addCluster(FileSystem *fs,uint32_t firstCluster)
{
    uint32_t lastc,logicalc;
	ClusterChain cache;

	fs_initClusterChain(fs,&cache,firstCluster);
	if(fat_allocClusterChain(fs,&cache,1))
    {
		return(-1);
	}

	lastc = fs_getLastCluster(fs,&cache);

	if(CLUSTER_PREALLOC_DIRECTORY)
    {
		if(fat_allocClusterChain(fs,&cache,CLUSTER_PREALLOC_DIRECTORY))
        {
			return(-1);
		}

		logicalc = fat_DiscToLogicCluster(fs,firstCluster,lastc);

		while(!fat_LogicToDiscCluster(fs,&cache,++logicalc))
        {
			fs_clearCluster(fs,cache.DiscCluster);
		}
	}
    else
    {
		fs_clearCluster(fs,lastc);
	}
	return(0);
}

int dir_getFileCount( char * path )
{
    Directory dir;
    int count;
    
    SYSCALL_DIR_FILE_COUNT();

    // it doesnt exist, return as not empty to stop deleting
    if( dir_openFileList( &dir, path ) != 0 ) return -1;
    
    count = dir_readFileList( &dir, NULL );
    dir_closeFileList( &dir );
    
    return count;    
}

bool_t dir_isEmpty( char * path )
{
    if( dir_getFileCount( path ) == 0 ) return TRUE;
    return FALSE;
}

char dir_openFileList( Directory * dir, char * path )
{
    char * dirname;
    char file_type;
    
    SYSCALL_DIR_OPEN_FILELIST();
    
    file_type = file_locatePath( path );
    
    //if( file_isRoot( path ) == TRUE )
    if( file_type == FS_IS_ROOT_DIR )
    {
        static char dir_volume[40];
        
        dirname = file_getVolume( path, dir_volume );
        dir->dir_file.fs = efs_get_filesystem( dir_volume );
        
        if( dir->dir_file.fs == NULL ) return( -6 );
        if( dir->dir_file.fs->type == FAT32 ) return -7;
        
        dir->dir_file.Location.Sector = dir->dir_file.fs->FirstSectorRootDir;
        dir->dir_file.Location.Offset = 0;
        dir->mode = DIR_MODE_ROOT;
        dir->index = 0;
        return FILE_OK;
    }
    else if( file_type == FS_IS_ROOT_SYSTEM )
    {
        // display the /dev and mounted discs
        dir->mode = DIR_MODE_SYSTEM;
        dir->index = 0;
        return FILE_OK;        
    }
    #if defined TIMA_OS
    else if( file_type == FS_IS_ROOT_DEVICE )
    {
        // display installed devices
        dir->mode = DIR_MODE_DEVICE;
        dir->index = 0;
        dir->dir_file.FilePtr = 0;
        dir->dir_file.DevInfo.device_index = 0;
        dir->dir_file.DevInfo.device_ptr = ( device_data_t * )system_Get_Item( _device_section, dir->dir_file.FilePtr );
        return FILE_OK;        
    }
    #endif
    else if( file_fopen( &dir->dir_file, path, FS_MODE_READ ) == 0 )
    {
        dir->mode = DIR_MODE_DIR;
        dir->index = 0;
        return FILE_OK;
    }

    return FILE_INVALID_MODE;
}

int dir_readFileList( Directory * dir, tFileInformation * file_info )
{
    FileRecord * file_record;
    uint8_t * buf;
    uint32_t max_sector;
    
    #if defined TIMA_OS
    bool_t is_device_found;
    uint32_t device_cnt;
    #endif
    
    uint32_t counter;
    uint8_t entry_state;
    static tFileInformation temp_info;
    bool_t is_long_name = FALSE;   
    uint32_t read_size;
    static uint8_t read_buffer[32];
    
    SYSCALL_DIR_READ_FILELIST();
    
    counter = 0;
    file_record = ( FileRecord * )&read_buffer[0];
    
    while( 1 )
    {          
        if( dir->mode == DIR_MODE_ROOT )
        {
            max_sector = dir->dir_file.fs->FirstSectorRootDir + ( dir->dir_file.fs->volumeId.RootEntryCount / 16 );
            if( dir->dir_file.Location.Sector >= max_sector )
            {
                if( file_info != NULL )
                {
                    return -1;
                }
                else
                {
                    // file_info was null, so wanted to total of files in the directory
                    // after reached the end, reset file pointers
                    dir->dir_file.Location.Sector = dir->dir_file.fs->FirstSectorRootDir;
                    dir->dir_file.Location.Offset = 0;
                    dir->mode = DIR_MODE_ROOT;
                    dir->index = 0;
                    break;
                }                
            }

            buf = part_getSect( &dir->dir_file.fs->part, dir->dir_file.Location.Sector, 0 );

            entry_state = ReadFileEntry( ( ( FileRecord * )buf ) + dir->dir_file.Location.Offset, &temp_info, is_long_name );

            if( ++dir->dir_file.Location.Offset >= 16 )
            {
                dir->dir_file.Location.Offset = 0;
                dir->dir_file.Location.Sector++;
            }
        }
        #if defined TIMA_OS
        else if( dir->mode == DIR_MODE_SYSTEM )
        {
            // display mounted discs
            entry_state = READ_ENTRY_NORMAL;
            
            buf = ( uint8_t * )system_Get_Item( _disc_section, dir->index );
            if( buf == NULL )
            {
                if( file_info != NULL )
                {
                    return -1;
                }
                else
                {
                    // file_info was null, so wanted to total of files in the directory
                    // after reached the end, reset file pointers
                    dir->mode = DIR_MODE_SYSTEM;
                    dir->index = 0;   
                    break;
                }                     
            }
            else
            {
                msd_driver_t * msd = ( msd_driver_t * )buf;
                uint8_t lun = MAL_GetLun( ( char * )msd->name );
                
                memset( &temp_info, 0x00, sizeof( temp_info ) );

                if( ( lun != LUN_DEVICE ) && ( lun != LUN_SYSTEM ) && ( lun != LUN_NOT_FOUND ) )
                {
                    temp_info.size = MAL_GetBlockCount( lun );
                }
                
                temp_info.date = system_Get_Build_Date();
                temp_info.time = system_Get_Build_Time();
                strcpy( temp_info.name, msd->name );
            }
        }
        else if( dir->mode == DIR_MODE_DEVICE )
        {
            entry_state = READ_ENTRY_NORMAL;
            is_device_found = FALSE;
                    
            if( dir->dir_file.DevInfo.device_ptr == NULL )
            {
                if( file_info != NULL )
                {
                    return -1;
                }
                else
                {
                    // file_info was null, so wanted to total of devices installed
                    // after reached the end, reset file pointers
                    dir->index = 0;
                    dir->dir_file.FilePtr = 0;
                    dir->dir_file.DevInfo.device_index = 0;
                    dir->dir_file.DevInfo.device_ptr = ( device_data_t * )system_Get_Item( _device_section, dir->dir_file.FilePtr );
                    break;
                }                        
            }
            
            // display installed devices
            if( strchr( dir->dir_file.DevInfo.device_ptr->name, '*' ) != NULL )
            {
                is_device_found = FALSE;
                
                // contain index
                while( dir->dir_file.DevInfo.device_index < MAX_DEVICE_INDEX )
                {
                    device_cnt = dir->dir_file.DevInfo.device_index;
                    dir->dir_file.DevInfo.device_index++;
                    
                    if( dir->dir_file.DevInfo.device_ptr->validate( device_cnt ) == TRUE )
                    {
                        memset( &temp_info, 0x00, sizeof( temp_info ) );
                        strcpy( temp_info.name, "/dev/" );
                        strcat( temp_info.name, dir->dir_file.DevInfo.device_ptr->name );
                        tima_itoa( device_cnt, &temp_info.name[strlen(temp_info.name)-1], 10 );
                        temp_info.date = system_Get_Build_Date();
                        temp_info.time = system_Get_Build_Time();
                        is_device_found = TRUE;
                        break;
                    }
                }
                
                if( ( dir->dir_file.DevInfo.device_index >= MAX_DEVICE_INDEX ) &&
                    ( is_device_found == FALSE ) )
                {
                    dir->dir_file.DevInfo.device_index = 0;
                    dir->dir_file.FilePtr++;
                    dir->dir_file.DevInfo.device_ptr = ( device_data_t * )system_Get_Item( _device_section, dir->dir_file.FilePtr );
                    continue;
                }
            }
            else
            {
                memset( &temp_info, 0x00, sizeof( temp_info ) );
                strcpy( temp_info.name, "/dev/" );
                strcat( temp_info.name, dir->dir_file.DevInfo.device_ptr->name );
                
                if( strchr( dir->dir_file.DevInfo.device_ptr->name, '?' ) != NULL )
                {
                    temp_info.name[strlen(temp_info.name)-1] = 0;
                }

                temp_info.date = system_Get_Build_Date();
                temp_info.time = system_Get_Build_Time();

                dir->dir_file.FilePtr++;
                dir->dir_file.DevInfo.device_ptr = ( device_data_t * )system_Get_Item( _device_section, dir->dir_file.FilePtr );
            }
        }
        #endif
        else
        {
            if( file_feof( &dir->dir_file ) )
            {
                if( file_info != NULL )
                {
                    return -1;
                }
                else
                {
                    // file_info was null, so wanted to total of files in the directory
                    // after reached the end, reset file pointers
                    dir->dir_file.FilePtr = 0;
                    dir->index = 0;
                    break;
                }
            }
            read_size = file_fread( read_buffer, 32, &dir->dir_file );
            entry_state = ReadFileEntry( file_record, &temp_info, is_long_name );
        }

        if( entry_state == READ_ENTRY_LONG ) is_long_name = TRUE;
        else is_long_name = FALSE;

        if( entry_state == READ_ENTRY_NORMAL ) 
        {
            counter = dir->index;
            dir->index++;
            
            if( file_info != NULL )
            {
                memcpy( file_info, &temp_info, sizeof( tFileInformation ) );
                break;
            }
        }
    }
    
    return counter;
}

void dir_closeFileList( Directory * dir )
{
    SYSCALL_DIR_CLOSE_FILELIST();
    if( dir->mode == DIR_MODE_DIR ) file_fclose( &dir->dir_file );
}

