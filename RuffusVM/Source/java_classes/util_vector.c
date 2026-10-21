#include "util_vector.h"
#include "heap.h"
#include "application.h"
#include "threads.h"
#include "exceptions.h"
#include "native.h"
#include "objects.h"
#include "stack.h"
#include "value_type.h"
#include "strings.h"
#include "util_vector_lib.h"
#include "arrays_type.h"

///////////////////////////////////////////////////////////////////////////

// use New method implementation to hold a method
// use New implementation to mark start block
// use End new implementation to mark end block to keep

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////

// protected  int capacityIncrement
#define NATIVE_FIELD_VALUE_UTIL_VECTOR_CAPACITYINCREMENT                         0

// protected  int elementCount
#define NATIVE_FIELD_VALUE_UTIL_VECTOR_ELEMENTCOUNT                              1

// protected  Object[] elementData
#define NATIVE_FIELD_VALUE_UTIL_VECTOR_ELEMENTDATA                               2

///////////////////////////////////////////////////////////////////////////

object_t native_util_vector_new( void )
{
    return( object_create( GET_CLASS_REF( NATIVE_CLASS_UTIL_VECTOR ), T_CLASS, NATIVE_UTIL_VECTOR_TOTAL_FIELDS ) );
}

///////////////////////////////////////////////////////////////////////////

void native_method_util_vector_init( void )
{
    // Vector()
    // Constructs an empty vector so that its internal data array 
    // has size 10 and its standard capacity increment is zero. 
    // Implementation code: F73ED720
    object_t object;

    object = stack_peek(0);

    // put your code here
	native_vector_init_base( object, VECTOR_DEFAULT_SIZE, 0 );

	stack_remove(1);
}

void native_method_util_vector_init_collection( void )
{
    // Vector(Collection c)
    // Constructs a vector containing the elements of the specified 
    // collection, in the order they are returned by the collection's 
    // iterator. 
    // Implementation code: 2C0FF067
    object_t collection_c;
    object_t object;

    collection_c = stack_peek(0);
    object = stack_peek(1);

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

	stack_remove(2);
}

void native_method_util_vector_init_int( void )
{
    // Vector(int initialCapacity)
    // Constructs an empty vector with the specified initial capacity 
    // and with its capacity increment equal to zero. 
    // Implementation code: B8EDD492
    object_t int_initialcapacity;
    object_t object;

    int_initialcapacity = stack_peek(0);
    object = stack_peek(1);

    // put your code here
    native_vector_init_base( object, value_get_int( int_initialcapacity ), VECTOR_DEFAULT_SIZE );

	stack_remove(2);
}

void native_method_util_vector_init_int_int( void )
{
    // Vector(int initialCapacity, int capacityIncrement)
    // Constructs an empty vector with the specified initial capacity 
    // and capacity increment. 
    // Implementation code: 7B611935
    object_t int_initialcapacity;
    object_t int_capacityincrement;
    object_t object;

    int_capacityincrement = stack_peek(0);
    int_initialcapacity = stack_peek(1);
    object = stack_peek(2);

    // put your code here
    native_vector_init_base( object, value_get_int( int_initialcapacity ), value_get_int( int_capacityincrement ) );

	stack_remove(3);
}

///////////////////////////////////////////////////////////////////////////

void native_method_util_vector_add_int_object( void )
{
    // void add(int index, Object element)
    // Inserts the specified element at the specified position 
    // in this Vector. 
    // Implementation code: FBBC0638
    object_t int_index;
    object_t object_element;
    object_t object;

    object_element = stack_peek(0);
    int_index = stack_peek(1);
    object = stack_peek(2);

    // put your code here
	native_vector_add_base( object, value_get_int( int_index ), object_element );

	stack_remove(3);
}

