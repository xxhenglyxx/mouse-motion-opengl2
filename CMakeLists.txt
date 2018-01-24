
cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

project(mouse-motion)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(OpenGL)
find_package(GLUT)

find_library(COCOA Cocoa)

include_directories(
    include
    ${GLUT_INCLUDE_DIR}
    ${OPENGL_INCLUDE_DIR}
)

add_executable(
    mouse-motion
    src/main.cpp
    src/modules.cpp
    src/glut_torus.cpp
)

target_link_libraries(
    mouse-motion
    ${COCOA_LIBRARIES}
    ${OPENGL_LIBRARIES}
    ${GLUT_LIBRARIES}
)