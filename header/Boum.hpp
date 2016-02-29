//
// Boum.hpp for Bomberman in /home/rousse_3/rendu/cpp_bomberman/header
// 
// Made by rousse_3
// Login   <rousse_3@epitech.net>
// 
// Started on  Wed May 20 18:26:11 2015 rousse_3
// Last update Fri Jun 12 11:42:46 2015 Christian Boisson
//

#ifndef			BOUM_HPP_
# define		BOUM_HPP_

# include		<Input.hh>
# include		"Entity.hpp"
# include		"Player.hpp"

# define		BOUM_STR	"Boum"

class			Player;

class			Boum : public Entity
{
public:
  Boum(void);
  Boum(Player *owner);
  Boum(const Boum &old);
  virtual ~Boum(void);
  Player		*getOwner(void) const;
  void			setOwner(Player *);
  virtual std::string	toString(void) const;
  virtual void		update(gdl::Clock const &clock, Map &gameMap, gdl::Input &input);
  virtual void		draw(gdl::AShader &shader, gdl::Clock const &clock);
  virtual bool		upgrade(Item *up);
  virtual bool		isSolid(Entity *pusher);
  virtual void		explode(Map &gameMap);
private:
  void			alertEntitys(Map &gameMap);
  double		m_timer; /* Temps d'affichage de l'explosion (ms)*/
  Player		*m_owner;
};

#endif			/* !BOUM_HPP_ */
