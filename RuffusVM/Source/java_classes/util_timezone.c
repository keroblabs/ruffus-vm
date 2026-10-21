#include "util_timezone.h"
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

// static int LONG
#define NATIVE_FIELD_VALUE_UTIL_TIMEZONE_LONG                                    0

// static int SHORT
#define NATIVE_FIELD_VALUE_UTIL_TIMEZONE_SHORT                                   1

///////////////////////////////////////////////////////////////////////////

object_t native_util_timezone_new( void )
{
    return( object_create( GET_CLASS_REF( NATIVE_CLASS_UTIL_TIMEZONE ), T_CLASS, NATIVE_UTIL_TIMEZONE_TOTAL_FIELDS ) );
}

///////////////////////////////////////////////////////////////////////////

void native_method_util_timezone_init( void )
{
    // TimeZone()
    // Sole constructor. 
    // Implementation code: 5758B379
    object_t object;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

///////////////////////////////////////////////////////////////////////////

void native_method_util_timezone_clone( void )
{
    // Object clone()
    // Creates a copy of this TimeZone. 
    // Implementation code: 4666F78E
    object_t object;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: Object
    stack_push( 0 );
}

void native_method_util_timezone_getavailableids( void )
{
    // static String[] getAvailableIDs()
    // Gets all the available IDs supported. 
    // Implementation code: BE67B40D

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: String[]
    stack_push( 0 );
}

void native_method_util_timezone_getavailableids_int( void )
{
    // static String[] getAvailableIDs(int rawOffset)
    // Gets the available IDs according to the given time zone 
    // offset in milliseconds. 
    // Implementation code: DFF9C820
    object_t int_rawoffset;

    int_rawoffset = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: String[]
    stack_push( 0 );
}

void native_method_util_timezone_getdefault( void )
{
    // static TimeZone getDefault()
    // Gets the default TimeZone for this host. 
    // Implementation code: 5F9F43AD

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: TimeZone
    stack_push( 0 );
}

void native_method_util_timezone_getdisplayname( void )
{
    // String getDisplayName()
    // Returns a name of this time zone suitable for presentation 
    // to the user in the default locale. 
    // Implementation code: 9033D886
    object_t object;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: String
    stack_push( strings_create( "" ) );
}

void native_method_util_timezone_getdisplayname_boolean_int( void )
{
    // String getDisplayName(boolean daylight, int style)
    // Returns a name of this time zone suitable for presentation 
    // to the user in the default locale. 
    // Implementation code: 9033D886
    object_t object;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: String
    stack_push( strings_create( "" ) );
}

void native_method_util_timezone_getdisplayname_boolean_int_locale( void )
{
    // String getDisplayName(boolean daylight, int style, Locale locale)
    // Returns a name of this time zone suitable for presentation 
    // to the user in the specified locale. 
    // Implementation code: 30F218E2
    object_t boolean_daylight;
    object_t int_style;
    object_t locale_locale;
    object_t object;

    locale_locale = stack_pop();
    int_style = stack_pop();
    boolean_daylight = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: String
    stack_push( strings_create( "" ) );
}

void native_method_util_timezone_getdisplayname_locale( void )
{
    // String getDisplayName(Locale locale)
    // Returns a name of this time zone suitable for presentation 
    // to the user in the specified locale. 
    // Implementation code: 30F218E2
    object_t boolean_daylight;
    object_t int_style;
    object_t locale_locale;
    object_t object;

    locale_locale = stack_pop();
    int_style = stack_pop();
    boolean_daylight = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: String
    stack_push( strings_create( "" ) );
}

void native_method_util_timezone_getdstsavings( void )
{
    // int getDSTSavings()
    // Returns the amount of time to be added to local standard 
    // time to get local wall clock time. 
    // Implementation code: 0C2197A1
    object_t object;
    int32_t ret_value = 0;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push( value_create( &ret_value, T_INT ) );
}

void native_method_util_timezone_getid( void )
{
    // String getID()
    // Gets the ID of this time zone. 
    // Implementation code: 41EAA727
    object_t object;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: String
    stack_push( strings_create( "" ) );
}

void native_method_util_timezone_getoffset_int_int_int_int_int_int( void )
{
    // abstract  int getOffset(int era, int year, int month, int day, int dayOfWeek, int milliseconds)
    // Gets the time zone offset, for current date, modified in 
    // case of daylight savings. 
    // Implementation code: D28C5DE9
    object_t int_era;
    object_t int_year;
    object_t int_month;
    object_t int_day;
    object_t int_dayofweek;
    object_t int_milliseconds;
    object_t object;
    int32_t ret_value = 0;

    int_milliseconds = stack_pop();
    int_dayofweek = stack_pop();
    int_day = stack_pop();
    int_month = stack_pop();
    int_year = stack_pop();
    int_era = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push( value_create( &ret_value, T_INT ) );
}

void native_method_util_timezone_getoffset_long( void )
{
    // int getOffset(long date)
    // Returns the offset of this time zone from UTC at the specified 
    // date. 
    // Implementation code: 9B4B2DCC
    object_t long_date;
    object_t object;
    int32_t ret_value = 0;

    long_date = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push( value_create( &ret_value, T_INT ) );
}

void native_method_util_timezone_getrawoffset( void )
{
    // abstract  int getRawOffset()
    // Returns the amount of time in milliseconds to add to UTC 
    // to get standard time in this time zone. 
    // Implementation code: 3FE7E9DB
    object_t object;
    int32_t ret_value = 0;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push( value_create( &ret_value, T_INT ) );
}

void native_method_util_timezone_gettimezone_string( void )
{
    // static TimeZone getTimeZone(String ID)
    // Gets the TimeZone for the given ID. 
    // Implementation code: 01F11850
    object_t string_id;

    string_id = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: TimeZone
    stack_push( 0 );
}

void native_method_util_timezone_hassamerules_timezone( void )
{
    // boolean hasSameRules(TimeZone other)
    // Returns true if this zone has the same rule and offset as 
    // another zone. 
    // Implementation code: F72E8D60
    object_t timezone_other;
    object_t object;
    bool_t ret_value = 0;

    timezone_other = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: boolean
    stack_push( value_create( &ret_value, T_BOOLEAN ) );
}

void native_method_util_timezone_indaylighttime_date( void )
{
    // abstract  boolean inDaylightTime(Date date)
    // Queries if the given date is in daylight savings time in 
    // this time zone. 
    // Implementation code: 6F96ACB3
    object_t date_date;
    object_t object;
    bool_t ret_value = 0;

    date_date = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: boolean
    stack_push( value_create( &ret_value, T_BOOLEAN ) );
}

void native_method_util_timezone_setdefault_timezone( void )
{
    // static void setDefault(TimeZone zone)
    // Sets the TimeZone that is returned by the getDefault method. 
    // Implementation code: 731C7797
    object_t timezone_zone;

    timezone_zone = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_util_timezone_setid_string( void )
{
    // void setID(String ID)
    // Sets the time zone ID. 
    // Implementation code: 167CD142
    object_t string_id;
    object_t object;

    string_id = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_util_timezone_setrawoffset_int( void )
{
    // abstract  void setRawOffset(int offsetMillis)
    // Sets the base time zone offset to GMT. 
    // Implementation code: 7068147E
    object_t int_offsetmillis;
    object_t object;

    int_offsetmillis = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_util_timezone_usedaylighttime( void )
{
    // abstract  boolean useDaylightTime()
    // Queries if this time zone uses daylight savings time. 
    // Implementation code: 6EE5DDFD
    object_t object;
    bool_t ret_value = 0;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: boolean
    stack_push( value_create( &ret_value, T_BOOLEAN ) );
}

///////////////////////////////////////////////////////////////////////////

void native_util_timezone_get_field(uint16_t mref)
{
    switch( mref )
    {
        case NATIVE_FIELD_UTIL_TIMEZONE_LONG:
            // static int LONG
            // Implementation field read code: FIELD_READ_UTIL_TIMEZONE_LONG
            stack_push( value_create_int( NATIVE_FIELD_VALUE_UTIL_TIMEZONE_LONG ) );
            break;

        case NATIVE_FIELD_UTIL_TIMEZONE_SHORT:
            // static int SHORT
            // Implementation field read code: FIELD_READ_UTIL_TIMEZONE_SHORT
            stack_push( value_create_int( NATIVE_FIELD_VALUE_UTIL_TIMEZONE_SHORT ) );
            break;

        default: 
            exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
            break;
    }
}

void native_util_timezone_invoke(uint16_t mref)
{
    switch( mref )
    {
        case NATIVE_UTIL_TIMEZONE_INIT:
            native_method_util_timezone_init();
            break;

        case NATIVE_UTIL_TIMEZONE_CLONE:
            native_method_util_timezone_clone();
            break;

        case NATIVE_UTIL_TIMEZONE_GETAVAILABLEIDS:
            native_method_util_timezone_getavailableids();
            break;

        case NATIVE_UTIL_TIMEZONE_GETAVAILABLEIDS_INT:
            native_method_util_timezone_getavailableids_int();
            break;

        case NATIVE_UTIL_TIMEZONE_GETDEFAULT:
            native_method_util_timezone_getdefault();
            break;

        case NATIVE_UTIL_TIMEZONE_GETDISPLAYNAME:
            native_method_util_timezone_getdisplayname();
            break;

        case NATIVE_UTIL_TIMEZONE_GETDISPLAYNAME_BOOLEAN_INT:
            native_method_util_timezone_getdisplayname_boolean_int();
            break;

        case NATIVE_UTIL_TIMEZONE_GETDISPLAYNAME_BOOLEAN_INT_LOCALE:
            native_method_util_timezone_getdisplayname_boolean_int_locale();
            break;

        case NATIVE_UTIL_TIMEZONE_GETDISPLAYNAME_LOCALE:
            native_method_util_timezone_getdisplayname_locale();
            break;

        case NATIVE_UTIL_TIMEZONE_GETDSTSAVINGS:
            native_method_util_timezone_getdstsavings();
            break;

        case NATIVE_UTIL_TIMEZONE_GETID:
            native_method_util_timezone_getid();
            break;

        case NATIVE_UTIL_TIMEZONE_GETOFFSET_INT_INT_INT_INT_INT_INT:
            native_method_util_timezone_getoffset_int_int_int_int_int_int();
            break;

        case NATIVE_UTIL_TIMEZONE_GETOFFSET_LONG:
            native_method_util_timezone_getoffset_long();
            break;

        case NATIVE_UTIL_TIMEZONE_GETRAWOFFSET:
            native_method_util_timezone_getrawoffset();
            break;

        case NATIVE_UTIL_TIMEZONE_GETTIMEZONE_STRING:
            native_method_util_timezone_gettimezone_string();
            break;

        case NATIVE_UTIL_TIMEZONE_HASSAMERULES_TIMEZONE:
            native_method_util_timezone_hassamerules_timezone();
            break;

        case NATIVE_UTIL_TIMEZONE_INDAYLIGHTTIME_DATE:
            native_method_util_timezone_indaylighttime_date();
            break;

        case NATIVE_UTIL_TIMEZONE_SETDEFAULT_TIMEZONE:
            native_method_util_timezone_setdefault_timezone();
            break;

        case NATIVE_UTIL_TIMEZONE_SETID_STRING:
            native_method_util_timezone_setid_string();
            break;

        case NATIVE_UTIL_TIMEZONE_SETRAWOFFSET_INT:
            native_method_util_timezone_setrawoffset_int();
            break;

        case NATIVE_UTIL_TIMEZONE_USEDAYLIGHTTIME:
            native_method_util_timezone_usedaylighttime();
            break;

        default:
            exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
            break;

    }
}


