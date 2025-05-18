#pragma once

//#include "GLFW/glfw3.h"
#include <unordered_map>
#include "Core/gl_container.h"
#include "Common/Types.h"
#include "acme/constant/user_key.h"


namespace glc
{


   class Input :
      virtual public ::particle
   {
   public:

      ::pointer < glc::GlContainer> m_pglcontainer;
      bool m_IsFullscreen;

      std::unordered_map<::user::e_key, bool> m_KeyPressed; // Store the state of each key
      //static int m_WindowedWidth, m_WindowedHeight;
      //static int m_WindowedPosX, m_WindowedPosY;

      Input(glc::GlContainer* pglcontainer);
      ~Input() override;

      ::user::enum_key_state  get_key_state(::user::e_key ekey);
      bool IsKeyPressed(::user::e_key ekey); // New method for released keys
      bool IsKeyReleased(::user::e_key ekey); // New method for released keys
      //void SetGLFWWindow(glc::GlContainer * pglcontainer);
      void ToggleFullscreen();  // Fullscreen toggle logic
      void Update(); // Update key states each frame
      bool IsAnyKeyPressed(); // New method to check if any keys are pressed
   //private:

      bool WasKeyPressed(::user::e_key ekey); // Helper to check if key was pressed once
   };




} // namespace glc


