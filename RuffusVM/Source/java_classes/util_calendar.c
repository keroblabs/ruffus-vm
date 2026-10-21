#include <time.h>

#include "util_calendar.h"
#include "heap.h"
#include "application.h"
#include "threads.h"
#include "exceptions.h"
#include "native.h"
#include "objects.h"
#include "stack.h"
#include "value_type.h"
#include "strings.h"

///////////////////////////////////////////////////////////////////////////

// use New method implementation to hold a method
// use New implementation to mark start block
// use End new implementation to mark end block to keep

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////

#define NATIVE_FIELD_VALUE_UTIL_CALENDAR_ERA                        0

#define NATIVE_FIELD_VALUE_UTIL_CALENDAR_YEAR                       1
#define NATIVE_FIELD_VALUE_UTIL_CALENDAR_MONTH  		            2
#define NATIVE_FIELD_VALUE_UTIL_CALENDAR_WEEK_OF_YEAR  	            3
#define NATIVE_FIELD_VALUE_UTIL_CALENDAR_WEEK_OF_MONTH              4
#define NATIVE_FIELD_VALUE_UTIL_CALENDAR_DATE  			            5
#define NATIVE_FIELD_VALUE_UTIL_CALENDAR_DAY_OF_MONTH  	            5
#define NATIVE_FIELD_VALUE_UTIL_CALENDAR_DAY_OF_YEAR  	            6
#define NATIVE_FIELD_VALUE_UTIL_CALENDAR_DAY_OF_WEEK  	            7
#define NATIVE_FIELD_VALUE_UTIL_CALENDAR_DAY_OF_WEEK_IN_MONTH       8
#define NATIVE_FIELD_VALUE_UTIL_CALENDAR_AM_PM  		            9
#define NATIVE_FIELD_VALUE_UTIL_CALENDAR_HOUR  			            10
#define NATIVE_FIELD_VALUE_UTIL_CALENDAR_HOUR_OF_DAY  	            11
#define NATIVE_FIELD_VALUE_UTIL_CALENDAR_MINUTE  		            12
#define NATIVE_FIELD_VALUE_UTIL_CALENDAR_SECOND  		            13
#define NATIVE_FIELD_VALUE_UTIL_CALENDAR_MILLISECOND  	            14
#define NATIVE_FIELD_VALUE_UTIL_CALENDAR_ZONE_OFFSET  	            15
#define NATIVE_FIELD_VALUE_UTIL_CALENDAR_DST_OFFSET  	            16
#define NATIVE_FIELD_VALUE_UTIL_CALENDAR_FIELD_COUNT  	            17

#define NATIVE_FIELD_VALUE_UTIL_CALENDAR_SUNDAY  		1
#define NATIVE_FIELD_VALUE_UTIL_CALENDAR_MONDAY  		2
#define NATIVE_FIELD_VALUE_UTIL_CALENDAR_TUESDAY  		3
#define NATIVE_FIELD_VALUE_UTIL_CALENDAR_WEDNESDAY  	4
#define NATIVE_FIELD_VALUE_UTIL_CALENDAR_THURSDAY  		5
#define NATIVE_FIELD_VALUE_UTIL_CALENDAR_FRIDAY  		6
#define NATIVE_FIELD_VALUE_UTIL_CALENDAR_SATURDAY  		7

#define NATIVE_FIELD_VALUE_UTIL_CALENDAR_JANUARY  		0
#define NATIVE_FIELD_VALUE_UTIL_CALENDAR_FEBRUARY  		1
#define NATIVE_FIELD_VALUE_UTIL_CALENDAR_MARCH  		2
#define NATIVE_FIELD_VALUE_UTIL_CALENDAR_APRIL  		3
#define NATIVE_FIELD_VALUE_UTIL_CALENDAR_MAY  			4
#define NATIVE_FIELD_VALUE_UTIL_CALENDAR_JUNE  			5
#define NATIVE_FIELD_VALUE_UTIL_CALENDAR_JULY  			6
#define NATIVE_FIELD_VALUE_UTIL_CALENDAR_AUGUST  		7
#define NATIVE_FIELD_VALUE_UTIL_CALENDAR_SEPTEMBER  	8
#define NATIVE_FIELD_VALUE_UTIL_CALENDAR_OCTOBER  		9
#define NATIVE_FIELD_VALUE_UTIL_CALENDAR_NOVEMBER  		10
#define NATIVE_FIELD_VALUE_UTIL_CALENDAR_DECEMBER  		11
#define NATIVE_FIELD_VALUE_UTIL_CALENDAR_UNDECIMBER  	12

#define NATIVE_FIELD_VALUE_UTIL_CALENDAR_AM  			0
#define NATIVE_FIELD_VALUE_UTIL_CALENDAR_PM  			1

#define NATIVE_FIELD_VALUE_UTIL_CALENDAR_ALL_STYLES  	0
#define NATIVE_FIELD_VALUE_UTIL_CALENDAR_SHORT  		1
#define NATIVE_FIELD_VALUE_UTIL_CALENDAR_LONG           2

///////////////////////////////////////////////////////////////////////////

object_t native_util_calendar_new( void )
{
    return( object_create( GET_CLASS_REF( NATIVE_CLASS_UTIL_CALENDAR ), T_CLASS, NATIVE_UTIL_CALENDAR_TOTAL_FIELDS ) );
}

///////////////////////////////////////////////////////////////////////////

void native_method_util_calendar_init( void )
{
    // protected Calendar()
    // Constructs a Calendar with the default time zone and locale. 
    // Implementation code: EC7CCF10
    object_t object;
    object_t date_obj;
    int64_t time_val;
    
    object = stack_peek(0);

    // put your code here
    date_obj = native_util_date_new();
	rtc_driver_get( &time_val );
	object_get_fields_ptr( date_obj )[ NATIVE_FIELD_UTIL_DATE_TIME ] = value_create_long( time_val );
    object_get_fields_ptr( object )[ NATIVE_FIELD_UTIL_CALENDAR_DATE_OBJ ] = date_obj;
    
    stack_remove(1);
}

