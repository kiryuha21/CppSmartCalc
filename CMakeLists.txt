cmake_minimum_required(VERSION 3.26)
project(CPP3_SmartCalc_v2_0_1)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)

add_executable(CPP3_SmartCalc_v2_0_1
        src/consoleView.cpp
        src/consoleView.h
        src/exampleController.cpp
        src/exampleController.h
        src/exampleModel.cpp
        src/exampleModel.h
        src/main.cpp)
