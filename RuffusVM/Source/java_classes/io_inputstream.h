#ifndef NATIVE_IO_INPUTSTREAM_H
#define NATIVE_IO_INPUTSTREAM_H

#ifdef	__cplusplus
extern "C" {
#endif

///////////////////////////////////////////////////////////////////////////

#include "datatypes.h"

///////////////////////////////////////////////////////////////////////////

// Class field implementation: IO_INPUTSTREAM_ENUM
enum
{
    NATIVE_FIELD_IO_INPUTSTREAM_DUMMY,
    NATIVE_IO_INPUTSTREAM_TOTAL_FIELDS
};

enum
{

    NATIVE_IO_INPUTSTREAM_INIT,                                                  // InputStream()

    NATIVE_IO_INPUTSTREAM_AVAILABLE,                                             // int available()
    NATIVE_IO_INPUTSTREAM_CLOSE,                                                 // void close()
    NATIVE_IO_INPUTSTREAM_MARK_INT,                                              // void mark(int readlimit)
    NATIVE_IO_INPUTSTREAM_MARKSUPPORTED,                                         // boolean markSupported()
    NATIVE_IO_INPUTSTREAM_READ,                                                  // abstract  int read()
    NATIVE_IO_INPUTSTREAM_READ_ARRAY_BYTE,                                       // int read(byte[] b)
    NATIVE_IO_INPUTSTREAM_READ_ARRAY_BYTE_INT_INT,                               // int read(byte[] b, int off, int len)
    NATIVE_IO_INPUTSTREAM_RESET,                                                 // void reset()
    NATIVE_IO_INPUTSTREAM_SKIP_LONG,                                             // long skip(long n)
};

///////////////////////////////////////////////////////////////////////////

object_t native_io_inputstream_new( void );
void native_io_inputstream_get_field(uint16_t mref);
void native_io_inputstream_invoke(uint16_t mref);

///////////////////////////////////////////////////////////////////////////

#ifdef	__cplusplus
}
#endif

#endif // NATIVE_IO_INPUTSTREAM_H