void native_method_util_vector_add_object( void )
{
    // boolean add(Object o)
    // Appends the specified element to the end of this Vector. 
    // Implementation code: 20B077AB
    object_t object_o;
    object_t object;
	object_t ret_obj;
    bool_t ret_value = 0;

    object_o = stack_peek(0);
    object = stack_peek(1);

    // return type: boolean
	native_vector_add_base( object, NEG_U32, object_o );

    // return type: boolean
	ret_obj = value_create( &ret_value, T_BOOLEAN );
	stack_remove(2);

	stack_push( ret_obj );
}

void native_method_util_vector_addall_collection( void )
{
    // boolean addAll(Collection c)
    // Appends all of the elements in the specified Collection 
    // to the end of this Vector, in the order that they are returned 
    // by the specified Collection's Iterator. 
    // Implementation code: 10B8BF69
    object_t collection_c;
    object_t object;
    bool_t ret_value = 0;

    collection_c = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: boolean
    stack_push( value_create( &ret_value, T_BOOLEAN ) );
}

void native_method_util_vector_addall_int_collection( void )
{
    // boolean addAll(int index, Collection c)
    // Inserts all of the elements in in the specified Collection 
    // into this Vector at the specified position. 
    // Implementation code: A14FBC82
    object_t int_index;
    object_t collection_c;
    object_t object;
    bool_t ret_value = 0;

    collection_c = stack_pop();
    int_index = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: boolean
    stack_push( value_create( &ret_value, T_BOOLEAN ) );
}

