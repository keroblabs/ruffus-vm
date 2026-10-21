package ThreadDemo;
import java.util.*;

public class ThreadDemo
{
	private static final int version = 11;
	private static final float f_value = ( float )10.0;
    private static Vector vector;

	public static void main(String[] args) 
	{
        vector = new Vector();
		System.out.println("Thread demo " + version);	
		
		ThreadProgram thread = new ThreadProgram();

		System.out.println("start thread");	
		thread.start();
        
        vector.add(version);
        vector.add((int)f_value);
        vector.add(1);
        vector.add(2);
        vector.add(3);
        vector.add(4);
        vector.add(5);
        vector.add(6);
        vector.add(7);
        vector.add(8);
        vector.add(9);
        
		thread.set_float( f_value );
		
        System.out.println("Boolean field TRUE = " + Boolean.TRUE);	
        System.out.println("Vector count = " + vector.size());	
        
        System.out.println("element at 5 = " + vector.toArray()[5]);
        // System.out.println("element at 5 = " + vector.elementAt(5));
		
		// switch( (int)thread.getId() )
		switch( ( int )thread.GetMyID() )
		{
			case 0:
				System.out.println("ID cant be defined on construction");	
				break;
				
			case 1:
				System.out.println("This is main thread");	
				break;

			case 2:
				System.out.println("This is second thread");	
				break;
				
			case 3:
				System.out.println("This is background thread");	
				break;
		}
		
		Thread.yield();
		
		System.out.println("Thread name1 = " + thread.toString().toUpperCase());
        
        try
        {
            System.out.println("Thread name2 = " + thread.toString().charAt(10));
        }
        catch(StringIndexOutOfBoundsException e)
        {
            System.out.println( e.toString() );
            System.gc();
        }
		
		System.out.println("try use object = " + thread.toString().concat(" 123"));
		synchronized(thread)
		{
			System.out.println("object released");
		}
		
		System.out.println("now wait");
		try
		{
			thread.wait();
		}
		catch (InterruptedException e)
		{
			System.out.println( "interrupted" );
			// System.out.println( e.toString() );
		}		
		
        System.out.println("Vector count 1 = " + vector.size());	
        System.out.println("Vector count 2 = " + vector.capacity());	
        System.out.println("Does contain 8 = " + vector.contains(8));
        
        Integer[] vector_array = new Integer[vector.size()];
        vector.copyInto(vector_array);
        //Integer[] vector_array = vector.toArray( new Integer[0] );

        for( int i = 0; i < vector_array.length; i++)
        {
            // System.out.print( vector_array[i].intValue() + " - ");
            System.out.print( vector_array[i] + " - ");
        }
		System.out.println("");	

        
		System.out.println("now in loop");	
		//Date now = new Date();
		System.out.println(new Date().toString());	

		while( true )
		{
		}
	}
}
