package FieldTest;

import ruffus.system.Eventable;
import ruffus.system.EventArgs;
import ruffus.widgets.Menu;
import ruffus.widgets.MenuItem;

public class ReadField {
    
    private Menu m_menu;
    private boolean is_exit;
    
    public ReadField() {
        is_exit = false;
    }
    
    public void Execute() {
        m_menu = new Menu( "Main menu", false);
        m_menu.addItem( new MenuItem( "Item 1", MenuItem.modeItem, new Eventable() {
                    @Override
                    public void onRun( Object obj, EventArgs arg ) {
                        System.out.println("Item 1 clicked");
                    }
                }));
        
        m_menu.addItem( new MenuItem( "Item 2", MenuItem.modeItem, new Eventable() {
                    @Override
                    public void onRun( Object obj, EventArgs arg ) {
                        System.out.println("Item 2 clicked");
                    }
                }));
        
        m_menu.addItem( new MenuItem( "Item 3", MenuItem.modeExit, new Eventable() {
                    @Override
                    public void onRun( Object obj, EventArgs arg ) {
                        System.out.println("This is exit");
                        is_exit = true;
                    }
                }));
        
        m_menu.onMove(new Eventable() {
                @Override
                public void onRun( Object obj, EventArgs arg ) {
                    Menu menu = ( Menu )obj;
                    System.out.println("Selected " + menu.currItem);
                }
            });
    }
    
    public boolean isExit() {
        Thread.yield();
        
        if( is_exit == true ) {
            m_menu.stop();
        }
        return is_exit;
    }
    
}
