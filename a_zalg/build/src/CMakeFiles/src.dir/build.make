# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /workspaces/cs225/.devcontainer/release

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /workspaces/cs225/.devcontainer/release/build

# Include any dependencies generated for this target.
include src/CMakeFiles/src.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/src.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/src.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/src.dir/flags.make

src/CMakeFiles/src.dir/naive.cpp.o: src/CMakeFiles/src.dir/flags.make
src/CMakeFiles/src.dir/naive.cpp.o: ../src/naive.cpp
src/CMakeFiles/src.dir/naive.cpp.o: src/CMakeFiles/src.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/cs225/.devcontainer/release/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/src.dir/naive.cpp.o"
	cd /workspaces/cs225/.devcontainer/release/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/src.dir/naive.cpp.o -MF CMakeFiles/src.dir/naive.cpp.o.d -o CMakeFiles/src.dir/naive.cpp.o -c /workspaces/cs225/.devcontainer/release/src/naive.cpp

src/CMakeFiles/src.dir/naive.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/src.dir/naive.cpp.i"
	cd /workspaces/cs225/.devcontainer/release/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/cs225/.devcontainer/release/src/naive.cpp > CMakeFiles/src.dir/naive.cpp.i

src/CMakeFiles/src.dir/naive.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/src.dir/naive.cpp.s"
	cd /workspaces/cs225/.devcontainer/release/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/cs225/.devcontainer/release/src/naive.cpp -o CMakeFiles/src.dir/naive.cpp.s

src/CMakeFiles/src.dir/zalg.cpp.o: src/CMakeFiles/src.dir/flags.make
src/CMakeFiles/src.dir/zalg.cpp.o: ../src/zalg.cpp
src/CMakeFiles/src.dir/zalg.cpp.o: src/CMakeFiles/src.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/cs225/.devcontainer/release/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/src.dir/zalg.cpp.o"
	cd /workspaces/cs225/.devcontainer/release/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/src.dir/zalg.cpp.o -MF CMakeFiles/src.dir/zalg.cpp.o.d -o CMakeFiles/src.dir/zalg.cpp.o -c /workspaces/cs225/.devcontainer/release/src/zalg.cpp

src/CMakeFiles/src.dir/zalg.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/src.dir/zalg.cpp.i"
	cd /workspaces/cs225/.devcontainer/release/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/cs225/.devcontainer/release/src/zalg.cpp > CMakeFiles/src.dir/zalg.cpp.i

src/CMakeFiles/src.dir/zalg.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/src.dir/zalg.cpp.s"
	cd /workspaces/cs225/.devcontainer/release/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/cs225/.devcontainer/release/src/zalg.cpp -o CMakeFiles/src.dir/zalg.cpp.s

src/CMakeFiles/src.dir/zval.cpp.o: src/CMakeFiles/src.dir/flags.make
src/CMakeFiles/src.dir/zval.cpp.o: ../src/zval.cpp
src/CMakeFiles/src.dir/zval.cpp.o: src/CMakeFiles/src.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/cs225/.devcontainer/release/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/src.dir/zval.cpp.o"
	cd /workspaces/cs225/.devcontainer/release/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/src.dir/zval.cpp.o -MF CMakeFiles/src.dir/zval.cpp.o.d -o CMakeFiles/src.dir/zval.cpp.o -c /workspaces/cs225/.devcontainer/release/src/zval.cpp

src/CMakeFiles/src.dir/zval.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/src.dir/zval.cpp.i"
	cd /workspaces/cs225/.devcontainer/release/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/cs225/.devcontainer/release/src/zval.cpp > CMakeFiles/src.dir/zval.cpp.i

src/CMakeFiles/src.dir/zval.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/src.dir/zval.cpp.s"
	cd /workspaces/cs225/.devcontainer/release/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/cs225/.devcontainer/release/src/zval.cpp -o CMakeFiles/src.dir/zval.cpp.s

# Object files for target src
src_OBJECTS = \
"CMakeFiles/src.dir/naive.cpp.o" \
"CMakeFiles/src.dir/zalg.cpp.o" \
"CMakeFiles/src.dir/zval.cpp.o"

# External object files for target src
src_EXTERNAL_OBJECTS =

src/libsrc.a: src/CMakeFiles/src.dir/naive.cpp.o
src/libsrc.a: src/CMakeFiles/src.dir/zalg.cpp.o
src/libsrc.a: src/CMakeFiles/src.dir/zval.cpp.o
src/libsrc.a: src/CMakeFiles/src.dir/build.make
src/libsrc.a: src/CMakeFiles/src.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/workspaces/cs225/.devcontainer/release/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX static library libsrc.a"
	cd /workspaces/cs225/.devcontainer/release/build/src && $(CMAKE_COMMAND) -P CMakeFiles/src.dir/cmake_clean_target.cmake
	cd /workspaces/cs225/.devcontainer/release/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/src.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/src.dir/build: src/libsrc.a
.PHONY : src/CMakeFiles/src.dir/build

src/CMakeFiles/src.dir/clean:
	cd /workspaces/cs225/.devcontainer/release/build/src && $(CMAKE_COMMAND) -P CMakeFiles/src.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/src.dir/clean

src/CMakeFiles/src.dir/depend:
	cd /workspaces/cs225/.devcontainer/release/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /workspaces/cs225/.devcontainer/release /workspaces/cs225/.devcontainer/release/src /workspaces/cs225/.devcontainer/release/build /workspaces/cs225/.devcontainer/release/build/src /workspaces/cs225/.devcontainer/release/build/src/CMakeFiles/src.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/src.dir/depend

