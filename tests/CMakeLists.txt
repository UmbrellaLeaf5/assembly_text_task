# language: CMake

project(tests VERSION 0.1 LANGUAGES CXX)

file(GLOB_RECURSE PROJECT_SOURCES "*.cpp")

include_directories(${PROJECT_DIR})

add_executable(tests ${PROJECT_SOURCES})

target_link_libraries(tests PRIVATE ${Boost_LIBRARIES})
