# language: CMake

cmake_minimum_required(VERSION 3.20)

project(TextTask LANGUAGES C CXX ASM)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic -std=c++17 -Og")

# ----------------------        Main Dir        ----------------------
cmake_path(SET MAIN_DIR "${CMAKE_CURRENT_SOURCE_DIR}/main")
cmake_path(SET ASM_DIR "${CMAKE_CURRENT_SOURCE_DIR}/assembly_funcs")

file(GLOB_RECURSE ASM_SOURCES "${ASM_DIR}/*.s" "${ASM_DIR}/*.asm")

add_executable(assembly_text_task "${MAIN_DIR}/main.cpp" ${ASM_SOURCES})

# ----------------------        Test Dir        ----------------------
add_subdirectory(tests) # comment to disable testing with Boost
