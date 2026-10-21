#include "libc.h"
#include "file.h"
#include "efs.h"

#ifdef TIMA_OS
#include "device.h"
#include "t_threads.h"
#endif

#include "heap.h"

///////////////////////////////////////////////////////////////////////////////

#define CLUSTER_PREALLOC_FILE 2

///////////////////////////////////////////////////////////////////////////////

static char volume[ 128 ];
static uint8_t dir_read_buffer[32];

///////////////////////////////////////////////////////////////////////////////

uint32_t	_file_required_cluster(File *file,uint32_t offset, uint32_t size);
void		_file_initFile(File *file, FileSystem *fs, FileLocation *loc);
uint8_t		_file_validateChar(uint8_t c);

///////////////////////////////////////////////////////////////////////////////


char file_locatePath( const char * full_filename )
{
    //char fatfilename[11];
    FileLocation loc;
    FileSystem *fs;
	char * filename;
    
    SYSCALL_FILE_LOCATE();

	// identify the device driver
	filename = file_getVolume( full_filename, volume );

    fs = efs_get_filesystem( volume );
	if( fs == NULL ) return( -6 );
    
    if( fs->type == SYS_DEVICE )
    {
        if( !strcmp( volume, "/" ) )
        {
            return FS_IS_ROOT_SYSTEM;
        }
        else if( ( filename == NULL ) || ( !strcmp( filename, "/" ) ) )
        {
            return FS_IS_ROOT_DEVICE;
        }
                
        return FS_IS_DEVICE;
    }
    
    if( filename == NULL ) return FS_IS_ROOT_DIR;
    
    if( !strcmp( filename, "/" ) ) return FS_IS_ROOT_DIR;

    //dir_getFatFileName(filename,fatfilename);
    //dir_getFatFileName_Long( filename, long_filename );    
    
    return fs_findFile(fs,filename,&loc,0);  
}

uint32_t file_get_size( File *file )
{
	return( file->FileSize );
}

uint32_t _file_required_cluster(File *file,uint32_t offset, uint32_t size)
{
	uint32_t clusters_required,clustersize;
	uint32_t hc;

	if((offset+size)>file->FileSize)
	{
		if(file->Cache.ClusterCount==0)
		{ 
			/* Number of cluster unknown */
			hc = fat_countClustersInChain(file->fs,file->Cache.FirstCluster);
			file->Cache.ClusterCount = hc;
		}
		else
		{
			hc = file->Cache.ClusterCount; /* This better be right */
		}
		clustersize = file->fs->volumeId.BytesPerSector * file->fs->volumeId.SectorsPerCluster;
		if((size-file->FileSize+offset)>((hc-((file->FileSize+clustersize-1)/clustersize))*clustersize))
		{
			clusters_required = (((offset+size)-(hc*clustersize))+clustersize-1)/clustersize;
		}
		else
		{
			clusters_required = 0;
		}
	}
	else
	{
		clusters_required = 0;
	}
	return(clusters_required);
}

///////////////////////////////////////////////////////////////////////////////

uint32_t file_fread(uint8_t *buf,uint32_t size,File *file)
{
	uint32_t r;
    
    if( file == NULL ) return 0;

	r=file_read(buf, size, file->FilePtr,file);
	file->FilePtr+=r;
	return(r);
}

int file_fgetc(File *file)
{
	int ret;
    int size;
    
    if( file == NULL ) return -1;
    
    ret = 0;
	size=file_read( ( uint8_t * )&ret, 1, file->FilePtr, file );
	file->FilePtr += size;
    
    if( size == 0 ) return -1;
    
	return(ret);
}

uint32_t file_fwrite(uint8_t *buf, uint32_t size, File *file)
{
	uint32_t r;
    
    if( file == NULL ) return 0;

	r=file_write(buf,size,file->FilePtr,file);
	file->FilePtr+=r;
	return(r);
}

