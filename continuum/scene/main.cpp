// From continuum (V0idsEmbrace@Twitch)
// by camilo on 2025-05-07 02:18 <3ThomasBorregaardSorensen!!
#include "framework.h"
#include "main.h"
#include "cube/camera.h"
#include "cube/scene_object.h"


namespace opengl_graphics3d_continuum
{


   main_scene::main_scene()
   {

   }


   main_scene::~main_scene()
   {

   }


   ::cube::camera main_scene::get_default_camera()
   {

      glm::vec3 cameraPos = glm::vec3(0.0f, .0f, -5.0f);
      glm::vec3 target = glm::vec3(0.0f); // Look at origin
      glm::vec3 direction = glm::normalize(target - cameraPos);
      //camera camera{ glm::vec3(0.0f, 2.0f, -15.0f), -90.0f, 0.0f };
      return {cameraPos, target, direction };


   }


   void main_scene::on_load_scene()
   {

      {

         auto & flatVase = create_object("matter://models/flat_vase.obj");
         flatVase.translate({ -.5f, .5f, 0.f });
         flatVase.scale({3.f, 1.5f, 3.f});

      }

      {

         auto & floor = create_object("matter://models/quad.obj");
         floor.translate({0.f, .5f, 0.f});
         floor.scale({8.f, 1.f, 8.f});

      }

      {

         auto & smoothVase = create_object("matter://models/smooth_vase.obj");
         smoothVase.translate({.5f, .5f, 0.f});
         smoothVase.scale({3.f, 1.5f, 3.f});

      }

      {

         auto & stoneSphere = create_object("matter://models/StoneSphere.obj");
         stoneSphere.translate({ .0f, 0.f, 2.f });
         stoneSphere.scale({.5f, .5f, .5f});

      }

      {

         auto & woodBarrel = create_object("matter://models/Barrel_OBJ.obj");
         woodBarrel.translate({ 1.f, -.4f, -1.5f });
         woodBarrel.scale({1.f, 1.f, 1.f});

      }

      float fLo = 0.5f;

      std::vector<glm::vec3> lightColors{
            {1.f, fLo, fLo},
            {fLo, fLo, 1.f},
            {fLo, 1.f, fLo},
            {1.f, 1.f, fLo},
            {fLo, 1.f, 1.f},
            {1.f, 1.f, 1.f}
      };

      for (int i = 0; i < lightColors.size(); i++) 
      {
         auto pointLight = __allocate ::cube::point_light (0.2f);
         pointLight->m_color = lightColors[i];
         auto rotateLight = glm::rotate(
            glm::mat4(1.f),
            (i * glm::two_pi<float>()) / lightColors.size(),
            { 0.f, -1.f, 0.f });
         pointLight->m_pointlightcomponent.lightIntensity = 1.0f;
         pointLight->m_transform.translation = glm::vec3(rotateLight * glm::vec4(-1.f, -1.f, -1.f, 1.f));
         add_object(pointLight);

      }

   }



} // namespace opengl_graphics3d_continuum



