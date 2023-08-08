cmake_minimum_required(VERSION 3.26)
project(CPP3_SmartCalc_v2_0_1)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)

add_executable(CPP3_SmartCalc_v2_0_1
        src/model/PolishEvaluation.h
        src/model/PolishEvaluation.cpp
        src/tests/tests_main.cpp
        src/tests/parsing_suite.cpp)

target_link_libraries(CPP3_SmartCalc_v2_0_1 gtest)
