@echo off
mkdir ..\RuffusVMTool\build\temp
copy ..\RuffusVMTool\src\RuffusTool\*.java ..\RuffusVMTool\build\temp /y > ..\RuffusVMTool\build\copy_log.txt
copy ..\RuffusVMTool\src\RuffusTool\*.mf ..\RuffusVMTool\build\temp /y > ..\RuffusVMTool\build\copy_log.txt
cd ..\RuffusVMTool\build\temp
javac -classpath . .\RuffusVMTool.java
jar cmf .\RuffusVMTool.mf ..\..\..\Projects\RuffusVMTool.jar *.class
del *.class /q
cd ..\..\..\Projects
del ..\RuffusVMTool\build\temp /q
rd ..\RuffusVMTool\build\temp /q
