package ruffus.widgets;

import ruffus.system.Eventable;
import ruffus.system.EventArgs;
import ruffus.graphics.Drawing;
import ruffus.widgets.Widget;

import java.util.Vector;

public class Menu {

    public static native void menuInit(Object obj);
    public static native void menuDisplay(Object obj);
    
    public static final int msgNone = 0;
    public static final int msgMove = 1;
    public static final int msgClick = 2;
	
    public String menuTitle;
	public int currMessage;
    public int currItem;
    public boolean isCheck;
	public Vector itemList;
    
    public int startX;
    public int startY;
    public int titleX;
    public int titleY;
    public int spacingY;
    
    public Object _items_ptr;
    public Object _check_ptr;
    public Object _data_ptr;
    public Object _config_ptr;
    
    public int fontItems;
    public int fontTitle;
    
    private int totalItems;
    private Eventable m_moveEvent;
    private Thread m_thread;
    private boolean is_run;
    
    public Menu( String title, boolean is_check_menu ) {
        is_run = false;
        isCheck = is_check_menu;
        totalItems = 0;
        itemList = new Vector();
        
        // this force framework to set default values
        spacingY = -1;
        currItem = 0;
        currMessage = msgNone;
        menuTitle = title;
        
        fontTitle = Drawing.FONT_8X12;
        fontItems = Drawing.FONT_8X8;
    }
    
    public void addItem(MenuItem item) {
        item.index = totalItems;
        totalItems++;
        itemList.add(item);
    }
    
    public void SetPosition(int item_x, int item_y, int title_x, int title_y, int spacing) {
        startX = item_x;
        startY = item_y;
        titleX = title_x;
        titleX = title_x;
        spacingY = spacing;
    }
    
    public void setFonts( int itemfont, int titlefont ) {
        fontTitle = titlefont;
        fontItems = itemfont;
    }
            
    public int getItem() {
        return currItem;
    }
    
    public void onMove(Eventable event) {
        if( is_run == false ) {
            menuInit(this);
            m_moveEvent = event;
            
            is_run = true;
            m_thread = new Thread( menuRunnable );
            m_thread.start();
        }        
    }
    
    public void stop() {
        is_run = false;
        try {
            menuRunnable.wait();
        } catch (InterruptedException ex) {
        }
    }
    
	final Runnable menuRunnable = new Runnable() {
        @Override
		public synchronized void run() {
            while( is_run == true ) {
                menuDisplay(Menu.this);
                
                if( currMessage == msgClick ) {
                    //m_clickEvent.onRun(Menu.this, EventArgs.Empty);
                    MenuItem menu_item = (MenuItem)itemList.elementAt(currItem);
                    menu_item.handler.onRun(Menu.this, EventArgs.Empty);
                    currMessage = msgNone;
                } else if( currMessage == msgMove ) {
                    m_moveEvent.onRun(Menu.this, EventArgs.Empty);
                    currMessage = msgNone;
                }

                Thread.yield();
            }
            
            this.notify();
		}
	};    
}
