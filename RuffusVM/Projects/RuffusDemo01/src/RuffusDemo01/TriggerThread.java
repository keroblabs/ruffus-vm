package RuffusDemo01;

public class TriggerThread extends Thread
{
    private Runnable m_task;
    
    public TriggerThread() {
    }
    
    public void setOnEvent(Runnable task) {
        m_task = task;
        start();
    }
    
    protected boolean triggerCheck() {
        return true;
    }
    
	@Override
	public void run() {
        while( true ) {

            if( triggerCheck() == true ) {
                new Thread(m_task).start();
                break;
            }

            Thread.yield();
        }
	} 
}
