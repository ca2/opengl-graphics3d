#pragma once


#include "bred/user/user/graphics3d.h"


namespace opengl_graphics3d_continuum
{


   class CLASS_DECL_OPENGL_GRAPHICS3D_CONTINUUM impact :
      virtual public ::app_consumer < application, ::user::graphics3d >
   {
   public:


      ::write_text::font_pointer       m_pfontThomasBS_;
      string                           m_strFont1;
      int                              m_iSequence;


      impact();
      ~impact() override;

//      // void assert_ok() const override;
//      // void dump(dump_context & dumpcontext) const override;

#ifdef _DEBUG
      virtual long long increment_reference_count() override;
      virtual long long decrement_reference_count() override;
#endif

      //::pointer < ::graphics3d::application > start_graphics3d_application() override;


      virtual void install_message_routing(::channel * psender) override;

      virtual void _001OnClip(::draw2d::graphics_pointer & pgraphics) override;

      virtual void _001OnDraw(::draw2d::graphics_pointer & pgraphics) override;

      void handle(::topic * ptopic, ::handler_context * phandlercontext) override;

      document * get_document();

      void on_layout(::draw2d::graphics_pointer & pgraphics) override;

      DECLARE_MESSAGE_HANDLER(on_message_create);
      DECLARE_MESSAGE_HANDLER(on_message_destroy);
      
      
      bool on_click(::item * pitem, ::user::mouse * pmouse) override;
      
      bool is_absolute_mouse_position() override;

      void on_load_engine() override;

      ::pointer < ::cube::key_map > get_default_key_map() override;

   };


} // namespace opengl_graphics3d_continuum