void file_setPos(File *file,uint32_t pos)
{
    if( file == NULL ) return;
    
	if(pos<=file->FileSize)
    {
		file->FilePtr=pos;
	}
    else
    {
		file->FilePtr=file->FileSize;
    }
}

uint32_t file_getPos(File *file)
{
    if( file == NULL ) return 0;
	return(file->FilePtr);
}

char file_feof(File *file)
{
    if( file == NULL ) return 1;
    if( file->fs == NULL ) 
	{
		return 1;
	}

    SYSCALL_FILE_FEOF();
    
    #ifdef TIMA_OS
    if( file->fs->type == SYS_DEVICE )
    {
        if( device_is_rx_empty( file ) == TRUE ) return 1;
    }
    else
    #endif
        if( file->FilePtr >= file->FileSize ) return( 1 );
    
	return( 0 );
}

void file_flush( File * file )
{
    #ifdef TIMA_OS
    if( file->fs->type == SYS_DEVICE )
    {
        if( device_is_tx_in_use( file ) == TRUE )
        {
            // TODO: flush tx buffer
            thread_wait( device_is_tx_in_use( file ) == FALSE );
        }
    }
    #endif
}

uint32_t file_getSize( const char *filename )
{
    uint32_t size;
    File the_file;
    
    if( file_fopen( &the_file, ( char * )filename, FS_MODE_READ ) != 0 ) return 0;
    size = file_get_size( &the_file );
    file_fclose( &the_file );
    return size;
}

bool_t file_IsOpen( File * file )
{
	if( file == NULL ) return FALSE;
	if( file->fs == NULL ) return FALSE;

    SYSCALL_FILE_IS_OPEN();
    
    #ifdef TIMA_OS
    if( file->fs->type == SYS_DEVICE )
    {
        return device_is_opened( file );
    }
    #endif
    
	if(!file_getAttr(file,FILE_STATUS_OPEN))return(FALSE);
    
    return TRUE;
}

uint32_t file_read(uint8_t *buf, uint32_t size, uint32_t offset, File *file)
{
	uint32_t bytes_read=0,size_left=size,coffset=offset;
	uint32_t cclus,csec,cbyte;
	uint32_t rclus,rsec;
	uint32_t btr;
	uint8_t *tbuf;
    
	if(!file_getAttr(file,FILE_STATUS_OPEN))return(0);
    
    SYSCALL_FILE_FREAD();

    if( file_feof( file ) == TRUE ) return 0;
    
    #ifdef TIMA_OS
    if( file->fs->type == SYS_DEVICE )
    {
        return device_read_buffer( file, buf, (uint16_t)size );
    }
    #endif
    
    if( buf == NULL )
    {
        return( file->FileSize - file->FilePtr );
    }
    
	if(offset>=file->FileSize)
		size_left=0; /* Offset check */

	if( (offset+size > file->FileSize) && size_left!=0)
		size_left=file->FileSize-offset;

	while(size_left>0)
	{
		cclus = coffset/(512*file->fs->volumeId.SectorsPerCluster);
		csec = (coffset/(512))%file->fs->volumeId.SectorsPerCluster;
		cbyte = coffset%512;

		if(cbyte!=0 || size_left<512)
		{
			btr = 512-(coffset%512)>=size_left?size_left:512-(coffset%512);
		}
		else
		{
			btr = 512;
		}

		if((fat_LogicToDiscCluster(file->fs,&(file->Cache),cclus))!=0)
		{
			return(0);
		}
		rclus=file->Cache.DiscCluster;
		rsec=fs_clusterToSector(file->fs,rclus);


		if(btr==512)
		{
			/*part_readBuf(file->fs.part,rsec+csec,buf+bytes_read);*/
			part_directSectorRead(&file->fs->part,rsec+csec,buf+bytes_read);
		}
		else
		{
			/*part_readBuf(file->fs->part,rsec+csec,tbuf);*/
			tbuf = part_getSect(&file->fs->part,rsec+csec,0);
			// memcpy(tbuf+(coffset%512),buf+bytes_read,btr);
			memcpy(buf+bytes_read,tbuf+(coffset%512),btr);
		}

		coffset+=btr;
		bytes_read+=btr;
		size_left-=btr;
	}

	return(bytes_read);
}

