cmake_minimum_required(VERSION 3.12)
project(STLViewer)

set(CMAKE_CXX_STANDARD 17)
link_libraries(${GLFW_LIBRARY_DIRS})
set(CMAKE_CXX_FLAGS "-O2 -lglfw -lGLEW -framework OpenGL -framework CoreVideo -framework IOKit -framework Cocoa")

add_executable(STLViewer main.cpp obj_model.cpp obj_model.h loader.cpp loader.h)