# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.23.2/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.23.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/xin/Desktop/NTU/大一下/資料結構/DSAP110-Final-v0.1.2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/xin/Desktop/NTU/大一下/資料結構/DSAP110-Final-v0.1.2/build

# Include any dependencies generated for this target.
include CMakeFiles/DSAP_Final.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/DSAP_Final.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/DSAP_Final.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DSAP_Final.dir/flags.make

CMakeFiles/DSAP_Final.dir/src/main.cpp.o: CMakeFiles/DSAP_Final.dir/flags.make
CMakeFiles/DSAP_Final.dir/src/main.cpp.o: ../src/main.cpp
CMakeFiles/DSAP_Final.dir/src/main.cpp.o: CMakeFiles/DSAP_Final.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/xin/Desktop/NTU/大一下/資料結構/DSAP110-Final-v0.1.2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DSAP_Final.dir/src/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DSAP_Final.dir/src/main.cpp.o -MF CMakeFiles/DSAP_Final.dir/src/main.cpp.o.d -o CMakeFiles/DSAP_Final.dir/src/main.cpp.o -c /Users/xin/Desktop/NTU/大一下/資料結構/DSAP110-Final-v0.1.2/src/main.cpp

CMakeFiles/DSAP_Final.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DSAP_Final.dir/src/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/xin/Desktop/NTU/大一下/資料結構/DSAP110-Final-v0.1.2/src/main.cpp > CMakeFiles/DSAP_Final.dir/src/main.cpp.i

CMakeFiles/DSAP_Final.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DSAP_Final.dir/src/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/xin/Desktop/NTU/大一下/資料結構/DSAP110-Final-v0.1.2/src/main.cpp -o CMakeFiles/DSAP_Final.dir/src/main.cpp.s

CMakeFiles/DSAP_Final.dir/src/Snake.cpp.o: CMakeFiles/DSAP_Final.dir/flags.make
CMakeFiles/DSAP_Final.dir/src/Snake.cpp.o: ../src/Snake.cpp
CMakeFiles/DSAP_Final.dir/src/Snake.cpp.o: CMakeFiles/DSAP_Final.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/xin/Desktop/NTU/大一下/資料結構/DSAP110-Final-v0.1.2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/DSAP_Final.dir/src/Snake.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DSAP_Final.dir/src/Snake.cpp.o -MF CMakeFiles/DSAP_Final.dir/src/Snake.cpp.o.d -o CMakeFiles/DSAP_Final.dir/src/Snake.cpp.o -c /Users/xin/Desktop/NTU/大一下/資料結構/DSAP110-Final-v0.1.2/src/Snake.cpp

CMakeFiles/DSAP_Final.dir/src/Snake.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DSAP_Final.dir/src/Snake.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/xin/Desktop/NTU/大一下/資料結構/DSAP110-Final-v0.1.2/src/Snake.cpp > CMakeFiles/DSAP_Final.dir/src/Snake.cpp.i

CMakeFiles/DSAP_Final.dir/src/Snake.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DSAP_Final.dir/src/Snake.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/xin/Desktop/NTU/大一下/資料結構/DSAP110-Final-v0.1.2/src/Snake.cpp -o CMakeFiles/DSAP_Final.dir/src/Snake.cpp.s

CMakeFiles/DSAP_Final.dir/src/Game.cpp.o: CMakeFiles/DSAP_Final.dir/flags.make
CMakeFiles/DSAP_Final.dir/src/Game.cpp.o: ../src/Game.cpp
CMakeFiles/DSAP_Final.dir/src/Game.cpp.o: CMakeFiles/DSAP_Final.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/xin/Desktop/NTU/大一下/資料結構/DSAP110-Final-v0.1.2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/DSAP_Final.dir/src/Game.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DSAP_Final.dir/src/Game.cpp.o -MF CMakeFiles/DSAP_Final.dir/src/Game.cpp.o.d -o CMakeFiles/DSAP_Final.dir/src/Game.cpp.o -c /Users/xin/Desktop/NTU/大一下/資料結構/DSAP110-Final-v0.1.2/src/Game.cpp

