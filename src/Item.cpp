//
// Item.cpp for bomberman in /home/boisso_c/rendu/cpp_bomberman/src
// 
// Made by Christian Boisson
// Login   <boisso_c@epitech.net>
// 
// Started on  Tue May 26 11:31:13 2015 Christian Boisson
// Last update Sun Jun 14 23:07:43 2015 rousse_3
//

#include		<iostream>
#include		"Item.hpp"
#include		"Graphics/Bonus.hpp"

Item::Item(void) : m_rangeModifier(0), m_timerModifier(0), m_canBeMovedModifier(false), m_moveSpeedModifier(0), m_maxAmmoModifier(0), m_protected(2)
{
  m_tex = new Bonus(0, 0, 0, 1, 1, 1);
  m_tex->initialize();
}

Item::Item(bool canBeMovedModifier) : m_rangeModifier(0), m_timerModifier(0), m_canBeMovedModifier(canBeMovedModifier), m_moveSpeedModifier(0), m_maxAmmoModifier(0), m_protected(2)
{
  m_tex = new Bonus(0, 0, 0, 1, 1, 1);
  m_tex->initialize();
}

Item::Item(double modifier, eModifier type) : m_rangeModifier(0), m_timerModifier(0), m_canBeMovedModifier(false), m_moveSpeedModifier(0), m_maxAmmoModifier(0), m_protected(2)
{
  switch (type)
    {
    case RANGE:
      m_rangeModifier = modifier;
      break;
    case TIMER:
      m_timerModifier = modifier;
      break;
    case SPEED:
      m_moveSpeedModifier = modifier;
      break;
    case AMMO:
      m_maxAmmoModifier = modifier;
      break;
    default:
      break;
    }
  m_tex = new Bonus(0, 0, 0, 1, 1, 1);
  m_tex->initialize();
}

Item::Item(int modifier, eModifier type) : m_rangeModifier(0), m_timerModifier(0), m_canBeMovedModifier(false), m_moveSpeedModifier(0), m_maxAmmoModifier(0), m_protected(2)
{
  switch (type)
    {
    case RANGE:
      m_rangeModifier = modifier;
      break;
    case TIMER:
      m_timerModifier = modifier;
      break;
    case SPEED:
      m_moveSpeedModifier = modifier;
      break;
    case AMMO:
      m_maxAmmoModifier = modifier;
      break;
    default:
      break;
    }
  m_tex = new Bonus(0, 0, 0, 1, 1, 1);
  m_tex->initialize();
}

Item::Item(int rangeModifier, double timerModifier, bool canBeMovedModifier, int moveSpeedModifier, int maxAmmoModifier) : m_rangeModifier(rangeModifier), m_timerModifier(timerModifier), m_canBeMovedModifier(canBeMovedModifier), m_moveSpeedModifier(moveSpeedModifier), m_maxAmmoModifier(maxAmmoModifier), m_protected(2)
{
  m_tex = new Bonus(0, 0, 0, 1, 1, 1);
  m_tex->initialize();
}

Item::Item(const Item &old) : Entity(old), m_rangeModifier(old.m_rangeModifier), m_timerModifier(old.m_timerModifier), m_canBeMovedModifier(old.m_canBeMovedModifier), m_moveSpeedModifier(old.m_moveSpeedModifier), m_maxAmmoModifier(old.m_maxAmmoModifier), m_protected(old.m_protected)
{
  m_tex = new Bonus(0, 0, 0, 1, 1, 1);
  m_tex->initialize();
}

Item::~Item()
{

}

void			Item::pickedUp(Entity *picker, Map &gameMap)
{
  if (picker->upgrade(this))
    {
      gameMap.addToUpdate(this, m_pos);
      m_pos.setPosition(-1, -1, 0);
    }
}

int			Item::getRangeModifier(void) const
{
  return (m_rangeModifier);
}

double			Item::getTimerModifier(void) const
{
  return (m_timerModifier);
}

bool			Item::getCanBeMovedModifier(void) const
{
  return (m_canBeMovedModifier);
}

int			Item::getMoveSpeedModifier(void) const
{
  return (m_moveSpeedModifier);
}

int			Item::getMaxAmmoModifier(void) const
{
  return (m_maxAmmoModifier);
}

void			Item::setRangeModifier(int rangeModifier)
{
  m_rangeModifier = rangeModifier;
}

void			Item::setTimerModifier(double timerModifier)
{
  m_timerModifier = timerModifier;
}

void			Item::setCanBeMovedModifier(bool canBeMovedModifier)
{
  m_canBeMovedModifier = canBeMovedModifier;
}

void			Item::setMoveSpeedModifier(int moveSpeedModifier)
{
  m_moveSpeedModifier = moveSpeedModifier;
}

void			Item::setMaxAmmoModifier(int maxAmmoModifier)
{
  m_maxAmmoModifier = maxAmmoModifier;
}

std::string		Item::toString(void) const
{
  return (ITEM_STR);
}

void			Item::update(gdl::Clock const &clock, Map &gameMap, gdl::Input &input)
{
  (void) input;
  std::string		playerString(PLAYER_STR);
  bool			next = true;

  m_protected -= clock.getElapsed();
  if (gameMap.checkForEntity(m_pos.getX(), m_pos.getY(), 0, playerString))
    {
      std::list<Entity *>	entitys = gameMap.getEntitysAtPos(m_pos.getX(), m_pos.getY());
      std::list<Entity *>::iterator it = entitys.begin();
      while (it != entitys.end() && next)
	{
	  if ((*it)->toString().compare(playerString) == 0)
	    {
	      pickedUp(*it, gameMap);
	      next = false;
	    }
	  ++it;
	}
    }
}

void			Item::draw(gdl::AShader &shader, gdl::Clock const &clock)
{
  m_tex->draw(shader, clock);
}

bool			Item::upgrade(Item *up)
{
  (void) up;
  return (false);
}

bool			Item::isSolid(Entity *pusher)
{
  (void) pusher;
  return (false);
}

void			Item::explode(Map &gameMap)
{
  if (m_protected < 0)
    {
      gameMap.addToUpdate(this, m_pos);
      m_pos.setPosition(-1, -1, 0);
    }
}
