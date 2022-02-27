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
add_library(dynamic_array STATIC src/dynamic_array.cpp include/classwork/dynamic_array.hpp)
target_sources(dynamic_array PUBLIC include/classwork/private/list.hpp)
target_include_directories(dynamic_array PUBLIC include)

add_library(linked_list STATIC src/linked_list.cpp include/classwork/linked_list.hpp)
target_sources(linked_list PUBLIC include/classwork/node.hpp include/classwork/private/list.hpp)
target_include_directories(linked_list PUBLIC include)

add_library(stack STATIC src/array_stack.cpp include/classwork/array_stack.hpp)
target_sources(stack PUBLIC include/classwork/private/stack.hpp)
target_include_directories(stack PUBLIC include)

add_library(queue STATIC src/linked_queue.cpp include/classwork/linked_queue.hpp)
target_sources(queue PUBLIC include/classwork/private/queue.hpp)
target_include_directories(queue PUBLIC include)

# Executables
add_executable(run_${PROJECT_NAME} main.cpp)
target_link_libraries(run_${PROJECT_NAME} PRIVATE dynamic_array linked_list stack queue)

# Warnings
if (ENABLE_COMPILER_WARNINGS)
    message(STATUS "Compiler warnings: enabled")
    add_library(project_warnings INTERFACE)
    set_project_warnings(project_warnings)

    target_link_libraries(run_${PROJECT_NAME} PRIVATE project_warnings)
endif (ENABLE_COMPILER_WARNINGS)
