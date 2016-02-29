//
// TextureLoader.hpp for bomberman in /home/rousse_3/rendu/cpp_bomberman
// 
// Made by rousse_3
// Login   <rousse_3@epitech.net>
// 
// Started on  Tue Jun  9 17:23:34 2015 rousse_3
// Last update Tue Jun  9 21:56:24 2015 rousse_3
//

#ifndef		TEXTURELOADER_HPP_
# define	TEXTURELOADER_HPP_

# include	<list>
# include	<string>
# include	<Texture.hh>

class		TextureLoader
{
public:
  TextureLoader(void);
  ~TextureLoader(void) throw();

  static TextureLoader	&getInstance(void);
  bool			load(const std::string &label, const std::string &filename);
  gdl::Texture		*getTexture(const std::string &label);
private:
  std::list<std::pair<std::string, gdl::Texture*> >	_textures;
  static TextureLoader					*_obj;
};

#endif		/* !TEXTURELOADER_HPP_ */
