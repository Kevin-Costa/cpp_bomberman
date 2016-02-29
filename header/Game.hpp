//
// Game.hpp for bomberman in /home/boisso_c/rendu/cpp_bomberman/header
// 
// Made by Christian Boisson
// Login   <boisso_c@epitech.net>
// 
// Started on  Tue May 19 12:15:54 2015 Christian Boisson
// Last update Tue May 26 12:16:59 2015 Christian Boisson
//

#ifndef			GAME_HPP
# define		GAME_HPP

# include		<list>
# include		"Player.hpp"
# include		"Map.hpp"

class			Game
{
public:
  Game(void);
  Game(const Game &old);
  ~Game(void);
private:
  std::list<Player>	m_player;	/* Liste des joueurs (contient aussi les IA qui devrons émuler un jouer humain. (Pourrait être modifier par une list d'entitée) */
  Map			m_map;
};

#endif			/* !GAME_HPP */
