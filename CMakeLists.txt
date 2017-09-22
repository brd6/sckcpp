cmake_minimum_required(VERSION 3.0)
project(sckcpp)

set(CMAKE_CXX_STANDARD 11)

set(ENABLE_BUILD_TESTS true)

# Include directory
set(SCKCPP_INCLUDE include)
include_directories(${SCKCPP_INCLUDE})

IF (WIN32)
    set(SOURCE_FILES src/sckcpp/Socket.cpp src/sckcpp/win/BaseSocket.cpp src/sckcpp/win/SockAddress.cpp)
    set(INCLUDE_FILES include/sckcpp/Buffer.hpp
            include/sckcpp/SockAddress.hpp
            include/sckcpp/Socket.hpp
            include/sckcpp/SocketException.hpp
            include/sckcpp/socketPlateform.hpp
            include/sckcpp/sckcpp.hpp
            include/sckcpp/win/socketPlateform.hpp
            include/sckcpp/win/SockAddress.hpp
            include/sckcpp/win/BaseSocket.hpp)

ELSE()
    set(SOURCE_FILES src/sckcpp/Socket.cpp src/sckcpp/unix/BaseSocket.cpp src/sckcpp/unix/SockAddress.cpp)
    set(INCLUDE_FILES include/sckcpp/Buffer.hpp
            include/sckcpp/SockAddress.hpp
            include/sckcpp/Socket.hpp
            include/sckcpp/SocketException.hpp
            include/sckcpp/socketPlateform.hpp
            include/sckcpp/sckcpp.hpp
            include/sckcpp/unix/socketPlateform.hpp
            include/sckcpp/unix/SockAddress.hpp
            include/sckcpp/unix/BaseSocket.hpp)
ENDIF()

# Source files
set(SOURCE_FILES ${SOURCE_FILES} ${INCLUDE_FILES})

# Unit test
if (ENABLE_BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()

# Lib configuration
add_library(${PROJECT_NAME} ${SOURCE_FILES})

add_subdirectory(example/server)
add_subdirectory(example/client)

IF(WIN32)
    target_link_libraries(${PROJECT_NAME} wsock32 ws2_32)
ENDIF()

# Install lib
install(TARGETS ${PROJECT_NAME} DESTINATION .)

install(DIRECTORY ${B2GE_INCLUDE} DESTINATION .)