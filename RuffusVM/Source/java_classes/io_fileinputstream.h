#ifndef NATIVE_IO_FILEINPUTSTREAM_H
#define NATIVE_IO_FILEINPUTSTREAM_H

#ifdef	__cplusplus
extern "C" {
#endif

///////////////////////////////////////////////////////////////////////////

#include "datatypes.h"

///////////////////////////////////////////////////////////////////////////

// Class field implementation: IO_FILEINPUTSTREAM_ENUM
enum
{
    NATIVE_FIELD_IO_FILEINPUTSTREAM_MARK,
    NATIVE_IO_FILEINPUTSTREAM_TOTAL_FIELDS
};

enum
{

    NATIVE_IO_FILEINPUTSTREAM_INIT_FILE,                                         // FileInputStream(File file)
    NATIVE_IO_FILEINPUTSTREAM_INIT_FILEDESCRIPTOR,                               // FileInputStream(FileDescriptor fdObj)
    NATIVE_IO_FILEINPUTSTREAM_INIT_STRING,                                       // FileInputStream(String name)

    NATIVE_IO_FILEINPUTSTREAM_AVAILABLE,                                         // int available()
    NATIVE_IO_FILEINPUTSTREAM_CLOSE,                                             // void close()
    NATIVE_IO_FILEINPUTSTREAM_FINALIZE,                                          // protected  void finalize()
    NATIVE_IO_FILEINPUTSTREAM_GETFD,                                             // FileDescriptor getFD()
    NATIVE_IO_FILEINPUTSTREAM_MARK_INT,                                          // void mark(int readlimit)
    NATIVE_IO_FILEINPUTSTREAM_MARKSUPPORTED,                                     // boolean markSupported()
    NATIVE_IO_FILEINPUTSTREAM_READ,                                              // int read()
    NATIVE_IO_FILEINPUTSTREAM_READ_ARRAY_BYTE,                                   // int read(byte[] b)
    NATIVE_IO_FILEINPUTSTREAM_READ_ARRAY_BYTE_INT_INT,                           // int read(byte[] b, int off, int len)
    NATIVE_IO_FILEINPUTSTREAM_RESET,                                             // void reset()
    NATIVE_IO_FILEINPUTSTREAM_SKIP_LONG,                                         // long skip(long n)
};

///////////////////////////////////////////////////////////////////////////

object_t native_io_fileinputstream_new( void );
void native_io_fileinputstream_get_field(uint16_t mref);
void native_io_fileinputstream_invoke(uint16_t mref);

///////////////////////////////////////////////////////////////////////////

#ifdef	__cplusplus
}
#endif

#endif // NATIVE_IO_FILEINPUTSTREAM_H


