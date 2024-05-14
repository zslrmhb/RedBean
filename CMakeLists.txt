cmake_minimum_required(VERSION 3.20)

project(RedBean)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set the output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Add the include directory
include_directories(${CMAKE_SOURCE_DIR}/RedBean/src)

# Add the executable
add_executable(SandboxApp Sandbox/src/SandboxApp.cpp)

# Set the output directory for object files
set_target_properties(SandboxApp PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    OBJECT_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/obj
)