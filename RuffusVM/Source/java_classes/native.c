#include "native.h"
#include "strings.h"
#include "vm.h"
#include "stack.h"
#include "application.h"
#include "exceptions.h"

///////////////////////////////////////////////////////////////////////////

object_t native_new( uint32_t mref )
{
    switch( GET_CLASS_INDEX( mref ) )
    {
        case NATIVE_CLASS_LANG_OBJECT:              // java/lang/Object
            return native_lang_object_new();

        case NATIVE_CLASS_LANG_SYSTEM:              // java/lang/System
            return native_lang_system_new();

        case NATIVE_CLASS_LANG_BOOLEAN:             // java/lang/Boolean
            return native_lang_boolean_new();

        case NATIVE_CLASS_LANG_BYTE:                // java/lang/Byte
            return native_lang_byte_new();

        case NATIVE_CLASS_LANG_CHARACTER:           // java/lang/Character
            return native_lang_character_new();

        case NATIVE_CLASS_LANG_SHORT:               // java/lang/Short
            return native_lang_short_new();

        case NATIVE_CLASS_LANG_INTEGER:             // java/lang/Integer
            return native_lang_integer_new();

        case NATIVE_CLASS_LANG_LONG:                // java/lang/Long
            return native_lang_long_new();

        case NATIVE_CLASS_LANG_FLOAT:               // java/lang/Float
            return native_lang_float_new();

        case NATIVE_CLASS_LANG_DOUBLE:              // java/lang/Double
            return native_lang_double_new();

        case NATIVE_CLASS_LANG_MATH:                // java/lang/Math
            return native_lang_math_new();

        case NATIVE_CLASS_LANG_STRING:              // java/lang/String
            return native_lang_string_new();

        case NATIVE_CLASS_LANG_STRINGBUILDER:       // java/lang/StringBuilder
            return native_lang_stringbuilder_new();

        case NATIVE_CLASS_LANG_PROCESS:             // java/lang/Process
            return native_lang_process_new();

        case NATIVE_CLASS_LANG_NUMBER:              // java/lang/Number
            return native_lang_number_new();

        case NATIVE_CLASS_LANG_RUNTIME:             // java/lang/Runtime
            return native_lang_runtime_new();

        case NATIVE_CLASS_LANG_THREAD:              // java/lang/Thread
            return native_lang_thread_new();

		case NATIVE_CLASS_LANG_REFLECT_FIELD:		// java/lang/reflect/Field
			return native_lang_reflect_field_new();

		case NATIVE_CLASS_LANG_REFLECT_METHOD:		// java/lang/reflect/Method
			return native_lang_reflect_method_new();

        case NATIVE_CLASS_UTIL_BITSET:              // java/util/BitSet
            return native_util_bitset_new();

        case NATIVE_CLASS_UTIL_CALENDAR:            // java/util/Calendar
            return native_util_calendar_new();

        case NATIVE_CLASS_UTIL_DATE:                // java/util/Date
            return native_util_date_new();

        case NATIVE_CLASS_UTIL_STRINGTOKENIZER:     // java/util/StringTokenizer
            return native_util_stringtokenizer_new();

        case NATIVE_CLASS_UTIL_RANDOM:              // java/util/Random
            return native_util_random_new();

        case NATIVE_CLASS_UTIL_TIMER:               // java/util/Timer
            return native_util_timer_new();

        case NATIVE_CLASS_UTIL_TIMERTASK:           // java/util/TimerTask
            return native_util_timertask_new();

        case NATIVE_CLASS_UTIL_TIMEZONE:            // java/util/TimeZone
            return native_util_timezone_new();

        case NATIVE_CLASS_UTIL_VECTOR:              // java/util/Vector
            return native_util_vector_new();

        case NATIVE_CLASS_IO_FILE:                  // java/io/File
            return native_io_file_new();

        case NATIVE_CLASS_IO_FILEINPUTSTREAM:       // java/io/FileInputStream
            return native_io_fileinputstream_new();

        case NATIVE_CLASS_IO_FILEOUTPUTSTREAM:      // java/io/FileOutputStream
            return native_io_fileoutputstream_new();

        case NATIVE_CLASS_IO_INPUTSTREAM:           // java/io/InputStream
            return native_io_inputstream_new();

        case NATIVE_CLASS_IO_OUTPUTSTREAM:          // java/io/OutputStream
            return native_io_outputstream_new();

        case NATIVE_CLASS_IO_PRINTSTREAM:           // java/io/PrintStream
            return native_io_printstream_new();

        case NATIVE_CLASS_IO_RANDOMACCESSFILE:      // java/io/RandomAccessFile
            return native_io_randomaccessfile_new();

			/*
        case NATIVE_CLASS_RUFFUS_OBJECTS_DISPOSABLE:      // java/io/RandomAccessFile
            return native_io_randomaccessfile_new();
            
        case NATIVE_CLASS_RUFFUS_GRAPHICS_DRAWING:
            return native_graphics_drawing_new();
            
        case NATIVE_CLASS_RUFFUS_GRAPHICS_COLOUR:
            return native_graphics_colour_new();

        case NATIVE_CLASS_RUFFUS_SYSTEM_INPUTPOINTER:
            return native_system_inputpointer_new();

        case NATIVE_CLASS_RUFFUS_SYSTEM_EVENTARGS:
            return native_system_eventargs_new();

		case NATIVE_CLASS_RUFFUS_WIDGETS_MENU:
			return native_widgets_menu_new();
			*/
        case NATIVE_CLASS_THROW_LANG_INTERRUPTEDEXCEPTION:                // java/throw/lang/InterruptedException
        case NATIVE_CLASS_THROW_LANG_NULLPOINTEREXECPTION:                // java/throw/lang/NullPointerException
        case NATIVE_CLASS_THROW_LANG_NEGATIVEARRAYSIZEEXCEPTION:          // java/throw/lang/NegativeArraySizeException
        case NATIVE_CLASS_THROW_LANG_ARITHMETICEXCEPTION:                 // java/throw/lang/ArithmeticException
        case NATIVE_CLASS_THROW_LANG_ARRAYSTOREEXCEPTION:                 // java/throw/lang/ArrayStoreException
        case NATIVE_CLASS_THROW_LANG_ILLEGALARGUMENTEXCEPTION:            // java/throw/lang/IllegalArgumentException
        case NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION:               // java/throw/lang/NoSuchMethodException
        case NATIVE_CLASS_THROW_LANG_NOSUCHFIELDEXCEPTION:                // java/throw/lang/NoSuchFieldException
        case NATIVE_CLASS_THROW_LANG_INDEXOUTOFBOUNDSEXCEPTION:           // java/throw/lang/IndexOutOfBoundsException
        case NATIVE_CLASS_THROW_LANG_ARRAYINDEXOUTOFBOUNDSEXCEPTION:      // java/throw/lang/ArrayIndexOutOfBoundsException
        case NATIVE_CLASS_THROW_LANG_STRINGINDEXOUTOFBOUNDSEXCEPTION:     // java/throw/lang/StringIndexOutOfBoundsException
        case NATIVE_CLASS_THROW_LANG_CLASSNOTFOUNDEXCEPTION:              // java/throw/lang/ClassNotFoundException
        case NATIVE_CLASS_THROW_LANG_UNSUPPORTEDOPERATIONEXCEPTION:       // java/throw/lang/UnsupportedOperationException
        case NATIVE_CLASS_THROW_UTIL_EMPTYSTACKEXCEPTION:                 // java/throw/util/EmptyStackException
        case NATIVE_CLASS_THROW_UTIL_NOSUCHELEMENTEXCEPTION:              // java/throw/util/NoSuchElementException
        case NATIVE_CLASS_THROW_IO_CHARCONVERSIONEXCEPTION:               // java/throw/io/CharConversionException
        case NATIVE_CLASS_THROW_IO_EOFEXCEPTION:                          // java/throw/io/EOFException
        case NATIVE_CLASS_THROW_IO_FILENOTFOUNDEXCEPTION:                 // java/throw/io/FileNotFoundException
        case NATIVE_CLASS_THROW_IO_INTERRUPTEDIOEXCEPTION:                // java/throw/io/InterruptedIOException
        case NATIVE_CLASS_THROW_IO_INVALIDCLASSEXCEPTION:                 // java/throw/io/InvalidClassException
        case NATIVE_CLASS_THROW_IO_INVALIDOBJECTEXCEPTION:                // java/throw/io/InvalidObjectException
        case NATIVE_CLASS_THROW_IO_IOEXCEPTION:                           // java/throw/io/IOException
        case NATIVE_CLASS_THROW_IO_NOTACTIVEEXCEPTION:                    // java/throw/io/NotActiveException
        case NATIVE_CLASS_THROW_IO_OBJECTSTREAMEXCEPTION:                 // java/throw/io/ObjectStreamException
        case NATIVE_CLASS_THROW_IO_STREAMCORRUPTEDEXCEPTION:              // java/throw/io/StreamCorruptedException
        case NATIVE_CLASS_THROW_IO_WRITEABORTEDEXCEPTION:                 // java/throw/io/WriteAbortedException
            return throw_exception_new_object( GET_CLASS_INDEX( mref ) );

        default:
            exception_new( NATIVE_CLASS_THROW_LANG_CLASSNOTFOUNDEXCEPTION, msg_throw_class_not_found );
            break;
    }
    return 0;
}

