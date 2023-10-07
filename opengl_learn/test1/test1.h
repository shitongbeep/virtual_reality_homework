#pragma once

#include "glad/glad.h"
#include "GLFW/glfw3.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);
void input_vertex(float* const vertices, int32_t vertices_size, uint32_t* const VBO);
bool create_vertex_shader(const char* const vertex_shader_src, uint32_t* const vertex_shader);
bool create_fragment_shader(const char* const fragment_shader_src, uint32_t* const fragment_shader);
bool create_shader_program(const char* const vertex_shader_src, const char* const fragment_shader_src,
                           uint32_t* const shader_program);