#pragma once
#include "../utils.h"
#include <memory>
#include "../Engine/Camera.h"
#include <algorithm>

// Forward declarations
class Window;
class Renderer;
class TurnSystem;

class Application {
public:
    Application();
    ~Application();

    // Main entry point - runs the application
    void Run();

    // Prevent copying
    Application(const Application&) = delete;
    Application& operator=(const Application&) = delete;

private:
    // Initialization
    bool Initialize();
    void Shutdown();
    Camera camera;
    // Game loop components
    void ProcessInput();
    void Update(float deltaTime);
    void Render();

    // Core systems
    std::unique_ptr<Window> m_Window;
    std::unique_ptr<Renderer> m_Renderer;
    std::unique_ptr<TurnSystem> m_TurnSystem;

    // Loop control
    bool m_Running;
    
    // Fixed timestep settings (60 updates per second)
    const float m_FixedTimestep = 1.0f / 60.0f;
};
