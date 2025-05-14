#include "framework.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "aura/graphics/gpu/approach.h"
#include "aura/graphics/gpu/context.h"
#include "engine.h"
#include "Core/Window.h"
#include "Core/Input.h"
#include "Renderer/Renderer.h"
#include "Renderer/Types/Mesh.h"
#include "Shader/Shader.h"
#include <iostream>
#include "Core/Camera.h"
#include "AppCore/Application.h"

#pragma comment( lib, "glu32" )
#pragma comment( lib, "opengl32" )
//.lib; opengl32.lib;
// Acting weird flag = :   ------------------- **


namespace opengl
{


   engine::engine()
      : m_Running(true)
      //,m_Window("My Universe", 1100, 600),
   {
      //m_bRunEngine = true;
   }

   
   void engine::on_initialize_particle()
   {

      ::particle::on_initialize_particle();

//      gladLoadGL();


//      m_pcamera->initialize(this);



      

      // Set the window for input management
      //Input::SetGLFWWindow(m_Window.GetGLFWWindow());

      // Set up mouse callback and user pointer
      //glfwSetWindowUserPointer(m_Window.GetGLFWWindow(), this);
      //glfwSetCursorPosCallback(m_Window.GetGLFWWindow(), MouseCallback);
      //glfwSetInputMode(m_Window.GetGLFWWindow(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);  // Hide cursor


   }

   // Destroy Game
   engine::~engine()
   {
   }


   void engine::initialize_engine(glc::GlContainer* pglcontainer)
   {


   }

   // engine Run
   bool engine::render_step() 
   {


      float lastFrame = 0.0f;

      // Main loop
      if (!m_Running || m_pglcontainer->m_bShouldClose)
      {

         return false;

      }

      //{

      if (m_pglcontainer->m_iWidth <= 0
         || m_pglcontainer->m_iHeight <= 0)
      {

         return true;

      }
            // Frame Logic
            float currentFrame = ::time::now().floating_second();
            float deltaTime = currentFrame - lastFrame;
            lastFrame = currentFrame;

            deltaTime = minimum_maximum(deltaTime, 0.001, 0.016666666);

            ProcessInput(deltaTime);

            // Toggle wireframe mode
            if (m_bWireframeMode) {
               glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // Enable wireframe mode
            }
            else {
               glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // Enable solid mode
            }

            // Clear the screen
            m_prenderer->Clear();

            // Update and render the game (and the current scene)
            m_pglcapplication->Update(deltaTime, m_pcamera);
            m_pglcapplication->Render(m_prenderer, m_pcamera);

            // Swap buffers and poll for events
            //m_Window.SwapBuffers();
            //m_pglcontainer->present();
            // 
            // 

            if (m_pglcontainer->m_callbackOffscreen)
            {
               void* p = nullptr;
               int w = m_pglcontainer->m_iWidth;
               int h = m_pglcontainer->m_iHeight;
               int stride = w * 4;
               m_memoryBuffer.set_size(stride * h);
               if (glReadnPixels)
               {
                  glReadnPixels(
                     0, 0,
                     w, h,
                     GL_BGRA,
                     GL_UNSIGNED_BYTE,
                     m_memoryBuffer.size(),
                     m_memoryBuffer.data());
               }
               else
               {
                  glReadPixels(
                     0, 0,
                     w, h,
                     GL_BGRA,
                     GL_UNSIGNED_BYTE,
                     m_memoryBuffer.data());

               }

               m_pglcontainer->m_callbackOffscreen(
                  m_memoryBuffer.data(),
                  w,
                  h,
                  stride);

            }

            return true;

         //}

      //   //)

      //   //m_Window.PollEvents();
      //   ::task_iteration();
      //}
   }


   //void task::run_loop()
   //{

   //   while (task_get_run())
   //   {

   //      task_run(0_s);

   //   }

   //}


