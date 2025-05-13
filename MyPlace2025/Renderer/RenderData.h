#pragma once

#include <string>
#include <memory>
#include <glm/glm.hpp>
#include "Renderer/Renderer.h"
#include "Shader/Shader.h"
#include "Renderer/Types/Mesh.hpp"
#include "Core/Camera.h"
#include "Renderer/Types/Texture.h"


namespace glc
{

   class Renderer;
   class Shader;
   class Mesh;
   class Camera;
   class Skybox;

   class RenderData :
      virtual public ::particle
   {
   public:
      RenderData();
      ~RenderData();



      struct DrawIndexedIndirectCommand {
         GLuint indexCount;    // Number of indices to draw
         GLuint instanceCount; // Number of instances
         GLuint firstIndex;    // Starting index in index buffer
         GLuint baseVertex;    // Base vertex offset
         GLuint baseInstance;  // Instance offset
      };

      void Init();
      void Update(float deltaTime);
      void Render(Renderer& renderer, Camera& camera);
      void LoadModel(std::string& path);
      // Misc


   private:
      // Shaders
      ::pointer<Shader> m_Shader;
      ::pointer<Shader> m_LightingShader;
      ::pointer<Shader> m_LightSourceShader;
      ::pointer<Shader> m_SkyboxShader;
      ::pointer<Shader> m_WallShader;

      // Textures
      ::pointer<Texture> m_PlaneTexture;
      ::pointer<Texture> m_BoxTexture;
      ::pointer<Texture> m_Specular;
      ::pointer<Texture> m_SphereTexture;
      ::pointer<Texture> m_Misc;

      // Meshes
      ::pointer<Mesh> m_BoxMesh;
      ::pointer<Mesh> m_PlaneMesh;
      ::pointer<Mesh> m_SkyboxMesh;
      ::pointer<Mesh> m_SphereMesh;
      ::pointer<Mesh> m_WallMesh;

      // Models
      std::vector<::pointer<Mesh>> m_Meshes;

      //Instances
      int m_PlaneInstanceCount = 1;
      int m_BoxInstanceCount = 200;
      int m_SphereInstanceCount = 400;
      int m_WallInstanceCount = 1000;


      // Misc
      std::vector<glm::mat4> boxModelMatrices; // Declare as a member variable
      std::vector<glm::mat4> wallModelMatrices;
      std::vector<glm::vec3> wallPositions;




      float rotationSpeed = 60.0f; // Degrees per second


      float scaleFactorX = 20.0f;
      float scaleFactorY = 20.0f;
      float scaleFactorZ = 20.0f;

      ::pointer<Skybox> m_Skybox;


   };





} //  namespace glc





