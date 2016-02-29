//
// Model.cpp for  in /home/degand/Projects/bombe_graphic/src
// 
// Made by Alaric
// Login   <degand@epitech.net>
// 
// Started on  Mon Jun  1 17:30:49 2015 Alaric
// Last update Fri Jun 12 12:43:12 2015 Nicolas Ribeiro Teixeira
//

#include	<Game.hh>
#include	<Clock.hh>
#include	<SdlContext.hh>
#include	<Geometry.hh>
#include	<Texture.hh>
#include	<BasicShader.hh>
#include	<Model.hh>
#include	<Input.hh>

#include	<OpenGL.hh>

#include	<glm/glm.hpp>
#include	<glm/gtc/matrix_transform.hpp>
#include	"Graphics/Model.hpp"
#include	"Graphics/TextureLoader.hpp"

Model::Model(double x, double y, double z, double scaleX, double scaleY, double scaleZ) : AObject(x, y, z, scaleX, scaleY, scaleZ) {}

bool		Model::initialize()
{
  TextureLoader		load = TextureLoader::getInstance();

  _speed = 10.0f;
  _texture = load.getTexture("Player");
  _geometry.load("./LibBomberman_linux_x64/assets/marvin.fbx");
  _geometry.setCurrentAnim(0, true);
  return (true);
}

void		Model::update(gdl::Clock const &clock, gdl::Input &input)
{
  (void) clock;
  (void) input;
}

void		Model::draw(gdl::AShader &shader, gdl::Clock const &clock)
{
  (void)clock;
  _texture->bind();
  _geometry.draw(shader, getTransformation(), clock.getElapsed());
}
