#pragma once


#include "cube/_.h"



#if defined(_opengl_graphics3d_landen_project)
   #define CLASS_DECL_OPENGL_GRAPHICS3D_LANDEN  CLASS_DECL_EXPORT
#else
   #define CLASS_DECL_OPENGL_GRAPHICS3D_LANDEN  CLASS_DECL_IMPORT
#endif


namespace opengl_graphics3d_landen
{


   class application;
   //class top_impact;
   //class main_impact;
   class document;
   class impact;


} // namespace opengl_graphics3d_landen


//#undef APP_TYPE
//#define APP_TYPE ::vulken::application


//#include "application.h"


#if defined(WINDOWS_DESKTOP)

#define VK_PROTOTYPES
#define VK_USE_PLATFORM_WIN32_KHR

#endif



