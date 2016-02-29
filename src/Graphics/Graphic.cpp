//
// Graphic.cpp for  in /home/degand/Projects/bombe_graphic/src
// 
// Made by Alaric
// Login   <degand@epitech.net>
// 
// Started on  Mon Jun  1 17:43:20 2015 Alaric
// Last update Sun Jun 14 23:07:28 2015 rousse_3
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

#include	<iostream>
#include	<stdexcept>

#include	"Player.hpp"
#include	"Wall.hpp"
#include	"Save.hpp"
#include	"Graphics/Cube.hpp"
#include	"Graphics/Pause.hpp"
#include	"Graphics/Plan.hpp"
#include	"Graphics/Ground.hpp"
#include	"Graphics/Model.hpp"
#include	"Graphics/Bombe.hpp"
#include	"Graphics/Graphic.hpp"
#include	"Graphics/TextureLoader.hpp"

Graphic::Graphic(int sizeX, int sizeY, int nbPlayer) : _sizeX(sizeX), _sizeY(sizeY), _orientation(1), _stop(false)
{
  initialize();
  TextureLoader		&load = TextureLoader::getInstance();
  std::cout << "Loading Texture" << std::endl;

  if (load.load("Bombe", "./LibBomberman_linux_x64/assets/marvin.fbm/Main_texture_diffuse2.tga") != true)
    throw std::runtime_error("Cannot load the texture");
  if (load.load("Explosion", "./LibBomberman_linux_x64/assets/flame.tga") != true)
    throw std::runtime_error("Cannot load the texture");
  if (load.load("Dead", "./LibBomberman_linux_x64/assets/rip.tga") != true)
    throw std::runtime_error("Cannot load the texture");
  if (load.load("Item", "./LibBomberman_linux_x64/assets/Bonus.tga") != true)
    throw std::runtime_error("Cannot load the texture");
  if (load.load("Wall", "./LibBomberman_linux_x64/assets/wall.tga") != true)
    throw std::runtime_error("Cannot load the texture");
  if (load.load("Player", "./LibBomberman_linux_x64/assets/marvin.fbm/Main_texture_diffuse2.tga") != true)
    throw std::runtime_error("Cannot load the texture");
  if (load.load("Ground", "./LibBomberman_linux_x64/assets/sol.tga") != true)
    throw std::runtime_error("Cannot load the texture");

  int	i = menu();
  if (i == 0 || i == 1)
    {
      _camX = _sizeX / 2;
      _camY = 30;
      _camZ = 3 * _sizeY / 4;
      _orientation = sizeY / 2 - 3 * _sizeY / 4;
      
      _map = new Map(sizeX, sizeY);
      _ground = new Ground(static_cast<double>(sizeX - 1) / 2, 0, static_cast<double>(sizeY - 1) / 2, sizeX, 1, sizeY);
      _ground->initialize();
  
      int		idx = 1;
      int		tab[5];
      std::vector<Player*>	tabPlayer;
      
      tab[0] = SDLK_UP;
      tab[1] = SDLK_DOWN;
      tab[2] = SDLK_LEFT;
      tab[3] = SDLK_RIGHT;
      tab[4] = SDLK_SPACE;
      tabPlayer.push_back(new Player(tab));
      if (i == 1)
	{
	  tab[0] = SDLK_z;
	  tab[1] = SDLK_s;
	  tab[2] = SDLK_q;
	  tab[3] = SDLK_d;
	  tab[4] = SDLK_x;
	  tabPlayer.push_back(new Player(tab));
	  idx++;
	}
      tab[0] = -1;
      tab[1] = -1;
      tab[2] = -1;
      tab[3] = -1;
      tab[4] = -1;
      while (idx < nbPlayer)
	{
	  tabPlayer.push_back(new Player(tab));
	  idx++;
	}
      _map->placePlayer(nbPlayer, tabPlayer);
    }
  else if (i == 2)
    {
      std::cerr << "404 feature Not found" << std::endl;
      _stop = true;
    }
  else
    _stop = true;
}

Graphic::~Graphic(void)
{
  if (!_stop)
    {
      delete _map;
      delete _ground;
    }
}

const Map &Graphic::getMap(void) const
{
  return (*_map);
}

bool Graphic::initialize()
{
  if (!this->_init.start(900, 900, "My bomberman!"))
    return false;
  glEnable(GL_DEPTH_TEST);
  if (!this->_shader.load("./LibBomberman_linux_x64/shaders/basic.fp", GL_FRAGMENT_SHADER) || !this->_shader.load("./LibBomberman_linux_x64/shaders/basic.vp", GL_VERTEX_SHADER) || !this->_shader.build())
    return false;
  glm::mat4 projection;
  projection = glm::perspective(60.0f, 900.0f / 900.0f, 0.1f, 100.0f);
  this->_shader.bind();
  this->_shader.setUniform("projection", projection);
  return true;
}

