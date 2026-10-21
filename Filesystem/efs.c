#include "efs.h"
#include "disc.h"
#include "partition.h"
#include "mass_mal.h"

///////////////////////////////////////////////////////////////////////////////

typedef struct _EmbeddedFileSystem
{
	uint8_t myCard;
	FileSystem myFs;

} EmbeddedFileSystem;

///////////////////////////////////////////////////////////////////////////////

#define MAX_DEVICE_LIST			4

///////////////////////////////////////////////////////////////////////////////

static EmbeddedFileSystem embedded_fs[ MAX_DEVICE_LIST ];
static EmbeddedFileSystem device_fs;

///////////////////////////////////////////////////////////////////////////////

int _efs_init_fs( FileSystem * fs, char* volume )
{
	uint8_t lun = 0;
    
    // normal disc units
	if( disc_InitDevice( &lun, volume ) == 0 )
	{
		part_initPartition( &fs->part, lun );
            
		if(fs->part.activePartition==-1)
		{
			fs->part.partitions[0].type=0x0B;
			fs->part.partitions[0].LBA_begin=0;
			fs->part.partitions[0].numSectors = disc_GetSectorCount( lun ); // efs->myCard.sectorCount;	

			part_initPartition(&fs->part, lun);
		}

		if(fs_initFs(fs, &fs->part))
		{
    		return(-2);
		}
		
		return(0);
	}
	return(-1);
}

FileSystem * efs_get_filesystem( char * volume )
{
    uint8_t i;
    uint8_t lun;
    
	lun = MAL_GetLun( volume );
	if( lun == LUN_NOT_FOUND ) return NULL;
    
    // include devices to filesystem
    if( ( lun == LUN_DEVICE ) ||
        ( lun == LUN_SYSTEM ) )
    {
        return &device_fs.myFs;
    }    

	// locate disc unit in the cache
    for( i = 0; i < MAX_DEVICE_LIST; i++ )
    {
        if( embedded_fs[ i ].myCard == lun )
        {
            return( &embedded_fs[ i ].myFs );
        }
    }

	// not found, initialize a new one
    for( i = 0; i < MAX_DEVICE_LIST; i++ )
    {
        if( embedded_fs[ i ].myCard == LUN_NOT_FOUND )
        {
            if( _efs_init_fs( &embedded_fs[ i ].myFs, volume ) != 0 ) return( NULL );
            return( &embedded_fs[ i ].myFs);
        }
    }
    
    return( NULL );
}

void efs_close_filesystem( FileSystem * fs )
{
    uint8_t i;
    uint8_t lun = fs->part.disc;
    
    for( i = 0; i < MAX_DEVICE_LIST; i++ )
    {
        if( embedded_fs[ i ].myCard == lun )
        {
            embedded_fs[ i ].myCard = LUN_NOT_FOUND;
            break;
        }
    }	
}

int efs_format_unit( char * volume )
{
    FileSystem * fs;
    
    fs = efs_get_filesystem( volume );
    if( fs == NULL ) return -1;
    
    return disc_Format( fs->part.disc );
}

void efs_init( void )
{
	int i;
	int size = (int)sizeof(embedded_fs);
	memset( embedded_fs, 0x00, size );

    // init for disc units
    for( i = 0; i < MAX_DEVICE_LIST; i++ )
    {
        embedded_fs[ i ].myCard = LUN_NOT_FOUND;
    }	
    
    #if defined TIMA_OS
    // init for devices
    memset( &device_fs, 0x00, sizeof( device_fs ) );
    device_fs.myCard = LUN_DEVICE;
    device_fs.myFs.type = SYS_DEVICE;
    #endif
}

