cmake_minimum_required(VERSION 3.27.7)

project(
    engine
    VERSION 1.0
)

cmake_policy(SET CMP0072 NEW)

find_package(OpenGL REQUIRED)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(engine
    src/Main.cpp
    src/MainMenu.cpp
    src/glad.c
)

target_include_directories(engine
    PRIVATE
        include
        Dependencies
)

target_link_libraries(engine
    OpenGL::GL
    glfw
)
