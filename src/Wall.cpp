//
// Wall.cpp for bomberman in /home/boisso_c/rendu/cpp_bomberman/src
// 
// Made by Christian Boisson
// Login   <boisso_c@epitech.net>
// 
// Started on  Tue May 26 13:00:31 2015 Christian Boisson
// Last update Sun Jun 14 23:06:56 2015 rousse_3
//

#include		<stdlib.h>
#include		"Wall.hpp"
#include		"Graphics/Cube.hpp"
#include		"Graphics/Model.hpp"

Wall::Wall(bool canBeBreak) : m_canBeBreak(canBeBreak), m_canDrop(false)
{
  m_drop = NULL;
  m_tex = new Cube(0, 0, 0, 1, 1, 1, 0.4, 0.4, 0.4);
  m_tex->initialize();
}

Wall::Wall(DropTable *drop, bool canBeBreak) : m_canBeBreak(canBeBreak), m_canDrop(true)
{
  m_drop = selectDrop(drop);
  m_tex = new Cube(0, 0, 0, 1, 1, 1, 1, 1, 1);
  m_tex->initialize();
}

Wall::Wall(const Wall &old) : Entity(old), m_canBeBreak(old.m_canBeBreak), m_canDrop(old.m_canDrop)
{
  m_drop = old.m_drop;
}

Wall::~Wall(void)
{

}

bool			Wall::canBeBreak(void) const
{
  return (m_canBeBreak);
}

bool			Wall::canDrop(void) const
{
  return (m_canDrop);
}

Item			*Wall::getDropedItem(void) const
{
  return (m_drop);
}

void			Wall::setCanBeBreak(bool canBeBreak)
{
  m_canBeBreak = canBeBreak;
}

std::string		Wall::toString(void) const
{
  return ("Wall");
}

void			Wall::update(gdl::Clock const &clock, Map &gameMap, gdl::Input &input)
{
  (void) clock;
  (void) gameMap;
  (void) input;
}

void			Wall::draw(gdl::AShader &shader, gdl::Clock const &clock)
{
  m_tex->draw(shader, clock);
}

bool			Wall::upgrade(Item *up)
{
  (void) up;
  return (false);
}

bool			Wall::isSolid(Entity *pusher)
{
  (void) pusher;
  return (true);
}

void			Wall::explode(Map &gameMap)
{
  if (m_canBeBreak)
    {
      if (m_canDrop && m_drop != NULL)
	{
	  Position	pos;

	  pos.setPosition(m_pos.getX(), m_pos.getY(), 0);
	  m_drop->setPosition(pos);
	  gameMap.addEntityAtPos(m_pos.getX(), m_pos.getY(), m_drop);
	}
      gameMap.addToUpdate(this, m_pos);
      m_pos.setPosition(-1, -1, 0);
    }
}

Item			*Wall::selectDrop(DropTable *drop)
{
  if (drop)
    {
      m_drop = drop->randItem();
      return (m_drop);
    }
  return (NULL);
}
