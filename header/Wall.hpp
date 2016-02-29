//
// Wall.hpp for bomberman in /home/boisso_c/rendu/cpp_bomberman/header
// 
// Made by Christian Boisson
// Login   <boisso_c@epitech.net>
// 
// Started on  Tue May 19 12:41:47 2015 Christian Boisson
// Last update Fri Jun 12 11:48:32 2015 Christian Boisson
//

#ifndef			WALL_HPP
# define		WALL_HPP

# include		<Input.hh>
# include		"Entity.hpp"
# include		"Item.hpp"

# define		WALL_STR	"Wall"

class			Wall : public Entity
{
public:
  Wall(bool canBeBreak = true);						/* Créé un Wall qui ne peux pas drop (m_drop == NULL)*/
  Wall(DropTable *drop, bool canBeBreak = true);				/* Créé un Wall qui peux drop (cas ou m_drop == NULL présent tout de même) */
  Wall(const Wall &old);
  virtual ~Wall(void);
  bool			canBeBreak(void) const;
  bool			canDrop(void) const;
  Item			*getDropedItem(void) const;
  void			setCanBeBreak(bool canBeBreak);
  virtual std::string	toString(void) const;
  virtual void		update(gdl::Clock const &clock, Map &gameMap, gdl::Input &input);
  virtual void		draw(gdl::AShader &shader, gdl::Clock const &clock);
  virtual bool		upgrade(Item *up);
  virtual bool		isSolid(Entity *pusher);
  virtual void		explode(Map &gameMap);
private:
  Item			*selectDrop(DropTable *drop);

  bool			m_canBeBreak;			/* Définit si le Wall peut être cassé */
  bool			m_canDrop;			/* Définit si le Wall peut drop des Items */
  Item			*m_drop;			/* Définit l'item drop (peut être NULL) (Calculé via DropTable dans le constructeur) */
};

#endif			/* !WALL_HPP */
