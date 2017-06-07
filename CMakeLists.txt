cmake_minimum_required(VERSION 3.6)
project(ProcessChain)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES uebung/src/main.cpp uebung/src/Duration.cpp uebung/src/Process.cpp uebung/src/ProcessChain.cpp)
include_directories(uebung/include)
add_executable(ProcessChain ${SOURCE_FILES})