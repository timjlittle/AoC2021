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
CMAKE_SOURCE_DIR = D:\Projects\AdventOfCode2021\Day13inC

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Projects\AdventOfCode2021\Day13inC\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Day13inC.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Day13inC.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Day13inC.dir/flags.make

CMakeFiles/Day13inC.dir/main.c.obj: CMakeFiles/Day13inC.dir/flags.make
CMakeFiles/Day13inC.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Projects\AdventOfCode2021\Day13inC\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Day13inC.dir/main.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Day13inC.dir\main.c.obj   -c D:\Projects\AdventOfCode2021\Day13inC\main.c

CMakeFiles/Day13inC.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Day13inC.dir/main.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\Projects\AdventOfCode2021\Day13inC\main.c > CMakeFiles\Day13inC.dir\main.c.i

CMakeFiles/Day13inC.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Day13inC.dir/main.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\Projects\AdventOfCode2021\Day13inC\main.c -o CMakeFiles\Day13inC.dir\main.c.s

# Object files for target Day13inC
Day13inC_OBJECTS = \
"CMakeFiles/Day13inC.dir/main.c.obj"

# External object files for target Day13inC
Day13inC_EXTERNAL_OBJECTS =

Day13inC.exe: CMakeFiles/Day13inC.dir/main.c.obj
Day13inC.exe: CMakeFiles/Day13inC.dir/build.make
Day13inC.exe: CMakeFiles/Day13inC.dir/linklibs.rsp
Day13inC.exe: CMakeFiles/Day13inC.dir/objects1.rsp
Day13inC.exe: CMakeFiles/Day13inC.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Projects\AdventOfCode2021\Day13inC\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Day13inC.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Day13inC.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Day13inC.dir/build: Day13inC.exe

.PHONY : CMakeFiles/Day13inC.dir/build

CMakeFiles/Day13inC.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Day13inC.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Day13inC.dir/clean

CMakeFiles/Day13inC.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Projects\AdventOfCode2021\Day13inC D:\Projects\AdventOfCode2021\Day13inC D:\Projects\AdventOfCode2021\Day13inC\cmake-build-debug D:\Projects\AdventOfCode2021\Day13inC\cmake-build-debug D:\Projects\AdventOfCode2021\Day13inC\cmake-build-debug\CMakeFiles\Day13inC.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Day13inC.dir/depend

