//
//  NanoVMTool, Converter and Upload Tool for the NanoVM
//  Copyright (C) 2005 by Till Harbaum <Till@Harbaum.org>
//
//  This program is free software; you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation; either version 2 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//
//  Parts of this tool are based on public domain code written by Kimberley
//  Burchett: http://www.kimbly.com/code/classfile/
//

//
// UVMWriter.java
//

import java.io.*;
import java.util.*;

public class UVMWriter 
{
	static final int MAGIC   = 0xBE000000;
	static final int VERSION = 2;
    static private int fileSize = 0;
    static private int maxSize = 0;
    
    public static final int T_BOOLEAN  = 4;
	public static final int T_CHAR 	   = 5;
	public static final int T_FLOAT    = 6;
	public static final int T_DOUBLE   = 7;
	public static final int T_BYTE 	   = 8;
	public static final int T_SHORT    = 9;
	public static final int T_INT 	   = 10;
	public static final int T_LONG 	   = 11;
    public static final int T_ARRAY    = 0x10;
    public static final int T_STRING   = ( T_ARRAY + T_CHAR );
    
	// write 8 bit value into the file
	static void writeFile8(int val, FileOutputStream file) throws IOException
	{
		file.write((byte)val);
        fileSize++;
        
        if( fileSize == maxSize )
        {
			System.out.println("File is too big! (max is " + maxSize + ")" );
			System.exit(-1);            
        }
	}
	
	// write 16 bit value into the file
	static void writeFile16(int val, FileOutputStream file) throws IOException
	{
	    writeFile8(val&0xff, file);
	    writeFile8((val>>8)&0xff, file);
	}
	
	// write 32 bit value into the file
	static void writeFile32(int val, FileOutputStream file) throws IOException
	{
	    writeFile8(val&0xff, file);
	    writeFile8((val>>8)&0xff, file);
	    writeFile8((val>>16)&0xff, file);
	    writeFile8((val>>24)&0xff, file);
	}

	// write string null terminated into the file
	static void writeStringFile(String str, FileOutputStream file) throws IOException
	{
		for(int j=0;j<str.length();j++) writeFile8(str.charAt(j), file);
            writeFile8(0, file);
	}

	// write uvm file header
	static void writeHeader(FileOutputStream file) throws ConvertException 
	{
		int offset = 20;
        int total_const;

		try
		{
            total_const = ClassLoader.totalConstantEntries() + 
                          CodeTranslator.interfaceGet().length +
                          ClassLoader.totalStrings() + 
                          ClassLoader.totalMethods() +
                          ClassLoader.totalClasses();
            
            Console.ConsoleLn("Total of statics " + ClassLoader.totalStaticFields());
            
			writeFile16(ClassLoader.totalMethods(), file);
			writeFile16(total_const, file);
			writeFile16(ClassLoader.totalClasses(), file);
			writeFile16(ClassLoader.totalStaticFields(), file);  
            writeFile16(0, file);

            writeFile16(ClassLoader.getMainIndex(), file);
			offset += 4 * ClassLoader.totalClasses(); // class header size: 4bytes

			// offset to constant data
			writeFile32(offset, file);
            offset += 4 * total_const;
			offset += totalConstantEntriesSize();
            offset = ( offset + 3 ) & ~3;

			// offset to string data
			// writeFile16(offset, file);
			offset += ClassLoader.totalStringSize();  // string data
            offset += CodeTranslator.interfaceStringLen(); // interface strings
			offset += ClassLoader.getMethodNamesSize();  // method name data
            offset += ClassLoader.getClassNamesSize();
            offset = ( offset + 3 ) & ~3;

			// offset to method data
			writeFile32(offset, file);
		}
		catch(IOException e)
		{
		}
	}

