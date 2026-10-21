#include "exceptions.h"
#include "objects.h"
#include "application.h"
#include "heap.h"
#include "native.h"
#include "stack.h"
#include "methods.h"
#include "strings.h"
#include "vm.h"
#include "threads.h"
#include "vm_debug.h"

#ifdef TIMA_OS
#include "debug.h"
#include "system.h"
#endif

/////////////////////////////////////////////////////////////////////////////

#define VSF_PRINTK_BUF_SIZE         2048

/////////////////////////////////////////////////////////////////////////////

static bool_t b_new_line = TRUE;
static uint32_t base_address = 0;
//static uint16_t vm_state;

static vm_console_t vm_console_hdl = NULL;

static char vsf_printk_buf[VSF_PRINTK_BUF_SIZE];

/////////////////////////////////////////////////////////////////////////////

uint16_t vm_monitor_process( void )
{
    uint16_t ret_state = app_data->vm_state;
    app_data->vm_state = MONITOR_NONE;
    return ret_state;
}

void vm_monitor_init( void )
{
    vm_console_hdl = NULL;
}

void vm_monitor_base_address( uint32_t address )
{
    base_address = address;
}

void vm_monitor_breakpoint( bool_t is_break )
{
    thread_t * curr_thread = thread_get();
    uint32_t addr = 0;
    uint32_t method_id = 0;
    
    if( curr_thread != NULL )
    {
        addr = ( uint32_t )( ( uint8_t * )curr_thread->pc - ( uint8_t * )method_get_address( curr_thread->ptr_method ) );
        addr &= 0x0FFFF;
        
        method_id = curr_thread->ptr_method->id;
    }
    
    vm_printk( LEVEL_BREAKPT, "%08x-%04x%s\r\n", method_id, addr, is_break ? "":"-GO" );
}

vm_console_t vm_debug_set_console( vm_console_t new_hdl )
{
    vm_console_t old = vm_console_hdl;
    vm_console_hdl = new_hdl;
    return old;
}

void vm_printk(int level, const char * fmt, ...)
{
	va_list args;
	int printed_len;
	int index = 0;
	char str_temp[50];
	char * p_cr;
    
    if( vm_console_hdl == NULL ) return;
    if( ( app_data->debug_printk == FALSE ) && ( !( level & LEVEL_STOP ) ) ) return;

	vsf_printk_buf[0] = 0;
    
    if(!( level & DEBUG_LEVEL )) return;

	// header information
	if( b_new_line == TRUE )
	{
		if( level & LEVEL_HEAP )
		{
			sprintf( str_temp, "HEAP  %08d: ", ms_timer_get_ms() );
		}
		else if( thread_get() != NULL )
		{
			sprintf( str_temp, "T%03d, %08d: ", thread_get()->thread_id, ms_timer_get_ms() );
		}
		else
		{
			sprintf( str_temp, "T---, %08d: ", ms_timer_get_ms() );
		}

		strcat( vsf_printk_buf, str_temp );

		if( level & LEVEL_CONSOLE )strcat( vsf_printk_buf, "[CONSOLE]: " );
		if( level & LEVEL_INFO )   strcat( vsf_printk_buf, "[ INFO  ]: " );
		if( level & LEVEL_WARN )   strcat( vsf_printk_buf, "[WARNING]: " );
		if( level & LEVEL_ERROR )  strcat( vsf_printk_buf, "[ ERROR ]: " );
		if( level & LEVEL_STACK )  strcat( vsf_printk_buf, "[ STACK ]: " );
		if( level & LEVEL_GC )     strcat( vsf_printk_buf, "[  GC   ]: " );
		if( level & LEVEL_THREAD ) strcat( vsf_printk_buf, "[THREAD ]: " );
		if( level & LEVEL_BREAKPT )strcat( vsf_printk_buf, "[ BRKPT ]: " );
		if( level & LEVEL_STOP )   strcat( vsf_printk_buf, "[ STOP  ]: " );
	}

	b_new_line = FALSE;

	index = (int)strlen( vsf_printk_buf );

	// append log data
	va_start(args, fmt);
	printed_len = vsnprintf(&vsf_printk_buf[index], VSF_PRINTK_BUF_SIZE-index, fmt, args);
	va_end(args);

	// send it over
	// DEBUG_PRINTK( vsf_printk_buf );
    // ftm_console_write( vsf_printk_buf );
    vm_console_hdl( vsf_printk_buf );

	// make sure there is the right end of line
	p_cr = strstr( vsf_printk_buf, "\n" );
	if( p_cr != NULL )
	{
		b_new_line = TRUE;
        // DEBUG_FLUSH();
	}
}

