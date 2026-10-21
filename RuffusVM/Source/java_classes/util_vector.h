#ifndef NATIVE_UTIL_VECTOR_H
#define NATIVE_UTIL_VECTOR_H

#ifdef	__cplusplus
extern "C" {
#endif

///////////////////////////////////////////////////////////////////////////

#include "datatypes.h"

///////////////////////////////////////////////////////////////////////////

// Class field implementation: UTIL_VECTOR_ENUM
enum
{
    NATIVE_FIELD_UTIL_VECTOR_ARRAY,
    NATIVE_FIELD_UTIL_VECTOR_DATA,
    NATIVE_UTIL_VECTOR_TOTAL_FIELDS
};

enum
{
    NATIVE_FIELD_UTIL_VECTOR_CAPACITYINCREMENT,                                  // protected  int capacityIncrement
    NATIVE_FIELD_UTIL_VECTOR_ELEMENTCOUNT,                                       // protected  int elementCount
    NATIVE_FIELD_UTIL_VECTOR_ELEMENTDATA,                                        // protected  Object[] elementData
};

enum
{
    NATIVE_UTIL_VECTOR_INIT,                                                     // Vector()
    NATIVE_UTIL_VECTOR_INIT_COLLECTION,                                          // Vector(Collection c)
    NATIVE_UTIL_VECTOR_INIT_INT,                                                 // Vector(int initialCapacity)
    NATIVE_UTIL_VECTOR_INIT_INT_INT,                                             // Vector(int initialCapacity, int capacityIncrement)

    NATIVE_UTIL_VECTOR_ADD_INT_OBJECT,                                           // void add(int index, Object element)
    NATIVE_UTIL_VECTOR_ADD_OBJECT,                                               // boolean add(Object o)
    NATIVE_UTIL_VECTOR_ADDALL_COLLECTION,                                        // boolean addAll(Collection c)
    NATIVE_UTIL_VECTOR_ADDALL_INT_COLLECTION,                                    // boolean addAll(int index, Collection c)
    NATIVE_UTIL_VECTOR_ADDELEMENT_OBJECT,                                        // void addElement(Object obj)
    NATIVE_UTIL_VECTOR_CAPACITY,                                                 // int capacity()
    NATIVE_UTIL_VECTOR_CLEAR,                                                    // void clear()
    NATIVE_UTIL_VECTOR_CLONE,                                                    // Object clone()
    NATIVE_UTIL_VECTOR_CONTAINS_OBJECT,                                          // boolean contains(Object elem)
    NATIVE_UTIL_VECTOR_CONTAINSALL_COLLECTION,                                   // boolean containsAll(Collection c)
    NATIVE_UTIL_VECTOR_COPYINTO_ARRAY_OBJECT,                                    // void copyInto(Object[] anArray)
    NATIVE_UTIL_VECTOR_ELEMENTAT_INT,                                            // Object elementAt(int index)
    NATIVE_UTIL_VECTOR_ELEMENTS,                                                 // Enumeration elements()
    NATIVE_UTIL_VECTOR_ENSURECAPACITY_INT,                                       // void ensureCapacity(int minCapacity)
    NATIVE_UTIL_VECTOR_EQUALS_OBJECT,                                            // boolean equals(Object o)
    NATIVE_UTIL_VECTOR_FIRSTELEMENT,                                             // Object firstElement()
    NATIVE_UTIL_VECTOR_GET_INT,                                                  // Object get(int index)
    NATIVE_UTIL_VECTOR_HASHCODE,                                                 // int hashCode()
    NATIVE_UTIL_VECTOR_INDEXOF_OBJECT,                                           // int indexOf(Object elem)
    NATIVE_UTIL_VECTOR_INDEXOF_OBJECT_INT,                                       // int indexOf(Object elem, int index)
    NATIVE_UTIL_VECTOR_INSERTELEMENTAT_OBJECT_INT,                               // void insertElementAt(Object obj, int index)
    NATIVE_UTIL_VECTOR_ISEMPTY,                                                  // boolean isEmpty()
    NATIVE_UTIL_VECTOR_LASTELEMENT,                                              // Object lastElement()
    NATIVE_UTIL_VECTOR_LASTINDEXOF_OBJECT,                                       // int lastIndexOf(Object elem)
    NATIVE_UTIL_VECTOR_LASTINDEXOF_OBJECT_INT,                                   // int lastIndexOf(Object elem, int index)
    NATIVE_UTIL_VECTOR_REMOVE_INT,                                               // Object remove(int index)
    NATIVE_UTIL_VECTOR_REMOVE_OBJECT,                                            // boolean remove(Object o)
    NATIVE_UTIL_VECTOR_REMOVEALL_COLLECTION,                                     // boolean removeAll(Collection c)
    NATIVE_UTIL_VECTOR_REMOVEALLELEMENTS,                                        // void removeAllElements()
    NATIVE_UTIL_VECTOR_REMOVEELEMENT_OBJECT,                                     // boolean removeElement(Object obj)
    NATIVE_UTIL_VECTOR_REMOVEELEMENTAT_INT,                                      // void removeElementAt(int index)
    NATIVE_UTIL_VECTOR_REMOVERANGE_INT_INT,                                      // protected  void removeRange(int fromIndex, int toIndex)
    NATIVE_UTIL_VECTOR_RETAINALL_COLLECTION,                                     // boolean retainAll(Collection c)
    NATIVE_UTIL_VECTOR_SET_INT_OBJECT,                                           // Object set(int index, Object element)
    NATIVE_UTIL_VECTOR_SETELEMENTAT_OBJECT_INT,                                  // void setElementAt(Object obj, int index)
    NATIVE_UTIL_VECTOR_SETSIZE_INT,                                              // void setSize(int newSize)
    NATIVE_UTIL_VECTOR_SIZE,                                                     // int size()
    NATIVE_UTIL_VECTOR_SUBLIST_INT_INT,                                          // List subList(int fromIndex, int toIndex)
    NATIVE_UTIL_VECTOR_TOARRAY,                                                  // Object[] toArray()
    NATIVE_UTIL_VECTOR_TOARRAY_ARRAY_OBJECT,                                     // Object[] toArray(Object[] a)
    NATIVE_UTIL_VECTOR_TOSTRING,                                                 // String toString()
    NATIVE_UTIL_VECTOR_TRIMTOSIZE,                                               // void trimToSize()
};

///////////////////////////////////////////////////////////////////////////

object_t native_util_vector_new( void );
void native_util_vector_get_field(uint16_t mref);
void native_util_vector_invoke(uint16_t mref);

///////////////////////////////////////////////////////////////////////////

#ifdef	__cplusplus
}
#endif

#endif // NATIVE_UTIL_VECTOR_H


