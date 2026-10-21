package RuffusDemo01;

public class RunnableTest
{
    public RunnableTest() {
    }
    
    public void Execute()
    {
        try {
            EventTrigger event = new EventTrigger();
            event.setObject();
            
            event.setOnEvent( new Runnable() {
                @Override
                public void run()
                {
                    System.out.println( "Runnable thread" );
                }
            });

            Thread.sleep(10000);
        } catch( InterruptedException ex ) {
        }
    }
}
