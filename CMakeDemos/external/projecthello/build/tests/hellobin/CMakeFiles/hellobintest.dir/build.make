# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /root/CMakeDemos/external/projecthello

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/CMakeDemos/external/projecthello/build

# Include any dependencies generated for this target.
include tests/hellobin/CMakeFiles/hellobintest.dir/depend.make

# Include the progress variables for this target.
include tests/hellobin/CMakeFiles/hellobintest.dir/progress.make

# Include the compile flags for this target's objects.
include tests/hellobin/CMakeFiles/hellobintest.dir/flags.make

tests/hellobin/CMakeFiles/hellobintest.dir/main.c.o: tests/hellobin/CMakeFiles/hellobintest.dir/flags.make
tests/hellobin/CMakeFiles/hellobintest.dir/main.c.o: ../tests/hellobin/main.c
	$(CMAKE_COMMAND) -E cmake_progress_report /root/CMakeDemos/external/projecthello/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object tests/hellobin/CMakeFiles/hellobintest.dir/main.c.o"
	cd /root/CMakeDemos/external/projecthello/build/tests/hellobin && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/hellobintest.dir/main.c.o   -c /root/CMakeDemos/external/projecthello/tests/hellobin/main.c

tests/hellobin/CMakeFiles/hellobintest.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/hellobintest.dir/main.c.i"
	cd /root/CMakeDemos/external/projecthello/build/tests/hellobin && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /root/CMakeDemos/external/projecthello/tests/hellobin/main.c > CMakeFiles/hellobintest.dir/main.c.i

tests/hellobin/CMakeFiles/hellobintest.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/hellobintest.dir/main.c.s"
	cd /root/CMakeDemos/external/projecthello/build/tests/hellobin && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /root/CMakeDemos/external/projecthello/tests/hellobin/main.c -o CMakeFiles/hellobintest.dir/main.c.s

tests/hellobin/CMakeFiles/hellobintest.dir/main.c.o.requires:
.PHONY : tests/hellobin/CMakeFiles/hellobintest.dir/main.c.o.requires

tests/hellobin/CMakeFiles/hellobintest.dir/main.c.o.provides: tests/hellobin/CMakeFiles/hellobintest.dir/main.c.o.requires
	$(MAKE) -f tests/hellobin/CMakeFiles/hellobintest.dir/build.make tests/hellobin/CMakeFiles/hellobintest.dir/main.c.o.provides.build
.PHONY : tests/hellobin/CMakeFiles/hellobintest.dir/main.c.o.provides

tests/hellobin/CMakeFiles/hellobintest.dir/main.c.o.provides.build: tests/hellobin/CMakeFiles/hellobintest.dir/main.c.o

# Object files for target hellobintest
hellobintest_OBJECTS = \
"CMakeFiles/hellobintest.dir/main.c.o"

# External object files for target hellobintest
hellobintest_EXTERNAL_OBJECTS =

bin/hellobintest: tests/hellobin/CMakeFiles/hellobintest.dir/main.c.o
bin/hellobintest: tests/hellobin/CMakeFiles/hellobintest.dir/build.make
bin/hellobintest: tests/hellobin/CMakeFiles/hellobintest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable ../../bin/hellobintest"
	cd /root/CMakeDemos/external/projecthello/build/tests/hellobin && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hellobintest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/hellobin/CMakeFiles/hellobintest.dir/build: bin/hellobintest
.PHONY : tests/hellobin/CMakeFiles/hellobintest.dir/build

tests/hellobin/CMakeFiles/hellobintest.dir/requires: tests/hellobin/CMakeFiles/hellobintest.dir/main.c.o.requires
.PHONY : tests/hellobin/CMakeFiles/hellobintest.dir/requires

tests/hellobin/CMakeFiles/hellobintest.dir/clean:
	cd /root/CMakeDemos/external/projecthello/build/tests/hellobin && $(CMAKE_COMMAND) -P CMakeFiles/hellobintest.dir/cmake_clean.cmake
.PHONY : tests/hellobin/CMakeFiles/hellobintest.dir/clean

tests/hellobin/CMakeFiles/hellobintest.dir/depend:
	cd /root/CMakeDemos/external/projecthello/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/CMakeDemos/external/projecthello /root/CMakeDemos/external/projecthello/tests/hellobin /root/CMakeDemos/external/projecthello/build /root/CMakeDemos/external/projecthello/build/tests/hellobin /root/CMakeDemos/external/projecthello/build/tests/hellobin/CMakeFiles/hellobintest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/hellobin/CMakeFiles/hellobintest.dir/depend

