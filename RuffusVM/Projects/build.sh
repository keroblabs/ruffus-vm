#!/bin/sh

mkdir ./$1/build/$1
cp ./$1/src/$1/*.java ./$1/build/$1
javac -g -classpath ./$1/build ./$1/build/$1/$1.java

verbose=""

if [ $# -eq 2 ] ; then
	verbose="-v"
fi

if [ $? -eq 0 ] ; then
	cp ./$1/build/$1/*.class ./$1/build/classes
	java -jar ./RuffusVMTool.jar $verbose -f ./$1/build/$1 ../NativeClasses/Native.config ./$1/build $1/$1
	#javap -c ./$1/build/classes/*.class > ./$1/build/$1.dis

	FILES=./$1/build/classes/*.class
	OUT=""

	for f in $FILES
	do
		echo ${f}
		file1=`echo ${f#./$1/build/classes/}`
		file=`echo $file1 | rev | cut -c7- | rev`
		OUT=$OUT" "$file
	done
	javap -c -classpath ./$1/build/classes $OUT > ./$1/build/$1.dis
	#javap -c -classpath ./$1/build/classes $OUT
fi
rm -rf /s /q ./$1/build/$1
cp ./$1/build/$1.rja .
