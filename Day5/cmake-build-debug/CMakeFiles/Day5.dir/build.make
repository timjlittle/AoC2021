# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.2.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Projects\AdventOfCode2021\Day5

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Projects\AdventOfCode2021\Day5\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Day5.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Day5.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Day5.dir/flags.make

CMakeFiles/Day5.dir/Day5Task2.c.obj: CMakeFiles/Day5.dir/flags.make
CMakeFiles/Day5.dir/Day5Task2.c.obj: ../Day5Task2.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Projects\AdventOfCode2021\Day5\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Day5.dir/Day5Task2.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Day5.dir\Day5Task2.c.obj   -c D:\Projects\AdventOfCode2021\Day5\Day5Task2.c

CMakeFiles/Day5.dir/Day5Task2.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Day5.dir/Day5Task2.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\Projects\AdventOfCode2021\Day5\Day5Task2.c > CMakeFiles\Day5.dir\Day5Task2.c.i

CMakeFiles/Day5.dir/Day5Task2.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Day5.dir/Day5Task2.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\Projects\AdventOfCode2021\Day5\Day5Task2.c -o CMakeFiles\Day5.dir\Day5Task2.c.s

# Object files for target Day5
Day5_OBJECTS = \
"CMakeFiles/Day5.dir/Day5Task2.c.obj"

# External object files for target Day5
Day5_EXTERNAL_OBJECTS =

Day5.exe: CMakeFiles/Day5.dir/Day5Task2.c.obj
Day5.exe: CMakeFiles/Day5.dir/build.make
Day5.exe: CMakeFiles/Day5.dir/linklibs.rsp
Day5.exe: CMakeFiles/Day5.dir/objects1.rsp
Day5.exe: CMakeFiles/Day5.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Projects\AdventOfCode2021\Day5\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Day5.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Day5.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Day5.dir/build: Day5.exe

.PHONY : CMakeFiles/Day5.dir/build

CMakeFiles/Day5.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Day5.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Day5.dir/clean

CMakeFiles/Day5.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Projects\AdventOfCode2021\Day5 D:\Projects\AdventOfCode2021\Day5 D:\Projects\AdventOfCode2021\Day5\cmake-build-debug D:\Projects\AdventOfCode2021\Day5\cmake-build-debug D:\Projects\AdventOfCode2021\Day5\cmake-build-debug\CMakeFiles\Day5.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Day5.dir/depend

