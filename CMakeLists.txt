# This is the top-level CMakeLists.txt file

cmake_minimum_required(VERSION 3.15 FATAL_ERROR)

project(classwork CXX)

# C++ standard specification
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Helpers
include(CMakePrintHelpers)
include(cmake/CompilerWarnings.cmake)

# Options
option(ENABLE_COMPILER_WARNINGS "Project compile warnings." ON)

cmake_print_variables(CMAKE_BUILD_TYPE ENABLE_COMPILER_WARNINGS CMAKE_CXX_FLAGS)

# Libraries
add_library(dynamic_array STATIC src/dynamic_array.cpp)
target_sources(dynamic_array PUBLIC include/classwork/dynamic_array.hpp)
target_include_directories(dynamic_array PUBLIC include)

add_library(linked_list STATIC src/linked_list.cpp)
target_sources(linked_list PUBLIC include/classwork/node.hpp include/classwork/linked_list.hpp)
target_include_directories(linked_list PUBLIC include)

add_library(stack STATIC src/array_stack.cpp src/linked_stack.cpp)
target_include_directories(stack PUBLIC include)

target_sources(stack PUBLIC
        include/classwork/private/stack.hpp
        include/classwork/array_stack.hpp
        include/classwork/linked_stack.hpp)

# Executables
add_executable(run_${PROJECT_NAME} main.cpp)
target_link_libraries(run_${PROJECT_NAME} PRIVATE dynamic_array linked_list stack)

# Warnings
if (ENABLE_COMPILER_WARNINGS)
    message(STATUS "Compiler warnings: enabled")
    add_library(project_warnings INTERFACE)
    set_project_warnings(project_warnings)

    target_link_libraries(run_${PROJECT_NAME} PRIVATE project_warnings)
endif (ENABLE_COMPILER_WARNINGS)
