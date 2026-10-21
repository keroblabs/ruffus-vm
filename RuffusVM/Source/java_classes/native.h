#ifndef _NATIVE_H_
#define _NATIVE_H_

///////////////////////////////////////////////////////////////////////////

#include "types.h"
#include "datatypes.h"

#include "lang_object.h"
#include "lang_system.h"
#include "lang_class.h"
#include "lang_boolean.h"
#include "lang_byte.h"
#include "lang_character.h"
#include "lang_short.h"
#include "lang_integer.h"
#include "lang_long.h"
#include "lang_float.h"
#include "lang_double.h"
#include "lang_math.h"
#include "lang_string.h"
#include "lang_stringbuilder.h"
#include "lang_process.h"
#include "lang_number.h"
#include "lang_runtime.h"
#include "lang_thread.h"
#include "lang_reflect_field.h"
#include "lang_reflect_method.h"
#include "util_bitset.h"
#include "util_calendar.h"
#include "util_date.h"
#include "util_stringtokenizer.h"
#include "util_random.h"
#include "util_timer.h"
#include "util_timertask.h"
#include "util_timezone.h"
#include "util_vector.h"
#include "io_file.h"
#include "io_fileinputstream.h"
#include "io_fileoutputstream.h"
#include "io_inputstream.h"
#include "io_outputstream.h"
#include "io_printstream.h"
#include "io_randomaccessfile.h"

/*
#include "objects_Disposable.h"
#include "graphics_Drawing.h"
#include "graphics_Colour.h"
#include "system_InputPointer.h"
#include "system_EventArgs.h"
#include "widgets_Widget.h"
#include "widgets_menu.h"
*/

#include "lang_string_lib.h"
#include "lang_number_lib.h"

///////////////////////////////////////////////////////////////////////////

enum
{
    NATIVE_CLASS_LANG_OBJECT = NATIVE_CLASS_BASE,                // java/lang/Object
    NATIVE_CLASS_LANG_CLASS,                                     // java/lang/Class
    NATIVE_CLASS_LANG_SYSTEM,                                    // java/lang/System
    NATIVE_CLASS_LANG_BOOLEAN,                                   // java/lang/Boolean
    NATIVE_CLASS_LANG_BYTE,                                      // java/lang/Byte
    NATIVE_CLASS_LANG_CHARACTER,                                 // java/lang/Character
    NATIVE_CLASS_LANG_SHORT,                                     // java/lang/Short
    NATIVE_CLASS_LANG_INTEGER,                                   // java/lang/Integer
    NATIVE_CLASS_LANG_LONG,                                      // java/lang/Long
    NATIVE_CLASS_LANG_FLOAT,                                     // java/lang/Float
    NATIVE_CLASS_LANG_DOUBLE,                                    // java/lang/Double
    NATIVE_CLASS_LANG_MATH,                                      // java/lang/Math
    NATIVE_CLASS_LANG_STRING,                                    // java/lang/String
    NATIVE_CLASS_LANG_STRINGBUILDER,                             // java/lang/StringBuilder
    NATIVE_CLASS_LANG_PROCESS,                                   // java/lang/Process
    NATIVE_CLASS_LANG_NUMBER,                                    // java/lang/Number
    NATIVE_CLASS_LANG_RUNTIME,                                   // java/lang/Runtime
    NATIVE_CLASS_LANG_THREAD,                                    // java/lang/Thread
	NATIVE_CLASS_LANG_REFLECT_FIELD,							 // java/lang/reflect/Field
	NATIVE_CLASS_LANG_REFLECT_METHOD,							 // java/lang/reflect/Method
    NATIVE_CLASS_UTIL_BITSET,                                    // java/util/BitSet
    NATIVE_CLASS_UTIL_CALENDAR,                                  // java/util/Calendar
    NATIVE_CLASS_UTIL_DATE,                                      // java/util/Date
    NATIVE_CLASS_UTIL_STRINGTOKENIZER,                           // java/util/StringTokenizer
    NATIVE_CLASS_UTIL_RANDOM,                                    // java/util/Random
    NATIVE_CLASS_UTIL_TIMER,                                     // java/util/Timer
    NATIVE_CLASS_UTIL_TIMERTASK,                                 // java/util/TimerTask
    NATIVE_CLASS_UTIL_TIMEZONE,                                  // java/util/TimeZone
    NATIVE_CLASS_UTIL_VECTOR,                                    // java/util/Vector
    NATIVE_CLASS_IO_FILE,                                        // java/io/File
    NATIVE_CLASS_IO_FILEINPUTSTREAM,                             // java/io/FileInputStream
    NATIVE_CLASS_IO_FILEOUTPUTSTREAM,                            // java/io/FileOutputStream
    NATIVE_CLASS_IO_INPUTSTREAM,                                 // java/io/InputStream
    NATIVE_CLASS_IO_OUTPUTSTREAM,                                // java/io/OutputStream
    NATIVE_CLASS_IO_PRINTSTREAM,                                 // java/io/PrintStream
    NATIVE_CLASS_IO_RANDOMACCESSFILE,                            // java/io/RandomAccessFile
    
