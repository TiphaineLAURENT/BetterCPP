cmake_minimum_required(VERSION 3.10.2)
project(BetterCPP)

set(CMAKE_CXX_STANDARD 17)

set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib)
set(LIB_TYPE_SOURCES
        src/type/Value/Value.hpp src/type/Value/Value.cpp
        src/type/type.hpp
        )
add_library(type SHARED ${LIB_TYPE_SOURCES})
set_target_properties(type PROPERTIES LINKER_LANGUAGE CXX)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
add_executable(test_binary ${PROJECT_SOURCE_DIR}/test/main.cpp)