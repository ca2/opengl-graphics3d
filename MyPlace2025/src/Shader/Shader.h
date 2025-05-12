#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "GLFW/glfw3.h"
#include <string>

class Shader {
public:
    Shader(const std::string& vertexPath, const std::string& fragmentPath);
    ~Shader();

    void Bind() const;
    void Unbind() const;

    void SetUniformMat4f(const std::string& name, const glm::mat4& matrix) const;
    void SetUniform3f(const std::string& name, float v0, float v1, float v2) const;

    // New method declarations for setting vec3 and float uniforms
    void setVec3(const std::string& name, const glm::vec3& value) const;
    void setFloat(const std::string& name, float value) const;

    GLuint GetProgramID() const { return m_ProgramID; }

private:
    GLuint m_ProgramID;
    std::string ParseShader(const std::string& filePath);
    GLuint CompileShader(GLenum type, const std::string& source);
    void LinkShaders(GLuint vertexShader, GLuint fragmentShader);
};
