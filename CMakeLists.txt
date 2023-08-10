cmake_minimum_required(VERSION 3.26)
project(CPP3_SmartCalc_v2_0_1)

set(CMAKE_CXX_STANDARD 17)

find_package(PkgConfig)
pkg_check_modules(GTKMM gtkmm-3.0)

link_directories(${GTKMM_LIBRARY_DIRS})
include_directories(${GTKMM_INCLUDE_DIRS})
include_directories(src)

add_executable(test
        src/model/EvaluationModel.h
        src/model/EvaluationModel.cc
        src/tests/tests_main.cc
        src/tests/parsing_suite.cc
        src/tests/calculation_suite.cc
        src/tests/polish_notation_suite.cc)

add_executable(app
        src/main.cc
        src/view/MainWindow.cc
        src/view/MainWindow.h
        src/view/CreditView.cc
        src/view/CreditView.h
        src/view/DepositView.cc
        src/view/DepositView.h
        src/view/GraphView.cc
        src/view/GraphView.h
        src/controller/EvaluationController.cc
        src/controller/EvaluationController.h
        src/model/EvaluationModel.cc
        src/model/EvaluationModel.h
        src/controller/GraphController.cc
        src/controller/GraphController.h
        src/model/GraphModel.cc
        src/model/GraphModel.h
        src/model/utils.cc
        src/model/utils.h
        src/model/utils.h
        src/model/utils.cc
        src/model/CreditModel.cc
        src/model/CreditModel.h
        src/controller/CreditController.cc
        src/controller/CreditController.h)

target_link_libraries(test gtest)
target_link_libraries(app ${GTKMM_LIBRARIES})