   void engine::resize(int cx, int cy)
   {

      m_pgpucontext->post([this, cx, cy]
         {

            if (!m_pglcapplication)
            {

               m_pinput = __allocate  glc::Input(m_pglcontainer);

               m_pcamera = __allocate glc::Camera(m_pglcontainer, glm::vec3(0.0f, 3.0f, 3.0f), -90.0f, 0.0f);

               m_pglcapplication = m_pglcontainer->start_opengl_application();

               m_pgpucontext->resize_offscreen_buffer({ cx, cy });

               // Initialize the game logic and scene data
               m_pglcapplication->Init();

               m_pgpucontext->m_timeSample = 1_s/ 60.0;

               m_pgpucontext->m_prender = this;

            }
            else
            {

               m_pgpucontext->resize_offscreen_buffer({ cx, cy });

            }

            m_pglcapplication->resize(cx, cy);

            m_pglcontainer->m_iWidth = cx;
            m_pglcontainer->m_iHeight = cy;

         });

   }


   // Keyboard event listeners
   void engine::ProcessInput(float deltaTime) 
   {

      if (m_pinput->IsKeyPressed(::user::e_key_w)) 
      {

         m_pcamera->ProcessKeyboardInput(glc::FORWARD, deltaTime);

         if (m_pinput->IsKeyPressed(::user::e_key_left_shift))
         {

            m_pcamera->TeleportInDirection(glc::FORWARD);

         }

      }

      if (m_pinput->IsKeyPressed(::user::e_key_s)) 
      {

         m_pcamera->ProcessKeyboardInput(glc::BACKWARD, deltaTime);

         if (m_pinput->IsKeyPressed(::user::e_key_left_shift))
         {

            m_pcamera->TeleportInDirection(glc::BACKWARD);

         }

      }

      if (m_pinput->IsKeyPressed(::user::e_key_a)) 
      {

         m_pcamera->ProcessKeyboardInput(glc::LEFT, deltaTime);

         if (m_pinput->IsKeyPressed(::user::e_key_left_shift))
         {

            m_pcamera->TeleportInDirection(glc::LEFT);

         }

      }

      if (m_pinput->IsKeyPressed(::user::e_key_d))
      {

         m_pcamera->ProcessKeyboardInput(glc::RIGHT, deltaTime);

         if (m_pinput->IsKeyPressed(::user::e_key_left_shift))
         {

            m_pcamera->TeleportInDirection(glc::RIGHT);

         }
      }

      if (m_pinput->IsKeyPressed(::user::e_key_escape))
      {

         m_Running = false;

      }
      if (m_pinput->IsKeyPressed(::user::e_key_4))
      {
         m_bWireframeMode = !m_bWireframeMode;

      }
      // Check for jump (Space key)
      if (m_pinput->IsKeyPressed(::user::e_key_space))
      {
         float jumpHeight = 0.20f;  // Define how high the jump should be
         m_pcamera->Jump(jumpHeight);
      }
      // Teleport down (Left Control key)
      if (m_pinput->IsKeyPressed(::user::e_key_left_shift)) 
      {
         float teleportDistance = 0.1081f;  // Define the downward distance
         m_pcamera->TeleportDownward(teleportDistance);
      }

      // Idle movement
      if (!m_pinput->IsAnyKeyPressed()) { // You might want to implement IsAnyKeyPressed to check for movement keys
         // m_pcamera->UpdateIdleMovement(deltaTime);
      }


   }


   // Mouse event listeners
   void engine::handleMouseMove(double dCursorX, double dCursorY)
   {

      double x, y;
      double newx, newy;

      if (m_pglcontainer->is_absolute_mouse_position())
      {

         newx = dCursorX * 1.25 * MATH_PI;
         newy = dCursorY * 1.25 * MATH_PI / 2.0;

      }
      else
      {

         newx = dCursorX;
         newy = dCursorY;

      }
      //glfwGetCursorPos(window, &xpos, &ypos);

      //if (pvkcontainer->m_bFirstMouse) {
      //   _lastX = newx;
      //   _lastY = newy;
      //   pvkcontainer->m_bFirstMouse = false;
      //   xpos = _lastX;
      //   ypos = _lastY;
      //}
      //else
      if (!m_pglcontainer->is_absolute_mouse_position())
      {

         if (m_pglcontainer->m_bFirstMouse)
         {
            
            m_dMouseLastX = newx;
            m_dMouseLastY = newy;

            m_pglcontainer->m_bFirstMouse = false;

         }

      }

      if (m_pglcontainer->is_absolute_mouse_position())
      {

         x = m_dMouseLastX + (newx - m_dMouseLastX) * 0.05;
         y = m_dMouseLastY + (newy - m_dMouseLastY) * 0.05;
         m_Δx = x;
         m_Δy = -y;  // reversed Y

      }
      else
      {

         x = newx;
         y = newy;

         m_Δx = m_Δx + static_cast<float>(x - m_dMouseLastX - m_Δx) * 0.05;
         m_Δy = m_Δy + static_cast<float>(m_dMouseLastY - y - m_Δy) * 0.05;  // reversed Y


      }

      m_dMouseLastX = x;
      m_dMouseLastY = y;

      m_pcamera->ProcessMouseMovement(m_Δx, m_Δy);

   }
   //{

