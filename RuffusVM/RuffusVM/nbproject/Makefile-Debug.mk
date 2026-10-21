#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc.exe
CCC=g++.exe
CXX=g++.exe
FC=gfortran
AS=as.exe

# Macros
CND_PLATFORM=MinGW-Windows
CND_DLIB_EXT=dll
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/131588722/io_outputstream.o \
	${OBJECTDIR}/_ext/131588722/native.o \
	${OBJECTDIR}/_ext/131588722/lang_runtime.o \
	${OBJECTDIR}/_ext/131588722/lang_byte.o \
	${OBJECTDIR}/_ext/131588722/lang_thread.o \
	${OBJECTDIR}/_ext/918017447/thread_lib.o \
	${OBJECTDIR}/_ext/131588722/util_vector.o \
	${OBJECTDIR}/_ext/131588722/io_fileoutputstream.o \
	${OBJECTDIR}/_ext/998369973/arrays_type.o \
	${OBJECTDIR}/_ext/918017447/util_vector_lib.o \
	${OBJECTDIR}/_ext/131588722/lang_system.o \
	${OBJECTDIR}/_ext/246765436/methods.o \
	${OBJECTDIR}/_ext/131588722/util_stringtokenizer.o \
	${OBJECTDIR}/_ext/131588722/lang_double.o \
	${OBJECTDIR}/_ext/131588722/io_inputstream.o \
	${OBJECTDIR}/_ext/131588722/lang_math.o \
	${OBJECTDIR}/_ext/131588722/lang_boolean.o \
	${OBJECTDIR}/_ext/246765436/vm.o \
	${OBJECTDIR}/_ext/998369973/stack.o \
	${OBJECTDIR}/_ext/131588722/util_timertask.o \
	${OBJECTDIR}/_ext/918017447/lang_number_lib.o \
	${OBJECTDIR}/_ext/998369973/value_type.o \
	${OBJECTDIR}/_ext/998369973/heap.o \
	${OBJECTDIR}/_ext/998369973/instance.o \
	${OBJECTDIR}/vsnprintk.o \
	${OBJECTDIR}/_ext/131588722/util_timezone.o \
	${OBJECTDIR}/_ext/246765436/threads.o \
	${OBJECTDIR}/_ext/998369973/objects.o \
	${OBJECTDIR}/_ext/131588722/util_date.o \
	${OBJECTDIR}/_ext/131588722/lang_number.o \
	${OBJECTDIR}/_ext/131588722/lang_stringbuilder.o \
	${OBJECTDIR}/_ext/246765436/vm_debug.o \
	${OBJECTDIR}/_ext/131588722/lang_object.o \
	${OBJECTDIR}/_ext/131588722/lang_process.o \
	${OBJECTDIR}/_ext/131588722/lang_short.o \
	${OBJECTDIR}/_ext/246765436/exceptions.o \
	${OBJECTDIR}/_ext/246765436/application.o \
	${OBJECTDIR}/_ext/131588722/lang_integer.o \
	${OBJECTDIR}/_ext/131588722/lang_string.o \
	${OBJECTDIR}/_ext/131588722/util_calendar.o \
	${OBJECTDIR}/_ext/131588722/lang_long.o \
	${OBJECTDIR}/_ext/131588722/util_bitset.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/_ext/131588722/io_printstream.o \
	${OBJECTDIR}/_ext/131588722/lang_float.o \
	${OBJECTDIR}/_ext/131588722/io_fileinputstream.o \
	${OBJECTDIR}/_ext/131588722/util_random.o \
	${OBJECTDIR}/_ext/131588722/lang_void.o \
	${OBJECTDIR}/_ext/131588722/io_file.o \
	${OBJECTDIR}/_ext/998369973/strings.o \
	${OBJECTDIR}/_ext/918017447/vm_java.o \
	${OBJECTDIR}/_ext/131588722/util_timer.o \
	${OBJECTDIR}/_ext/131588722/lang_character.o \
	${OBJECTDIR}/_ext/918017447/lang_string_lib.o \
	${OBJECTDIR}/_ext/1485326712/properties.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/ruffusvm.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/ruffusvm.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.c} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/ruffusvm ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/_ext/131588722/io_outputstream.o: ../Source/java_classes/io_outputstream.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/131588722
	${RM} $@.d
	$(COMPILE.c) -g -DRUFFUS_VM -DWIN32 -D_OBJECT_HANDLER -I../../ObjectHandler -I../Source/vm -I../Source/platform -I../Source/java_classes -I../Source/java -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/131588722/io_outputstream.o ../Source/java_classes/io_outputstream.c

