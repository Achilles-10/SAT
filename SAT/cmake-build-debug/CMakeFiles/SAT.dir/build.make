# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.9

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\10299\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\173.4127.32\bin\cmake\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\10299\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\173.4127.32\bin\cmake\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\learning\C program design\SAT"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\learning\C program design\SAT\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/SAT.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SAT.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SAT.dir/flags.make

CMakeFiles/SAT.dir/main.c.obj: CMakeFiles/SAT.dir/flags.make
CMakeFiles/SAT.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\learning\C program design\SAT\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/SAT.dir/main.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\SAT.dir\main.c.obj   -c "D:\learning\C program design\SAT\main.c"

CMakeFiles/SAT.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SAT.dir/main.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\learning\C program design\SAT\main.c" > CMakeFiles\SAT.dir\main.c.i

CMakeFiles/SAT.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SAT.dir/main.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "D:\learning\C program design\SAT\main.c" -o CMakeFiles\SAT.dir\main.c.s

CMakeFiles/SAT.dir/main.c.obj.requires:

.PHONY : CMakeFiles/SAT.dir/main.c.obj.requires

CMakeFiles/SAT.dir/main.c.obj.provides: CMakeFiles/SAT.dir/main.c.obj.requires
	$(MAKE) -f CMakeFiles\SAT.dir\build.make CMakeFiles/SAT.dir/main.c.obj.provides.build
.PHONY : CMakeFiles/SAT.dir/main.c.obj.provides

CMakeFiles/SAT.dir/main.c.obj.provides.build: CMakeFiles/SAT.dir/main.c.obj


CMakeFiles/SAT.dir/vec.c.obj: CMakeFiles/SAT.dir/flags.make
CMakeFiles/SAT.dir/vec.c.obj: ../vec.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\learning\C program design\SAT\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/SAT.dir/vec.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\SAT.dir\vec.c.obj   -c "D:\learning\C program design\SAT\vec.c"

CMakeFiles/SAT.dir/vec.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SAT.dir/vec.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\learning\C program design\SAT\vec.c" > CMakeFiles\SAT.dir\vec.c.i

CMakeFiles/SAT.dir/vec.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SAT.dir/vec.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "D:\learning\C program design\SAT\vec.c" -o CMakeFiles\SAT.dir\vec.c.s

CMakeFiles/SAT.dir/vec.c.obj.requires:

.PHONY : CMakeFiles/SAT.dir/vec.c.obj.requires

CMakeFiles/SAT.dir/vec.c.obj.provides: CMakeFiles/SAT.dir/vec.c.obj.requires
	$(MAKE) -f CMakeFiles\SAT.dir\build.make CMakeFiles/SAT.dir/vec.c.obj.provides.build
.PHONY : CMakeFiles/SAT.dir/vec.c.obj.provides

CMakeFiles/SAT.dir/vec.c.obj.provides.build: CMakeFiles/SAT.dir/vec.c.obj


CMakeFiles/SAT.dir/formula.c.obj: CMakeFiles/SAT.dir/flags.make
CMakeFiles/SAT.dir/formula.c.obj: ../formula.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\learning\C program design\SAT\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/SAT.dir/formula.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\SAT.dir\formula.c.obj   -c "D:\learning\C program design\SAT\formula.c"

CMakeFiles/SAT.dir/formula.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SAT.dir/formula.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\learning\C program design\SAT\formula.c" > CMakeFiles\SAT.dir\formula.c.i

CMakeFiles/SAT.dir/formula.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SAT.dir/formula.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "D:\learning\C program design\SAT\formula.c" -o CMakeFiles\SAT.dir\formula.c.s

CMakeFiles/SAT.dir/formula.c.obj.requires:

.PHONY : CMakeFiles/SAT.dir/formula.c.obj.requires

CMakeFiles/SAT.dir/formula.c.obj.provides: CMakeFiles/SAT.dir/formula.c.obj.requires
	$(MAKE) -f CMakeFiles\SAT.dir\build.make CMakeFiles/SAT.dir/formula.c.obj.provides.build
.PHONY : CMakeFiles/SAT.dir/formula.c.obj.provides

CMakeFiles/SAT.dir/formula.c.obj.provides.build: CMakeFiles/SAT.dir/formula.c.obj


