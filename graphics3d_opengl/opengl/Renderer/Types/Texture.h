
#pragma once 

#include <string>
#include <glad.h>  

namespace glc
{

   class Texture :
      virtual public ::particle
   
   {
   public:
      Texture(::particle * pparticle,const std::string& filePath);
      ~Texture();

      void Bind(unsigned int slot = 0) const;
      void Unbind() const;

      GLuint m_TextureID;
      std::string m_FilePath;
      ::std::string type;
   };

   //*/

} // namespace glc


