//
// Pause.cpp for Pause in /home/costa_b/rendu/cpp_bomberman/src/Graphics
// 
// Made by Kevin Costa
// Login   <costa_b@epitech.net>
// 
// Started on  Sat Jun 13 07:56:48 2015 Kevin Costa
// Last update Sun Jun 14 15:43:16 2015 rousse_3
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
#include	"Graphics/Pause.hpp"

Pause::Pause(double x, double y, double z, double scaleX, double scaleY, double scaleZ) : AObject(x, y, z, scaleX, scaleY, scaleZ) {}


bool		Pause::initialize()
{
  _speed = 10.0f;
  // On charge la texture qui sera affichee sur chaque face du cube
  if (_texture.load("./LibBomberman_linux_x64/assets/Pause.tga") == false)
    {
      std::cerr << "Cannot load the cube texture" << std::endl;
      return (false);
    }
  // on set la color d'une premiere face
  _geometry.setColor(glm::vec4(1, 1, 1, 1));
  // tout les pushVertex qui suivent seront de cette couleur
  // On y push les vertices d une premiere face
  _geometry.pushVertex(glm::vec3(0.5, -0.5, 0.5));
  _geometry.pushVertex(glm::vec3(0.5, 0.5, 0.5));
  _geometry.pushVertex(glm::vec3(-0.5, 0.5, 0.5));
  _geometry.pushVertex(glm::vec3(-0.5, -0.5, 0.5));
  // Les UVs d'une premiere face
  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));
  // Tres important, on n'oublie pas de build la geometrie pour envoyer ses informations a la carte graphique
  _geometry.build();
  this->rotate(glm::vec3(1, 0, 0), 1);
  this->rotate(glm::vec3(0, 0, 1), 90);
  this->rotate(glm::vec3(0, 1, 0), 180);
  this->rotate(glm::vec3(1, 0, 0), 90);
  // this->_position = glm::vec3(0, 0, -20);
  return (true);
}

void		Pause::update(gdl::Clock const &clock, gdl::Input &input)
{
  (void)clock;
  (void)input;
}

void		Pause::draw(gdl::AShader &shader, gdl::Clock const &clock)
{
  (void)clock;
  // On bind la texture pour dire que l'on veux l'utiliser
  _texture.bind();
  // Et on dessine notre cube
  _geometry.draw(shader, getTransformation(), GL_QUADS);
}
