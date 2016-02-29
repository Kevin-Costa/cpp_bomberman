//
// Player.cpp for bomberman in /home/boisso_c/rendu/cpp_bomberman/src
// 
// Made by Christian Boisson
// Login   <boisso_c@epitech.net>
// 
// Started on  Sun May 24 15:20:49 2015 Christian Boisson
// Last update Sun Jun 14 22:22:51 2015 rousse_3
//

#include		<iostream>
#include		"Input.hh"
#include		"SdlContext.hh"
#include		"Graphics/Model.hpp"
#include		"Graphics/Rip.hpp"
#include		"Player.hpp"

unsigned int		newId(void)
{
  static unsigned int	id = 0;

  ++id;
  return (id);
}

Player::Player(int tab[5], const std::string &name, unsigned int id) : m_name(name), m_id(id), m_alive(true), m_ammo(1), m_ref(this), m_moveSpeed(100), m_canPush(false), m_score(0), m_time(0)
{
  m_keys[0].first = tab[0];
  m_keys[1].first = tab[1];
  m_keys[2].first = tab[2];
  m_keys[3].first = tab[3];
  m_keys[4].first = tab[4];
  m_keys[0].second = &Player::moveUp;
  m_keys[1].second = &Player::moveDown;
  m_keys[2].second = &Player::moveLeft;
  m_keys[3].second = &Player::moveRight;
  m_keys[4].second = &Player::putBomb;
  m_tex = (new Model(0, 0, 0, 0.002, 0.002, 0.002));
  m_tex->initialize();
}

Player::Player(const Player &old) : Entity(old), m_name(old.m_name), m_id(old.m_id), m_alive(old.m_alive), m_ammo(old.m_ammo), m_ref(old.m_ref), m_moveSpeed(old.m_moveSpeed), m_canPush(false), m_score(0), m_time(0)
{

}

Player::~Player()
{

}

std::string		Player::getName(void) const
{
  return (m_name);
}

unsigned int		Player::getID(void) const
{
  return (m_id);
}

unsigned int		Player::getScore(void) const
{
  return (m_score);
}

bool			Player::isAlive(void) const
{
  return (m_alive);
}

int			Player::getAmmo(void) const
{
  return (m_ammo);
}

Bomb			*Player::getRef(void)
{
  return (&m_ref);
}

int			Player::getMoveSpeed(void) const
{
  return (m_moveSpeed);
}

bool			Player::getCanPush(void) const
{
  return (m_canPush);
}

void			Player::addScore(unsigned int score)
{
  m_score += score;
}

void			Player::setScore(unsigned int score)
{
  m_score = score;
}

void			Player::setKeys(int tab[5])
{
  m_keys[0].first = tab[0];
  m_keys[1].first = tab[1];
  m_keys[2].first = tab[2];
  m_keys[3].first = tab[3];
  m_keys[4].first = tab[4];
}

void			Player::setName(const std::string &name)
{
  m_name = name;
}

void			Player::setID(unsigned int ID)
{
  m_id = ID;
}

void			Player::setAlive(bool alive)
{
  m_alive = alive;
}

void			Player::setAmmo(int ammo)
{
  m_ammo = ammo;
}

void			Player::setRef(Bomb ref)
{
  m_ref = ref;
}

void			Player::setMoveSpeed(int moveSpeed)
{
  m_moveSpeed = moveSpeed;
}

void			Player::setCanPush(bool canPush)
{
  m_canPush = canPush;
}

void			Player::putBomb(Map &gameMap)
{
  std::string		bombString(BOMB_STR);

  if (m_ammo > 0)
    {
      if (!(gameMap.checkForEntity(m_pos.getX(), m_pos.getY(), 0, bombString)))
	{
	  Bomb		*newBomb;
	  Position	pos;

	  newBomb = new Bomb(m_ref);
	  pos.setPosition(m_pos.getX(), m_pos.getY(), 0);
	  newBomb->setPosition(pos);
	  gameMap.addEntityAtPos(m_pos.getX(), m_pos.getY(), newBomb);
	  --m_ammo;
	}
    }
}

static void		rotate_face(Position &pos, AObject *tex)
{
  eDirection		rotate = pos.getDirection();

  tex->translate(glm::vec3(-pos.getX(), -pos.getZ(), -pos.getY()));
  switch(rotate)
    {
    case TOP:
      tex->rotate(glm::vec3(0, 1, 0), 180);
      break;
    case RIGHT:
      tex->rotate(glm::vec3(0, 1, 0), 270);
      break;
    case LEFT:
      tex->rotate(glm::vec3(0, 1, 0), 90);
      break;
    default:
      break;
    }
  tex->translate(glm::vec3(pos.getX(), pos.getZ(), pos.getY()));
}

