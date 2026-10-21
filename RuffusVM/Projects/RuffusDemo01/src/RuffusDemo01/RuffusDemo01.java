package RuffusDemo01;

public class RuffusDemo01
{
    public static void main(String[] args)
    {
        // write sequence in a text file
        //TestCase01 test_01 = new TestCase01("/local/result_01.txt");
        //test_01.Execute();
        
        // write sequence in a binary file
        TestCase02 test_02 = new TestCase02("/local/result_02.bin");
        test_02.Execute();

        // read sequence from a binary file created above
        //TestCase03 test_03 = new TestCase03("/local/result_02.bin");
        //test_03.Execute();
        
        // Calendar test
        //TestCase04 test_04 = new TestCase04();
        //test_04.Execute();
        
        // Tokenizer test
        //TestCase05 test_05 = new TestCase05( "this is a token test" );
        //test_05.Execute();      
        
        // test a trigger thread
        RunnableTest runnable_test = new RunnableTest();
        runnable_test.Execute();    
        
        // test of properties
        //TestCase06.Execute();
        
        // test class name
        TestCase07 test_07 = new TestCase07();
        test_07.Execute();
    }
}