	/*
    NATIVE_CLASS_RUFFUS_OBJECTS_DISPOSABLE,                      // ruffus/objects/Disposable
    NATIVE_CLASS_RUFFUS_GRAPHICS_DRAWING,                        // ruffus/graphics/Drawing
    NATIVE_CLASS_RUFFUS_GRAPHICS_COLOUR,                         // ruffus/graphics/Colour
    NATIVE_CLASS_RUFFUS_SYSTEM_INPUTPOINTER,                     // ruffus/system/InputPointer
    NATIVE_CLASS_RUFFUS_SYSTEM_EVENTARGS,
    NATIVE_CLASS_RUFFUS_WIDGETS_WIDGET,
    NATIVE_CLASS_RUFFUS_WIDGETS_BUTTON,
    NATIVE_CLASS_RUFFUS_WIDGETS_TEXT_BOX,
    NATIVE_CLASS_RUFFUS_WIDGETS_TEXT_LABEL,
    NATIVE_CLASS_RUFFUS_WIDGETS_FORM,
	NATIVE_CLASS_RUFFUS_WIDGETS_MENU,
    */

    NATIVE_CLASS_THROW_LANG_INTERRUPTEDEXCEPTION,                // java/throw/lang/InterruptedException
    NATIVE_CLASS_THROW_LANG_NULLPOINTEREXECPTION,                // java/throw/lang/NullPointerException
    NATIVE_CLASS_THROW_LANG_NEGATIVEARRAYSIZEEXCEPTION,          // java/throw/lang/NegativeArraySizeException
    NATIVE_CLASS_THROW_LANG_ARITHMETICEXCEPTION,                 // java/throw/lang/ArithmeticException
    NATIVE_CLASS_THROW_LANG_ARRAYSTOREEXCEPTION,                 // java/throw/lang/ArrayStoreException
    NATIVE_CLASS_THROW_LANG_ILLEGALARGUMENTEXCEPTION,            // java/throw/lang/IllegalArgumentException
    NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION,               // java/throw/lang/NoSuchMethodException
    NATIVE_CLASS_THROW_LANG_NOSUCHFIELDEXCEPTION,                // java/throw/lang/NoSuchFieldException
    NATIVE_CLASS_THROW_LANG_INDEXOUTOFBOUNDSEXCEPTION,           // java/throw/lang/IndexOutOfBoundsException
    NATIVE_CLASS_THROW_LANG_ARRAYINDEXOUTOFBOUNDSEXCEPTION,      // java/throw/lang/ArrayIndexOutOfBoundsException
    NATIVE_CLASS_THROW_LANG_STRINGINDEXOUTOFBOUNDSEXCEPTION,     // java/throw/lang/StringIndexOutOfBoundsException
    NATIVE_CLASS_THROW_LANG_CLASSNOTFOUNDEXCEPTION,              // java/throw/lang/ClassNotFoundException
    NATIVE_CLASS_THROW_LANG_UNSUPPORTEDOPERATIONEXCEPTION,       // java/throw/lang/UnsupportedOperationException
    NATIVE_CLASS_THROW_UTIL_EMPTYSTACKEXCEPTION,                 // java/throw/util/EmptyStackException
    NATIVE_CLASS_THROW_UTIL_NOSUCHELEMENTEXCEPTION,              // java/throw/util/NoSuchElementException
    NATIVE_CLASS_THROW_IO_CHARCONVERSIONEXCEPTION,               // java/throw/io/CharConversionException
    NATIVE_CLASS_THROW_IO_EOFEXCEPTION,                          // java/throw/io/EOFException
    NATIVE_CLASS_THROW_IO_FILENOTFOUNDEXCEPTION,                 // java/throw/io/FileNotFoundException
    NATIVE_CLASS_THROW_IO_INTERRUPTEDIOEXCEPTION,                // java/throw/io/InterruptedIOException
    NATIVE_CLASS_THROW_IO_INVALIDCLASSEXCEPTION,                 // java/throw/io/InvalidClassException
    NATIVE_CLASS_THROW_IO_INVALIDOBJECTEXCEPTION,                // java/throw/io/InvalidObjectException
    NATIVE_CLASS_THROW_IO_IOEXCEPTION,                           // java/throw/io/IOException
    NATIVE_CLASS_THROW_IO_NOTACTIVEEXCEPTION,                    // java/throw/io/NotActiveException
    NATIVE_CLASS_THROW_IO_OBJECTSTREAMEXCEPTION,                 // java/throw/io/ObjectStreamException
    NATIVE_CLASS_THROW_IO_STREAMCORRUPTEDEXCEPTION,              // java/throw/io/StreamCorruptedException
    NATIVE_CLASS_THROW_IO_WRITEABORTEDEXCEPTION,                 // java/throw/io/WriteAbortedException
};

///////////////////////////////////////////////////////////////////////////

object_t native_new( uint32_t mref );
void native_get_field( uint32_t mref );
void native_invoke( uint32_t mref );
void native_init( uint32_t mref );
void native_call_finalize( uint32_t cref, object_t object );

uint32_t native_superclass( uint32_t mref );

void ruffus_native_init( void );

///////////////////////////////////////////////////////////////////////////

#endif // _NATIVE_H_


