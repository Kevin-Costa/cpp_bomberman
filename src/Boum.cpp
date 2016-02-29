//
// Boum.cpp for bomberman in /home/boisso_c/rendu/cpp_bomberman/src
// 
// Made by Christian Boisson
// Login   <boisso_c@epitech.net>
// 
// Started on  Tue May 26 11:28:14 2015 Christian Boisson
// Last update Fri Jun 12 12:08:49 2015 Christian Boisson
//

#include		<iostream>
#include		"Boum.hpp"
#include		"Graphics/Explosion.hpp"
#include		"Map.hpp"
#include		"Wall.hpp"

Boum::Boum(void) : m_timer(1.5)
{
  m_tex = new Explosion(0, 0, 0, 1, 1, 1, 1, 0, 0);
  m_tex->initialize();
  m_owner = NULL;
}

Boum::Boum(Player *owner) : m_timer(1.5)
{
  m_tex = new Explosion(0, 0, 0, 1, 1, 1, 1, 0, 0);
  m_tex->initialize();
  m_owner = owner;
}

Boum::Boum(const Boum &old) : Entity(old), m_timer(old.m_timer)
{
  m_owner = old.m_owner;
}

Boum::~Boum(void)
{

}

std::string		Boum::toString(void) const
{
  return ("Boum");
}

Player			*Boum::getOwner(void) const
{
  return (m_owner);
}

void			Boum::setOwner(Player *owner)
{
  m_owner = owner;
}

void			Boum::update(gdl::Clock const &clock, Map &gameMap, gdl::Input &input)
{
  (void) input;
  alertEntitys(gameMap);
  m_timer -= clock.getElapsed();
  if (m_timer <= 0)
    {
      gameMap.addToUpdate(this, m_pos);
      m_pos.setPosition(-1, -1, 0);
    }
}

void			Boum::draw(gdl::AShader &shader, gdl::Clock const &clock)
{
  m_tex->draw(shader, clock);
}

bool			Boum::upgrade(Item *up)
{
  (void) up;
  return (false);
}

bool			Boum::isSolid(Entity *pusher)
{
  (void) pusher;
  return (false);
}

void			Boum::explode(Map &gameMap)
{
  (void) gameMap;
}

void			Boum::alertEntitys(Map &gameMap)
{
  std::list<Entity *>	entitys = gameMap.getEntitysAtPos(m_pos.getX(), m_pos.getY());
  std::list<Entity *>::iterator it = entitys.begin();

  std::string		playerString(PLAYER_STR);
  std::string		wallString(WALL_STR);

  if (m_owner)
    {
      if (gameMap.checkForEntity(m_pos.getX(), m_pos.getY(), 0, wallString))
	{
	  while (it != entitys.end())
	    {
	      if ((*it)->toString().compare(WALL_STR) == 0)
		if ((reinterpret_cast<Wall *>(*it))->canBeBreak())
		  m_owner->addScore(5);
	      ++it;
	    }
	}
      else if (gameMap.checkForEntity(m_pos.getX(), m_pos.getY(), 0, playerString))
	{
	  it = entitys.begin();
	  while (it != entitys.end())
	    {
	      if ((*it)->toString().compare(PLAYER_STR) == 0 && ((*it) != m_owner))
		if (reinterpret_cast<Player *>(*it)->isAlive())
		  m_owner->addScore(100);
	      ++it;
	    }
	}
    }
  it = entitys.begin();
  while (it != entitys.end())
    {
      (*it)->explode(gameMap);
      ++it;
    }
}
