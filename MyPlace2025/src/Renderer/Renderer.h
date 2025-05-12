#pragma once
#include "Types/Mesh.hpp"
#include "Shader/shader.h"
#include "GLFW/glfw3.h"
#include <memory>
#include <glm/glm.hpp>



class Renderer {
public:
    Renderer();
    ~Renderer();

    void Clear() const;

    // Draws the skybox using the given mesh and shader
    void DrawSkybox(const Mesh& skyboxMesh, const Shader& shader) const;

    void DrawInstanced(const std::vector<Mesh*>& meshes, const Shader& shader, unsigned int instanceCount) const;
    void MultiDrawIndirectCommand() {}

    void DrawModel(const std::vector<Mesh*>& mehses, const Shader& shader);
  

private:
    int instanceCount = 0;
};