${OBJECTDIR}/_ext/131588722/native.o: ../Source/java_classes/native.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/131588722
	${RM} $@.d
	$(COMPILE.c) -g -DRUFFUS_VM -DWIN32 -D_OBJECT_HANDLER -I../../ObjectHandler -I../Source/vm -I../Source/platform -I../Source/java_classes -I../Source/java -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/131588722/native.o ../Source/java_classes/native.c

${OBJECTDIR}/_ext/131588722/lang_runtime.o: ../Source/java_classes/lang_runtime.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/131588722
	${RM} $@.d
	$(COMPILE.c) -g -DRUFFUS_VM -DWIN32 -D_OBJECT_HANDLER -I../../ObjectHandler -I../Source/vm -I../Source/platform -I../Source/java_classes -I../Source/java -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/131588722/lang_runtime.o ../Source/java_classes/lang_runtime.c

${OBJECTDIR}/_ext/131588722/lang_byte.o: ../Source/java_classes/lang_byte.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/131588722
	${RM} $@.d
	$(COMPILE.c) -g -DRUFFUS_VM -DWIN32 -D_OBJECT_HANDLER -I../../ObjectHandler -I../Source/vm -I../Source/platform -I../Source/java_classes -I../Source/java -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/131588722/lang_byte.o ../Source/java_classes/lang_byte.c

${OBJECTDIR}/_ext/131588722/lang_thread.o: ../Source/java_classes/lang_thread.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/131588722
	${RM} $@.d
	$(COMPILE.c) -g -DRUFFUS_VM -DWIN32 -D_OBJECT_HANDLER -I../../ObjectHandler -I../Source/vm -I../Source/platform -I../Source/java_classes -I../Source/java -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/131588722/lang_thread.o ../Source/java_classes/lang_thread.c

${OBJECTDIR}/_ext/918017447/thread_lib.o: ../Source/java/thread_lib.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/918017447
	${RM} $@.d
	$(COMPILE.c) -g -DRUFFUS_VM -DWIN32 -D_OBJECT_HANDLER -I../../ObjectHandler -I../Source/vm -I../Source/platform -I../Source/java_classes -I../Source/java -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/918017447/thread_lib.o ../Source/java/thread_lib.c

${OBJECTDIR}/_ext/131588722/util_vector.o: ../Source/java_classes/util_vector.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/131588722
	${RM} $@.d
	$(COMPILE.c) -g -DRUFFUS_VM -DWIN32 -D_OBJECT_HANDLER -I../../ObjectHandler -I../Source/vm -I../Source/platform -I../Source/java_classes -I../Source/java -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/131588722/util_vector.o ../Source/java_classes/util_vector.c

${OBJECTDIR}/_ext/131588722/io_fileoutputstream.o: ../Source/java_classes/io_fileoutputstream.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/131588722
	${RM} $@.d
	$(COMPILE.c) -g -DRUFFUS_VM -DWIN32 -D_OBJECT_HANDLER -I../../ObjectHandler -I../Source/vm -I../Source/platform -I../Source/java_classes -I../Source/java -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/131588722/io_fileoutputstream.o ../Source/java_classes/io_fileoutputstream.c

${OBJECTDIR}/_ext/998369973/arrays_type.o: ../../ObjectHandler/arrays_type.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/998369973
	${RM} $@.d
	$(COMPILE.c) -g -DRUFFUS_VM -DWIN32 -D_OBJECT_HANDLER -I../../ObjectHandler -I../Source/vm -I../Source/platform -I../Source/java_classes -I../Source/java -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/998369973/arrays_type.o ../../ObjectHandler/arrays_type.c

