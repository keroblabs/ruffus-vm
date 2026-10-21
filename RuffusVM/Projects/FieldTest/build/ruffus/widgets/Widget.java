package ruffus.widgets;

import ruffus.graphics.Colour;

public class Widget {

    public static final int WIDGET_COLOUR_STATE0 = 0;
    public static final int WIDGET_COLOUR_STATE1 = 1;
    public static final int WIDGET_COLOUR_TEXT = 2;
    public static final int WIDGET_COLOUR_FRAME = 3;
    public static final int WIDGET_COLOUR_RESERVED0 = 4;
    public static final int WIDGET_COLOUR_RESERVED1 = 5;
	
	public native void addChild( Widget widget, int posx, int posy );
	
	public native void setColour( Colour color, int index );
	
	public native String getCaption();
	public native void setCaption( String text );
	
	public native void update();
	public native void setPosition( int posx, int posy );
	public native void show( int posx, int posy );
	
	public native static void updateAll();
    
}
