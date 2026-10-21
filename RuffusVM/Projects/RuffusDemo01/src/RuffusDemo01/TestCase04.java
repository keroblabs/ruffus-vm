package RuffusDemo01;

import java.util.*;

public class TestCase04
{
    private Calendar calendar;
    
    public TestCase04()
    {
        System.out.println("Calendar test");
        calendar = Calendar.getInstance();
    }
    
    public void Execute()
    {
        // actual time
        System.out.println("Now     = " + calendar.getTime().toString());
        System.out.println("hour    = " + calendar.get(Calendar.HOUR));
        System.out.println("minute  = " + calendar.get(Calendar.MINUTE));
        System.out.println("seconds = " + calendar.get(Calendar.SECOND));

        System.out.println("day     = " + calendar.get(Calendar.DAY_OF_MONTH));
        System.out.println("month   = " + calendar.get(Calendar.MONTH));
        System.out.println("year    = " + calendar.get(Calendar.YEAR));
        
        // add 10 hours
        calendar.add(Calendar.HOUR, 10);
        System.out.println("hour    = " + calendar.get(Calendar.HOUR));
        System.out.println("minute  = " + calendar.get(Calendar.MINUTE));
        System.out.println("seconds = " + calendar.get(Calendar.SECOND));

        System.out.println("day     = " + calendar.get(Calendar.DAY_OF_MONTH));
        System.out.println("month   = " + calendar.get(Calendar.MONTH));
        System.out.println("year    = " + calendar.get(Calendar.YEAR));
        
        // reset calendar
        // calendar.clear();
        calendar = Calendar.getInstance();
        System.out.println("hour    = " + calendar.get(Calendar.HOUR));
        System.out.println("minute  = " + calendar.get(Calendar.MINUTE));
        System.out.println("seconds = " + calendar.get(Calendar.SECOND));
    }        
}
