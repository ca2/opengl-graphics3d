#pragma once



#include "bred/user/user/graphics3d.h"
//#include "opengl-graphics3d/graphics3d_opengl/types.h"
//#include "graphics3d/application.h"
//#include "bred/user/user/graphics3d.h"
//#include "apex/platform/app_consumer.h"
//#include "bred/graphics3d/container.h"


namespace opengl_graphics3d_landen
{


   class CLASS_DECL_OPENGL_GRAPHICS3D_LANDEN impact :
      virtual public ::app_consumer < application, ::user::graphics3d>
   {
   public:

      //memory m_memory;
      //int m_i;

      //::graphics3d::mouse_state     m_mousestate;



      impact();
      ~impact() override;

//      // void assert_ok() const override;
//      // void dump(dump_context & dumpcontext) const override;
      //::int_size size() override;



      void install_message_routing(::channel * pchannel) override;

      //::user::enum_key_state get_key_state(::user::e_key ekey) override;
      //void _001OnNcClip(::draw2d::graphics_pointer & pgraphics) override;
      //void _001OnClip(::draw2d::graphics_pointer & pgraphics) override;


      //void _001OnNcDraw(::draw2d::graphics_pointer & pgraphics) override;
      //void _001OnDraw(::draw2d::graphics_pointer & pgraphics) override;
      //void _001OnNcPostDraw(::draw2d::graphics_pointer & pgraphics) override;


      void handle(::topic * ptopic, ::handler_context * phandlercontext) override;

      ::user::document * get_document();


      //virtual ::pointer < ::graphics3d::application > start_graphics3d_application();


      void on_layout(::draw2d::graphics_pointer & pgraphics) override;

      DECLARE_MESSAGE_HANDLER(on_message_create);
      DECLARE_MESSAGE_HANDLER(on_message_destroy);
      //DECLARE_MESSAGE_HANDLER(on_message_key_down);
      //DECLARE_MESSAGE_HANDLER(on_message_key_up);
      //DECLARE_MESSAGE_HANDLER(on_message_mouse_move);
      //DECLARE_MESSAGE_HANDLER(on_message_left_button_down);
      //DECLARE_MESSAGE_HANDLER(on_message_left_button_up);
      //DECLARE_MESSAGE_HANDLER(on_message_mouse_leave);

      void on_timer(::timer * ptimer) override;

      void reset_mouse_last_position();


      long long increment_reference_count() override
      {
         return ::object::increment_reference_count();
      }
      long long decrement_reference_count() override
      {
         return ::object::decrement_reference_count();
      }
      bool keyboard_focus_is_focusable() override;


      void on_load_engine() override;

      ::pointer < ::cube::key_map > get_default_key_map() override;

   };


} // namespace opengl_graphics3d_landen



