//
// Position.hpp for bomberman in /home/boisso_c/rendu/cpp_bomberman/header
// 
// Made by Christian Boisson
// Login   <boisso_c@epitech.net>
// 
// Started on  Tue May 19 12:22:08 2015 Christian Boisson
// Last update Wed Jun  3 13:16:49 2015 Christian Boisson
//

#ifndef			POSITION_HPP
# define		POSITION_HPP

# define		ABS(val)	(val) > 0 ? (val) : (-(val))

enum			eDirection
  {
    TOP,
    LEFT,
    BOTTOM,
    RIGHT,
    UNDEFINED
  };

class			Position
{
public:
  Position(void);
  Position(int x, int y, int z, eDirection direction);
  Position(const Position &old);
  ~Position(void);
  int			getX(void) const;
  int			getY(void) const;
  int			getZ(void) const;
  eDirection		getDirection(void) const;
  void			setPosition(int x, int y, int z); /* Prévoir le changement de Direction via cette fonction en calculant la différence avec les anciennes positions */
  void			setX(int x);
  void			setY(int y);
  void			setZ(int z);
  void			setDirection(eDirection direction);
  void			moveRight(int d = 1);
  void			moveLeft(int d = 1);
  void			moveDown(int d = 1);
  void			moveUp(int d = 1);
private:
  int			m_x;			/* Position en X */
  int			m_y;			/* Position en Y */
  int			m_z;			/* Position en Z */
  eDirection		m_direction;		/* Direction dans laquelle va l'entité */
};

#endif			/* !POSITION_HPP */
