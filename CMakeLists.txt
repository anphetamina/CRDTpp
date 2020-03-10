cmake_minimum_required(VERSION 3.14)
project(LSEQpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(LSEQpp "main.cpp" "Symbol.cpp" "Symbol.h" "NetworkServer.cpp" "NetworkServer.h" "SharedEditor.cpp" "SharedEditor.h" "Message.cpp" "Message.h")
