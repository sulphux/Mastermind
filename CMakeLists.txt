cmake_minimum_required (VERSION 3.14)

project(Mastermind LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

enable_testing()

#include_directories(src)

add_subdirectory (source)
add_subdirectory (tests)
#add_subdirectory (lib/googletest)
