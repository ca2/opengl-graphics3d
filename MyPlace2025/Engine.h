#pragma once

#include <memory>
#include <vector>
#include "Core/Window.h"
#include "Core/Input.h"
#include "Renderer/Renderer.h"
#include "Renderer/Types/Mesh.hpp"
#include "Shader/Shader.h"
#include "Core/Camera.h" // Include the Camera header
#include "Game/Game.h"


class Engine {
public:
	Engine();
	~Engine();

	void Init();

	void Run();

private:
	void ProcessInput(float deltaTime);
	static void MouseCallback(GLFWwindow* window, double xpos, double ypos);


	Window m_Window;
	Renderer m_Renderer;
	Camera m_Camera;
	
	
	bool m_Running;

	bool m_WireframeMode = false;
	
	Game m_Game;  // Game object that manages the scenes

	// Variables for mouse handling
	bool m_FirstMouse = true;
	float m_LastX = 0.0f;
	float m_LastY = 0.0f;
	
};
