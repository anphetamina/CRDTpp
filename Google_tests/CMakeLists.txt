cmake_minimum_required(VERSION 3.14)
project(Google_tests)
set(CMAKE_CXX_STANDARD 17)
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(Google_Tests_run SharedEditorTest.cpp)

target_link_libraries(Google_Tests_run gtest gtest_main)