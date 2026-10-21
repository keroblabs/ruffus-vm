#include "util_date.h"
#include "heap.h"
#include "application.h"
#include "threads.h"
#include "exceptions.h"
#include "native.h"
#include "objects.h"
#include "stack.h"
#include "value_type.h"
#include "strings.h"
//#include "libc.h"

#ifdef TIMA_OS
#include "system.h"
#endif

///////////////////////////////////////////////////////////////////////////

// use New method implementation to hold a method
// use New implementation to mark start block
// use End new implementation to mark end block to keep

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////

object_t native_util_date_new( void )
{
    return( object_create( GET_CLASS_REF( NATIVE_CLASS_UTIL_DATE ), T_CLASS, NATIVE_UTIL_DATE_TOTAL_FIELDS ) );
}

///////////////////////////////////////////////////////////////////////////

void native_method_util_date_init( void )
{
    // Date()
    // Allocates a Date object and initializes it so that it represents 
    // the time at which it was allocated, measured to the nearest 
    // millisecond. 
    // Implementation code: CF37AEE6
    object_t object;
	object_t * fields;
	int64_t time_val;

    object = stack_pop();

    // put your code here
	fields = object_get_fields_ptr( object );
	rtc_driver_get( &time_val );
	fields[ NATIVE_FIELD_UTIL_DATE_TIME ] = value_create_long( time_val );
}

void native_method_util_date_init_int_int_int( void )
{
    // Date(int year, int month, int date)
    // Deprecated. As of JDK version 1.1, replaced by Calendar.set(year 
    // + 1900, month, date) or GregorianCalendar(year + 1900, month, 
    // date). 
    // Implementation code: 56D1397A
    object_t int_year;
    object_t int_month;
    object_t int_date;
    object_t object;
	struct tm tm_time;

    int_date = stack_pop();
    int_month = stack_pop();
    int_year = stack_pop();
    object = stack_pop();

	// get date information
	tm_time.tm_mday = value_get_int(int_date);
	tm_time.tm_mon = value_get_int(int_month);
	tm_time.tm_year = value_get_int(int_year);

	// set current system time
	object_get_fields_ptr( object )[ NATIVE_FIELD_UTIL_DATE_TIME ] = value_create_long( mktime( &tm_time ) );
}

void native_method_util_date_init_int_int_int_int_int( void )
{
    // Date(int year, int month, int date, int hrs, int min)
    // Deprecated. As of JDK version 1.1, replaced by Calendar.set(year 
    // + 1900, month, date, hrs, min) or GregorianCalendar(year 
    // + 1900, month, date, hrs, min). 
    // Implementation code: BDEE3FA1
    object_t int_year;
    object_t int_month;
    object_t int_date;
    object_t int_hrs;
    object_t int_min;
    object_t object;
	struct tm tm_time;

    int_min = stack_pop();
    int_hrs = stack_pop();
    int_date = stack_pop();
    int_month = stack_pop();
    int_year = stack_pop();
    object = stack_pop();

	// get date information
	tm_time.tm_mday = value_get_int(int_date);
	tm_time.tm_mon = value_get_int(int_month);
	tm_time.tm_year = value_get_int(int_year);
	tm_time.tm_hour = value_get_int(int_hrs);
	tm_time.tm_min = value_get_int(int_min);

    // put your code here
	object_get_fields_ptr( object )[ NATIVE_FIELD_UTIL_DATE_TIME ] = value_create_long( mktime( &tm_time ) );
}

