#include "vm.h"
#include "stack.h"
#include "value_type.h"
#include "strings.h"
#include "application.h"
#include "objects.h"
#include "threads.h"
#include "arrays_type.h"
#include "exceptions.h"
#include "opcodes.h"
#include "heap.h"
#include "native.h"

/////////////////////////////////////////////////////////////////////////////

#define CAST_32(a)			_vm_cast_32(a)

#define GET_ARG_REF(a)		((int32_t)thread_get()->arg_ref_ptr[a])

/////////////////////////////////////////////////////////////////////////////

typedef union 
{
	uint16_t w;
	struct 
	{
		uint8_t bl, bh;
	} z;
	
	uint32_t tmp;
  
} vm_arg_t;

/////////////////////////////////////////////////////////////////////////////

static INLINE uint32_t _vm_cast_32( u08_t * ptr )
{
	uint32_t ret = 0;
	//memcpy( &ret, ptr, 4 );
	ret = ptr[0];
	ret = ( ret << 8 ) + ptr[1];
	ret = ( ret << 16 ) + ptr[2];
	ret = ( ret << 24 ) + ptr[3];
	return ret;
}

/////////////////////////////////////////////////////////////////////////////

#if 1

bool_t vm_run_java(opcode_t instr)
{
    uint8_t * curr_pc;
	uint8_t pc_inc;
	vm_arg_t arg0;

	int32_t tmp1=0;
	int32_t tmp2;

	object_t obj1;
	object_t obj2;

	uint8_t size;

	float f0;
	float f1;

	bool_t is_continue = TRUE;

	DEBUG_INSTR("$%08X: ", ( int )thread_get()->pc);

	pc_inc = 1;

	// prefetch next args (in big endian order)
	arg0.z.bh = *(thread_get()->pc+1);
	arg0.z.bl = *(thread_get()->pc+2);

	// branch operation
	if((instr >= OP_IFEQ) && (instr <= OP_IF_ICMPLE)) 
	{
		DEBUG_INSTR("if");
			
		if((instr >= OP_IFEQ) && (instr <= OP_IFLE)) 
		{
			// comparision with zero
			tmp2 = 0;
			instr = ( opcode_t )( instr - ( OP_IFEQ - OP_IF_ICMPEQ ) );
		} 
		else 
		{
			// comparison with second argument
			DEBUG_INSTR("_cmp");

			tmp2 = stack_pop_integer();
		}
	
	    // tmp1 = stack_pop_int();
		tmp1 = stack_pop_integer();
	
	    switch(instr) 
	    {
			case OP_IF_ICMPEQ: 
				DEBUG_INSTR("eq (%d %d)", tmp1, tmp2);
				tmp1 = (tmp1 == tmp2); 
				break;
					
			case OP_IF_ICMPNE: 
				DEBUG_INSTR("ne (%d %d)", tmp1, tmp2);
				tmp1 = (tmp1 != tmp2); 
				break;
					
			case OP_IF_ICMPLT: 
				DEBUG_INSTR("lt (%d %d)", tmp1, tmp2);
				tmp1 = (tmp1 <  tmp2); 
				break;
					
			case OP_IF_ICMPGE: 
				DEBUG_INSTR("ge (%d %d)", tmp1, tmp2);
				tmp1 = (tmp1 >= tmp2); 
				break;
					
			case OP_IF_ICMPGT: 
				DEBUG_INSTR("gt (%d %d)", tmp1, tmp2);
				tmp1 = (tmp1 >  tmp2); 
				break;
					
			case OP_IF_ICMPLE: 
				DEBUG_INSTR("le (%d %d)", tmp1, tmp2);
				tmp1 = (tmp1 <= tmp2); 
				break;
                
            default:
                exception_new( NATIVE_CLASS_THROW_LANG_UNSUPPORTEDOPERATIONEXCEPTION, msg_throw_unsupported_opcode );
				break;
		}
	      
	    // change pc if jump has been taken
		if(tmp1) 
		{ 
			DEBUG_INSTR(" -> taken\n"); 
			thread_get()->pc += arg0.w; 
			pc_inc = 0; 
		}
		else     
		{ 
			DEBUG_INSTR(" -> taken\n"); 
			pc_inc = 3; 
		}
	} 
	
	// two operand arithmetic
	else if((instr >= OP_IADD) && (instr <= OP_IINC)) 
	{
		// single operand arithmetic
		if(instr == OP_INEG) 
		{
			tmp1 = -stack_pop_integer();
			stack_push_integer(tmp1);

			DEBUG_INSTR("ineg(%d)\n", -stack_peek_integer(0));
		} 
		else if(instr == OP_IINC) 
		{
			DEBUG_INSTR("iinc %d,%d\n", arg0.z.bh, arg0.z.bl); 

			tmp1 = value_get_decimal( thread_instance()->locals[arg0.z.bh] ) + arg0.z.bl;
			thread_instance()->locals[arg0.z.bh] = value_create_decimal( tmp1 );
			pc_inc = 3;
	    } 
	    else if(((instr & 0x03) == 0x02) && (instr <= OP_FNEG)) 
	    {
		    if (instr == OP_FNEG) 
		    {
				f0 = -stack_pop_float();

				stack_push_float(f0);
				DEBUG_INSTR("fneg (%5.2f)\n", stack_peek_float(0));
		    }
		    else 
		    {
				// fetch operands from stack
				f0 = stack_pop_float();  
				f1 = stack_pop_float();

				switch(instr) 
				{
					case OP_FADD:  
						DEBUG_INSTR("fadd(%5.2f,%5.2f)", f1, f0);
						f1  += f0; 
						break;
							
					case OP_FSUB:  
						DEBUG_INSTR("fsub(%5.2f,%5.2f)", f1, f0);
						f1  -= f0; 
						break;
							
					case OP_FMUL:  
						DEBUG_INSTR("fmul(%5.2f,%5.2f)", f1, f0);
						f1  *= f0; 
						break;
							
					case OP_FDIV:  
						DEBUG_INSTR("fdiv(%5.2f,%5.2f)", f1, f0);
						if(!f0) exception_new( NATIVE_CLASS_THROW_LANG_ARITHMETICEXCEPTION, msg_throw_divison_by_zero );
						f1  /= f0; 
						break;
							
					case OP_IREM:  
						DEBUG_INSTR("frem(%5.2f,%5.2f)", f1, f0);
						exception_new( NATIVE_CLASS_THROW_LANG_UNSUPPORTEDOPERATIONEXCEPTION, msg_throw_unsupported_opcode );
						break;
                        
                    default:
                        exception_new( NATIVE_CLASS_THROW_LANG_UNSUPPORTEDOPERATIONEXCEPTION, msg_throw_unsupported_opcode );
                        break;
				}

				stack_push_float(f1);
				DEBUG_INSTR(" = %5.2f\n", stack_peek_float(0));
			}
		} 
		else 
		{
			// fetch operands from stack
			tmp1 = stack_pop_integer();  
			tmp2 = stack_pop_integer();
		
			switch(instr) 
			{
				case OP_IADD:  
					DEBUG_INSTR("iadd(%d,%d)", tmp2, tmp1);
					tmp2  += tmp1; 
					break;
						
				case OP_ISUB:  
					DEBUG_INSTR("isub(%d,%d)", tmp2, tmp1);
					tmp2  -= tmp1; 
					break;
						
				case OP_IMUL:  
					DEBUG_INSTR("imul(%d,%d)", tmp2, tmp1);
					tmp2  *= tmp1; 
					break;
						
				case OP_IDIV:  
					DEBUG_INSTR("idiv(%d,%d)", tmp2, tmp1);
					if(!tmp1) exception_new( NATIVE_CLASS_THROW_LANG_ARITHMETICEXCEPTION, msg_throw_divison_by_zero );
					tmp2  /= tmp1; 
					break;
						
				case OP_IREM:  
					DEBUG_INSTR("irem(%d,%d)", tmp2, tmp1);
					tmp2  %= tmp1; 
					break;
						
				case OP_ISHL:  
					DEBUG_INSTR("ishl(%d,%d)", tmp2, tmp1);
					tmp2 <<= tmp1; 
					break;
					
				case OP_ISHR:  
					DEBUG_INSTR("ishr(%d,%d)", tmp2, tmp1);
					tmp2 >>= tmp1; 
					break;
						
				case OP_IAND:  
					DEBUG_INSTR("iand(%d,%d)", tmp2, tmp1);
					tmp2  &= tmp1; 
					break;
						
				case OP_IOR:   
					DEBUG_INSTR("ior(%d,%d)",  tmp2, tmp1);
					tmp2  |= tmp1; 
					break;
						
				case OP_IXOR:  
					DEBUG_INSTR("ixor(%d,%d)", tmp2, tmp1);
					tmp2  ^= tmp1; 
					break;
						
				case OP_IUSHR: 
					DEBUG_INSTR("iushr(%d,%d)", tmp2, tmp1);
					tmp2 = ((uint32_t)tmp2 >> tmp1); 
					break;

                default:
                    exception_new( NATIVE_CLASS_THROW_LANG_UNSUPPORTEDOPERATIONEXCEPTION, msg_throw_unsupported_opcode );
                    break;
			}
		
			// and finally push result
			stack_push_integer(tmp2);

			DEBUG_INSTR(" = %d\n", stack_peek_integer(0));
		}
	}
	else
	{
		switch( instr )
		{
			case OP_NOP:
				DEBUG_INSTR("nop\n");
				break;

			case OP_BIPUSH:
				// push 8bit integer signed value to stack - need to be object
				stack_push_integer(arg0.z.bh); 
				pc_inc = 2;

				DEBUG_INSTR("bipush #%d (0x%04x)\n", arg0.z.bh, stack_peek(0));
				break;

			case OP_SIPUSH:
				// push 16bit integer signed value to stack - need to be object
				stack_push_integer(arg0.w); 
				pc_inc = 3;

				DEBUG_INSTR("sipush #"DBG16"\n", arg0.w);
				break;

			case OP_USR_GETSTATIC:
				// push 16bit integer signed value to stack - need to be object
				// stack_push_field(GET_ARG_REF(arg0.w)); 
				// push native field value to stack
				native_get_field( GET_ARG_REF(arg0.w) );
				pc_inc = 3;

				DEBUG_INSTR("usr_getfield #"DBG32"\n", GET_ARG_REF(arg0.w));
				break;

			case OP_ICONST_M1:
			case OP_ICONST_0:
			case OP_ICONST_1:
			case OP_ICONST_2:
			case OP_ICONST_3:
			case OP_ICONST_4:
			case OP_ICONST_5:
				// push integer const -1 (M1), 0 to 5 value to stack - need to be object
				stack_push_integer(instr - OP_ICONST_0);

				DEBUG_INSTR("iconst_%d\n", instr - OP_ICONST_0);
				break;

			case OP_LCONST_0:
			case OP_LCONST_1:
				// push long integer const 0 or 1 value to stack - need to be object
				tmp1 = instr - OP_LCONST_0;
				stack_push_long(tmp1);

				DEBUG_INSTR("lconst_%d\n", tmp1);
				break;

			case OP_ISTORE:
				// pull integer from stack and store into a variable
				thread_instance()->locals[arg0.z.bh] = stack_pop(); 
				pc_inc = 2;

				DEBUG_INSTR("istore %d (%d)\n", arg0.z.bh, thread_instance()->locals[arg0.z.bh]);
				break;

			case OP_ISTORE_0:
			case OP_ISTORE_1:
			case OP_ISTORE_2:
			case OP_ISTORE_3:
				// pull integer from stack and store into a variable 0 to 3
				thread_instance()->locals[instr - OP_ISTORE_0] = stack_pop();

				DEBUG_INSTR("istore_%d (0x%04x)\n", instr - OP_ISTORE_0, thread_instance()->locals[instr - OP_ISTORE_0]);
				break;

			case OP_ILOAD:
				// pushes integer from a variable to stack
				obj1 = thread_instance()->locals[arg0.z.bh];
				stack_push(obj1); 
				pc_inc = 2;

				DEBUG_INSTR("iload %d (0x%04x): ", arg0.z.bh, obj1);
				#if SET_LEVEL_INSTR != 0
				heap_dump_object(obj1);
				#endif
				break;

			case OP_ILOAD_0:
			case OP_ILOAD_1:
			case OP_ILOAD_2:
			case OP_ILOAD_3:
				// pushes integer from a variable 0 to 3 to stack
				obj1 = thread_instance()->locals[instr - OP_ILOAD_0];
				stack_push(obj1);

				DEBUG_INSTR("iload_%d (0x%04x)", instr-OP_ILOAD_0, obj1);
				#if SET_LEVEL_HEAP != 0
				//DEBUG_INSTR(": " );
				//heap_dump_object(obj1);
				#endif
				DEBUG_INSTR("\n" );
				break;

			case OP_GOTO:
				// branch to an address
                curr_pc = thread_get()->pc;
				thread_get()->pc += ((int16_t)arg0.w-3);
				pc_inc = 3;
                
                // is it endeless loop?
                if( curr_pc == ( thread_get()->pc+3 ) )
                {
                    obj1 = strings_create("");
                    thread_set_wait(obj1);
                }

				DEBUG_INSTR("goto 0x%08x\n", thread_get()->pc + 3); 
				break;	

			case OP_POP2: 
				// discard both top stack items
				DEBUG_INSTR("ipop\n");
				stack_pop(); 
				stack_pop();
				break;	
	    
			case OP_POP: 
				// discard top stack item
				DEBUG_INSTR("pop\n");
				stack_pop();
				break;	
	    
			case OP_DUP: 
				// duplicate top stack item
				stack_push(stack_peek(0));
				DEBUG_INSTR("dup ("DBG16")\n", ( uint32_t )stack_peek(0) & 0xffff);
				break;	
	
			case OP_DUP2: 
				// duplicate top two stack items  (a,b -> a,b,a,b)
				stack_push(stack_peek(1));
				stack_push(stack_peek(1));
				DEBUG_INSTR("dup2 ("DBG16","DBG16")\n",  ( uint32_t )stack_peek(0) & 0xffff, ( uint32_t )stack_peek(1) & 0xffff);
				break;	

			case OP_GETFIELD: 
				// pushed value from class field to stack
				pc_inc = 3;
				stack_push( object_get_fields_ptr( stack_pop() )[arg0.w] );

				DEBUG_INSTR("getfield #%d\n", arg0.w);
				break;
	    
			case OP_PUTFIELD: 
				// pop value from stack to class field
				pc_inc = 3;
				object_get_fields_ptr( stack_peek(1) )[arg0.w] = stack_peek(0);
				stack_add_sp(-2);

				DEBUG_INSTR("putfield #%d\n", arg0.w);
				break;
	    
			case OP_NEW: 
				// create new class
				pc_inc = 3;
				vm_new(GET_ARG_REF(arg0.w));

				DEBUG_INSTR("new #"DBG32" (0x%04x)\n", GET_ARG_REF(arg0.w), stack_peek(0));
				break;

			case OP_CASTCHECK:
				// cast check
				pc_inc = 3;
				obj1 = stack_peek(0);
				vm_cast_check( GET_ARG_REF(arg0.w), obj1 );

				DEBUG_INSTR("castcheck #"DBG32" (0x%04x)\n", GET_ARG_REF(arg0.w), obj1);
				break;
	    
			case OP_NEWARRAY: 
				// create new array
				pc_inc = 2;
				// stack_push(array_value_new(stack_pop_integer()));
				// arg0.z.bh is the array type
				stack_push( array_create( ( uint32_t )stack_pop_integer(), arg0.z.bh ) );

				DEBUG_INSTR("OP_NEWARRAY\n");
				break;
	    
			case OP_ARRAYLENGTH: 
				// get array length
				stack_push_integer(( int32_t )array_get_capacity(stack_pop()));

				DEBUG_INSTR("OP_ARRAYLENGTH\n");
				break;
	    
			case OP_BASTORE: 
				// pop and store <8bit> onto array[index]
				tmp2 = stack_pop_integer();		    // value
				tmp1 = stack_pop_integer();         // index
				array_copy(stack_pop(), tmp1, &tmp2, 1); //sizeof( uint8_t ));

				DEBUG_INSTR("OP_BASTORE\n");
				break;
	    
			case OP_IASTORE: 
				// pop and store <32bit> onto array[index]
				tmp2 = stack_pop_integer();		    // value
				tmp1 = stack_pop_integer();         // index
				array_copy(stack_pop(), tmp1, &tmp2, 1); // sizeof( uint32_t ));

				DEBUG_INSTR("OP_IASTORE\n");
				break;
	    
			case OP_FASTORE:
				// pop and store <float> onto array[index] - only as object
				f0 = stack_pop_float();				// value
				tmp1 = stack_pop_integer();       // index
				array_copy(stack_pop(), tmp1, &f0, 1); // sizeof( float ));

				DEBUG_INSTR("OP_FASTORE\n");
				break;
	
			case OP_BALOAD:
				// push <8bit> from array[index]
				tmp1 = stack_pop_integer();       // index
				tmp2 = 0;
				array_get( stack_pop(), tmp1, 1, /*sizeof( uint8_t ),*/ &tmp2 );
				stack_push( value_create_decimal( tmp2 ));

				DEBUG_INSTR("OP_BALOAD\n");
				break;
	    
			case OP_IALOAD: 
				// push <32bit> from array[index]
				tmp1 = stack_pop_integer();       // index
				tmp2 = 0;
				array_get( stack_pop(), tmp1, 1, /*sizeof( uint32_t ),*/ &tmp2 );
				stack_push( value_create_decimal( tmp2 ));

				DEBUG_INSTR("OP_IALOAD\n");
				break;

			case OP_FALOAD: 
				// push <float> from array[index]
				tmp1 = stack_pop_integer();       // index
				f0 = 0.0;
				array_get( stack_pop(), tmp1, 1, /*sizeof( float ),*/ &f0 );
				stack_push( value_create_float( f0 ));

				DEBUG_INSTR("OP_FALOAD\n");
				break;

			case OP_FCONST_0: 
				// push 0.0 - need to be object
				stack_push_float(0.0);
				DEBUG_INSTR("fconst_0\n");
				break;

			case OP_FCONST_1: 
				// push 1.0 - need to be object
				stack_push_float(1.0);
				DEBUG_INSTR("fconst_1\n");
				break;
		
			case OP_FCONST_2:
				// push 2.0 - need to be object
				stack_push_float(2.0);
				DEBUG_INSTR("fconst_2\n");
				break;
		
			case OP_I2F:
				// pop <32bit> and push back <float> - need to be object
				tmp1 = stack_pop_integer();
				stack_push_float( (float)tmp1 );
				DEBUG_INSTR("i2f %d\n", tmp1);
				break;
		
			case OP_F2I:
				// pop <float> and push back <32bit> - need to be object
				tmp1 = (int32_t)stack_pop_float();
				stack_push_integer(tmp1);
				DEBUG_INSTR("i2f %d\n", tmp1);
				break;

			case OP_L2I:
				// pop <long> and push back <32bit> - need to be object
				tmp1 = (int32_t)stack_pop_long();
				stack_push_integer(tmp1);
				DEBUG_INSTR("l2i %d\n", tmp1);
				break;
	    
			case OP_FSTORE:
				// pop float from stack into locals
				thread_instance()->locals[arg0.z.bh] = stack_pop(); 
				pc_inc = 2;
				DEBUG_INSTR("fstore %d (%5.2f)\n", arg0.z.bh, value_get_float(thread_instance()->locals[arg0.z.bh]));
				break; 

			case OP_FSTORE_0:
			case OP_FSTORE_1:
			case OP_FSTORE_2:
			case OP_FSTORE_3:
				// pop integer from stack into locals
				thread_instance()->locals[instr - OP_FSTORE_0] = stack_pop();
				DEBUG_INSTR("fstore_%d (%f)\n", instr - OP_FSTORE_0, value_get_float(thread_instance()->locals[instr - OP_FSTORE_0]));
				break;
				
			case OP_FLOAD:
				// push float from local variable (push local var)
				stack_push(thread_instance()->locals[arg0.z.bh]); 
				pc_inc = 2;
				DEBUG_INSTR("fload %d (%f, "DBG16")\n", thread_instance()->locals[arg0.z.bh], stack_peek_float(0)); // , stack_peek_integer(0));
				break;
	
			case OP_FLOAD_0:
			case OP_FLOAD_1:
			case OP_FLOAD_2:
			case OP_FLOAD_3:		
				// push local onto stack
				stack_push(thread_instance()->locals[instr - OP_FLOAD_0]);
				DEBUG_INSTR("fload_%d (%f, "DBG16")\n", instr-OP_FLOAD_0, stack_peek_float(0), stack_peek_integer(0));
				break;
	    
			case OP_FCMPL:
			case OP_FCMPG:
				// compare top floats on stack - OK
				f1 = stack_pop_float();
				f0 = stack_pop_float();
				tmp1=0;
				
				if (f0<f1)
					tmp1=-1;
				else if (f0>f1)
					tmp1=1;
					
				// stack_push(nvm_int2stack(tmp1));
				stack_push_integer(tmp1);
				DEBUG_INSTR("fcmp%c (%f, %f, %i)\n", (instr==OP_FCMPL)?'l':'g', f0, f1, stack_peek_integer(0));
				break;

			case OP_GETSTATIC:
				// push static field from class
				pc_inc = 3;   // prefetched data used
                if( instance_get_statics() == NULL )
                {
                    stack_push( 0 );
                }
                else
                {
                    stack_push(instance_get_statics()[arg0.w]);
                    DEBUG_INSTR("getstatic #"DBG16"\n", arg0.w);
                }
				break;
			
			case OP_PUTSTATIC:
				// pop static field to class
				pc_inc = 3;
                if( instance_get_statics() == NULL ) break;
				instance_get_statics()[arg0.w] = stack_pop();
				DEBUG_INSTR("putstatic #"DBG16" -> "DBG16"\n", arg0.w, instance_get_statics()[arg0.w]);
				break;
			
			case OP_LDC:
				pc_inc = 2;
				DEBUG_INSTR("ldc #"DBG16"\n", arg0.z.bh);
				stack_push( object_const_create( arg0.z.bh ) );
				break;

			case OP_LDC2_W:
				// push double item from constant pool - need to be object
				pc_inc = 3;
				stack_push( object_const_create( arg0.z.bh ) );

				DEBUG_INSTR("ldc2_w #"DBG16"\n", arg0.z.bh);
				break;

			case OP_TABLESWITCH:
				DEBUG_INSTR("TABLESWITCH\n");
				
				// get low and high values
				tmp1 = CAST_32( thread_get()->pc + 5 );
				tmp2 = CAST_32( thread_get()->pc + 9 );

				// get actual value - need to be object
				// arg0.tmp = stack_pop();               
				arg0.tmp = stack_pop_integer();
				DEBUGF("tableswitch %d-%d (%d)\n", tmp1, tmp2, arg0.w);
			
				// value within range?
				if((( int32_t )arg0.tmp < tmp1)||(( int32_t )arg0.tmp > tmp2))
				{
					// no: use default
					tmp2 = 1;
				}
				else
				{
					// yes: get offset from table
					tmp2 = 13 + ((arg0.tmp - tmp1)<<2);
				}

				// and do the jump
				thread_get()->pc += CAST_32(thread_get()->pc + tmp2);
				pc_inc = 0;
				break;

			case OP_LOOKUPSWITCH:
				DEBUG_INSTR("LOOKUPSWITCH\n");
			
				// point to size field
				tmp2 = 1 + 4;

				// get size field
				size = CAST_32( thread_get()->pc + tmp2 );

				// point to the beginning of the table
				tmp2 += 4;
			
				// get actual value - need to be object
				tmp1 = stack_pop_integer();                        
	      
				while(size)
				{
					if( CAST_32(thread_get()->pc + tmp2) == tmp1 )
					{
						tmp2 += 4;
						break;
					}
					tmp2 += 8;
					size--;
				}
	      
				if (size==0)
				{
					tmp2 = 1;
				}

				// calculate the destination address
				thread_get()->pc += CAST_32(thread_get()->pc + tmp2);
				pc_inc = 0;
				break;

			case OP_ANEWARRAY:
				// Object array is the same as int array...
				pc_inc = 3;
				// stack_push( object_create( GET_ARG_REF(arg0.w), T_ARRAY + T_CLASS, (uint32_t)stack_pop_integer() ) );
				stack_push( array_create( (uint32_t)stack_pop_integer(), T_CLASS ) );

            	DEBUG_INSTR("OP_ANEWARRAY\n");
				break;
	    
			case OP_AASTORE:
				// pop and store object onto array[index] - need to be object
				obj2 = stack_pop();				// value
				tmp1 = stack_pop_integer();     // index
				object_get_fields_ptr( stack_pop() )[ tmp1 ] = obj2;
				// array_copy(stack_pop(), tmp1, &obj2, sizeof( object_t ));

            	DEBUG_INSTR("OP_AASTORE\n");
				break;
	    
			case OP_AALOAD:
				// push object from array[index] - need to be object
				tmp1 = stack_pop_integer();       // index
				array_get( stack_pop(), tmp1, 1, &obj2 );
				// obj2 = object_get_fields_ptr( stack_pop() )[ tmp1 ];
				stack_push( obj2 ); 

				DEBUG_INSTR("OP_AALOAD\n");
				break;

         	case OP_ATHROW:
				// throw an exception
            	DEBUG_INSTR("OP_ATHROW\n");
            	obj1 = stack_pop();
				exception_throw( obj1 );
            	break;

			case OP_MONITORENTER:
            	DEBUG_INSTR("OP_MONITORENTER\n");
            	obj1 = stack_pop();
                vm_enter_monitor( obj1 );
				break;

			case OP_MONITOREXIT:
            	DEBUG_INSTR("OP_MONITOREXIT\n");
            	obj1 = stack_pop();

				DEBUG_INFO( "thread %d released object %08x\n", thread_get()->thread_id, obj1 );

				// release object taken by the thread
				thread_instance()->sync_object = 0;
				break;

			#ifdef NVM_USE_EXTSTACKOPS
			// duplicate top stack item and put it under the second
			case OP_DUP_X1:
				nvm_stack_t w1 = stack_pop();
				nvm_stack_t w2 = stack_pop();
				stack_push(w1);
				stack_push(w2);
				stack_push(w1);
				DEBUG_INSTR("dup_x1 ("DBG16")\n", stack_peek(0) & 0xffff);
				break;
	
			// duplicate top stack item
			case OP_DUP_X2:
				nvm_stack_t w1 = stack_pop();
				nvm_stack_t w2 = stack_pop();
				nvm_stack_t w3 = stack_pop();
				stack_push(w1);
				stack_push(w2);
				stack_push(w3);
				stack_push(w1);
				DEBUG_INSTR("dup ("DBG16")\n", stack_peek(0) & 0xffff);
				break;
	
			// duplicate top two stack items  (a,b -> a,b,a,b)
			case OP_DUP2_X1:
				nvm_stack_t w1 = stack_pop();
				nvm_stack_t w2 = stack_pop();
				nvm_stack_t w3 = stack_pop();
				stack_push(w1);
				stack_push(w2);
				stack_push(w3);
				stack_push(w1);
				stack_push(w2);
				DEBUG_INSTR("dup2 ("DBG16","DBG16")\n", stack_peek(0) & 0xffff, stack_peek(1) & 0xffff);
				break;
	
			// duplicate top two stack items  (a,b -> a,b,a,b)
			case OP_DUP2_X2:
				nvm_stack_t w1 = stack_pop();
				nvm_stack_t w2 = stack_pop();
				nvm_stack_t w3 = stack_pop();
				nvm_stack_t w4 = stack_pop();
				stack_push(w1);
				stack_push(w2);
				stack_push(w3);
				stack_push(w4);
				stack_push(w1);
				stack_push(w2);
				DEBUG_INSTR("dup2 ("DBG16","DBG16")\n", stack_peek(0) & 0xffff, stack_peek(1) & 0xffff);
				break;
			#endif
	    
			// swap top two stack items  (a,b -> b,a)
			case OP_SWAP:
				obj1 = stack_pop();
				obj2 = stack_pop();
				stack_push(obj1);
				stack_push(obj2);
				DEBUG_INSTR("swap ("DBG16","DBG16")\n", stack_peek(0), stack_peek(1));
				break;
	    
			case OP_FRETURN:
			case OP_IRETURN:
					DEBUGF("i");
			case OP_RETURN:
				if( instr == OP_IRETURN )
				{
					DEBUG_INSTR("OP_IRETURN\n");
				}
				else if(instr == OP_FRETURN)
				{
					DEBUG_INSTR("OP_FRETURN\n");
				}
				else if(instr == OP_RETURN)
				{
					DEBUG_INSTR("OP_RETURN\n");
				}
	
				DEBUGF("return: ");

				if( vm_return( ((instr == OP_IRETURN)||(instr == OP_FRETURN)) ) == FALSE )
				{
					// stop this thread
					is_continue = FALSE;
				}

				pc_inc = 3;
				break;	    
                
            case OP_INVOKEINTERFACE:
                if(instr == OP_INVOKEINTERFACE)
                {
                    DEBUG_INSTR("invoke interface");
                    // pc_inc = vm_invoke_interface( GET_ARG_REF(arg0.w) );
                    tmp1 = arg0.w;
                    
                    arg0.z.bl = *(thread_get()->pc+3);
                    arg0.z.bh = *(thread_get()->pc+4);
                    
                    // opcode with 5 bytes, increment 2 here before call and 3 more will be on return
                    thread_get()->pc += 2;

                    if( vm_invoke_interface( stack_peek( arg0.w - 1 ), ( char * )object_get_constant( tmp1, NULL, NULL ) ) == FALSE )
                    {
                        exception_new( NATIVE_CLASS_THROW_LANG_ILLEGALARGUMENTEXCEPTION, msg_throw_invalid_ref );
                    }

                    // at this point we are in the called method, dont increment pc
                    pc_inc = 0;
                }

                break;

			case OP_INVOKEVIRTUAL:
			case OP_INVOKESPECIAL:
			case OP_INVOKESTATIC:
				DEBUG_INSTR("invoke");
			
				if(instr == OP_INVOKEVIRTUAL) 
				{ 
					DEBUG_INSTR(" virtual"); 
				}

				if(instr == OP_INVOKESPECIAL) 
				{ 
					DEBUG_INSTR(" special"); 
				}

				if(instr == OP_INVOKESTATIC)  
				{ 
					DEBUG_INSTR(" static"); 
				}
                
                //(FIX_ME check?)
				if(arg0.z.bh >= GET_CLASS_INDEX(NATIVE_CLASS_BASE))
				{
					DEBUG_INSTR( " native" );
				}

				DEBUG_INSTR(" #"DBG32"\n", GET_ARG_REF(arg0.w));

                pc_inc = vm_invoke( GET_ARG_REF(arg0.w), instr );
				
				break;

			default:
				exception_new( NATIVE_CLASS_THROW_LANG_UNSUPPORTEDOPERATIONEXCEPTION, msg_throw_unsupported_opcode );
				break;
		}
	}

	thread_get()->pc += pc_inc;

	// this thread is been marked to be terminated
	if( thread_get()->run_mode & THREAD_MARK_TERMINATE ) return FALSE;

	return is_continue;
}
#endif
