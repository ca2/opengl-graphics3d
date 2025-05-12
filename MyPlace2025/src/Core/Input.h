#pragma once

#include "GLFW/glfw3.h"
#include <unordered_map>

class Input {
public:
    static bool IsKeyPressed(int key);
    static bool IsKeyReleased(int key); // New method for released keys
    static void SetGLFWWindow(GLFWwindow* window);
    static void ToggleFullscreen();  // Fullscreen toggle logic
    static void Update(); // Update key states each frame
    static bool IsAnyKeyPressed(); // New method to check if any keys are pressed
private:
    static GLFWwindow* m_Window;
    static bool m_IsFullscreen;

    static bool m_KeyWasPressed(int key); // Helper to check if key was pressed once
    static std::unordered_map<int, bool> m_KeyPressed; // Store the state of each key
    static int m_WindowedWidth, m_WindowedHeight;
    static int m_WindowedPosX, m_WindowedPosY;
};

 
