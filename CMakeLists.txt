cmake_minimum_required(VERSION 3.21)
project(CRoboter)

set(CMAKE_CXX_STANDARD 14)

add_executable(CRoboter
        Makefile
        main.c measuring.c walkingBack.c malloc2dCharArray.c free2dCharArray.c decideHowToWalkBack.c populate2dCharArray.c)
