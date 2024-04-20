cmake_minimum_required(VERSION 3.20)

project(TextTask C CXX ASM)

file(GLOB_RECURSE ASM_SOURCES "assembly_funcs/.s" "assembly_funcs/*.asm")
file(GLOB_RECURSE C_CPP_SOURCES "main/*.cpp" "main/*.c")

set_property(SOURCE ASM_SOURCES APPEND PROPERTY COMPILE_OPTIONS "-x" "assembler-with-cpp")

add_executable(text_task ${C_CPP_SOURCES} ${ASM_SOURCES})