	// write all class headers
	static void writeClassHeaders(FileOutputStream file) throws ConvertException 
	{
		try
		{
			for(int i=0;i<ClassLoader.totalClasses();i++) 
			{
				ClassInfo classInfo = ClassLoader.getClassInfo(i);
                
                Console.ConsoleLn("class["+i+"] = "+classInfo.getName());

				writeFile16(classInfo.getSuperClassIndex(), file);
				writeFile16(classInfo.nonStaticFields(), file);
			}
		}
		catch(IOException e)
		{
		}
	}
    
    static int totalConstantEntriesSize()
    {
		int j = 0;

        for(int i=0;i<ClassLoader.totalConstantEntries();i++) 
        {
            if(ClassLoader.getConstantEntryType(i)==(byte)ConstPoolEntry.LONG) j += 4;
            j += 4;
        }
        
        return j;
    }

	// write all 32/64bit constant values
	static void writeConstantEntries(FileOutputStream file) throws ConvertException 
	{
        int total = ClassLoader.totalConstantEntries() + 
                    CodeTranslator.interfaceGet().length +
                    ClassLoader.totalStrings() + 
                    ClassLoader.totalMethods() + 
                    ClassLoader.totalClasses();
        int offset = ( 4 * total );
		int j = 0;

		Console.ConsoleLn("Writing " + total + " constant entries");

        try
		{
            // first write headers for constants
			for(int i=0;i<ClassLoader.totalConstantEntries();i++) 
			{
				if(ClassLoader.getConstantEntryType(i)==(byte)ConstPoolEntry.LONG)
				{
					Console.Console("  entry[" + j + "] = (LONG) 0x" + Long.toHexString(ClassLoader.getLongConstantEntryLow(i)));
                    writeFile16(T_LONG, file);
                    writeFile16(offset, file);

					Console.ConsoleLn(" / 0x" + Long.toHexString(ClassLoader.getLongConstantEntryHigh(i)));
					j++;
                    
                    offset += 8;
				}
                else if(ClassLoader.getConstantEntryType(i)==(byte)ConstPoolEntry.DOUBLE)
                {
					Console.ConsoleLn("  entry[" + j + "] = (DOUBLE) 0x" + Long.toHexString(ClassLoader.getLongConstantEntryLow(i)));
                    writeFile16(T_DOUBLE, file);
                    writeFile16(offset, file);

					Console.ConsoleLn(" / 0x" + Long.toHexString(ClassLoader.getLongConstantEntryHigh(i)));
					j++;
                    
                    offset += 8;                    
                }
                else if(ClassLoader.getConstantEntryType(i)==(byte)ConstPoolEntry.FLOAT)
                {
					Console.ConsoleLn("  entry[" + j + "] = (FLOAT) 0x" + Integer.toHexString(ClassLoader.getConstantEntry(i)));
                    writeFile16(T_FLOAT, file);
                    writeFile16(offset, file);
					j++;

                    offset += 4;
                }
                else
				{
					Console.ConsoleLn("  entry[" + j + "] = (INT) 0x" + Integer.toHexString(ClassLoader.getConstantEntry(i)));
                    writeFile16(T_INT, file);
                    writeFile16(offset, file);
					j++;

                    offset += 4;
				}
			}
            
            // write string headers
			for(int i=0;i<ClassLoader.totalStrings();i++) 
			{
                String str = ClassLoader.getString(i);
                
                Console.ConsoleLn("  entry[" + j + "] = \"" + str+ "\"");
                
                writeFile16(T_STRING, file);
                writeFile16(offset, file);
                j++;
                
				offset += str.length()+1;
			}
            
            // write interface string headers
			for(int i=0;i<CodeTranslator.interfaceGet().length;i++) 
			{
                String str = CodeTranslator.interfaceGet()[i];
                
                Console.ConsoleLn("  entry[" + j + "] = \"" + str+ "\"");
                
                writeFile16(T_STRING, file);
                writeFile16(offset, file);
                j++;
                
				offset += str.length()+1;
			}            
            
            // write methods name headers
			for(int i=0;i<ClassLoader.totalMethods();i++) 
			{
                String str;
                
                str = ClassLoader.getMethod(i).getName() + ":" + ClassLoader.getMethod(i).getSignature();
                
                Console.ConsoleLn("  entry[" + j + "] = \"" + str+ "\"");
                
                writeFile16(T_STRING, file);
                writeFile16(offset, file);
                j++;
                        
				offset += str.length()+1;
			}
            
            // write class name headers
			for(int i=0;i<ClassLoader.totalClasses();i++) 
			{
                String str;
                
                str = ClassLoader.getClassInfo(i).getName();
                
                Console.ConsoleLn("  entry[" + j + "] = \"" + str+ "\"");
                
                writeFile16(T_STRING, file);
                writeFile16(offset, file);
                j++;
                        
				offset += str.length()+1;
			}

            // write constants itself
			for(int i=0;i<ClassLoader.totalConstantEntries();i++) 
			{
				if(ClassLoader.getConstantEntryType(i)==(byte)ConstPoolEntry.LONG)
				{
					writeFile32(ClassLoader.getLongConstantEntryLow(i), file);   
					writeFile32(ClassLoader.getLongConstantEntryHigh(i), file);      	
				}
                else if(ClassLoader.getConstantEntryType(i)==(byte)ConstPoolEntry.DOUBLE)
                {
					writeFile32(ClassLoader.getLongConstantEntryLow(i), file);   
					writeFile32(ClassLoader.getLongConstantEntryHigh(i), file);      	
                }
                else if(ClassLoader.getConstantEntryType(i)==(byte)ConstPoolEntry.FLOAT)
                {
					writeFile32(ClassLoader.getConstantEntry(i), file);
                }
                else
				{
					writeFile32(ClassLoader.getConstantEntry(i), file);
				}
			}
            
			// write the strings itself
			for(int i=0;i<ClassLoader.totalStrings();i++) 
			{
				String str = ClassLoader.getString(i);

				// write zero terminated c strings
				for(j=0;j<str.length();j++) writeFile8(str.charAt(j), file);
				writeFile8(0, file);
			}

			// write the interface name itself
			for(int i=0;i<CodeTranslator.interfaceGet().length;i++) 
			{
                String str = CodeTranslator.interfaceGet()[i];

				// write zero terminated c strings
				for(j=0;j<str.length();j++) writeFile8(str.charAt(j), file);
				writeFile8(0, file);
			}
            
			// write the method names itself
			for(int i=0;i<ClassLoader.totalMethods();i++) 
			{
                String str;
                        
                str = ClassLoader.getMethod(i).getName() + ":" + ClassLoader.getMethod(i).getSignature();

				// write zero terminated c strings
				for(j=0;j<str.length();j++) writeFile8(str.charAt(j), file);
				writeFile8(0, file);
			}   
            
			// write the class names itself
			for(int i=0;i<ClassLoader.totalClasses();i++) 
			{
                String str;
                        
                str = ClassLoader.getClassInfo(i).getName();

				// write zero terminated c strings
				for(j=0;j<str.length();j++) writeFile8(str.charAt(j), file);
				writeFile8(0, file);
			}   
            
            while( ( fileSize & 0x03 ) != 0 )
            {
                writeFile8(0, file);
            }
		}
		catch(IOException e)
		{
		}
	}

