
#pragma once
#pragma warning(push, 0)
#define GLM_FORCE_SILENT_WARNINGS
#define GLM_ENABLE_EXPERIMENTAL
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glad.h>
//#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <string>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "glm/gtx/hash.hpp"
//#include "Math.h"
#pragma warning(pop)
#include "Defines.h"
#include "_constant.h"


struct Vertex {
    float Position[3];
    float Color[4];
    float TexCoords[2];
    float TexID;
};



/** @brief State of mouse/touch input */
struct mouseState
{
   struct {
      bool left = false;
      bool right = false;
      bool middle = false;
   } buttons;
   glm::vec2 position;
};


