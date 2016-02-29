//
// Game.cpp for bomberman in /home/boisso_c/rendu/cpp_bomberman/src
// 
// Made by Christian Boisson
// Login   <boisso_c@epitech.net>
// 
// Started on  Tue May 26 12:13:25 2015 Christian Boisson
// Last update Tue May 26 12:17:08 2015 Christian Boisson
//

#include		"Game.hpp"

Game::Game(void)
{

}

Game::Game(const Game &old) : m_map(old.m_map)
{
  m_player = old.m_player;
}

Game::~Game(void)
{

}