void native_get_field( uint32_t mref )
{
    switch( GET_CLASS_INDEX( mref ) )
    {
        case NATIVE_CLASS_LANG_SYSTEM:              // java/lang/System
            native_lang_system_get_field( GET_METHOD_ID(mref) );
            break;

        case NATIVE_CLASS_LANG_BOOLEAN:             // java/lang/Boolean
            native_lang_boolean_get_field( GET_METHOD_ID(mref) );
            break;

        case NATIVE_CLASS_LANG_BYTE:                // java/lang/Byte
            native_lang_byte_get_field( GET_METHOD_ID(mref) );
            break;

        case NATIVE_CLASS_LANG_CHARACTER:           // java/lang/Character
            native_lang_character_get_field( GET_METHOD_ID(mref) );
            break;

        case NATIVE_CLASS_LANG_SHORT:               // java/lang/Short
            native_lang_short_get_field( GET_METHOD_ID(mref) );
            break;

        case NATIVE_CLASS_LANG_INTEGER:             // java/lang/Integer
            native_lang_integer_get_field( GET_METHOD_ID(mref) );
            break;

        case NATIVE_CLASS_LANG_LONG:                // java/lang/Long
            native_lang_long_get_field( GET_METHOD_ID(mref) );
            break;

        case NATIVE_CLASS_LANG_FLOAT:               // java/lang/Float
            native_lang_float_get_field( GET_METHOD_ID(mref) );
            break;

        case NATIVE_CLASS_LANG_DOUBLE:              // java/lang/Double
            native_lang_double_get_field( GET_METHOD_ID(mref) );
            break;

        case NATIVE_CLASS_LANG_MATH:                // java/lang/Math
            native_lang_math_get_field( GET_METHOD_ID(mref) );
            break;

        case NATIVE_CLASS_LANG_STRING:              // java/lang/String
            native_lang_string_get_field( GET_METHOD_ID(mref) );
            break;

        case NATIVE_CLASS_LANG_THREAD:              // java/lang/Thread
            native_lang_thread_get_field( GET_METHOD_ID(mref) );
            break;

		case NATIVE_CLASS_LANG_REFLECT_FIELD:		// java/lang/reflect/Field
			native_lang_reflect_field_get_field( GET_METHOD_ID(mref) );
			break;

		case NATIVE_CLASS_LANG_REFLECT_METHOD:		// java/lang/reflect/Method
			native_lang_reflect_method_get_field( GET_METHOD_ID(mref) );
			break;

        case NATIVE_CLASS_UTIL_CALENDAR:            // java/util/Calendar
            native_util_calendar_get_field( GET_METHOD_ID(mref) );
            break;

        case NATIVE_CLASS_UTIL_TIMEZONE:            // java/util/TimeZone
            native_util_timezone_get_field( GET_METHOD_ID(mref) );
            break;

        case NATIVE_CLASS_UTIL_VECTOR:              // java/util/Vector
            native_util_vector_get_field( GET_METHOD_ID(mref) );
            break;

        case NATIVE_CLASS_IO_FILE:                  // java/io/File
            native_io_file_get_field( GET_METHOD_ID(mref) );
            break;

        case NATIVE_CLASS_IO_RANDOMACCESSFILE:      // java/io/RandomAccessFile
            native_io_file_get_field( GET_METHOD_ID(mref) );
            break;
            
			/*
        case NATIVE_CLASS_RUFFUS_GRAPHICS_COLOUR:
            native_graphics_colour_get_field( GET_METHOD_ID(mref) );
            break;

        case NATIVE_CLASS_RUFFUS_SYSTEM_INPUTPOINTER:
            native_system_inputpointer_get_field( GET_METHOD_ID(mref) );
            break;
            
        case NATIVE_CLASS_RUFFUS_SYSTEM_EVENTARGS:
            native_system_eventargs_get_field( GET_METHOD_ID(mref) );
            break;

		case NATIVE_CLASS_RUFFUS_WIDGETS_MENU:
			native_widgets_menu_get_field( GET_METHOD_ID(mref) );
			break;
            */
        default:
            exception_new( NATIVE_CLASS_THROW_LANG_CLASSNOTFOUNDEXCEPTION, msg_throw_class_not_found );
            break;
    }
}

