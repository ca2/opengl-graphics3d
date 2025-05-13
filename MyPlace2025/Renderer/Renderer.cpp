#include "framework.h"
#include "glad.h"
//#include "GLFW/glfw3.h"
#include <vector>
#include <map>
#include "OpenGL/GLError.h"
#include "Renderer/Renderer.h"
#include "Renderer/Types/Mesh.h"


namespace glc
{


   Renderer::Renderer()
   {

      glEnable(GL_DEPTH_TEST);


      glDepthFunc(GL_LESS);
   }

   Renderer::~Renderer()
   {
   }

   void Renderer::Clear() const
   {

      // Clear the screen 
      GLCheckError();
      glClearColor(0.678f, 0.847f, 0.902f, 1.0f);
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
      GLCheckError();
   }

   // Skybox
   void Renderer::DrawSkybox(const Mesh& skyboxMesh, const Shader& shader) const {
      GLCheckError();
      // Disable depth writing for the skybox
      glDepthFunc(GL_LEQUAL);
      glEnable(GL_BLEND);
      glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
      shader.Bind();

      skyboxMesh.Bind();
      glDrawElements(GL_TRIANGLES, skyboxMesh.GetIndexCount(), GL_UNSIGNED_INT, nullptr);
      skyboxMesh.Unbind();

      glDepthFunc(GL_LESS);
      shader.Unbind();
      GLCheckError();
   }


   void Renderer::DrawInstanced(const std::vector<Mesh*>& meshes, const Shader& shader, unsigned int instanceCount) const {
      GLCheckError();

      for (const Mesh* mesh : meshes) {
         mesh->Bind();
         glDrawElementsInstanced(GL_TRIANGLES, mesh->GetIndexCount(), GL_UNSIGNED_INT, (void*)(mesh->GetIndexOffset() * sizeof(unsigned int)), instanceCount);
         mesh->Unbind();
      }

      GLCheckError();
   }

   void Renderer::DrawModel(const std::vector<Mesh*>& mehses, const Shader& shader)
   {

   }


} // namespace glc





