#include "Game.h"
#include "RenderData.h"

Game::Game() : currentScene(nullptr) {}

Game::~Game() {}

void Game::Init() {
    // Create and initialize the first scene  *** EVENTUALLY ADD ACTUAL SCENE CLASS TO MANAGE MULTIPLE UNIQUE RENDER DATA IE SCENE DATA
    currentScene = std::make_unique<RenderData>();
    currentScene->Init();  // Initialize scene-specific assets like shaders, meshes, etc.
}
void Game::Update(float deltaTime, Camera& camera) {
    if (currentScene) {
        glm::vec3 cameraPosition = camera.GetPosition(); // Get the camera's current position
        currentScene->Update(deltaTime); // Pass both delta time and camera position
    }
}

void Game::Render(Renderer& renderer, Camera& camera) {
    if (currentScene) {
        currentScene->Render(renderer, camera);  // Call the scene's render function
    }
}

