# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/wangzilong/Desktop/作业/Program/Lab1_18281218

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/wangzilong/Desktop/作业/Program/Lab1_18281218/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Lab1_18281218.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Lab1_18281218.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Lab1_18281218.dir/flags.make

CMakeFiles/Lab1_18281218.dir/main.cpp.o: CMakeFiles/Lab1_18281218.dir/flags.make
CMakeFiles/Lab1_18281218.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wangzilong/Desktop/作业/Program/Lab1_18281218/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Lab1_18281218.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Lab1_18281218.dir/main.cpp.o -c /Users/wangzilong/Desktop/作业/Program/Lab1_18281218/main.cpp

CMakeFiles/Lab1_18281218.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lab1_18281218.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wangzilong/Desktop/作业/Program/Lab1_18281218/main.cpp > CMakeFiles/Lab1_18281218.dir/main.cpp.i

CMakeFiles/Lab1_18281218.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lab1_18281218.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wangzilong/Desktop/作业/Program/Lab1_18281218/main.cpp -o CMakeFiles/Lab1_18281218.dir/main.cpp.s

# Object files for target Lab1_18281218
Lab1_18281218_OBJECTS = \
"CMakeFiles/Lab1_18281218.dir/main.cpp.o"

# External object files for target Lab1_18281218
Lab1_18281218_EXTERNAL_OBJECTS =

Lab1_18281218: CMakeFiles/Lab1_18281218.dir/main.cpp.o
Lab1_18281218: CMakeFiles/Lab1_18281218.dir/build.make
Lab1_18281218: CMakeFiles/Lab1_18281218.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/wangzilong/Desktop/作业/Program/Lab1_18281218/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Lab1_18281218"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Lab1_18281218.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Lab1_18281218.dir/build: Lab1_18281218

.PHONY : CMakeFiles/Lab1_18281218.dir/build

CMakeFiles/Lab1_18281218.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Lab1_18281218.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Lab1_18281218.dir/clean

CMakeFiles/Lab1_18281218.dir/depend:
	cd /Users/wangzilong/Desktop/作业/Program/Lab1_18281218/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/wangzilong/Desktop/作业/Program/Lab1_18281218 /Users/wangzilong/Desktop/作业/Program/Lab1_18281218 /Users/wangzilong/Desktop/作业/Program/Lab1_18281218/cmake-build-debug /Users/wangzilong/Desktop/作业/Program/Lab1_18281218/cmake-build-debug /Users/wangzilong/Desktop/作业/Program/Lab1_18281218/cmake-build-debug/CMakeFiles/Lab1_18281218.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Lab1_18281218.dir/depend