uint32_t file_fgets(char *buf,uint32_t size,File *file)
{
	static uint8_t buffer[ 51 ];
	uint32_t read_size = 0;
	uint32_t xfer_size = 0;
	uint32_t counter;
    
    SYSCALL_FILE_FGETS();

	while( ( file->FilePtr < file->FileSize ) || ( file->fs->type == SYS_DEVICE ) )
	{
		read_size = file_read( buffer, sizeof( buffer ), file->FilePtr, file ); // - 1;

		for( counter = 0; counter < read_size; counter++ )
		{
			if( ( buffer[ counter ] == 0x0A ) ||
				( ( buffer[ counter ] == 0x0D ) && ( buffer[ counter + 1 ] == 0x0A ) ) )
			{
				file->FilePtr++;
				if( buffer[ counter ] == 0x0D ) file->FilePtr++;

				return( xfer_size );
			}

			buf[ xfer_size++ ] = buffer[ counter ];
			buf[ xfer_size ] = 0;

			file->FilePtr++;

			if( xfer_size >= ( size - 1 ) ) return( xfer_size );
		}
        
        if( file->fs->type == SYS_DEVICE ) break; // return read_size;
	}

	return( xfer_size );
}

void file_fputc( File *file, uint8_t data )
{
    file_fwrite( ( uint8_t * )&data, 1, file );
}

int file_fputs(File *file, const char * text )
{
    int total_bytes = file_fwrite( ( uint8_t * )text, ( uint32_t )strlen( text ), file );
    
    if( total_bytes == -1 ) return FILE_EOF;

    file->FilePtr--;

	return( total_bytes - 1 );
}

uint32_t file_write(uint8_t* buf,uint32_t size,uint32_t offset,File* file)
{
	uint32_t need_cluster;
	uint32_t cclus,csec,cbyte;
	uint32_t size_left=size,bytes_written=0;
	uint32_t rclus,rsec;
	uint32_t coffset=offset;
	uint16_t btr;
	uint8_t *tbuf;
    
	if(!file_getAttr(file,FILE_STATUS_OPEN) || !file_getAttr(file,FILE_STATUS_WRITE))return(0);
    
    // check this before syscall
    /*
    if( file->fs->type == SYS_DEVICE )
    {
        thread_wait( device_is_tx_busy( file ) == FALSE );
    }    
     */
    SYSCALL_FILE_FWRITE();

    #ifdef TIMA_OS
    if( file->fs->type == SYS_DEVICE )
    {
        return device_write_buffer( file, buf, (uint16_t)size );
        // return size;
    }
    #endif
    
	if(offset>file->FileSize)
	{
		offset=file->FileSize;
	}

	need_cluster = _file_required_cluster(file,offset,size);

	if(need_cluster)
	{
		if(fat_allocClusterChain(file->fs,&(file->Cache),need_cluster+CLUSTER_PREALLOC_FILE)!=0)
		{
			return(0);
		}
	}

	while(size_left>0){

		cclus = coffset/(512*file->fs->volumeId.SectorsPerCluster);
		csec = (coffset/(512))%file->fs->volumeId.SectorsPerCluster;
		cbyte = coffset%512;

		if(cbyte!=0 || size_left<512)
		{
			btr = ( uint16_t )( ( 512-(coffset%512)>=size_left?size_left:512-(coffset%512) ) & 0x01FF );
		}
		else
		{
			btr = 512;
		}

		if((fat_LogicToDiscCluster(file->fs,&(file->Cache),cclus))!=0)
		{
			file->FileSize+=bytes_written;
			dir_setFileSize(file->fs,&(file->Location),file->FileSize);
			return(bytes_written);
		}
		rclus=file->Cache.DiscCluster;
		rsec=fs_clusterToSector(file->fs,rclus);

		if(btr==512)
		{
			/*part_writeBuf(&file->fs->part,rsec+csec,buf+bytes_written);*/
			part_directSectorWrite(&file->fs->part,rsec+csec,buf+bytes_written);
		}
		else
		{
			tbuf = part_getSect(&file->fs->part,rsec+csec,0);
			memcpy(tbuf+(coffset%512),buf+bytes_written,btr);
			part_writeBuf(&file->fs->part,rsec+csec,tbuf);
		}

		coffset+=btr;
		bytes_written+=btr;
		size_left-=btr;
	}

	if(bytes_written>file->FileSize-offset){
		file->FileSize+=bytes_written-(file->FileSize-offset);
    }

	return(bytes_written);
}

