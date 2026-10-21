package ruffus.graphics;

public class Drawing {
    
    public static final int FONT_4X6 =      0;
    public static final int FONT_5X12 = 	1;
    public static final int FONT_6X8 =      2;
    public static final int FONT_8X8 =      3;
    public static final int FONT_8X12 =     4;
    public static final int FONT_10X18 =	5;
    public static final int FONT_12X16 =	6;
    
    public native void clear();
	public native void fillBox(int posx, int posy, int width, int height, Colour colour);
	public native void drawBox(int posx, int posy, int width, int height, Colour colour);
	public native void drawLine(int posx1, int posy1, int posx2, int posy2, Colour colour);
	public native void drawLineTo(int posx2, int posy2, Colour colour);
	public native void setPixel(int posx, int posy, Colour colour);
	
	//public native void showBitmap(int posx, int posy, BitmapRGB bitmap);
	//public native void showBitmap(int posx, int posy, Bitmap1BPP bitmap);
	
	public native static Drawing getInstance();

	private Drawing() {
	}
	
}
