cmake_minimum_required(VERSION 3.7.2)
project(BetterCPP)

set(CMAKE_CXX_STANDARD 17)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
add_executable(test_binary ${PROJECT_SOURCE_DIR}/test/main.cpp)