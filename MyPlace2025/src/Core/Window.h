#pragma once

#include <GLFW/glfw3.h>

class Window {
public:
    Window(const char* title, int width, int height);
    ~Window();

    bool ShouldClose() const;
    void SwapBuffers() const;
    void PollEvents() const;

    GLFWwindow* GetGLFWWindow() const { return m_Window; }

private:
    GLFWwindow* m_Window;
    int m_Width, m_Height;
};

