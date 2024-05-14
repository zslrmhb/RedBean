cmake_minimum_required(VERSION 3.20)

project(RedBean LANGUAGES CXX)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set the output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Add the include directory
include_directories(${CMAKE_SOURCE_DIR}/RedBean/src)
include_directories(${CMAKE_SOURCE_DIR}/RedBean/3rdparty/spdlog/include)

# source file
file(GLOB_RECURSE REDBEAN_SRC "RedBean/src/*.cpp")
file(GLOB_RECURSE SANDBOX_SRC "Sandbox/src/*.cpp")

# Add the executable
add_executable(SandboxApp ${REDBEAN_SRC} ${SANDBOX_SRC})

# Link spdlog library (if you use it as an external dependency)
add_subdirectory(RedBean/3rdparty/spdlog)
target_link_libraries(SandboxApp PRIVATE spdlog::spdlog)

# Set the output directory for object files
set_target_properties(SandboxApp PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    OBJECT_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/obj
)