void native_invoke( uint32_t mref )
{
    switch( GET_CLASS_INDEX( mref ) )
    {
        case NATIVE_CLASS_LANG_OBJECT:              // java/lang/Object
            native_lang_object_invoke( GET_METHOD_ID(mref) );
            break;

        case NATIVE_CLASS_LANG_CLASS:              // java/lang/Class
            native_lang_class_invoke( GET_METHOD_ID(mref) );
            break;

        case NATIVE_CLASS_LANG_SYSTEM:              // java/lang/System
            native_lang_system_invoke( GET_METHOD_ID(mref) );
            break;

        case NATIVE_CLASS_LANG_BOOLEAN:             // java/lang/Boolean
            native_lang_boolean_invoke( GET_METHOD_ID(mref) );
            break;

        case NATIVE_CLASS_LANG_BYTE:                // java/lang/Byte
            native_lang_byte_invoke( GET_METHOD_ID(mref) );
            break;

        case NATIVE_CLASS_LANG_CHARACTER:           // java/lang/Character
            native_lang_character_invoke( GET_METHOD_ID(mref) );
            break;

        case NATIVE_CLASS_LANG_SHORT:               // java/lang/Short
            native_lang_short_invoke( GET_METHOD_ID(mref) );
            break;

        case NATIVE_CLASS_LANG_INTEGER:             // java/lang/Integer
            native_lang_integer_invoke( GET_METHOD_ID(mref) );
            break;

        case NATIVE_CLASS_LANG_LONG:                // java/lang/Long
            native_lang_long_invoke( GET_METHOD_ID(mref) );
            break;

        case NATIVE_CLASS_LANG_FLOAT:               // java/lang/Float
            native_lang_float_invoke( GET_METHOD_ID(mref) );
            break;

        case NATIVE_CLASS_LANG_DOUBLE:              // java/lang/Double
            native_lang_double_invoke( GET_METHOD_ID(mref) );
            break;

        case NATIVE_CLASS_LANG_MATH:                // java/lang/Math
            native_lang_math_invoke( GET_METHOD_ID(mref) );
            break;

        case NATIVE_CLASS_LANG_STRING:              // java/lang/String
            native_lang_string_invoke( GET_METHOD_ID(mref) );
            break;

        case NATIVE_CLASS_LANG_STRINGBUILDER:       // java/lang/StringBuilder
            native_lang_stringbuilder_invoke( GET_METHOD_ID(mref) );
            break;

        case NATIVE_CLASS_LANG_PROCESS:             // java/lang/Process
            native_lang_process_invoke( GET_METHOD_ID(mref) );
            break;

        case NATIVE_CLASS_LANG_NUMBER:              // java/lang/Number
            native_lang_number_invoke( GET_METHOD_ID(mref) );
            break;

        case NATIVE_CLASS_LANG_RUNTIME:             // java/lang/Runtime
            native_lang_runtime_invoke( GET_METHOD_ID(mref) );
            break;

        case NATIVE_CLASS_LANG_THREAD:              // java/lang/Thread
            native_lang_thread_invoke( GET_METHOD_ID(mref) );
            break;

		case NATIVE_CLASS_LANG_REFLECT_FIELD:		// java/lang/reflect/Field
			native_lang_reflect_field_invoke( GET_METHOD_ID(mref) );
			break;

		case NATIVE_CLASS_LANG_REFLECT_METHOD:		// java/lang/reflect/Method
			native_lang_reflect_method_invoke( GET_METHOD_ID(mref) );
			break;

        case NATIVE_CLASS_UTIL_BITSET:              // java/util/BitSet
            native_util_bitset_invoke( GET_METHOD_ID(mref) );
            break;

        case NATIVE_CLASS_UTIL_CALENDAR:            // java/util/Calendar
            native_util_calendar_invoke( GET_METHOD_ID(mref) );
            break;

        case NATIVE_CLASS_UTIL_DATE:                // java/util/Date
            native_util_date_invoke( GET_METHOD_ID(mref) );
            break;

        case NATIVE_CLASS_UTIL_STRINGTOKENIZER:     // java/util/StringTokenizer
            native_util_stringtokenizer_invoke( GET_METHOD_ID(mref) );
            break;

        case NATIVE_CLASS_UTIL_RANDOM:              // java/util/Random
            native_util_random_invoke( GET_METHOD_ID(mref) );
            break;

        case NATIVE_CLASS_UTIL_TIMER:               // java/util/Timer
            native_util_timer_invoke( GET_METHOD_ID(mref) );
            break;

        case NATIVE_CLASS_UTIL_TIMERTASK:           // java/util/TimerTask
            native_util_timertask_invoke( GET_METHOD_ID(mref) );
            break;

        case NATIVE_CLASS_UTIL_TIMEZONE:            // java/util/TimeZone
            native_util_timezone_invoke( GET_METHOD_ID(mref) );
            break;

        case NATIVE_CLASS_UTIL_VECTOR:              // java/util/Vector
            native_util_vector_invoke( GET_METHOD_ID(mref) );
            break;

        case NATIVE_CLASS_IO_FILE:                  // java/io/File
            native_io_file_invoke( GET_METHOD_ID(mref) );
            break;

        case NATIVE_CLASS_IO_FILEINPUTSTREAM:       // java/io/FileInputStream
            native_io_fileinputstream_invoke( GET_METHOD_ID(mref) );
            break;

        case NATIVE_CLASS_IO_FILEOUTPUTSTREAM:      // java/io/FileOutputStream
            native_io_fileoutputstream_invoke( GET_METHOD_ID(mref) );
            break;

        case NATIVE_CLASS_IO_INPUTSTREAM:           // java/io/InputStream
            native_io_inputstream_invoke( GET_METHOD_ID(mref) );
            break;

        case NATIVE_CLASS_IO_OUTPUTSTREAM:          // java/io/OutputStream
            native_io_outputstream_invoke( GET_METHOD_ID(mref) );
            break;

        case NATIVE_CLASS_IO_PRINTSTREAM:           // java/io/PrintStream
            native_io_printstream_invoke( GET_METHOD_ID(mref) );
            break;

        case NATIVE_CLASS_IO_RANDOMACCESSFILE:      // java/io/RandomAccessFile
            native_io_randomaccessfile_invoke( GET_METHOD_ID(mref) );
            break;

            /*
        case NATIVE_CLASS_RUFFUS_OBJECTS_DISPOSABLE:      // java/io/RandomAccessFile
            native_objects_disposable_invoke( GET_METHOD_ID(mref) );
            break;
            
        case NATIVE_CLASS_RUFFUS_GRAPHICS_COLOUR:
            native_graphics_colour_invoke( GET_METHOD_ID(mref) );
            break;
            
        case NATIVE_CLASS_RUFFUS_GRAPHICS_DRAWING:
            native_graphics_drawing_invoke( GET_METHOD_ID(mref) );
            break;

        case NATIVE_CLASS_RUFFUS_SYSTEM_INPUTPOINTER:
            native_system_inputpointer_invoke( GET_METHOD_ID(mref) );
            break;        
            
        case NATIVE_CLASS_RUFFUS_WIDGETS_WIDGET:
            native_widgets_widget_invoke( GET_METHOD_ID(mref) );
            break;
            
		case NATIVE_CLASS_RUFFUS_WIDGETS_MENU:
			native_widgets_menu_invoke( GET_METHOD_ID(mref) );
			break;

        case NATIVE_CLASS_RUFFUS_WIDGETS_BUTTON:
        case NATIVE_CLASS_RUFFUS_WIDGETS_TEXT_BOX:
        case NATIVE_CLASS_RUFFUS_WIDGETS_TEXT_LABEL:
        case NATIVE_CLASS_RUFFUS_WIDGETS_FORM:
            native_widget_custom_create_invoke( mref );
            break;
            */

        case NATIVE_CLASS_THROW_LANG_INTERRUPTEDEXCEPTION:                // java/throw/lang/InterruptedException
        case NATIVE_CLASS_THROW_LANG_NULLPOINTEREXECPTION:                // java/throw/lang/NullPointerException
        case NATIVE_CLASS_THROW_LANG_NEGATIVEARRAYSIZEEXCEPTION:          // java/throw/lang/NegativeArraySizeException
        case NATIVE_CLASS_THROW_LANG_ARITHMETICEXCEPTION:                 // java/throw/lang/ArithmeticException
        case NATIVE_CLASS_THROW_LANG_ARRAYSTOREEXCEPTION:                 // java/throw/lang/ArrayStoreException
        case NATIVE_CLASS_THROW_LANG_ILLEGALARGUMENTEXCEPTION:            // java/throw/lang/IllegalArgumentException
        case NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION:               // java/throw/lang/NoSuchMethodException
        case NATIVE_CLASS_THROW_LANG_NOSUCHFIELDEXCEPTION:                // java/throw/lang/NoSuchFieldException
        case NATIVE_CLASS_THROW_LANG_INDEXOUTOFBOUNDSEXCEPTION:           // java/throw/lang/IndexOutOfBoundsException
        case NATIVE_CLASS_THROW_LANG_ARRAYINDEXOUTOFBOUNDSEXCEPTION:      // java/throw/lang/ArrayIndexOutOfBoundsException
        case NATIVE_CLASS_THROW_LANG_STRINGINDEXOUTOFBOUNDSEXCEPTION:     // java/throw/lang/StringIndexOutOfBoundsException
        case NATIVE_CLASS_THROW_LANG_CLASSNOTFOUNDEXCEPTION:              // java/throw/lang/ClassNotFoundException
        case NATIVE_CLASS_THROW_LANG_UNSUPPORTEDOPERATIONEXCEPTION:       // java/throw/lang/UnsupportedOperationException
        case NATIVE_CLASS_THROW_UTIL_EMPTYSTACKEXCEPTION:                 // java/throw/util/EmptyStackException
        case NATIVE_CLASS_THROW_UTIL_NOSUCHELEMENTEXCEPTION:              // java/throw/util/NoSuchElementException
        case NATIVE_CLASS_THROW_IO_CHARCONVERSIONEXCEPTION:               // java/throw/io/CharConversionException
        case NATIVE_CLASS_THROW_IO_EOFEXCEPTION:                          // java/throw/io/EOFException
        case NATIVE_CLASS_THROW_IO_FILENOTFOUNDEXCEPTION:                 // java/throw/io/FileNotFoundException
        case NATIVE_CLASS_THROW_IO_INTERRUPTEDIOEXCEPTION:                // java/throw/io/InterruptedIOException
        case NATIVE_CLASS_THROW_IO_INVALIDCLASSEXCEPTION:                 // java/throw/io/InvalidClassException
        case NATIVE_CLASS_THROW_IO_INVALIDOBJECTEXCEPTION:                // java/throw/io/InvalidObjectException
        case NATIVE_CLASS_THROW_IO_IOEXCEPTION:                           // java/throw/io/IOException
        case NATIVE_CLASS_THROW_IO_NOTACTIVEEXCEPTION:                    // java/throw/io/NotActiveException
        case NATIVE_CLASS_THROW_IO_OBJECTSTREAMEXCEPTION:                 // java/throw/io/ObjectStreamException
        case NATIVE_CLASS_THROW_IO_STREAMCORRUPTEDEXCEPTION:              // java/throw/io/StreamCorruptedException
        case NATIVE_CLASS_THROW_IO_WRITEABORTEDEXCEPTION:                 // java/throw/io/WriteAbortedException
            native_throw_exception_invoke(GET_METHOD_ID(mref));
            break;

        default:
            exception_new( NATIVE_CLASS_THROW_LANG_CLASSNOTFOUNDEXCEPTION, msg_throw_class_not_found );
            break;
    }
}

