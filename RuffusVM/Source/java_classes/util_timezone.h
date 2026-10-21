#ifndef NATIVE_UTIL_TIMEZONE_H
#define NATIVE_UTIL_TIMEZONE_H

#ifdef	__cplusplus
extern "C" {
#endif

///////////////////////////////////////////////////////////////////////////

#include "datatypes.h"

///////////////////////////////////////////////////////////////////////////

// Class field implementation: UTIL_TIMEZONE_ENUM
enum
{
    NATIVE_FIELD_UTIL_TIMEZONE_DUMMY,
    NATIVE_UTIL_TIMEZONE_TOTAL_FIELDS
};

enum
{
    NATIVE_FIELD_UTIL_TIMEZONE_LONG,                                             // static int LONG
    NATIVE_FIELD_UTIL_TIMEZONE_SHORT,                                            // static int SHORT
};

enum
{
    NATIVE_UTIL_TIMEZONE_INIT,                                                   // TimeZone()

    NATIVE_UTIL_TIMEZONE_CLONE,                                                  // Object clone()
    NATIVE_UTIL_TIMEZONE_GETAVAILABLEIDS,                                        // static String[] getAvailableIDs()
    NATIVE_UTIL_TIMEZONE_GETAVAILABLEIDS_INT,                                    // static String[] getAvailableIDs(int rawOffset)
    NATIVE_UTIL_TIMEZONE_GETDEFAULT,                                             // static TimeZone getDefault()
    NATIVE_UTIL_TIMEZONE_GETDISPLAYNAME,                                         // String getDisplayName()
    NATIVE_UTIL_TIMEZONE_GETDISPLAYNAME_BOOLEAN_INT,                             // String getDisplayName(boolean daylight, int style)
    NATIVE_UTIL_TIMEZONE_GETDISPLAYNAME_BOOLEAN_INT_LOCALE,                      // String getDisplayName(boolean daylight, int style, Locale locale)
    NATIVE_UTIL_TIMEZONE_GETDISPLAYNAME_LOCALE,                                  // String getDisplayName(Locale locale)
    NATIVE_UTIL_TIMEZONE_GETDSTSAVINGS,                                          // int getDSTSavings()
    NATIVE_UTIL_TIMEZONE_GETID,                                                  // String getID()
    NATIVE_UTIL_TIMEZONE_GETOFFSET_INT_INT_INT_INT_INT_INT,                      // abstract  int getOffset(int era, int year, int month, int day, int dayOfWeek, int milliseconds)
    NATIVE_UTIL_TIMEZONE_GETOFFSET_LONG,                                         // int getOffset(long date)
    NATIVE_UTIL_TIMEZONE_GETRAWOFFSET,                                           // abstract  int getRawOffset()
    NATIVE_UTIL_TIMEZONE_GETTIMEZONE_STRING,                                     // static TimeZone getTimeZone(String ID)
    NATIVE_UTIL_TIMEZONE_HASSAMERULES_TIMEZONE,                                  // boolean hasSameRules(TimeZone other)
    NATIVE_UTIL_TIMEZONE_INDAYLIGHTTIME_DATE,                                    // abstract  boolean inDaylightTime(Date date)
    NATIVE_UTIL_TIMEZONE_SETDEFAULT_TIMEZONE,                                    // static void setDefault(TimeZone zone)
    NATIVE_UTIL_TIMEZONE_SETID_STRING,                                           // void setID(String ID)
    NATIVE_UTIL_TIMEZONE_SETRAWOFFSET_INT,                                       // abstract  void setRawOffset(int offsetMillis)
    NATIVE_UTIL_TIMEZONE_USEDAYLIGHTTIME,                                        // abstract  boolean useDaylightTime()
};

///////////////////////////////////////////////////////////////////////////

object_t native_util_timezone_new( void );
void native_util_timezone_get_field(uint16_t mref);
void native_util_timezone_invoke(uint16_t mref);

///////////////////////////////////////////////////////////////////////////

#ifdef	__cplusplus
}
#endif

#endif // NATIVE_UTIL_TIMEZONE_H


