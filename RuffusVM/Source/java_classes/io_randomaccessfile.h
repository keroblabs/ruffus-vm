#ifndef NATIVE_IO_RANDOMACCESSFILE_H
#define NATIVE_IO_RANDOMACCESSFILE_H

#ifdef	__cplusplus
extern "C" {
#endif

///////////////////////////////////////////////////////////////////////////

#include "datatypes.h"

///////////////////////////////////////////////////////////////////////////

// Class field implementation: IO_RANDOMACCESSFILE_ENUM
enum
{
    NATIVE_FIELD_IO_RANDOMACCESSFILE_DUMMY,
    NATIVE_IO_RANDOMACCESSFILE_TOTAL_FIELDS
};

enum
{

    NATIVE_IO_RANDOMACCESSFILE_INIT_FILE_STRING,                                 // RandomAccessFile(File file, String mode)
    NATIVE_IO_RANDOMACCESSFILE_INIT_STRING_STRING,                               // RandomAccessFile(String name, String mode)

    NATIVE_IO_RANDOMACCESSFILE_CLOSE,                                            // void close()
    NATIVE_IO_RANDOMACCESSFILE_GETFILEPOINTER,                                   // long getFilePointer()
    NATIVE_IO_RANDOMACCESSFILE_LENGTH,                                           // long length()
    NATIVE_IO_RANDOMACCESSFILE_READ,                                             // int read()
    NATIVE_IO_RANDOMACCESSFILE_READ_ARRAY_BYTE,                                  // int read(byte[] b)
    NATIVE_IO_RANDOMACCESSFILE_READ_ARRAY_BYTE_INT_INT,                          // int read(byte[] b, int off, int len)
    NATIVE_IO_RANDOMACCESSFILE_READBOOLEAN,                                      // boolean readBoolean()
    NATIVE_IO_RANDOMACCESSFILE_READBYTE,                                         // byte readByte()
    NATIVE_IO_RANDOMACCESSFILE_READCHAR,                                         // char readChar()
    NATIVE_IO_RANDOMACCESSFILE_READDOUBLE,                                       // double readDouble()
    NATIVE_IO_RANDOMACCESSFILE_READFLOAT,                                        // float readFloat()
    NATIVE_IO_RANDOMACCESSFILE_READFULLY_ARRAY_BYTE,                             // void readFully(byte[] b)
    NATIVE_IO_RANDOMACCESSFILE_READFULLY_ARRAY_BYTE_INT_INT,                     // void readFully(byte[] b, int off, int len)
    NATIVE_IO_RANDOMACCESSFILE_READINT,                                          // int readInt()
    NATIVE_IO_RANDOMACCESSFILE_READLONG,                                         // long readLong()
    NATIVE_IO_RANDOMACCESSFILE_READSHORT,                                        // short readShort()
    NATIVE_IO_RANDOMACCESSFILE_READUNSIGNEDBYTE,                                 // int readUnsignedByte()
    NATIVE_IO_RANDOMACCESSFILE_READUNSIGNEDSHORT,                                // int readUnsignedShort()
    NATIVE_IO_RANDOMACCESSFILE_SEEK_LONG,                                        // void seek(long pos)
    NATIVE_IO_RANDOMACCESSFILE_SETLENGTH_LONG,                                   // void setLength(long newLength)
    NATIVE_IO_RANDOMACCESSFILE_SKIPBYTES_INT,                                    // int skipBytes(int n)
    NATIVE_IO_RANDOMACCESSFILE_WRITE_ARRAY_BYTE,                                 // void write(byte[] b)
    NATIVE_IO_RANDOMACCESSFILE_WRITE_ARRAY_BYTE_INT_INT,                         // void write(byte[] b, int off, int len)
    NATIVE_IO_RANDOMACCESSFILE_WRITE_INT,                                        // void write(int b)
    NATIVE_IO_RANDOMACCESSFILE_WRITEBOOLEAN_BOOLEAN,                             // void writeBoolean(boolean v)
    NATIVE_IO_RANDOMACCESSFILE_WRITEBYTE_INT,                                    // void writeByte(int v)
    NATIVE_IO_RANDOMACCESSFILE_WRITEBYTES_STRING,                                // void writeBytes(String s)
    NATIVE_IO_RANDOMACCESSFILE_WRITECHAR_INT,                                    // void writeChar(int v)
    NATIVE_IO_RANDOMACCESSFILE_WRITECHARS_STRING,                                // void writeChars(String s)
    NATIVE_IO_RANDOMACCESSFILE_WRITEDOUBLE_DOUBLE,                               // void writeDouble(double v)
    NATIVE_IO_RANDOMACCESSFILE_WRITEFLOAT_FLOAT,                                 // void writeFloat(float v)
    NATIVE_IO_RANDOMACCESSFILE_WRITEINT_INT,                                     // void writeInt(int v)
    NATIVE_IO_RANDOMACCESSFILE_WRITELONG_LONG,                                   // void writeLong(long v)
    NATIVE_IO_RANDOMACCESSFILE_WRITESHORT_INT,                                   // void writeShort(int v)
    NATIVE_IO_RANDOMACCESSFILE_WRITEUTF_STRING,                                  // void writeUTF(String str)
};

///////////////////////////////////////////////////////////////////////////

object_t native_io_randomaccessfile_new( void );
void native_io_randomaccessfile_get_field(uint16_t mref);
void native_io_randomaccessfile_invoke(uint16_t mref);

///////////////////////////////////////////////////////////////////////////

#ifdef	__cplusplus
}
#endif

#endif // NATIVE_IO_RANDOMACCESSFILE_H


