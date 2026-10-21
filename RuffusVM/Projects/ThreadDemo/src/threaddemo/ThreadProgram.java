package ThreadDemo;

import java.util.*;

public class ThreadProgram extends ThreadSuper
{
	private Timer myTimer;
	//private Vector<Object> myArray;
	
	public ThreadProgram()
	{
		Date now = new Date();
		//myArray = new Vector<Object>(10);
		//System.out.println("Thread Program " + myArray.size());
		System.out.println("Thread Program");
		System.out.println(now.toString());
	}
	
	public void OnTimerEvent()
	{
		System.out.println("Timer event");
	}
	
	public void OnRunnable()
	{
		System.out.println("Runnable event");
	}
	
	final Runnable myRunnable = new Runnable() 
	{
        @Override
		public void run() 
		{
			OnRunnable();
            
            try
            {
                Thread.sleep(2000);
            }
            catch (InterruptedException e)
            {
                System.out.println( "interrupted" );	
            }
			OnRunnable();
            
		}
	};
	
	@Override
	public void my_run()
	{
		System.out.println("Thread Program - starting");
		
		myTimer = new Timer();
		myTimer.schedule(new TimerTask() 
			{
				@Override
				public void run() 
				{	
					OnTimerEvent(); 
				}
	  	    }, 0, 1000); 			
		
		if( my_id == 0 )
		{
			System.out.println("Wrong thread ID!!");
		}
		
		new Thread(myRunnable).start();
		
		try
		{
			synchronized(this)
			{
				System.out.println("object in use");
				Thread.sleep(5000);
			}
		}
		catch (InterruptedException e)
		{
			System.out.println( "interrupted" );	
		}
			
		Thread.yield();
		myTimer.cancel();

		try
		{
			System.out.println("Thread Program - threading");
			Thread.sleep(4500);
			// wait();
		}
		catch (InterruptedException e)
		{
			System.out.println( "interrupted" );	
		}
		finally
		{
			System.out.println( "finally" );	
			notify();
		}
	}
}
