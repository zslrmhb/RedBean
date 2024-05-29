cmake_minimum_required(VERSION 3.20)

project(RedBean LANGUAGES CXX)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set the output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Add the include directory
include_directories(${CMAKE_SOURCE_DIR}/RedBean/src)
include_directories(${CMAKE_SOURCE_DIR}/RedBean/3rdparty/spdlog/include)
include_directories(${CMAKE_SOURCE_DIR}/RedBean/3rdparty/GLFW/include)
include_directories(${CMAKE_SOURCE_DIR}/RedBean/3rdparty/glad/include)
include_directories(${CMAKE_SOURCE_DIR}/RedBean/3rdparty/imgui)
include_directories(${CMAKE_SOURCE_DIR}/RedBean/3rdparty/imgui/backends)

message(STATUS "CMake Source Directory: ${CMAKE_SOURCE_DIR}")
message(STATUS "ImGui include directory: ${CMAKE_SOURCE_DIR}/RedBean/3rdparty/imgui")
message(STATUS "ImGui backends include directory: ${CMAKE_SOURCE_DIR}/RedBean/3rdparty/imgui/backends")

# source file
file(GLOB_RECURSE REDBEAN_SRC "RedBean/src/*.cpp")
file(GLOB_RECURSE SANDBOX_SRC "Sandbox/src/*.cpp")

# Add the executable
add_executable(SandboxApp ${REDBEAN_SRC} ${SANDBOX_SRC})

# Link spdlog library (if you use it as an external dependency)
add_subdirectory(RedBean/3rdparty/spdlog)
add_subdirectory(RedBean/3rdparty/GLFW)

find_package(OpenGL REQUIRED)

# Make sure glad source files are compiled
file(GLOB_RECURSE GLAD_SRC "RedBean/3rdparty/glad/src/*.cpp")

add_library(glad STATIC ${GLAD_SRC})
target_include_directories(glad PUBLIC RedBean/3rdparty/glad/include)

# ImGui source files
file(GLOB IMGUI_SRC
    "${CMAKE_SOURCE_DIR}/RedBean/3rdparty/imgui/*.cpp"
    "${CMAKE_SOURCE_DIR}/RedBean/3rdparty/imgui/backends/imgui_impl_glfw.cpp"
    "${CMAKE_SOURCE_DIR}/RedBean/3rdparty/imgui/backends/imgui_impl_opengl3.cpp"
)

# Create ImGui library
add_library(imgui STATIC ${IMGUI_SRC})
target_include_directories(imgui PUBLIC RedBean/3rdparty/imgui)
target_include_directories(imgui PUBLIC RedBean/3rdparty/imgui/backends)

target_link_libraries(SandboxApp PRIVATE spdlog glfw glad imgui ${OPENGL_gl_LIBRARY} "-framework Cocoa")

# Set the output directory for object files
set_target_properties(SandboxApp PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    OBJECT_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/obj
)