#include "util_bitset.h"
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

// use New method implementation to hold a method
// use New implementation to mark start block
// use End new implementation to mark end block to keep

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////

object_t native_util_bitset_new( void )
{
    return( object_create( GET_CLASS_REF( NATIVE_CLASS_UTIL_BITSET ), T_CLASS, NATIVE_UTIL_BITSET_TOTAL_FIELDS ) );
}

///////////////////////////////////////////////////////////////////////////

void native_method_util_bitset_init( void )
{
    // BitSet()
    // Creates a new bit set. 
    // Implementation code: B94D244C
    object_t object;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_util_bitset_init_int( void )
{
    // BitSet(int nbits)
    // Creates a bit set whose initial size is large enough to 
    // explicitly represent bits with indices in the range 0 through 
    // nbits-1. 
    // Implementation code: 15AD3FB3
    object_t int_nbits;
    object_t object;

    int_nbits = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

///////////////////////////////////////////////////////////////////////////

void native_method_util_bitset_and_bitset( void )
{
    // void and(BitSet set)
    // Performs a logical AND of this target bit set with the argument 
    // bit set. 
    // Implementation code: 38D98EE6
    object_t bitset_set;
    object_t object;

    bitset_set = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_util_bitset_andnot_bitset( void )
{
    // void andNot(BitSet set)
    // Clears all of the bits in this BitSet whose corresponding 
    // bit is set in the specified BitSet. 
    // Implementation code: B0D1202B
    object_t bitset_set;
    object_t object;

    bitset_set = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_util_bitset_cardinality( void )
{
    // int cardinality()
    // Returns the number of bits set to true in this BitSet. 
    // Implementation code: E49531A5
    object_t object;
    int32_t ret_value = 0;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push( value_create( &ret_value, T_INT ) );
}

void native_method_util_bitset_clear( void )
{
    // void clear()
    // Sets all of the bits in this BitSet to false. 
    // Implementation code: FA032398
    object_t object;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_util_bitset_clear_int( void )
{
    // void clear(int bitIndex)
    // Sets the bit specified by the index to false. 
    // Implementation code: E8890F7C
    object_t int_bitindex;
    object_t object;

    int_bitindex = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_util_bitset_clear_int_int( void )
{
    // void clear(int fromIndex, int toIndex)
    // Sets the bits from the specified fromIndex (inclusive) to 
    // the specified toIndex (exclusive) to false. 
    // Implementation code: E62A309E
    object_t int_fromindex;
    object_t int_toindex;
    object_t object;

    int_toindex = stack_pop();
    int_fromindex = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_util_bitset_clone( void )
{
    // Object clone()
    // Cloning this BitSet produces a new BitSet that is equal 
    // to it. 
    // Implementation code: E73FD996
    object_t object;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: Object
    stack_push( 0 );
}

void native_method_util_bitset_equals_object( void )
{
    // boolean equals(Object obj)
    // Compares this object against the specified object. 
    // Implementation code: 4048E6D8
    object_t object_obj;
    object_t object;
    bool_t ret_value = 0;

    object_obj = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: boolean
    stack_push( value_create( &ret_value, T_BOOLEAN ) );
}

void native_method_util_bitset_flip_int( void )
{
    // void flip(int bitIndex)
    // Sets the bit at the specified index to the complement of 
    // its current value. 
    // Implementation code: 635DA504
    object_t int_bitindex;
    object_t object;

    int_bitindex = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_util_bitset_flip_int_int( void )
{
    // void flip(int fromIndex, int toIndex)
    // Sets each bit from the specified fromIndex (inclusive) to 
    // the specified toIndex (exclusive) to the complement of its 
    // current value. 
    // Implementation code: 5D56588E
    object_t int_fromindex;
    object_t int_toindex;
    object_t object;

    int_toindex = stack_pop();
    int_fromindex = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_util_bitset_get_int( void )
{
    // boolean get(int bitIndex)
    // Returns the value of the bit with the specified index. 
    // Implementation code: 6E04C64A
    object_t int_bitindex;
    object_t object;
    bool_t ret_value = 0;

    int_bitindex = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: boolean
    stack_push( value_create( &ret_value, T_BOOLEAN ) );
}

void native_method_util_bitset_get_int_int( void )
{
    // BitSet get(int fromIndex, int toIndex)
    // Returns a new BitSet composed of bits from this BitSet from 
    // fromIndex (inclusive) to toIndex (exclusive). 
    // Implementation code: 6C0B3D89
    object_t int_fromindex;
    object_t int_toindex;
    object_t object;

    int_toindex = stack_pop();
    int_fromindex = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: BitSet
    stack_push( 0 );
}

void native_method_util_bitset_hashcode( void )
{
    // int hashCode()
    // Returns a hash code value for this bit set. 
    // Implementation code: 9F444EDC
    object_t object;
    int32_t ret_value = 0;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push( value_create( &ret_value, T_INT ) );
}

void native_method_util_bitset_intersects_bitset( void )
{
    // boolean intersects(BitSet set)
    // Returns true if the specified BitSet has any bits set to 
    // true that are also set to true in this BitSet. 
    // Implementation code: 5DAED9F2
    object_t bitset_set;
    object_t object;
    bool_t ret_value = 0;

    bitset_set = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: boolean
    stack_push( value_create( &ret_value, T_BOOLEAN ) );
}

void native_method_util_bitset_isempty( void )
{
    // boolean isEmpty()
    // Returns true if this BitSet contains no bits that are set 
    // to true. 
    // Implementation code: 5768DF4A
    object_t object;
    bool_t ret_value = 0;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: boolean
    stack_push( value_create( &ret_value, T_BOOLEAN ) );
}

void native_method_util_bitset_length( void )
{
    // int length()
    // Returns the "logical size" of this BitSet: the index of 
    // the highest set bit in the BitSet plus one. 
    // Implementation code: 5D3AE652
    object_t object;
    int32_t ret_value = 0;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push( value_create( &ret_value, T_INT ) );
}

void native_method_util_bitset_nextclearbit_int( void )
{
    // int nextClearBit(int fromIndex)
    // Returns the index of the first bit that is set to false 
    // that occurs on or after the specified starting index. 
    // Implementation code: FD83586B
    object_t int_fromindex;
    object_t object;
    int32_t ret_value = 0;

    int_fromindex = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push( value_create( &ret_value, T_INT ) );
}

void native_method_util_bitset_nextsetbit_int( void )
{
    // int nextSetBit(int fromIndex)
    // Returns the index of the first bit that is set to true that 
    // occurs on or after the specified starting index. 
    // Implementation code: 56E8D88F
    object_t int_fromindex;
    object_t object;
    int32_t ret_value = 0;

    int_fromindex = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push( value_create( &ret_value, T_INT ) );
}

void native_method_util_bitset_or_bitset( void )
{
    // void or(BitSet set)
    // Performs a logical OR of this bit set with the bit set argument. 
    // Implementation code: 9275EAB4
    object_t bitset_set;
    object_t object;

    bitset_set = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_util_bitset_set_int( void )
{
    // void set(int bitIndex)
    // Sets the bit at the specified index to true. 
    // Implementation code: 8FA5F3DA
    object_t int_bitindex;
    object_t object;

    int_bitindex = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_util_bitset_set_int_boolean( void )
{
    // void set(int bitIndex, boolean value)
    // Sets the bit at the specified index to the specified value. 
    // Implementation code: AAD656FD
    object_t int_bitindex;
    object_t boolean_value;
    object_t object;

    boolean_value = stack_pop();
    int_bitindex = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_util_bitset_set_int_int( void )
{
    // void set(int fromIndex, int toIndex)
    // Sets the bits from the specified fromIndex (inclusive) to 
    // the specified toIndex (exclusive) to true. 
    // Implementation code: D02323B8
    object_t int_fromindex;
    object_t int_toindex;
    object_t object;

    int_toindex = stack_pop();
    int_fromindex = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_util_bitset_set_int_int_boolean( void )
{
    // void set(int fromIndex, int toIndex, boolean value)
    // Sets the bits from the specified fromIndex (inclusive) to 
    // the specified toIndex (exclusive) to the specified value. 
    // Implementation code: 11950F0D
    object_t int_fromindex;
    object_t int_toindex;
    object_t boolean_value;
    object_t object;

    boolean_value = stack_pop();
    int_toindex = stack_pop();
    int_fromindex = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_util_bitset_size( void )
{
    // int size()
    // Returns the number of bits of space actually in use by this 
    // BitSet to represent bit values. 
    // Implementation code: 9FE22943
    object_t object;
    int32_t ret_value = 0;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push( value_create( &ret_value, T_INT ) );
}

void native_method_util_bitset_tostring( void )
{
    // String toString()
    // Returns a string representation of this bit set. 
    // Implementation code: 98CE5492
    object_t object;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: String
    stack_push( strings_create( "" ) );
}

void native_method_util_bitset_xor_bitset( void )
{
    // void xor(BitSet set)
    // Performs a logical XOR of this bit set with the bit set 
    // argument. 
    // Implementation code: F3763059
    object_t bitset_set;
    object_t object;

    bitset_set = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

///////////////////////////////////////////////////////////////////////////

void native_util_bitset_invoke(uint16_t mref)
{
    switch( mref )
    {
        case NATIVE_UTIL_BITSET_INIT:
            native_method_util_bitset_init();
            break;

        case NATIVE_UTIL_BITSET_INIT_INT:
            native_method_util_bitset_init_int();
            break;

        case NATIVE_UTIL_BITSET_AND_BITSET:
            native_method_util_bitset_and_bitset();
            break;

        case NATIVE_UTIL_BITSET_ANDNOT_BITSET:
            native_method_util_bitset_andnot_bitset();
            break;

        case NATIVE_UTIL_BITSET_CARDINALITY:
            native_method_util_bitset_cardinality();
            break;

        case NATIVE_UTIL_BITSET_CLEAR:
            native_method_util_bitset_clear();
            break;

        case NATIVE_UTIL_BITSET_CLEAR_INT:
            native_method_util_bitset_clear_int();
            break;

        case NATIVE_UTIL_BITSET_CLEAR_INT_INT:
            native_method_util_bitset_clear_int_int();
            break;

        case NATIVE_UTIL_BITSET_CLONE:
            native_method_util_bitset_clone();
            break;

        case NATIVE_UTIL_BITSET_EQUALS_OBJECT:
            native_method_util_bitset_equals_object();
            break;

        case NATIVE_UTIL_BITSET_FLIP_INT:
            native_method_util_bitset_flip_int();
            break;

        case NATIVE_UTIL_BITSET_FLIP_INT_INT:
            native_method_util_bitset_flip_int_int();
            break;

        case NATIVE_UTIL_BITSET_GET_INT:
            native_method_util_bitset_get_int();
            break;

        case NATIVE_UTIL_BITSET_GET_INT_INT:
            native_method_util_bitset_get_int_int();
            break;

        case NATIVE_UTIL_BITSET_HASHCODE:
            native_method_util_bitset_hashcode();
            break;

        case NATIVE_UTIL_BITSET_INTERSECTS_BITSET:
            native_method_util_bitset_intersects_bitset();
            break;

        case NATIVE_UTIL_BITSET_ISEMPTY:
            native_method_util_bitset_isempty();
            break;

        case NATIVE_UTIL_BITSET_LENGTH:
            native_method_util_bitset_length();
            break;

        case NATIVE_UTIL_BITSET_NEXTCLEARBIT_INT:
            native_method_util_bitset_nextclearbit_int();
            break;

        case NATIVE_UTIL_BITSET_NEXTSETBIT_INT:
            native_method_util_bitset_nextsetbit_int();
            break;

        case NATIVE_UTIL_BITSET_OR_BITSET:
            native_method_util_bitset_or_bitset();
            break;

        case NATIVE_UTIL_BITSET_SET_INT:
            native_method_util_bitset_set_int();
            break;

        case NATIVE_UTIL_BITSET_SET_INT_BOOLEAN:
            native_method_util_bitset_set_int_boolean();
            break;

        case NATIVE_UTIL_BITSET_SET_INT_INT:
            native_method_util_bitset_set_int_int();
            break;

        case NATIVE_UTIL_BITSET_SET_INT_INT_BOOLEAN:
            native_method_util_bitset_set_int_int_boolean();
            break;

        case NATIVE_UTIL_BITSET_SIZE:
            native_method_util_bitset_size();
            break;

        case NATIVE_UTIL_BITSET_TOSTRING:
            native_method_util_bitset_tostring();
            break;

        case NATIVE_UTIL_BITSET_XOR_BITSET:
            native_method_util_bitset_xor_bitset();
            break;

        default:
            exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
            break;

    }
}


