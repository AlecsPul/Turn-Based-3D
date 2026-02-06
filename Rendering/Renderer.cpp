#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "../Engine/Window.h"
#include "Renderer.h"

bool Renderer::Initialize(Window* window)  {
        m_Window = window;
        if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
            std::cerr << "Failed to initialize OpenGL\n";
            return false;
        }
        std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << std::endl;

        glEnable(GL_DEPTH_TEST);
        return true;
    }

void Renderer::BeginFrame() {
    // nothing yet
}

void Renderer::Clear(float r, float g, float b, float a) {
    glClearColor(r, g, b, a);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::EndFrame() {
    // nothing yet
}
