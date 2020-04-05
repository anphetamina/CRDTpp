cmake_minimum_required(VERSION 3.14)
project(CRDTpp_multi)

set(CMAKE_CXX_STANDARD 17)

file(GLOB SOURCE_FILES
        "src/*.h"
        "src/*.cpp"
        )

add_executable(CRDTpp_multi main.cpp ${SOURCE_FILES})

add_subdirectory(Google_tests)