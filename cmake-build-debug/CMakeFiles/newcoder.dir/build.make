# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /home/hfq/clion-2018.2.6/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/hfq/clion-2018.2.6/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/hfq/clion_ws/newcoder

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hfq/clion_ws/newcoder/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/newcoder.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/newcoder.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/newcoder.dir/flags.make

CMakeFiles/newcoder.dir/Baidu_SheMen.cpp.o: CMakeFiles/newcoder.dir/flags.make
CMakeFiles/newcoder.dir/Baidu_SheMen.cpp.o: ../Baidu_SheMen.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hfq/clion_ws/newcoder/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/newcoder.dir/Baidu_SheMen.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/newcoder.dir/Baidu_SheMen.cpp.o -c /home/hfq/clion_ws/newcoder/Baidu_SheMen.cpp

CMakeFiles/newcoder.dir/Baidu_SheMen.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/newcoder.dir/Baidu_SheMen.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hfq/clion_ws/newcoder/Baidu_SheMen.cpp > CMakeFiles/newcoder.dir/Baidu_SheMen.cpp.i

CMakeFiles/newcoder.dir/Baidu_SheMen.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/newcoder.dir/Baidu_SheMen.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hfq/clion_ws/newcoder/Baidu_SheMen.cpp -o CMakeFiles/newcoder.dir/Baidu_SheMen.cpp.s

# Object files for target newcoder
newcoder_OBJECTS = \
"CMakeFiles/newcoder.dir/Baidu_SheMen.cpp.o"

# External object files for target newcoder
newcoder_EXTERNAL_OBJECTS =

newcoder: CMakeFiles/newcoder.dir/Baidu_SheMen.cpp.o
newcoder: CMakeFiles/newcoder.dir/build.make
newcoder: CMakeFiles/newcoder.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/hfq/clion_ws/newcoder/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable newcoder"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/newcoder.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/newcoder.dir/build: newcoder

.PHONY : CMakeFiles/newcoder.dir/build

CMakeFiles/newcoder.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/newcoder.dir/cmake_clean.cmake
.PHONY : CMakeFiles/newcoder.dir/clean

CMakeFiles/newcoder.dir/depend:
	cd /home/hfq/clion_ws/newcoder/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hfq/clion_ws/newcoder /home/hfq/clion_ws/newcoder /home/hfq/clion_ws/newcoder/cmake-build-debug /home/hfq/clion_ws/newcoder/cmake-build-debug /home/hfq/clion_ws/newcoder/cmake-build-debug/CMakeFiles/newcoder.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/newcoder.dir/depend

