//
// Save.cpp for cpp_bomberman in /home/makusa_n/tek2/cpp_bomberman/src
// 
// Made by Nayden Makusa
// Login   <makusa_n@epitech.net>
// 
// Started on  Tue Jun  9 16:54:26 2015 Nayden Makusa
// Last update Fri Jun 12 16:10:31 2015 Nayden Makusa
//

#include		<iostream>
#include		<string>
#include		<fstream>
#include		<sstream>
#include		<list>
#include		"Map.hpp"
#include		"Player.hpp"
#include		"Save.hpp"

Save::Save()
{
  ;
}

Save::~Save()
{
  ;
}

bool			Save::IsReadable(std::string file)
{
  std::ifstream fichier(file.c_str());

  return (!fichier.fail());
}

std::string		Save::CheckFileExist()
{
  int			tmp = 1;
  std::string		nb;
  std::string		file = "save/file_1.save";

  while (IsReadable(file))
    {
      std::stringstream	ss;
      tmp++;
      ss << tmp;
      nb = ss.str();
      file = "save/file_" + nb + ".save";
    }
  std::cout << "Votre partie a été sauvegardé dans le fichier : \'" << file << "\'" << std::endl;
  return (file);
}

int			Save::FileWriting(std::string file, const Map & map)
{
  int			x;
  int			y;
  std::ofstream		fichier(file.c_str(), std::ios::out | std::ios::trunc);

  y = 0;
  if (fichier)
    {
      while (y < map.getSizeY())
	{
	  x = 0;
	  while (x < map.getSizeX())
	    {
	      std::list<Entity *>	lst = map.getEntitysAtPos(x, y);
	      std::list<Entity *>::iterator	it = lst.begin();
	      std::list<Entity *>::iterator	end = lst.end();
	      if (it == end)
		fichier << "Empty|";
	      while (it != end)
		{
		  fichier << (*it)->toString() << "|";
		  ++it;
		}
	      x++;
	    }
	  fichier << std::endl;
	  y++;
	} 
      fichier.close();
    }
  else
    {
      std::cerr << "Sauvegarde echoué.\nFichier introuvable ou inaccessible." << std::endl;
      return (-1);
    }
  return (0);
}
