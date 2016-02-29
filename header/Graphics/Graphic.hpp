//
// Graphic.hh for  in /home/degand/Projects/graphic/src
// 
// Made by Alaric
// Login   <degand@epitech.net>
// 
// Started on  Tue May 12 12:00:05 2015 Alaric
// Last update Sun Jun 14 22:41:14 2015 rousse_3
//

#ifndef		GRAPHIC_HPP_
# define	GRAPHIC_HPP_

#include	<Game.hh>
#include	<SdlContext.hh>
#include	<Geometry.hh>
#include	<Texture.hh>
#include	<Input.hh>
#include	<Clock.hh>
#include	<BasicShader.hh>
#include	<Model.hh>

#include	<OpenGL.hh>

#include	<glm/glm.hpp>
#include	<glm/gtc/matrix_transform.hpp>

#include	"Map.hpp"
#include	"Ground.hpp"

class		Graphic : public gdl::Game
{
  int			_sizeX;
  int			_sizeY;
  int			_camX;
  int			_camY;
  int			_camZ;
  int			_orientation;
  gdl::SdlContext	_init;
  gdl::Geometry		_geometry;
  gdl::BasicShader     	_shader;
  gdl::Input		_input;
  gdl::Clock		_clock;
  Map			*_map;
  Ground		*_ground;
  bool			_stop;
public:
  Graphic(int sizeX, int sizeY, int nbPlayer);
  ~Graphic(void);

  virtual bool		initialize();
  virtual bool		update(void);
  virtual void		draw(void);
  double		getElapsed(void) const;
  const Map		&getMap(void) const;
  int			menu(void);
  int			pause(void);
  void			camUpdate(void);
};

#endif		/* !GRAPHIC_HPP_ */
