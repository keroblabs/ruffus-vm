#ifndef NATIVE_IO_PRINTSTREAM_H
#define NATIVE_IO_PRINTSTREAM_H

#ifdef	__cplusplus
extern "C" {
#endif

///////////////////////////////////////////////////////////////////////////

#include "datatypes.h"

///////////////////////////////////////////////////////////////////////////

// Class field implementation: IO_PRINTSTREAM_ENUM
enum
{
    NATIVE_FIELD_IO_PRINTSTREAM_DUMMY,
    NATIVE_IO_PRINTSTREAM_TOTAL_FIELDS
};

enum
{

    NATIVE_IO_PRINTSTREAM_INIT_FILE,                                             // PrintStream(File file)
    NATIVE_IO_PRINTSTREAM_INIT_FILE_STRING,                                      // PrintStream(File file, String csn)
    NATIVE_IO_PRINTSTREAM_INIT_OUTPUTSTREAM,                                     // PrintStream(OutputStream out)
    NATIVE_IO_PRINTSTREAM_INIT_OUTPUTSTREAM_BOOLEAN,                             // PrintStream(OutputStream out, boolean autoFlush)
    NATIVE_IO_PRINTSTREAM_INIT_OUTPUTSTREAM_BOOLEAN_STRING,                      // PrintStream(OutputStream out, boolean autoFlush, String encoding)
    NATIVE_IO_PRINTSTREAM_INIT_STRING,                                           // PrintStream(String fileName)
    NATIVE_IO_PRINTSTREAM_INIT_STRING_STRING,                                    // PrintStream(String fileName, String csn)

    NATIVE_IO_PRINTSTREAM_APPEND_CHAR,                                           // PrintStream append(char c)
    NATIVE_IO_PRINTSTREAM_APPEND_CHARSEQUENCE,                                   // PrintStream append(CharSequence csq)
    NATIVE_IO_PRINTSTREAM_APPEND_CHARSEQUENCE_INT_INT,                           // PrintStream append(CharSequence csq, int start, int end)
    NATIVE_IO_PRINTSTREAM_CHECKERROR,                                            // boolean checkError()
    NATIVE_IO_PRINTSTREAM_CLEARERROR,                                            // protected  void clearError()
    NATIVE_IO_PRINTSTREAM_CLOSE,                                                 // void close()
    NATIVE_IO_PRINTSTREAM_FLUSH,                                                 // void flush()
    NATIVE_IO_PRINTSTREAM_PRINT_BOOLEAN,                                         // void print(boolean b)
    NATIVE_IO_PRINTSTREAM_PRINT_CHAR,                                            // void print(char c)
    NATIVE_IO_PRINTSTREAM_PRINT_ARRAY_CHAR,                                      // void print(char[] s)
    NATIVE_IO_PRINTSTREAM_PRINT_DOUBLE,                                          // void print(double d)
    NATIVE_IO_PRINTSTREAM_PRINT_FLOAT,                                           // void print(float f)
    NATIVE_IO_PRINTSTREAM_PRINT_INT,                                             // void print(int i)
    NATIVE_IO_PRINTSTREAM_PRINT_LONG,                                            // void print(long l)
    NATIVE_IO_PRINTSTREAM_PRINT_OBJECT,                                          // void print(Object obj)
    NATIVE_IO_PRINTSTREAM_PRINT_STRING,                                          // void print(String s)
    NATIVE_IO_PRINTSTREAM_PRINTLN,                                               // void println()
    NATIVE_IO_PRINTSTREAM_PRINTLN_BOOLEAN,                                       // void println(boolean x)
    NATIVE_IO_PRINTSTREAM_PRINTLN_CHAR,                                          // void println(char x)
    NATIVE_IO_PRINTSTREAM_PRINTLN_ARRAY_CHAR,                                    // void println(char[] x)
    NATIVE_IO_PRINTSTREAM_PRINTLN_DOUBLE,                                        // void println(double x)
    NATIVE_IO_PRINTSTREAM_PRINTLN_FLOAT,                                         // void println(float x)
    NATIVE_IO_PRINTSTREAM_PRINTLN_INT,                                           // void println(int x)
    NATIVE_IO_PRINTSTREAM_PRINTLN_LONG,                                          // void println(long x)
    NATIVE_IO_PRINTSTREAM_PRINTLN_OBJECT,                                        // void println(Object x)
    NATIVE_IO_PRINTSTREAM_PRINTLN_STRING,                                        // void println(String x)
    NATIVE_IO_PRINTSTREAM_SETERROR,                                              // protected  void setError()
    NATIVE_IO_PRINTSTREAM_WRITE_ARRAY_BYTE,                                      // void write(byte[] b)
    NATIVE_IO_PRINTSTREAM_WRITE_ARRAY_BYTE_INT_INT,                              // void write(byte[] buf, int off, int len)
    NATIVE_IO_PRINTSTREAM_WRITE_INT,                                             // void write(int b)
};

///////////////////////////////////////////////////////////////////////////

object_t native_io_printstream_new( void );
void native_io_printstream_get_field(uint16_t mref);
void native_io_printstream_invoke(uint16_t mref);

///////////////////////////////////////////////////////////////////////////

#ifdef	__cplusplus
}
#endif

#endif // NATIVE_IO_PRINTSTREAM_H


