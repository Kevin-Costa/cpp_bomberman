//
// Map.hpp for Bomberman in /home/rousse_3/rendu/cpp_bomberman/header
// 
// Made by rousse_3
// Login   <rousse_3@epitech.net>
// 
// Started on  Wed May 20 17:48:53 2015 rousse_3
// Last update Sun Jun 14 18:35:27 2015 rousse_3
//

#ifndef			MAP_HPP_
# define		MAP_HPP_

# include		<iostream>
# include		<Clock.hh>
# include		<Input.hh>
# include		<list>
# include		"Entity.hpp"
# include		"DropTable.hpp"
# include		"Player.hpp"

class			Player;

class			Map
{
public:
  Map(int sizeX = 10, int sizeY = 10);
  Map(const Map &old);
  ~Map(void);
  int			getSizeX(void) const;
  int			getSizeY(void) const;
  std::list<Entity *>	getEntitysAtPos(int posX, int posY) const;
  void			addEntityAtPos(int posX, int posY, Entity *toAdd);
  void			addPlayer(Player *newPlayer);
  void			addPlayer(int x, int y, Player *newPlayer);
  void			update(gdl::Clock &clock, gdl::Input &input);
  void			draw(gdl::AShader &shader, gdl::Clock &clock);
  bool			checkForEntity(int posX, int posY, int range, const std::string &type) const;
  void			addToUpdate(Entity *toUpdate, Position oldPos);
  void			deleteEntity(Entity *toDelete);
  void			moveEntity(Entity *toMove, Position oldPos);
  void			removeEntityFromPos(Entity *toRemove, Position pos);
  void			dumpScore(void) const;
  bool			gameIsEnd(void) const;
  bool			placePlayer(int nbPlayer, std::vector<Player*> tab);
private:
  void			deleteEntitys(int posX, int posY, int range, bool deletePlayer = false);
  const int		m_sizeX;
  const int		m_sizeY;
  std::list<Entity *>	**m_map;
  DropTable		m_dropTable;
  std::list< std::pair<Entity *, Position> >	m_toUpdate;
  std::list<Player *>	m_players;
};

std::ostream		&operator<<(std::ostream &os, const Map &data);

#endif			/* !MAP_HPP_ */
