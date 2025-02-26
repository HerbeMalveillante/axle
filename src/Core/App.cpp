#define GLFW_INCLUDE_NONE

#include "Core/App.h"
#include "Core/Errors.h"
#include "GLFW/glfw3.h"
#include "glad/glad.h"
#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

namespace Axle::Core {

// Static variables definition
unsigned int App::height = 600;
unsigned int App::width = 800;
std::string App::title = "Axle Engine";
bool App::isReady = false;

unsigned int App::minWidth = GLFW_DONT_CARE;
unsigned int App::minHeight = GLFW_DONT_CARE;
unsigned int App::maxWidth = GLFW_DONT_CARE;
unsigned int App::maxHeight = GLFW_DONT_CARE;
bool App::resizable = false;

GLFWwindow *App::window = nullptr;

void App::ThrowErrorIfUninitialized() {
  if (!App::isReady) {
    throw AppNotInitializedError();
  }
}
void App::FramebufferSizeCallback(GLFWwindow *window, int width, int height) {
  App::ThrowErrorIfUninitialized();
  App::width = width;
  App::height = height;
  glViewport(0, 0, width, height);
}

void App::ProcessInput() {
  App::ThrowErrorIfUninitialized();
  if (glfwGetKey(App::window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
    glfwSetWindowShouldClose(App::window, true);
  }
}

void App::Init(unsigned int width, unsigned int height, std::string title) {

  App::width = width;
  App::height = height;
  App::title = title;
  App::resizable = false;

  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  // Window creation
  App::window = glfwCreateWindow(App::width, App::height, App::title.c_str(),
                                 nullptr, nullptr);
  if (App::window == nullptr) {
    std::cout << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
    return;
  }
  glfwMakeContextCurrent(App::window);

  // GLAD initialization
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cout << "Failed to initialize GLAD" << std::endl;
    return;
  }

  // Set up the callback function for when the window is resized
  glfwSetFramebufferSizeCallback(App::window, App::FramebufferSizeCallback);

  // Print the renderer
  std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;
  // Print the openGL and GLSL versions
  std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;
  std::cout << "GLSL version: " << glGetString(GL_SHADING_LANGUAGE_VERSION)
            << std::endl;

  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  App::isReady = true;
}

void App::Clear(const Color clearColor) {
  glClearColor(clearColor.getRf(), clearColor.getGf(), clearColor.getBf(),
               clearColor.getAf());
  glClear(GL_COLOR_BUFFER_BIT);
}

bool App::ShouldClose() {
  App::ThrowErrorIfUninitialized();
  return glfwWindowShouldClose(App::window);
}

void App::SwapBuffers() {
  App::ThrowErrorIfUninitialized();
  glfwSwapBuffers(App::window);
}

void App::PollEvents() {
  App::ThrowErrorIfUninitialized();
  glfwPollEvents();
}

void App::Exit() {
  App::ThrowErrorIfUninitialized();
  glfwTerminate();
}

void App::SetWindowResizable(bool resizable) {
  App::ThrowErrorIfUninitialized();
  App::resizable = resizable;
  if (resizable) {
    glfwSetWindowAttrib(App::window, GLFW_RESIZABLE, GLFW_TRUE);
  } else {
    glfwSetWindowAttrib(App::window, GLFW_RESIZABLE, GLFW_FALSE);
  }
}

void App::SetWindowMinSize(unsigned int width, unsigned int height) {
  App::ThrowErrorIfUninitialized();

  App::minWidth = width;
  App::minHeight = height;
  glfwSetWindowSizeLimits(App::window, App::minWidth, App::minHeight,
                          App::maxWidth, App::maxHeight);
}
void App::SetWindowMaxSize(unsigned int width, unsigned int height) {
  App::ThrowErrorIfUninitialized();

  App::maxWidth = width;
  App::maxHeight = height;
  glfwSetWindowSizeLimits(App::window, App::minWidth, App::minHeight,
                          App::maxWidth, App::maxHeight);
}

unsigned int App::GetWindowWidth() {
  App::ThrowErrorIfUninitialized();
  return App::width;
}
unsigned int App::GetWindowHeight() {
  App::ThrowErrorIfUninitialized();
  return App::height;
}

} // namespace Axle::Core
