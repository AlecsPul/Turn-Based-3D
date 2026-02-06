#pragma once

class Window;

class Renderer {
public:
    Renderer() = default;
    ~Renderer() = default;

    bool Initialize(Window* window) {
        m_Window = window;
        // TODO: Initialize graphics API (OpenGL, Vulkan, DirectX, etc.)
        return true;
    }

    void BeginFrame() {
        // TODO: Begin rendering frame
    }

    void EndFrame() {
        // TODO: End rendering frame
    }

    void Clear(float r, float g, float b, float a) {
        // TODO: Clear screen with color
    }

private:
    Window* m_Window = nullptr;
};
