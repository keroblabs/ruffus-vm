package RuffusDemo01;

public class EventTrigger extends TriggerThread
{
    private static native boolean native_check_status();
    private static native void native_set_object(Class obj);
    private int cnt;

    public EventTrigger() {
    }
    
    public void setObject() {
        native_set_object(this.getClass());
        cnt = 0;
    }

    @Override
    protected boolean triggerCheck() {
        if( native_check_status() == true ) {
            return true;
        }
        cnt++;
        return false;
    }    
    
    public static void calledByNative( int i ) {
        System.out.println( "Called by native " + i ); // + " " + cnt );
    }
}
