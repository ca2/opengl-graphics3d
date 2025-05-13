#pragma once

//#include "GLFW/glfw3.h"
#include <unordered_map>
#include "Core/gl_container.h"
#include "Common/Types.h"
#include "acme/constant/user_key.h"

namespace glc
{


   class Input {
   public:
      static ::user::enum_key_state  get_key_state(::user::e_key ekey);
      static bool IsKeyPressed(::user::e_key ekey); // New method for released keys
      static bool IsKeyReleased(::user::e_key ekey); // New method for released keys
      static void SetGLFWWindow(glc::GlContainer * pglcontainer);
      static void ToggleFullscreen();  // Fullscreen toggle logic
      static void Update(); // Update key states each frame
      static bool IsAnyKeyPressed(); // New method to check if any keys are pressed
   private:
      static glc::GlContainer* m_pglcontainer;
      static bool m_IsFullscreen;

      static bool WasKeyPressed(::user::e_key ekey); // Helper to check if key was pressed once
      static std::unordered_map<::user::e_key, bool> m_KeyPressed; // Store the state of each key
      static int m_WindowedWidth, m_WindowedHeight;
      static int m_WindowedPosX, m_WindowedPosY;
   };




} // namespace glc


