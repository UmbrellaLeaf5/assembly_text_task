# language: CMake

project(tests VERSION 0.1 LANGUAGES CXX)

file(GLOB_RECURSE TEST_SOURCES "*.cpp")

add_executable(tests ${TEST_SOURCES} "${MAIN_DIR}/funcs.c")

target_link_libraries(tests PRIVATE ${Boost_LIBRARIES})
