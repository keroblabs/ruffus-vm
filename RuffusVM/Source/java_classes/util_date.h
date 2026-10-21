#ifndef NATIVE_UTIL_DATE_H
#define NATIVE_UTIL_DATE_H

#ifdef	__cplusplus
extern "C" {
#endif

///////////////////////////////////////////////////////////////////////////

#include "datatypes.h"

///////////////////////////////////////////////////////////////////////////

// Class field implementation: UTIL_DATE_ENUM
enum
{
    NATIVE_FIELD_UTIL_DATE_TIME,
    NATIVE_UTIL_DATE_TOTAL_FIELDS
};

enum
{

    NATIVE_UTIL_DATE_INIT,                                                       // Date()
    NATIVE_UTIL_DATE_INIT_INT_INT_INT,                                           // Date(int year, int month, int date)
    NATIVE_UTIL_DATE_INIT_INT_INT_INT_INT_INT,                                   // Date(int year, int month, int date, int hrs, int min)
    NATIVE_UTIL_DATE_INIT_INT_INT_INT_INT_INT_INT,                               // Date(int year, int month, int date, int hrs, int min, int sec)
    NATIVE_UTIL_DATE_INIT_LONG,                                                  // Date(long date)
    NATIVE_UTIL_DATE_INIT_STRING,                                                // Date(String s)

    NATIVE_UTIL_DATE_AFTER_DATE,                                                 // boolean after(Date when)
    NATIVE_UTIL_DATE_BEFORE_DATE,                                                // boolean before(Date when)
    NATIVE_UTIL_DATE_CLONE,                                                      // Object clone()
    NATIVE_UTIL_DATE_COMPARETO_DATE,                                             // int compareTo(Date anotherDate)
    NATIVE_UTIL_DATE_EQUALS_OBJECT,                                              // boolean equals(Object obj)
    NATIVE_UTIL_DATE_GETDATE,                                                    // int getDate()
    NATIVE_UTIL_DATE_GETDAY,                                                     // int getDay()
    NATIVE_UTIL_DATE_GETHOURS,                                                   // int getHours()
    NATIVE_UTIL_DATE_GETMINUTES,                                                 // int getMinutes()
    NATIVE_UTIL_DATE_GETMONTH,                                                   // int getMonth()
    NATIVE_UTIL_DATE_GETSECONDS,                                                 // int getSeconds()
    NATIVE_UTIL_DATE_GETTIME,                                                    // long getTime()
    NATIVE_UTIL_DATE_GETTIMEZONEOFFSET,                                          // int getTimezoneOffset()
    NATIVE_UTIL_DATE_GETYEAR,                                                    // int getYear()
    NATIVE_UTIL_DATE_HASHCODE,                                                   // int hashCode()
    NATIVE_UTIL_DATE_PARSE_STRING,                                               // static long parse(String s)
    NATIVE_UTIL_DATE_SETDATE_INT,                                                // void setDate(int date)
    NATIVE_UTIL_DATE_SETHOURS_INT,                                               // void setHours(int hours)
    NATIVE_UTIL_DATE_SETMINUTES_INT,                                             // void setMinutes(int minutes)
    NATIVE_UTIL_DATE_SETMONTH_INT,                                               // void setMonth(int month)
    NATIVE_UTIL_DATE_SETSECONDS_INT,                                             // void setSeconds(int seconds)
    NATIVE_UTIL_DATE_SETTIME_LONG,                                               // void setTime(long time)
    NATIVE_UTIL_DATE_SETYEAR_INT,                                                // void setYear(int year)
    NATIVE_UTIL_DATE_TOGMTSTRING,                                                // String toGMTString()
    NATIVE_UTIL_DATE_TOLOCALESTRING,                                             // String toLocaleString()
    NATIVE_UTIL_DATE_TOSTRING,                                                   // String toString()
    NATIVE_UTIL_DATE_UTC_INT_INT_INT_INT_INT_INT,                                // static long UTC(int year, int month, int date, int hrs, int min, int sec)
};

///////////////////////////////////////////////////////////////////////////

object_t native_util_date_new( void );
void native_util_date_get_field(uint16_t mref);
void native_util_date_invoke(uint16_t mref);

///////////////////////////////////////////////////////////////////////////

#ifdef	__cplusplus
}
#endif

#endif // NATIVE_UTIL_DATE_H


