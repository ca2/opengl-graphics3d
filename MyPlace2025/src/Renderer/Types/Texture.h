
#pragma once 

#include <string>
#include <glad/glad.h>  

class Texture {
public:
    Texture(const std::string& filePath);
    ~Texture();

    void Bind(unsigned int slot = 0) const;
    void Unbind() const;

private:
    GLuint m_TextureID;
    std::string m_FilePath;
};

//*/