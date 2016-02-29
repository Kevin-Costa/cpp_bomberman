//
// Position.cpp for bomberman in /home/boisso_c/rendu/cpp_bomberman/src
// 
// Made by Christian Boisson
// Login   <boisso_c@epitech.net>
// 
// Started on  Sun May 24 14:13:44 2015 Christian Boisson
// Last update Thu Jun 11 16:52:14 2015 Christian Boisson
//

#include		"Position.hpp"

Position::Position() : m_x(0), m_y(0), m_z(0), m_direction(UNDEFINED)
{

}

Position::Position(int x, int y, int z, eDirection direction) : m_x(x), m_y(y), m_z(z), m_direction(direction)
{

}

Position::Position(const Position &old) : m_x(old.m_x), m_y(old.m_y), m_z(old.m_z), m_direction(old.m_direction)
{

}

Position::~Position()
{

}

int			Position::getX(void) const
{
  return (m_x);
}

int			Position::getY(void) const
{
  return (m_y);
}

int			Position::getZ(void) const
{
  return (m_z);
}

eDirection		Position::getDirection(void) const
{
  return (m_direction);
}

void			Position::setPosition(int x, int y, int z)
{
  int			deltaX;
  int			deltaY;

  deltaX = x - m_x;
  deltaY = y - m_y;
  if ((ABS(deltaX)) > (ABS(deltaY)))
    {
      if (deltaX > 0)
  	m_direction = BOTTOM;
      else
  	m_direction = TOP;
    }
  else if ((ABS(deltaX)) < (ABS(deltaY)))
    {
      if (deltaY > 0)
  	m_direction = RIGHT;
      else
  	m_direction = LEFT;
    }
  m_x = x;
  m_y = y;
  m_z = z;
}

void			Position::setX(int x)
{
  m_x = x;
}

void			Position::setY(int y)
{
  m_y = y;
}

void			Position::setZ(int z)
{
  m_z = z;
}

void			Position::setDirection(eDirection direction)
{
  m_direction = direction;
}

void			Position::moveRight(int d)
{
  m_x += d;
  m_direction = RIGHT;
}

void			Position::moveLeft(int d)
{
  m_x -= d;
  m_direction = LEFT;
}

void			Position::moveDown(int d)
{
  m_y += d;
  m_direction = BOTTOM;
}

void			Position::moveUp(int d)
{
  m_y -= d;
  m_direction = TOP;
}
