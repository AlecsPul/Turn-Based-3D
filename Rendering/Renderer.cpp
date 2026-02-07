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

void Renderer::SetProjectionMatrix(const glm::mat4& projection) {
    m_ProjectionMatrix = projection;
}

void Renderer::SetViewMatrix(const glm::mat4& view) {
    m_ViewMatrix = view;
}

void Renderer::DrawMesh(const Mesh& mesh, const Shader& shader, glm::mat4 model_matrix){
    shader.Use();
    shader.SetMat4("uModel", model_matrix);
    shader.SetMat4("uView", m_ViewMatrix);
    shader.SetMat4("uProjection", m_ProjectionMatrix);
    mesh.Draw();
}