cmake_minimum_required(VERSION 3.28)
project(DiscreteStructures VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

# Lab 1
set(L1_MAIN_SOURCES 
    ${CMAKE_CURRENT_SOURCE_DIR}/Lab1/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Lab1/functions.cpp
    )

set(L1_TEST_SOURCES 
    ${CMAKE_CURRENT_SOURCE_DIR}/Lab1/sampleTests.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Lab1/functions.cpp
    )

add_executable(Lab1 ${L1_MAIN_SOURCES})
add_executable(Lab1_tests ${L1_TEST_SOURCES})

target_include_directories(Lab1 PRIVATE {CMAKE_CURRENT_SOURCE_DIR}/Lab1)
target_include_directories(Lab1_tests PRIVATE {CMAKE_CURRENT_SOURCE_DIR}/Lab1)

# Lab 2
set(L2_MAIN_SOURCES 
    ${CMAKE_CURRENT_SOURCE_DIR}/Lab2/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Lab2/set.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Lab2/setFunctions.cpp
    )

# set(L2_TEST_SOURCES 
#     ${CMAKE_CURRENT_SOURCE_DIR}/Lab2/sampleTests.cpp
#     ${CMAKE_CURRENT_SOURCE_DIR}/Lab2/functions.cpp
#     )

add_executable(Lab2 ${L2_MAIN_SOURCES})
# add_executable(Lab2_tests ${L2_TEST_SOURCES})

target_include_directories(Lab2 PRIVATE {CMAKE_CURRENT_SOURCE_DIR}/Lab2)
# target_include_directories(Lab2_tests PRIVATE {CMAKE_CURRENT_SOURCE_DIR}/Lab2)