# Peace-In-Pieces

## Project Overview
Peace-In-Pieces is a gaming experience that enables users to craft and solve puzzles using imported images!

## External Libraries
- [Cocos2d-x](http://www.cocos2d-x.org/): A multi-platform framework for building 2d games, interactive books, demos and other graphical applications.
- [FMOD](http://www.fmod.org/): An easy to use crossplatform audio engine and audio content creation tool for games.

## Build Instructions
A version of [Cocos](http://www.cocos2d-x.org/download) must be downloaded so that the project can be built; we used version 4.0.
Run download-deps.py, as well as setup.py (and install-deps-linux.sh for Linux, and some dependencies need to be fixed for Linux, see [here](https://github.com/cocos2d/cocos2d-x/issues/20471) and [here](https://discuss.cocos2d-x.org/t/error-while-building-for-linux-libfmod-so-6/26553/31?u=doyoque)).

You can run a project by running CMake which creates projects for your system and a make file to create the program. In CLion, the CMake project being reloaded should set up the directories and point out any pressing issues. Running will compile the CMake and the resulting make file, and the program will appear in cmake-build-debug under bin, in the project folder as an executable with the name of the project.
