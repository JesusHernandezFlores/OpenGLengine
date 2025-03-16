cmake_minimum_required(VERSION 3.30)

project(OpenGLengine)

add_executable(OpenGLengine src/main.cpp)

if(LINUX)
    find_package(OpenGL REQUIRED)
    include_directories(${CMAKE_SOURCE_DIR}/3rdParty/Linux/include/)
    target_link_libraries(OpenGLengine ${CMAKE_SOURCE_DIR}/3rdParty/Linux/lib/libGLEW.a)
    target_link_libraries(OpenGLengine ${CMAKE_SOURCE_DIR}/3rdParty/Linux/lib/libglfw3.a)
    target_link_libraries(OpenGLengine OpenGL::GL)
endif(LINUX)

if(WIN32)

endif(WIN32)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

