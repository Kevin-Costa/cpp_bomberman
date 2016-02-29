//
// Model.hh for  in /home/degand/Projects/bombe_graphic/src
// 
// Made by Alaric
// Login   <degand@epitech.net>
// 
// Started on  Mon Jun  1 17:31:52 2015 Alaric
// Last update Tue Jun  9 20:09:44 2015 rousse_3
//

#ifndef		MODEL_HPP_
# define	MODEL_HPP_

// Permet d'inclure la SDL 2
# include <SdlContext.hh>
// Inclus la bibliotheque de mathematiques
# include <glm/glm.hpp>
# include <glm/gtc/matrix_transform.hpp>
# include <iostream>
# include <Model.hh>
# include <Texture.hh>

#include	"AObject.hpp"

class Model : public AObject
{
private:
  gdl::Texture *_texture;
  gdl::Model _geometry;
  float _speed;
public:
  Model(double x, double y, double z, double scaleX, double scaleY, double scaleZ);
  virtual ~Model() { }
  virtual bool initialize();
  virtual void update(gdl::Clock const &clock, gdl::Input &input);
  virtual void draw(gdl::AShader &shader, gdl::Clock const &clock);
};

#endif		/* !MODEL_HPP_ */
