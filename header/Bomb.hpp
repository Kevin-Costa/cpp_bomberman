//
// Bomb.hpp for bomberman in /home/boisso_c/rendu/cpp_bomberman/header
// 
// Made by Christian Boisson
// Login   <boisso_c@epitech.net>
// 
// Started on  Tue May 19 12:35:24 2015 Christian Boisson
// Last update Fri Jun 12 11:42:19 2015 Christian Boisson
//

#ifndef			BOMB_HPP
# define		BOMB_HPP

# include		<string>
# include		<stdlib.h>
# include		<Input.hh>
# include		"Entity.hpp"
# include		"Graphics/Bombe.hpp"

# define		BOMB_STR	"Bomb"
/*
**	Les bombes, comme tout le reste, sont des entités et disposent donc d'une position et d'une texture
*/

class			Map;
class			Player;

class			Bomb : public Entity
{
public:
  Bomb(Player *owner = NULL);
  Bomb(const Bomb &old);
  virtual ~Bomb();
  bool			getState(void) const;
  int			getRange(void) const;
  int			getTimer(void) const;
  Player		*getOwner(void) const;
  void			setState(bool state);
  void			setRange(int range);
  void			setTimer(int timer);
  void			setOwner(Player *owner);
  virtual std::string	toString(void) const;
  virtual void		update(gdl::Clock const &clock, Map &gameMap, gdl::Input &input);
  virtual void		draw(gdl::AShader &shader, gdl::Clock const &clock);
  virtual bool		upgrade(Item *up);
  virtual bool		isSolid(Entity *pusher);	/* Doit vérifier "m_canBeMoved" afin de déplacer la bombe dans ce cas (et donc renvoyer false pour que le Joueur qui pousse avance) */
  virtual void		explode(Map &gameMap);
private:
  void			putBoum(int x, int y, Map &gameMap);
  void			putBoumAtBomb(Map &gameMap);
  void			slide(Map &gameMap);
  bool			m_exploded;			/* Status de la bombe */
  int			m_range;			/* Porté de la bombe */
  double		m_timer;			/* Temps avant l'explosion (ms)*/
  Player		*m_owner;			/* Propriétaire de la bombe */
  int			m_dX;
  int			m_dY;
};

#endif			/* !BOMB_HPP */
