#include "fs_time.h"
#include "libc.h"

///////////////////////////////////////////////////////////////////////////////

uint16_t fs_makeDate(void)
{
	uint8_t m,d;
	uint16_t y;

    date_time_t * time_tm;
    time_t time_now;
    
    time_now = libc_gettime();
    
    if( time_now != 0 )
    {
        time_tm = libc_localtime( time_now );
        
        y = time_tm->tm_year-1980;
        m = time_tm->tm_mon;
        d = time_tm->tm_mday;
    }
    else
    {
        y = 2013-1980;
        m = 01;
        d = 01;
    }
	
	return(
		(y>127?127<<9:(y&0x3F)<<9)   |
		((m==0||m>12)?1:(m&0xF)<<5)  |
		((d==0||d>31)?1:(d&0x1F))
	);
}

uint16_t fs_makeTime(void)
{
	uint8_t s,m,h;
    
    date_time_t * time_tm;
    time_t time_now;
        
    time_now = libc_gettime();
    
    if( time_now != 0 )
    {
        time_tm = libc_localtime( time_now );

        s = time_tm->tm_sec;
        m = time_tm->tm_min;
        h = time_tm->tm_hour;
    }
    else
    {
        s = 10;
        m = 35;
        h = 10;
    }
	
	return(
		(h>23?0:(h&0x1F)<<11) |
		(m>59?0:(m&0x3F)<<5)  |
		(s>59?0:(s-s%2)/2)
	);
}

uint8_t fs_hasTimeSupport(void)
{
    return ( libc_gettime() != 0 );
}

const static char * str_month[12] = 
{
    "Jan", "Feb", "Mar", "Apr", "May", "Jun", 
    "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
};

uint16_t fs_TimeFromString( char * str_in )
{
    // input format is GCC format:
    // time is 21:06:19
    uint8_t s,m,h;
    
    s = ( ( str_in[6] & 0x0F ) * 10 ) + ( str_in[7] & 0x0F );
    m = ( ( str_in[3] & 0x0F ) * 10 ) + ( str_in[4] & 0x0F );
    h = ( ( str_in[0] & 0x0F ) * 10 ) + ( str_in[1] & 0x0F );
    
	return(
		(h>23?0:(h&0x1F)<<11) |
		(m>59?0:(m&0x3F)<<5)  |
		(s>59?0:(s-s%2)/2)
	);    
}

uint16_t fs_DateFromString( char * str_in )
{
    // input format is GCC format:
    // data is "Jul 27 2012"
	uint16_t m,d;
	uint16_t y;
    
    for( m = 1; m <= 12; m++ )
    {
        if( !strncmp( str_in, str_month[m-1], 3) )
        {
            break;
        }
    }
    
    d = ( ( str_in[4] & 0x0F ) * 10 ) + ( str_in[5] & 0x0F );
    y = (uint16_t)libc_atoi( &str_in[7] ) - 1980;

	return(
		(y>127?127<<9:(y&0x3F)<<9)   |
		((m==0||m>12)?1:(m&0xF)<<5)  |
		((d==0||d>31)?1:(d&0x1F))
	);    
}

void fs_TimeToString( uint16_t date, uint16_t time, char * str_out )
{
    uint16_t hour, min, day, month, year;
    // uint8_t sec;
    
    hour = ( time & 0xF800 ) >> 11;
    min = ( time & 0x07E0 ) >> 5;
    //sec = ( time & 0x001F ) << 1; 

    year = ( ( date & 0xFE00 ) >> 9 ) + 1980;
    month = ( date & 0x01E0 ) >> 5;
    day = ( date & 0x001F ); 
    
    libc_sprintk( str_out, "%s %2d %02d:%02d", str_month[month], day, hour, min );
}

