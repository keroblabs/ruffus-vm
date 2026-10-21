# makefile

TRGT    =
LD		= $(TRGT)gcc
CC      = $(TRGT)gcc
CP      = $(TRGT)objcopy
AS      = $(TRGT)gcc -x assembler-with-cpp
SIZE    = $(TRGT)size
OBJCOPY = $(TRGT)objcopy
OBJDUMP = $(TRGT)objdump
BIN     = $(TRGT)objcopy -O ihex
MAKE    = make
CP      = cp

SRC =
SRC += ../Boards/Linux/dir.c
SRC += ../Boards/Linux/file.c
SRC += ../Boards/Linux/main.c
SRC += ../Boards/Linux/ms_timer.c
SRC += ../Boards/Linux/rtc_driver.c
SRC += ../ObjectHandler/arrays_type.c
SRC += ../ObjectHandler/gc.c
SRC += ../ObjectHandler/heap.c
SRC += ../ObjectHandler/instance.c
SRC += ../ObjectHandler/objects.c
SRC += ../ObjectHandler/stack.c
SRC += ../ObjectHandler/strings.c
SRC += ../ObjectHandler/value_type.c
SRC += ../RuffusVM/Source/filesystem/file_module.c
SRC += ../RuffusVM/Source/java/lang_class_lib.c
SRC += ../RuffusVM/Source/java/lang_number_lib.c
SRC += ../RuffusVM/Source/java/lang_string_lib.c
SRC += ../RuffusVM/Source/java/thread_lib.c
SRC += ../RuffusVM/Source/java/util_vector_lib.c
SRC += ../RuffusVM/Source/java/vm_java.c
SRC += ../RuffusVM/Source/java_classes/io_file.c
SRC += ../RuffusVM/Source/java_classes/io_fileinputstream.c
SRC += ../RuffusVM/Source/java_classes/io_fileoutputstream.c
SRC += ../RuffusVM/Source/java_classes/io_inputstream.c
SRC += ../RuffusVM/Source/java_classes/io_outputstream.c
SRC += ../RuffusVM/Source/java_classes/io_printstream.c
SRC += ../RuffusVM/Source/java_classes/io_randomaccessfile.c
SRC += ../RuffusVM/Source/java_classes/lang_boolean.c
SRC += ../RuffusVM/Source/java_classes/lang_byte.c
SRC += ../RuffusVM/Source/java_classes/lang_character.c
SRC += ../RuffusVM/Source/java_classes/lang_class.c
SRC += ../RuffusVM/Source/java_classes/lang_double.c
SRC += ../RuffusVM/Source/java_classes/lang_float.c
SRC += ../RuffusVM/Source/java_classes/lang_integer.c
SRC += ../RuffusVM/Source/java_classes/lang_long.c
SRC += ../RuffusVM/Source/java_classes/lang_math.c
SRC += ../RuffusVM/Source/java_classes/lang_number.c
SRC += ../RuffusVM/Source/java_classes/lang_object.c
SRC += ../RuffusVM/Source/java_classes/lang_process.c
SRC += ../RuffusVM/Source/java_classes/lang_reflect_field.c
SRC += ../RuffusVM/Source/java_classes/lang_reflect_method.c
SRC += ../RuffusVM/Source/java_classes/lang_runtime.c
SRC += ../RuffusVM/Source/java_classes/lang_short.c
SRC += ../RuffusVM/Source/java_classes/lang_string.c
SRC += ../RuffusVM/Source/java_classes/lang_stringbuilder.c
SRC += ../RuffusVM/Source/java_classes/lang_system.c
SRC += ../RuffusVM/Source/java_classes/lang_thread.c
SRC += ../RuffusVM/Source/java_classes/lang_void.c
SRC += ../RuffusVM/Source/java_classes/native.c
SRC += ../RuffusVM/Source/java_classes/util_bitset.c
SRC += ../RuffusVM/Source/java_classes/util_calendar.c
SRC += ../RuffusVM/Source/java_classes/util_date.c
SRC += ../RuffusVM/Source/java_classes/util_random.c
SRC += ../RuffusVM/Source/java_classes/util_stringtokenizer.c
SRC += ../RuffusVM/Source/java_classes/util_timer.c
SRC += ../RuffusVM/Source/java_classes/util_timertask.c
SRC += ../RuffusVM/Source/java_classes/util_timezone.c
SRC += ../RuffusVM/Source/java_classes/util_vector.c
SRC += ../RuffusVM/Source/vm/application.c
SRC += ../RuffusVM/Source/vm/exceptions.c
SRC += ../RuffusVM/Source/vm/methods.c
SRC += ../RuffusVM/Source/vm/properties.c
SRC += ../RuffusVM/Source/vm/threads.c
SRC += ../RuffusVM/Source/vm/vm.c
SRC += ../RuffusVM/Source/vm/vm_debug.c

CINCDIR =
CINCDIR += ../RuffusVM/Source/vm
CINCDIR += ../RuffusVM/Source/java_classes
CINCDIR += ../RuffusVM/Source/java
CINCDIR += ../RuffusVM/Source/filesystem
CINCDIR += ../ObjectHandler
CINCDIR += ../Boards/Linux

DEFS =
DEFS += -DWANT_OBJECT_HANDLER
DEFS += -DLINUX_BUILD

# Define optimisation level here
OPT = -O3

# Define debug level
##  -gdwarf-2
DEBUG = -g
#  -gstabs

INCDIR  = $(patsubst %,-I %,$(CINCDIR))

CFLAGS = -c -fsigned-char -ffunction-sections
CFLAGS += $(MCFLAGS)
CFLAGS += $(DEFS)
CFLAGS += $(INCDIR) -I.

OBJS = $(SRC:.c=.o)

#
# makefile rules
#

build: DO_BUILD
all: DO_FLASH
clean: DO_CLEAN
rebuild: DO_REBUILD

#
# internal makefile rules
#

DO_BUILD: show_start $(OBJS)
DO_FLASH: show_start $(OBJS) $(PROJECT).elf $(PROJECT).hex $(PROJECT).bin $(PROJECT).dfu $(PROJECT).dis show_finished
DO_REBUILD: DO_CLEAN DO_FLASH
DO_CLEAN: exec_clean

#
# internal rules
#

%o : %c
	@echo ""
	$(CC) $(CFLAGS) $< -o $@
	@$(SIZE) $@

%o : %cpp
	@echo ""
	@$(CC) $(CPFLAGS) $< -o $@
	@$(SIZE) $@

%o : %s
	@echo ""
	@$(AS) $(ASMFLAGS) $< -o $@
	@$(SIZE) $@

#
# scripts
#

show_start:
	@echo "Starting ..."
	@$(CC) --version

show_finished:
	@echo ""
	@echo "Finished!"

exec_clean:
	@echo Erasing all object files
	@rm -f $(OBJS)
	@rm -f $(PROJECT).elf
	@rm -f $(PROJECT).map
	@rm -f $(PROJECT).hex
	@rm -f $(PROJECT).dis
	@rm -f $(PROJECT).bug
	@rm -f $(PROJECT).bin

