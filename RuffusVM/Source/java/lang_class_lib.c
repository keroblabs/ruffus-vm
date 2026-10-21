#include "lang_class_lib.h"
#include "heap.h"
#include "application.h"
#include "threads.h"
#include "exceptions.h"
#include "native.h"
#include "objects.h"
#include "stack.h"
#include "value_type.h"
#include "strings.h"

///////////////////////////////////////////////////////////////////////////

app_instance_t * lang_class_lib_get_info( object_t class_object, object_t * p_object, uint32_t * cref )
{
    object_t * fields;
    app_instance_t * ret;
    
    // make sure this call is made inside the correct instance (FIX_ME 64bit)
    // otherwise it wont find the object
    if( object_get_class_ref( class_object ) != GET_CLASS_REF( NATIVE_CLASS_LANG_CLASS ) ) return NULL;
    
    fields = object_get_fields_ptr( class_object );
    if( p_object != NULL ) *p_object = fields[NATIVE_FIELD_LANG_CLASS_OBJECT];
    if( cref != NULL ) *cref = ( uint32_t )value_get_as_integer( fields[NATIVE_FIELD_LANG_CLASS_CREF] );
    
#if defined SYSTEM_64BIT
    ret = ( app_instance_t * )value_get_as_long( fields[NATIVE_FIELD_LANG_CLASS_INSTANCE] );
#else
    ret = ( app_instance_t * )value_get_as_integer( fields[NATIVE_FIELD_LANG_CLASS_INSTANCE] );
#endif
    return ret;
}

object_t lang_class_lib_get_class( object_t object )
{
	object_t class_object;
    object_t * fields;
    
    object = stack_peek(0);
    
    class_object = native_lang_class_new();
    fields = object_get_fields_ptr( class_object );
    fields[NATIVE_FIELD_LANG_CLASS_CREF] = value_create_int( (int32_t)object_get_class_ref(object) );
    fields[NATIVE_FIELD_LANG_CLASS_OBJECT] = object;
    
#if defined SYSTEM_64BIT
    fields[NATIVE_FIELD_LANG_CLASS_INSTANCE] = value_create_long( (int64_t)instance_set_app(NULL) );
#else
    fields[NATIVE_FIELD_LANG_CLASS_INSTANCE] = value_create_int( (int32_t)instance_set_app(NULL) );
#endif

	return class_object;
}

