#include "Application.h"
#include "Time.h"
#include "../Engine/Window.h"
#include "../Rendering/Renderer.h"
#include "../Gameplay/TurnSystem.h"
#include "../World/Grid.h"

#include <glm/gtc/matrix_transform.hpp>
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
    m_Grid = std::make_unique<Grid>(10, 10);

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

        // Cap frame time to prevent getting stuck in the same frame if the game lags
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

   
    Vector3 forward = normalize(camera.target - camera.camera_position);
    forward.y = 0; // Keep movement in the horizontal plane
    Vector3 right = normalize(cross(forward, camera.up));
    //Move camera with WASD
    
    float dt = Time::GetDeltaTime();
    float panSpeed = 10.0f*dt;

    Vector3 pan = {0, 0, 0};
    if (m_Window->IsKeyDown(GLFW_KEY_W)) pan += forward * panSpeed;
    if (m_Window->IsKeyDown(GLFW_KEY_A)) pan -= right * panSpeed;
    if (m_Window->IsKeyDown(GLFW_KEY_S)) pan -= forward * panSpeed;
    if (m_Window->IsKeyDown(GLFW_KEY_D)) pan += right * panSpeed;
    
    camera.target += pan;

    //Rotate camera with mouse
    
    if(m_Window->IsMouseButtonDown(GLFW_MOUSE_BUTTON_MIDDLE)){
        float rotateSpeed = 0.005f;
        camera.horizontal_rotation -= m_Window->GetMouseDX() * rotateSpeed;
        camera.vertical_angle += m_Window->GetMouseDY() * rotateSpeed;

        camera.vertical_angle = std::clamp(camera.vertical_angle, 0.2618f, 1.3962f);
    }
    //ZOOM

    float zoomSpeed = 2.0f;

    camera.distance_from_target -= m_Window->GetScrollDelta()*zoomSpeed;
    camera.distance_from_target = std::clamp(camera.distance_from_target,0.0f,10.0f);

    camera.Update();

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

    glm::mat4 projection = glm::perspective(glm::radians(45.0f),
        (float)m_Window->GetWidth() / m_Window->GetHeight(), 0.1f, 100.0f);
    glm::mat4 view = camera.GetViewMatrix();

    
    m_Renderer->SetProjectionMatrix(projection);
    m_Renderer->SetViewMatrix(view);

    // Render grid with its model matrix
    if (m_Grid) {
        m_Grid->Draw(*m_Renderer);
    }
    
    // Render game objects here...
    if (m_TurnSystem) {
        m_TurnSystem->Render(m_Renderer.get());
    }
    
    // End rendering and present
    m_Renderer->EndFrame();
    m_Window->SwapBuffers();
}