void			Player::moveRight(Map &gameMap)
{
  int			posX = m_pos.getX() + 1;
  int			posY = m_pos.getY();
  std::list<Entity *>	entitys;

  if (posX >= 0 && posX < gameMap.getSizeX())
    {
      entitys = gameMap.getEntitysAtPos(posX, posY);
      if (canMoveToPos(entitys))
	{
	  gameMap.addToUpdate(this, m_pos);
	  rotate_face(m_pos, m_tex);
	  m_pos.moveRight();
	  m_tex->translate(glm::vec3(1, 0, 0));
	  m_tex->translate(glm::vec3(-m_pos.getX(), -m_pos.getZ(), -m_pos.getY()));
	  m_tex->rotate(glm::vec3(0, 1, 0), -270);
	  m_tex->translate(glm::vec3(m_pos.getX(), m_pos.getZ(), m_pos.getY()));
	}
    }
}

void			Player::moveLeft(Map &gameMap)
{
  int			posX = m_pos.getX() - 1;
  int			posY = m_pos.getY();
  std::list<Entity *>	entitys;

  if (posX >= 0 && posX < gameMap.getSizeX())
    {
      entitys = gameMap.getEntitysAtPos(posX, posY);
      if (canMoveToPos(entitys))
	{
	  gameMap.addToUpdate(this, m_pos);
	  rotate_face(m_pos, m_tex);
	  m_pos.moveLeft();
	  m_tex->translate(glm::vec3(-1, 0, 0));
	  m_tex->translate(glm::vec3(-m_pos.getX(), -m_pos.getZ(), -m_pos.getY()));
	  m_tex->rotate(glm::vec3(0, 1, 0), -90);
	  m_tex->translate(glm::vec3(m_pos.getX(), m_pos.getZ(), m_pos.getY()));
	}
    }
}

void			Player::moveDown(Map &gameMap)
{
  int			posX = m_pos.getX();
  int			posY = m_pos.getY() + 1;
  std::list<Entity *>	entitys;

  if (posY >= 0 && posY < gameMap.getSizeY())
    {
      entitys = gameMap.getEntitysAtPos(posX, posY);
      if (canMoveToPos(entitys))
	{
	  gameMap.addToUpdate(this, m_pos);
	  rotate_face(m_pos, m_tex);
	  m_pos.moveDown();
	  m_tex->translate(glm::vec3(0, 0, 1));
	}
    }
}

void			Player::moveUp(Map &gameMap)
{
  int			posX = m_pos.getX();
  int			posY = m_pos.getY() - 1;
  std::list<Entity *>	entitys;

  if (posY >= 0 && posY < gameMap.getSizeY())
    {
      entitys = gameMap.getEntitysAtPos(posX, posY);
      if (canMoveToPos(entitys))
	{
	  gameMap.addToUpdate(this, m_pos);
	  rotate_face(m_pos, m_tex);
	  m_pos.moveUp();
	  m_tex->translate(glm::vec3(0, 0, -1));
	  m_tex->translate(glm::vec3(-m_pos.getX(), -m_pos.getZ(), -m_pos.getY()));
	  m_tex->rotate(glm::vec3(0, 1, 0), -180);
	  m_tex->translate(glm::vec3(m_pos.getX(), m_pos.getZ(), m_pos.getY()));
	}
    }
}

void			Player::incrementAmmo(void)
{
  ++m_ammo;
}

std::string		Player::toString(void) const
{
  return ("Player");
}

void			Player::update(gdl::Clock const &clock, Map &gameMap, gdl::Input &input)
{
  int			i = 0;

  m_time += clock.getElapsed();
  if (m_time >= ((0.70 / 100) * m_moveSpeed))
    {
      if (m_alive && m_keys[i].first != -1)
	{
	  while (i != 5)
	    {
	      if (m_keys[i].first != -1)
		{
		  if (input.getInput(m_keys[i].first))
		    {
		      (this->*m_keys[i].second)(gameMap);
		      m_time = 0;
		    }
		  ++i;
		}
	    }
	}
      else if (m_alive)
	{
	  int		action = rand() % 30;

	  action -= 25;
	  if (action < 0)
	    return;
	  else
	    (this->*m_keys[action].second)(gameMap);
	}
    }
}

void			Player::draw(gdl::AShader &shader, gdl::Clock const &clock)
{
  m_tex->draw(shader, clock);
}

bool			Player::upgrade(Item *up)
{
  m_ref.setRange(m_ref.getRange() + up->getRangeModifier());
  m_ref.setTimer(m_ref.getTimer() + up->getTimerModifier());
  if (up->getCanBeMovedModifier())
    m_canPush = true;
  m_moveSpeed += up->getMoveSpeedModifier();
  m_ammo += up->getMaxAmmoModifier();
  return (true);
}

bool			Player::isSolid(Entity *pusher)
{
  (void) pusher;
  return (false);
}

void			Player::explode(Map &gameMap)
{
  (void) gameMap;
  if (m_alive == true)
    {
      m_alive = false;
      delete m_tex;
      m_tex = new Rip(m_pos.getX(), m_pos.getZ(), m_pos.getY(), 1, 1, 1);
      m_tex->initialize();
      // std::cout << "Player " << m_id << " dead." << std::endl;
    }
}
