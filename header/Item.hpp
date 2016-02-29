//
// Item.hpp for bomberman in /home/boisso_c/rendu/cpp_bomberman/header
// 
// Made by Christian Boisson
// Login   <boisso_c@epitech.net>
// 
// Started on  Tue May 19 12:49:59 2015 Christian Boisson
// Last update Fri Jun 12 11:45:57 2015 Christian Boisson
//

#ifndef			ITEM_HPP
# define		ITEM_HPP

# include		"Entity.hpp"
# include		"Map.hpp"

# define		ITEM_STR	"Item"

enum			eModifier
  {
    RANGE,
    TIMER,
    SPEED,
    AMMO
  };

class			Item : public Entity
{
public:
  Item(void);
  Item(bool canBeMovedModifier);
  Item(double modifier, eModifier type);
  Item(int modifier, eModifier type);
  Item(int rangeModifier = 0, double timerModifier = 0, bool canBeMovedModifier = false, int moveSpeedModifier = 0, int maxAmmoModifier = 0);
  Item(const Item &old);
  virtual ~Item(void);
  void			pickedUp(Entity *picker, Map &gameMap); /* Appelle la fonction "bool upgrade()" de l'entité si "upgrade()" retourne "vrai" l'Item est libéré (délivré) */
  int			getRangeModifier(void) const;
  double		getTimerModifier(void) const;
  bool			getCanBeMovedModifier(void) const;
  int			getMoveSpeedModifier(void) const;
  int			getMaxAmmoModifier(void) const;
  void			setRangeModifier(int rangeModifier);
  void			setTimerModifier(double timerModifier);
  void			setCanBeMovedModifier(bool canBeMovedModifier);
  void			setMoveSpeedModifier(int moveSpeedModifier);
  void			setMaxAmmoModifier(int maxAmmoModifier);
  virtual std::string	toString(void) const;
  virtual void		update(gdl::Clock const &clock, Map &gameMap, gdl::Input &input);
  virtual void		draw(gdl::AShader &shader, gdl::Clock const &clock);
  virtual bool		upgrade(Item *up);
  virtual bool		isSolid(Entity *pusher);
  virtual void		explode(Map &gameMap);
private:
  int			m_rangeModifier;	/* Valeur de MODIFICATION de la range de la bombe */
  double		m_timerModifier;	/* Valeur de MODIFICATION du timer de la bombe */
  bool			m_canBeMovedModifier;	/* Valeur de canBeMoved de la bombe */
  int			m_moveSpeedModifier;	/* Valeur de MODIFICATION du move speed du joueur */
  int			m_maxAmmoModifier;	/* Valeur de MODIFICATION du montant d'ammo du joueur */
  double		m_protected;
};

#endif			/* ITEM_HPP */
