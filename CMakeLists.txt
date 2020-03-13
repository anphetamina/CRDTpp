cmake_minimum_required(VERSION 3.14)
project(CRDTpp)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(Google_tests)
add_executable(CRDTpp "main.cpp" "Symbol.cpp" "Symbol.h" "NetworkServer.cpp" "NetworkServer.h" "SharedEditor.cpp" "SharedEditor.h" "Message.cpp" "Message.h")
