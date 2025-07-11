#pragma once


#include "cube/frame.h"


namespace opengl_graphics3d_landen
{


   class CLASS_DECL_OPENGL_GRAPHICS3D_LANDEN frame :
      virtual public ::simple_frame_window
   {
   public:


      bool                       m_bExplicitTranslucency;
      ::user::enum_translucency      m_etranslucency;


      frame();
      ~frame() override;

      void install_message_routing(::channel* pchannel) override;
	   // void assert_ok() const override;
	   // void dump(dump_context & dumpcontext) const override;

      void _001OnNcClip(::draw2d::graphics_pointer & pgraphics) override;
      void _001OnClip(::draw2d::graphics_pointer & pgraphics) override;

      void _001OnNcDraw(::draw2d::graphics_pointer & pgraphics) override;
      void _001OnDraw(::draw2d::graphics_pointer & pgraphics) override;



      ::user::enum_translucency get_translucency(::user::style * pstyle) override;
      using simple_frame_window::frame_experience;
      ::pointer < ::experience::frame > frame_experience() override;

      //DECLARE_MESSAGE_HANDLER(on_message_close);
   };


} // namespace app_core_vulken












