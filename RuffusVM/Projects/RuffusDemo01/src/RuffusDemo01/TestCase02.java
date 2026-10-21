package RuffusDemo01;

import java.util.*;
import java.io.*;

public class TestCase02
{
    private RandomAccessFile file1;
    private Random random;
    
    public TestCase02(String filename)
    {
        System.out.println("Write in binary format sequence of random numbers");
        
        try {
            file1 = new RandomAccessFile(filename, "w");
        } catch(IOException ex) {
            System.out.println("Error creating file - " + ex.toString());
        }
        
        random = new Random();
    }
    
    public void Execute()
    {
        try {
            for( int i = 0; i < 20; i++ ) {
                int result = random.nextInt();
                file1.writeInt(result);
                System.out.println("Random = 0x" + Integer.toHexString(result));
            }
            
            file1.close();
        } catch(IOException ex) {
            System.out.println("Error writing to file - " + ex.toString());
        }        
    }    
}
