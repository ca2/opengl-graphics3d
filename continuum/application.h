#pragma once


#include "cube/application.h"


namespace opengl_graphics3d_continuum
{


   class CLASS_DECL_OPENGL_GRAPHICS3D_CONTINUUM application :
      virtual public ::cube::application
   {
   public:


      bool m_bAbsoluteMousePosition;

      pane_impact* m_ppaneimpact;
      ::file::path                                    m_pathApplicationText;
      ::user::document* m_pdocMenu;
      //::pointer<::user::single_document_template>  m_ptemplateSimpleDrawingMain;
      //pane_impact *                                     m_ppaneimpact;
      ::pointer < ::user::plain_edit >             m_peditYeeColor;

      application();
      ~application() override;


      __DECLARE_APPLICATION_RELEASE_TIME();


      virtual string preferred_experience() override;
      virtual void init_instance() override;
      virtual void term_application() override;

      virtual void on_request(::request* prequest) override;

#ifdef _DEBUG
      virtual long long increment_reference_count() override;
      virtual long long decrement_reference_count() override;
#endif
      void create_options_body(::user::interaction* pparent);


      bool is_absolute_mouse_position();
      ::string graphics3d_get_implementation_name() override;
   };


} // namespace opengl_graphics3d_continuum



