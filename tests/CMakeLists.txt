# language: CMake

project(Tests LANGUAGES C CXX ASM)

set(Boost_USE_STATIC_LIBS OFF)

if(POLICY CMP0167)
  cmake_policy(SET CMP0167 NEW)
endif()

find_package(Boost REQUIRED COMPONENTS unit_test_framework)

# ----------------------        asm tests        ----------------------
file(GLOB_RECURSE ASM_FUNCS_TEST_SOURCES "assembly_funcs/*.cpp" "test.cpp")
add_executable(ASM_funcs_tests ${ASM_FUNCS_TEST_SOURCES} ${ASM_SOURCES})
target_link_libraries(ASM_funcs_tests PRIVATE ${Boost_LIBRARIES})

# ----------------------         c tests         ----------------------
file(GLOB_RECURSE C_FUNCS_TEST_SOURCES "C_funcs/*.cpp" "test.cpp")
add_executable(C_funcs_tests ${C_FUNCS_TEST_SOURCES} "${MAIN_DIR}/funcs.c")
target_link_libraries(C_funcs_tests PRIVATE ${Boost_LIBRARIES})
