package JavaGraphics;

import java.util.Timer;
import java.util.TimerTask;
import ruffus.graphics.Colour;
import ruffus.graphics.Drawing;

public class FlashingBox
{
    private int counter;
    private Drawing gr;
    private int posx;
    private int posy;
    private Timer myTimer;
        
    public FlashingBox( int x, int y ) {
        gr = Drawing.getInstance();
        counter = 0;
        
        posx = x;
        posy = y;
    }
    
	public void OnTimerEvent() {
        Colour color = Colour.Black;
        
        counter++;
        switch( counter & 0x03 ) {
            case 0:
                color = Colour.Green;
                break;
                
            case 1:
                color = Colour.Yellow;
                break;

            case 2:
                color = Colour.Blue;
                break;
            
            case 3:
                color = Colour.White;
                break;
        }
        
        gr.fillBox(posx, posy, 50, 50, color);
	}    
    
    public void Execute() {
    	myTimer = new Timer();
		myTimer.schedule(new TimerTask() 
			{
				@Override
				public void run() 
				{	
					OnTimerEvent(); 
				}
	  	    }, 0, 400); 	
    }
    
    public void Stop() {
        myTimer.cancel();
    }
}