uint32_t native_superclass( uint32_t mref )
{
    switch( GET_CLASS_INDEX( mref ) )
    {
        case NATIVE_CLASS_LANG_OBJECT:              // java/lang/Object
            return native_lang_object_get_superclass();
            break;

        case NATIVE_CLASS_LANG_SYSTEM:              // java/lang/System
            return native_lang_system_get_superclass();
            break;

        case NATIVE_CLASS_LANG_BOOLEAN:             // java/lang/Boolean
            return native_lang_boolean_get_superclass();
            break;

        case NATIVE_CLASS_LANG_BYTE:                // java/lang/Byte
            return native_lang_byte_get_superclass();
            break;

        case NATIVE_CLASS_LANG_CHARACTER:           // java/lang/Character
            return native_lang_character_get_superclass();
            break;

        case NATIVE_CLASS_LANG_SHORT:               // java/lang/Short
            return native_lang_short_get_superclass();
            break;

        case NATIVE_CLASS_LANG_INTEGER:             // java/lang/Integer
            return native_lang_integer_get_superclass();
            break;

        case NATIVE_CLASS_LANG_LONG:                // java/lang/Long
            return native_lang_long_get_superclass();
            break;

        case NATIVE_CLASS_LANG_FLOAT:               // java/lang/Float
            return native_lang_float_get_superclass();
            break;

        case NATIVE_CLASS_LANG_DOUBLE:              // java/lang/Double
            return native_lang_double_get_superclass();
            break;

        case NATIVE_CLASS_LANG_MATH:                // java/lang/Math
            return native_lang_math_get_superclass();
            break;

        case NATIVE_CLASS_LANG_STRING:              // java/lang/String
            return native_lang_string_get_superclass();
            break;

        case NATIVE_CLASS_LANG_STRINGBUILDER:       // java/lang/StringBuilder
            return native_lang_stringbuilder_get_superclass();
            break;

        case NATIVE_CLASS_LANG_PROCESS:             // java/lang/Process
            return native_lang_process_get_superclass();
            break;

        case NATIVE_CLASS_LANG_NUMBER:              // java/lang/Number
            return native_lang_number_get_superclass();
            break;

        case NATIVE_CLASS_LANG_RUNTIME:             // java/lang/Runtime
            return native_lang_runtime_get_superclass();
            break;

        case NATIVE_CLASS_LANG_THREAD:              // java/lang/Thread
            return native_lang_thread_get_superclass();
            break;
            
        case NATIVE_CLASS_IO_RANDOMACCESSFILE:      // java/io/RandomAccessFile
            return native_lang_thread_get_superclass();
            break;            
	}

	return NATIVE_CLASS_LANG_OBJECT;
}

void native_call_finalize( uint32_t cref, object_t object )
{
    switch( GET_CLASS_INDEX( cref ) )
    {
        case NATIVE_CLASS_IO_FILEINPUTSTREAM:
            stack_push( object );
            native_io_fileinputstream_invoke( NATIVE_IO_FILEINPUTSTREAM_FINALIZE );
            break;

        case NATIVE_CLASS_IO_FILEOUTPUTSTREAM:
            stack_push( object );
            native_io_fileoutputstream_invoke( NATIVE_IO_FILEOUTPUTSTREAM_FINALIZE );
            break;
            
			/*
        case NATIVE_CLASS_RUFFUS_WIDGETS_WIDGET:
            native_widgets_widget_finalize( object );
            break;
			*/
    }
}

void native_init( uint32_t mref )
{
    // native initialization
    // put your code here
    // Implementation code: C567C3C6
}

void ruffus_native_init( void )
{
    //native_method_objects_disposable_init();
}
