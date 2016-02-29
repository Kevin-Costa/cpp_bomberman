//
// Cube.cpp for  in /home/degand/Projects/bombe_graphic/src
// 
// Made by Alaric
// Login   <degand@epitech.net>
// 
// Started on  Mon Jun  1 17:23:49 2015 Alaric
// Last update Thu Jun 11 18:16:43 2015 rousse_3
//

#include	<SdlContext.hh>
#include	<glm/glm.hpp>
#include	<glm/gtc/matrix_transform.hpp>
#include	<iostream>
#include	<Game.hh>
#include	<Clock.hh>
#include	<Input.hh>
#include	<SdlContext.hh>
#include	<Geometry.hh>
#include	<Texture.hh>
#include	<BasicShader.hh>
#include	<Model.hh>

#include	<OpenGL.hh>

#include	"Graphics/AObject.hpp"
#include	"Graphics/Cube.hpp"
#include	"Graphics/TextureLoader.hpp"

Cube::Cube(double x, double y, double z, double scaleX, double scaleY, double scaleZ, double red, double green, double blue) : AObject(x, y, z, scaleX, scaleY, scaleZ, red, green, blue) {}

Cube::~Cube()
{
  delete _geometry;
}

bool		Cube::initialize()
{
  TextureLoader		load = TextureLoader::getInstance();

  _speed = 10.0f;
  _texture = load.getTexture("Wall");
  _geometry = new gdl::Geometry;
  _geometry->setColor(glm::vec4(_color, 1));
  _geometry->pushVertex(glm::vec3(0.5, -0.5, 0.5));
  _geometry->pushVertex(glm::vec3(0.5, 0.5, 0.5));
  _geometry->pushVertex(glm::vec3(-0.5, 0.5, 0.5));
  _geometry->pushVertex(glm::vec3(-0.5, -0.5, 0.5));
  _geometry->pushUv(glm::vec2(0.0f, 0.0f));
  _geometry->pushUv(glm::vec2(1.0f, 0.0f));
  _geometry->pushUv(glm::vec2(1.0f, 1.0f));
  _geometry->pushUv(glm::vec2(0.0f, 1.0f));
  _geometry->pushVertex(glm::vec3(0.5, -0.5, -0.5));
  _geometry->pushVertex(glm::vec3(0.5, 0.5, -0.5));
  _geometry->pushVertex(glm::vec3(-0.5, 0.5, -0.5));
  _geometry->pushVertex(glm::vec3(-0.5, -0.5, -0.5));
  _geometry->pushUv(glm::vec2(0.0f, 0.0f));
  _geometry->pushUv(glm::vec2(1.0f, 0.0f));
  _geometry->pushUv(glm::vec2(1.0f, 1.0f));
  _geometry->pushUv(glm::vec2(0.0f, 1.0f));
  _geometry->pushVertex(glm::vec3(0.5, -0.5, -0.5));
  _geometry->pushVertex(glm::vec3(0.5, 0.5, -0.5));
  _geometry->pushVertex(glm::vec3(0.5, 0.5, 0.5));
  _geometry->pushVertex(glm::vec3(0.5, -0.5, 0.5));
  _geometry->pushUv(glm::vec2(0.0f, 0.0f));
  _geometry->pushUv(glm::vec2(1.0f, 0.0f));
  _geometry->pushUv(glm::vec2(1.0f, 1.0f));
  _geometry->pushUv(glm::vec2(0.0f, 1.0f));
  _geometry->pushVertex(glm::vec3(-0.5, -0.5, 0.5));
  _geometry->pushVertex(glm::vec3(-0.5, 0.5, 0.5));
  _geometry->pushVertex(glm::vec3(-0.5, 0.5, -0.5));
  _geometry->pushVertex(glm::vec3(-0.5, -0.5, -0.5));
  _geometry->pushUv(glm::vec2(0.0f, 0.0f));
  _geometry->pushUv(glm::vec2(1.0f, 0.0f));
  _geometry->pushUv(glm::vec2(1.0f, 1.0f));
  _geometry->pushUv(glm::vec2(0.0f, 1.0f));
  _geometry->pushVertex(glm::vec3(0.5, 0.5, 0.5));
  _geometry->pushVertex(glm::vec3(0.5, 0.5, -0.5));
  _geometry->pushVertex(glm::vec3(-0.5, 0.5, -0.5));
  _geometry->pushVertex(glm::vec3(-0.5, 0.5, 0.5));
  _geometry->pushUv(glm::vec2(0.0f, 0.0f));
  _geometry->pushUv(glm::vec2(1.0f, 0.0f));
  _geometry->pushUv(glm::vec2(1.0f, 1.0f));
  _geometry->pushUv(glm::vec2(0.0f, 1.0f));
  _geometry->pushVertex(glm::vec3(0.5, -0.5, -0.5));
  _geometry->pushVertex(glm::vec3(0.5, -0.5, 0.5));
  _geometry->pushVertex(glm::vec3(-0.5, -0.5, 0.5));
  _geometry->pushVertex(glm::vec3(-0.5, -0.5, -0.5));
  _geometry->pushUv(glm::vec2(0.0f, 0.0f));
  _geometry->pushUv(glm::vec2(1.0f, 0.0f));
  _geometry->pushUv(glm::vec2(1.0f, 1.0f));
  _geometry->pushUv(glm::vec2(0.0f, 1.0f));
  _geometry->build();

  return (true);
}

void		Cube::update(gdl::Clock const &clock, gdl::Input &input)
{
  (void)clock;
  (void)input;
}

void		Cube::draw(gdl::AShader &shader, gdl::Clock const &clock)
{
  (void)clock;
  _texture->bind();
  _geometry->draw(shader, getTransformation(), GL_QUADS);
}
