# language: CMake

cmake_minimum_required(VERSION 3.20)

project(TextTask LANGUAGES C CXX ASM)

# ----------------------        Main Dir        ----------------------
cmake_path(SET MAIN_DIR "${CMAKE_SOURCE_DIR}/main")
cmake_path(SET ASM_DIR "${CMAKE_SOURCE_DIR}/assembly_funcs")

file(GLOB_RECURSE ASM_SOURCES "${ASM_DIR}/*.s" "${ASM_DIR}/*.asm")
file(GLOB_RECURSE C_CPP_SOURCES "${MAIN_DIR}/*.cpp" "${MAIN_DIR}/*.c")

set_property(SOURCE ASM_SOURCES APPEND PROPERTY COMPILE_OPTIONS "-x" "assembler-with-cpp")

add_executable(main ${C_CPP_SOURCES} ${ASM_SOURCES})

# ----------------------        Test Dir        ----------------------
set(Boost_USE_STATIC_LIBS OFF)

find_package(Boost REQUIRED COMPONENTS locale unit_test_framework)

add_subdirectory(tests)
