//
// Ground.cpp for Ground in /home/costa_b/rendu/bombe_graphic/src
// 
// Made by Kevin Costa
// Login   <costa_b@epitech.net>
// 
// Started on  Mon Jun  1 17:25:50 2015 Kevin Costa
// Last update Wed Jun 10 14:17:43 2015 rousse_3
//

#include	<Game.hh>
#include	<Clock.hh>
#include	<Input.hh>
#include	<SdlContext.hh>
#include	<Geometry.hh>
#include	<Texture.hh>
#include	<BasicShader.hh>
#include	<Model.hh>

#include	<OpenGL.hh>

#include	<glm/glm.hpp>
#include	<glm/gtc/matrix_transform.hpp>
#include	"Graphics/Ground.hpp"
#include	"Graphics/TextureLoader.hpp"

Ground::Ground(double x, double y, double z, double scaleX, double scaleY, double scaleZ) : AObject(x, y, z, scaleX, scaleY, scaleZ) {}

bool		Ground::initialize()
{
  TextureLoader		load = TextureLoader::getInstance();

  _speed = 10.0f;
  _texture = load.getTexture("Ground");
  _geometry.setColor(glm::vec4(1, 1, 1, 1));
  _geometry.pushVertex(glm::vec3(0.5, -0.5, -0.5));
  _geometry.pushVertex(glm::vec3(0.5, -0.5, 0.5));
  _geometry.pushVertex(glm::vec3(-0.5, -0.5, 0.5));
  _geometry.pushVertex(glm::vec3(-0.5, -0.5, -0.5));
  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));
  _geometry.build();
  // this->scale(glm::vec3(32, 32, 32));
  // this->rotate(glm::vec3(1, 0, -30), 0);
  // this->rotate(glm::vec3(0, 0, 1), 90);
  // this->_position = glm::vec3(0, 0, -20);
  return (true);
}

void		Ground::update(gdl::Clock const &clock, gdl::Input &input)
{
  // On multiplie par le temps ecoule depuis la derniere image pour que la vitesse ne depende pas de la puissance de l'ordinateur
  (void)clock;
  (void)input;
}

void		Ground::draw(gdl::AShader &shader, gdl::Clock const &clock)
{
  (void)clock;
  // On bind la texture pour dire que l'on veux l'utiliser
  _texture->bind();
  // Et on dessine notre cube
  _geometry.draw(shader, getTransformation(), GL_QUADS);
}