int file_fprintk( File *file, const char *fmt, ... )
{
	va_list args;	
	int printed_len;
	
    if( file == NULL ) return 0;
    if(!file_getAttr(file,FILE_STATUS_OPEN) || !file_getAttr(file,FILE_STATUS_WRITE))return(0);
    
	/* Emit the output into the temporary buffer */ 
	va_start(args, fmt);	
	printed_len = libc_vsnprintk(vsf_printk_buf, VSF_PRINTK_BUF_SIZE, fmt, args);
	va_end(args);	

	/*	 * Copy the output into log_buf.  
	       If the caller didn't provide	 
	     * appropriate log level tags, we insert them here	 */ 

    return file_fputs( file, ( const char * )vsf_printk_buf );  
}

bool_t file_isRoot( const char * full_filename )
{
    char result = file_locatePath( full_filename );
    if( result == FS_IS_ROOT_DIR ) return TRUE;
    return FALSE;
}

bool_t file_IsDirectory( const char * full_filename )
{
    char result = file_locatePath( full_filename );
    
    if( ( result == FS_IS_DIRECTORY ) || ( result == FS_IS_ROOT_DIR ) ) return TRUE;
    return FALSE;
}

bool_t file_Exists( const char * full_filename )
{
    if( file_locatePath( full_filename ) == FS_IS_FILE ) return TRUE;
    return FALSE;
}

char * file_getVolume( const char * full_filename, char * volume )
{
	char * stop_ptr;
	//int counter;
	//int size;

    strcpy( volume, full_filename );
	stop_ptr = strchr( &volume[ 1 ], '/' );
    
    if( stop_ptr != NULL )
        *stop_ptr = 0;

	stop_ptr = ( char * )strchr( &full_filename[ 1 ], '/' );
    return( stop_ptr );
}

uint32_t file_fioctrl( File * file, uint32_t param, void * data )
{
    if( file == NULL ) return 0;
    SYSCALL_FILE_FIOCTRL();
    
    #ifdef TIMA_OS
    if( file->fs->type == SYS_DEVICE )
    {
        return device_ioctrl( file, param, data );
    }
    #endif
    
    return FILE_INVALID_MODE;
}

