//
// Player.hpp for Bomberman in /home/boisso_c/rendu/cpp_bomberman/header
// 
// Made by Christian Boisson
// Login   <boisso_c@epitech.net>
// 
// Started on  Tue May 19 12:28:33 2015 Christian Boisson
// Last update Sat Jun 13 19:56:58 2015 rousse_3
//

#ifndef			PLAYER_HPP
# define		PLAYER_HPP

# include		<queue>
# include		<string>
# include		<Input.hh>
# include		"Map.hpp"
# include		"Entity.hpp"
# include		"Bomb.hpp"
# include		"Item.hpp"

# define		PLAYER_STR	"Player"

class			Item;

unsigned int		newId(void);

class			Player : public Entity
{
public:
  Player(int tab[5], const std::string &name = "Player", unsigned int id = newId());
  Player(const Player &old);
  virtual ~Player(void);
  std::string		getName(void) const;
  unsigned int		getID(void) const;
  unsigned int		getScore(void) const;
  bool			isAlive(void) const;
  int			getAmmo(void) const;
  Bomb			*getRef(void);
  int			getMoveSpeed(void) const;
  bool			getCanPush(void) const;
  void			addScore(unsigned int score = 1);
  void			setScore(unsigned int score);
  void			setKeys(int tab[5]);
  void			setName(const std::string &name);
  void			setID(unsigned int ID);
  void			setAlive(bool alive);
  void			setAmmo(int ammo);
  void			setRef(Bomb ref);
  void			setMoveSpeed(int moveSpeed);
  void			setCanPush(bool canPush);
  void			putBomb(Map &gameMap);
  void			moveRight(Map &gameMap);
  void			moveLeft(Map &gameMap);
  void			moveDown(Map &gameMap);
  void			moveUp(Map &gameMap);
  void			incrementAmmo(void);
  virtual std::string	toString(void) const;
  virtual void		update(gdl::Clock const &clock, Map &gameMap, gdl::Input &input);
  virtual void		draw(gdl::AShader &shader, gdl::Clock const &clock);
  virtual bool		upgrade(Item *up);
  virtual bool		isSolid(Entity *pusher);
  virtual void		explode(Map &gameMap);
private:
  std::string					m_name;		/* Nom d'affichage du joueur (Ne devra pas être utilisé pour différencier les joueurs) */
  unsigned int					m_id;		/* ID du joueur permettant de le reconnaitre parmis les autres */
  bool						m_alive;	/* Status du joueur */
  int						m_ammo;		/* Bombes restantes (incrémenté dès qu'une bombe explose) */
  Bomb						m_ref;		/* Bombe de référence copiée quand le joueur en pose une */
  int						m_moveSpeed;	/* En pourcentage de la vitesse de base (100%) */
  bool						m_canPush;	/* Definit si le joueur peux pousser des Bombs */
  std::pair<int, void (Player::*)(Map &)>	m_keys[5];	/* Definit les touches dépendant du joueur */
  unsigned int					m_score;	/* Définit le score du joueur */
  double					m_time;
};

#endif			/* !PLAYER_HPP */
