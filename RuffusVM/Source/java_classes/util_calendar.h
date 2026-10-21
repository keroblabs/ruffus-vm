#ifndef NATIVE_UTIL_CALENDAR_H
#define NATIVE_UTIL_CALENDAR_H

#ifdef	__cplusplus
extern "C" {
#endif

///////////////////////////////////////////////////////////////////////////

#include "datatypes.h"

///////////////////////////////////////////////////////////////////////////

// Class field implementation: UTIL_CALENDAR_ENUM
enum
{
    NATIVE_FIELD_UTIL_CALENDAR_DATE_OBJ,
    NATIVE_UTIL_CALENDAR_TOTAL_FIELDS
};

enum
{
    NATIVE_FIELD_UTIL_CALENDAR_ALL_STYLES,                                       // static int ALL_STYLES
    NATIVE_FIELD_UTIL_CALENDAR_AM,                                               // static int AM
    NATIVE_FIELD_UTIL_CALENDAR_AM_PM,                                            // static int AM_PM
    NATIVE_FIELD_UTIL_CALENDAR_APRIL,                                            // static int APRIL
    NATIVE_FIELD_UTIL_CALENDAR_AREFIELDSSET,                                     // protected  boolean areFieldsSet
    NATIVE_FIELD_UTIL_CALENDAR_AUGUST,                                           // static int AUGUST
    NATIVE_FIELD_UTIL_CALENDAR_DATE,                                             // static int DATE
    NATIVE_FIELD_UTIL_CALENDAR_DAY_OF_MONTH,                                     // static int DAY_OF_MONTH
    NATIVE_FIELD_UTIL_CALENDAR_DAY_OF_WEEK,                                      // static int DAY_OF_WEEK
    NATIVE_FIELD_UTIL_CALENDAR_DAY_OF_WEEK_IN_MONTH,                             // static int DAY_OF_WEEK_IN_MONTH
    NATIVE_FIELD_UTIL_CALENDAR_DAY_OF_YEAR,                                      // static int DAY_OF_YEAR
    NATIVE_FIELD_UTIL_CALENDAR_DECEMBER,                                         // static int DECEMBER
    NATIVE_FIELD_UTIL_CALENDAR_DST_OFFSET,                                       // static int DST_OFFSET
    NATIVE_FIELD_UTIL_CALENDAR_ERA,                                              // static int ERA
    NATIVE_FIELD_UTIL_CALENDAR_FEBRUARY,                                         // static int FEBRUARY
    NATIVE_FIELD_UTIL_CALENDAR_FIELD_COUNT,                                      // static int FIELD_COUNT
    NATIVE_FIELD_UTIL_CALENDAR_FIELDS,                                           // protected  int[] fields
    NATIVE_FIELD_UTIL_CALENDAR_FRIDAY,                                           // static int FRIDAY
    NATIVE_FIELD_UTIL_CALENDAR_HOUR,                                             // static int HOUR
    NATIVE_FIELD_UTIL_CALENDAR_HOUR_OF_DAY,                                      // static int HOUR_OF_DAY
    NATIVE_FIELD_UTIL_CALENDAR_ISSET,                                            // protected  boolean[] isSet
    NATIVE_FIELD_UTIL_CALENDAR_ISTIMESET,                                        // protected  boolean isTimeSet
    NATIVE_FIELD_UTIL_CALENDAR_JANUARY,                                          // static int JANUARY
    NATIVE_FIELD_UTIL_CALENDAR_JULY,                                             // static int JULY
    NATIVE_FIELD_UTIL_CALENDAR_JUNE,                                             // static int JUNE
    NATIVE_FIELD_UTIL_CALENDAR_LONG,                                             // static int LONG
    NATIVE_FIELD_UTIL_CALENDAR_MARCH,                                            // static int MARCH
    NATIVE_FIELD_UTIL_CALENDAR_MAY,                                              // static int MAY
    NATIVE_FIELD_UTIL_CALENDAR_MILLISECOND,                                      // static int MILLISECOND
    NATIVE_FIELD_UTIL_CALENDAR_MINUTE,                                           // static int MINUTE
    NATIVE_FIELD_UTIL_CALENDAR_MONDAY,                                           // static int MONDAY
    NATIVE_FIELD_UTIL_CALENDAR_MONTH,                                            // static int MONTH
    NATIVE_FIELD_UTIL_CALENDAR_NOVEMBER,                                         // static int NOVEMBER
    NATIVE_FIELD_UTIL_CALENDAR_OCTOBER,                                          // static int OCTOBER
    NATIVE_FIELD_UTIL_CALENDAR_PM,                                               // static int PM
    NATIVE_FIELD_UTIL_CALENDAR_SATURDAY,                                         // static int SATURDAY
    NATIVE_FIELD_UTIL_CALENDAR_SECOND,                                           // static int SECOND
    NATIVE_FIELD_UTIL_CALENDAR_SEPTEMBER,                                        // static int SEPTEMBER
    NATIVE_FIELD_UTIL_CALENDAR_SHORT,                                            // static int SHORT
    NATIVE_FIELD_UTIL_CALENDAR_SUNDAY,                                           // static int SUNDAY
    NATIVE_FIELD_UTIL_CALENDAR_THURSDAY,                                         // static int THURSDAY
    NATIVE_FIELD_UTIL_CALENDAR_TIME,                                             // protected  long time
    NATIVE_FIELD_UTIL_CALENDAR_TUESDAY,                                          // static int TUESDAY
    NATIVE_FIELD_UTIL_CALENDAR_UNDECIMBER,                                       // static int UNDECIMBER
    NATIVE_FIELD_UTIL_CALENDAR_WEDNESDAY,                                        // static int WEDNESDAY
    NATIVE_FIELD_UTIL_CALENDAR_WEEK_OF_MONTH,                                    // static int WEEK_OF_MONTH
    NATIVE_FIELD_UTIL_CALENDAR_WEEK_OF_YEAR,                                     // static int WEEK_OF_YEAR
    NATIVE_FIELD_UTIL_CALENDAR_YEAR,                                             // static int YEAR
    NATIVE_FIELD_UTIL_CALENDAR_ZONE_OFFSET,                                      // static int ZONE_OFFSET
};

enum
{
    NATIVE_UTIL_CALENDAR_INIT,                                                   // protected Calendar()
    NATIVE_UTIL_CALENDAR_INIT_TIMEZONE_LOCALE,                                   // protected Calendar(TimeZone zone, Locale aLocale)

    NATIVE_UTIL_CALENDAR_ADD_INT_INT,                                            // abstract  void add(int field, int amount)
    NATIVE_UTIL_CALENDAR_AFTER_OBJECT,                                           // boolean after(Object when)
    NATIVE_UTIL_CALENDAR_BEFORE_OBJECT,                                          // boolean before(Object when)
    NATIVE_UTIL_CALENDAR_CLEAR,                                                  // void clear()
    NATIVE_UTIL_CALENDAR_CLEAR_INT,                                              // void clear(int field)
    NATIVE_UTIL_CALENDAR_CLONE,                                                  // Object clone()
    NATIVE_UTIL_CALENDAR_COMPARETO_CALENDAR,                                     // int compareTo(Calendar anotherCalendar)
    NATIVE_UTIL_CALENDAR_COMPLETE,                                               // protected  void complete()
    NATIVE_UTIL_CALENDAR_COMPUTEFIELDS,                                          // protected abstract  void computeFields()
    NATIVE_UTIL_CALENDAR_COMPUTETIME,                                            // protected abstract  void computeTime()
    NATIVE_UTIL_CALENDAR_EQUALS_OBJECT,                                          // boolean equals(Object obj)
    NATIVE_UTIL_CALENDAR_GET_INT,                                                // int get(int field)
    NATIVE_UTIL_CALENDAR_GETACTUALMAXIMUM_INT,                                   // int getActualMaximum(int field)
    NATIVE_UTIL_CALENDAR_GETACTUALMINIMUM_INT,                                   // int getActualMinimum(int field)
    NATIVE_UTIL_CALENDAR_GETAVAILABLELOCALES,                                    // static Locale[] getAvailableLocales()
    NATIVE_UTIL_CALENDAR_GETDISPLAYNAME_INT_INT_LOCALE,                          // String getDisplayName(int field, int style, Locale locale)
    NATIVE_UTIL_CALENDAR_GETFIRSTDAYOFWEEK,                                      // int getFirstDayOfWeek()
    NATIVE_UTIL_CALENDAR_GETGREATESTMINIMUM_INT,                                 // abstract  int getGreatestMinimum(int field)
    NATIVE_UTIL_CALENDAR_GETINSTANCE,                                            // static Calendar getInstance()
    NATIVE_UTIL_CALENDAR_GETINSTANCE_LOCALE,                                     // static Calendar getInstance(Locale aLocale)
    NATIVE_UTIL_CALENDAR_GETINSTANCE_TIMEZONE,                                   // static Calendar getInstance(TimeZone zone)
    NATIVE_UTIL_CALENDAR_GETINSTANCE_TIMEZONE_LOCALE,                            // static Calendar getInstance(TimeZone zone, Locale aLocale)
    NATIVE_UTIL_CALENDAR_GETLEASTMAXIMUM_INT,                                    // abstract  int getLeastMaximum(int field)
    NATIVE_UTIL_CALENDAR_GETMAXIMUM_INT,                                         // abstract  int getMaximum(int field)
    NATIVE_UTIL_CALENDAR_GETMINIMALDAYSINFIRSTWEEK,                              // int getMinimalDaysInFirstWeek()
    NATIVE_UTIL_CALENDAR_GETMINIMUM_INT,                                         // abstract  int getMinimum(int field)
    NATIVE_UTIL_CALENDAR_GETTIME,                                                // Date getTime()
    NATIVE_UTIL_CALENDAR_GETTIMEINMILLIS,                                        // long getTimeInMillis()
    NATIVE_UTIL_CALENDAR_GETTIMEZONE,                                            // TimeZone getTimeZone()
    NATIVE_UTIL_CALENDAR_HASHCODE,                                               // int hashCode()
    NATIVE_UTIL_CALENDAR_INTERNALGET_INT,                                        // protected  int internalGet(int field)
    NATIVE_UTIL_CALENDAR_ISLENIENT,                                              // boolean isLenient()
    NATIVE_UTIL_CALENDAR_ISSET_INT,                                              // boolean isSet(int field)
    NATIVE_UTIL_CALENDAR_ROLL_INT_BOOLEAN,                                       // abstract  void roll(int field, boolean up)
    NATIVE_UTIL_CALENDAR_ROLL_INT_INT,                                           // void roll(int field, int amount)
    NATIVE_UTIL_CALENDAR_SET_INT_INT,                                            // void set(int field, int value)
    NATIVE_UTIL_CALENDAR_SET_INT_INT_INT,                                        // void set(int year, int month, int date)
    NATIVE_UTIL_CALENDAR_SET_INT_INT_INT_INT_INT,                                // void set(int year, int month, int date, int hourOfDay, int minute)
    NATIVE_UTIL_CALENDAR_SET_INT_INT_INT_INT_INT_INT,                            // void set(int year, int month, int date, int hourOfDay, int minute, int second)
    NATIVE_UTIL_CALENDAR_SETFIRSTDAYOFWEEK_INT,                                  // void setFirstDayOfWeek(int value)
    NATIVE_UTIL_CALENDAR_SETLENIENT_BOOLEAN,                                     // void setLenient(boolean lenient)
    NATIVE_UTIL_CALENDAR_SETMINIMALDAYSINFIRSTWEEK_INT,                          // void setMinimalDaysInFirstWeek(int value)
    NATIVE_UTIL_CALENDAR_SETTIME_DATE,                                           // void setTime(Date date)
    NATIVE_UTIL_CALENDAR_SETTIMEINMILLIS_LONG,                                   // void setTimeInMillis(long millis)
    NATIVE_UTIL_CALENDAR_SETTIMEZONE_TIMEZONE,                                   // void setTimeZone(TimeZone value)
    NATIVE_UTIL_CALENDAR_TOSTRING,                                               // String toString()
};

///////////////////////////////////////////////////////////////////////////

object_t native_util_calendar_new( void );
void native_util_calendar_get_field(uint16_t mref);
void native_util_calendar_invoke(uint16_t mref);

///////////////////////////////////////////////////////////////////////////

#ifdef	__cplusplus
}
#endif

#endif // NATIVE_UTIL_CALENDAR_H


