#ifndef NATIVE_IO_FILEOUTPUTSTREAM_H
#define NATIVE_IO_FILEOUTPUTSTREAM_H

#ifdef	__cplusplus
extern "C" {
#endif

///////////////////////////////////////////////////////////////////////////

#include "datatypes.h"

///////////////////////////////////////////////////////////////////////////

// Class field implementation: IO_FILEOUTPUTSTREAM_ENUM
enum
{
    NATIVE_FIELD_IO_FILEOUTPUTSTREAM_DUMMY,
    NATIVE_IO_FILEOUTPUTSTREAM_TOTAL_FIELDS
};

enum
{

    NATIVE_IO_FILEOUTPUTSTREAM_INIT_FILE,                                        // FileOutputStream(File file)
    NATIVE_IO_FILEOUTPUTSTREAM_INIT_FILE_BOOLEAN,                                // FileOutputStream(File file, boolean append)
    NATIVE_IO_FILEOUTPUTSTREAM_INIT_FILEDESCRIPTOR,                              // FileOutputStream(FileDescriptor fdObj)
    NATIVE_IO_FILEOUTPUTSTREAM_INIT_STRING,                                      // FileOutputStream(String name)
    NATIVE_IO_FILEOUTPUTSTREAM_INIT_STRING_BOOLEAN,                              // FileOutputStream(String name, boolean append)

    NATIVE_IO_FILEOUTPUTSTREAM_CLOSE,                                            // void close()
    NATIVE_IO_FILEOUTPUTSTREAM_FINALIZE,                                         // protected  void finalize()
    NATIVE_IO_FILEOUTPUTSTREAM_FLUSH,                                            // void flush()
    NATIVE_IO_FILEOUTPUTSTREAM_GETFD,                                            // FileDescriptor getFD()
    NATIVE_IO_FILEOUTPUTSTREAM_WRITE_ARRAY_BYTE,                                 // void write(byte[] b)
    NATIVE_IO_FILEOUTPUTSTREAM_WRITE_ARRAY_BYTE_INT_INT,                         // void write(byte[] b, int off, int len)
    NATIVE_IO_FILEOUTPUTSTREAM_WRITE_INT,                                        // void write(int b)
};

///////////////////////////////////////////////////////////////////////////

object_t native_io_fileoutputstream_new( void );
void native_io_fileoutputstream_get_field(uint16_t mref);
void native_io_fileoutputstream_invoke(uint16_t mref);

///////////////////////////////////////////////////////////////////////////

#ifdef	__cplusplus
}
#endif

#endif // NATIVE_IO_FILEOUTPUTSTREAM_H


