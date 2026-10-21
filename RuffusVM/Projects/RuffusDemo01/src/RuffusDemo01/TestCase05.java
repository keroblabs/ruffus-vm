package RuffusDemo01;

import java.util.StringTokenizer;

public class TestCase05
{
    private String string_data;
    
    public TestCase05( String input )
    {
        string_data = input;
    }
    
    public void Execute()
    {
        StringTokenizer token = new StringTokenizer( string_data );
        
        while( token.hasMoreTokens() == true )
        {
            System.out.println("token = " + token.nextToken() );
        }
    }
}
