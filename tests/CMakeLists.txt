# language: CMake

project(tests VERSION 0.1 LANGUAGES CXX)

file(GLOB_RECURSE C_FUNCS_TEST_SOURCES "C_funcs/*.cpp" "test.cpp")
file(GLOB_RECURSE ASM_FUNCS_TEST_SOURCES "assembly_funcs/*.cpp" "test.cpp")

add_executable(C_funcs_tests ${C_FUNCS_TEST_SOURCES} "${MAIN_DIR}/funcs.c")
add_executable(ASM_funcs_tests ${ASM_FUNCS_TEST_SOURCES} ${ASM_SOURCES})

target_link_libraries(C_funcs_tests PRIVATE ${Boost_LIBRARIES})
target_link_libraries(ASM_funcs_tests PRIVATE ${Boost_LIBRARIES})
