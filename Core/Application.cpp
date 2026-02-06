#include "Application.h"
#include "Time.h"
#include "../Engine/Window.h"
#include "../Rendering/Renderer.h"
#include "../Gameplay/TurnSystem.h"

#include <iostream>
#include <thread>

Application::Application()
    : m_Running(false) {
}

Application::~Application() {
    Shutdown();
}

bool Application::Initialize() {
    std::cout << "Initializing Application...\n";

    // Create window
    m_Window = std::make_unique<Window>("Turn-Based 3D Game", 1280, 720);
    if (!m_Window->IsValid()) {
        std::cerr << "Failed to create window!\n";
        return false;
    }

    // Create renderer
    m_Renderer = std::make_unique<Renderer>();
    if (!m_Renderer->Initialize(m_Window.get())) {
        std::cerr << "Failed to initialize renderer!\n";
        return false;
    }

    // Create game systems
    m_TurnSystem = std::make_unique<TurnSystem>();

    std::cout << "Application initialized successfully!\n";
    return true;
}

void Application::Shutdown() {
    std::cout << "Shutting down Application...\n";
    
    m_TurnSystem.reset();
    m_Renderer.reset();
    m_Window.reset();
}

void Application::Run() {
    if (!Initialize()) {
        return;
    }

    m_Running = true;
    Time::Reset();

    float accumulator = 0.0f;

    std::cout << "Entering main loop...\n";

    // Main game loop with fixed timestep
    while (m_Running && m_Window->IsOpen()) {
        Time::Update();
        float frameTime = Time::GetDeltaTime();

        // Cap frame time to prevent spiral of death
        if (frameTime > 0.25f) {
            frameTime = 0.25f;
        }

        accumulator += frameTime;

        // Process input (once per frame)
        ProcessInput();

        // Fixed timestep update loop
        while (accumulator >= m_FixedTimestep) {
            Update(m_FixedTimestep);
            accumulator -= m_FixedTimestep;
        }

        // Render (decoupled from gameplay logic)
        Render();

        // Small sleep to prevent CPU spinning at 100%
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }

    std::cout << "Exiting main loop...\n";
}

void Application::ProcessInput() {
    // Poll window events
    m_Window->PollEvents();

    // Check for window close
    if (m_Window->ShouldClose()) {
        m_Running = false;
    }

    // Additional input handling could go here
}

void Application::Update(float deltaTime) {
    // Update game systems with fixed timestep
    if (m_TurnSystem) {
        m_TurnSystem->Update(deltaTime);
    }

    // Update other gameplay systems here...
}

void Application::Render() {
    // Begin rendering
    m_Renderer->BeginFrame();

    // Render game world
    m_Renderer->Clear(0.1f, 0.1f, 0.15f, 1.0f);

    // Render game objects here...
    if (m_TurnSystem) {
        m_TurnSystem->Render(m_Renderer.get());
    }

    // End rendering and present
    m_Renderer->EndFrame();
    m_Window->SwapBuffers();
}
