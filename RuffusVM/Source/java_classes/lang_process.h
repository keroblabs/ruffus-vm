#ifndef NATIVE_LANG_PROCESS_H
#define NATIVE_LANG_PROCESS_H

#ifdef	__cplusplus
extern "C" {
#endif

///////////////////////////////////////////////////////////////////////////

#include "datatypes.h"

///////////////////////////////////////////////////////////////////////////

// Class field implementation: LANG_PROCESS_ENUM
enum
{
    NATIVE_FIELD_LANG_PROCESS_DUMMY,
    NATIVE_LANG_PROCESS_TOTAL_FIELDS
};

enum
{

    NATIVE_LANG_PROCESS_INIT,                                                    // Process()

    NATIVE_LANG_PROCESS_DESTROY,                                                 // abstract  void destroy()
    NATIVE_LANG_PROCESS_EXITVALUE,                                               // abstract  int exitValue()
    NATIVE_LANG_PROCESS_GETERRORSTREAM,                                          // abstract  InputStream getErrorStream()
    NATIVE_LANG_PROCESS_GETINPUTSTREAM,                                          // abstract  InputStream getInputStream()
    NATIVE_LANG_PROCESS_GETOUTPUTSTREAM,                                         // abstract  OutputStream getOutputStream()
    NATIVE_LANG_PROCESS_WAITFOR,                                                 // abstract  int waitFor()
};

///////////////////////////////////////////////////////////////////////////

object_t native_lang_process_new( void );
void native_lang_process_get_field(uint16_t mref);
void native_lang_process_invoke(uint16_t mref);

uint32_t native_lang_process_get_superclass( void );

///////////////////////////////////////////////////////////////////////////

#ifdef	__cplusplus
}
#endif

#endif // NATIVE_LANG_PROCESS_H


