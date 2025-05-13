#pragma once


#include "apex/platform/app_consumer.h"
#include "base/user/user/impact.h"
#include "AppCore/Application.h"
#include "Core/gl_container.h"
#include "Common/Types.h"


namespace opengl_land_MyPlace2025
{


   class CLASS_DECL_OPENGL_LAND_MYPLACE2025 impact :
      virtual public ::app_consumer < application, ::user::impact, glc::GlContainer >
   {
   public:


      ::write_text::font_pointer       m_pfontThomasBS_;
      string                           m_strFont1;
      int                              m_iSequence;
      mouseState                       m_mousestate;


      impact();
      ~impact() override;

//      // void assert_ok() const override;
//      // void dump(dump_context & dumpcontext) const override;

#ifdef _DEBUG
      virtual long long increment_reference_count() override;
      virtual long long decrement_reference_count() override;
#endif

      virtual ::pointer < ::glc::Application > start_vulkan_application();


      virtual void install_message_routing(::channel * psender) override;

      virtual void _001OnClip(::draw2d::graphics_pointer & pgraphics) override;

      virtual void _001OnDraw(::draw2d::graphics_pointer & pgraphics) override;

      void handle(::topic * ptopic, ::handler_context * phandlercontext) override;

      document * get_document();

      void on_layout(::draw2d::graphics_pointer & pgraphics) override;

      DECLARE_MESSAGE_HANDLER(on_message_create);
      DECLARE_MESSAGE_HANDLER(on_message_destroy);
      
      
      bool on_click(::item * pitem, ::user::mouse * pmouse) override;
      
      virtual bool is_absolute_mouse_position();

   };


} // namespace opengl_land_MyPlace2025


