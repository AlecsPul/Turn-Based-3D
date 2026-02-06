#pragma once

#include <string>

class Window {
public:
    Window(const std::string& title, int width, int height)
        : m_Title(title), m_Width(width), m_Height(height), m_IsValid(true), m_IsOpen(true) {
    }

    bool IsValid() const { return m_IsValid; }
    bool IsOpen() const { return m_IsOpen; }
    bool ShouldClose() const { return !m_IsOpen; }

    void PollEvents() {
        // TODO: Implement actual event polling (GLFW, SDL, etc.)
    }

    void SwapBuffers() {
        // TODO: Implement buffer swapping
    }

    int GetWidth() const { return m_Width; }
    int GetHeight() const { return m_Height; }

private:
    std::string m_Title;
    int m_Width;
    int m_Height;
    bool m_IsValid;
    bool m_IsOpen;
};
