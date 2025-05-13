#include "framework.h"
#include "Application.h"
#include "Renderer/RenderData.h"
#include "Core/Camera.h"


namespace glc
{

   Application::Application() : currentScene(nullptr) {}

   Application::~Application() {}

   void Application::Init() {
      // Create and initialize the first scene  *** EVENTUALLY ADD ACTUAL SCENE CLASS TO MANAGE MULTIPLE UNIQUE RENDER DATA IE SCENE DATA
      currentScene = __create_new<RenderData>();
      currentScene->Init();  // Initialize scene-specific assets like shaders, meshes, etc.
   }
   void Application::Update(float deltaTime, Camera& camera) {
      if (currentScene) {
         glm::vec3 cameraPosition = camera.GetPosition(); // Get the camera's current position
         currentScene->Update(deltaTime); // Pass both delta time and camera position
      }
   }

   void Application::Render(Renderer& renderer, Camera& camera) {
      if (currentScene) {
         currentScene->Render(renderer, camera);  // Call the scene's render function
      }
   }



} // namespace glc


