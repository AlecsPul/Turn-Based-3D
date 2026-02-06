#pragma once
#include <glm/mat4x4.hpp>
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

private:
    Window* m_Window = nullptr;
};
