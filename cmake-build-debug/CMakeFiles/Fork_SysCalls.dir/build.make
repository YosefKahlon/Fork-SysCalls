# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/c/Users/97252/Documents/GitHub/Fork-SysCalls

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/97252/Documents/GitHub/Fork-SysCalls/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Fork_SysCalls.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Fork_SysCalls.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Fork_SysCalls.dir/flags.make

CMakeFiles/Fork_SysCalls.dir/shell.c.o: CMakeFiles/Fork_SysCalls.dir/flags.make
CMakeFiles/Fork_SysCalls.dir/shell.c.o: ../shell.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/97252/Documents/GitHub/Fork-SysCalls/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Fork_SysCalls.dir/shell.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Fork_SysCalls.dir/shell.c.o   -c /mnt/c/Users/97252/Documents/GitHub/Fork-SysCalls/shell.c

CMakeFiles/Fork_SysCalls.dir/shell.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Fork_SysCalls.dir/shell.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/97252/Documents/GitHub/Fork-SysCalls/shell.c > CMakeFiles/Fork_SysCalls.dir/shell.c.i

CMakeFiles/Fork_SysCalls.dir/shell.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Fork_SysCalls.dir/shell.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/97252/Documents/GitHub/Fork-SysCalls/shell.c -o CMakeFiles/Fork_SysCalls.dir/shell.c.s

CMakeFiles/Fork_SysCalls.dir/server.c.o: CMakeFiles/Fork_SysCalls.dir/flags.make
CMakeFiles/Fork_SysCalls.dir/server.c.o: ../server.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/97252/Documents/GitHub/Fork-SysCalls/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Fork_SysCalls.dir/server.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Fork_SysCalls.dir/server.c.o   -c /mnt/c/Users/97252/Documents/GitHub/Fork-SysCalls/server.c

CMakeFiles/Fork_SysCalls.dir/server.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Fork_SysCalls.dir/server.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/97252/Documents/GitHub/Fork-SysCalls/server.c > CMakeFiles/Fork_SysCalls.dir/server.c.i

CMakeFiles/Fork_SysCalls.dir/server.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Fork_SysCalls.dir/server.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/97252/Documents/GitHub/Fork-SysCalls/server.c -o CMakeFiles/Fork_SysCalls.dir/server.c.s

# Object files for target Fork_SysCalls
Fork_SysCalls_OBJECTS = \
"CMakeFiles/Fork_SysCalls.dir/shell.c.o" \
"CMakeFiles/Fork_SysCalls.dir/server.c.o"

# External object files for target Fork_SysCalls
Fork_SysCalls_EXTERNAL_OBJECTS =

Fork_SysCalls: CMakeFiles/Fork_SysCalls.dir/shell.c.o
Fork_SysCalls: CMakeFiles/Fork_SysCalls.dir/server.c.o
Fork_SysCalls: CMakeFiles/Fork_SysCalls.dir/build.make
Fork_SysCalls: CMakeFiles/Fork_SysCalls.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/97252/Documents/GitHub/Fork-SysCalls/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable Fork_SysCalls"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Fork_SysCalls.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Fork_SysCalls.dir/build: Fork_SysCalls

.PHONY : CMakeFiles/Fork_SysCalls.dir/build

CMakeFiles/Fork_SysCalls.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Fork_SysCalls.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Fork_SysCalls.dir/clean

CMakeFiles/Fork_SysCalls.dir/depend:
	cd /mnt/c/Users/97252/Documents/GitHub/Fork-SysCalls/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/97252/Documents/GitHub/Fork-SysCalls /mnt/c/Users/97252/Documents/GitHub/Fork-SysCalls /mnt/c/Users/97252/Documents/GitHub/Fork-SysCalls/cmake-build-debug /mnt/c/Users/97252/Documents/GitHub/Fork-SysCalls/cmake-build-debug /mnt/c/Users/97252/Documents/GitHub/Fork-SysCalls/cmake-build-debug/CMakeFiles/Fork_SysCalls.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Fork_SysCalls.dir/depend

