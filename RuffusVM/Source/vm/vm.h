#ifndef VM_H
#define	VM_H

#ifdef	__cplusplus
extern "C" {
#endif

///////////////////////////////////////////////////////////////////////////

#include "types.h"
#include "datatypes.h"
#include "error.h"
    
///////////////////////////////////////////////////////////////////////////

enum
{
    ERROR_VM_BASE                       = ERROR_VM_BASE_INDEX,
    
    ERROR_VM_DIVISION_BY_ZERO,
	ERROR_VM_UNSUPPORTED_OPCODE,
	ERROR_VM_FILE_TOO_BIG,
	ERROR_VM_UNKNOWN_METHOD,
    ERROR_VM_UNKNOWN_CLASS,
	ERROR_VM_OUT_OF_MEMORY,
	ERROR_VM_ILLEGAL_REFERENCE,
	ERROR_VM_STACK_CORRUPTED,
};
    
///////////////////////////////////////////////////////////////////////////
    
void    vm_new( uint32_t cref );
void    vm_invoke_new( app_method_t * ptr_method, object_t object, object_t * param_list );

uint8_t vm_invoke( uint32_t cref, uint8_t mode );
bool_t  vm_invoke_interface(object_t object, char * method_name);

uint8_t vm_run(void);

void    vm_enter_monitor( object_t object );

bool_t  vm_return( bool_t is_return );
bool_t  vm_cast_check( uint32_t cref, object_t object );

void    vm_on_delete_object( object_t object );

lib_native_t  vm_search_lib_by_id( uint32_t id );
lib_entry_t * vm_search_lib( char * name );
void          vm_add_lib( char * name, lib_native_t native_call );

///////////////////////////////////////////////////////////////////////////


#ifdef	__cplusplus
}
#endif

#endif	/* VM_H */