${OBJECTDIR}/_ext/918017447/util_vector_lib.o: ../Source/java/util_vector_lib.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/918017447
	${RM} $@.d
	$(COMPILE.c) -g -DRUFFUS_VM -DWIN32 -D_OBJECT_HANDLER -I../../ObjectHandler -I../Source/vm -I../Source/platform -I../Source/java_classes -I../Source/java -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/918017447/util_vector_lib.o ../Source/java/util_vector_lib.c

${OBJECTDIR}/_ext/131588722/lang_system.o: ../Source/java_classes/lang_system.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/131588722
	${RM} $@.d
	$(COMPILE.c) -g -DRUFFUS_VM -DWIN32 -D_OBJECT_HANDLER -I../../ObjectHandler -I../Source/vm -I../Source/platform -I../Source/java_classes -I../Source/java -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/131588722/lang_system.o ../Source/java_classes/lang_system.c

${OBJECTDIR}/_ext/246765436/methods.o: ../Source/vm/methods.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/246765436
	${RM} $@.d
	$(COMPILE.c) -g -DRUFFUS_VM -DWIN32 -D_OBJECT_HANDLER -I../../ObjectHandler -I../Source/vm -I../Source/platform -I../Source/java_classes -I../Source/java -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/246765436/methods.o ../Source/vm/methods.c

${OBJECTDIR}/_ext/131588722/util_stringtokenizer.o: ../Source/java_classes/util_stringtokenizer.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/131588722
	${RM} $@.d
	$(COMPILE.c) -g -DRUFFUS_VM -DWIN32 -D_OBJECT_HANDLER -I../../ObjectHandler -I../Source/vm -I../Source/platform -I../Source/java_classes -I../Source/java -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/131588722/util_stringtokenizer.o ../Source/java_classes/util_stringtokenizer.c

${OBJECTDIR}/_ext/131588722/lang_double.o: ../Source/java_classes/lang_double.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/131588722
	${RM} $@.d
	$(COMPILE.c) -g -DRUFFUS_VM -DWIN32 -D_OBJECT_HANDLER -I../../ObjectHandler -I../Source/vm -I../Source/platform -I../Source/java_classes -I../Source/java -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/131588722/lang_double.o ../Source/java_classes/lang_double.c

${OBJECTDIR}/_ext/131588722/io_inputstream.o: ../Source/java_classes/io_inputstream.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/131588722
	${RM} $@.d
	$(COMPILE.c) -g -DRUFFUS_VM -DWIN32 -D_OBJECT_HANDLER -I../../ObjectHandler -I../Source/vm -I../Source/platform -I../Source/java_classes -I../Source/java -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/131588722/io_inputstream.o ../Source/java_classes/io_inputstream.c

${OBJECTDIR}/_ext/131588722/lang_math.o: ../Source/java_classes/lang_math.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/131588722
	${RM} $@.d
	$(COMPILE.c) -g -DRUFFUS_VM -DWIN32 -D_OBJECT_HANDLER -I../../ObjectHandler -I../Source/vm -I../Source/platform -I../Source/java_classes -I../Source/java -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/131588722/lang_math.o ../Source/java_classes/lang_math.c

${OBJECTDIR}/_ext/131588722/lang_boolean.o: ../Source/java_classes/lang_boolean.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/131588722
	${RM} $@.d
	$(COMPILE.c) -g -DRUFFUS_VM -DWIN32 -D_OBJECT_HANDLER -I../../ObjectHandler -I../Source/vm -I../Source/platform -I../Source/java_classes -I../Source/java -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/131588722/lang_boolean.o ../Source/java_classes/lang_boolean.c

${OBJECTDIR}/_ext/246765436/vm.o: ../Source/vm/vm.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/246765436
	${RM} $@.d
	$(COMPILE.c) -g -DRUFFUS_VM -DWIN32 -D_OBJECT_HANDLER -I../../ObjectHandler -I../Source/vm -I../Source/platform -I../Source/java_classes -I../Source/java -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/246765436/vm.o ../Source/vm/vm.c

