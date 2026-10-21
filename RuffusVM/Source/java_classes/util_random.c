#include "util_random.h"
#include "heap.h"
#include "application.h"
#include "threads.h"
#include "exceptions.h"
#include "native.h"
#include "objects.h"
#include "stack.h"
#include "value_type.h"
#include "arrays_type.h"
#include "strings.h"

///////////////////////////////////////////////////////////////////////////

// use New method implementation to hold a method
// use New implementation to mark start block
// use End new implementation to mark end block to keep

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////

object_t native_util_random_new( void )
{
    return( object_create( GET_CLASS_REF( NATIVE_CLASS_UTIL_RANDOM ), T_CLASS, NATIVE_UTIL_RANDOM_TOTAL_FIELDS ) );
}

///////////////////////////////////////////////////////////////////////////

void native_method_util_random_init( void )
{
    // Random()
    // Creates a new random number generator. 
    // Implementation code: 181B5B11
    object_t object;
    int64_t seed_64 = 0L;

    object = stack_pop();

    // put your code here
    lang_rand_get_seed( &seed_64 );
    LANG_NUMBER_VALUE_FIELD( object ) = value_create_long( seed_64 );
}

void native_method_util_random_init_long( void )
{
    // Random(long seed)
    // Creates a new random number generator using a single long 
    // seed. 
    // Implementation code: 5066AA6D
    object_t long_seed;
    object_t object;

    long_seed = stack_pop();
    object = stack_pop();

    // put your code here
    LANG_NUMBER_VALUE_FIELD( object ) = value_create_long( value_get_long( long_seed ) );
}

///////////////////////////////////////////////////////////////////////////

void native_method_util_random_next_int( void )
{
    // protected  int next(int bits)
    // Generates the next pseudorandom number. 
    // Implementation code: B32FA60E
    object_t int_bits;
    object_t object;
    int32_t ret_value = 0;
    uint32_t num_bits;
    int64_t * seed_64;
    
    int_bits = stack_pop();
    object = stack_pop();

    // put your code here
    num_bits = value_get_as_integer( int_bits );
    if( num_bits > 31 ) num_bits = 31;
    
    seed_64 = ( int64_t * )object_get_ptr( LANG_NUMBER_VALUE_FIELD( object ) );
    ret_value = lang_number_generate_random( seed_64 ) % ( 1 << num_bits );

    // return type: int
    stack_push_integer( ret_value );
}

void native_method_util_random_nextboolean( void )
{
    // boolean nextBoolean()
    // Returns the next pseudorandom, uniformly distributed boolean 
    // value from this random number generator's sequence. 
    // Implementation code: 516964D2
    object_t object;
    bool_t ret_value = 0;
    int64_t * seed_64;
    
    object = stack_pop();

    // put your code here
    seed_64 = ( int64_t * )object_get_ptr( LANG_NUMBER_VALUE_FIELD( object ) );
    ret_value = lang_number_generate_random( seed_64 ) & 0x001;

    // return type: boolean
    stack_push_boolean( ret_value );
}

void native_method_util_random_nextbytes_array_byte( void )
{
    // void nextBytes(byte[] bytes)
    // Generates random bytes and places them into a user-supplied 
    // byte array. 
    // Implementation code: F138BE40
    object_t byte_array_bytes;
    object_t object;
    uint8_t * buf;
    uint32_t len;
    uint32_t cnt;
    int64_t * seed_64;
    
    byte_array_bytes = stack_pop();
    object = stack_pop();

    // put your code here
    buf = object_get_ptr( byte_array_bytes );
    len = array_get_capacity( byte_array_bytes );
    seed_64 = ( int64_t * )object_get_ptr( LANG_NUMBER_VALUE_FIELD( object ) );
    
    for( cnt = 0; cnt < len; cnt++ )
    {
        buf[cnt] = ( uint8_t )( lang_number_generate_random( seed_64 ) & 0x0ff );
    }
}

void native_method_util_random_nextdouble( void )
{
    // double nextDouble()
    // Returns the next pseudorandom, uniformly distributed double 
    // value between 0.0 and 1.0 from this random number generator's 
    // sequence. 
    // Implementation code: 4E8157D1
    object_t object;
    double ret_value = 0.0;
    uint8_t * buf;
    uint32_t len;
    uint32_t cnt;
    int64_t * seed_64;
    
    object = stack_pop();

    // put your code here
    buf = ( uint8_t * )&ret_value;
    len = sizeof( ret_value );
    seed_64 = ( int64_t * )object_get_ptr( LANG_NUMBER_VALUE_FIELD( object ) );
    
    for( cnt = 0; cnt < len; cnt++ )
    {
        buf[cnt] = ( uint8_t )( lang_number_generate_random( seed_64 ) & 0x0ff );
    }

    // return type: double
    stack_push_double( ret_value );
}

void native_method_util_random_nextfloat( void )
{
    // float nextFloat()
    // Returns the next pseudorandom, uniformly distributed float 
    // value between 0.0 and 1.0 from this random number generator's 
    // sequence. 
    // Implementation code: F7DC4C7E
    object_t object;
    float ret_value = 0.0;
    uint8_t * buf;
    uint32_t len;
    uint32_t cnt;
    int64_t * seed_64;
    
    object = stack_pop();

    // put your code here
    buf = ( uint8_t * )&ret_value;
    len = sizeof( ret_value );
    seed_64 = ( int64_t * )object_get_ptr( LANG_NUMBER_VALUE_FIELD( object ) );
    
    for( cnt = 0; cnt < len; cnt++ )
    {
        buf[cnt] = ( uint8_t )( lang_number_generate_random( seed_64 ) & 0x0ff );
    }

    // return type: float
    stack_push_float( ret_value );
}

