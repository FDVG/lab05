cmake_minimum_required(VERSION 3.4)

set(CMAKE_CXX_STANDART 11)
set(CMAKE_CXX_STANDART_REQUIRED ON)

project(banking)

enable_testing()
add_subdirectory(gtest/googletest)

file(GLOB ${PROJECT_NAME}_TEST_SOURCES tests/*.cpp)
add_executable(check ${${PROJECT_NAME}_TEST_SOURCES})
target_link_libraries(check ${PROJECT_NAME} gtest_main)
add_test(NAME check COMMAND check)

