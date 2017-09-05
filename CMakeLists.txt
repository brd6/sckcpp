cmake_minimum_required(VERSION 3.0)
project(sckcpp)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES src/sckcpp/library.cpp)

# Include directory
set(SCKCPP_INCLUDE include)
include_directories(${SCKCPP})

file(GLOB_RECURSE SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

file(GLOB_RECURSE INCLUDE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp)

# Source files
set(SOURCE_FILES ${SOURCE_FILES} ${INCLUDE_FILES})

# Lib configuration
add_library(${PROJECT_NAME} ${SOURCE_FILES})

# Install lib
install(TARGETS ${PROJECT_NAME} DESTINATION .)

install(DIRECTORY ${B2GE_INCLUDE} DESTINATION .)