void native_method_util_random_nextgaussian( void )
{
    // double nextGaussian()
    // Returns the next pseudorandom, Gaussian ("normally") distributed 
    // double value with mean 0.0 and standard deviation 1.0 from 
    // this random number generator's sequence. 
    // Implementation code: B8FC422B
    object_t object;
    double ret_value = 0.0;
    int64_t * seed_64;
    
    object = stack_pop();

    // put your code here
    seed_64 = ( int64_t * )object_get_ptr( LANG_NUMBER_VALUE_FIELD( object ) );
    ret_value = ( double )( lang_number_generate_random( seed_64 ) % ( 1 << 24 ) ) / ( double )( 1 << 24 );

    // return type: double
    stack_push_double( ret_value );
}

void native_method_util_random_nextint( void )
{
    // int nextInt()
    // Returns the next pseudorandom, uniformly distributed int 
    // value from this random number generator's sequence. 
    // Implementation code: 575394E3
    object_t object;
    int32_t ret_value = 0;
    int64_t * seed_64;
    
    object = stack_pop();

    // put your code here
    seed_64 = ( int64_t * )object_get_ptr( LANG_NUMBER_VALUE_FIELD( object ) );
    ret_value = lang_number_generate_random( seed_64 );

    // return type: int
    stack_push_integer( ret_value );
}

void native_method_util_random_nextint_int( void )
{
    // int nextInt(int n)
    // Returns a pseudorandom, uniformly distributed int value 
    // between 0 (inclusive) and the specified value (exclusive), 
    // drawn from this random number generator's sequence. 
    // Implementation code: 65F5FD7B
    object_t int_n;
    object_t object;
    int32_t ret_value = 0;
    int64_t * seed_64;

    int_n = stack_pop();
    object = stack_pop();

    // put your code here
    seed_64 = ( int64_t * )object_get_ptr( LANG_NUMBER_VALUE_FIELD( object ) );
    ret_value = lang_number_generate_random( seed_64 ) % ( value_get_int( int_n ) );

    // return type: int
    stack_push_integer( ret_value );
}

void native_method_util_random_nextlong( void )
{
    // long nextLong()
    // Returns the next pseudorandom, uniformly distributed long 
    // value from this random number generator's sequence. 
    // Implementation code: E0EC76DA
    object_t object;
    int64_t ret_value = 0L;
    int64_t * seed_64;
    
    object = stack_pop();

    // put your code here
    seed_64 = ( int64_t * )object_get_ptr( LANG_NUMBER_VALUE_FIELD( object ) );
    ret_value = lang_number_generate_random( seed_64 );
    ret_value = ( int64_t )lang_number_generate_random( seed_64 ) + ( ret_value << 32 );

    // return type: long
    stack_push_long( ret_value );
}

void native_method_util_random_setseed_long( void )
{
    // void setSeed(long seed)
    // Sets the seed of this random number generator using a single 
    // long seed. 
    // Implementation code: 8BE6F61F
    object_t long_seed;
    object_t object;

    long_seed = stack_pop();
    object = stack_pop();

    // put your code here
    LANG_NUMBER_VALUE_FIELD( object ) = value_create_long( value_get_long( long_seed ) );
}

///////////////////////////////////////////////////////////////////////////

void native_util_random_invoke(uint16_t mref)
{
    switch( mref )
    {
        case NATIVE_UTIL_RANDOM_INIT:
            native_method_util_random_init();
            break;

        case NATIVE_UTIL_RANDOM_INIT_LONG:
            native_method_util_random_init_long();
            break;

        case NATIVE_UTIL_RANDOM_NEXT_INT:
            native_method_util_random_next_int();
            break;

        case NATIVE_UTIL_RANDOM_NEXTBOOLEAN:
            native_method_util_random_nextboolean();
            break;

        case NATIVE_UTIL_RANDOM_NEXTBYTES_ARRAY_BYTE:
            native_method_util_random_nextbytes_array_byte();
            break;

        case NATIVE_UTIL_RANDOM_NEXTDOUBLE:
            native_method_util_random_nextdouble();
            break;

        case NATIVE_UTIL_RANDOM_NEXTFLOAT:
            native_method_util_random_nextfloat();
            break;

        case NATIVE_UTIL_RANDOM_NEXTGAUSSIAN:
            native_method_util_random_nextgaussian();
            break;

        case NATIVE_UTIL_RANDOM_NEXTINT:
            native_method_util_random_nextint();
            break;

        case NATIVE_UTIL_RANDOM_NEXTINT_INT:
            native_method_util_random_nextint_int();
            break;

        case NATIVE_UTIL_RANDOM_NEXTLONG:
            native_method_util_random_nextlong();
            break;

        case NATIVE_UTIL_RANDOM_SETSEED_LONG:
            native_method_util_random_setseed_long();
            break;

        default:
            exception_new( NATIVE_CLASS_THROW_LANG_NOSUCHMETHODEXCEPTION, msg_throw_no_such_method );
            break;

    }
}