char file_fopen(File* file,char* full_filename,char mode)
{
    char fatfilename[11];
    FileRecord wtmp;
    FileLocation loc;
    uint32_t sec;
    FileSystem *fs;
	char find_file_ret;
	char * filename;
    char * long_filename;
    
    SYSCALL_FILE_FOPEN();
    
    memset( file, 0x00, sizeof( File ) );

	// identify the device driver
	filename = file_getVolume( full_filename, volume );

    fs = efs_get_filesystem( volume );
	if( fs == NULL ) return( FILE_INVALID_FS );
    
    if( ( mode == FS_MODE_DEVICE ) && ( fs->type != SYS_DEVICE ) ) return FILE_INVALID_DEVICE;
    if( ( mode != FS_MODE_DEVICE ) && ( fs->type == SYS_DEVICE ) ) mode = FS_MODE_DEVICE;

    dir_getFatFileName(filename,fatfilename);

    switch(mode)
	{
        case FS_MODE_DEVICE:
            #ifdef TIMA_OS
            if( device_dev_open( file, full_filename ) == FALSE ) return FILE_NOT_FOUND;

            _file_initFile(file,fs,NULL);
            file_setAttr(file,FILE_STATUS_OPEN, TRUE);
            file_setAttr(file,FILE_STATUS_WRITE, TRUE);
            return FILE_OK;
            #else
            return FILE_NOT_FOUND;
            #endif
            
        case FS_MODE_READ:
            //DEBUG_PRINTK( "fopen filename: %s = ", filename );
			find_file_ret = fs_findFile(fs,filename,&loc,0);
            //DEBUG_PRINTK( "%d\r\n", find_file_ret );
            if( ( find_file_ret == FS_IS_DIRECTORY ) || ( find_file_ret == FS_IS_FILE ) )
			{
                dir_getFileStructure(fs,&(file->DirEntry), &loc);
                _file_initFile(file,fs,&loc);
				file_setAttr(file,FILE_STATUS_OPEN, TRUE);
				file_setAttr(file,FILE_STATUS_WRITE, FALSE);
                
                if( find_file_ret == FS_IS_DIRECTORY )
                {
                    // for directory, determine the data size
                    file->FileSize = ( 1024 * 1024 );
                    
                    while( !file_feof( file ) )
                    {
                        file_fread( dir_read_buffer, 32, file );
                        if( dir_read_buffer[0] == 0 )
                        {
                            // one of the directory entries is NULL, this is the end
                            file->FileSize = file->FilePtr - 32;
                            file->FilePtr = 0;
                            break;
                        }
                    }
                }
                return(FILE_OK);
            }
            return(FILE_NOT_FOUND);

        case FS_MODE_WRITE:
            if(fs_findFile(fs,filename,&loc,&sec)) /* File may NOT exist, but parent HAS to exist */
			{
				fs_fileDelete( fs, ( uint8_t * )filename );
                // return(FILE_OPEN_ALREADY_EXIST);
			}

			if(sec==0)
            { 
                /* Parent dir does not exist */
 				return(FILE_WRITE_INVALID);
			}
            
            if(fs_findFreeFile(fs,filename,&loc,0))
			{
                long_filename = ( char * )malloc( 128 );
                if( long_filename == NULL ) return FILE_UNABLE_TO_WRITE;
                
                dir_getFatFileName_Long( filename, long_filename );
                
                dir_createDefaultEntry(fs,&wtmp,fatfilename);
                dir_createDirectoryEntry(fs,&wtmp,&loc, long_filename, filename );
                memcpy(&(file->DirEntry),&wtmp,sizeof(wtmp));
				_file_initFile(file,fs,&loc);
                sec=fs_getNextFreeCluster(file->fs,fs_giveFreeClusterHint(file->fs));
                dir_setFirstCluster(file->fs,&(file->Location),sec);
                fs_setFirstClusterInDirEntry(&(file->DirEntry),sec);
                fs_initClusterChain(fs,&(file->Cache),sec);
                fat_setNextClusterAddress(fs,sec,fat_giveEocMarker(fs));
				file_setAttr(file,FILE_STATUS_OPEN, TRUE);
				file_setAttr(file,FILE_STATUS_WRITE, TRUE);
                
                free( long_filename );
            	return(0);
			}
            else
			{
                return(FILE_WRITE_ERROR);
			}
            break;
            
        case FS_MODE_APPEND:
        case FS_MODE_RANDOM:
			if(fs_findFile(fs,filename,&loc,0)==FS_IS_FILE) /* File exists */
			{
				dir_getFileStructure(fs,&(file->DirEntry), &loc);
				_file_initFile(file,fs,&loc);
				if(file->Cache.FirstCluster==0)
                {
					sec=fs_getNextFreeCluster(file->fs,fs_giveFreeClusterHint(file->fs));
					dir_setFirstCluster(file->fs,&(file->Location),sec);
					fs_setFirstClusterInDirEntry(&(file->DirEntry),sec);
					fat_setNextClusterAddress(fs,sec,fat_giveEocMarker(fs));
					_file_initFile(file,fs,&loc);
				}
                if( mode == FS_MODE_RANDOM ) file_setPos(file, 0);
				else file_setPos(file,file->FileSize);
				file_setAttr(file,FILE_STATUS_OPEN, TRUE);
				file_setAttr(file,FILE_STATUS_WRITE, TRUE);
			}
			else /* File does not exist */
			{
				if(fs_findFreeFile(fs,filename,&loc,0))
				{
					dir_createDefaultEntry(fs,&wtmp,fatfilename);
					dir_createDirectoryEntry(fs,&wtmp,&loc, filename, filename );
					memcpy(&(file->DirEntry),&wtmp,sizeof(wtmp));
					_file_initFile(file,fs,&loc);
					sec=fs_getNextFreeCluster(file->fs,fs_giveFreeClusterHint(file->fs));
					dir_setFirstCluster(file->fs,&(file->Location),sec);
	                fs_setFirstClusterInDirEntry(&(file->DirEntry),sec);
    	            fs_initClusterChain(fs,&(file->Cache),sec);
					fat_setNextClusterAddress(fs,sec,fat_giveEocMarker(fs));
					file_setAttr(file,FILE_STATUS_OPEN, TRUE);
					file_setAttr(file,FILE_STATUS_WRITE, TRUE);
				}
				else
				{
					return(FILE_WRITE_ERROR);
				}
			}
			return(FILE_OK);

    }
    return(FILE_INVALID_MODE);
}

