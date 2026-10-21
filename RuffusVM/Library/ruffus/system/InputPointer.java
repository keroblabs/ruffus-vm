package ruffus.system;

public class InputPointer {

	public static native boolean readTTS( Object obj );
    public static native void initTTS( Object obj );
        
	public static final int TTS_NONE = 0;
	public static final int TTS_DOWN = 1;
	public static final int TTS_UP = 2;

	public int posX;
	public int posY;
	public int state; 
    public boolean onTTS;
	
    private Eventable m_event;
    private Thread m_thread;
    private boolean is_run;
    
	final Runnable ttsRunnable = new Runnable() {
        @Override
		public synchronized void run() {
            while( is_run == true ) {
                if( readTTS(InputPointer.this) == true ) {
                    m_event.onRun(InputPointer.this, EventArgs.Empty);
                }
                Thread.yield();
            }
            
            this.notify();
		}
	};
    
	public InputPointer() { 
        is_run = false;
    }
    
    public void stop() {
        is_run = false;
        try {
            ttsRunnable.wait();
        } catch (InterruptedException ex) {
        }
    }
    
    public void setOnEvent(Eventable event) {
        initTTS( this );
        m_event = event;
        if( is_run == false ) {
            is_run = true;
            m_thread = new Thread( ttsRunnable );
            m_thread.start();
        }
    }    
}
