#pragma once


#include "core/platform/application.h"


namespace opengl_land_MyPlace2025
{


   class CLASS_DECL_OPENGL_LAND_MYPLACE2025 application :
      virtual public ::core::application
   {
   public:


bool m_bAbsoluteMousePosition;

      pane_impact* m_ppaneimpact;
      ::file::path                                    m_pathApplicationText;
      ::user::document *                              m_pdocMenu;
      //::pointer<::user::single_document_template>  m_ptemplateSimpleDrawingMain;
      //pane_impact *                                     m_ppaneimpact;
      ::pointer < ::user::plain_edit >             m_peditYeeColor;

      application();
      ~application() override;
      

      __DECLARE_APPLICATION_RELEASE_TIME();


      virtual string preferred_experience() override;
      virtual void init_instance() override;
      virtual void term_application() override;

      virtual void on_request(::request * prequest) override;

#ifdef _DEBUG
      virtual long long increment_reference_count() override;
      virtual long long decrement_reference_count() override;
#endif
      void create_options_body(::user::interaction* pparent);


bool is_absolute_mouse_position();

   };


} // namespace opengl_land_MyPlace2025



