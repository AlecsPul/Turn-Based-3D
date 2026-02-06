
#include "Window.h"
#include <iostream>


Window::Window(const std::string& title, int width, int height)
    : m_Title(title), m_Width(width), m_Height(height) {
        if(!glfwInit()){
            std::cerr << "Failed to initialize GLFW\n";
            m_IsValid = false;
            return;
        }

        m_WindowHandle = glfwCreateWindow(width,height,title.c_str(),nullptr,nullptr);
        if(!m_WindowHandle){
            std::cerr << "Failed to create window\n";
            glfwTerminate();
            m_IsValid = false;
            return;
        }

        glfwMakeContextCurrent(m_WindowHandle);
        glfwSetWindowUserPointer(m_WindowHandle, this);
        glfwSetKeyCallback(m_WindowHandle, KeyCallback);
        glfwSetCursorPosCallback(m_WindowHandle, CursorPosCallback);
        glfwSetScrollCallback(m_WindowHandle, ScrollCallback);

    }

Window::~Window() {
    if(m_WindowHandle){
        glfwDestroyWindow(m_WindowHandle);
        glfwTerminate();
    }
}

void Window::SwapBuffers(){
    glfwSwapBuffers(m_WindowHandle);

}

void Window::PollEvents(){
    mouse.deltaX = 0;
    mouse.deltaY = 0;
    mouse.scroll = 0; //frame_based movement

    glfwPollEvents();

    if(glfwWindowShouldClose(m_WindowHandle)){
        m_IsOpen = false;
    }
}

static void KeyCallback(GLFWwindow* g_window, int key, int scancode, int action, int mods){
    Window* window = static_cast<Window*>(glfwGetWindowUserPointer(g_window));
    if(!window){
        return;
    }

    if(key >= 0 && key <512){
        window->m_Keys[key] = (action != GLFW_RELEASE); // if key is pressed, m_keys[key] true
    }

}


static void CursorPosCallback(GLFWwindow* g_window, double xpos, double ypos){
    Window* window = static_cast<Window*>(glfwGetWindowUserPointer(g_window));
    if(!window){
        return;
    }

    window->mouse.deltaX = xpos - window->mouse.x;
    window->mouse.deltaY = ypos - window->mouse.y;
    window->mouse.x = xpos;
    window->mouse.y = ypos;

}

static void ScrollCallback(GLFWwindow* g_window, double xoffset, double yoffset){
    Window* window = static_cast<Window*>(glfwGetWindowUserPointer(g_window));
    if(!window){
        return;
    }

    window->mouse.scroll += yoffset;
}