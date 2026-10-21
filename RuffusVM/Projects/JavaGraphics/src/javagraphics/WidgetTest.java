
package JavaGraphics;

import java.util.HashSet;
import ruffus.graphics.Colour;
import ruffus.system.EventArgs;
import ruffus.system.Eventable;
import ruffus.system.InputPointer;
import ruffus.widgets.Button;
import ruffus.widgets.Form;
import ruffus.widgets.TextBox;

public class WidgetTest {
    
    private Button button;
    private TextBox text_box;
    private Form my_form;
    private InputPointer tts;
    
    public WidgetTest() {
    }
    
    public void Execute() {
        button = Button.create(60, 35, "OK");
        text_box = TextBox.create(150, 12, "");

        my_form = Form.create(200, 150, "My Form");
        my_form.setPosition(10, 150);
        
        my_form.addChild(button, 10, 80);
        my_form.addChild(text_box, 10, 24);
        
        my_form.update();
        
        tts = new InputPointer();
        
        tts.setOnEvent( new Eventable() {
            @Override
            public void onRun( Object obj, EventArgs arg ) {
                InputPointer _tts = ( InputPointer )obj;
                if( _tts.state == InputPointer.TTS_DOWN ) {
                    String caption;
                    
                    caption = _tts.posX + " x " + tts.posY + "  ";
                    text_box.setCaption(caption);
                    text_box.update();
                }
            }
        });
        
    }
    
    void stop() {
        tts.stop();
    }
}
