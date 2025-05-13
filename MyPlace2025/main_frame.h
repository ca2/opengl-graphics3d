#pragma once


#include "base/user/simple/frame_window.h"


namespace opengl_land_MyPlace2025
{


   class CLASS_DECL_OPENGL_LAND_MYPLACE2025 main_frame :
      virtual public simple_frame_window
   {
   public:


      bool                       m_bExplicitTranslucency;


      main_frame();
      ~main_frame() override;


//      // void assert_ok() const override;
//      // void dump(dump_context & dumpcontext) const override;


      ::pointer < ::experience::frame > frame_experience() override;


      //bool has_pending_graphical_update() override;


      void install_message_routing(::channel * pchannel) override;


      DECLARE_MESSAGE_HANDLER(on_message_create);


   };


} // namespace opengl_land_MyPlace2025



