// Created by camilo on 2025-05-17 04:41 <3ThomasBorregaardSorensen!!
#pragma once


#include "app-cube/cube/scene.h"


namespace opengl_graphics3d_landen
{


   class main_scene :
      virtual public ::cube::scene
   {
   public:



      main_scene();
      ~main_scene() override;

      void on_load_scene() override;


   };


}//    namespace opengl_graphics3d_landen