CMakeFiles/DSAP_Final.dir/src/Game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DSAP_Final.dir/src/Game.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/xin/Desktop/NTU/大一下/資料結構/DSAP110-Final-v0.1.2/src/Game.cpp > CMakeFiles/DSAP_Final.dir/src/Game.cpp.i

CMakeFiles/DSAP_Final.dir/src/Game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DSAP_Final.dir/src/Game.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/xin/Desktop/NTU/大一下/資料結構/DSAP110-Final-v0.1.2/src/Game.cpp -o CMakeFiles/DSAP_Final.dir/src/Game.cpp.s

CMakeFiles/DSAP_Final.dir/src/Position.cpp.o: CMakeFiles/DSAP_Final.dir/flags.make
CMakeFiles/DSAP_Final.dir/src/Position.cpp.o: ../src/Position.cpp
CMakeFiles/DSAP_Final.dir/src/Position.cpp.o: CMakeFiles/DSAP_Final.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/xin/Desktop/NTU/大一下/資料結構/DSAP110-Final-v0.1.2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/DSAP_Final.dir/src/Position.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DSAP_Final.dir/src/Position.cpp.o -MF CMakeFiles/DSAP_Final.dir/src/Position.cpp.o.d -o CMakeFiles/DSAP_Final.dir/src/Position.cpp.o -c /Users/xin/Desktop/NTU/大一下/資料結構/DSAP110-Final-v0.1.2/src/Position.cpp

CMakeFiles/DSAP_Final.dir/src/Position.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DSAP_Final.dir/src/Position.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/xin/Desktop/NTU/大一下/資料結構/DSAP110-Final-v0.1.2/src/Position.cpp > CMakeFiles/DSAP_Final.dir/src/Position.cpp.i

CMakeFiles/DSAP_Final.dir/src/Position.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DSAP_Final.dir/src/Position.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/xin/Desktop/NTU/大一下/資料結構/DSAP110-Final-v0.1.2/src/Position.cpp -o CMakeFiles/DSAP_Final.dir/src/Position.cpp.s

CMakeFiles/DSAP_Final.dir/src/GUI.cpp.o: CMakeFiles/DSAP_Final.dir/flags.make
CMakeFiles/DSAP_Final.dir/src/GUI.cpp.o: ../src/GUI.cpp
CMakeFiles/DSAP_Final.dir/src/GUI.cpp.o: CMakeFiles/DSAP_Final.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/xin/Desktop/NTU/大一下/資料結構/DSAP110-Final-v0.1.2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/DSAP_Final.dir/src/GUI.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DSAP_Final.dir/src/GUI.cpp.o -MF CMakeFiles/DSAP_Final.dir/src/GUI.cpp.o.d -o CMakeFiles/DSAP_Final.dir/src/GUI.cpp.o -c /Users/xin/Desktop/NTU/大一下/資料結構/DSAP110-Final-v0.1.2/src/GUI.cpp

CMakeFiles/DSAP_Final.dir/src/GUI.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DSAP_Final.dir/src/GUI.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/xin/Desktop/NTU/大一下/資料結構/DSAP110-Final-v0.1.2/src/GUI.cpp > CMakeFiles/DSAP_Final.dir/src/GUI.cpp.i

CMakeFiles/DSAP_Final.dir/src/GUI.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DSAP_Final.dir/src/GUI.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/xin/Desktop/NTU/大一下/資料結構/DSAP110-Final-v0.1.2/src/GUI.cpp -o CMakeFiles/DSAP_Final.dir/src/GUI.cpp.s

CMakeFiles/DSAP_Final.dir/src/StraightForwardController.cpp.o: CMakeFiles/DSAP_Final.dir/flags.make
CMakeFiles/DSAP_Final.dir/src/StraightForwardController.cpp.o: ../src/StraightForwardController.cpp
CMakeFiles/DSAP_Final.dir/src/StraightForwardController.cpp.o: CMakeFiles/DSAP_Final.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/xin/Desktop/NTU/大一下/資料結構/DSAP110-Final-v0.1.2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/DSAP_Final.dir/src/StraightForwardController.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DSAP_Final.dir/src/StraightForwardController.cpp.o -MF CMakeFiles/DSAP_Final.dir/src/StraightForwardController.cpp.o.d -o CMakeFiles/DSAP_Final.dir/src/StraightForwardController.cpp.o -c /Users/xin/Desktop/NTU/大一下/資料結構/DSAP110-Final-v0.1.2/src/StraightForwardController.cpp

