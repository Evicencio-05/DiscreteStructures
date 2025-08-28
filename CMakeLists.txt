cmake_minimum_required(VERSION 3.28)
project(DiscreteStructures VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

set(MAIN_SOURCES 
    ${CMAKE_CURRENT_SOURCE_DIR}/Lab1/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Lab1/functions.cpp
    )

set(TEST_SOURCES 
    ${CMAKE_CURRENT_SOURCE_DIR}/Lab1/sampleTests.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Lab1/functions.cpp
    )

add_executable(Lab1 ${MAIN_SOURCES})
add_executable(Lab1_tests ${TEST_SOURCES})

target_include_directories(Lab1 PRIVATE {CMAKE_CURRENT_SOURCE_DIR}/Lab1)
target_include_directories(Lab1_tests PRIVATE {CMAKE_CURRENT_SOURCE_DIR}/Lab1)