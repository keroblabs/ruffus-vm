#!/bin/sh
rm -rf ../RuffusVMTool/build/temp
mkdir ../RuffusVMTool/build/temp
cp ../RuffusVMTool/src/RuffusTool/*.java ../RuffusVMTool/build/temp
cp ../RuffusVMTool/src/RuffusTool/*.mf ../RuffusVMTool/build/temp

cd ../RuffusVMTool/build/temp
javac -classpath . ./RuffusVMTool.java
jar cmf ./RuffusVMTool.mf ../../../Projects/RuffusVMTool.jar *.class
cd ../../../Projects

