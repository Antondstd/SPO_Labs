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
CMAKE_COMMAND = /snap/clion/151/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/151/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/user/SPO/Lab1Final

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/user/SPO/Lab1Final/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Lab1Final.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Lab1Final.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Lab1Final.dir/flags.make

CMakeFiles/Lab1Final.dir/main.c.o: CMakeFiles/Lab1Final.dir/flags.make
CMakeFiles/Lab1Final.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/SPO/Lab1Final/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Lab1Final.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Lab1Final.dir/main.c.o -c /home/user/SPO/Lab1Final/main.c

CMakeFiles/Lab1Final.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Lab1Final.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/user/SPO/Lab1Final/main.c > CMakeFiles/Lab1Final.dir/main.c.i

CMakeFiles/Lab1Final.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Lab1Final.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/user/SPO/Lab1Final/main.c -o CMakeFiles/Lab1Final.dir/main.c.s

CMakeFiles/Lab1Final.dir/disks_partitions_task/disks_partitions.c.o: CMakeFiles/Lab1Final.dir/flags.make
CMakeFiles/Lab1Final.dir/disks_partitions_task/disks_partitions.c.o: ../disks_partitions_task/disks_partitions.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/SPO/Lab1Final/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Lab1Final.dir/disks_partitions_task/disks_partitions.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Lab1Final.dir/disks_partitions_task/disks_partitions.c.o -c /home/user/SPO/Lab1Final/disks_partitions_task/disks_partitions.c

CMakeFiles/Lab1Final.dir/disks_partitions_task/disks_partitions.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Lab1Final.dir/disks_partitions_task/disks_partitions.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/user/SPO/Lab1Final/disks_partitions_task/disks_partitions.c > CMakeFiles/Lab1Final.dir/disks_partitions_task/disks_partitions.c.i

CMakeFiles/Lab1Final.dir/disks_partitions_task/disks_partitions.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Lab1Final.dir/disks_partitions_task/disks_partitions.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/user/SPO/Lab1Final/disks_partitions_task/disks_partitions.c -o CMakeFiles/Lab1Final.dir/disks_partitions_task/disks_partitions.c.s

CMakeFiles/Lab1Final.dir/hfs_task/utils.c.o: CMakeFiles/Lab1Final.dir/flags.make
CMakeFiles/Lab1Final.dir/hfs_task/utils.c.o: ../hfs_task/utils.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/SPO/Lab1Final/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/Lab1Final.dir/hfs_task/utils.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Lab1Final.dir/hfs_task/utils.c.o -c /home/user/SPO/Lab1Final/hfs_task/utils.c

CMakeFiles/Lab1Final.dir/hfs_task/utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Lab1Final.dir/hfs_task/utils.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/user/SPO/Lab1Final/hfs_task/utils.c > CMakeFiles/Lab1Final.dir/hfs_task/utils.c.i

CMakeFiles/Lab1Final.dir/hfs_task/utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Lab1Final.dir/hfs_task/utils.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/user/SPO/Lab1Final/hfs_task/utils.c -o CMakeFiles/Lab1Final.dir/hfs_task/utils.c.s

CMakeFiles/Lab1Final.dir/hfs_task/hfs_structures.c.o: CMakeFiles/Lab1Final.dir/flags.make
CMakeFiles/Lab1Final.dir/hfs_task/hfs_structures.c.o: ../hfs_task/hfs_structures.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/SPO/Lab1Final/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/Lab1Final.dir/hfs_task/hfs_structures.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Lab1Final.dir/hfs_task/hfs_structures.c.o -c /home/user/SPO/Lab1Final/hfs_task/hfs_structures.c

CMakeFiles/Lab1Final.dir/hfs_task/hfs_structures.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Lab1Final.dir/hfs_task/hfs_structures.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/user/SPO/Lab1Final/hfs_task/hfs_structures.c > CMakeFiles/Lab1Final.dir/hfs_task/hfs_structures.c.i

CMakeFiles/Lab1Final.dir/hfs_task/hfs_structures.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Lab1Final.dir/hfs_task/hfs_structures.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/user/SPO/Lab1Final/hfs_task/hfs_structures.c -o CMakeFiles/Lab1Final.dir/hfs_task/hfs_structures.c.s

# Object files for target Lab1Final
Lab1Final_OBJECTS = \
"CMakeFiles/Lab1Final.dir/main.c.o" \
"CMakeFiles/Lab1Final.dir/disks_partitions_task/disks_partitions.c.o" \
"CMakeFiles/Lab1Final.dir/hfs_task/utils.c.o" \
"CMakeFiles/Lab1Final.dir/hfs_task/hfs_structures.c.o"

# External object files for target Lab1Final
Lab1Final_EXTERNAL_OBJECTS =

Lab1Final: CMakeFiles/Lab1Final.dir/main.c.o
Lab1Final: CMakeFiles/Lab1Final.dir/disks_partitions_task/disks_partitions.c.o
Lab1Final: CMakeFiles/Lab1Final.dir/hfs_task/utils.c.o
Lab1Final: CMakeFiles/Lab1Final.dir/hfs_task/hfs_structures.c.o
Lab1Final: CMakeFiles/Lab1Final.dir/build.make
Lab1Final: CMakeFiles/Lab1Final.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/user/SPO/Lab1Final/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable Lab1Final"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Lab1Final.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Lab1Final.dir/build: Lab1Final

.PHONY : CMakeFiles/Lab1Final.dir/build

CMakeFiles/Lab1Final.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Lab1Final.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Lab1Final.dir/clean

CMakeFiles/Lab1Final.dir/depend:
	cd /home/user/SPO/Lab1Final/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/user/SPO/Lab1Final /home/user/SPO/Lab1Final /home/user/SPO/Lab1Final/cmake-build-debug /home/user/SPO/Lab1Final/cmake-build-debug /home/user/SPO/Lab1Final/cmake-build-debug/CMakeFiles/Lab1Final.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Lab1Final.dir/depend
