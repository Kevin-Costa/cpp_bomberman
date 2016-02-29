//
// Plan.hh for  in /home/degand/Projects/bombe_graphic/src
// 
// Made by Alaric
// Login   <degand@epitech.net>
// 
// Started on  Mon Jun  1 17:41:08 2015 Alaric
// Last update Sat Jun 13 07:59:12 2015 Kevin Costa
//

#ifndef		PLAN_HPP_
# define	PLAN_HPP_

// Permet d'inclure la SDL 2
#include <SdlContext.hh>
// Inclus la bibliotheque de mathematiques
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>

#include	"AObject.hpp"

class Plan : public AObject
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
  Plan(double x, double y, double z, double scaleX, double scaleY, double scaleZ);
  virtual ~Plan() { }
  virtual bool initialize();
  virtual void update(gdl::Clock const &clock, gdl::Input &input);
  virtual void draw(gdl::AShader &shader, gdl::Clock const &clock);
};

#endif		/* !PLAN_HPP_ */
