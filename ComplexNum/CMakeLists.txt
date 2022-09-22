cmake_minimum_required(VERSION 3.16)
project(ComplexNum)

include_directories(inc src)
add_compile_options(-std=c++17 -O2)

add_executable(comNumbder driver_complex_number.cpp ../src/ComplexNumber.cpp)
