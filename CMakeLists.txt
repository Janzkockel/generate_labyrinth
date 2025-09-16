cmake_minimum_required(VERSION 3.22.1)
project(labirynth_generator)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
include_directories(usr/include/)

find_package(OpenGL REQUIRED )

add_executable(${PROJECT_NAME} 
        src/main.cpp
        libraries/rightHandRule.cpp
        )
add_executable(testing_algorithms
        src/testing_algorithms.cpp
        libraries/rightHandRule.cpp
        )

# if(OPENGL_LIBRARY)
target_link_libraries( ${PROJECT_NAME} ${OPENGL_LIBRARIES} glfw)
# endif()
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/libraries/)
target_include_directories(testing_algorithms PRIVATE ${CMAKE_SOURCE_DIR}/libraries/)