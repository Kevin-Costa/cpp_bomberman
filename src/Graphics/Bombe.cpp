//
// Bombe.cpp for Bombe in /home/costa_b/rendu/bombe_graphic/src
// 
// Made by Kevin Costa
// Login   <costa_b@epitech.net>
// 
// Started on  Mon Jun  8 14:44:05 2015 Kevin Costa
// Last update Fri Jun 12 16:34:46 2015 Kevin Costa
//

#include	<Game.hh>
#include	<SdlContext.hh>
#include	<Model.hh>

#include	<OpenGL.hh>

#include	<glm/glm.hpp>
#include	"Graphics/Bombe.hpp"
#include	"Graphics/TextureLoader.hpp"

Bombe::Bombe(double x, double y, double z, double scaleX, double scaleY, double scaleZ) : AObject(x, y, z, scaleX, scaleY, scaleZ)
{
}

bool		Bombe::initialize()
{
  TextureLoader		load = TextureLoader::getInstance();

  _speed = 10.0f;
  _texture = load.getTexture("Bombe");
  _geometry.load("./LibBomberman_linux_x64/assets/bombe.fbx");
  return (true);
}

void	Bombe::update(gdl::Clock const &clock, gdl::Input &input)
{
  (void)clock;
  (void)input;
}

void	Bombe::draw(gdl::AShader &shader, gdl::Clock const &clock)
{
  (void)clock;
  _texture->bind();
  _geometry.draw(shader, getTransformation(), 0);
}