void native_method_util_date_init_int_int_int_int_int_int( void )
{
    // Date(int year, int month, int date, int hrs, int min, int sec)
    // Deprecated. As of JDK version 1.1, replaced by Calendar.set(year 
    // + 1900, month, date, hrs, min, sec) or GregorianCalendar(year 
    // + 1900, month, date, hrs, min, sec). 
    // Implementation code: 0250C854
    object_t int_year;
    object_t int_month;
    object_t int_date;
    object_t int_hrs;
    object_t int_min;
    object_t int_sec;
    object_t object;
	struct tm tm_time;

    int_sec = stack_pop();
    int_min = stack_pop();
    int_hrs = stack_pop();
    int_date = stack_pop();
    int_month = stack_pop();
    int_year = stack_pop();
    object = stack_pop();

	// get date information
	tm_time.tm_mday = value_get_int(int_date);
	tm_time.tm_mon = value_get_int(int_month);
	tm_time.tm_year = value_get_int(int_year);
	tm_time.tm_hour = value_get_int(int_hrs);
	tm_time.tm_min = value_get_int(int_min);
	tm_time.tm_sec = value_get_int(int_sec);

    // put your code here
	object_get_fields_ptr( object )[ NATIVE_FIELD_UTIL_DATE_TIME ] = value_create_long( mktime( &tm_time ) );
}

void native_method_util_date_init_long( void )
{
    // Date(long date)
    // Allocates a Date object and initializes it to represent 
    // the specified number of milliseconds since the standard 
    // base time known as "the epoch", namely January 1, 1970, 
    // 00:00:00 GMT. 
    // Implementation code: 48506923
    object_t long_date;
    object_t object;

    long_date = stack_pop();
    object = stack_pop();

    // put your code here
	object_get_fields_ptr( object )[ NATIVE_FIELD_UTIL_DATE_TIME ] = value_create_long( value_get_long( long_date ) );
}

