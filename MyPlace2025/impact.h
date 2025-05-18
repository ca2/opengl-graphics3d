#pragma once


#include "apex/platform/app_consumer.h"
#include "app-cube/cube/impact.h"
#include "application.h"
#include "app-cube/cube/engine.h"
//#include "app-cube/cube/impact.h"
#include "app-cube/cube/types.h"


namespace opengl_graphics3d_MyPlace2025
{


   class CLASS_DECL_OPENGL_GRAPHICS3D_MYPLACE2025 impact :
      virtual public ::app_consumer < application, ::cube::impact >
   {
   public:


      ::write_text::font_pointer       m_pfontThomasBS_;
      string                           m_strFont1;
      int                              m_iSequence;
      mouseState                       m_mousestate;

      ::image::image_pointer m_pimage;

      ::particle_pointer         m_pparticleImageSynchronization;

      impact();
      ~impact() override;

//      // void assert_ok() const override;
//      // void dump(dump_context & dumpcontext) const override;

#ifdef _DEBUG
      virtual long long increment_reference_count() override;
      virtual long long decrement_reference_count() override;
#endif

      virtual ::pointer < ::opengl::engine > start_opengl_engine();

      ::pointer < ::opengl::application > start_opengl_application() override;


      virtual void install_message_routing(::channel * psender) override;

      virtual void _001OnClip(::draw2d::graphics_pointer & pgraphics) override;

      virtual void _001OnDraw(::draw2d::graphics_pointer & pgraphics) override;

      void handle(::topic * ptopic, ::handler_context * phandlercontext) override;

      document * get_document();


      void reset_mouse_last_position();

      void on_layout(::draw2d::graphics_pointer & pgraphics) override;

      DECLARE_MESSAGE_HANDLER(on_message_create);
      DECLARE_MESSAGE_HANDLER(on_message_destroy);
      DECLARE_MESSAGE_HANDLER(on_message_mouse_move);
      DECLARE_MESSAGE_HANDLER(on_message_mouse_leave);
      
      
      bool on_click(::item * pitem, ::user::mouse * pmouse) override;
      
      virtual bool is_absolute_mouse_position();

   };


} // namespace opengl_graphics3d_MyPlace2025


