package DisposableTest;

import java.util.Calendar;
import ruffus.objects.Disposable;

public class StringTest extends Disposable {
    private String str;
    
    public StringTest() {
    }
    
    public void Execute() {
        str = new String();
        
        load_String( str );
        setDisposable( str );
        objectDispose( str );
        
        System.out.println( "3. " + str );
    }
    
    public void load_String( Object obj ) {
        String _str;
        _str = Calendar.getInstance().toString();
        System.out.println( "1. " + _str );

        obj = objRedirect(_str, obj);
        System.out.println( "2. " + (String)obj );
    }

    @Override
    public void OnDisposed(Object c) {
        load_String(c);
    }
}
