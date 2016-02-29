//
// Pause.hpp for Pause in /home/costa_b/rendu/cpp_bomberman/header/Graphics
// 
// Made by Kevin Costa
// Login   <costa_b@epitech.net>
// 
// Started on  Sat Jun 13 07:58:38 2015 Kevin Costa
// Last update Sat Jun 13 07:59:53 2015 Kevin Costa
//

#ifndef		PAUSE_HPP_
# define	PAUSE_HPP_

// Permet d'inclure la SDL 2
#include <SdlContext.hh>
// Inclus la bibliotheque de mathematiques
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>

#include	"AObject.hpp"

class Pause : public AObject
{
private:
  // La texture utilisee pour le cube
  gdl::Texture _texture;
  // La geometrie du cube
  gdl::Geometry _geometry;
  // La vitesse de deplacement du cube
  float _speed;
  std::string	_Path;
public:
  Pause(double x, double y, double z, double scaleX, double scaleY, double scaleZ);
  virtual ~Pause() { }
  virtual bool initialize();
  virtual void update(gdl::Clock const &clock, gdl::Input &input);
  virtual void draw(gdl::AShader &shader, gdl::Clock const &clock);
};

#endif		/* !PAUSE_HPP_ */
