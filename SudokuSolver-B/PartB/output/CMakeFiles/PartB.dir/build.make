# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.27

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Natalia Wilson\Desktop\18-Spandana-Natalia-P4\PartB"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Natalia Wilson\Desktop\18-Spandana-Natalia-P4\PartB\output"

# Include any dependencies generated for this target.
include CMakeFiles/PartB.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/PartB.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/PartB.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PartB.dir/flags.make

CMakeFiles/PartB.dir/board.cpp.obj: CMakeFiles/PartB.dir/flags.make
CMakeFiles/PartB.dir/board.cpp.obj: CMakeFiles/PartB.dir/includes_CXX.rsp
CMakeFiles/PartB.dir/board.cpp.obj: C:/Users/Natalia\ Wilson/Desktop/18-Spandana-Natalia-P4/PartB/board.cpp
CMakeFiles/PartB.dir/board.cpp.obj: CMakeFiles/PartB.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="C:\Users\Natalia Wilson\Desktop\18-Spandana-Natalia-P4\PartB\output\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/PartB.dir/board.cpp.obj"
	C:\msys64\ucrt64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/PartB.dir/board.cpp.obj -MF CMakeFiles\PartB.dir\board.cpp.obj.d -o CMakeFiles\PartB.dir\board.cpp.obj -c "C:\Users\Natalia Wilson\Desktop\18-Spandana-Natalia-P4\PartB\board.cpp"

CMakeFiles/PartB.dir/board.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/PartB.dir/board.cpp.i"
	C:\msys64\ucrt64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Natalia Wilson\Desktop\18-Spandana-Natalia-P4\PartB\board.cpp" > CMakeFiles\PartB.dir\board.cpp.i

CMakeFiles/PartB.dir/board.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/PartB.dir/board.cpp.s"
	C:\msys64\ucrt64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Natalia Wilson\Desktop\18-Spandana-Natalia-P4\PartB\board.cpp" -o CMakeFiles\PartB.dir\board.cpp.s

CMakeFiles/PartB.dir/main.cpp.obj: CMakeFiles/PartB.dir/flags.make
CMakeFiles/PartB.dir/main.cpp.obj: CMakeFiles/PartB.dir/includes_CXX.rsp
CMakeFiles/PartB.dir/main.cpp.obj: C:/Users/Natalia\ Wilson/Desktop/18-Spandana-Natalia-P4/PartB/main.cpp
CMakeFiles/PartB.dir/main.cpp.obj: CMakeFiles/PartB.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="C:\Users\Natalia Wilson\Desktop\18-Spandana-Natalia-P4\PartB\output\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/PartB.dir/main.cpp.obj"
	C:\msys64\ucrt64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/PartB.dir/main.cpp.obj -MF CMakeFiles\PartB.dir\main.cpp.obj.d -o CMakeFiles\PartB.dir\main.cpp.obj -c "C:\Users\Natalia Wilson\Desktop\18-Spandana-Natalia-P4\PartB\main.cpp"

CMakeFiles/PartB.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/PartB.dir/main.cpp.i"
	C:\msys64\ucrt64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Natalia Wilson\Desktop\18-Spandana-Natalia-P4\PartB\main.cpp" > CMakeFiles\PartB.dir\main.cpp.i

CMakeFiles/PartB.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/PartB.dir/main.cpp.s"
	C:\msys64\ucrt64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Natalia Wilson\Desktop\18-Spandana-Natalia-P4\PartB\main.cpp" -o CMakeFiles\PartB.dir\main.cpp.s

# Object files for target PartB
PartB_OBJECTS = \
"CMakeFiles/PartB.dir/board.cpp.obj" \
"CMakeFiles/PartB.dir/main.cpp.obj"

# External object files for target PartB
PartB_EXTERNAL_OBJECTS =

PartB.exe: CMakeFiles/PartB.dir/board.cpp.obj
PartB.exe: CMakeFiles/PartB.dir/main.cpp.obj
PartB.exe: CMakeFiles/PartB.dir/build.make
PartB.exe: CMakeFiles/PartB.dir/linkLibs.rsp
PartB.exe: CMakeFiles/PartB.dir/objects1.rsp
PartB.exe: CMakeFiles/PartB.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="C:\Users\Natalia Wilson\Desktop\18-Spandana-Natalia-P4\PartB\output\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable PartB.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\PartB.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PartB.dir/build: PartB.exe
.PHONY : CMakeFiles/PartB.dir/build

CMakeFiles/PartB.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\PartB.dir\cmake_clean.cmake
.PHONY : CMakeFiles/PartB.dir/clean

CMakeFiles/PartB.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Natalia Wilson\Desktop\18-Spandana-Natalia-P4\PartB" "C:\Users\Natalia Wilson\Desktop\18-Spandana-Natalia-P4\PartB" "C:\Users\Natalia Wilson\Desktop\18-Spandana-Natalia-P4\PartB\output" "C:\Users\Natalia Wilson\Desktop\18-Spandana-Natalia-P4\PartB\output" "C:\Users\Natalia Wilson\Desktop\18-Spandana-Natalia-P4\PartB\output\CMakeFiles\PartB.dir\DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/PartB.dir/depend

