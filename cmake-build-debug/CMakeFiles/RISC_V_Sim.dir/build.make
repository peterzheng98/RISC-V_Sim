# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = "/Users/peterzheng/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/191.7479.33/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Users/peterzheng/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/191.7479.33/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/peterzheng/CLionProjects/RISC-V_Sim

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/peterzheng/CLionProjects/RISC-V_Sim/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/RISC_V_Sim.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/RISC_V_Sim.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/RISC_V_Sim.dir/flags.make

CMakeFiles/RISC_V_Sim.dir/main.cpp.o: CMakeFiles/RISC_V_Sim.dir/flags.make
CMakeFiles/RISC_V_Sim.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/peterzheng/CLionProjects/RISC-V_Sim/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/RISC_V_Sim.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RISC_V_Sim.dir/main.cpp.o -c /Users/peterzheng/CLionProjects/RISC-V_Sim/main.cpp

CMakeFiles/RISC_V_Sim.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RISC_V_Sim.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/peterzheng/CLionProjects/RISC-V_Sim/main.cpp > CMakeFiles/RISC_V_Sim.dir/main.cpp.i

CMakeFiles/RISC_V_Sim.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RISC_V_Sim.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/peterzheng/CLionProjects/RISC-V_Sim/main.cpp -o CMakeFiles/RISC_V_Sim.dir/main.cpp.s

# Object files for target RISC_V_Sim
RISC_V_Sim_OBJECTS = \
"CMakeFiles/RISC_V_Sim.dir/main.cpp.o"

# External object files for target RISC_V_Sim
RISC_V_Sim_EXTERNAL_OBJECTS =

RISC_V_Sim: CMakeFiles/RISC_V_Sim.dir/main.cpp.o
RISC_V_Sim: CMakeFiles/RISC_V_Sim.dir/build.make
RISC_V_Sim: CMakeFiles/RISC_V_Sim.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/peterzheng/CLionProjects/RISC-V_Sim/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable RISC_V_Sim"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/RISC_V_Sim.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/RISC_V_Sim.dir/build: RISC_V_Sim

.PHONY : CMakeFiles/RISC_V_Sim.dir/build

CMakeFiles/RISC_V_Sim.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/RISC_V_Sim.dir/cmake_clean.cmake
.PHONY : CMakeFiles/RISC_V_Sim.dir/clean

CMakeFiles/RISC_V_Sim.dir/depend:
	cd /Users/peterzheng/CLionProjects/RISC-V_Sim/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/peterzheng/CLionProjects/RISC-V_Sim /Users/peterzheng/CLionProjects/RISC-V_Sim /Users/peterzheng/CLionProjects/RISC-V_Sim/cmake-build-debug /Users/peterzheng/CLionProjects/RISC-V_Sim/cmake-build-debug /Users/peterzheng/CLionProjects/RISC-V_Sim/cmake-build-debug/CMakeFiles/RISC_V_Sim.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/RISC_V_Sim.dir/depend

