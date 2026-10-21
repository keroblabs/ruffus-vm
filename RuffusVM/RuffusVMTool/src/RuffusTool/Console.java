import java.io.*;
import java.util.*;

public class Console
{
    public static boolean isEnabled = true;
    
	public static void ConsoleLn(String msg)
	{
		if( ( Config.getVerbose() == true ) && ( isEnabled == true ) )
		{
			System.out.println(msg);
		}
	}

	public static void Console(String msg)
	{
		if( ( Config.getVerbose() == true ) && ( isEnabled == true ) )
		{
			System.out.print(msg);
		}
	}
}

