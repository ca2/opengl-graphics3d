#pragma once
#include "Renderer/RenderData.h"
#include <memory>


namespace glc
{

   class Application :
      virtual public ::particle
   {
   public:


      ::pointer<RenderData> currentScene;

      Application();
      ~Application();

      void Init();       // Initialize the game and load the first scene
      void Update(float deltaTime, Camera& camera);  // Update game logic
      void Render(Renderer& renderer, Camera& camera);

   //private:
   //   ::pointer<RenderData> currentScene;
   };


} // namespace glc


