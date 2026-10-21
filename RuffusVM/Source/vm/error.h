#ifndef ERROR_H
#define	ERROR_H

#ifdef	__cplusplus
extern "C" {
#endif

///////////////////////////////////////////////////////////////////////////

enum
{
	ERROR_NO_ERROR                  = 0,
	
	ERROR_HEAP_BASE_INDEX           = 0x20 ,
	ERROR_HEAP_INVALID_OBJECT,
    ERROR_HEAP_MEMORY_OVERFLOW,
    ERROR_HEAP_CORRUPTED,

	ERROR_ARRAY_BASE_INDEX          = 0x40 ,
    ERROR_ARRAY_OUT_OF_BOUND,
	ERROR_ARRAY_INVALID_REFERENCE,

	ERROR_NATIVE_BASE_INDEX         = 0x60 ,
	ERROR_FILE_BASE_INDEX			= 0x80 ,
	ERROR_VM_BASE_INDEX             = 0xA0 ,

	ERROR_OBJECT_BASE_INDEX			= 0xC0 ,
    ERROR_OBJECT_MEMORY_OVERFLOW,
	ERROR_OBJECT_INVALID_REFERENCE,

	ERROR_STRING_BASE_INDEX         = 0xD0 ,
    ERROR_STRING_OUT_OF_BOUND,
	ERROR_STRING_INVALID_REFERENCE,
};

///////////////////////////////////////////////////////////////////////////

extern const char * msg_throw_eof_reached;
extern const char * msg_throw_no_such_method;
extern const char * msg_throw_no_such_element;
extern const char * msg_throw_invalid_ref;
extern const char * msg_throw_out_of_bounds;
extern const char * msg_throw_divison_by_zero;
extern const char * msg_throw_unsupported_opcode;
extern const char * msg_throw_class_not_found;
extern const char * msg_throw_stack_underflow;
extern const char * msg_throw_invalid_array_store;
extern const char * msg_throw_illegal_argument;
extern const char * msg_throw_null_pointer;
extern const char * msg_throw_unsupported_operation;

///////////////////////////////////////////////////////////////////////////

void app_set_error( uint32_t error );

///////////////////////////////////////////////////////////////////////////

#ifdef	__cplusplus
}
#endif

#endif	/* ERROR_H */

