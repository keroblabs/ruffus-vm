package ruffus.widgets;

import ruffus.system.Eventable;

public class MenuItem {

    public static final int modeNone = 0;
    public static final int modeItem = 1;
    public static final int modeMax = 2;
    public static final int modeSub = 3;
    public static final int modeExit = 4;

	public int index;
	public String caption;
	public Eventable handler;
	public int mode;
	
	public MenuItem( String _caption, int _mode, Eventable _handler ) {
        index = 0;
        caption = _caption;
        mode = _mode;
        handler = _handler;
    }
}