   //   double xpos, ypos;
   //   double newx, newy;
   //   if (m_pglcontainer->is_absolute_mouse_position())
   //   {
   //      
   //      newx = dCursorX * 1.25 * MATH_PI;
   //      newy = dCursorY * 1.25 * MATH_PI / 2.0;

   //   }
   //   else
   //   {

   //      newx = dCursorX;
   //      newy = dCursorY;

   //   }
   //   //glfwGetCursorPos(window, &xpos, &ypos);

   //   //if (pvkcontainer->m_bFirstMouse) {
   //   //   _lastX = newx;
   //   //   _lastY = newy;
   //   //   pvkcontainer->m_bFirstMouse = false;
   //   //   xpos = _lastX;
   //   //   ypos = _lastY;
   //   //}
   //   //else
   //   if (!m_pglcontainer->is_absolute_mouse_position())
   //   {

   //      if (m_pglcontainer->m_bFirstMouse)
   //      {

   //         dCursorX = newx;
   //         dCursorY = newy;
   //         m_pglcontainer->m_bFirstMouse = false;

   //      }

   //   }
   //   {



   //   }

   //   if (m_pglcontainer->is_absolute_mouse_position())
   //   {

   //      xpos = m_pglcontainer->m_dMouseLastX + (newx - m_pglcontainer->m_dMouseLastX) * 0.05;
   //      ypos = m_pglcontainer->m_dMouseLastY + (newy - m_pglcontainer->m_dMouseLastY) * 0.05;
   //      m_Δx = xpos;
   //      m_Δy = -ypos;  // reversed Y
   //   }
   //   else
   //   {

   //      xpos = newx;
   //      ypos = newy;

   //      m_Δx = m_Δx + static_cast<float>(xpos - m_pglcontainer->m_dMouseLastX - m_Δx) * 0.05;
   //      m_Δy = m_Δy + static_cast<float>(m_pglcontainer->m_dMouseLastY - ypos - m_Δy) * 0.05;  // reversed Y


   //   }

   //   m_pglcontainer->m_dMouseLastX = xpos;
   //   m_pglcontainer->m_dMouseLastY = ypos;
   //   //auto x = (double)xpos;
   //   //auto y = (double)ypos;
   //   ////engine* engine = static_cast<engine*>(glfwGetWindowUserPointer(window));

   //   //if (m_pglcontainer->m_bFirstMouse)
   //   //{
   //   //   m_pglcontainer->m_dMouseLastX = x;
   //   //   m_pglcontainer->m_dMouseLastY = Y;
   //   //   m_bFirstMouse = false;
   //   //}

   //   //float Δx = x - m_fLastX;
   //   //float Δy = m_fLastY - y;  // Y-coordinates go from bottom to top
   //   //m_fLastX = x;
   //   //m_fLastY = y;


   //   m_pcamera->ProcessMouseMovement(m_Δx, m_Δy);

   //}





   ::pointer<::opengl::engine > start_opengl_engine(::glc::GlContainer* pglcontainer, mouseState* pmousestate)
   {

      auto popenglengine = pglcontainer->__create_new <::opengl::engine >();

      popenglengine->m_pglcontainer = pglcontainer;

      return popenglengine;

      }



} // namespace opengl