CMakeFiles/SAT.dir/clauses.c.obj: CMakeFiles/SAT.dir/flags.make
CMakeFiles/SAT.dir/clauses.c.obj: ../clauses.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\learning\C program design\SAT\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/SAT.dir/clauses.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\SAT.dir\clauses.c.obj   -c "D:\learning\C program design\SAT\clauses.c"

CMakeFiles/SAT.dir/clauses.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SAT.dir/clauses.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\learning\C program design\SAT\clauses.c" > CMakeFiles\SAT.dir\clauses.c.i

CMakeFiles/SAT.dir/clauses.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SAT.dir/clauses.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "D:\learning\C program design\SAT\clauses.c" -o CMakeFiles\SAT.dir\clauses.c.s

CMakeFiles/SAT.dir/clauses.c.obj.requires:

.PHONY : CMakeFiles/SAT.dir/clauses.c.obj.requires

CMakeFiles/SAT.dir/clauses.c.obj.provides: CMakeFiles/SAT.dir/clauses.c.obj.requires
	$(MAKE) -f CMakeFiles\SAT.dir\build.make CMakeFiles/SAT.dir/clauses.c.obj.provides.build
.PHONY : CMakeFiles/SAT.dir/clauses.c.obj.provides

CMakeFiles/SAT.dir/clauses.c.obj.provides.build: CMakeFiles/SAT.dir/clauses.c.obj


CMakeFiles/SAT.dir/sudoku.c.obj: CMakeFiles/SAT.dir/flags.make
CMakeFiles/SAT.dir/sudoku.c.obj: ../sudoku.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\learning\C program design\SAT\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/SAT.dir/sudoku.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\SAT.dir\sudoku.c.obj   -c "D:\learning\C program design\SAT\sudoku.c"

CMakeFiles/SAT.dir/sudoku.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SAT.dir/sudoku.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\learning\C program design\SAT\sudoku.c" > CMakeFiles\SAT.dir\sudoku.c.i

CMakeFiles/SAT.dir/sudoku.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SAT.dir/sudoku.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "D:\learning\C program design\SAT\sudoku.c" -o CMakeFiles\SAT.dir\sudoku.c.s

CMakeFiles/SAT.dir/sudoku.c.obj.requires:

.PHONY : CMakeFiles/SAT.dir/sudoku.c.obj.requires

CMakeFiles/SAT.dir/sudoku.c.obj.provides: CMakeFiles/SAT.dir/sudoku.c.obj.requires
	$(MAKE) -f CMakeFiles\SAT.dir\build.make CMakeFiles/SAT.dir/sudoku.c.obj.provides.build
.PHONY : CMakeFiles/SAT.dir/sudoku.c.obj.provides

CMakeFiles/SAT.dir/sudoku.c.obj.provides.build: CMakeFiles/SAT.dir/sudoku.c.obj


CMakeFiles/SAT.dir/toCNF.c.obj: CMakeFiles/SAT.dir/flags.make
CMakeFiles/SAT.dir/toCNF.c.obj: ../toCNF.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\learning\C program design\SAT\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/SAT.dir/toCNF.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\SAT.dir\toCNF.c.obj   -c "D:\learning\C program design\SAT\toCNF.c"

CMakeFiles/SAT.dir/toCNF.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SAT.dir/toCNF.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\learning\C program design\SAT\toCNF.c" > CMakeFiles\SAT.dir\toCNF.c.i

CMakeFiles/SAT.dir/toCNF.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SAT.dir/toCNF.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "D:\learning\C program design\SAT\toCNF.c" -o CMakeFiles\SAT.dir\toCNF.c.s

CMakeFiles/SAT.dir/toCNF.c.obj.requires:

.PHONY : CMakeFiles/SAT.dir/toCNF.c.obj.requires

CMakeFiles/SAT.dir/toCNF.c.obj.provides: CMakeFiles/SAT.dir/toCNF.c.obj.requires
	$(MAKE) -f CMakeFiles\SAT.dir\build.make CMakeFiles/SAT.dir/toCNF.c.obj.provides.build
.PHONY : CMakeFiles/SAT.dir/toCNF.c.obj.provides

CMakeFiles/SAT.dir/toCNF.c.obj.provides.build: CMakeFiles/SAT.dir/toCNF.c.obj