char file_fclose(File *file)
{
    SYSCALL_FILE_FCLOSE();
    
    #ifdef TIMA_OS
    if( file->fs->type == SYS_DEVICE )
    {
        device_close( file );
    }
    else
    #endif
    {
        if(fs_hasTimeSupport()){
            if(file_getAttr(file,FILE_STATUS_WRITE))
            {
                file->DirEntry.AccessDate = fs_makeDate();
                file->DirEntry.FileSize = file->FileSize;
                file->DirEntry.WriteDate = file->DirEntry.AccessDate;
                file->DirEntry.WriteTime = fs_makeTime();
                dir_updateDirectoryEntry(file->fs,&(file->DirEntry),&(file->Location));
            }
        }
        else
        {
            if(file_getAttr(file,FILE_STATUS_WRITE))
            {
                dir_setFileSize(file->fs,&(file->Location),file->FileSize);
            }
        }
    }
    
    if( file_getAttr( file, FILE_STATUS_HEAP ) )
    {
        free( file );
    }
    else
    {
        memset(file,0x00,sizeof(*file));
        file_setAttr(file,FILE_STATUS_OPEN, FALSE);
        file_setAttr(file,FILE_STATUS_WRITE, FALSE);
    }

	return(FILE_OK);
}

void _file_initFile(File *file, FileSystem *fs, FileLocation *loc)
{
	file->fs=fs;
    if( fs->type == SYS_DEVICE ) return;
    
	file->FileSize=file->DirEntry.FileSize;
	file->FilePtr=0;
    file->Location.firstSector=loc->firstSector;
	file->Location.Sector=loc->Sector;
	file->Location.Offset=loc->Offset;
	file->Cache.Linear=0;
	file->Cache.FirstCluster=(((uint32_t)file->DirEntry.FirstClusterHigh)<<16)+
	                                    file->DirEntry.FirstClusterLow;
	file->Cache.LastCluster=0;
	file->Cache.LogicCluster=0;
	file->Cache.DiscCluster=file->Cache.FirstCluster;
}