	// write debug information
	static void writeDebugInfo() throws IOException
	{
	    // build up filename
        int index_ref;
	    String fileName = ClassLoader.getClassInfo(0).getName()+".bug";

		if(Config.getFileName() != null)
			fileName = Config.getFileName() + ".bug";		

	    // open file
		Console.ConsoleLn("Writing to debug file " + fileName);
		File outputDebugFile = new File(fileName);
		FileOutputStream bug = new FileOutputStream(outputDebugFile);

		// write binary name
	    String binFileName = ClassLoader.getClassInfo(0).getName()+".bin";

		if(Config.getFileName() != null)
			fileName = Config.getFileName() + ".bin";	
		
        index_ref = fileSize;
	    writeStringFile(binFileName, bug);
        
        while( ( index_ref + 256 ) > fileSize )
        {
            writeFile8(0, bug);
        }        
        
        // write method indexes
        int method_index = fileSize + ( 4 * ( ClassLoader.totalMethods() + 1 ) );
        for(int i=0;i<ClassLoader.totalMethods();i++)
        {
	    	MethodInfo methodInfo = ClassLoader.getMethod(i);
            if( methodInfo.getCodeInfo() == null ) continue;
            
            writeFile32(method_index, bug);
			LineNumberInfo[] line_num = methodInfo.getCodeInfo().getLineNumberTable();
            
            int total_size = 256 + 4 + ( ( line_num.length + 1 ) * 4 );
            method_index += total_size;
        }
        
        // end of list
        writeFile32(0, bug);
        
		// write methods
	    for(int i=0;i<ClassLoader.totalMethods();i++)
	    {
		    ClassInfo classInfo = ClassLoader.getClassInfoFromMethodIndex(i);
	    	MethodInfo methodInfo = ClassLoader.getMethod(i);
            if( methodInfo.getCodeInfo() == null ) continue;
            
			LineNumberInfo[] line_num = methodInfo.getCodeInfo().getLineNumberTable();
            
            //int total_size = 4 + 256 + 4 + ( ( line_num.length + 1 ) * 4 );
            //writeFile32(total_size, bug);
	    	
			// write source name
            index_ref = fileSize;
			// writeStringFile(classInfo.getSourceFile(), bug);
            String filename = "..\\src\\" + classInfo.getClassFilename() + ".java";
            filename = filename.replace('/', '\\');
            writeStringFile(filename, bug);
            
            while( ( index_ref + 256 ) > fileSize )
            {
                 writeFile8(0, bug);
            }    
            
            // write method ID
            writeFile32((ClassLoader.getClassIndex(i) << ClassLoader.Shift_Size) + MethodIdTable.getEntry(i), bug);
            
			// write lines
            // writeFile32(line_num.length, bug);

            for( int j = 0; j < line_num.length; j++ )
			{
				writeFile16(line_num[j].startPC, bug);
				writeFile16(line_num[j].lineNumber, bug);
			}
            
            writeFile32(0, bug);
	    }

        writeFile32(0, bug);
	    
		bug.close();
	}
	
