cmake_minimum_required(VERSION 3.22.1)
project(labirynth_generator)
set(CMAKE_C_STANDARD 11)
include_directories(usr/include/)

find_package(OpenGL REQUIRED )

add_executable(${PROJECT_NAME} src/main.cpp)

# if(OPENGL_LIBRARY)
target_link_libraries( ${PROJECT_NAME} ${OPENGL_LIBRARIES} glfw)
# endif()