void native_method_util_calendar_init_timezone_locale( void )
{
    // protected Calendar(TimeZone zone, Locale aLocale)
    // Constructs a calendar with the specified time zone and locale. 
    // Implementation code: 0510EB7F
    object_t timezone_zone;
    object_t locale_alocale;
    object_t object;

    locale_alocale = stack_pop();
    timezone_zone = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

///////////////////////////////////////////////////////////////////////////

void native_method_util_calendar_add_int_int( void )
{
    // abstract  void add(int field, int amount)
    // Adds or subtracts the specified amount of time to the given 
    // calendar field, based on the calendar's rules. 
    // Implementation code: FAC79543
    object_t int_field;
    object_t int_amount;
    object_t object;
    object_t date_obj;
    int value_to_set;
    int64_t * time_ptr;
    time_t time_value;
    struct tm * time_data;
    
    int_amount = stack_pop();
    int_field = stack_pop();
    object = stack_pop();

    // put your code here
    date_obj = object_get_fields_ptr( object )[ NATIVE_FIELD_UTIL_CALENDAR_DATE_OBJ ];
	time_ptr = ( ( int64_t * )object_get_ptr( object_get_fields_ptr( date_obj )[ NATIVE_FIELD_UTIL_DATE_TIME ] ) );
    time_value = *time_ptr / ( uint64_t )1000;
    time_data = localtime( &time_value );
    
    value_to_set = value_get_int( int_amount );
    
    switch( value_get_int( int_field ) )
    {
        case NATIVE_FIELD_VALUE_UTIL_CALENDAR_DAY_OF_MONTH:
            time_data->tm_mday += value_to_set;
            break;
            
        case NATIVE_FIELD_VALUE_UTIL_CALENDAR_DAY_OF_YEAR:
            time_data->tm_yday += value_to_set;
            break;
            
        case NATIVE_FIELD_VALUE_UTIL_CALENDAR_DAY_OF_WEEK:
            time_data->tm_wday += value_to_set;
            break;
            
        case NATIVE_FIELD_VALUE_UTIL_CALENDAR_MONTH:
            time_data->tm_mon += value_to_set;
            break;
            
        case NATIVE_FIELD_VALUE_UTIL_CALENDAR_YEAR:
            time_data->tm_year += value_to_set;
            break;
            
        case NATIVE_FIELD_VALUE_UTIL_CALENDAR_HOUR_OF_DAY:
        case NATIVE_FIELD_VALUE_UTIL_CALENDAR_HOUR:
            time_data->tm_hour += value_to_set;
            break;
            
        case NATIVE_FIELD_VALUE_UTIL_CALENDAR_MINUTE:
            time_data->tm_min += value_to_set;
            break;
            
        case NATIVE_FIELD_VALUE_UTIL_CALENDAR_SECOND:
            time_data->tm_sec += value_to_set;
            break;
            
        default:
            exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
    }
    
    time_value = mktime( time_data );
    *time_ptr = time_value * ( uint64_t )1000;
}

void native_method_util_calendar_after_object( void )
{
    // boolean after(Object when)
    // Returns whether this Calendar represents a time after the 
    // time represented by the specified Object. 
    // Implementation code: 8F5BA804
    object_t object_when;
    object_t object;
    bool_t ret_value = 0;

    object_when = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: boolean
    stack_push( value_create( &ret_value, T_BOOLEAN ) );
}

void native_method_util_calendar_before_object( void )
{
    // boolean before(Object when)
    // Returns whether this Calendar represents a time before the 
    // time represented by the specified Object. 
    // Implementation code: DDDAEA3A
    object_t object_when;
    object_t object;
    bool_t ret_value = 0;

    object_when = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: boolean
    stack_push( value_create( &ret_value, T_BOOLEAN ) );
}

void native_method_util_calendar_clear( void )
{
    // void clear()
    // Sets all the calendar field values and the time value (millisecond 
    // offset from the Epoch) of this Calendar undefined. 
    // Implementation code: 33FDB906
    object_t object;
    object_t date_obj;
    int64_t * time_ptr;

    // instead, this method updates the calendar with actual time to avoid memory usage
    object = stack_pop();

    // put your code here
    date_obj = object_get_fields_ptr( object )[ NATIVE_FIELD_UTIL_CALENDAR_DATE_OBJ ];
	time_ptr = ( ( int64_t * )object_get_ptr( object_get_fields_ptr( date_obj )[ NATIVE_FIELD_UTIL_DATE_TIME ] ) );
    rtc_driver_get( time_ptr );
}

void native_method_util_calendar_clear_int( void )
{
    // void clear(int field)
    // Sets the given calendar field value and the time value (millisecond 
    // offset from the Epoch) of this Calendar undefined. 
    // Implementation code: 3FE40EBA
    object_t int_field;
    object_t object;

    int_field = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_util_calendar_clone( void )
{
    // Object clone()
    // Creates and returns a copy of this object. 
    // Implementation code: 83E10E77
    object_t object;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: Object
    stack_push( 0 );
}

void native_method_util_calendar_compareto_calendar( void )
{
    // int compareTo(Calendar anotherCalendar)
    // Compares the time values (millisecond offsets from the Epoch) 
    // represented by two Calendar objects. 
    // Implementation code: DA40067B
    object_t calendar_anothercalendar;
    object_t object;
    int32_t ret_value = 0;

    calendar_anothercalendar = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push( value_create( &ret_value, T_INT ) );
}

void native_method_util_calendar_complete( void )
{
    // protected  void complete()
    // Fills in any unset fields in the calendar fields. 
    // Implementation code: E8A882A3
    object_t object;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_util_calendar_computefields( void )
{
    // protected abstract  void computeFields()
    // Converts the current millisecond time value time to calendar 
    // field values in fields[]. 
    // Implementation code: 61ED8878
    object_t object;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_util_calendar_computetime( void )
{
    // protected abstract  void computeTime()
    // Converts the current calendar field values in fields[] to 
    // the millisecond time value time. 
    // Implementation code: 9E90A0F1
    object_t object;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_util_calendar_equals_object( void )
{
    // boolean equals(Object obj)
    // Compares this Calendar to the specified Object. 
    // Implementation code: 87C06B35
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

void native_method_util_calendar_get_int( void )
{
    // int get(int field)
    // Returns the value of the given calendar field. 
    // Implementation code: 68E7A8DF
    object_t int_field;
    object_t object;
    object_t date_obj;
    time_t time_value;
    int32_t ret_value = 0;
    int32_t index;
    struct tm * time_data;

    int_field = stack_pop();
    object = stack_pop();

    // put your code here
    date_obj = object_get_fields_ptr( object )[ NATIVE_FIELD_UTIL_CALENDAR_DATE_OBJ ];
	time_value = value_get_long(object_get_fields_ptr( date_obj )[ NATIVE_FIELD_UTIL_DATE_TIME ]);
    time_value /= ( uint64_t )1000;
    time_data = localtime( &time_value );
    index = value_get_int( int_field );
    
    switch( index )
    {
        case NATIVE_FIELD_VALUE_UTIL_CALENDAR_DAY_OF_MONTH:
            ret_value = time_data->tm_mday;
            break;
            
        case NATIVE_FIELD_VALUE_UTIL_CALENDAR_DAY_OF_YEAR:
            ret_value = time_data->tm_yday;
            break;
            
        case NATIVE_FIELD_VALUE_UTIL_CALENDAR_DAY_OF_WEEK:
            ret_value = time_data->tm_wday;
            break;
            
        case NATIVE_FIELD_VALUE_UTIL_CALENDAR_MONTH:
            ret_value = time_data->tm_mon + 1;
            break;
            
        case NATIVE_FIELD_VALUE_UTIL_CALENDAR_YEAR:
            ret_value = time_data->tm_year + 1900;
            break;
            
        case NATIVE_FIELD_VALUE_UTIL_CALENDAR_HOUR_OF_DAY:
        case NATIVE_FIELD_VALUE_UTIL_CALENDAR_HOUR:
            ret_value = time_data->tm_hour;
            break;
            
        case NATIVE_FIELD_VALUE_UTIL_CALENDAR_MINUTE:
            ret_value = time_data->tm_min;
            break;
            
        case NATIVE_FIELD_VALUE_UTIL_CALENDAR_SECOND:
            ret_value = time_data->tm_sec;
            break;
            
        default:
            exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
    }
    
    // return type: int
    stack_push( value_create( &ret_value, T_INT ) );
}

void native_method_util_calendar_getactualmaximum_int( void )
{
    // int getActualMaximum(int field)
    // Returns the maximum value that the specified calendar field 
    // could have, given the time value of this Calendar. 
    // Implementation code: 6AC3AD7B
    object_t int_field;
    object_t object;
    int32_t ret_value = 0;

    int_field = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push( value_create( &ret_value, T_INT ) );
}

void native_method_util_calendar_getactualminimum_int( void )
{
    // int getActualMinimum(int field)
    // Returns the minimum value that the specified calendar field 
    // could have, given the time value of this Calendar. 
    // Implementation code: 88F59148
    object_t int_field;
    object_t object;
    int32_t ret_value = 0;

    int_field = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push( value_create( &ret_value, T_INT ) );
}

void native_method_util_calendar_getavailablelocales( void )
{
    // static Locale[] getAvailableLocales()
    // Returns an array of all locales for which the getInstance 
    // methods of this class can return localized instances. 
    // Implementation code: A64178F1

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: Locale[]
    stack_push( 0 );
}

void native_method_util_calendar_getdisplayname_int_int_locale( void )
{
    // String getDisplayName(int field, int style, Locale locale)
    // Returns the string representation of the calendar field 
    // value in the given style and locale. 
    // Implementation code: A522B307
    object_t int_field;
    object_t int_style;
    object_t locale_locale;
    object_t object;

    locale_locale = stack_pop();
    int_style = stack_pop();
    int_field = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: String
    stack_push( strings_create( "" ) );
}


void native_method_util_calendar_getfirstdayofweek( void )
{
    // int getFirstDayOfWeek()
    // Gets what the first day of the week is; e.g., SUNDAY in 
    // the U.S., MONDAY in France. 
    // Implementation code: BC0EE88A
    object_t object;
    int32_t ret_value = 0;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push( value_create( &ret_value, T_INT ) );
}

void native_method_util_calendar_getgreatestminimum_int( void )
{
    // abstract  int getGreatestMinimum(int field)
    // Returns the highest minimum value for the given calendar 
    // field of this Calendar instance. 
    // Implementation code: CAAF6854
    object_t int_field;
    object_t object;
    int32_t ret_value = 0;

    int_field = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push( value_create( &ret_value, T_INT ) );
}

void native_method_util_calendar_getinstance( void )
{
    // static Calendar getInstance()
    // Gets a calendar using the default time zone and locale. 
    // Implementation code: 05009CD0
    object_t date_obj;
    object_t object;
    int64_t time_val;
    uint16_t new_index;
    
    // put your code here
    object = instance_locate_native_static( CREATE_ID( NATIVE_CLASS_UTIL_CALENDAR, 0 ) );
    
    if( object == 0 )
    {
        object = native_util_calendar_new();
        date_obj = native_util_date_new();
        rtc_driver_get( &time_val );
        object_get_fields_ptr( date_obj )[ NATIVE_FIELD_UTIL_DATE_TIME ] = value_create_long( time_val );
        object_get_fields_ptr( object )[ NATIVE_FIELD_UTIL_CALENDAR_DATE_OBJ ] = date_obj;
        
        new_index = instance_resize_statics( 1 );
        instance_get_statics()[ new_index ] = object;
    }

    // return type: Calendar
    stack_push( object );
}

void native_method_util_calendar_getinstance_locale( void )
{
    // static Calendar getInstance(Locale aLocale)
    // Gets a calendar using the default time zone and specified 
    // locale. 
    // Implementation code: A4C21BBD
    object_t locale_alocale;

    locale_alocale = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: Calendar
    stack_push( 0 );
}

void native_method_util_calendar_getinstance_timezone( void )
{
    // static Calendar getInstance(TimeZone zone)
    // Gets a calendar using the specified time zone and default 
    // locale. 
    // Implementation code: F59AB089
    object_t timezone_zone;

    timezone_zone = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: Calendar
    stack_push( 0 );
}

void native_method_util_calendar_getinstance_timezone_locale( void )
{
    // static Calendar getInstance(TimeZone zone, Locale aLocale)
    // Gets a calendar with the specified time zone and locale. 
    // Implementation code: DD1B4575
    object_t timezone_zone;
    object_t locale_alocale;

    locale_alocale = stack_pop();
    timezone_zone = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: Calendar
    stack_push( 0 );
}

void native_method_util_calendar_getleastmaximum_int( void )
{
    // abstract  int getLeastMaximum(int field)
    // Returns the lowest maximum value for the given calendar 
    // field of this Calendar instance. 
    // Implementation code: E684EAB2
    object_t int_field;
    object_t object;
    int32_t ret_value = 0;

    int_field = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push( value_create( &ret_value, T_INT ) );
}

void native_method_util_calendar_getmaximum_int( void )
{
    // abstract  int getMaximum(int field)
    // Returns the maximum value for the given calendar field of 
    // this Calendar instance. 
    // Implementation code: 50ABFAB6
    object_t int_field;
    object_t object;
    int32_t ret_value = 0;

    int_field = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push( value_create( &ret_value, T_INT ) );
}

void native_method_util_calendar_getminimaldaysinfirstweek( void )
{
    // int getMinimalDaysInFirstWeek()
    // Gets what the minimal days required in the first week of 
    // the year are; e.g., if the first week is defined as one 
    // that contains the first day of the first month of a year, 
    // this method returns 1. 
    // Implementation code: B8C40A73
    object_t object;
    int32_t ret_value = 0;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push( value_create( &ret_value, T_INT ) );
}

void native_method_util_calendar_getminimum_int( void )
{
    // abstract  int getMinimum(int field)
    // Returns the minimum value for the given calendar field of 
    // this Calendar instance. 
    // Implementation code: F6D4DE06
    object_t int_field;
    object_t object;
    int32_t ret_value = 0;

    int_field = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push( value_create( &ret_value, T_INT ) );
}

void native_method_util_calendar_gettime( void )
{
    // Date getTime()
    // Returns a Date object representing this Calendar's time 
    // value (millisecond offset from the Epoch"). 
    // Implementation code: DA55F16A
    object_t object;
    object_t date_obj;

    object = stack_pop();

    // put your code here
    date_obj = object_get_fields_ptr( object )[ NATIVE_FIELD_UTIL_CALENDAR_DATE_OBJ ];

    // return type: Date
    stack_push( date_obj );
}

void native_method_util_calendar_gettimeinmillis( void )
{
    // long getTimeInMillis()
    // Returns this Calendar's time value in milliseconds. 
    // Implementation code: 697A02C2
    object_t object;
    object_t date_obj;
    int64_t ret_value = 0L;

    object = stack_pop();

    // put your code here
    date_obj = object_get_fields_ptr( object )[ NATIVE_FIELD_UTIL_CALENDAR_DATE_OBJ ];
	ret_value = value_get_long(object_get_fields_ptr( date_obj )[ NATIVE_FIELD_UTIL_DATE_TIME ]);

    // return type: long
    stack_push_long( ret_value );
}

void native_method_util_calendar_gettimezone( void )
{
    // TimeZone getTimeZone()
    // Gets the time zone. 
    // Implementation code: DEEBDB62
    object_t object;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: TimeZone
    stack_push( 0 );
}

void native_method_util_calendar_hashcode( void )
{
    // int hashCode()
    // Returns a hash code for this calendar. 
    // Implementation code: 4F375736
    object_t object;
    int32_t ret_value = 0;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push( value_create( &ret_value, T_INT ) );
}

void native_method_util_calendar_internalget_int( void )
{
    // protected  int internalGet(int field)
    // Returns the value of the given calendar field. 
    // Implementation code: 68E7A8DF
    object_t int_field;
    object_t object;
    int32_t ret_value = 0;

    int_field = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push( value_create( &ret_value, T_INT ) );
}

void native_method_util_calendar_islenient( void )
{
    // boolean isLenient()
    // Tells whether date/time interpretation is to be lenient. 
    // Implementation code: EACEAF79
    object_t object;
    bool_t ret_value = 0;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: boolean
    stack_push( value_create( &ret_value, T_BOOLEAN ) );
}

void native_method_util_calendar_isset_int( void )
{
    // boolean isSet(int field)
    // Determines if the given calendar field has a value set, 
    // including cases that the value has been set by internal 
    // fields calculations triggered by a get method call. 
    // Implementation code: 0EEC5A18
    object_t int_field;
    object_t object;
    bool_t ret_value = 0;

    int_field = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: boolean
    stack_push( value_create( &ret_value, T_BOOLEAN ) );
}

void native_method_util_calendar_roll_int_boolean( void )
{
    // abstract  void roll(int field, boolean up)
    // Adds or subtracts (up/down) a single unit of time on the 
    // given time field without changing larger fields. 
    // Implementation code: 3CE3AF80
    object_t int_field;
    object_t boolean_up;
    object_t object;

    boolean_up = stack_pop();
    int_field = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_util_calendar_roll_int_int( void )
{
    // void roll(int field, int amount)
    // Adds the specified (signed) amount to the specified calendar 
    // field without changing larger fields. 
    // Implementation code: 152A43CF
    object_t int_field;
    object_t int_amount;
    object_t object;

    int_amount = stack_pop();
    int_field = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_util_calendar_set_int_int( void )
{
    // void set(int field, int value)
    // Sets the given calendar field to the given value. 
    // Implementation code: ED694845
    object_t int_field;
    object_t int_value;
    object_t object;
    object_t date_obj;
    int value_to_set;
    int64_t * time_ptr;
    time_t time_value;
    struct tm * time_data;

    int_value = stack_pop();
    int_field = stack_pop();
    object = stack_pop();

    // put your code here
    date_obj = object_get_fields_ptr( object )[ NATIVE_FIELD_UTIL_CALENDAR_DATE_OBJ ];
	time_ptr = ( ( int64_t * )object_get_ptr( object_get_fields_ptr( date_obj )[ NATIVE_FIELD_UTIL_DATE_TIME ] ) );
    time_value = *time_ptr / ( uint64_t )1000;
    time_data = localtime( &time_value );
    
    value_to_set = value_get_int( int_value );
    
    switch( value_get_int( int_field ) )
    {
        case NATIVE_FIELD_VALUE_UTIL_CALENDAR_DAY_OF_MONTH:
            time_data->tm_mday = value_to_set;
            break;
            
        case NATIVE_FIELD_VALUE_UTIL_CALENDAR_DAY_OF_YEAR:
            time_data->tm_yday = value_to_set;
            break;
            
        case NATIVE_FIELD_VALUE_UTIL_CALENDAR_DAY_OF_WEEK:
            time_data->tm_wday = value_to_set;
            break;
            
        case NATIVE_FIELD_VALUE_UTIL_CALENDAR_MONTH:
            time_data->tm_mon = value_to_set - 1;
            break;
            
        case NATIVE_FIELD_VALUE_UTIL_CALENDAR_YEAR:
            time_data->tm_year = value_to_set - 1900;
            break;
            
        case NATIVE_FIELD_VALUE_UTIL_CALENDAR_HOUR_OF_DAY:
        case NATIVE_FIELD_VALUE_UTIL_CALENDAR_HOUR:
            time_data->tm_hour = value_to_set;
            break;
            
        case NATIVE_FIELD_VALUE_UTIL_CALENDAR_MINUTE:
            time_data->tm_min = value_to_set;
            break;
            
        case NATIVE_FIELD_VALUE_UTIL_CALENDAR_SECOND:
            time_data->tm_sec = value_to_set;
            break;
            
        default:
            exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
    }
    
    time_value = mktime( time_data );
    *time_ptr = time_value * ( uint64_t )1000;
}

void native_method_util_calendar_set_int_int_int( void )
{
    // void set(int year, int month, int date)
    // Sets the values for the calendar fields YEAR, MONTH, and 
    // DAY_OF_MONTH. 
    // Implementation code: F079712B
    object_t int_year;
    object_t int_month;
    object_t int_date;
    object_t object;
    object_t date_obj;
    int64_t * time_ptr;
    time_t time_value;
    struct tm * time_data;
    
    int_date = stack_pop();
    int_month = stack_pop();
    int_year = stack_pop();
    object = stack_pop();

    // put your code here
    date_obj = object_get_fields_ptr( object )[ NATIVE_FIELD_UTIL_CALENDAR_DATE_OBJ ];
	time_ptr = ( ( int64_t * )object_get_ptr( object_get_fields_ptr( date_obj )[ NATIVE_FIELD_UTIL_DATE_TIME ] ) );
    time_value = *time_ptr / ( uint64_t )1000;
    time_data = localtime( &time_value );
    
    time_data->tm_year = value_get_int( int_year ) - 1900;
    time_data->tm_mon = value_get_int( int_month ) - 1;
    time_data->tm_mday = value_get_int( int_date );
    
    time_value = mktime( time_data );
    *time_ptr = time_value * ( uint64_t )1000;
}

void native_method_util_calendar_set_int_int_int_int_int( void )
{
    // void set(int year, int month, int date, int hourOfDay, int minute)
    // Sets the values for the calendar fields YEAR, MONTH, DAY_OF_MONTH, 
    // HOUR_OF_DAY, and MINUTE. 
    // Implementation code: 2454A6B5
    object_t int_year;
    object_t int_month;
    object_t int_date;
    object_t int_hourofday;
    object_t int_minute;
    object_t object;
    object_t date_obj;
    int64_t * time_ptr;
    time_t time_value;
    struct tm * time_data;
    
    int_minute = stack_pop();
    int_hourofday = stack_pop();
    int_date = stack_pop();
    int_month = stack_pop();
    int_year = stack_pop();
    object = stack_pop();

    // put your code here
    date_obj = object_get_fields_ptr( object )[ NATIVE_FIELD_UTIL_CALENDAR_DATE_OBJ ];
	time_ptr = ( ( int64_t * )object_get_ptr( object_get_fields_ptr( date_obj )[ NATIVE_FIELD_UTIL_DATE_TIME ] ) );
    time_value = *time_ptr / ( uint64_t )1000;
    time_data = localtime( &time_value );
    
    time_data->tm_year = value_get_int( int_year ) - 1900;
    time_data->tm_mon = value_get_int( int_month ) - 1;
    time_data->tm_mday = value_get_int( int_date );
    time_data->tm_hour = value_get_int( int_hourofday );
    time_data->tm_min = value_get_int( int_minute );
    
    time_value = mktime( time_data );
    *time_ptr = time_value * ( uint64_t )1000;
}

void native_method_util_calendar_set_int_int_int_int_int_int( void )
{
    // void set(int year, int month, int date, int hourOfDay, int minute, int second)
    // Sets the values for the fields YEAR, MONTH, DAY_OF_MONTH, 
    // HOUR, MINUTE, and SECOND. 
    // Implementation code: B303DE1F
    object_t int_year;
    object_t int_month;
    object_t int_date;
    object_t int_hourofday;
    object_t int_minute;
    object_t int_second;
    object_t object;
    object_t date_obj;
    int64_t * time_ptr;
    time_t time_value;
    struct tm * time_data;
    
    int_second = stack_pop();
    int_minute = stack_pop();
    int_hourofday = stack_pop();
    int_date = stack_pop();
    int_month = stack_pop();
    int_year = stack_pop();
    object = stack_pop();

    // put your code here
    date_obj = object_get_fields_ptr( object )[ NATIVE_FIELD_UTIL_CALENDAR_DATE_OBJ ];
	time_ptr = ( ( int64_t * )object_get_ptr( object_get_fields_ptr( date_obj )[ NATIVE_FIELD_UTIL_DATE_TIME ] ) );
    time_value = *time_ptr / ( uint64_t )1000;
    time_data = localtime( &time_value );
    
    time_data->tm_year = value_get_int( int_year ) - 1900;
    time_data->tm_mon = value_get_int( int_month ) - 1;
    time_data->tm_mday = value_get_int( int_date );
    time_data->tm_hour = value_get_int( int_hourofday );
    time_data->tm_min = value_get_int( int_minute );
    time_data->tm_sec = value_get_int( int_second );
    
    time_value = mktime( time_data );
    *time_ptr = time_value * ( uint64_t )1000;
}

void native_method_util_calendar_setfirstdayofweek_int( void )
{
    // void setFirstDayOfWeek(int value)
    // Sets what the first day of the week is; e.g., SUNDAY in 
    // the U.S., MONDAY in France. 
    // Implementation code: 05F4E4CC
    object_t int_value;
    object_t object;

    int_value = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_util_calendar_setlenient_boolean( void )
{
    // void setLenient(boolean lenient)
    // Specifies whether or not date/time interpretation is to 
    // be lenient. 
    // Implementation code: E9C926A8
    object_t boolean_lenient;
    object_t object;

    boolean_lenient = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_util_calendar_setminimaldaysinfirstweek_int( void )
{
    // void setMinimalDaysInFirstWeek(int value)
    // Sets what the minimal days required in the first week of 
    // the year are; For example, if the first week is defined 
    // as one that contains the first day of the first month of 
    // a year, call this method with value 1. 
    // Implementation code: 47B8AC55
    object_t int_value;
    object_t object;

    int_value = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_util_calendar_settime_date( void )
{
    // void setTime(Date date)
    // Sets this Calendar's time with the given Date. 
    // Implementation code: 98D1D4C0
    object_t date_date;
    object_t object;

    date_date = stack_pop();
    object = stack_pop();

    // put your code here
    object_get_fields_ptr( object )[ NATIVE_FIELD_UTIL_CALENDAR_DATE_OBJ ] = date_date;
}

void native_method_util_calendar_settimeinmillis_long( void )
{
    // void setTimeInMillis(long millis)
    // Sets this Calendar's current time from the given long value. 
    // Implementation code: 0D5AC02D
    object_t long_millis;
    object_t object;
    object_t date_obj;
    int64_t * time_ptr;

    long_millis = stack_pop();
    object = stack_pop();

    // put your code here
    date_obj = object_get_fields_ptr( object )[ NATIVE_FIELD_UTIL_CALENDAR_DATE_OBJ ];
	time_ptr = ( ( int64_t * )object_get_ptr( object_get_fields_ptr( date_obj )[ NATIVE_FIELD_UTIL_DATE_TIME ] ) );
    *time_ptr = value_get_long( long_millis );
}

void native_method_util_calendar_settimezone_timezone( void )
{
    // void setTimeZone(TimeZone value)
    // Sets the time zone with the given time zone value. 
    // Implementation code: FA350485
    object_t timezone_value;
    object_t object;

    timezone_value = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_util_calendar_tostring( void )
{
    // String toString()
    // Return a string representation of this calendar. 
    // Implementation code: B7643048
    object_t object;
    object_t date_obj;
    int64_t * time_ptr;
    time_t time_value;
    char * time_str;
    
    object = stack_pop();

	// put your code here
    date_obj = object_get_fields_ptr( object )[ NATIVE_FIELD_UTIL_CALENDAR_DATE_OBJ ];
	time_ptr = ( ( int64_t * )object_get_ptr( object_get_fields_ptr( date_obj )[ NATIVE_FIELD_UTIL_DATE_TIME ] ) );
    time_value = *time_ptr / ( uint64_t )1000;
    time_str = ctime( ( const time_t *) &time_value );
	time_str[strlen(time_str)-1] = 0;

    // return type: String
    stack_push( strings_create( time_str ) );
}

///////////////////////////////////////////////////////////////////////////

void native_util_calendar_get_field(uint16_t mref)
{
    switch( mref )
    {
        case NATIVE_FIELD_UTIL_CALENDAR_ALL_STYLES:
            // static int ALL_STYLES
            // Implementation field read code: FIELD_READ_UTIL_CALENDAR_ALL_STYLES
            stack_push( value_create_int( NATIVE_FIELD_VALUE_UTIL_CALENDAR_ALL_STYLES ) );
            break;

        case NATIVE_FIELD_UTIL_CALENDAR_AM:
            // static int AM
            // Implementation field read code: FIELD_READ_UTIL_CALENDAR_AM
            stack_push( value_create_int( NATIVE_FIELD_VALUE_UTIL_CALENDAR_AM ) );
            break;

        case NATIVE_FIELD_UTIL_CALENDAR_AM_PM:
            // static int AM_PM
            // Implementation field read code: FIELD_READ_UTIL_CALENDAR_AM_PM
            stack_push( value_create_int( NATIVE_FIELD_VALUE_UTIL_CALENDAR_AM_PM ) );
            break;

        case NATIVE_FIELD_UTIL_CALENDAR_APRIL:
            // static int APRIL
            // Implementation field read code: FIELD_READ_UTIL_CALENDAR_APRIL
            stack_push( value_create_int( NATIVE_FIELD_VALUE_UTIL_CALENDAR_APRIL ) );
            break;

        case NATIVE_FIELD_UTIL_CALENDAR_AREFIELDSSET:
            // protected  boolean areFieldsSet
            // Implementation field read code: FIELD_READ_UTIL_CALENDAR_AREFIELDSSET
            stack_push( value_create_boolean( 0 ) );
            break;

        case NATIVE_FIELD_UTIL_CALENDAR_AUGUST:
            // static int AUGUST
            // Implementation field read code: FIELD_READ_UTIL_CALENDAR_AUGUST
            stack_push( value_create_int( NATIVE_FIELD_VALUE_UTIL_CALENDAR_AUGUST ) );
            break;

        case NATIVE_FIELD_UTIL_CALENDAR_DATE:
            // static int DATE
            // Implementation field read code: FIELD_READ_UTIL_CALENDAR_DATE
            stack_push( value_create_int( NATIVE_FIELD_VALUE_UTIL_CALENDAR_DATE ) );
            break;

        case NATIVE_FIELD_UTIL_CALENDAR_DAY_OF_MONTH:
            // static int DAY_OF_MONTH
            // Implementation field read code: FIELD_READ_UTIL_CALENDAR_DAY_OF_MONTH
            stack_push( value_create_int( NATIVE_FIELD_VALUE_UTIL_CALENDAR_DAY_OF_MONTH ) );
            break;

        case NATIVE_FIELD_UTIL_CALENDAR_DAY_OF_WEEK:
            // static int DAY_OF_WEEK
            // Implementation field read code: FIELD_READ_UTIL_CALENDAR_DAY_OF_WEEK
            stack_push( value_create_int( NATIVE_FIELD_VALUE_UTIL_CALENDAR_DAY_OF_WEEK ) );
            break;

        case NATIVE_FIELD_UTIL_CALENDAR_DAY_OF_WEEK_IN_MONTH:
            // static int DAY_OF_WEEK_IN_MONTH
            // Implementation field read code: FIELD_READ_UTIL_CALENDAR_DAY_OF_WEEK_IN_MONTH
            stack_push( value_create_int( NATIVE_FIELD_VALUE_UTIL_CALENDAR_DAY_OF_WEEK_IN_MONTH ) );
            break;

        case NATIVE_FIELD_UTIL_CALENDAR_DAY_OF_YEAR:
            // static int DAY_OF_YEAR
            // Implementation field read code: FIELD_READ_UTIL_CALENDAR_DAY_OF_YEAR
            stack_push( value_create_int( NATIVE_FIELD_VALUE_UTIL_CALENDAR_DAY_OF_YEAR ) );
            break;

        case NATIVE_FIELD_UTIL_CALENDAR_DECEMBER:
            // static int DECEMBER
            // Implementation field read code: FIELD_READ_UTIL_CALENDAR_DECEMBER
            stack_push( value_create_int( NATIVE_FIELD_VALUE_UTIL_CALENDAR_DECEMBER ) );
            break;

        case NATIVE_FIELD_UTIL_CALENDAR_DST_OFFSET:
            // static int DST_OFFSET
            // Implementation field read code: FIELD_READ_UTIL_CALENDAR_DST_OFFSET
            stack_push( value_create_int( NATIVE_FIELD_VALUE_UTIL_CALENDAR_DST_OFFSET ) );
            break;

        case NATIVE_FIELD_UTIL_CALENDAR_ERA:
            // static int ERA
            // Implementation field read code: FIELD_READ_UTIL_CALENDAR_ERA
            stack_push( value_create_int( NATIVE_FIELD_VALUE_UTIL_CALENDAR_ERA ) );
            break;

        case NATIVE_FIELD_UTIL_CALENDAR_FEBRUARY:
            // static int FEBRUARY
            // Implementation field read code: FIELD_READ_UTIL_CALENDAR_FEBRUARY
            stack_push( value_create_int( NATIVE_FIELD_VALUE_UTIL_CALENDAR_FEBRUARY ) );
            break;

        case NATIVE_FIELD_UTIL_CALENDAR_FIELD_COUNT:
            // static int FIELD_COUNT
            // Implementation field read code: FIELD_READ_UTIL_CALENDAR_FIELD_COUNT
            stack_push( value_create_int( NATIVE_FIELD_VALUE_UTIL_CALENDAR_FIELD_COUNT ) );
            break;

        case NATIVE_FIELD_UTIL_CALENDAR_FIELDS:
            // protected  int[] fields
            // Implementation field read code: FIELD_READ_UTIL_CALENDAR_FIELDS
            stack_push( 0 );
            break;

        case NATIVE_FIELD_UTIL_CALENDAR_FRIDAY:
            // static int FRIDAY
            // Implementation field read code: FIELD_READ_UTIL_CALENDAR_FRIDAY
            stack_push( value_create_int( NATIVE_FIELD_VALUE_UTIL_CALENDAR_FRIDAY ) );
            break;

        case NATIVE_FIELD_UTIL_CALENDAR_HOUR:
            // static int HOUR
            // Implementation field read code: FIELD_READ_UTIL_CALENDAR_HOUR
            stack_push( value_create_int( NATIVE_FIELD_VALUE_UTIL_CALENDAR_HOUR ) );
            break;

        case NATIVE_FIELD_UTIL_CALENDAR_HOUR_OF_DAY:
            // static int HOUR_OF_DAY
            // Implementation field read code: FIELD_READ_UTIL_CALENDAR_HOUR_OF_DAY
            stack_push( value_create_int( NATIVE_FIELD_VALUE_UTIL_CALENDAR_HOUR_OF_DAY ) );
            break;

        case NATIVE_FIELD_UTIL_CALENDAR_ISSET:
            // protected  boolean[] isSet
            // Implementation field read code: FIELD_READ_UTIL_CALENDAR_ISSET
            stack_push( 0 );
            break;

        case NATIVE_FIELD_UTIL_CALENDAR_ISTIMESET:
            // protected  boolean isTimeSet
            // Implementation field read code: FIELD_READ_UTIL_CALENDAR_ISTIMESET
            stack_push( value_create_boolean( 0 ) );
            break;

        case NATIVE_FIELD_UTIL_CALENDAR_JANUARY:
            // static int JANUARY
            // Implementation field read code: FIELD_READ_UTIL_CALENDAR_JANUARY
            stack_push( value_create_int( NATIVE_FIELD_VALUE_UTIL_CALENDAR_JANUARY ) );
            break;

        case NATIVE_FIELD_UTIL_CALENDAR_JULY:
            // static int JULY
            // Implementation field read code: FIELD_READ_UTIL_CALENDAR_JULY
            stack_push( value_create_int( NATIVE_FIELD_VALUE_UTIL_CALENDAR_JULY ) );
            break;

        case NATIVE_FIELD_UTIL_CALENDAR_JUNE:
            // static int JUNE
            // Implementation field read code: FIELD_READ_UTIL_CALENDAR_JUNE
            stack_push( value_create_int( NATIVE_FIELD_VALUE_UTIL_CALENDAR_JUNE ) );
            break;

        case NATIVE_FIELD_UTIL_CALENDAR_LONG:
            // static int LONG
            // Implementation field read code: FIELD_READ_UTIL_CALENDAR_LONG
            stack_push( value_create_int( NATIVE_FIELD_VALUE_UTIL_CALENDAR_LONG ) );
            break;

        case NATIVE_FIELD_UTIL_CALENDAR_MARCH:
            // static int MARCH
            // Implementation field read code: FIELD_READ_UTIL_CALENDAR_MARCH
            stack_push( value_create_int( NATIVE_FIELD_VALUE_UTIL_CALENDAR_MARCH ) );
            break;

        case NATIVE_FIELD_UTIL_CALENDAR_MAY:
            // static int MAY
            // Implementation field read code: FIELD_READ_UTIL_CALENDAR_MAY
            stack_push( value_create_int( NATIVE_FIELD_VALUE_UTIL_CALENDAR_MAY ) );
            break;

        case NATIVE_FIELD_UTIL_CALENDAR_MILLISECOND:
            // static int MILLISECOND
            // Implementation field read code: FIELD_READ_UTIL_CALENDAR_MILLISECOND
            stack_push( value_create_int( NATIVE_FIELD_VALUE_UTIL_CALENDAR_MILLISECOND ) );
            break;

        case NATIVE_FIELD_UTIL_CALENDAR_MINUTE:
            // static int MINUTE
            // Implementation field read code: FIELD_READ_UTIL_CALENDAR_MINUTE
            stack_push( value_create_int( NATIVE_FIELD_VALUE_UTIL_CALENDAR_MINUTE ) );
            break;

        case NATIVE_FIELD_UTIL_CALENDAR_MONDAY:
            // static int MONDAY
            // Implementation field read code: FIELD_READ_UTIL_CALENDAR_MONDAY
            stack_push( value_create_int( NATIVE_FIELD_VALUE_UTIL_CALENDAR_MONDAY ) );
            break;

        case NATIVE_FIELD_UTIL_CALENDAR_MONTH:
            // static int MONTH
            // Implementation field read code: FIELD_READ_UTIL_CALENDAR_MONTH
            stack_push( value_create_int( NATIVE_FIELD_VALUE_UTIL_CALENDAR_MONTH ) );
            break;

        case NATIVE_FIELD_UTIL_CALENDAR_NOVEMBER:
            // static int NOVEMBER
            // Implementation field read code: FIELD_READ_UTIL_CALENDAR_NOVEMBER
            stack_push( value_create_int( NATIVE_FIELD_VALUE_UTIL_CALENDAR_NOVEMBER ) );
            break;

        case NATIVE_FIELD_UTIL_CALENDAR_OCTOBER:
            // static int OCTOBER
            // Implementation field read code: FIELD_READ_UTIL_CALENDAR_OCTOBER
            stack_push( value_create_int( NATIVE_FIELD_VALUE_UTIL_CALENDAR_OCTOBER ) );
            break;

        case NATIVE_FIELD_UTIL_CALENDAR_PM:
            // static int PM
            // Implementation field read code: FIELD_READ_UTIL_CALENDAR_PM
            stack_push( value_create_int( NATIVE_FIELD_VALUE_UTIL_CALENDAR_PM ) );
            break;

        case NATIVE_FIELD_UTIL_CALENDAR_SATURDAY:
            // static int SATURDAY
            // Implementation field read code: FIELD_READ_UTIL_CALENDAR_SATURDAY
            stack_push( value_create_int( NATIVE_FIELD_VALUE_UTIL_CALENDAR_SATURDAY ) );
            break;

        case NATIVE_FIELD_UTIL_CALENDAR_SECOND:
            // static int SECOND
            // Implementation field read code: FIELD_READ_UTIL_CALENDAR_SECOND
            stack_push( value_create_int( NATIVE_FIELD_VALUE_UTIL_CALENDAR_SECOND ) );
            break;

        case NATIVE_FIELD_UTIL_CALENDAR_SEPTEMBER:
            // static int SEPTEMBER
            // Implementation field read code: FIELD_READ_UTIL_CALENDAR_SEPTEMBER
            stack_push( value_create_int( NATIVE_FIELD_VALUE_UTIL_CALENDAR_SEPTEMBER ) );
            break;

        case NATIVE_FIELD_UTIL_CALENDAR_SHORT:
            // static int SHORT
            // Implementation field read code: FIELD_READ_UTIL_CALENDAR_SHORT
            stack_push( value_create_int( NATIVE_FIELD_VALUE_UTIL_CALENDAR_SHORT ) );
            break;

        case NATIVE_FIELD_UTIL_CALENDAR_SUNDAY:
            // static int SUNDAY
            // Implementation field read code: FIELD_READ_UTIL_CALENDAR_SUNDAY
            stack_push( value_create_int( NATIVE_FIELD_VALUE_UTIL_CALENDAR_SUNDAY ) );
            break;

        case NATIVE_FIELD_UTIL_CALENDAR_THURSDAY:
            // static int THURSDAY
            // Implementation field read code: FIELD_READ_UTIL_CALENDAR_THURSDAY
            stack_push( value_create_int( NATIVE_FIELD_VALUE_UTIL_CALENDAR_THURSDAY ) );
            break;

        case NATIVE_FIELD_UTIL_CALENDAR_TIME:
            // protected  long time
            // Implementation field read code: FIELD_READ_UTIL_CALENDAR_TIME
            stack_push( value_create_long( 0 ) );
            break;

        case NATIVE_FIELD_UTIL_CALENDAR_TUESDAY:
            // static int TUESDAY
            // Implementation field read code: FIELD_READ_UTIL_CALENDAR_TUESDAY
            stack_push( value_create_int( NATIVE_FIELD_VALUE_UTIL_CALENDAR_TUESDAY ) );
            break;

        case NATIVE_FIELD_UTIL_CALENDAR_UNDECIMBER:
            // static int UNDECIMBER
            // Implementation field read code: FIELD_READ_UTIL_CALENDAR_UNDECIMBER
            stack_push( value_create_int( NATIVE_FIELD_VALUE_UTIL_CALENDAR_UNDECIMBER ) );
            break;

        case NATIVE_FIELD_UTIL_CALENDAR_WEDNESDAY:
            // static int WEDNESDAY
            // Implementation field read code: FIELD_READ_UTIL_CALENDAR_WEDNESDAY
            stack_push( value_create_int( NATIVE_FIELD_VALUE_UTIL_CALENDAR_WEDNESDAY ) );
            break;

        case NATIVE_FIELD_UTIL_CALENDAR_WEEK_OF_MONTH:
            // static int WEEK_OF_MONTH
            // Implementation field read code: FIELD_READ_UTIL_CALENDAR_WEEK_OF_MONTH
            stack_push( value_create_int( NATIVE_FIELD_VALUE_UTIL_CALENDAR_WEEK_OF_MONTH ) );
            break;

        case NATIVE_FIELD_UTIL_CALENDAR_WEEK_OF_YEAR:
            // static int WEEK_OF_YEAR
            // Implementation field read code: FIELD_READ_UTIL_CALENDAR_WEEK_OF_YEAR
            stack_push( value_create_int( NATIVE_FIELD_VALUE_UTIL_CALENDAR_WEEK_OF_YEAR ) );
            break;

        case NATIVE_FIELD_UTIL_CALENDAR_YEAR:
            // static int YEAR
            // Implementation field read code: FIELD_READ_UTIL_CALENDAR_YEAR
            stack_push( value_create_int( NATIVE_FIELD_VALUE_UTIL_CALENDAR_YEAR ) );
            break;

        case NATIVE_FIELD_UTIL_CALENDAR_ZONE_OFFSET:
            // static int ZONE_OFFSET
            // Implementation field read code: FIELD_READ_UTIL_CALENDAR_ZONE_OFFSET
            stack_push( value_create_int( NATIVE_FIELD_VALUE_UTIL_CALENDAR_ZONE_OFFSET ) );
            break;

        default: 
            exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
            break;
    }
}

void native_util_calendar_invoke(uint16_t mref)
{
    switch( mref )
    {
        case NATIVE_UTIL_CALENDAR_INIT:
            native_method_util_calendar_init();
            break;

        case NATIVE_UTIL_CALENDAR_INIT_TIMEZONE_LOCALE:
            native_method_util_calendar_init_timezone_locale();
            break;

        case NATIVE_UTIL_CALENDAR_ADD_INT_INT:
            native_method_util_calendar_add_int_int();
            break;

        case NATIVE_UTIL_CALENDAR_AFTER_OBJECT:
            native_method_util_calendar_after_object();
            break;

        case NATIVE_UTIL_CALENDAR_BEFORE_OBJECT:
            native_method_util_calendar_before_object();
            break;

        case NATIVE_UTIL_CALENDAR_CLEAR:
            native_method_util_calendar_clear();
            break;

        case NATIVE_UTIL_CALENDAR_CLEAR_INT:
            native_method_util_calendar_clear_int();
            break;

        case NATIVE_UTIL_CALENDAR_CLONE:
            native_method_util_calendar_clone();
            break;

        case NATIVE_UTIL_CALENDAR_COMPARETO_CALENDAR:
            native_method_util_calendar_compareto_calendar();
            break;

        case NATIVE_UTIL_CALENDAR_COMPLETE:
            native_method_util_calendar_complete();
            break;

        case NATIVE_UTIL_CALENDAR_COMPUTEFIELDS:
            native_method_util_calendar_computefields();
            break;

        case NATIVE_UTIL_CALENDAR_COMPUTETIME:
            native_method_util_calendar_computetime();
            break;

        case NATIVE_UTIL_CALENDAR_EQUALS_OBJECT:
            native_method_util_calendar_equals_object();
            break;

        case NATIVE_UTIL_CALENDAR_GET_INT:
            native_method_util_calendar_get_int();
            break;

        case NATIVE_UTIL_CALENDAR_GETACTUALMAXIMUM_INT:
            native_method_util_calendar_getactualmaximum_int();
            break;

        case NATIVE_UTIL_CALENDAR_GETACTUALMINIMUM_INT:
            native_method_util_calendar_getactualminimum_int();
            break;

        case NATIVE_UTIL_CALENDAR_GETAVAILABLELOCALES:
            native_method_util_calendar_getavailablelocales();
            break;

        case NATIVE_UTIL_CALENDAR_GETDISPLAYNAME_INT_INT_LOCALE:
            native_method_util_calendar_getdisplayname_int_int_locale();
            break;

        case NATIVE_UTIL_CALENDAR_GETFIRSTDAYOFWEEK:
            native_method_util_calendar_getfirstdayofweek();
            break;

        case NATIVE_UTIL_CALENDAR_GETGREATESTMINIMUM_INT:
            native_method_util_calendar_getgreatestminimum_int();
            break;

        case NATIVE_UTIL_CALENDAR_GETINSTANCE:
            native_method_util_calendar_getinstance();
            break;

        case NATIVE_UTIL_CALENDAR_GETINSTANCE_LOCALE:
            native_method_util_calendar_getinstance_locale();
            break;

        case NATIVE_UTIL_CALENDAR_GETINSTANCE_TIMEZONE:
            native_method_util_calendar_getinstance_timezone();
            break;

        case NATIVE_UTIL_CALENDAR_GETINSTANCE_TIMEZONE_LOCALE:
            native_method_util_calendar_getinstance_timezone_locale();
            break;

        case NATIVE_UTIL_CALENDAR_GETLEASTMAXIMUM_INT:
            native_method_util_calendar_getleastmaximum_int();
            break;

        case NATIVE_UTIL_CALENDAR_GETMAXIMUM_INT:
            native_method_util_calendar_getmaximum_int();
            break;

        case NATIVE_UTIL_CALENDAR_GETMINIMALDAYSINFIRSTWEEK:
            native_method_util_calendar_getminimaldaysinfirstweek();
            break;

        case NATIVE_UTIL_CALENDAR_GETMINIMUM_INT:
            native_method_util_calendar_getminimum_int();
            break;

        case NATIVE_UTIL_CALENDAR_GETTIME:
            native_method_util_calendar_gettime();
            break;

        case NATIVE_UTIL_CALENDAR_GETTIMEINMILLIS:
            native_method_util_calendar_gettimeinmillis();
            break;

        case NATIVE_UTIL_CALENDAR_GETTIMEZONE:
            native_method_util_calendar_gettimezone();
            break;

        case NATIVE_UTIL_CALENDAR_HASHCODE:
            native_method_util_calendar_hashcode();
            break;

        case NATIVE_UTIL_CALENDAR_INTERNALGET_INT:
            native_method_util_calendar_internalget_int();
            break;

        case NATIVE_UTIL_CALENDAR_ISLENIENT:
            native_method_util_calendar_islenient();
            break;

        case NATIVE_UTIL_CALENDAR_ISSET_INT:
            native_method_util_calendar_isset_int();
            break;

        case NATIVE_UTIL_CALENDAR_ROLL_INT_BOOLEAN:
            native_method_util_calendar_roll_int_boolean();
            break;

        case NATIVE_UTIL_CALENDAR_ROLL_INT_INT:
            native_method_util_calendar_roll_int_int();
            break;

        case NATIVE_UTIL_CALENDAR_SET_INT_INT:
            native_method_util_calendar_set_int_int();
            break;

        case NATIVE_UTIL_CALENDAR_SET_INT_INT_INT:
            native_method_util_calendar_set_int_int_int();
            break;

        case NATIVE_UTIL_CALENDAR_SET_INT_INT_INT_INT_INT:
            native_method_util_calendar_set_int_int_int_int_int();
            break;

        case NATIVE_UTIL_CALENDAR_SET_INT_INT_INT_INT_INT_INT:
            native_method_util_calendar_set_int_int_int_int_int_int();
            break;

        case NATIVE_UTIL_CALENDAR_SETFIRSTDAYOFWEEK_INT:
            native_method_util_calendar_setfirstdayofweek_int();
            break;

        case NATIVE_UTIL_CALENDAR_SETLENIENT_BOOLEAN:
            native_method_util_calendar_setlenient_boolean();
            break;

        case NATIVE_UTIL_CALENDAR_SETMINIMALDAYSINFIRSTWEEK_INT:
            native_method_util_calendar_setminimaldaysinfirstweek_int();
            break;

        case NATIVE_UTIL_CALENDAR_SETTIME_DATE:
            native_method_util_calendar_settime_date();
            break;

        case NATIVE_UTIL_CALENDAR_SETTIMEINMILLIS_LONG:
            native_method_util_calendar_settimeinmillis_long();
            break;

        case NATIVE_UTIL_CALENDAR_SETTIMEZONE_TIMEZONE:
            native_method_util_calendar_settimezone_timezone();
            break;

        case NATIVE_UTIL_CALENDAR_TOSTRING:
            native_method_util_calendar_tostring();
            break;

        default:
            exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
            break;

    }
}


