cmake_minimum_required(VERSION 3.27.7)

project(
    engine
    VERSION 1.0
)

find_package(OpenGL REQUIRED)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(engine
    Engine/src/Main.cpp
    Engine/src/MainMenu.cpp
    Engine/src/glad.c
)

target_include_directories(engine
    PRIVATE
        Engine/include
        Engine/Dependencies
)

target_link_libraries(engine
    OpenGL::GL
    glfw
)