${OBJECTDIR}/_ext/998369973/stack.o: ../../ObjectHandler/stack.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/998369973
	${RM} $@.d
	$(COMPILE.c) -g -DRUFFUS_VM -DWIN32 -D_OBJECT_HANDLER -I../../ObjectHandler -I../Source/vm -I../Source/platform -I../Source/java_classes -I../Source/java -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/998369973/stack.o ../../ObjectHandler/stack.c

${OBJECTDIR}/_ext/131588722/util_timertask.o: ../Source/java_classes/util_timertask.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/131588722
	${RM} $@.d
	$(COMPILE.c) -g -DRUFFUS_VM -DWIN32 -D_OBJECT_HANDLER -I../../ObjectHandler -I../Source/vm -I../Source/platform -I../Source/java_classes -I../Source/java -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/131588722/util_timertask.o ../Source/java_classes/util_timertask.c

${OBJECTDIR}/_ext/918017447/lang_number_lib.o: ../Source/java/lang_number_lib.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/918017447
	${RM} $@.d
	$(COMPILE.c) -g -DRUFFUS_VM -DWIN32 -D_OBJECT_HANDLER -I../../ObjectHandler -I../Source/vm -I../Source/platform -I../Source/java_classes -I../Source/java -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/918017447/lang_number_lib.o ../Source/java/lang_number_lib.c

${OBJECTDIR}/_ext/998369973/value_type.o: ../../ObjectHandler/value_type.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/998369973
	${RM} $@.d
	$(COMPILE.c) -g -DRUFFUS_VM -DWIN32 -D_OBJECT_HANDLER -I../../ObjectHandler -I../Source/vm -I../Source/platform -I../Source/java_classes -I../Source/java -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/998369973/value_type.o ../../ObjectHandler/value_type.c

${OBJECTDIR}/_ext/998369973/heap.o: ../../ObjectHandler/heap.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/998369973
	${RM} $@.d
	$(COMPILE.c) -g -DRUFFUS_VM -DWIN32 -D_OBJECT_HANDLER -I../../ObjectHandler -I../Source/vm -I../Source/platform -I../Source/java_classes -I../Source/java -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/998369973/heap.o ../../ObjectHandler/heap.c

${OBJECTDIR}/_ext/998369973/instance.o: ../../ObjectHandler/instance.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/998369973
	${RM} $@.d
	$(COMPILE.c) -g -DRUFFUS_VM -DWIN32 -D_OBJECT_HANDLER -I../../ObjectHandler -I../Source/vm -I../Source/platform -I../Source/java_classes -I../Source/java -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/998369973/instance.o ../../ObjectHandler/instance.c

${OBJECTDIR}/vsnprintk.o: vsnprintk.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.c) -g -DRUFFUS_VM -DWIN32 -D_OBJECT_HANDLER -I../../ObjectHandler -I../Source/vm -I../Source/platform -I../Source/java_classes -I../Source/java -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/vsnprintk.o vsnprintk.c

${OBJECTDIR}/_ext/131588722/util_timezone.o: ../Source/java_classes/util_timezone.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/131588722
	${RM} $@.d
	$(COMPILE.c) -g -DRUFFUS_VM -DWIN32 -D_OBJECT_HANDLER -I../../ObjectHandler -I../Source/vm -I../Source/platform -I../Source/java_classes -I../Source/java -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/131588722/util_timezone.o ../Source/java_classes/util_timezone.c

${OBJECTDIR}/_ext/246765436/threads.o: ../Source/vm/threads.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/246765436
	${RM} $@.d
	$(COMPILE.c) -g -DRUFFUS_VM -DWIN32 -D_OBJECT_HANDLER -I../../ObjectHandler -I../Source/vm -I../Source/platform -I../Source/java_classes -I../Source/java -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/246765436/threads.o ../Source/vm/threads.c

