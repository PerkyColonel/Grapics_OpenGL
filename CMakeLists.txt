cmake_minimum_required(VERSION 3.19.2)

project(GRAPHICS_OPENGL)

include(ExternalProject)

# Configure the ExternalProject to download and build GLFW
set(CMAKE_PREFIX_PATH "${CMAKE_BINARY_DIR}/glfw/lib/cmake/glfw3" CACHE PATH "Path to GLFW config files")
set(GLFW_VERSION "3.3.4")
ExternalProject_Add(
    GLFW
    URL "https://github.com/glfw/glfw/archive/${GLFW_VERSION}.tar.gz"
    PREFIX "${CMAKE_BINARY_DIR}/glfw/lib/cmake/glfw3"
    INSTALL_DIR "${CMAKE_BINARY_DIR}/glfw"
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}/glfw
    CONFIGURE_HANDLED_BY_BUILD 1
)

# Find the GLFW package
find_package(glfw3 REQUIRED)
# Configure the ExternalProject to download and build GLM
set(CMAKE_PREFIX_PATH "${CMAKE_BINARY_DIR}/glm/share/glm/glm" CACHE PATH "Path to GLM config files")
set(GLM_VERSION "1.0.1")
ExternalProject_Add(
    GLM
    URL "https://github.com/g-truc/glm/archive/${GLM_VERSION}.tar.gz"
    PREFIX "${CMAKE_BINARY_DIR}/glm"
    INSTALL_DIR "${CMAKE_BINARY_DIR}/glm"
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}/glm
    CONFIGURE_HANDLED_BY_BUILD 1
)
# find_package(glm REQUIRED)
include_directories("${CMAKE_BINARY_DIR}/glm/include")

# Require GLAD from dependencies/glad
include_directories("${CMAKE_SOURCE_DIR}/dependencies/GLAD/include")

# # Add your executable and link against GLFW
add_executable(GRAPHICS_OPENGL src/main.cpp)
target_link_libraries(GRAPHICS_OPENGL PRIVATE glfw)

