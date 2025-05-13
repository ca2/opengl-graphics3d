
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Engine.h"
#include "Core/Window.h"
#include "Core/Input.h"
#include "Renderer/Renderer.h"
#include "Renderer/Types/Mesh.hpp"
#include "Shader/Shader.h"
#include <iostream>
#include "Core/Camera.h"
#include "Game/Game.h"

// Acting weird flag = :   ------------------- **


Engine::Engine()
    : m_Running(true),
    m_Window("My Universe", 1100, 600),
    m_Camera(glm::vec3(0.0f, 3.0f, 3.0f), -90.0f, 0.0f)
{
    // Set the window for input management
    Input::SetGLFWWindow(m_Window.GetGLFWWindow());

    // Set up mouse callback and user pointer
    glfwSetWindowUserPointer(m_Window.GetGLFWWindow(), this);
    glfwSetCursorPosCallback(m_Window.GetGLFWWindow(), MouseCallback);
    glfwSetInputMode(m_Window.GetGLFWWindow(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);  // Hide cursor

  
    // Initialize the game logic and scene data
    m_Game.Init();
}

void Engine::Init() {

}

// Destroy Game
Engine::~Engine()
{
}


// Engine Run
void Engine::Run() {


    float lastFrame = 0.0f;

    // Main loop
    while (m_Running && !m_Window.ShouldClose()) {
        // Frame Logic
        float currentFrame = glfwGetTime();
        float deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        ProcessInput(deltaTime);

        // Toggle wireframe mode
        if (m_WireframeMode) {
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // Enable wireframe mode
        }
        else {
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // Enable solid mode
        }

        // Clear the screen
        m_Renderer.Clear();

        // Update and render the game (and the current scene)
        m_Game.Update(deltaTime, m_Camera);
        m_Game.Render(m_Renderer, m_Camera);
       
        // Swap buffers and poll for events
        m_Window.SwapBuffers();
        m_Window.PollEvents();
    }
}

// Keyboard event listeners
void Engine::ProcessInput(float deltaTime) {
    if (Input::IsKeyPressed(GLFW_KEY_W)) {
        m_Camera.ProcessKeyboardInput(FORWARD, deltaTime);
        if (Input::IsKeyPressed(GLFW_KEY_LEFT_SHIFT))
            m_Camera.TeleportInDirection(FORWARD);
    }
    if (Input::IsKeyPressed(GLFW_KEY_S)) {
        m_Camera.ProcessKeyboardInput(BACKWARD, deltaTime);
        if (Input::IsKeyPressed(GLFW_KEY_LEFT_SHIFT))
            m_Camera.TeleportInDirection(BACKWARD);
    }
    if (Input::IsKeyPressed(GLFW_KEY_A)) {
        m_Camera.ProcessKeyboardInput(LEFT, deltaTime);
        if (Input::IsKeyPressed(GLFW_KEY_LEFT_SHIFT))
            m_Camera.TeleportInDirection(LEFT);
    }
    if (Input::IsKeyPressed(GLFW_KEY_D)) {
        m_Camera.ProcessKeyboardInput(RIGHT, deltaTime);
        if (Input::IsKeyPressed(GLFW_KEY_LEFT_SHIFT))
            m_Camera.TeleportInDirection(RIGHT);
    }

    if (Input::IsKeyPressed(GLFW_KEY_ESCAPE))
        m_Running = false;
    if (Input::IsKeyPressed(GLFW_KEY_4))
        m_WireframeMode = !m_WireframeMode;
    // Check for jump (Space key)
    if (Input::IsKeyPressed(GLFW_KEY_SPACE)) {
        float jumpHeight = 0.20f;  // Define how high the jump should be
        m_Camera.Jump(jumpHeight);
    }
    // Teleport down (Left Control key)
    if (Input::IsKeyPressed(GLFW_KEY_LEFT_CONTROL)) {
        float teleportDistance = 0.1081f;  // Define the downward distance
        m_Camera.TeleportDownward(teleportDistance);
    }

    // Idle movement
    if (!Input::IsAnyKeyPressed()) { // You might want to implement IsAnyKeyPressed to check for movement keys
       // m_Camera.UpdateIdleMovement(deltaTime);
    }


}


// Mouse event listeners
void Engine::MouseCallback(GLFWwindow* window, double xpos, double ypos) {
    Engine* engine = static_cast<Engine*>(glfwGetWindowUserPointer(window));

    if (engine->m_FirstMouse) {
        engine->m_LastX = static_cast<float>(xpos);
        engine->m_LastY = static_cast<float>(ypos);
        engine->m_FirstMouse = false;
    }

    float xoffset = static_cast<float>(xpos) - engine->m_LastX;
    float yoffset = engine->m_LastY - static_cast<float>(ypos);  // Y-coordinates go from bottom to top
    engine->m_LastX = static_cast<float>(xpos);
    engine->m_LastY = static_cast<float>(ypos);

    engine->m_Camera.ProcessMouseMovement(xoffset, yoffset);
}


void Camera::scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
    m_Zoom -= (float)yoffset;
    if (m_Zoom < 1.0f)
        m_Zoom = 1.0f;
    if (m_Zoom > 45.0f)
        m_Zoom = 45.0f;
}

