#pragma once
#include <GLFW/glfw3.h>
#include <string>
#include "../utils.h"

struct MouseState{
    double x = 0;
    double y = 0;
    double deltaX = 0;
    double deltaY = 0;
    double scroll = 0;
};


class Window {
public:
    
    bool m_Keys[512] = {};
    MouseState mouse;
    
    Window(const std::string& title, int width, int height)
        : m_Title(title), m_Width(width), m_Height(height), m_IsValid(true), m_IsOpen(true) {
    }

    bool IsValid() const { return m_IsValid; }
    bool IsOpen() const { return m_IsOpen; }
    bool ShouldClose() const { return !m_IsOpen; }

    void PollEvents();
    void SwapBuffers();

    int GetWidth() const { return m_Width; }
    int GetHeight() const { return m_Height; }
    bool IsKeyDown(int key) const { return m_Keys[key]; }
    double GetMouseDX() const { return mouse.deltaX; }
    double GetMouseDY() const { return mouse.deltaY; }
    double GetScrollDelta() const { return mouse.scroll; }


private:
   
    std::string m_Title;
    int m_Width;
    int m_Height;
    bool m_IsValid;
    bool m_IsOpen;
    GLFWwindow* m_WindowHandle = nullptr; // Placeholder for actual window handle (e.g., GLFWwindow*) 
};

