package RuffusDemo01;

import java.util.*;
import java.io.*;

public class TestCase03
{
    private RandomAccessFile file1;
    
    public TestCase03(String filename)
    {
        System.out.println("Read integer from a binary file");
        
        try {
            file1 = new RandomAccessFile(filename, "r");
        } catch(IOException ex) {
            System.out.println("Error opening file - " + ex.toString());
        }
    }
    
    public void Execute()
    {
        try {
            for( int i = 0; i < 20; i++ ) {
                int result = file1.readInt();
                System.out.println("Read = 0x" + Integer.toHexString(result));
            }
            
            file1.close();
        } catch(IOException ex) {
            System.out.println("Error reading from file - " + ex.toString());
        }        
    }    
}
