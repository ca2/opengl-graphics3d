#pragma once

//#include "opengl/application.h"
#include "cube/platform/application.h"
#include "cube/application.h"


namespace opengl_graphics3d_landen
{


   class CLASS_DECL_OPENGL_GRAPHICS3D_LANDEN application :
      virtual public ::cube::application
   {
   public:


      //::user::document *                     m_pdocMenu;
      //::user::single_document_template *     m_ptemplateFuelMain;
      //::user::single_document_template *     m_ptemplateFuelImpact;
      //::pointer < ::graphics3d::application > m_p3dapplication;

      application();
      ~application() override;
      
      __DECLARE_APPLICATION_RELEASE_TIME();



      void init_instance() override;
      void term_instance() override;

      void on_request(::request * prequest) override;


      long long increment_reference_count() override;
      long long decrement_reference_count() override;

      
      //string draw2d_get_default_implementation_name() override;

      
      //virtual void on_layout_cube(int cx, int cy);

      ::string graphics3d_get_implementation_name() override;
   };


} // namespace opengl_graphics3d_landen



