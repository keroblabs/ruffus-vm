#ifndef NATIVE_IO_FILE_H
#define NATIVE_IO_FILE_H

#ifdef	__cplusplus
extern "C" {
#endif

///////////////////////////////////////////////////////////////////////////

#include "datatypes.h"

///////////////////////////////////////////////////////////////////////////

// Class field implementation: IO_FILE_ENUM
enum
{
    NATIVE_FIELD_IO_FILE_PATH,
    NATIVE_IO_FILE_TOTAL_FIELDS
};

enum
{
    NATIVE_FIELD_IO_FILE_PATHSEPARATOR,                                          // static String pathSeparator
    NATIVE_FIELD_IO_FILE_PATHSEPARATORCHAR,                                      // static char pathSeparatorChar
    NATIVE_FIELD_IO_FILE_SEPARATOR,                                              // static String separator
    NATIVE_FIELD_IO_FILE_SEPARATORCHAR,                                          // static char separatorChar
};

enum
{
    NATIVE_IO_FILE_INIT_FILE_STRING,                                             // File(File parent, String child)
    NATIVE_IO_FILE_INIT_STRING,                                                  // File(String pathname)
    NATIVE_IO_FILE_INIT_STRING_STRING,                                           // File(String parent, String child)
    NATIVE_IO_FILE_INIT_URI,                                                     // File(URI uri)

    NATIVE_IO_FILE_CANEXECUTE,                                                   // boolean canExecute()
    NATIVE_IO_FILE_CANREAD,                                                      // boolean canRead()
    NATIVE_IO_FILE_CANWRITE,                                                     // boolean canWrite()
    NATIVE_IO_FILE_COMPARETO_FILE,                                               // int compareTo(File pathname)
    NATIVE_IO_FILE_CREATENEWFILE,                                                // boolean createNewFile()
    NATIVE_IO_FILE_CREATETEMPFILE_STRING_STRING,                                 // static File createTempFile(String prefix, String suffix)
    NATIVE_IO_FILE_CREATETEMPFILE_STRING_STRING_FILE,                            // static File createTempFile(String prefix, String suffix, File directory)
    NATIVE_IO_FILE_DELETE,                                                       // boolean delete()
    NATIVE_IO_FILE_DELETEONEXIT,                                                 // void deleteOnExit()
    NATIVE_IO_FILE_EQUALS_OBJECT,                                                // boolean equals(Object obj)
    NATIVE_IO_FILE_EXISTS,                                                       // boolean exists()
    NATIVE_IO_FILE_GETABSOLUTEFILE,                                              // File getAbsoluteFile()
    NATIVE_IO_FILE_GETABSOLUTEPATH,                                              // String getAbsolutePath()
    NATIVE_IO_FILE_GETCANONICALFILE,                                             // File getCanonicalFile()
    NATIVE_IO_FILE_GETCANONICALPATH,                                             // String getCanonicalPath()
    NATIVE_IO_FILE_GETFREESPACE,                                                 // long getFreeSpace()
    NATIVE_IO_FILE_GETNAME,                                                      // String getName()
    NATIVE_IO_FILE_GETPARENT,                                                    // String getParent()
    NATIVE_IO_FILE_GETPARENTFILE,                                                // File getParentFile()
    NATIVE_IO_FILE_GETPATH,                                                      // String getPath()
    NATIVE_IO_FILE_GETTOTALSPACE,                                                // long getTotalSpace()
    NATIVE_IO_FILE_GETUSABLESPACE,                                               // long getUsableSpace()
    NATIVE_IO_FILE_HASHCODE,                                                     // int hashCode()
    NATIVE_IO_FILE_ISABSOLUTE,                                                   // boolean isAbsolute()
    NATIVE_IO_FILE_ISDIRECTORY,                                                  // boolean isDirectory()
    NATIVE_IO_FILE_ISFILE,                                                       // boolean isFile()
    NATIVE_IO_FILE_ISHIDDEN,                                                     // boolean isHidden()
    NATIVE_IO_FILE_LASTMODIFIED,                                                 // long lastModified()
    NATIVE_IO_FILE_LENGTH,                                                       // long length()
    NATIVE_IO_FILE_LIST,                                                         // String[] list()
    NATIVE_IO_FILE_LIST_FILENAMEFILTER,                                          // String[] list(FilenameFilter filter)
    NATIVE_IO_FILE_LISTFILES,                                                    // File[] listFiles()
    NATIVE_IO_FILE_LISTFILES_FILEFILTER,                                         // File[] listFiles(FileFilter filter)
    NATIVE_IO_FILE_LISTFILES_FILENAMEFILTER,                                     // File[] listFiles(FilenameFilter filter)
    NATIVE_IO_FILE_LISTROOTS,                                                    // static File[] listRoots()
    NATIVE_IO_FILE_MKDIR,                                                        // boolean mkdir()
    NATIVE_IO_FILE_MKDIRS,                                                       // boolean mkdirs()
    NATIVE_IO_FILE_RENAMETO_FILE,                                                // boolean renameTo(File dest)
    NATIVE_IO_FILE_SETEXECUTABLE_BOOLEAN,                                        // boolean setExecutable(boolean executable)
    NATIVE_IO_FILE_SETEXECUTABLE_BOOLEAN_BOOLEAN,                                // boolean setExecutable(boolean executable, boolean ownerOnly)
    NATIVE_IO_FILE_SETLASTMODIFIED_LONG,                                         // boolean setLastModified(long time)
    NATIVE_IO_FILE_SETREADABLE_BOOLEAN,                                          // boolean setReadable(boolean readable)
    NATIVE_IO_FILE_SETREADABLE_BOOLEAN_BOOLEAN,                                  // boolean setReadable(boolean readable, boolean ownerOnly)
    NATIVE_IO_FILE_SETREADONLY,                                                  // boolean setReadOnly()
    NATIVE_IO_FILE_SETWRITABLE_BOOLEAN,                                          // boolean setWritable(boolean writable)
    NATIVE_IO_FILE_SETWRITABLE_BOOLEAN_BOOLEAN,                                  // boolean setWritable(boolean writable, boolean ownerOnly)
    NATIVE_IO_FILE_TOSTRING,                                                     // String toString()
};

///////////////////////////////////////////////////////////////////////////

object_t native_io_file_new( void );
void native_io_file_get_field(uint16_t mref);
void native_io_file_invoke(uint16_t mref);

///////////////////////////////////////////////////////////////////////////

#ifdef	__cplusplus
}
#endif

#endif // NATIVE_IO_FILE_H


