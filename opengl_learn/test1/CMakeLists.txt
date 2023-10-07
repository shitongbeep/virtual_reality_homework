cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD_REQUIRED 17)

project(test)

find_package(glfw3 REQUIRED)
set(OpenGL_GL_PREFERENCE LEGACY)
find_package(OpenGL REQUIRED)

include_directories(${OPENGL_INCLUDE_DIRS})
message(OPENGL_INCLUDE_DIRS: ${OPENGL_INCLUDE_DIRS})

list(APPEND src basic.cc glad.c test1.cc)
add_executable(${PROJECT_NAME} ${src})
target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} glfw)