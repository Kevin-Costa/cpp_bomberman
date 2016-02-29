//
// Bomb.cpp for bomberman in /home/boisso_c/rendu/cpp_bomberman/src
// 
// Made by Christian Boisson
// Login   <boisso_c@epitech.net>
// 
// Started on  Sun May 24 17:15:52 2015 Christian Boisson
// Last update Fri Jun 12 12:37:47 2015 Christian Boisson
//

#include		<iostream>
#include		"Bomb.hpp"
#include		"Map.hpp"
#include		"Boum.hpp"
#include		"Wall.hpp"
#include		"Graphics/Bombe.hpp"
#include		"Graphics/Cube.hpp"

Bomb::Bomb(Player *owner) : m_exploded(false), m_range(2), m_timer(3), m_dX(0), m_dY(0)
{
  m_owner = owner;
  m_tex = new Bombe(0, 0, 0, 0.003, 0.003, 0.003);
  m_tex->initialize();
}

Bomb::Bomb(const Bomb &old) : Entity(old), m_exploded(old.m_exploded), m_range(old.m_range), m_timer(old.m_timer)
{
  m_tex = new Bombe(0, 0, 0, 0.003, 0.003, 0.003);
  m_tex->initialize();
  m_owner = old.m_owner;
}

Bomb::~Bomb()
{
}

bool			Bomb::getState(void) const
{
  return (m_exploded);
}

int			Bomb::getRange(void) const
{
  return (m_range);
}

int			Bomb::getTimer(void) const
{
  return (m_timer);
}

Player			*Bomb::getOwner(void) const
{
  return (m_owner);
}

void			Bomb::setState(bool state)
{
  m_exploded = state;
}

void			Bomb::setRange(int range)
{
  m_range = range;
}

void			Bomb::setTimer(int timer)
{
  m_timer = timer;
}

void			Bomb::setOwner(Player *owner)
{
  m_owner = owner;
}

std::string		Bomb::toString(void) const
{
  return (BOMB_STR);
}

void			Bomb::update(gdl::Clock const &clock, Map &gameMap, gdl::Input &input)
{
  (void) input;
  m_timer -= clock.getElapsed();
  if (m_timer <= 0)
    explode(gameMap);
  if (m_dX != 0 || m_dY != 0)
    slide(gameMap);
}

void			Bomb::draw(gdl::AShader &shader, gdl::Clock const &clock)
{
  m_tex->draw(shader, clock);
}

bool			Bomb::upgrade(Item *up)
{
  (void) up;
  return (false);
}

bool			Bomb::isSolid(Entity *pusher)
{
  std::string		playerString(PLAYER_STR);

  if (pusher->toString() == playerString)
    {
      Player		*push;

      push = reinterpret_cast<Player *>(pusher);
      if (push->getCanPush())
	{
	  if (push->getPosition().getX() < m_pos.getX())
	    m_dX = 1;
	  else if (push->getPosition().getX() > m_pos.getX())
	    m_dX = -1;
	  if (push->getPosition().getY() < m_pos.getY())
	    m_dY = 1;
	  else if (push->getPosition().getY() > m_pos.getY())
	    m_dY = -1;
	  return (false);
	}
    }
  return (true);
}

void			Bomb::explode(Map &gameMap)
{
  if (!m_exploded)
    {
      m_exploded = true;
      m_timer = 0;
      m_dX = 0;
      m_dY = 0;
      putBoumAtBomb(gameMap);
      putBoum(1, 0, gameMap);
      putBoum(-1, 0, gameMap);
      putBoum(0, 1, gameMap);
      putBoum(0, -1, gameMap);
      gameMap.addToUpdate(this, m_pos);
      m_pos.setPosition(-1, -1, 0);
      if (m_owner != NULL)
	m_owner->incrementAmmo();
    }
}

void			Bomb::putBoum(int x, int y, Map &gameMap)
{
  int			tmpX;
  int			tmpY;
  Boum			*newBoum;
  Position		posBoum;
  std::string		wallString(WALL_STR);
  bool			next = true;
  int			i = 1;

  while (i <= m_range && next)
    {
      tmpX = m_pos.getX() + x * i;
      tmpY = m_pos.getY() + y * i;
      if (gameMap.checkForEntity(tmpX, tmpY, 0, wallString))
	next = false;
      newBoum = new Boum(m_owner);
      posBoum.setPosition(tmpX, tmpY, 0);
      newBoum->setPosition(posBoum);
      gameMap.addEntityAtPos(tmpX, tmpY, newBoum);
      ++i;
    }
}

void			Bomb::putBoumAtBomb(Map &gameMap)
{
  Boum			*newBoum;
  Position		posBoum;

  newBoum = new Boum(m_owner);
  posBoum.setPosition(m_pos.getX(), m_pos.getY(), 0);
  newBoum->setPosition(posBoum);
  gameMap.addEntityAtPos(m_pos.getX(), m_pos.getY(), newBoum);
}

void			Bomb::slide(Map &gameMap)
{
  int			newX = m_pos.getX() + m_dX;
  int			newY = m_pos.getY() + m_dY;
  std::list<Entity *>	entitys;

  if (newX >= 0 && newX < gameMap.getSizeX() && newY >= 0 && newY < gameMap.getSizeY())
    {
      entitys = gameMap.getEntitysAtPos(newX, newY);
      if (canMoveToPos(entitys))
	{
	  Position	pos;

	  pos.setPosition(newX, newY, 0);
	  gameMap.addToUpdate(this, m_pos);
	  this->setPosition(pos);
	  //	  m_pos.setPosition(newX, newY, 0);
	}
      else
	{
	  m_dX = 0;
	  m_dY = 0;
	}
    }
}
