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
include tests/hellolib/CMakeFiles/hellolibtest.dir/depend.make

# Include the progress variables for this target.
include tests/hellolib/CMakeFiles/hellolibtest.dir/progress.make

# Include the compile flags for this target's objects.
include tests/hellolib/CMakeFiles/hellolibtest.dir/flags.make

tests/hellolib/CMakeFiles/hellolibtest.dir/main.c.o: tests/hellolib/CMakeFiles/hellolibtest.dir/flags.make
tests/hellolib/CMakeFiles/hellolibtest.dir/main.c.o: ../tests/hellolib/main.c
	$(CMAKE_COMMAND) -E cmake_progress_report /root/CMakeDemos/external/projecthello/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object tests/hellolib/CMakeFiles/hellolibtest.dir/main.c.o"
	cd /root/CMakeDemos/external/projecthello/build/tests/hellolib && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/hellolibtest.dir/main.c.o   -c /root/CMakeDemos/external/projecthello/tests/hellolib/main.c

tests/hellolib/CMakeFiles/hellolibtest.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/hellolibtest.dir/main.c.i"
	cd /root/CMakeDemos/external/projecthello/build/tests/hellolib && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /root/CMakeDemos/external/projecthello/tests/hellolib/main.c > CMakeFiles/hellolibtest.dir/main.c.i

tests/hellolib/CMakeFiles/hellolibtest.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/hellolibtest.dir/main.c.s"
	cd /root/CMakeDemos/external/projecthello/build/tests/hellolib && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /root/CMakeDemos/external/projecthello/tests/hellolib/main.c -o CMakeFiles/hellolibtest.dir/main.c.s

tests/hellolib/CMakeFiles/hellolibtest.dir/main.c.o.requires:
.PHONY : tests/hellolib/CMakeFiles/hellolibtest.dir/main.c.o.requires

tests/hellolib/CMakeFiles/hellolibtest.dir/main.c.o.provides: tests/hellolib/CMakeFiles/hellolibtest.dir/main.c.o.requires
	$(MAKE) -f tests/hellolib/CMakeFiles/hellolibtest.dir/build.make tests/hellolib/CMakeFiles/hellolibtest.dir/main.c.o.provides.build
.PHONY : tests/hellolib/CMakeFiles/hellolibtest.dir/main.c.o.provides

tests/hellolib/CMakeFiles/hellolibtest.dir/main.c.o.provides.build: tests/hellolib/CMakeFiles/hellolibtest.dir/main.c.o

# Object files for target hellolibtest
hellolibtest_OBJECTS = \
"CMakeFiles/hellolibtest.dir/main.c.o"

# External object files for target hellolibtest
hellolibtest_EXTERNAL_OBJECTS =

bin/hellolibtest: tests/hellolib/CMakeFiles/hellolibtest.dir/main.c.o
bin/hellolibtest: tests/hellolib/CMakeFiles/hellolibtest.dir/build.make
bin/hellolibtest: tests/hellolib/CMakeFiles/hellolibtest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable ../../bin/hellolibtest"
	cd /root/CMakeDemos/external/projecthello/build/tests/hellolib && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hellolibtest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/hellolib/CMakeFiles/hellolibtest.dir/build: bin/hellolibtest
.PHONY : tests/hellolib/CMakeFiles/hellolibtest.dir/build

tests/hellolib/CMakeFiles/hellolibtest.dir/requires: tests/hellolib/CMakeFiles/hellolibtest.dir/main.c.o.requires
.PHONY : tests/hellolib/CMakeFiles/hellolibtest.dir/requires

tests/hellolib/CMakeFiles/hellolibtest.dir/clean:
	cd /root/CMakeDemos/external/projecthello/build/tests/hellolib && $(CMAKE_COMMAND) -P CMakeFiles/hellolibtest.dir/cmake_clean.cmake
.PHONY : tests/hellolib/CMakeFiles/hellolibtest.dir/clean

tests/hellolib/CMakeFiles/hellolibtest.dir/depend:
	cd /root/CMakeDemos/external/projecthello/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/CMakeDemos/external/projecthello /root/CMakeDemos/external/projecthello/tests/hellolib /root/CMakeDemos/external/projecthello/build /root/CMakeDemos/external/projecthello/build/tests/hellolib /root/CMakeDemos/external/projecthello/build/tests/hellolib/CMakeFiles/hellolibtest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/hellolib/CMakeFiles/hellolibtest.dir/depend