CMakeFiles/SAT.dir/menu.c.obj: CMakeFiles/SAT.dir/flags.make
CMakeFiles/SAT.dir/menu.c.obj: ../menu.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\learning\C program design\SAT\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/SAT.dir/menu.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\SAT.dir\menu.c.obj   -c "D:\learning\C program design\SAT\menu.c"

CMakeFiles/SAT.dir/menu.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SAT.dir/menu.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\learning\C program design\SAT\menu.c" > CMakeFiles\SAT.dir\menu.c.i

CMakeFiles/SAT.dir/menu.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SAT.dir/menu.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "D:\learning\C program design\SAT\menu.c" -o CMakeFiles\SAT.dir\menu.c.s

CMakeFiles/SAT.dir/menu.c.obj.requires:

.PHONY : CMakeFiles/SAT.dir/menu.c.obj.requires

CMakeFiles/SAT.dir/menu.c.obj.provides: CMakeFiles/SAT.dir/menu.c.obj.requires
	$(MAKE) -f CMakeFiles\SAT.dir\build.make CMakeFiles/SAT.dir/menu.c.obj.provides.build
.PHONY : CMakeFiles/SAT.dir/menu.c.obj.provides

CMakeFiles/SAT.dir/menu.c.obj.provides.build: CMakeFiles/SAT.dir/menu.c.obj


# Object files for target SAT
SAT_OBJECTS = \
"CMakeFiles/SAT.dir/main.c.obj" \
"CMakeFiles/SAT.dir/vec.c.obj" \
"CMakeFiles/SAT.dir/formula.c.obj" \
"CMakeFiles/SAT.dir/clauses.c.obj" \
"CMakeFiles/SAT.dir/sudoku.c.obj" \
"CMakeFiles/SAT.dir/toCNF.c.obj" \
"CMakeFiles/SAT.dir/menu.c.obj"

# External object files for target SAT
SAT_EXTERNAL_OBJECTS =

SAT.exe: CMakeFiles/SAT.dir/main.c.obj
SAT.exe: CMakeFiles/SAT.dir/vec.c.obj
SAT.exe: CMakeFiles/SAT.dir/formula.c.obj
SAT.exe: CMakeFiles/SAT.dir/clauses.c.obj
SAT.exe: CMakeFiles/SAT.dir/sudoku.c.obj
SAT.exe: CMakeFiles/SAT.dir/toCNF.c.obj
SAT.exe: CMakeFiles/SAT.dir/menu.c.obj
SAT.exe: CMakeFiles/SAT.dir/build.make
SAT.exe: CMakeFiles/SAT.dir/linklibs.rsp
SAT.exe: CMakeFiles/SAT.dir/objects1.rsp
SAT.exe: CMakeFiles/SAT.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\learning\C program design\SAT\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "Linking C executable SAT.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\SAT.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SAT.dir/build: SAT.exe

.PHONY : CMakeFiles/SAT.dir/build

CMakeFiles/SAT.dir/requires: CMakeFiles/SAT.dir/main.c.obj.requires
CMakeFiles/SAT.dir/requires: CMakeFiles/SAT.dir/vec.c.obj.requires
CMakeFiles/SAT.dir/requires: CMakeFiles/SAT.dir/formula.c.obj.requires
CMakeFiles/SAT.dir/requires: CMakeFiles/SAT.dir/clauses.c.obj.requires
CMakeFiles/SAT.dir/requires: CMakeFiles/SAT.dir/sudoku.c.obj.requires
CMakeFiles/SAT.dir/requires: CMakeFiles/SAT.dir/toCNF.c.obj.requires
CMakeFiles/SAT.dir/requires: CMakeFiles/SAT.dir/menu.c.obj.requires

.PHONY : CMakeFiles/SAT.dir/requires

CMakeFiles/SAT.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\SAT.dir\cmake_clean.cmake
.PHONY : CMakeFiles/SAT.dir/clean

CMakeFiles/SAT.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\learning\C program design\SAT" "D:\learning\C program design\SAT" "D:\learning\C program design\SAT\cmake-build-debug" "D:\learning\C program design\SAT\cmake-build-debug" "D:\learning\C program design\SAT\cmake-build-debug\CMakeFiles\SAT.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/SAT.dir/depend

