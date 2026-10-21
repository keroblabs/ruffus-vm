package JavaGraphics;

import ruffus.graphics.Colour;
import ruffus.graphics.Drawing;
import ruffus.system.EventArgs;
import ruffus.system.Eventable;
import ruffus.system.InputPointer;

public class PaintTTS
{
    private Drawing gr;
    private InputPointer tts;
    
    public PaintTTS() {
        gr = Drawing.getInstance();
    }
    
    public void Execute() {
        tts = new InputPointer();
        
        tts.setOnEvent( new Eventable() {
            @Override
            public void onRun( Object obj, EventArgs arg ) {
                InputPointer _tts = ( InputPointer )obj;
                if( _tts.state == InputPointer.TTS_DOWN ) {
                    gr.setPixel(_tts.posX, _tts.posY, Colour.White);
                }
            }
        });
    }
    
    public void Stop() {
        tts.stop();
    } 
}
