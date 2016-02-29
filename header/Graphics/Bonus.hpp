//
// Bonus.hh for  in /home/degand/Projects/bombe_graphic/src
// 
// Made by Alaric
// Login   <degand@epitech.net>
// 
// Started on  Mon Jun  1 17:35:50 2015 Alaric
// Last update Thu Jun 11 13:39:07 2015 rousse_3
//

#ifndef		BONUS_HPP_
# define	BONUS_HPP_

#include	<SdlContext.hh>
#include	<glm/glm.hpp>
#include	<glm/gtc/matrix_transform.hpp>
#include	<iostream>
# include <Texture.hh>
# include <Geometry.hh>

#include	"AObject.hpp"

class Bonus : public AObject
{
private:
  gdl::Texture *_texture;
  gdl::Geometry *_geometry;
  float _speed;
public:
  Bonus(double x, double y, double z, double scaleX, double scaleY, double scaleZ, double red = 1, double green = 1, double blue = 1);
  virtual ~Bonus() { }
  virtual bool initialize();
  virtual void update(gdl::Clock const &clock, gdl::Input &input);
  virtual void draw(gdl::AShader &shader, gdl::Clock const &clock);
};

#endif		/* !BONUS_HPP_ */
