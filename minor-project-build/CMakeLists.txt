cmake_minimum_required(VERSION 3.0.0)

project(main)

find_program(GNUPLOT gnuplot)
if(NOT GNUPLOT)
    message(FATAL_ERROR "Gnuplot not found! Please install Gnuplot.")
endif()

#include the header files
include_directories(inc)

#includig SOURCES files at once (wildcard method)
file(GLOB SOURCES "src/*.cpp" "src/*.h")

#set the executable file name and the SOURCES
add_executable(${PROJECT_NAME} ${SOURCES})