# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /snap/clion/152/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/152/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/andrei/Linguagem_C/Engenharia_de_Software/Algoritmos2/AE_3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/andrei/Linguagem_C/Engenharia_de_Software/Algoritmos2/AE_3/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/AE_3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/AE_3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/AE_3.dir/flags.make

CMakeFiles/AE_3.dir/main.c.o: CMakeFiles/AE_3.dir/flags.make
CMakeFiles/AE_3.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andrei/Linguagem_C/Engenharia_de_Software/Algoritmos2/AE_3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/AE_3.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/AE_3.dir/main.c.o -c /home/andrei/Linguagem_C/Engenharia_de_Software/Algoritmos2/AE_3/main.c

CMakeFiles/AE_3.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/AE_3.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/andrei/Linguagem_C/Engenharia_de_Software/Algoritmos2/AE_3/main.c > CMakeFiles/AE_3.dir/main.c.i

CMakeFiles/AE_3.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/AE_3.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/andrei/Linguagem_C/Engenharia_de_Software/Algoritmos2/AE_3/main.c -o CMakeFiles/AE_3.dir/main.c.s

# Object files for target AE_3
AE_3_OBJECTS = \
"CMakeFiles/AE_3.dir/main.c.o"

# External object files for target AE_3
AE_3_EXTERNAL_OBJECTS =

AE_3: CMakeFiles/AE_3.dir/main.c.o
AE_3: CMakeFiles/AE_3.dir/build.make
AE_3: CMakeFiles/AE_3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/andrei/Linguagem_C/Engenharia_de_Software/Algoritmos2/AE_3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable AE_3"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/AE_3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/AE_3.dir/build: AE_3

.PHONY : CMakeFiles/AE_3.dir/build

CMakeFiles/AE_3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/AE_3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/AE_3.dir/clean

CMakeFiles/AE_3.dir/depend:
	cd /home/andrei/Linguagem_C/Engenharia_de_Software/Algoritmos2/AE_3/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/andrei/Linguagem_C/Engenharia_de_Software/Algoritmos2/AE_3 /home/andrei/Linguagem_C/Engenharia_de_Software/Algoritmos2/AE_3 /home/andrei/Linguagem_C/Engenharia_de_Software/Algoritmos2/AE_3/cmake-build-debug /home/andrei/Linguagem_C/Engenharia_de_Software/Algoritmos2/AE_3/cmake-build-debug /home/andrei/Linguagem_C/Engenharia_de_Software/Algoritmos2/AE_3/cmake-build-debug/CMakeFiles/AE_3.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/AE_3.dir/depend

