#include "types.h"

#include "application.h"
#include "vm.h"

void platform_console_write( char * text )
{
	printf(text);
}

#if defined __MACH__
int SDL_main( int argc, char* argv[] )
#else
int main( int argc, char* argv[] )
#endif
{
	app_data_t * ret_ptr;

	// initiate VM
    app_ruffus_init();

    // attach print console to VM
    vm_debug_set_console( platform_console_write );

    // load startup application if exists
    app_open_file( "/local/ThreadDemo.rja" );

	while( 1 )
	{
		// execute VM
		ret_ptr = app_execute_vm();
		if( ret_ptr != NULL )
		{
			// release file buffer
			free( app_get_file_buffer( ret_ptr ) );

			// release app data
			free( ret_ptr );
		}
	}
    
    return 0;
}
