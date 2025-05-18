#pragma once
#include <vector>
#include <glm/glm.hpp>

namespace glc
{


   class Shader;
   class Texture;

   class Mesh:
   virtual public ::particle
   {
   public:
      Mesh(const std::vector<float>& vertices, const std::vector<unsigned int>& indices,
         unsigned int vertexOffset, unsigned int indexOffset, unsigned int indexCount);
      ~Mesh();
      void Bind() const;
      void Unbind() const;
      unsigned int GetIndexCount() const;
      unsigned int GetIndexOffset() const;
      void SetInstanceModelMatrices(const std::vector<glm::mat4>& modelmatricies);
      void UpdateInstanceModelMatrices(const std::vector<glm::mat4>& modelMatrices);



      void Draw(Shader * pshader);
   //private:
      void SetupMesh();

      ::pointer_array<Texture>      textures;
      std::vector<float> m_Vertices;
      std::vector<unsigned int> m_Indices;
      unsigned int m_VAO, m_VBO, m_EBO;
      unsigned int m_IndexOffset;
      unsigned int m_IndexCount;
      unsigned int m_VertexOffset;
      std::vector<glm::mat4> m_ModelMatrices;
      // New instance buffer
      unsigned int m_InstanceVBO;
   };


} // namespace glc


