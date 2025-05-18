#pragma once
#include "Types/Mesh.h"
#include "Shader/shader.h"
//#include "GLFW/glfw3.h"
#include <memory>
#include <glm/glm.hpp>

namespace glc
{

   class Renderer :
      virtual public ::particle
   {
   public:
      Renderer();
      ~Renderer();

      void Clear() const;

      // Draws the skybox using the given mesh and shader
      void DrawSkybox(const Mesh *pskyboxMesh, const Shader * pshader) const;

      void DrawInstanced(const std::vector<Mesh*>& meshes, const Shader *pshader, unsigned int instanceCount) const;
      void MultiDrawIndirectCommand() {}

      void DrawModel(const std::vector<Mesh*>& mehses, const Shader *pshader);


   private:
      int instanceCount = 0;
   };



} // namespace glc



