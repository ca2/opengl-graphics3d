#include "framework.h"
#include "Input.h"
#include "Common/Types.h"
#include "aura/platform/session.h"

namespace graphics3d_opengl
{


   // Initialize static members
   //::cube::impact* Input::m_pimpact = nullptr;
   //bool Input::m_IsFullscreen = false;
   //int Input::m_WindowedWidth = 1280;
   //int Input::m_WindowedHeight = 720;
   //int Input::m_WindowedPosX = 100;
   //int Input::m_WindowedPosY = 100;
   //std::unordered_map<::user::e_key, bool> Input::m_KeyPressed;
   Input::Input(::cube::impact* pglcontainer) :
      m_pimpact(pglcontainer)
   {

      initialize(pglcontainer);
   }

   Input::~Input()
   {


   }

::user::enum_key_state Input::get_key_state(::user::e_key ekey) 
   {
      //int state = glfwGetKey(m_pimpact, key);
      //return state == GLFW_PRESS || state == GLFW_REPEAT;


      if (session()->is_key_pressed(ekey))
      {


         return ::user::e_key_state_pressed;

      }

      return ::user::e_key_state_none;
   }

bool Input::IsKeyPressed(::user::e_key ekey)
{
   return get_key_state(ekey) & ::user::e_key_state_pressed;
}

   bool Input::IsKeyReleased(::user::e_key ekey) 
   {
      return !get_key_state(ekey);
   }

   //void Input::SetGLFWWindow(::cube::impact* window) {
   //   m_pimpact = window;
   //}

   // Fullscreen toggle logic
   void Input::ToggleFullscreen() {
      //if (m_IsFullscreen) {
      //   // Exit fullscreen, go back to windowed mode
      //   glfwSetWindowMonitor(m_pimpact, nullptr, m_WindowedPosX, m_WindowedPosY,
      //      m_WindowedWidth, m_WindowedHeight, 0);
      //}
      //else {
      //   // Enter fullscreen mode
      //   GLFWmonitor* monitor = glfwGetPrimaryMonitor();
      //   const GLFWvidmode* mode = glfwGetVideoMode(monitor);

      //   // Save current window position and size
      //   glfwGetWindowPos(m_pimpact, &m_WindowedPosX, &m_WindowedPosY);
      //   glfwGetWindowSize(m_pimpact, &m_WindowedWidth, &m_WindowedHeight);

      //   glfwSetWindowMonitor(m_pimpact, monitor, 0, 0, mode->width, mode->height, mode->refreshRate);
      //}
      //m_IsFullscreen = !m_IsFullscreen;  // Toggle the state
   }

   // Check if any movement keys are pressed (W, A, S, D)
   bool Input::IsAnyKeyPressed() {
      return IsKeyPressed(::user::e_key_w) ||
         IsKeyPressed(::user::e_key_a) ||
         IsKeyPressed(::user::e_key_s) ||
         IsKeyPressed(::user::e_key_d);
   }
   // Update the state of keys every frame
   void Input::Update() {
      for (auto& [ekey, wasPressed] : m_KeyPressed) {
         auto state = get_key_state(ekey);
         if (state & ::user::e_key_state_pressed) {
            if (!wasPressed) {
               m_KeyPressed[ekey] = true;
            }
         }
         else if (!state) {
            m_KeyPressed[ekey] = false;
         }
      }
   }

   bool Input::WasKeyPressed(::user::e_key ekey) {
      if (IsKeyPressed(ekey)) {
         if (!m_KeyPressed[ekey]) {
            m_KeyPressed[ekey] = true;
            return true;  // Only return true once when key is initially pressed
         }
      }
      else {
         m_KeyPressed[ekey] = false;
      }
      return false;
   }



} // namespace graphics3d_opengl




