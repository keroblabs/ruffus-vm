#ifndef OPCODES_H
#define OPCODES_H

#ifdef	__cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////////////////////

typedef enum
{
   OP_NOP	=	      0x00	,	
   OP_ACONST_NULL	=	0x01	,	

   OP_ICONST_M1	=	0x02	,	
   OP_ICONST_0	=	   0x03	,	
   OP_ICONST_1	=	   0x04	,	
   OP_ICONST_2	=	   0x05	,	
   OP_ICONST_3	=	   0x06	,	
   OP_ICONST_4	=	   0x07	,	
   OP_ICONST_5	=	   0x08	,	
				
   OP_LCONST_0	=	   0x09	,	
   OP_LCONST_1	=	   0x0a	,	

   OP_FCONST_0	=	0x0b	,	// only if floating point compiled
   OP_FCONST_1	=	0x0c	,	// only if floating point compiled
   OP_FCONST_2	=	0x0d	,	// only if floating point compiled

   OP_DCONST_0  =   0x0E    ,   //not implemented
   OP_DCONST_1  =   0x0F    ,   //not implemented
				
   OP_BIPUSH	=	0x10	,	
   OP_SIPUSH	=	0x11	,	
   OP_LDC	=	    0x12	,	
   OP_LDC_W  =      0x13    ,	// not implemented
   OP_LDC2_W =	    0x14    ,
				
				
   OP_ILOAD	=	   0x15	,	
   OP_FLOAD	=	   0x17	,	// only if floating point compiled
				
   OP_ILOAD_0	=	0x1a	,	
   OP_ILOAD_1	=	0x1b	,	
   OP_ILOAD_2	=	0x1c	,	
   OP_ILOAD_3	=	0x1d	,	
				
   OP_FLOAD_0	=	0x22	,	// only if floating point compiled
   OP_FLOAD_1	=	0x23	,	// only if floating point compiled
   OP_FLOAD_2	=	0x24	,	// only if floating point compiled
   OP_FLOAD_3	=	0x25	,	// only if floating point compiled
				
   OP_ALOAD_0	=	0x2a	,	
   OP_ALOAD_1	=	0x2b	,	
   OP_ALOAD_2	=	0x2c	,	
   OP_ALOAD_3	=	0x2d	,	
				
   OP_IALOAD	=	0x2e	,	// only if array compiled in
   OP_FALOAD	=	0x30	,	// only if array and floating poi
   OP_AALOAD	=	0x32	,	// only if array compiled in
   OP_BALOAD	=	0x33	,	// only if array compiled in
				
   OP_ISTORE	=	0x36	,	
   OP_FSTORE	=	0x38	,	// only if floating point compiled
   OP_ASTORE	=	0x3a	,	
   OP_ISTORE_0	=	0x3b	,	
   OP_ISTORE_1	=	0x3c	,	
   OP_ISTORE_2	=	0x3d	,	
   OP_ISTORE_3	=	0x3e	,	
   OP_FSTORE_0	=	0x43	,	// only if floating point compiled
   OP_FSTORE_1	=	0x44	,	// only if floating point compiled
   OP_FSTORE_2	=	0x45	,	// only if floating point compiled
   OP_FSTORE_3	=	0x46	,	// only if floating point compiled
   OP_ASTORE_0	=	0x4b	,	
   OP_ASTORE_1	=	0x4c	,	
   OP_ASTORE_2	=	0x4d	,	
   OP_ASTORE_3	=	0x4e	,	
				
   OP_IASTORE	=	0x4f	,	// only if array compiled in
   OP_FASTORE	=	0x51	,	// only if array and floating poi
   OP_AASTORE	=	0x53	,	// only if array compiled in
   OP_BASTORE	=	0x54	,	// only if array compiled in
				
   OP_POP	=	   0x57	,	
   OP_POP2	=	   0x58	,	
   OP_DUP	=	   0x59	,	
   OP_DUP_X1	=	0x5a	,	// only if extedend stack ops are
   OP_DUP_X2	=	0x5b	,	// only if extedend stack ops are
   OP_DUP2	=	   0x5c	,	
   OP_DUP2_X1	=	0x5d	,	// only if extedend stack ops are
   OP_DUP2_X2	=	0x5e	,	// only if extedend stack ops are
   OP_SWAP	=	   0x5f	,	// only if extedend stack ops are
				
   OP_IADD	=	0x60	,	
   OP_FADD	=	0x62	,	// only if floating point compiled
   OP_ISUB	=	0x64	,	
   OP_FSUB	=	0x66	,	// only if floating point compiled
   OP_IMUL	=	0x68	,	
   OP_FMUL	=	0x6a	,	// only if floating point compiled
   OP_IDIV	=	0x6c	,	
   OP_FDIV	=	0x6e	,	// only if floating point compiled
   OP_IREM	=	0x70	,	
   OP_FREM	=	0x72	,	// only if floating point compiled
   OP_INEG	=	0x74	,	
   OP_FNEG	=	0x76	,	// only if floating point compiled
   OP_ISHL	=	0x78	,	
   OP_ISHR	=	0x7a	,	
   OP_IUSHR	=	0x7c	,	
   OP_IAND	=	0x7e	,	
   OP_IOR	=	0x80	,	
   OP_IXOR	=	0x82	,	
   OP_IINC	=	0x84	,	
				
   OP_I2F	=	0x86	,	// only if floating point compiled
   OP_L2I   =   0x88    ,
   OP_F2I	=	0x8b	,	// only if floating point compiled
				
   OP_FCMPL	=	0x95	,	// only if floating point compiled
   OP_FCMPG	=	0x96	,	// only if floating point compiled
				
   OP_IFEQ	=	0x99	,	
   OP_IFNE	=	0x9a	,	
   OP_IFLT	=	0x9b	,	
   OP_IFGE	=	0x9c	,	
   OP_IFGT	=	0x9d	,	
   OP_IFLE	=	0x9e	,	
				
   OP_IF_ICMPEQ	=	0x9f	,	
   OP_IF_ICMPNE	=	0xa0	,	
   OP_IF_ICMPLT	=	0xa1	,	
   OP_IF_ICMPGE	=	0xa2	,	
   OP_IF_ICMPGT	=	0xa3	,	
   OP_IF_ICMPLE	=	0xa4	,	
				
   OP_GOTO	=	      0xa7	,	
				
   OP_TABLESWITCH	=	0xaa	,	
   OP_LOOKUPSWITCH	=	0xab	,	
				
   OP_IRETURN	=		0xac	,	
   OP_FRETURN	=		0xae	,	// only if floating point compiled
   OP_RETURN	=		0xb1	,	
				
   OP_GETSTATIC	=		0xb2	,	
   OP_PUTSTATIC	=		0xb3	,	// only if fields are compiled in
   OP_GETFIELD	=	    0xb4	,	// only if fields are compiled in
   OP_PUTFIELD	=	    0xb5	,	// only if fields are compiled in
   OP_INVOKEVIRTUAL	=	0xb6	,	
   OP_INVOKESPECIAL	=	0xb7	,	
   OP_INVOKESTATIC	=	0xb8	,	
   OP_INVOKEINTERFACE = 0xB9    ,
				
   OP_NEW	=			0xbb	,	
   OP_NEWARRAY	=		0xbc	,	// only if array compiled in
   OP_ANEWARRAY	=		0xbd	,	// only if array compiled in
   OP_ARRAYLENGTH	=	0xbe	,	// only if array compiled in
   OP_ATHROW =			0xbf  ,

   OP_CASTCHECK    =    0xc0,
   OP_MONITORENTER =    0xc2,
   OP_MONITOREXIT  =    0xc3,

   // opcodes changed by nanovm tool and are not JAVA standard
   OP_USR_GETSTATIC	=	0xcb,		// load class reference


   OP_UNKNOWN = 0xff

} opcode_t;

/////////////////////////////////////////////////////////////////////////////

bool_t vm_run_java(opcode_t instr);

/////////////////////////////////////////////////////////////////////////////

#ifdef	__cplusplus
}
#endif

#endif // OPCODES_H
