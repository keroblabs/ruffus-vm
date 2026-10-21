package JavaGraphics;

import ruffus.graphics.Colour;
import ruffus.graphics.Drawing;

public class JavaGraphics {
    
    // public static 
    public static void main(String[] args) {
        Drawing.getInstance().clear();
        Drawing.getInstance().drawBox(10, 10, 50, 50, Colour.White);

        FlashingBox box = new FlashingBox( 70, 30 );
        box.Execute();
        
        //PaintTTS tts = new PaintTTS();
        //tts.Execute();
        
        WidgetTest widget = new WidgetTest();
        widget.Execute();
        
		try {
            System.out.println("Running box");
			Thread.sleep(10000);
            box.Stop();
            
            System.out.println("Now only widgets");
			Thread.sleep(10000);
            // tts.Stop();
            widget.stop();
		} catch (InterruptedException e) {
		}
    }
}