void		Graphic::camUpdate(void)
{
  glm::mat4 transformation;
  glm::mat4 projection;

  projection = glm::perspective(60.0f, 900.0f / 900.0f, 0.1f, 100.0f);
  transformation = glm::lookAt(glm::vec3(_camX, _camY, _camZ), glm::vec3(_camX, 0, _camZ + _orientation), glm::vec3(0, 1, 0));
  this->_shader.setUniform("projection", projection);
  this->_shader.setUniform("view", transformation);
}

bool		Graphic::update(void)
{
  if (_stop)
    return (false);
  if (_map->gameIsEnd())
    {
      _map->dumpScore();
      return (false);
    }
  this->_init.updateClock(this->_clock);
  this->_init.updateInputs(this->_input);
  if (this->_input.getKey(SDLK_ESCAPE))
    {
      int		i = pause();

      if (i == 1)
	{
	  Save		save;
  
	  save.FileWriting(save.CheckFileExist(), getMap());
	}
      else if (i == 2)
	return (false);

    }
  if (this->_input.getInput(SDL_QUIT))
    {
      return (false);
    }
  _map->update(_clock, _input);
  camUpdate();
  return (true);
}

void		Graphic::draw(void)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  this->_shader.bind();
  _map->draw(_shader, _clock);
  _ground->draw(_shader, _clock);
  this->_init.flush();
}

double		Graphic::getElapsed(void) const
{
  return (_clock.getElapsed());
}

int		Graphic::menu(void)
{
  int i = 0;
  AObject *plan = new Plan(0, 0, 0, 23, 23, 23);
  AObject *cursor = new Bombe(1.4, 22, -3.2, 0.003, 0.003, 0.003);

  _camX = 0;
  _camY = 32;
  _camZ = 1;
  _orientation = -1;
  camUpdate();
  if (plan->initialize() == false)
    return (3);
  if (cursor->initialize() == false)
    return (3);
  plan->rotate(glm::vec3(1, 0, 0), 1);
  while (1)
    {
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
      this->_shader.bind();
      plan->draw(this->_shader, this->_clock);
      cursor->draw(this->_shader, this->_clock);
      this->_init.flush();
      if (this->_input.getKey(SDL_QUIT, true) || this->_input.getKey(SDLK_ESCAPE, true))
	return (3);
      if (this->_input.getKey(SDLK_UP, true))
	{
	  i--;
	  cursor->translate(glm::vec3(0, 0, -1.655));
	}
      if (this->_input.getKey(SDLK_DOWN, true))
	{
	  i++;
	  cursor->translate(glm::vec3(0, 0, 1.655));
	}
      if (i < 0)
	{
	  i = 3;
	  cursor->translate(glm::vec3(0, 0, 1.655 * 4));
	}
      if (i > 3)
	{
	  i = 0;
	  cursor->translate(glm::vec3(0, 0, -1.655 * 4));
	}
      if (this->_input.getKey(SDLK_RETURN, true))
	return (i);
      this->_init.updateClock(this->_clock);
      this->_init.updateInputs(this->_input);
    }
}

int		Graphic::pause(void)
{
  int		i = 0;
  int		oldX = _camX;
  int		oldY = _camY;
  int		oldZ = _camZ;
  int		oldO = _orientation;
  AObject *plan = new Pause(0, 0, 0, 23, 23, 23);
  AObject *cursor = new Bombe(1.4, 22, -2.8, 0.003, 0.003, 0.003);
  glm::mat4 transformation;

  _camX = 0;
  _camY = 32;
  _camZ = 1;
  _orientation = -1;
  camUpdate();
  if (plan->initialize() == false)
    return (2);
  if (cursor->initialize() == false)
    return (2);
  while (1)
    {
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
      this->_shader.bind();
      plan->draw(this->_shader, this->_clock);
      cursor->draw(this->_shader, this->_clock);
      this->_init.flush();
      if (this->_input.getKey(SDL_QUIT, true))
	return (2);
      if (this->_input.getKey(SDLK_UP, true))
	{
	  i--;
	  cursor->translate(glm::vec3(0, 0, -1.7));
	}
      if (this->_input.getKey(SDLK_DOWN, true))
	{
	  i++;
	  cursor->translate(glm::vec3(0, 0, 1.7));
	}
      if (i < 0)
	{
	  i = 2;
	  cursor->translate(glm::vec3(0, 0, 1.7 * 3));
	}
      if (i > 2)
	{
	  i = 0;
	  cursor->translate(glm::vec3(0, 0, -1.7 * 3));
	}
      if (this->_input.getKey(SDLK_RETURN, true))
	{
	  _camX = oldX;
	  _camY = oldY;
	  _camZ = oldZ;
	  _orientation = oldO;
	  camUpdate();
	  return (i);
	}
      this->_init.updateClock(this->_clock);
      this->_init.updateInputs(this->_input);
    }
}
