//
// Entity.cpp for Bomberman in /home/boisso_c/rendu/cpp_bomberman/src
// 
// Made by Christian Boisson
// Login   <boisso_c@epitech.net>
// 
// Started on  Sun May 24 16:13:12 2015 Christian Boisson
// Last update Fri Jun 12 12:09:26 2015 Christian Boisson
//

#include		"Entity.hpp"

Entity::Entity()
{

}

Entity::Entity(const Entity &old) : m_pos(old.m_pos), m_isSolid(old.m_isSolid)
{

}

Entity::~Entity()
{
  delete m_tex;
}

void			Entity::setPosition(Position pos)
{
  m_tex->translate(glm::vec3(pos.getX() - m_pos.getX(), 0, pos.getY() - m_pos.getY()));
  m_pos = pos;
}

void			Entity::setIsSolid(bool isSolid)
{
  m_isSolid = isSolid;
}

Position		Entity::getPosition(void) const
{
  return (m_pos);
}

std::string		Entity::toString(void) const
{
  return (ENTITY_STR);
}

bool			Entity::canMoveToPos(std::list<Entity *> entitys)
{
  std::list<Entity *>::iterator it = entitys.begin();

  while (it != entitys.end())
    {
      if ((*it)->isSolid(this))
	return (false);
      ++it;
    }
  return (true);
}
