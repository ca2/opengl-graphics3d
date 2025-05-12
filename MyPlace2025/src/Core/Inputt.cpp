#include "Input.h"

// Initialize static members
GLFWwindow* Input::m_Window = nullptr;
bool Input::m_IsFullscreen = false;
int Input::m_WindowedWidth = 1280;
int Input::m_WindowedHeight = 720;
int Input::m_WindowedPosX = 100;
int Input::m_WindowedPosY = 100;
std::unordered_map<int, bool> Input::m_KeyPressed;

bool Input::IsKeyPressed(int key) {
    int state = glfwGetKey(m_Window, key);
    return state == GLFW_PRESS || state == GLFW_REPEAT;
}

bool Input::IsKeyReleased(int key) {
    return glfwGetKey(m_Window, key) == GLFW_RELEASE;
}

void Input::SetGLFWWindow(GLFWwindow* window) {
    m_Window = window;
}

// Fullscreen toggle logic
void Input::ToggleFullscreen() {
    if (m_IsFullscreen) {
        // Exit fullscreen, go back to windowed mode
        glfwSetWindowMonitor(m_Window, nullptr, m_WindowedPosX, m_WindowedPosY,
            m_WindowedWidth, m_WindowedHeight, 0);
    }
    else {
        // Enter fullscreen mode
        GLFWmonitor* monitor = glfwGetPrimaryMonitor();
        const GLFWvidmode* mode = glfwGetVideoMode(monitor);

        // Save current window position and size
        glfwGetWindowPos(m_Window, &m_WindowedPosX, &m_WindowedPosY);
        glfwGetWindowSize(m_Window, &m_WindowedWidth, &m_WindowedHeight);

        glfwSetWindowMonitor(m_Window, monitor, 0, 0, mode->width, mode->height, mode->refreshRate);
    }
    m_IsFullscreen = !m_IsFullscreen;  // Toggle the state
}

// Check if any movement keys are pressed (W, A, S, D)
bool Input::IsAnyKeyPressed() {
    return IsKeyPressed(GLFW_KEY_W) ||
        IsKeyPressed(GLFW_KEY_A) ||
        IsKeyPressed(GLFW_KEY_S) ||
        IsKeyPressed(GLFW_KEY_D);
}
// Update the state of keys every frame
void Input::Update() {
    for (auto& [key, wasPressed] : m_KeyPressed) {
        int state = glfwGetKey(m_Window, key);
        if (state == GLFW_PRESS) {
            if (!wasPressed) {
                m_KeyPressed[key] = true;
            }
        }
        else if (state == GLFW_RELEASE) {
            m_KeyPressed[key] = false;
        }
    }
}

bool Input::m_KeyWasPressed(int key) {
    if (IsKeyPressed(key)) {
        if (!m_KeyPressed[key]) {
            m_KeyPressed[key] = true;
            return true;  // Only return true once when key is initially pressed
        }
    }
    else {
        m_KeyPressed[key] = false;
    }
    return false;
}
