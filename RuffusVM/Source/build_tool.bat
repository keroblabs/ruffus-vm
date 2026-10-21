@echo off
del ..\RuffusVMTool\build\temp\*.java /q
del ..\RuffusVMTool\build\temp\*.class /q
copy ..\RuffusVMTool\src\RuffusTool\*.java ..\RuffusVMTool\build\temp /y > ..\RuffusVMTool\build\copy_log.txt
cd ..\RuffusVMTool\build\temp
javac -classpath . .\RuffusVMTool.java
jar cmf .\RuffusVMTool.mf ..\..\..\Projects\RuffusVMTool.jar *.class
cd ..\..\..\Projects
