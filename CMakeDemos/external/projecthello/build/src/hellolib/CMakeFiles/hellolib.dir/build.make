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
include src/hellolib/CMakeFiles/hellolib.dir/depend.make

# Include the progress variables for this target.
include src/hellolib/CMakeFiles/hellolib.dir/progress.make

# Include the compile flags for this target's objects.
include src/hellolib/CMakeFiles/hellolib.dir/flags.make

src/hellolib/CMakeFiles/hellolib.dir/main.c.o: src/hellolib/CMakeFiles/hellolib.dir/flags.make
src/hellolib/CMakeFiles/hellolib.dir/main.c.o: ../src/hellolib/main.c
	$(CMAKE_COMMAND) -E cmake_progress_report /root/CMakeDemos/external/projecthello/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object src/hellolib/CMakeFiles/hellolib.dir/main.c.o"
	cd /root/CMakeDemos/external/projecthello/build/src/hellolib && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/hellolib.dir/main.c.o   -c /root/CMakeDemos/external/projecthello/src/hellolib/main.c

src/hellolib/CMakeFiles/hellolib.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/hellolib.dir/main.c.i"
	cd /root/CMakeDemos/external/projecthello/build/src/hellolib && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /root/CMakeDemos/external/projecthello/src/hellolib/main.c > CMakeFiles/hellolib.dir/main.c.i

src/hellolib/CMakeFiles/hellolib.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/hellolib.dir/main.c.s"
	cd /root/CMakeDemos/external/projecthello/build/src/hellolib && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /root/CMakeDemos/external/projecthello/src/hellolib/main.c -o CMakeFiles/hellolib.dir/main.c.s

src/hellolib/CMakeFiles/hellolib.dir/main.c.o.requires:
.PHONY : src/hellolib/CMakeFiles/hellolib.dir/main.c.o.requires

src/hellolib/CMakeFiles/hellolib.dir/main.c.o.provides: src/hellolib/CMakeFiles/hellolib.dir/main.c.o.requires
	$(MAKE) -f src/hellolib/CMakeFiles/hellolib.dir/build.make src/hellolib/CMakeFiles/hellolib.dir/main.c.o.provides.build
.PHONY : src/hellolib/CMakeFiles/hellolib.dir/main.c.o.provides

src/hellolib/CMakeFiles/hellolib.dir/main.c.o.provides.build: src/hellolib/CMakeFiles/hellolib.dir/main.c.o

# Object files for target hellolib
hellolib_OBJECTS = \
"CMakeFiles/hellolib.dir/main.c.o"

# External object files for target hellolib
hellolib_EXTERNAL_OBJECTS =

../lib/hellolib: src/hellolib/CMakeFiles/hellolib.dir/main.c.o
../lib/hellolib: src/hellolib/CMakeFiles/hellolib.dir/build.make
../lib/hellolib: src/hellolib/CMakeFiles/hellolib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable ../../../lib/hellolib"
	cd /root/CMakeDemos/external/projecthello/build/src/hellolib && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hellolib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/hellolib/CMakeFiles/hellolib.dir/build: ../lib/hellolib
.PHONY : src/hellolib/CMakeFiles/hellolib.dir/build

src/hellolib/CMakeFiles/hellolib.dir/requires: src/hellolib/CMakeFiles/hellolib.dir/main.c.o.requires
.PHONY : src/hellolib/CMakeFiles/hellolib.dir/requires

src/hellolib/CMakeFiles/hellolib.dir/clean:
	cd /root/CMakeDemos/external/projecthello/build/src/hellolib && $(CMAKE_COMMAND) -P CMakeFiles/hellolib.dir/cmake_clean.cmake
.PHONY : src/hellolib/CMakeFiles/hellolib.dir/clean

src/hellolib/CMakeFiles/hellolib.dir/depend:
	cd /root/CMakeDemos/external/projecthello/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/CMakeDemos/external/projecthello /root/CMakeDemos/external/projecthello/src/hellolib /root/CMakeDemos/external/projecthello/build /root/CMakeDemos/external/projecthello/build/src/hellolib /root/CMakeDemos/external/projecthello/build/src/hellolib/CMakeFiles/hellolib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/hellolib/CMakeFiles/hellolib.dir/depend