void native_method_util_date_init_string( void )
{
    // Date(String s)
    // Deprecated. As of JDK version 1.1, replaced by DateFormat.parse(String 
    // s). 
    // Implementation code: 8FF9FF73
    object_t string_s;
    object_t object;

    string_s = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

///////////////////////////////////////////////////////////////////////////

void native_method_util_date_after_date( void )
{
    // boolean after(Date when)
    // Tests if this date is after the specified date. 
    // Implementation code: FE1F39E2
    object_t date_when;
    object_t object;
    bool_t ret_value = 0;

    date_when = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: boolean
    stack_push( value_create( &ret_value, T_BOOLEAN ) );
}

void native_method_util_date_before_date( void )
{
    // boolean before(Date when)
    // Tests if this date is before the specified date. 
    // Implementation code: FA11C67F
    object_t date_when;
    object_t object;
    bool_t ret_value = 0;

    date_when = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: boolean
    stack_push( value_create( &ret_value, T_BOOLEAN ) );
}

void native_method_util_date_clone( void )
{
    // Object clone()
    // Return a copy of this object. 
    // Implementation code: 75A33569
    object_t object;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: Object
    stack_push( 0 );
}

void native_method_util_date_compareto_date( void )
{
    // int compareTo(Date anotherDate)
    // Compares two Dates for ordering. 
    // Implementation code: 5889DBE8
    object_t date_anotherdate;
    object_t object;
    int32_t ret_value = 0;

    date_anotherdate = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push( value_create( &ret_value, T_INT ) );
}

void native_method_util_date_equals_object( void )
{
    // boolean equals(Object obj)
    // Compares two dates for equality. 
    // Implementation code: AAC97610
    object_t object_obj;
    object_t object;
    bool_t ret_value = 0;

    object_obj = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: boolean
    stack_push( value_create( &ret_value, T_BOOLEAN ) );
}

void native_method_util_date_getdate( void )
{
    // int getDate()
    // Deprecated. As of JDK version 1.1, replaced by Calendar.get(Calendar.DAY_OF_MONTH). 
    // Implementation code: F3142ABD
    object_t object;
    int32_t ret_value = 0;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push( value_create( &ret_value, T_INT ) );
}

void native_method_util_date_getday( void )
{
    // int getDay()
    // Deprecated. As of JDK version 1.1, replaced by Calendar.get(Calendar.DAY_OF_WEEK). 
    // Implementation code: CB099D8C
    object_t object;
    int32_t ret_value = 0;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push( value_create( &ret_value, T_INT ) );
}

void native_method_util_date_gethours( void )
{
    // int getHours()
    // Deprecated. As of JDK version 1.1, replaced by Calendar.get(Calendar.HOUR_OF_DAY). 
    // Implementation code: F44ABACA
    object_t object;
    int32_t ret_value = 0;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push( value_create( &ret_value, T_INT ) );
}

void native_method_util_date_getminutes( void )
{
    // int getMinutes()
    // Deprecated. As of JDK version 1.1, replaced by Calendar.get(Calendar.MINUTE). 
    // Implementation code: 6AF53CF0
    object_t object;
    int32_t ret_value = 0;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push( value_create( &ret_value, T_INT ) );
}

void native_method_util_date_getmonth( void )
{
    // int getMonth()
    // Deprecated. As of JDK version 1.1, replaced by Calendar.get(Calendar.MONTH). 
    // Implementation code: B240BED7
    object_t object;
    int32_t ret_value = 0;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push( value_create( &ret_value, T_INT ) );
}

void native_method_util_date_getseconds( void )
{
    // int getSeconds()
    // Deprecated. As of JDK version 1.1, replaced by Calendar.get(Calendar.SECOND). 
    // Implementation code: C88B36D7
    object_t object;
    int32_t ret_value = 0;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push( value_create( &ret_value, T_INT ) );
}

void native_method_util_date_gettime( void )
{
    // long getTime()
    // Returns the number of milliseconds since January 1, 1970, 
    // 00:00:00 GMT represented by this Date object. 
    // Implementation code: DF99E548
    object_t object;
    int64_t ret_value = 0L;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
	ret_value = value_get_long( object_get_fields_ptr( object )[ NATIVE_FIELD_UTIL_DATE_TIME ] );

    // return type: long
    stack_push_long( ret_value );
}

void native_method_util_date_gettimezoneoffset( void )
{
    // int getTimezoneOffset()
    // Deprecated. As of JDK version 1.1, replaced by -(Calendar.get(Calendar.ZONE_OFFSET) 
    // + Calendar.get(Calendar.DST_OFFSET)) / (60 * 1000). 
    // Implementation code: 7FDDAEE5
    object_t object;
    int32_t ret_value = 0;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push( value_create( &ret_value, T_INT ) );
}

void native_method_util_date_getyear( void )
{
    // int getYear()
    // Deprecated. As of JDK version 1.1, replaced by Calendar.get(Calendar.YEAR) 
    // - 1900. 
    // Implementation code: 8F94AD9F
    object_t object;
    int32_t ret_value = 0;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push( value_create( &ret_value, T_INT ) );
}

void native_method_util_date_hashcode( void )
{
    // int hashCode()
    // Returns a hash code value for this object. 
    // Implementation code: 8FCC1BCD
    object_t object;
    int32_t ret_value = 0;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push( value_create( &ret_value, T_INT ) );
}

void native_method_util_date_parse_string( void )
{
    // static long parse(String s)
    // Deprecated. As of JDK version 1.1, replaced by DateFormat.parse(String 
    // s). 
    // Implementation code: 8FF9FF73
    object_t string_s;
    object_t object;

    string_s = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_util_date_setdate_int( void )
{
    // void setDate(int date)
    // Deprecated. As of JDK version 1.1, replaced by Calendar.set(Calendar.DAY_OF_MONTH, 
    // int date). 
    // Implementation code: 2685D9FD
    object_t int_date;
    object_t object;

    int_date = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_util_date_sethours_int( void )
{
    // void setHours(int hours)
    // Deprecated. As of JDK version 1.1, replaced by Calendar.set(Calendar.HOUR_OF_DAY, 
    // int hours). 
    // Implementation code: F3597701
    object_t int_hours;
    object_t object;

    int_hours = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_util_date_setminutes_int( void )
{
    // void setMinutes(int minutes)
    // Deprecated. As of JDK version 1.1, replaced by Calendar.set(Calendar.MINUTE, 
    // int minutes). 
    // Implementation code: 798E121A
    object_t int_minutes;
    object_t object;

    int_minutes = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_util_date_setmonth_int( void )
{
    // void setMonth(int month)
    // Deprecated. As of JDK version 1.1, replaced by Calendar.set(Calendar.MONTH, 
    // int month). 
    // Implementation code: EC61BDA5
    object_t int_month;
    object_t object;

    int_month = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_util_date_setseconds_int( void )
{
    // void setSeconds(int seconds)
    // Deprecated. As of JDK version 1.1, replaced by Calendar.set(Calendar.SECOND, 
    // int seconds). 
    // Implementation code: E51E6261
    object_t int_seconds;
    object_t object;

    int_seconds = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_util_date_settime_long( void )
{
    // void setTime(long time)
    // Sets this Date object to represent a point in time that 
    // is time milliseconds after January 1, 1970 00:00:00 GMT. 
    // Implementation code: 77F62D02
    object_t long_time;
    object_t object;

    long_time = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_util_date_setyear_int( void )
{
    // void setYear(int year)
    // Deprecated. As of JDK version 1.1, replaced by Calendar.set(Calendar.YEAR, 
    // year + 1900). 
    // Implementation code: 0F149E7D
    object_t int_year;
    object_t object;

    int_year = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_util_date_togmtstring( void )
{
    // String toGMTString()
    // Deprecated. As of JDK version 1.1, replaced by DateFormat.format(Date 
    // date), using a GMT TimeZone. 
    // Implementation code: 3577FFAE
    object_t object;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: String
    stack_push( strings_create( "" ) );
}

void native_method_util_date_tolocalestring( void )
{
    // String toLocaleString()
    // Deprecated. As of JDK version 1.1, replaced by DateFormat.format(Date 
    // date). 
    // Implementation code: 912ECADA
    object_t object;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: String
    stack_push( strings_create( "" ) );
}

void native_method_util_date_tostring( void )
{
    // String toString()
    // Converts this Date object to a String of the form: 
    // Implementation code: C4C3E0BB
    object_t object;
	char * time_str;
	object_t * fields;
	time_t time_value;

    object = stack_pop();

	// get timer value
	fields = object_get_fields_ptr( object );
	time_value = value_get_long(fields[ NATIVE_FIELD_UTIL_DATE_TIME ]);

	// convert to string (time.h accepts seconds of epoch)
	time_value /= ( uint64_t )1000;
	// time_str = tima_ctime( ( const time_t *) &time_value );
	time_str = ctime( &time_value );
	time_str[strlen(time_str)-1] = 0;

    // return type: String
    stack_push( strings_create( time_str ) );
}

void native_method_util_date_utc_int_int_int_int_int_int( void )
{
    // static long UTC(int year, int month, int date, int hrs, int min, int sec)
    // Deprecated. As of JDK version 1.1, replaced by Calendar.set(year 
    // + 1900, month, date, hrs, min, sec) or GregorianCalendar(year 
    // + 1900, month, date, hrs, min, sec), using a UTC TimeZone, 
    // followed by Calendar.getTime().getTime(). 
    // Implementation code: 0F25C2EA
    object_t int_year;
    object_t int_month;
    object_t int_date;
    object_t int_hrs;
    object_t int_min;
    object_t int_sec;
    int64_t ret_value = 0L;

    int_sec = stack_pop();
    int_min = stack_pop();
    int_hrs = stack_pop();
    int_date = stack_pop();
    int_month = stack_pop();
    int_year = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: long
    stack_push( value_create( &ret_value, T_LONG ) );
}

///////////////////////////////////////////////////////////////////////////

void native_util_date_invoke(uint16_t mref)
{
    switch( mref )
    {
        case NATIVE_UTIL_DATE_INIT:
            native_method_util_date_init();
            break;

        case NATIVE_UTIL_DATE_INIT_INT_INT_INT:
            native_method_util_date_init_int_int_int();
            break;

        case NATIVE_UTIL_DATE_INIT_INT_INT_INT_INT_INT:
            native_method_util_date_init_int_int_int_int_int();
            break;

        case NATIVE_UTIL_DATE_INIT_INT_INT_INT_INT_INT_INT:
            native_method_util_date_init_int_int_int_int_int_int();
            break;

        case NATIVE_UTIL_DATE_INIT_LONG:
            native_method_util_date_init_long();
            break;

        case NATIVE_UTIL_DATE_INIT_STRING:
            native_method_util_date_init_string();
            break;

        case NATIVE_UTIL_DATE_AFTER_DATE:
            native_method_util_date_after_date();
            break;

        case NATIVE_UTIL_DATE_BEFORE_DATE:
            native_method_util_date_before_date();
            break;

        case NATIVE_UTIL_DATE_CLONE:
            native_method_util_date_clone();
            break;

        case NATIVE_UTIL_DATE_COMPARETO_DATE:
            native_method_util_date_compareto_date();
            break;

        case NATIVE_UTIL_DATE_EQUALS_OBJECT:
            native_method_util_date_equals_object();
            break;

        case NATIVE_UTIL_DATE_GETDATE:
            native_method_util_date_getdate();
            break;

        case NATIVE_UTIL_DATE_GETDAY:
            native_method_util_date_getday();
            break;

        case NATIVE_UTIL_DATE_GETHOURS:
            native_method_util_date_gethours();
            break;

        case NATIVE_UTIL_DATE_GETMINUTES:
            native_method_util_date_getminutes();
            break;

        case NATIVE_UTIL_DATE_GETMONTH:
            native_method_util_date_getmonth();
            break;

        case NATIVE_UTIL_DATE_GETSECONDS:
            native_method_util_date_getseconds();
            break;

        case NATIVE_UTIL_DATE_GETTIME:
            native_method_util_date_gettime();
            break;

        case NATIVE_UTIL_DATE_GETTIMEZONEOFFSET:
            native_method_util_date_gettimezoneoffset();
            break;

        case NATIVE_UTIL_DATE_GETYEAR:
            native_method_util_date_getyear();
            break;

        case NATIVE_UTIL_DATE_HASHCODE:
            native_method_util_date_hashcode();
            break;

        case NATIVE_UTIL_DATE_PARSE_STRING:
            native_method_util_date_parse_string();
            break;

        case NATIVE_UTIL_DATE_SETDATE_INT:
            native_method_util_date_setdate_int();
            break;

        case NATIVE_UTIL_DATE_SETHOURS_INT:
            native_method_util_date_sethours_int();
            break;

        case NATIVE_UTIL_DATE_SETMINUTES_INT:
            native_method_util_date_setminutes_int();
            break;

        case NATIVE_UTIL_DATE_SETMONTH_INT:
            native_method_util_date_setmonth_int();
            break;

        case NATIVE_UTIL_DATE_SETSECONDS_INT:
            native_method_util_date_setseconds_int();
            break;

        case NATIVE_UTIL_DATE_SETTIME_LONG:
            native_method_util_date_settime_long();
            break;

        case NATIVE_UTIL_DATE_SETYEAR_INT:
            native_method_util_date_setyear_int();
            break;

        case NATIVE_UTIL_DATE_TOGMTSTRING:
            native_method_util_date_togmtstring();
            break;

        case NATIVE_UTIL_DATE_TOLOCALESTRING:
            native_method_util_date_tolocalestring();
            break;

        case NATIVE_UTIL_DATE_TOSTRING:
            native_method_util_date_tostring();
            break;

        case NATIVE_UTIL_DATE_UTC_INT_INT_INT_INT_INT_INT:
            native_method_util_date_utc_int_int_int_int_int_int();
            break;

        default:
            exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
            break;

    }
}