${OBJECTDIR}/_ext/998369973/objects.o: ../../ObjectHandler/objects.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/998369973
	${RM} $@.d
	$(COMPILE.c) -g -DRUFFUS_VM -DWIN32 -D_OBJECT_HANDLER -I../../ObjectHandler -I../Source/vm -I../Source/platform -I../Source/java_classes -I../Source/java -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/998369973/objects.o ../../ObjectHandler/objects.c

${OBJECTDIR}/_ext/131588722/util_date.o: ../Source/java_classes/util_date.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/131588722
	${RM} $@.d
	$(COMPILE.c) -g -DRUFFUS_VM -DWIN32 -D_OBJECT_HANDLER -I../../ObjectHandler -I../Source/vm -I../Source/platform -I../Source/java_classes -I../Source/java -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/131588722/util_date.o ../Source/java_classes/util_date.c

${OBJECTDIR}/_ext/131588722/lang_number.o: ../Source/java_classes/lang_number.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/131588722
	${RM} $@.d
	$(COMPILE.c) -g -DRUFFUS_VM -DWIN32 -D_OBJECT_HANDLER -I../../ObjectHandler -I../Source/vm -I../Source/platform -I../Source/java_classes -I../Source/java -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/131588722/lang_number.o ../Source/java_classes/lang_number.c

${OBJECTDIR}/_ext/131588722/lang_stringbuilder.o: ../Source/java_classes/lang_stringbuilder.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/131588722
	${RM} $@.d
	$(COMPILE.c) -g -DRUFFUS_VM -DWIN32 -D_OBJECT_HANDLER -I../../ObjectHandler -I../Source/vm -I../Source/platform -I../Source/java_classes -I../Source/java -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/131588722/lang_stringbuilder.o ../Source/java_classes/lang_stringbuilder.c

${OBJECTDIR}/_ext/246765436/vm_debug.o: ../Source/vm/vm_debug.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/246765436
	${RM} $@.d
	$(COMPILE.c) -g -DRUFFUS_VM -DWIN32 -D_OBJECT_HANDLER -I../../ObjectHandler -I../Source/vm -I../Source/platform -I../Source/java_classes -I../Source/java -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/246765436/vm_debug.o ../Source/vm/vm_debug.c

${OBJECTDIR}/_ext/131588722/lang_object.o: ../Source/java_classes/lang_object.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/131588722
	${RM} $@.d
	$(COMPILE.c) -g -DRUFFUS_VM -DWIN32 -D_OBJECT_HANDLER -I../../ObjectHandler -I../Source/vm -I../Source/platform -I../Source/java_classes -I../Source/java -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/131588722/lang_object.o ../Source/java_classes/lang_object.c

${OBJECTDIR}/_ext/131588722/lang_process.o: ../Source/java_classes/lang_process.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/131588722
	${RM} $@.d
	$(COMPILE.c) -g -DRUFFUS_VM -DWIN32 -D_OBJECT_HANDLER -I../../ObjectHandler -I../Source/vm -I../Source/platform -I../Source/java_classes -I../Source/java -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/131588722/lang_process.o ../Source/java_classes/lang_process.c

${OBJECTDIR}/_ext/131588722/lang_short.o: ../Source/java_classes/lang_short.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/131588722
	${RM} $@.d
	$(COMPILE.c) -g -DRUFFUS_VM -DWIN32 -D_OBJECT_HANDLER -I../../ObjectHandler -I../Source/vm -I../Source/platform -I../Source/java_classes -I../Source/java -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/131588722/lang_short.o ../Source/java_classes/lang_short.c

${OBJECTDIR}/_ext/246765436/exceptions.o: ../Source/vm/exceptions.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/246765436
	${RM} $@.d
	$(COMPILE.c) -g -DRUFFUS_VM -DWIN32 -D_OBJECT_HANDLER -I../../ObjectHandler -I../Source/vm -I../Source/platform -I../Source/java_classes -I../Source/java -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/246765436/exceptions.o ../Source/vm/exceptions.c

