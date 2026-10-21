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

import java.io.*;
import java.util.HashSet;
import java.util.Set;
import java.util.Vector;
import java.util.StringTokenizer;

public class ClassLoader {
  static private Vector classes = new Vector();
  static private String classPath = null;
  static private String currClass = null;
  
  public static final int Shift_Size = 16;

  static public void setClassPath(String path) {
    classPath = path;
  }

  static public String getCurrClass() {
    return currClass;
  }
  
  static ClassInfo getClassInfo(int index) {
    return (ClassInfo)classes.elementAt(index);
  }

  static ClassInfo getClassInfo(String className) {
    // search through all classes
    for(int i=0;i<classes.size();i++) {
      if(getClassInfo(i).getName().equals(className))
	return getClassInfo(i);
    }

    return null;
  }

  // in an uvm file all methods of all classes are stored after each other
  // this method returns the class index from the method index in this list
  static ClassInfo getClassInfoFromMethodIndex(int index) {
    int classIndex = 0;
    
    // search through all classes
    while(index >= getClassInfo(classIndex).methods()) 
      index -= getClassInfo(classIndex++).methods();

    return getClassInfo(classIndex);
  }

  // get index of class named className
  public static int getClassIndex(String className) {
    // search through all classes
    for(int i=0;i<classes.size();i++) {
        //if( className.equals("[Ljava/lang/Integer;") )
            //Console.ConsoleLn(getClassInfo(i).getName());
      if(getClassInfo(i).getName().equals(className))
        return i;
    }
    return -1;
  }

  public static boolean methodExists(String className, 
				     String name, String type) {
    // search through all classes

    for(int i=0;i<classes.size();i++) {
      ClassInfo classInfo = getClassInfo(i);

      if((classInfo.getName().equals(className)) &&
	 (classInfo.providesMethod(name, type)))
	return true;
    }
    return false;
  }

	// search through all classes and return index of matching method
	public static int getMethodIndex(String className, String name, String type) 
	{
	  	int ret;
	  	int class_index;
		String super_class;
		ClassInfo class_info;
		
	    for(int i=0, index=0;i<classes.size();i++) 
	    {
	    	// search for the class
	    	if(getClassInfo(i).getName().equals(className)) 
	    	{
	    		// found, now search for the method
				ret = getClassInfo(i).getMethodIndex(name, type);
				if( ret == -1 )
				{
					// didnt find, so go to super class
					class_index = i;
					
					while( class_index != -1 )
					{
						// get super class data
						super_class = getClassInfo(class_index).getSuperClassName();
						class_index = getClassIndex(super_class);

						// check for native super-class
						if( class_index == -1 )
						{
							Console.Console("(native) ");
							return NativeMapper.getMethodId(super_class, name, type);
						}

						// search the method in the super class
						ret = getClassInfo(class_index).getMethodIndex(name, type);
						if( ret != -1 )
						{
							int val = getClassInfo(class_index).getMethod(ret).GetMainIndex();
							// finally found the method, return the index
							//index += ret;
							//return index;
							return val;
						}
					}
				}
				index += ret;
				return index;
	      	} else
			index += getClassInfo(i).methods();
	    }
	    return -1;
	}

  public static boolean fieldExistsExact(String className, 
				    String name, String type) {
    // search through all classes
    for(int i=0;i<classes.size();i++) {
      ClassInfo classInfo = getClassInfo(i);

      if((classInfo.getName().equals(className)) &&
	 (classInfo.providesField(name, type)))
	return true;
    }
    return false;
  }
  
  public static boolean fieldExists(String className,
                                    String name, String type) {
    while (className!=null) {
      if (fieldExistsExact(className, name, type))
        return true;
      className = getSuperClassName(className);
    }
    return false;
  }

  public static FieldInfo getFieldInfoExact(String className, 
				       String name, String type) {
    // search through all classes
    for(int i=0;i<classes.size();i++) {
      ClassInfo classInfo = getClassInfo(i);

      if(classInfo.getName().equals(className))
	return classInfo.getFieldInfo(name, type);
    }
    return null;
  }

  public static FieldInfo getFieldInfo(String className,
                                       String name, String type) {
    while (className!=null) {
      FieldInfo result = getFieldInfoExact(className, name, type);
      if (result!=null)
        return result;
      className = getSuperClassName(className);
    }
    return null;
  }


  public static String getSuperClassName(String className) {
    // search through all classes
    for(int i=0;i<classes.size();i++) {
      ClassInfo classInfo = getClassInfo(i);

      if(classInfo.getName().equals(className))
	return classInfo.getSuperClassName();
    }
    return null;
  }

  // search for a static field and sum up all static fields before,
  // this gives us the offset to this static field in the table
  // of all static fields of our set of class files
  public static int getStaticFieldIndex(String className, 
					String name, String type) {
    // search through all classes
    for(int i=0, cnt=0;i<classes.size();i++) {
      ClassInfo classInfo = getClassInfo(i);

      if(classInfo.getName().equals(className))
	return cnt + classInfo.getFieldIndex(AccessFlags.STATIC, name, type);
      else
	cnt += classInfo.staticFields();
    }
    return -1;
  }

  // get total methods of all classes
  public static int totalMethods() {
    int num = 0;

    for(int i=0;i<classes.size();i++) 
      num += getClassInfo(i).methods();

    return num;
  }

  public static int totalConstantEntries() {
    int sum = 0;

    for(int i=0;i<classes.size();i++) 
      sum += getClassInfo(i).getConstPool().totalConstantEntries();

    return sum;
  }

  public static byte getConstantEntryType(int index)
  {
    int i=0;
    
    // search through all classes
    while(index >= getClassInfo(i).getConstPool().totalConstantEntries()) 
      index -= getClassInfo(i++).getConstPool().totalConstantEntries();

    return getClassInfo(i).getConstPool().getConstantEntryType(index);
  }
  
