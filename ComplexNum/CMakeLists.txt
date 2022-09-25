cmake_minimum_required(VERSION 3.16)
project(ComplexNum)

include_directories(inc src testSys)
set(CMAKE_CXX_STANDARD 17)
add_compile_options(-O2)

add_executable(checkTests ../testSys/checkTestSet.cpp ../src/ComplexNumber.cpp)