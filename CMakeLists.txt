# language: CMake

cmake_minimum_required(VERSION 3.20)

project(TextTask LANGUAGES C CXX ASM)

# ----------------------        Main Dir        ----------------------
cmake_path(SET MAIN_DIR "${CMAKE_SOURCE_DIR}/main")
cmake_path(SET ASM_DIR "${CMAKE_SOURCE_DIR}/assembly_funcs")

file(GLOB_RECURSE ASM_SOURCES "${ASM_DIR}/*.s" "${ASM_DIR}/*.asm")

add_executable(main "${MAIN_DIR}/main.cpp" ${ASM_SOURCES})

# ----------------------        Test Dir        ----------------------
add_subdirectory(tests) # comment to disable testing with Boost
