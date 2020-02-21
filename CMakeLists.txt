cmake_minimum_required(VERSION 3.4)

set(CMAKE_CXX_STANDART 11)
set(CMAKE_CXX_STANDART_REQUIRED ON)

project(banking)

enable_testing()
add_subdirectory(gtest/googletest)
add_subdirectory(tests/)

file(GLOB tests/*.cpp)
add_executable(check tests/banking.cpp)
target_link_libraries(check banking googletest-distribution)
add_test(NAME check COMMAND check)

