
# base configuration
cmake_minimum_required(VERSION 3.0)
project(sckcpptest)

set(GTEST_LIB_DIR external/googletest)

add_subdirectory(${GTEST_LIB_DIR})

include_directories(${GTEST_LIB_DIR}/googletest/include)

include_directories(${CMAKE_SOURCE_DIR}/include)

file(GLOB TEST_SOURCE_FILES *.cpp)

add_executable(${PROJECT_NAME} ${TEST_SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} gtest gtest_main)
target_link_libraries(${PROJECT_NAME} sckcpp)