char* file_normalToFatName(char* filename,char* fatfilename)
{
	uint8_t c,dot=0,vc=0;

	for(c=0;c<11;c++)fatfilename[c]=' ';

	c=0;

	if(*filename == '.')
	{
		fatfilename[0]='.';
		vc++;
		if(*(filename+1) == '.')
		{
			fatfilename[1]='.';
			filename+=2;
		}
		else
		{
			filename++;
		}
	}
	else
	{
		while(*filename != '\0' && *filename != '/')
		{
		// while(*filename != '\0' && *filename != ' ' && *filename != '/'){
			if(*filename=='.' && !dot)
			{
				dot=1;
				c=8;
			}
			else
			{
				if(dot)
				{
					if(c<=10)
					{
						fatfilename[c]=_file_validateChar(*filename);
						c++;
					}
				}
				else
				{
					if(c<=7)
					{
						fatfilename[c]=_file_validateChar(*filename);
						c++; vc++;
					}
				}
			}
			filename++;
		}
	}

	if(vc>0)
	{
		if(*filename=='\0')
		{
			return(filename);
		}
		else
		{
			return(filename+1);
		}
	}
	else
	{
		return(0);
	}
}

char* file_normalToFatName2(char* filename,char* fatfilename)
{
	uint8_t c;
    // uint8_t dot=0;
    uint8_t vc=0;

	// for(c=0;c<11;c++)fatfilename[c]=' ';

	c=0;

	if(*filename == '.')
    {
		fatfilename[0]='.';
		vc++;
		if(*(filename+1) == '.')
        {
			fatfilename[1]='.';
			filename+=2;
		}
        else
        {
			filename++;
		}
	}
    else
    {
		while(*filename != '\0' && *filename != '/')
        {
            #if 0
		    // while(*filename != '\0' && *filename != ' ' && *filename != '/'){
			if(*filename=='.' && !dot)
            {
				dot=1;
				c=8;
			}
            else
            {
				if(dot)
                {
					if(c<=10)
                    {
						fatfilename[c]=_file_validateChar(*filename);
						c++;
					}
				}
                else
                {
					if(c<=7)
                    {
						fatfilename[c]=_file_validateChar(*filename);
						c++;
                        vc++;
					}
				}
			}
            #endif

    		fatfilename[c]=(*filename);
			vc++;
    		c++;
    		fatfilename[c]=0;

			filename++;
		}
	}

	if(vc>0)
    {
		if(*filename=='\0')
        {
			return(filename);
		}
        else
        {
			return(filename+1);
		}
	}
    else
    {
		return(0);
	}
}

uint8_t _file_validateChar(uint8_t c)
{
    if( (c<0x20) || (c>0x20&&c<0x30&&c!='-') || (c>0x39&&c<0x41) || (c>0x5A&&c<0x61&&c!='_') ||	(c>0x7A&&c!='~') )
		return(0x58);
    if( c>=0x61 && c<=0x7A )
		return(c-32);

	return(c);
}

void file_setAttr(File* file,uint8_t attribute,uint8_t val)
{
	if(val)
	{
		file->FileStatus|=1<<attribute;
	}
	else
	{
		file->FileStatus&=~(1<<attribute);
	}
}

uint8_t file_getAttr(File* file,uint8_t attribute)
{
	return((file->FileStatus&(1<<attribute))!=0);
}

char file_delete( char* full_filename )
{
    //char fatfilename[11];
    FileSystem *fs = NULL;
	char * filename;
    
    SYSCALL_FILE_FDELETE();

	// identify the device driver
	filename = file_getVolume( full_filename, volume );

    fs = efs_get_filesystem( volume );
	if( fs == NULL ) return( FILE_INVALID_FS );
    
    if( filename == NULL ) return FILE_NOT_FOUND;
    
    //dir_getFatFileName(filename,fatfilename);
    //dir_getFatFileName_Long( filename, long_filename );   

    return fs_fileDelete( fs, ( uint8_t * )filename );
}



