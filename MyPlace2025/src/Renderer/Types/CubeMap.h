#pragma once

#include <glad/glad.h>
#include <string>
#include <vector>

class Skybox {
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

