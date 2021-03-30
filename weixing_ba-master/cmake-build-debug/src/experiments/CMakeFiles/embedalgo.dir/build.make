# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /home/weixing/clion-2019.3.5/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/weixing/clion-2019.3.5/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/weixing/offline-sim

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/weixing/offline-sim/cmake-build-debug

# Include any dependencies generated for this target.
include src/experiments/CMakeFiles/embedalgo.dir/depend.make

# Include the progress variables for this target.
include src/experiments/CMakeFiles/embedalgo.dir/progress.make

# Include the compile flags for this target's objects.
include src/experiments/CMakeFiles/embedalgo.dir/flags.make

src/experiments/CMakeFiles/embedalgo.dir/Grcnodealgo.cpp.o: src/experiments/CMakeFiles/embedalgo.dir/flags.make
src/experiments/CMakeFiles/embedalgo.dir/Grcnodealgo.cpp.o: ../src/experiments/Grcnodealgo.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/weixing/offline-sim/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/experiments/CMakeFiles/embedalgo.dir/Grcnodealgo.cpp.o"
	cd /home/weixing/offline-sim/cmake-build-debug/src/experiments && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/embedalgo.dir/Grcnodealgo.cpp.o -c /home/weixing/offline-sim/src/experiments/Grcnodealgo.cpp

src/experiments/CMakeFiles/embedalgo.dir/Grcnodealgo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/embedalgo.dir/Grcnodealgo.cpp.i"
	cd /home/weixing/offline-sim/cmake-build-debug/src/experiments && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/weixing/offline-sim/src/experiments/Grcnodealgo.cpp > CMakeFiles/embedalgo.dir/Grcnodealgo.cpp.i

src/experiments/CMakeFiles/embedalgo.dir/Grcnodealgo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/embedalgo.dir/Grcnodealgo.cpp.s"
	cd /home/weixing/offline-sim/cmake-build-debug/src/experiments && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/weixing/offline-sim/src/experiments/Grcnodealgo.cpp -o CMakeFiles/embedalgo.dir/Grcnodealgo.cpp.s

src/experiments/CMakeFiles/embedalgo.dir/Grclinkalgo.cpp.o: src/experiments/CMakeFiles/embedalgo.dir/flags.make
src/experiments/CMakeFiles/embedalgo.dir/Grclinkalgo.cpp.o: ../src/experiments/Grclinkalgo.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/weixing/offline-sim/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/experiments/CMakeFiles/embedalgo.dir/Grclinkalgo.cpp.o"
	cd /home/weixing/offline-sim/cmake-build-debug/src/experiments && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/embedalgo.dir/Grclinkalgo.cpp.o -c /home/weixing/offline-sim/src/experiments/Grclinkalgo.cpp

src/experiments/CMakeFiles/embedalgo.dir/Grclinkalgo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/embedalgo.dir/Grclinkalgo.cpp.i"
	cd /home/weixing/offline-sim/cmake-build-debug/src/experiments && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/weixing/offline-sim/src/experiments/Grclinkalgo.cpp > CMakeFiles/embedalgo.dir/Grclinkalgo.cpp.i

src/experiments/CMakeFiles/embedalgo.dir/Grclinkalgo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/embedalgo.dir/Grclinkalgo.cpp.s"
	cd /home/weixing/offline-sim/cmake-build-debug/src/experiments && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/weixing/offline-sim/src/experiments/Grclinkalgo.cpp -o CMakeFiles/embedalgo.dir/Grclinkalgo.cpp.s

# Object files for target embedalgo
embedalgo_OBJECTS = \
"CMakeFiles/embedalgo.dir/Grcnodealgo.cpp.o" \
"CMakeFiles/embedalgo.dir/Grclinkalgo.cpp.o"

# External object files for target embedalgo
embedalgo_EXTERNAL_OBJECTS =

src/experiments/libembedalgo.so: src/experiments/CMakeFiles/embedalgo.dir/Grcnodealgo.cpp.o
src/experiments/libembedalgo.so: src/experiments/CMakeFiles/embedalgo.dir/Grclinkalgo.cpp.o
src/experiments/libembedalgo.so: src/experiments/CMakeFiles/embedalgo.dir/build.make
src/experiments/libembedalgo.so: src/experiments/CMakeFiles/embedalgo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/weixing/offline-sim/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX shared library libembedalgo.so"
	cd /home/weixing/offline-sim/cmake-build-debug/src/experiments && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/embedalgo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/experiments/CMakeFiles/embedalgo.dir/build: src/experiments/libembedalgo.so

.PHONY : src/experiments/CMakeFiles/embedalgo.dir/build

src/experiments/CMakeFiles/embedalgo.dir/clean:
	cd /home/weixing/offline-sim/cmake-build-debug/src/experiments && $(CMAKE_COMMAND) -P CMakeFiles/embedalgo.dir/cmake_clean.cmake
.PHONY : src/experiments/CMakeFiles/embedalgo.dir/clean

src/experiments/CMakeFiles/embedalgo.dir/depend:
	cd /home/weixing/offline-sim/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/weixing/offline-sim /home/weixing/offline-sim/src/experiments /home/weixing/offline-sim/cmake-build-debug /home/weixing/offline-sim/cmake-build-debug/src/experiments /home/weixing/offline-sim/cmake-build-debug/src/experiments/CMakeFiles/embedalgo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/experiments/CMakeFiles/embedalgo.dir/depend