  public static int getConstantEntry(int index) {
    int i=0;
    
    // search through all classes
    while(index >= getClassInfo(i).getConstPool().totalConstantEntries()) 
      index -= getClassInfo(i++).getConstPool().totalConstantEntries();

    return getClassInfo(i).getConstPool().getConstantEntry(index);
  }

  public static long getLongConstantEntry(int index) {
    int i=0;
    
    // search through all classes
    while(index >= getClassInfo(i).getConstPool().totalConstantEntries()) 
      index -= getClassInfo(i++).getConstPool().totalConstantEntries();

    return getClassInfo(i).getConstPool().getLongConstantEntry(index);
  }
  
  public static int getLongConstantEntryLow(int index) {
    int i=0;
    
    // search through all classes
    while(index >= getClassInfo(i).getConstPool().totalConstantEntries()) 
      index -= getClassInfo(i++).getConstPool().totalConstantEntries();

    return (int)(getClassInfo(i).getConstPool().getLongConstantEntry(index));
  }

  public static int getLongConstantEntryHigh(int index) {
    int i=0;
    long high;
    
    // search through all classes
    while(index >= getClassInfo(i).getConstPool().totalConstantEntries()) 
      index -= getClassInfo(i++).getConstPool().totalConstantEntries();

    return (int)(getClassInfo(i).getConstPool().getLongConstantEntry(index) >> 32);
  }
  
  // get memory required to store all strings
  public static int totalStringSize() {
    int sum = 0;

    for(int i=0;i<classes.size();i++) 
      sum += getClassInfo(i).getConstPool().totalStringSize();

    return sum;
  }

  // get memory required to store all strings
  public static int totalStrings() {
    int sum = 0;

    for(int i=0;i<classes.size();i++) 
      sum += getClassInfo(i).getConstPool().totalStrings();

    return sum;
  }

  public static String getString(int index) {
    int i=0;
    
    // search through all classes
    while(index >= getClassInfo(i).getConstPool().totalStrings()) 
      index -= getClassInfo(i++).getConstPool().totalStrings();

    return getClassInfo(i).getConstPool().getString(index);
  }

  // total number of static fields
  public static int totalStaticFields() {
    int sum = 0;

    for(int i=0;i<classes.size();i++) {
      ClassInfo classInfo = getClassInfo(i);
      sum += classInfo.staticFields();
    }
    return sum;
  }

  // return index of main method (must be in class 0, since
  // it is the one the user gave as an argument)
  public static int getMainIndex() {
    return getClassInfo(0).getMethodIndex("main", "([Ljava/lang/String;)V");
  }
  
  public static MethodInfo getMethod(int index) {
    int i=0;
    
    // search through all classes
    while(index >= getClassInfo(i).methods()) 
      index -= getClassInfo(i++).methods();

    return(getClassInfo(i).getMethod(index));
  }

  public static int getMethodNamesSize() {
  	int size = 0;
	for(int i=0;i<totalMethods();i++) {
        size += getMethod(i).getName().length();  
        size += getMethod(i).getSignature().length()+2;        
	}
    
	return size;
  }

  public static int getClassNamesSize() {
  	int size = 0;
	for(int i=0;i<totalClasses();i++) {
        size += getClassInfo(i).getName().length() + 1;
	}
	return size;
  }
  
  public static int getMethodNameSize(int index) {
	return getMethod(index).getName().length();
  }  

  public static int totalClasses() {
    return classes.size();
  }

  // get class index of method with index 
  public static int getClassIndex(int index) {
    int i=0;
    
    // search through all classes
    while(index >= getClassInfo(i).methods()) 
      index -= getClassInfo(i++).methods();

    return i;
  }

  public static void constantRelocate(int i) {
    Console.ConsoleLn("request to relocate " + i);
  }

  static public void load(String name) {

    try {
      InputStream is = null;

      // walk through all paths stored in classpath
      StringTokenizer pathTokenizer = new StringTokenizer(classPath, File.pathSeparator);

      while((pathTokenizer.hasMoreElements()) && (is == null)) {
	String filename;
	String outname;
	String debugname;
  
	// build full base file name
	filename = pathTokenizer.nextToken();
	filename += "/";
	filename += name;
	filename += ".class";

	Console.ConsoleLn("Filename " + filename );
	
	try {
	  // load given class
	  is = new FileInputStream(filename);
	} catch(FileNotFoundException e) {
	  is = null;
	}
      }

      if(is == null)
	throw new FileNotFoundException("Unable to find class file " + name + ".class");

      Console.ConsoleLn("Loading class " + name );
      

      ClassInfo classInfo = new ClassInfo();

      currClass = name;
      classInfo.setClassFilename(currClass);
        
      new ClassFileReader().read(is, classInfo);
      is.close();
      // classes.addElement(classInfo);
      addClass(classInfo);
      
      Console.ConsoleLn("Checking dependencies ...");
      
      // go through all constants and check for method references
      classInfo.getConstPool().resolveMethodRefs();

    } catch(Exception e) {
      System.out.println("Error loading class: " + e.toString());
      System.exit(-1);
    }
  }

	public static void addClass( ClassInfo classInfo )
	{
		// first check if already exists
		for( int i = 0; i < totalClasses(); i++ )
		{
			//System.out.print("(" + i + ") is " + getClassInfo(i).getName() + " == " + classInfo.getName() + " ? ");
			if( getClassInfo(i).getName().compareTo( classInfo.getName() ) == 0 )
			{
				//System.out.println( "Yes" );
				return;
			}
			//System.out.println( "no" );
		}

		classes.addElement(classInfo);
	}
}

