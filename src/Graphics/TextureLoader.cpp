//
// TextureLoader.cpp for bomberman in /home/rousse_3/rendu/cpp_bomberman
// 
// Made by rousse_3
// Login   <rousse_3@epitech.net>
// 
// Started on  Tue Jun  9 17:31:49 2015 rousse_3
// Last update Wed Jun 10 15:54:43 2015 rousse_3
//

#include	<stdexcept>
#include	<iostream>
#include	"Graphics/TextureLoader.hpp"

TextureLoader	*TextureLoader::_obj = NULL;

TextureLoader::TextureLoader(void) {}

TextureLoader::~TextureLoader(void) throw() {}

TextureLoader	&TextureLoader::getInstance(void)
{
  if (_obj == NULL)
    _obj = new TextureLoader();
  return (*_obj);
}

bool		TextureLoader::load(const std::string &label, const std::string &filename)
{
  gdl::Texture	*text = new gdl::Texture;

  if (text->load(filename.c_str()) == false)
    return (false);
  _textures.push_back(std::make_pair(label, text));
  return (true);
}

gdl::Texture	*TextureLoader::getTexture(const std::string &label)
{
  std::list< std::pair<std::string, gdl::Texture*> >::iterator	it = _textures.begin();

  while (it != _textures.end())
    {
      if ((*it).first == label)
	return ((*it).second);
      ++it;
    }
  throw std::logic_error("Unknow Texture" + label);
}
