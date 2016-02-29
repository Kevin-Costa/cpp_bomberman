//
// Entity.hpp for bonberman in /home/boisso_c/rendu/cpp_bomberman/header
// 
// Made by Christian Boisson
// Login   <boisso_c@epitech.net>
// 
// Started on  Tue May 19 12:18:21 2015 Christian Boisson
// Last update Fri Jun 12 11:44:22 2015 Christian Boisson
//

#ifndef			ENTITY
# define		ENTITY

# include		<list>
# include		<string>
# include		<Input.hh>
# include		"Position.hpp"
# include		"Graphics/AObject.hpp"

# define		ENTITY_STR	"Entity"

class			Map;
class			Item;

class			Entity
{
public:
  Entity(void);
  Entity(const Entity &old);
  virtual ~Entity(void);
  void			setPosition(Position pos);
  //  void			setTex(MESH tex);
  void			setIsSolid(bool isSolid);
  Position		getPosition(void) const;
  //  MESH			getTex(void);
  virtual std::string	toString(void) const;
  virtual void		update(gdl::Clock const &clock, Map &gameMap, gdl::Input &input) = 0;
  virtual void		draw(gdl::AShader &shader, gdl::Clock const &clock) = 0;
  virtual bool		upgrade(Item *up) = 0;
  virtual bool		isSolid(Entity *pusher) = 0;
  virtual void		explode(Map &gameMap) = 0;
  bool			canMoveToPos(std::list<Entity *> entitys);
protected:
  Position		m_pos;		/* Position de l'Entité (Si une unité plus petite que la "case" est utilisé pour le rendu
					   la position pourra être celle du coin supérieur gauche afin de réduire la charge de calcul) */
  AObject		*m_tex;		/* Mesh de l'entité utilisé pour l'affichage (contient l'animation actuelle */
  bool			m_isSolid;	/* Définit la possibilité de traverser ou non l'entité */
};

#endif			/* !ENTITY */
