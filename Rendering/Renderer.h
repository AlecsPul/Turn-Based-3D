#pragma once
#include <glm/mat4x4.hpp>
#include "Mesh.h"
#include "Shader.h"
#include "../Engine/Window.h"

class Window;

class Renderer {
public:
    Renderer() = default;
    ~Renderer() = default;
    void SetViewMatrix(const glm::mat4& view);
    void SetProjectionMatrix(const glm::mat4& projection);

    bool Initialize(Window* window);

    void BeginFrame();
    void EndFrame();

    void Clear(float r, float g, float b, float a);

    void DrawMesh(const Mesh& mesh, const Shader& shader);


private:
    Window* m_Window = nullptr;
    glm::mat4 m_View;
    glm::mat4 m_Projection;
    glm::mat4 m_ProjectionMatrix;
    glm::mat4 m_ViewMatrix;
};
