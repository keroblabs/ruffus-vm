#ifndef NATIVE_IO_OUTPUTSTREAM_H
#define NATIVE_IO_OUTPUTSTREAM_H

#ifdef	__cplusplus
extern "C" {
#endif

///////////////////////////////////////////////////////////////////////////

#include "datatypes.h"

///////////////////////////////////////////////////////////////////////////

// Class field implementation: IO_OUTPUTSTREAM_ENUM
enum
{
    NATIVE_FIELD_IO_OUTPUTSTREAM_DUMMY,
    NATIVE_IO_OUTPUTSTREAM_TOTAL_FIELDS
};

enum
{

    NATIVE_IO_OUTPUTSTREAM_INIT,                                                 // OutputStream()

    NATIVE_IO_OUTPUTSTREAM_CLOSE,                                                // void close()
    NATIVE_IO_OUTPUTSTREAM_FLUSH,                                                // void flush()
    NATIVE_IO_OUTPUTSTREAM_WRITE_ARRAY_BYTE,                                     // void write(byte[] b)
    NATIVE_IO_OUTPUTSTREAM_WRITE_ARRAY_BYTE_INT_INT,                             // void write(byte[] b, int off, int len)
    NATIVE_IO_OUTPUTSTREAM_WRITE_INT,                                            // abstract  void write(int b)
};

///////////////////////////////////////////////////////////////////////////

object_t native_io_outputstream_new( void );
void native_io_outputstream_get_field(uint16_t mref);
void native_io_outputstream_invoke(uint16_t mref);

///////////////////////////////////////////////////////////////////////////

#ifdef	__cplusplus
}
#endif

#endif // NATIVE_IO_OUTPUTSTREAM_H


