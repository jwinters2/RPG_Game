# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jamie/Programming/RPG-game

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jamie/Programming/RPG-game

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/bin/ccmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/jamie/Programming/RPG-game/CMakeFiles /home/jamie/Programming/RPG-game/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/jamie/Programming/RPG-game/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named RPG_Game

# Build rule for target.
RPG_Game: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 RPG_Game
.PHONY : RPG_Game

# fast build rule for target.
RPG_Game/fast:
	$(MAKE) -f CMakeFiles/RPG_Game.dir/build.make CMakeFiles/RPG_Game.dir/build
.PHONY : RPG_Game/fast

main.o: main.cpp.o

.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) -f CMakeFiles/RPG_Game.dir/build.make CMakeFiles/RPG_Game.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i

.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) -f CMakeFiles/RPG_Game.dir/build.make CMakeFiles/RPG_Game.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s

.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) -f CMakeFiles/RPG_Game.dir/build.make CMakeFiles/RPG_Game.dir/main.cpp.s
.PHONY : main.cpp.s

src/Camera.o: src/Camera.cpp.o

.PHONY : src/Camera.o

# target to build an object file
src/Camera.cpp.o:
	$(MAKE) -f CMakeFiles/RPG_Game.dir/build.make CMakeFiles/RPG_Game.dir/src/Camera.cpp.o
.PHONY : src/Camera.cpp.o

src/Camera.i: src/Camera.cpp.i

.PHONY : src/Camera.i

# target to preprocess a source file
src/Camera.cpp.i:
	$(MAKE) -f CMakeFiles/RPG_Game.dir/build.make CMakeFiles/RPG_Game.dir/src/Camera.cpp.i
.PHONY : src/Camera.cpp.i

src/Camera.s: src/Camera.cpp.s

.PHONY : src/Camera.s

# target to generate assembly for a file
src/Camera.cpp.s:
	$(MAKE) -f CMakeFiles/RPG_Game.dir/build.make CMakeFiles/RPG_Game.dir/src/Camera.cpp.s
.PHONY : src/Camera.cpp.s

src/GraphicsManager.o: src/GraphicsManager.cpp.o

.PHONY : src/GraphicsManager.o

# target to build an object file
src/GraphicsManager.cpp.o:
	$(MAKE) -f CMakeFiles/RPG_Game.dir/build.make CMakeFiles/RPG_Game.dir/src/GraphicsManager.cpp.o
.PHONY : src/GraphicsManager.cpp.o

src/GraphicsManager.i: src/GraphicsManager.cpp.i

.PHONY : src/GraphicsManager.i

# target to preprocess a source file
src/GraphicsManager.cpp.i:
	$(MAKE) -f CMakeFiles/RPG_Game.dir/build.make CMakeFiles/RPG_Game.dir/src/GraphicsManager.cpp.i
.PHONY : src/GraphicsManager.cpp.i

src/GraphicsManager.s: src/GraphicsManager.cpp.s

.PHONY : src/GraphicsManager.s

# target to generate assembly for a file
src/GraphicsManager.cpp.s:
	$(MAKE) -f CMakeFiles/RPG_Game.dir/build.make CMakeFiles/RPG_Game.dir/src/GraphicsManager.cpp.s
.PHONY : src/GraphicsManager.cpp.s

src/Math.o: src/Math.cpp.o

.PHONY : src/Math.o

# target to build an object file
src/Math.cpp.o:
	$(MAKE) -f CMakeFiles/RPG_Game.dir/build.make CMakeFiles/RPG_Game.dir/src/Math.cpp.o
.PHONY : src/Math.cpp.o

src/Math.i: src/Math.cpp.i

.PHONY : src/Math.i

# target to preprocess a source file
src/Math.cpp.i:
	$(MAKE) -f CMakeFiles/RPG_Game.dir/build.make CMakeFiles/RPG_Game.dir/src/Math.cpp.i
.PHONY : src/Math.cpp.i

src/Math.s: src/Math.cpp.s

.PHONY : src/Math.s

# target to generate assembly for a file
src/Math.cpp.s:
	$(MAKE) -f CMakeFiles/RPG_Game.dir/build.make CMakeFiles/RPG_Game.dir/src/Math.cpp.s
.PHONY : src/Math.cpp.s

src/ObjModel.o: src/ObjModel.cpp.o

.PHONY : src/ObjModel.o

# target to build an object file
src/ObjModel.cpp.o:
	$(MAKE) -f CMakeFiles/RPG_Game.dir/build.make CMakeFiles/RPG_Game.dir/src/ObjModel.cpp.o
.PHONY : src/ObjModel.cpp.o

src/ObjModel.i: src/ObjModel.cpp.i

.PHONY : src/ObjModel.i

# target to preprocess a source file
src/ObjModel.cpp.i:
	$(MAKE) -f CMakeFiles/RPG_Game.dir/build.make CMakeFiles/RPG_Game.dir/src/ObjModel.cpp.i
.PHONY : src/ObjModel.cpp.i

src/ObjModel.s: src/ObjModel.cpp.s

.PHONY : src/ObjModel.s

# target to generate assembly for a file
src/ObjModel.cpp.s:
	$(MAKE) -f CMakeFiles/RPG_Game.dir/build.make CMakeFiles/RPG_Game.dir/src/ObjModel.cpp.s
.PHONY : src/ObjModel.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... RPG_Game"
	@echo "... edit_cache"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
	@echo "... src/Camera.o"
	@echo "... src/Camera.i"
	@echo "... src/Camera.s"
	@echo "... src/GraphicsManager.o"
	@echo "... src/GraphicsManager.i"
	@echo "... src/GraphicsManager.s"
	@echo "... src/Math.o"
	@echo "... src/Math.i"
	@echo "... src/Math.s"
	@echo "... src/ObjModel.o"
	@echo "... src/ObjModel.i"
	@echo "... src/ObjModel.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system
