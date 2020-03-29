cmake_minimum_required(VERSION 3.14)
project(Google_tests)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS --coverage)
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

#add_executable(Google_Tests_run ../src/Symbol.cpp ../src/Symbol.h ../src/NetworkServer.cpp ../src/NetworkServer.h ../src/SharedEditor.cpp ../src/SharedEditor.h ../src/Message.cpp ../src/Message.h SharedEditorTest.cpp)

#file(GLOB SOURCE_FILES
#        "../src/*.h"
#        "../src/*.cpp"
#        )

add_executable(Google_Tests_run ${SOURCE_FILES} SharedEditorTest.cpp)

target_link_libraries(Google_Tests_run gtest gtest_main)
