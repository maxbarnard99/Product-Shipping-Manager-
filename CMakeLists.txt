# set minimum cmake version
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# project name and language
project(CA6.1 LANGUAGES CXX)

# require C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define binary and library paths according to GNU standards:
include(GNUInstallDirs)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR})

# Add source directory
add_subdirectory(src)

option(USE_TEST "Compile activity with unit test" OFF)
# To Enable Testing, go to your build directory and clear all files, then 
# use the -D option to enable the USE_TEST option
# cd build 
# rm *
#  cmake -G "MinGW Makefiles"  -D USE_TEST=ON ..
if(USE_TEST)
    enable_testing()
    add_subdirectory(tests)
endif()