CMakeFiles/DSAP_Final.dir/src/StraightForwardController.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DSAP_Final.dir/src/StraightForwardController.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/xin/Desktop/NTU/大一下/資料結構/DSAP110-Final-v0.1.2/src/StraightForwardController.cpp > CMakeFiles/DSAP_Final.dir/src/StraightForwardController.cpp.i

CMakeFiles/DSAP_Final.dir/src/StraightForwardController.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DSAP_Final.dir/src/StraightForwardController.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/xin/Desktop/NTU/大一下/資料結構/DSAP110-Final-v0.1.2/src/StraightForwardController.cpp -o CMakeFiles/DSAP_Final.dir/src/StraightForwardController.cpp.s

# Object files for target DSAP_Final
DSAP_Final_OBJECTS = \
"CMakeFiles/DSAP_Final.dir/src/main.cpp.o" \
"CMakeFiles/DSAP_Final.dir/src/Snake.cpp.o" \
"CMakeFiles/DSAP_Final.dir/src/Game.cpp.o" \
"CMakeFiles/DSAP_Final.dir/src/Position.cpp.o" \
"CMakeFiles/DSAP_Final.dir/src/GUI.cpp.o" \
"CMakeFiles/DSAP_Final.dir/src/StraightForwardController.cpp.o"

# External object files for target DSAP_Final
DSAP_Final_EXTERNAL_OBJECTS =

DSAP_Final: CMakeFiles/DSAP_Final.dir/src/main.cpp.o
DSAP_Final: CMakeFiles/DSAP_Final.dir/src/Snake.cpp.o
DSAP_Final: CMakeFiles/DSAP_Final.dir/src/Game.cpp.o
DSAP_Final: CMakeFiles/DSAP_Final.dir/src/Position.cpp.o
DSAP_Final: CMakeFiles/DSAP_Final.dir/src/GUI.cpp.o
DSAP_Final: CMakeFiles/DSAP_Final.dir/src/StraightForwardController.cpp.o
DSAP_Final: CMakeFiles/DSAP_Final.dir/build.make
DSAP_Final: /Library/Frameworks/./sfml-network.framework/Versions/2.5.1/sfml-network
DSAP_Final: /Library/Frameworks/./sfml-graphics.framework/Versions/2.5.1/sfml-graphics
DSAP_Final: /Library/Frameworks/./sfml-window.framework/Versions/2.5.1/sfml-window
DSAP_Final: /Library/Frameworks/./sfml-system.framework/Versions/2.5.1/sfml-system
DSAP_Final: CMakeFiles/DSAP_Final.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/xin/Desktop/NTU/大一下/資料結構/DSAP110-Final-v0.1.2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable DSAP_Final"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DSAP_Final.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DSAP_Final.dir/build: DSAP_Final
.PHONY : CMakeFiles/DSAP_Final.dir/build

CMakeFiles/DSAP_Final.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/DSAP_Final.dir/cmake_clean.cmake
.PHONY : CMakeFiles/DSAP_Final.dir/clean

CMakeFiles/DSAP_Final.dir/depend:
	cd /Users/xin/Desktop/NTU/大一下/資料結構/DSAP110-Final-v0.1.2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/xin/Desktop/NTU/大一下/資料結構/DSAP110-Final-v0.1.2 /Users/xin/Desktop/NTU/大一下/資料結構/DSAP110-Final-v0.1.2 /Users/xin/Desktop/NTU/大一下/資料結構/DSAP110-Final-v0.1.2/build /Users/xin/Desktop/NTU/大一下/資料結構/DSAP110-Final-v0.1.2/build /Users/xin/Desktop/NTU/大一下/資料結構/DSAP110-Final-v0.1.2/build/CMakeFiles/DSAP_Final.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DSAP_Final.dir/depend