void native_method_util_vector_addelement_object( void )
{
    // void addElement(Object obj)
    // Adds the specified component to the end of this vector, 
    // increasing its size by one. 
    // Implementation code: 8DCE6219
    object_t object_obj;
    object_t object;

    object_obj = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_util_vector_capacity( void )
{
    // int capacity()
    // Returns the current capacity of this vector. 
    // Implementation code: 336294B8
    object_t object;
	object_t ret_obj;

    object = stack_peek(0);

	ret_obj = value_create_int( native_vector_get_data( object )->count );
	stack_remove(1);

	stack_push( ret_obj );
}

void native_method_util_vector_clear( void )
{
    // void clear()
    // Removes all of the elements from this Vector. 
    // Implementation code: 2102C5FD
    object_t object;
	object_t * fields;
	vector_t * data;

    object = stack_peek(0);

	// get class instance
	fields = object_get_fields_ptr( object );
	object_create_extension( object, sizeof( vector_t ) );
	data = ( vector_t * )object_get_extension( object );

	// delete array
	array_delete( fields[ NATIVE_FIELD_UTIL_VECTOR_ARRAY ], 0, NEG_U32 );
	array_insert( fields[ NATIVE_FIELD_UTIL_VECTOR_ARRAY ], 0, NULL, 0, data->min_size );

	data->count = 0;
	data->curr_size = data->min_size;
	data->mode = 0;

	stack_remove(1);
}

void native_method_util_vector_clone( void )
{
    // Object clone()
    // Returns a clone of this vector. 
    // Implementation code: 2679FF4B
    object_t object;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: Object
    stack_push( 0 );
}

void native_method_util_vector_contains_object( void )
{
    // boolean contains(Object elem)
    // Tests if the specified object is a component in this vector. 
    // Implementation code: 9592E451
    object_t object_elem;
    object_t object;
	object_t ret_obj;
	object_t * fields;
	vector_t * data;
    bool_t ret_value = 0;

    object_elem = stack_peek(0);
    object = stack_peek(1);

	// get class instance
	fields = object_get_fields_ptr( object );
	data = ( vector_t * )object_get_extension( object );

	// locate element
	ret_value = native_vector_array_contains( fields[ NATIVE_FIELD_UTIL_VECTOR_ARRAY ], object_elem );
	ret_obj = value_create_boolean( ret_value );
	stack_remove(2);

	stack_push( ret_obj );
}

void native_method_util_vector_containsall_collection( void )
{
    // boolean containsAll(Collection c)
    // Returns true if this Vector contains all of the elements 
    // in the specified Collection. 
    // Implementation code: 8899E623
    object_t collection_c;
    object_t object;
	object_t ret_obj;
    bool_t ret_value = 0;

    collection_c = stack_peek(0);
    object = stack_peek(1);

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: boolean
	ret_obj = value_create_boolean( ret_value );
	stack_remove(2);

	stack_push( ret_obj );
}

void native_method_util_vector_copyinto_array_object( void )
{
    // void copyInto(Object[] anArray)
    // Copies the components of this vector into the specified 
    // array. 
    // Implementation code: 5828E073
	uint8_t mode;
	uint32_t cref_vector;
	vector_t * data;
    object_t object_array_anarray;
    object_t object;
	object_t * fields;
	object_t * _array_ptr;

    object_array_anarray = stack_peek(0);
    object = stack_peek(1);

	// get class instance
	fields = object_get_fields_ptr( object );
	data = ( vector_t * )object_get_extension( object );

	// get array information
	mode = ( uint8_t )array_get_type( object_array_anarray );

	_array_ptr = ( object_t * )object_get_ptr( object_array_anarray );

	// is it an array of classes?
	if( mode == T_CLASS )
	{
		cref_vector = object_get_class_ref( object );
	}

	// must be same type
	if( GET_CLASS_INDEX( cref_vector ) != data->mode )
	{
		exception_new( NATIVE_CLASS_THROW_LANG_ILLEGALARGUMENTEXCEPTION, msg_throw_invalid_ref );
		return;
	}

	// check if the array has got enough capacity
	if( array_get_capacity( object_array_anarray ) < data->count )
	{
		exception_new( NATIVE_CLASS_THROW_LANG_ARRAYINDEXOUTOFBOUNDSEXCEPTION, msg_throw_out_of_bounds );
		return;
	}

	// place data into the array
	array_get( fields[ NATIVE_FIELD_UTIL_VECTOR_ARRAY ], 0, data->count, _array_ptr );
	stack_remove(2);
}

void native_method_util_vector_elementat_int( void )
{
    // Object elementAt(int index)
    // Returns the component at the specified index. 
    // Implementation code: 9781896E
    object_t int_index;
    object_t object;
	object_t ret_obj;

    int_index = stack_peek(0);
    object = object_get_fields_ptr( stack_peek(1) )[ NATIVE_FIELD_UTIL_VECTOR_ARRAY ];

    // put your code here
	array_get( object, value_get_int( int_index ), 1, &ret_obj );

    // return type: Object
	stack_remove(2);
    stack_push( ret_obj );
}

void native_method_util_vector_elements( void )
{
    // Enumeration elements()
    // Returns an enumeration of the components of this vector. 
    // Implementation code: 98DF1A9A
    object_t object;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: Enumeration
    stack_push( 0 );
}

void native_method_util_vector_ensurecapacity_int( void )
{
    // void ensureCapacity(int minCapacity)
    // Increases the capacity of this vector, if necessary, to 
    // ensure that it can hold at least the number of components 
    // specified by the minimum capacity argument. 
    // Implementation code: 3682B03D
    object_t int_mincapacity;

    int_mincapacity = stack_peek(0);

    // put your code here
    native_vector_get_data(stack_peek(1))->min_size = value_get_int( int_mincapacity );
	stack_remove(2);
}

void native_method_util_vector_equals_object( void )
{
    // boolean equals(Object o)
    // Compares the specified Object with this Vector for equality. 
    // Implementation code: 700E066E
    object_t object_o;
    object_t object;
    bool_t ret_value = 0;

    object_o = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: boolean
    stack_push( value_create( &ret_value, T_BOOLEAN ) );
}

void native_method_util_vector_firstelement( void )
{
    // Object firstElement()
    // Returns the first component (the item at index 0) of this 
    // vector. 
    // Implementation code: D2FBE9BE
    object_t object;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: Object
    stack_push( 0 );
}

void native_method_util_vector_get_int( void )
{
    // Object get(int index)
    // Returns the element at the specified position in this Vector. 
    // Implementation code: 2D1CD85E
    object_t int_index;
    object_t object;

    int_index = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: Object
    stack_push( 0 );
}

void native_method_util_vector_hashcode( void )
{
    // int hashCode()
    // Returns the hash code value for this Vector. 
    // Implementation code: 04881AF6
    object_t object;
    int32_t ret_value = 0;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push( value_create( &ret_value, T_INT ) );
}

void native_method_util_vector_indexof_object( void )
{
    // int indexOf(Object elem)
    // Searches for the first occurence of the given argument, 
    // testing for equality using the equals method. 
    // Implementation code: BB3F9CD8
    object_t object_elem;
    object_t object;
    int32_t ret_value = 0;

    object_elem = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push( value_create( &ret_value, T_INT ) );
}

void native_method_util_vector_indexof_object_int( void )
{
    // int indexOf(Object elem, int index)
    // Searches for the first occurence of the given argument, 
    // beginning the search at index, and testing for equality 
    // using the equals method. 
    // Implementation code: 28671D33
    object_t object_elem;
    object_t int_index;
    object_t object;
    int32_t ret_value = 0;

    int_index = stack_pop();
    object_elem = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push( value_create( &ret_value, T_INT ) );
}

void native_method_util_vector_insertelementat_object_int( void )
{
    // void insertElementAt(Object obj, int index)
    // Inserts the specified object as a component in this vector 
    // at the specified index. 
    // Implementation code: D4C4F10F
    object_t object_obj;
    object_t int_index;
    object_t object;

    int_index = stack_pop();
    object_obj = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_util_vector_isempty( void )
{
    // boolean isEmpty()
    // Tests if this vector has no components. 
    // Implementation code: F7395A31
    object_t object;
    bool_t ret_value = 0;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: boolean
    stack_push( value_create( &ret_value, T_BOOLEAN ) );
}

void native_method_util_vector_lastelement( void )
{
    // Object lastElement()
    // Returns the last component of the vector. 
    // Implementation code: EFA81EDC
    object_t object;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: Object
    stack_push( 0 );
}

void native_method_util_vector_lastindexof_object( void )
{
    // int lastIndexOf(Object elem)
    // Returns the index of the last occurrence of the specified 
    // object in this vector. 
    // Implementation code: 9972BD0E
    object_t object_elem;
    object_t object;
    int32_t ret_value = 0;

    object_elem = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push( value_create( &ret_value, T_INT ) );
}

void native_method_util_vector_lastindexof_object_int( void )
{
    // int lastIndexOf(Object elem, int index)
    // Searches backwards for the specified object, starting from 
    // the specified index, and returns an index to it. 
    // Implementation code: C48A5D35
    object_t object_elem;
    object_t int_index;
    object_t object;
    int32_t ret_value = 0;

    int_index = stack_pop();
    object_elem = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: int
    stack_push( value_create( &ret_value, T_INT ) );
}

void native_method_util_vector_remove_int( void )
{
    // Object remove(int index)
    // Removes the element at the specified position in this Vector. 
    // Implementation code: 75F1F004
    object_t int_index;
    object_t object;

    int_index = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: Object
    stack_push( 0 );
}

void native_method_util_vector_remove_object( void )
{
    // boolean remove(Object o)
    // Removes the first occurrence of the specified element in 
    // this Vector If the Vector does not contain the element, 
    // it is unchanged. 
    // Implementation code: F72E7FFC
    object_t object_o;
    object_t object;
    bool_t ret_value = 0;

    object_o = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: boolean
    stack_push( value_create( &ret_value, T_BOOLEAN ) );
}

void native_method_util_vector_removeall_collection( void )
{
    // boolean removeAll(Collection c)
    // Removes from this Vector all of its elements that are contained 
    // in the specified Collection. 
    // Implementation code: 37B2FD80
    object_t collection_c;
    object_t object;
    bool_t ret_value = 0;

    collection_c = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: boolean
    stack_push( value_create( &ret_value, T_BOOLEAN ) );
}

void native_method_util_vector_removeallelements( void )
{
    // void removeAllElements()
    // Removes all components from this vector and sets its size 
    // to zero. 
    // Implementation code: 453F1C61
    object_t object;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_util_vector_removeelement_object( void )
{
    // boolean removeElement(Object obj)
    // Removes the first (lowest-indexed) occurrence of the argument 
    // from this vector. 
    // Implementation code: E9E3C971
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

void native_method_util_vector_removeelementat_int( void )
{
    // void removeElementAt(int index)
    // Deletes the component at the specified index. 
    // Implementation code: 2AE3B935
    object_t int_index;
    object_t object;

    int_index = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_util_vector_removerange_int_int( void )
{
    // protected  void removeRange(int fromIndex, int toIndex)
    // Removes from this List all of the elements whose index is 
    // between fromIndex, inclusive and toIndex, exclusive. 
    // Implementation code: BDE4370D
    object_t int_fromindex;
    object_t int_toindex;
    object_t object;

    int_toindex = stack_pop();
    int_fromindex = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_util_vector_retainall_collection( void )
{
    // boolean retainAll(Collection c)
    // Retains only the elements in this Vector that are contained 
    // in the specified Collection. 
    // Implementation code: FDED9ED0
    object_t collection_c;
    object_t object;
    bool_t ret_value = 0;

    collection_c = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: boolean
    stack_push( value_create( &ret_value, T_BOOLEAN ) );
}

void native_method_util_vector_set_int_object( void )
{
    // Object set(int index, Object element)
    // Replaces the element at the specified position in this Vector 
    // with the specified element. 
    // Implementation code: 45CC7847
    object_t int_index;
    object_t object_element;
    object_t object;

    object_element = stack_pop();
    int_index = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: Object
    stack_push( 0 );
}

void native_method_util_vector_setelementat_object_int( void )
{
    // void setElementAt(Object obj, int index)
    // Sets the component at the specified index of this vector 
    // to be the specified object. 
    // Implementation code: DAB8DE8F
    object_t object_obj;
    object_t int_index;
    object_t object;

    int_index = stack_pop();
    object_obj = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

void native_method_util_vector_setsize_int( void )
{
    // void setSize(int newSize)
    // Sets the size of this vector. 
    // Implementation code: 0C60514E
	object_t ret_obj = value_create_int( native_vector_get_data( stack_peek(0) )->curr_size );
	stack_remove(1);
	stack_push( ret_obj );
}

void native_method_util_vector_size( void )
{
    // int size()
    // Returns the number of components in this vector. 
    // Implementation code: 0E9F7D17
	object_t ret_obj = value_create_int( native_vector_get_data( stack_peek(0) )->count );
	stack_remove(1);
	stack_push( ret_obj );
}

void native_method_util_vector_sublist_int_int( void )
{
    // List subList(int fromIndex, int toIndex)
    // Returns a view of the portion of this List between fromIndex, 
    // inclusive, and toIndex, exclusive. 
    // Implementation code: 91B6097D
    object_t int_fromindex;
    object_t int_toindex;
    object_t object;

    int_toindex = stack_pop();
    int_fromindex = stack_pop();
    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: List
    stack_push( 0 );
}

void native_method_util_vector_toarray( void )
{
    // Object[] toArray()
    // Returns an array containing all of the elements in this 
    // Vector in the correct order. 
    // Implementation code: E53E5164
    object_t object;

	object = object_get_fields_ptr( stack_peek(0) )[ NATIVE_FIELD_UTIL_VECTOR_ARRAY ];

    // return type: Object[]
	stack_remove(1);
    stack_push( object );
}

void native_method_util_vector_toarray_array_object( void )
{
    // Object[] toArray(Object[] a)
    // Returns an array containing all of the elements in this 
    // Vector in the correct order; the runtime type of the returned 
    // array is that of the specified array. 
    // Implementation code: 95ACC4FC
    object_t object_array_a;
    object_t object;

    object_array_a = stack_peek(0);
    object = stack_peek(1);

    // put your code here
    object = object_get_fields_ptr( stack_peek(0) )[ NATIVE_FIELD_UTIL_VECTOR_ARRAY ];

    // return type: Object[]
    stack_remove( 2 );
    stack_push( object );
}

void native_method_util_vector_tostring( void )
{
    // String toString()
    // Returns a string representation of this Vector, containing 
    // the String representation of each element. 
    // Implementation code: 479C2598
    object_t object;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );

    // return type: String
    stack_push( strings_create( "" ) );
}

void native_method_util_vector_trimtosize( void )
{
    // void trimToSize()
    // Trims the capacity of this vector to be the vector's current 
    // size. 
    // Implementation code: A39D3C0B
    object_t object;

    object = stack_pop();

    // put your code here
    exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
}

///////////////////////////////////////////////////////////////////////////

void native_util_vector_get_field(uint16_t mref)
{
    switch( mref )
    {
        case NATIVE_FIELD_UTIL_VECTOR_CAPACITYINCREMENT:
            // protected  int capacityIncrement
            // Implementation field read code: FIELD_READ_UTIL_VECTOR_CAPACITYINCREMENT
            stack_push( value_create_int( NATIVE_FIELD_VALUE_UTIL_VECTOR_CAPACITYINCREMENT ) );
            break;

        case NATIVE_FIELD_UTIL_VECTOR_ELEMENTCOUNT:
            // protected  int elementCount
            // Implementation field read code: FIELD_READ_UTIL_VECTOR_ELEMENTCOUNT
            stack_push( value_create_int( NATIVE_FIELD_VALUE_UTIL_VECTOR_ELEMENTCOUNT ) );
            break;

        case NATIVE_FIELD_UTIL_VECTOR_ELEMENTDATA:
            // protected  Object[] elementData
            // Implementation field read code: FIELD_READ_UTIL_VECTOR_ELEMENTDATA
            stack_push( 0 );
            break;

        default: 
            exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
            break;
    }
}

void native_util_vector_invoke(uint16_t mref)
{
    switch( mref )
    {
        case NATIVE_UTIL_VECTOR_INIT:
            native_method_util_vector_init();
            break;

        case NATIVE_UTIL_VECTOR_INIT_COLLECTION:
            native_method_util_vector_init_collection();
            break;

        case NATIVE_UTIL_VECTOR_INIT_INT:
            native_method_util_vector_init_int();
            break;

        case NATIVE_UTIL_VECTOR_INIT_INT_INT:
            native_method_util_vector_init_int_int();
            break;

        case NATIVE_UTIL_VECTOR_ADD_INT_OBJECT:
            native_method_util_vector_add_int_object();
            break;

        case NATIVE_UTIL_VECTOR_ADD_OBJECT:
            native_method_util_vector_add_object();
            break;

        case NATIVE_UTIL_VECTOR_ADDALL_COLLECTION:
            native_method_util_vector_addall_collection();
            break;

        case NATIVE_UTIL_VECTOR_ADDALL_INT_COLLECTION:
            native_method_util_vector_addall_int_collection();
            break;

        case NATIVE_UTIL_VECTOR_ADDELEMENT_OBJECT:
            native_method_util_vector_addelement_object();
            break;

        case NATIVE_UTIL_VECTOR_CAPACITY:
            native_method_util_vector_capacity();
            break;

        case NATIVE_UTIL_VECTOR_CLEAR:
            native_method_util_vector_clear();
            break;

        case NATIVE_UTIL_VECTOR_CLONE:
            native_method_util_vector_clone();
            break;

        case NATIVE_UTIL_VECTOR_CONTAINS_OBJECT:
            native_method_util_vector_contains_object();
            break;

        case NATIVE_UTIL_VECTOR_CONTAINSALL_COLLECTION:
            native_method_util_vector_containsall_collection();
            break;

        case NATIVE_UTIL_VECTOR_COPYINTO_ARRAY_OBJECT:
            native_method_util_vector_copyinto_array_object();
            break;

        case NATIVE_UTIL_VECTOR_ELEMENTAT_INT:
            native_method_util_vector_elementat_int();
            break;

        case NATIVE_UTIL_VECTOR_ELEMENTS:
            native_method_util_vector_elements();
            break;

        case NATIVE_UTIL_VECTOR_ENSURECAPACITY_INT:
            native_method_util_vector_ensurecapacity_int();
            break;

        case NATIVE_UTIL_VECTOR_EQUALS_OBJECT:
            native_method_util_vector_equals_object();
            break;

        case NATIVE_UTIL_VECTOR_FIRSTELEMENT:
            native_method_util_vector_firstelement();
            break;

        case NATIVE_UTIL_VECTOR_GET_INT:
            native_method_util_vector_get_int();
            break;

        case NATIVE_UTIL_VECTOR_HASHCODE:
            native_method_util_vector_hashcode();
            break;

        case NATIVE_UTIL_VECTOR_INDEXOF_OBJECT:
            native_method_util_vector_indexof_object();
            break;

        case NATIVE_UTIL_VECTOR_INDEXOF_OBJECT_INT:
            native_method_util_vector_indexof_object_int();
            break;

        case NATIVE_UTIL_VECTOR_INSERTELEMENTAT_OBJECT_INT:
            native_method_util_vector_insertelementat_object_int();
            break;

        case NATIVE_UTIL_VECTOR_ISEMPTY:
            native_method_util_vector_isempty();
            break;

        case NATIVE_UTIL_VECTOR_LASTELEMENT:
            native_method_util_vector_lastelement();
            break;

        case NATIVE_UTIL_VECTOR_LASTINDEXOF_OBJECT:
            native_method_util_vector_lastindexof_object();
            break;

        case NATIVE_UTIL_VECTOR_LASTINDEXOF_OBJECT_INT:
            native_method_util_vector_lastindexof_object_int();
            break;

        case NATIVE_UTIL_VECTOR_REMOVE_INT:
            native_method_util_vector_remove_int();
            break;

        case NATIVE_UTIL_VECTOR_REMOVE_OBJECT:
            native_method_util_vector_remove_object();
            break;

        case NATIVE_UTIL_VECTOR_REMOVEALL_COLLECTION:
            native_method_util_vector_removeall_collection();
            break;

        case NATIVE_UTIL_VECTOR_REMOVEALLELEMENTS:
            native_method_util_vector_removeallelements();
            break;

        case NATIVE_UTIL_VECTOR_REMOVEELEMENT_OBJECT:
            native_method_util_vector_removeelement_object();
            break;

        case NATIVE_UTIL_VECTOR_REMOVEELEMENTAT_INT:
            native_method_util_vector_removeelementat_int();
            break;

        case NATIVE_UTIL_VECTOR_REMOVERANGE_INT_INT:
            native_method_util_vector_removerange_int_int();
            break;

        case NATIVE_UTIL_VECTOR_RETAINALL_COLLECTION:
            native_method_util_vector_retainall_collection();
            break;

        case NATIVE_UTIL_VECTOR_SET_INT_OBJECT:
            native_method_util_vector_set_int_object();
            break;

        case NATIVE_UTIL_VECTOR_SETELEMENTAT_OBJECT_INT:
            native_method_util_vector_setelementat_object_int();
            break;

        case NATIVE_UTIL_VECTOR_SETSIZE_INT:
            native_method_util_vector_setsize_int();
            break;

        case NATIVE_UTIL_VECTOR_SIZE:
            native_method_util_vector_size();
            break;

        case NATIVE_UTIL_VECTOR_SUBLIST_INT_INT:
            native_method_util_vector_sublist_int_int();
            break;

        case NATIVE_UTIL_VECTOR_TOARRAY:
            native_method_util_vector_toarray();
            break;

        case NATIVE_UTIL_VECTOR_TOARRAY_ARRAY_OBJECT:
            native_method_util_vector_toarray_array_object();
            break;

        case NATIVE_UTIL_VECTOR_TOSTRING:
            native_method_util_vector_tostring();
            break;

        case NATIVE_UTIL_VECTOR_TRIMTOSIZE:
            native_method_util_vector_trimtosize();
            break;

        default:
            exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
            break;

    }
}