	// write all methods
	static void writeMethods(FileOutputStream file) throws ConvertException 
	{
		int codeOffset = 0;
        int methodHeaderSize = 20;
        int pred_fileSize = fileSize;
        
		// build the method id table
		Console.ConsoleLn("build the method id table");
		MethodIdTable.build();

		// write all Method headers
		Console.ConsoleLn("write all Method headers");

		codeOffset = ClassLoader.totalMethods()*methodHeaderSize;
        pred_fileSize += ClassLoader.totalMethods()*methodHeaderSize;
        
		try
		{
            CodeTranslator.interfaceClear();
            
			for(int i=0;i<ClassLoader.totalMethods();i++) 
			{
				MethodInfo methodInfo = ClassLoader.getMethod(i);
                ClassInfo classInfo = ClassLoader.getClassInfoFromMethodIndex(i);
				int method_flag = 0;

                ExceptionInfo[] exceptionTable = null;
                LineNumberInfo[] line_num = null;
                
                int max_locals = 0;
                int max_stack = 0;
                int code_size = 0;
                
                if( methodInfo.getCodeInfo() == null ) {
                    // this is a native method
                    exceptionTable = new ExceptionInfo[0];
                    line_num = new LineNumberInfo[0];
                    method_flag = MethodFlags.NATIVE;
                    code_size = methodInfo.getName().length() + methodInfo.getSignature().length() + 2;
                } else {
                    exceptionTable = methodInfo.getCodeInfo().getExceptionTable();
                    line_num = methodInfo.getCodeInfo().getLineNumberTable();      
                    
                    max_locals = methodInfo.getCodeInfo().getMaxLocals();
                    max_stack = methodInfo.getCodeInfo().getMaxStack();
                }
                
				// int index = ClassLoader.getMethodIndex(methodInfo.getSignature()
				Console.ConsoleLn("Name = "    + methodInfo.GetMainIndex() + " "
                                               + Integer.toHexString(MethodIdTable.getEntry(i)) + " "
                                               + ClassLoader.getClassIndex(i) + " "
											   + methodInfo.getName() + ":" 
											   + methodInfo.getSignature());
	      
				writeFile32(codeOffset, file);     				 								   
				
				// code_index 
                if( methodInfo.getCodeInfo() != null ) {
					writeFile32((ClassLoader.getClassIndex(i) << ClassLoader.Shift_Size) + MethodIdTable.getEntry(i), file);  // id
                } else {
                    writeFile32(0xFFFFFFFF, file);
                }
                
                writeFile16(methodInfo.GetMainIndex(), file);

                if( methodInfo.getName().equals("<clinit>") ) {
                    method_flag |= MethodFlags.INIT;
                }
                
                if( ( methodInfo.getAccessFlags() & AccessFlags.STATIC ) != 0 ) {
                    method_flag |= MethodFlags.STATIC;
                }
                
                if( ( methodInfo.getAccessFlags() & AccessFlags.SYNCHRONIZED ) != 0 ) {
                    method_flag |= MethodFlags.SYNCHRONIZED;
                }
                
				writeFile8(method_flag, file);				// flags
                
                writeFile8(methodInfo.getArgs(), file);       // args
				writeFile8(max_locals, file);           // max_locals
				writeFile8(max_stack, file);            // max_stack
                
                writeFile8( exceptionTable.length, file );
                
                if( methodInfo.getCodeInfo() != null ) {
                    writeFile8( line_num.length + 1, file );
                } else {
                    writeFile8( 0, file );
                }

                if( methodInfo.getCodeInfo() != null ) {
                    // include exception table and debug
                    codeOffset += (8*exceptionTable.length); 
                    codeOffset += (4*line_num.length) + 4; 

                    pred_fileSize += (8*exceptionTable.length); 
                    pred_fileSize += (4*line_num.length) + 4; 

	                // get total of arguments references
	                boolean state = Console.isEnabled;
	                Console.isEnabled = false;
					byte code[] = ClassLoader.getMethod(i).getCodeInfo().getBytecode().clone();
	                classInfo.getConstPool().argsClear();
	
					CodeTranslator.translate(classInfo, code);
	                codeOffset += (4*classInfo.getConstPool().argsGet().length);

	                pred_fileSize += (4*classInfo.getConstPool().argsGet().length);
	
                    Console.isEnabled = state;
	                
                    code_size = code.length;
                }
                
                if( methodInfo.getCodeInfo() != null ) {
                    writeFile8( classInfo.getConstPool().argsGet().length, file );
                } else {
                    writeFile8(0, file);       // args
                }
            
                writeFile8( 0, file );
                writeFile16( code_size, file );

				// add code size (original code)
                codeOffset += code_size;
                pred_fileSize += code_size;
                
                while( ( pred_fileSize & 0x03 ) != 0 )
                {
                    codeOffset++;
                    pred_fileSize++;
                }                
			}

			codeOffset = ClassLoader.totalMethods()*methodHeaderSize;
            CodeTranslator.interfaceClear();
            
			// write bytecode
			for(int i=0;i<ClassLoader.totalMethods();i++) 
			{
				ClassInfo classInfo = ClassLoader.getClassInfoFromMethodIndex(i);
				MethodInfo methodInfo = ClassLoader.getMethod(i);
                int code_size = 0;

				Console.ConsoleLn("Converting " +  classInfo.getName() + "." +
													methodInfo.getName() + ":" +
													methodInfo.getSignature());

                if( methodInfo.getCodeInfo() == null ) {
                    String method_name = methodInfo.getName() + ":" + methodInfo.getSignature();
                    System.out.println( "Native method: " + method_name );
                    writeStringFile(method_name, file);
                    code_size = method_name.length() + 1;
                } else {
					byte code[] = ClassLoader.getMethod(i).getCodeInfo().getBytecode();
	
					// adjust references etc
	
	                classInfo.getConstPool().argsClear();
					CodeTranslator.translate(classInfo, code);
	
					// get debug and exception tables
					ExceptionInfo[] exceptionTable = methodInfo.getCodeInfo().getExceptionTable();
	                LineNumberInfo[] line_num = methodInfo.getCodeInfo().getLineNumberTable();
	                
					codeOffset += (8*exceptionTable.length); // include exception table
	                codeOffset += (4*line_num.length) + 4;
	                
					// insert exception table
					for( int j = 0; j < exceptionTable.length; j++ )
					{
						int exception_num = ClassLoader.getClassIndex(exceptionTable[j].catchType);
	                    
						if(exception_num < 0) 
							exception_num = NativeMapper.getNativeClassId(exceptionTable[j].catchType);                
	
	                    writeFile16(exceptionTable[j].startPC, file);
	                    writeFile16(exceptionTable[j].endPC, file);
	                    writeFile16(exceptionTable[j].handlerPC, file);
	                    writeFile16(exception_num, file);
					}
	
	                // insert debug table
	                for( int j = 0; j < line_num.length; j++ )
	                {
	                    writeFile16(line_num[j].startPC, file);
	                    writeFile16(line_num[j].lineNumber, file);
	                }
	                
	                writeFile16(code.length, file);
	                writeFile16(line_num[line_num.length-1].lineNumber, file);
	                
	                // insert arg refs
	                int[] arg_refs = classInfo.getConstPool().argsGet();
	                for( int j = 0; j < arg_refs.length; j++ )
	                {
	                    writeFile32( arg_refs[j] , file );
	                    codeOffset += 4;
	                }
	                
	                // and write bytecode
					for(int j=0;j<code.length;j++)
						writeFile8(code[j], file);
	
                    code_size = code.length;
                }

                codeOffset += code_size;		
                
                while( ( fileSize & 0x03 ) != 0 )
                {
                    codeOffset++;
                    writeFile8(0, file);
                }

				Console.ConsoleLn(""); 
			}			
		}
		catch(IOException e)
		{
		}

	}

