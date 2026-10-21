@echo off
md .\%1\build\%1
md .\%1\build\classes
copy .\%1\src\%1\*.java .\%1\build\%1 /y > .\%1\build\copy_log.txt
xcopy ..\Library .\%1\build /E /Y > .\%1\build\copy_log.txt
javac -g -classpath .\%1\build .\%1\build\%1\%1.java
IF ERRORLEVEL 1 GOTO End
copy .\%1\build\%1\*.class .\%1\build\classes /y >> .\%1\build\copy_log.txt
javap -c .\%1\build\classes\*.class > .\%1\build\%1.dis
java -jar .\RuffusVMTool.jar %2 -f .\%1\build\%1 ..\NativeClasses\Native.config .\%1\build %1\%1
:End
rd /s /q .\%1\build\classes
rem rd /s /q .\%1\build\%1
copy .\%1\build\%1.rja . > .\%1\build\copy_log.txt
:End2