${OBJECTDIR}/_ext/246765436/application.o: ../Source/vm/application.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/246765436
	${RM} $@.d
	$(COMPILE.c) -g -DRUFFUS_VM -DWIN32 -D_OBJECT_HANDLER -I../../ObjectHandler -I../Source/vm -I../Source/platform -I../Source/java_classes -I../Source/java -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/246765436/application.o ../Source/vm/application.c

${OBJECTDIR}/_ext/131588722/lang_integer.o: ../Source/java_classes/lang_integer.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/131588722
	${RM} $@.d
	$(COMPILE.c) -g -DRUFFUS_VM -DWIN32 -D_OBJECT_HANDLER -I../../ObjectHandler -I../Source/vm -I../Source/platform -I../Source/java_classes -I../Source/java -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/131588722/lang_integer.o ../Source/java_classes/lang_integer.c

${OBJECTDIR}/_ext/131588722/lang_string.o: ../Source/java_classes/lang_string.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/131588722
	${RM} $@.d
	$(COMPILE.c) -g -DRUFFUS_VM -DWIN32 -D_OBJECT_HANDLER -I../../ObjectHandler -I../Source/vm -I../Source/platform -I../Source/java_classes -I../Source/java -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/131588722/lang_string.o ../Source/java_classes/lang_string.c

${OBJECTDIR}/_ext/131588722/util_calendar.o: ../Source/java_classes/util_calendar.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/131588722
	${RM} $@.d
	$(COMPILE.c) -g -DRUFFUS_VM -DWIN32 -D_OBJECT_HANDLER -I../../ObjectHandler -I../Source/vm -I../Source/platform -I../Source/java_classes -I../Source/java -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/131588722/util_calendar.o ../Source/java_classes/util_calendar.c

${OBJECTDIR}/_ext/131588722/lang_long.o: ../Source/java_classes/lang_long.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/131588722
	${RM} $@.d
	$(COMPILE.c) -g -DRUFFUS_VM -DWIN32 -D_OBJECT_HANDLER -I../../ObjectHandler -I../Source/vm -I../Source/platform -I../Source/java_classes -I../Source/java -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/131588722/lang_long.o ../Source/java_classes/lang_long.c

${OBJECTDIR}/_ext/131588722/util_bitset.o: ../Source/java_classes/util_bitset.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/131588722
	${RM} $@.d
	$(COMPILE.c) -g -DRUFFUS_VM -DWIN32 -D_OBJECT_HANDLER -I../../ObjectHandler -I../Source/vm -I../Source/platform -I../Source/java_classes -I../Source/java -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/131588722/util_bitset.o ../Source/java_classes/util_bitset.c

${OBJECTDIR}/main.o: main.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.c) -g -DRUFFUS_VM -DWIN32 -D_OBJECT_HANDLER -I../../ObjectHandler -I../Source/vm -I../Source/platform -I../Source/java_classes -I../Source/java -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.c

${OBJECTDIR}/_ext/131588722/io_printstream.o: ../Source/java_classes/io_printstream.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/131588722
	${RM} $@.d
	$(COMPILE.c) -g -DRUFFUS_VM -DWIN32 -D_OBJECT_HANDLER -I../../ObjectHandler -I../Source/vm -I../Source/platform -I../Source/java_classes -I../Source/java -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/131588722/io_printstream.o ../Source/java_classes/io_printstream.c

${OBJECTDIR}/_ext/131588722/lang_float.o: ../Source/java_classes/lang_float.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/131588722
	${RM} $@.d
	$(COMPILE.c) -g -DRUFFUS_VM -DWIN32 -D_OBJECT_HANDLER -I../../ObjectHandler -I../Source/vm -I../Source/platform -I../Source/java_classes -I../Source/java -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/131588722/lang_float.o ../Source/java_classes/lang_float.c

${OBJECTDIR}/_ext/131588722/io_fileinputstream.o: ../Source/java_classes/io_fileinputstream.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/131588722
	${RM} $@.d
	$(COMPILE.c) -g -DRUFFUS_VM -DWIN32 -D_OBJECT_HANDLER -I../../ObjectHandler -I../Source/vm -I../Source/platform -I../Source/java_classes -I../Source/java -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/131588722/io_fileinputstream.o ../Source/java_classes/io_fileinputstream.c

