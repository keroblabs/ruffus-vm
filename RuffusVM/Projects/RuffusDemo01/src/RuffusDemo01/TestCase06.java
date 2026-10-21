package RuffusDemo01;

public class TestCase06
{
    private TestCase06() {
        
    }
    
    public static void Execute() {
        System.setProperty("prop.keypress", "true");
        System.out.println(System.getProperty("prop.keypress"));
    }
}
