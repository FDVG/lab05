cmake_minimum_required(VERSION 3.4)

set(CMAKE_CXX_STANDART 11)
set(CMAKE_CXX_STANDART_REQUIRED ON)

project(test)

enable_testing()
include(${CMAKE_CURRENT_SOURCE_DIR}/gtest/googletest/CMakeLists.txt)
include(/tests/)
include(${CMAKE_CURRENT_SOURCE_DIR}/banking/)

add_library(banking STATIC ${CMAKE_CURRENT_SOURCE_DIR}/banking/Account.cpp ${CMAKE_CURRENT_SOURCE_DIR}/banking/Transaction.cpp)

add_executable(check tests/banking.cpp)
target_link_libraries(check banking googletest-distribution)
#add_test(NAME check COMMAND check)