${OBJECTDIR}/_ext/131588722/util_random.o: ../Source/java_classes/util_random.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/131588722
	${RM} $@.d
	$(COMPILE.c) -g -DRUFFUS_VM -DWIN32 -D_OBJECT_HANDLER -I../../ObjectHandler -I../Source/vm -I../Source/platform -I../Source/java_classes -I../Source/java -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/131588722/util_random.o ../Source/java_classes/util_random.c

${OBJECTDIR}/_ext/131588722/lang_void.o: ../Source/java_classes/lang_void.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/131588722
	${RM} $@.d
	$(COMPILE.c) -g -DRUFFUS_VM -DWIN32 -D_OBJECT_HANDLER -I../../ObjectHandler -I../Source/vm -I../Source/platform -I../Source/java_classes -I../Source/java -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/131588722/lang_void.o ../Source/java_classes/lang_void.c

${OBJECTDIR}/_ext/131588722/io_file.o: ../Source/java_classes/io_file.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/131588722
	${RM} $@.d
	$(COMPILE.c) -g -DRUFFUS_VM -DWIN32 -D_OBJECT_HANDLER -I../../ObjectHandler -I../Source/vm -I../Source/platform -I../Source/java_classes -I../Source/java -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/131588722/io_file.o ../Source/java_classes/io_file.c

${OBJECTDIR}/_ext/998369973/strings.o: ../../ObjectHandler/strings.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/998369973
	${RM} $@.d
	$(COMPILE.c) -g -DRUFFUS_VM -DWIN32 -D_OBJECT_HANDLER -I../../ObjectHandler -I../Source/vm -I../Source/platform -I../Source/java_classes -I../Source/java -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/998369973/strings.o ../../ObjectHandler/strings.c

${OBJECTDIR}/_ext/918017447/vm_java.o: ../Source/java/vm_java.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/918017447
	${RM} $@.d
	$(COMPILE.c) -g -DRUFFUS_VM -DWIN32 -D_OBJECT_HANDLER -I../../ObjectHandler -I../Source/vm -I../Source/platform -I../Source/java_classes -I../Source/java -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/918017447/vm_java.o ../Source/java/vm_java.c

${OBJECTDIR}/_ext/131588722/util_timer.o: ../Source/java_classes/util_timer.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/131588722
	${RM} $@.d
	$(COMPILE.c) -g -DRUFFUS_VM -DWIN32 -D_OBJECT_HANDLER -I../../ObjectHandler -I../Source/vm -I../Source/platform -I../Source/java_classes -I../Source/java -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/131588722/util_timer.o ../Source/java_classes/util_timer.c

${OBJECTDIR}/_ext/131588722/lang_character.o: ../Source/java_classes/lang_character.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/131588722
	${RM} $@.d
	$(COMPILE.c) -g -DRUFFUS_VM -DWIN32 -D_OBJECT_HANDLER -I../../ObjectHandler -I../Source/vm -I../Source/platform -I../Source/java_classes -I../Source/java -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/131588722/lang_character.o ../Source/java_classes/lang_character.c

${OBJECTDIR}/_ext/918017447/lang_string_lib.o: ../Source/java/lang_string_lib.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/918017447
	${RM} $@.d
	$(COMPILE.c) -g -DRUFFUS_VM -DWIN32 -D_OBJECT_HANDLER -I../../ObjectHandler -I../Source/vm -I../Source/platform -I../Source/java_classes -I../Source/java -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/918017447/lang_string_lib.o ../Source/java/lang_string_lib.c

${OBJECTDIR}/_ext/1485326712/properties.o: ../Source/platform/properties.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1485326712
	${RM} $@.d
	$(COMPILE.c) -g -DRUFFUS_VM -DWIN32 -D_OBJECT_HANDLER -I../../ObjectHandler -I../Source/vm -I../Source/platform -I../Source/java_classes -I../Source/java -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1485326712/properties.o ../Source/platform/properties.c

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/ruffusvm.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
