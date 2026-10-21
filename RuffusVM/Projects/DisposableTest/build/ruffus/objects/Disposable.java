package ruffus.objects;

public class Disposable {
	private static native void vm_set_disposable(Class c, Object o);
	private static native boolean vm_is_disposable( Object o );
	private static native boolean vm_is_disposed( Object o );
    private static native void vm_dispose(Object o);
    private static native void vm_dispose_all();
    private static native Object vm_object_redirect( Object src, Object dest );
	
	public Disposable() {
	}
    
    public static void disposeAll() {
        vm_dispose_all();
    }
	
	public void setDisposable( Object c ) {
		vm_set_disposable( this.getClass(), c );
	}
    
    public Object objRedirect( Object src, Object dest ) {
        return vm_object_redirect(src,dest);
    }
	
	public void OnDisposed( Object c ) {
	}
    
    public void objectDispose( Object c ) {
        vm_dispose(c);
    }
	
	public boolean isDisposable( Object c ) {
		return vm_is_disposable(c);
	}

	public boolean isDisposed( Object c ) {
		return vm_is_disposed(c);
	}
}
