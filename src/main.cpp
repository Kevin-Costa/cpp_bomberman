//
// main.cpp for Bomberman in /home/boisso_c/rendu/cpp_bomberman/src
// 
// Made by Christian Boisson
// Login   <boisso_c@epitech.net>
// 
// Started on  Sun May 24 16:23:11 2015 Christian Boisson
// Last update Sun Jun 14 16:06:19 2015 rousse_3
//

#include		<stdlib.h>
#include		<unistd.h>
#include		<iostream>
#include		"Save.hpp"
#include		"Map.hpp"
#include		"Bomb.hpp"
#include		"Option.hpp"
#include		"Player.hpp"
#include		"Graphics/Graphic.hpp"

int			main(int argc, char **argv)
{
  Option		opt(argc, argv);

  if (opt.isValid() != true)
    return (1);

  Graphic		gameEngine(opt.getSizeX(), opt.getSizeX(), opt.getPlayer());

  while (gameEngine.update() == true)
    gameEngine.draw();

  return (0);
}
