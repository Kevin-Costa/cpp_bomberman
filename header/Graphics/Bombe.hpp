//
// Bombe.hpp for Bombe in /home/costa_b/rendu/bombe_graphic/src
// 
// Made by Kevin Costa
// Login   <costa_b@epitech.net>
// 
// Started on  Mon Jun  1 15:45:50 2015 Kevin Costa
// Last update Sat Jun 13 08:00:55 2015 Kevin Costa
//

#ifndef		BOMBE_HPP_
# define	BOMBE_HPP_

#include <Geometry.hh>
#include <Texture.hh>
#include <Model.hh>
#include <SdlContext.hh>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>

#include	"AObject.hpp"

class Bombe : public AObject
{
private:
  gdl::Texture *_texture;
  gdl::Model _geometry;
  float _speed;
public:
  Bombe(double x, double y, double z, double scaleX, double scaleY, double scaleZ);
  virtual ~Bombe() { }
  virtual bool initialize();
  virtual void update(gdl::Clock const &clock, gdl::Input &input);
  virtual void draw(gdl::AShader &shader, gdl::Clock const &clock);
};

#endif		/* !BOMBE_HPP_ */
