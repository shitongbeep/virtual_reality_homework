#include "test1.h"

#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
  glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window) {
  if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
    glfwSetWindowShouldClose(window, true);
}

void input_vertex(float* const vertices, int32_t vertices_size, uint32_t* const VBO) {
  glGenBuffers(1, VBO);                                                    // create buffer id
  glBindBuffer(GL_ARRAY_BUFFER, *VBO);                                     // bind id to buffer type
  glBufferData(GL_ARRAY_BUFFER, vertices_size, vertices, GL_STATIC_DRAW);  // move to gpu
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);
}

bool create_vertex_shader(const char* const vertex_shader_src, uint32_t* const vertex_shader) {
  *vertex_shader = glCreateShader(GL_VERTEX_SHADER);            // create vertex shader id
  glShaderSource(*vertex_shader, 1, &vertex_shader_src, NULL);  // bind shader src
  glCompileShader(*vertex_shader);                              // compile shader
  // check complie success
  int success;
  char infoLog[512];
  glGetShaderiv(*vertex_shader, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(*vertex_shader, 512, NULL, infoLog);
    std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n"
              << infoLog << std::endl;
  }
  return success;
}

bool create_fragment_shader(const char* const fragment_shader_src, uint32_t* const fragment_shader) {
  *fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(*fragment_shader, 1, &fragment_shader_src, NULL);
  glCompileShader(*fragment_shader);
  // check complie success
  int success;
  char infoLog[512];
  glGetShaderiv(*fragment_shader, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(*fragment_shader, 512, NULL, infoLog);
    std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n"
              << infoLog << std::endl;
  }
  return success;
}

bool create_shader_program(const char* const vertex_shader_src, const char* const fragment_shader_src,
                           uint32_t* const shader_program) {
  *shader_program = glCreateProgram();
  uint32_t vertex_shader;
  uint32_t fragment_shader;
  create_vertex_shader(vertex_shader_src, &vertex_shader);
  create_fragment_shader(fragment_shader_src, &fragment_shader);
  glAttachShader(*shader_program, vertex_shader);
  glAttachShader(*shader_program, fragment_shader);
  glLinkProgram(*shader_program);  // link shader program
  // check link success
  int success;
  char infoLog[512];
  glGetProgramiv(*shader_program, GL_LINK_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(*shader_program, 512, NULL, infoLog);
    std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n"
              << infoLog << std::endl;
    return success;
  }
  glUseProgram(*shader_program);  // activate program
  glDeleteShader(vertex_shader);
  glDeleteShader(fragment_shader);
  return success;
}