    static private void loadInterfaces()
    {
        CodeTranslator.interfaceClear();
        
        boolean state = Console.isEnabled;
        Console.isEnabled = false;

        for(int i=0;i<ClassLoader.totalMethods();i++) 
        {
            MethodInfo methodInfo = ClassLoader.getMethod(i);
            ClassInfo classInfo = ClassLoader.getClassInfoFromMethodIndex(i);            

            if( methodInfo.getCodeInfo() != null ) {
                // run code translator to find list of interfaces
                byte code[] = ClassLoader.getMethod(i).getCodeInfo().getBytecode().clone();
                CodeTranslator.translate(classInfo, code);
            }            
        }
        
        Console.isEnabled = state;
    }
    
  	static public void binaryWrite() 
	{
        maxSize = Config.getMaxSize();
		Console.ConsoleLn("Generating unified class file ... (" + maxSize + ")");

		try 
		{
			String fileName = ClassLoader.getClassInfo(0).getName()+".rja";
            fileSize = 0;
			
			// if a file name has been specified in the Config file or 
			// via the command line use that
			if(Config.getFileName() != null)
				fileName = Config.getFileName() + ".rja";
			
			Console.ConsoleLn("Writing to file " + fileName);
			File outputFile = new File(fileName);
			FileOutputStream out = new FileOutputStream(outputFile);

            loadInterfaces();           // collect interfaces
			writeHeader(out);           // write file header
			writeClassHeaders(out);     // write class headers
			writeConstantEntries(out);  // write all constants and strings
			writeMethods(out);          // write method headers and byte code
			out.close();

            fileSize = 0;
			writeDebugInfo();			// write debug information
		}
		catch(ConvertException e) 
		{
			System.out.println("Conversion failed: " + e.toString());
			System.exit(-1);
		}
		catch(IOException e)
		{
			System.out.println("Conversion failed: " + e.toString());
			System.exit(-1);
		}
	}
}
