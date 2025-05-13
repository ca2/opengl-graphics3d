
#pragma once 

#include <string>
#include <glad.h>  

namespace glc
{

   class Texture :
      virtual public ::particle
   
   {
   public:
      Texture(const std::string& filePath);
      ~Texture();

      void Bind(unsigned int slot = 0) const;
      void Unbind() const;

   private:
      GLuint m_TextureID;
      std::string m_FilePath;
   };

   //*/

} // namespace glc


