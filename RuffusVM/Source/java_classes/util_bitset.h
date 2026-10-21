#ifndef NATIVE_UTIL_BITSET_H
#define NATIVE_UTIL_BITSET_H

#ifdef	__cplusplus
extern "C" {
#endif

///////////////////////////////////////////////////////////////////////////

#include "datatypes.h"

///////////////////////////////////////////////////////////////////////////

// Class field implementation: UTIL_BITSET_ENUM
enum
{
    NATIVE_FIELD_UTIL_BITSET_DUMMY,
    NATIVE_UTIL_BITSET_TOTAL_FIELDS
};

enum
{

    NATIVE_UTIL_BITSET_INIT,                                                     // BitSet()
    NATIVE_UTIL_BITSET_INIT_INT,                                                 // BitSet(int nbits)

    NATIVE_UTIL_BITSET_AND_BITSET,                                               // void and(BitSet set)
    NATIVE_UTIL_BITSET_ANDNOT_BITSET,                                            // void andNot(BitSet set)
    NATIVE_UTIL_BITSET_CARDINALITY,                                              // int cardinality()
    NATIVE_UTIL_BITSET_CLEAR,                                                    // void clear()
    NATIVE_UTIL_BITSET_CLEAR_INT,                                                // void clear(int bitIndex)
    NATIVE_UTIL_BITSET_CLEAR_INT_INT,                                            // void clear(int fromIndex, int toIndex)
    NATIVE_UTIL_BITSET_CLONE,                                                    // Object clone()
    NATIVE_UTIL_BITSET_EQUALS_OBJECT,                                            // boolean equals(Object obj)
    NATIVE_UTIL_BITSET_FLIP_INT,                                                 // void flip(int bitIndex)
    NATIVE_UTIL_BITSET_FLIP_INT_INT,                                             // void flip(int fromIndex, int toIndex)
    NATIVE_UTIL_BITSET_GET_INT,                                                  // boolean get(int bitIndex)
    NATIVE_UTIL_BITSET_GET_INT_INT,                                              // BitSet get(int fromIndex, int toIndex)
    NATIVE_UTIL_BITSET_HASHCODE,                                                 // int hashCode()
    NATIVE_UTIL_BITSET_INTERSECTS_BITSET,                                        // boolean intersects(BitSet set)
    NATIVE_UTIL_BITSET_ISEMPTY,                                                  // boolean isEmpty()
    NATIVE_UTIL_BITSET_LENGTH,                                                   // int length()
    NATIVE_UTIL_BITSET_NEXTCLEARBIT_INT,                                         // int nextClearBit(int fromIndex)
    NATIVE_UTIL_BITSET_NEXTSETBIT_INT,                                           // int nextSetBit(int fromIndex)
    NATIVE_UTIL_BITSET_OR_BITSET,                                                // void or(BitSet set)
    NATIVE_UTIL_BITSET_SET_INT,                                                  // void set(int bitIndex)
    NATIVE_UTIL_BITSET_SET_INT_BOOLEAN,                                          // void set(int bitIndex, boolean value)
    NATIVE_UTIL_BITSET_SET_INT_INT,                                              // void set(int fromIndex, int toIndex)
    NATIVE_UTIL_BITSET_SET_INT_INT_BOOLEAN,                                      // void set(int fromIndex, int toIndex, boolean value)
    NATIVE_UTIL_BITSET_SIZE,                                                     // int size()
    NATIVE_UTIL_BITSET_TOSTRING,                                                 // String toString()
    NATIVE_UTIL_BITSET_XOR_BITSET,                                               // void xor(BitSet set)
};

///////////////////////////////////////////////////////////////////////////

object_t native_util_bitset_new( void );
void native_util_bitset_get_field(uint16_t mref);
void native_util_bitset_invoke(uint16_t mref);

///////////////////////////////////////////////////////////////////////////

#ifdef	__cplusplus
}
#endif

#endif // NATIVE_UTIL_BITSET_H


