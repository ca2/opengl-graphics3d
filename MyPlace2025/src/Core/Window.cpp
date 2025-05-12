#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "Window.h"
#include <iostream>

Window::Window(const char* title, int width, int height)
    : m_Width(width), m_Height(height) {

    // Initialize GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW!" << std::endl;
        exit(EXIT_FAILURE);
    }

    // Set GLFW options (version, profile, etc.)
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, true);

    // Create the GLFW window
    m_Window = glfwCreateWindow(m_Width, m_Height, title, NULL, nullptr);
    if (!m_Window) {
        std::cerr << "Failed to create GLFW window!" << std::endl;
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    std::cout << "Window created successfully!" << std::endl;

    // Make the OpenGL context current
    glfwMakeContextCurrent(m_Window);

    // Load GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        return;
    }

    // Set the viewport (default to full window size)
    glViewport(0, 0, m_Width, m_Height);

    // Enable VSync (optional, for smooth rendering)
    glfwSwapInterval(1);

    // Register resize callback (optional)
    glfwSetFramebufferSizeCallback(m_Window, [](GLFWwindow* window, int width, int height) {
        glViewport(0, 0, width, height);  // Update the OpenGL viewport to new window size
        });

    // Retrieve the OpenGL version
    const GLubyte* version = glGetString(GL_VERSION);
    std::cout << "OpenGL Version: " << version << std::endl;
}

Window::~Window() {
    // Destroy the window and terminate GLFW
    glfwDestroyWindow(m_Window);
    glfwTerminate();
}

bool Window::ShouldClose() const {
    return glfwWindowShouldClose(m_Window);
}

void Window::SwapBuffers() const {
    glfwSwapBuffers(m_Window);
}

void Window::PollEvents() const {
    glfwPollEvents();
}
