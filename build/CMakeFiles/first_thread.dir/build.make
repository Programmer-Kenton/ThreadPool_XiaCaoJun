# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/cmake-3.30.3/bin/cmake

# The command to remove a file.
RM = /usr/local/cmake-3.30.3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /usr/local/WorkSpace/ThreadPool-XiaCaoJun

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /usr/local/WorkSpace/ThreadPool-XiaCaoJun/build

# Include any dependencies generated for this target.
include CMakeFiles/first_thread.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/first_thread.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/first_thread.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/first_thread.dir/flags.make

CMakeFiles/first_thread.dir/example/first_thread.cpp.o: CMakeFiles/first_thread.dir/flags.make
CMakeFiles/first_thread.dir/example/first_thread.cpp.o: /usr/local/WorkSpace/ThreadPool-XiaCaoJun/example/first_thread.cpp
CMakeFiles/first_thread.dir/example/first_thread.cpp.o: CMakeFiles/first_thread.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/usr/local/WorkSpace/ThreadPool-XiaCaoJun/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/first_thread.dir/example/first_thread.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/first_thread.dir/example/first_thread.cpp.o -MF CMakeFiles/first_thread.dir/example/first_thread.cpp.o.d -o CMakeFiles/first_thread.dir/example/first_thread.cpp.o -c /usr/local/WorkSpace/ThreadPool-XiaCaoJun/example/first_thread.cpp

CMakeFiles/first_thread.dir/example/first_thread.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/first_thread.dir/example/first_thread.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /usr/local/WorkSpace/ThreadPool-XiaCaoJun/example/first_thread.cpp > CMakeFiles/first_thread.dir/example/first_thread.cpp.i

CMakeFiles/first_thread.dir/example/first_thread.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/first_thread.dir/example/first_thread.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /usr/local/WorkSpace/ThreadPool-XiaCaoJun/example/first_thread.cpp -o CMakeFiles/first_thread.dir/example/first_thread.cpp.s

# Object files for target first_thread
first_thread_OBJECTS = \
"CMakeFiles/first_thread.dir/example/first_thread.cpp.o"

# External object files for target first_thread
first_thread_EXTERNAL_OBJECTS =

first_thread: CMakeFiles/first_thread.dir/example/first_thread.cpp.o
first_thread: CMakeFiles/first_thread.dir/build.make
first_thread: CMakeFiles/first_thread.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/usr/local/WorkSpace/ThreadPool-XiaCaoJun/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable first_thread"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/first_thread.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/first_thread.dir/build: first_thread
.PHONY : CMakeFiles/first_thread.dir/build

CMakeFiles/first_thread.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/first_thread.dir/cmake_clean.cmake
.PHONY : CMakeFiles/first_thread.dir/clean

CMakeFiles/first_thread.dir/depend:
	cd /usr/local/WorkSpace/ThreadPool-XiaCaoJun/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /usr/local/WorkSpace/ThreadPool-XiaCaoJun /usr/local/WorkSpace/ThreadPool-XiaCaoJun /usr/local/WorkSpace/ThreadPool-XiaCaoJun/build /usr/local/WorkSpace/ThreadPool-XiaCaoJun/build /usr/local/WorkSpace/ThreadPool-XiaCaoJun/build/CMakeFiles/first_thread.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/first_thread.dir/depend

