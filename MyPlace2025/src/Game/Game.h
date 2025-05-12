#pragma once
#include "RenderData.h"
#include <memory>

class Game {
public:
    Game();
    ~Game();

    void Init();       // Initialize the game and load the first scene
    void Update(float deltaTime, Camera& camera);  // Update game logic
    void Render(Renderer& renderer, Camera& camera);

private:
    std::unique_ptr<RenderData> currentScene;
};