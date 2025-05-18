#pragma once


#include "mesh.h"
#include "shader.h"
//#include "GLFW/glfw3.h"
#include <memory>
#include <glm/glm.hpp>


namespace graphics3d_opengl
{


   class renderer :
      virtual public ::particle
   {
   public:


      renderer();
      ~renderer();

      void Clear() const;

      // Draws the skybox using the given mesh and shader
      void DrawSkybox(const Mesh *pskyboxMesh, const Shader * pshader) const;

      void DrawInstanced(const std::vector<Mesh*>& meshes, const Shader *pshader, unsigned int instanceCount) const;
      void MultiDrawIndirectCommand() {}

      void DrawModel(const std::vector<Mesh*>& mehses, const Shader *pshader);


   private:
      int instanceCount = 0;
   };



} // namespace graphics3d_opengl



