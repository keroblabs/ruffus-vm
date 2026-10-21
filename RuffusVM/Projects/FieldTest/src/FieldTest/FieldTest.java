package FieldTest;

import ruffus.graphics.Drawing;

public class FieldTest
{
    public static void main(String[] args) {
        Drawing.getInstance().clear();
        
        ReadField field_test = new ReadField();
        field_test.Execute();
        
        while( field_test.isExit() == false ) {
        }
        
        System.out.println("Exited");
    }
}
