#pragma once

#include <glad.h>
#include <string>
#include <vector>


namespace glc
{

   class Skybox :
   virtual public ::particle 
   
   {
   public:
      Skybox(const std::vector<std::string>& faces);
      ~Skybox();

      void SetupSkybox();


   private:
      unsigned int skyboxVAO, skyboxVBO, skyboxEBO;
      unsigned int cubemapTexture;
      std::vector<std::string> facesCubemap;

      void LoadCubemapTextures();
   };



} // namespace glc



