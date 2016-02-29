#ifndef		GROUND_HPP_
# define	GROUND_HPP_

// Permet d'inclure la SDL 2
#include <SdlContext.hh>
// Inclus la bibliotheque de mathematiques
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>

#include	"AObject.hpp"

class Ground : public AObject
{
private:
  // La texture utilisee pour le cube
  gdl::Texture *_texture;
  // La geometrie du cube
  gdl::Geometry _geometry;
  // La vitesse de deplacement du cube
  float _speed;
  std::string	_Path;
public:
  Ground(double x, double y, double z, double scaleX, double scaleY, double scaleZ);
  virtual ~Ground() { }
  virtual bool initialize();
  // Ici le cube bougera avec les fleches du clavier
  virtual void update(gdl::Clock const &clock, gdl::Input &input);
  virtual void draw(gdl::AShader &shader, gdl::Clock const &clock);
};

#endif		/* !Ground_HPP_ */
