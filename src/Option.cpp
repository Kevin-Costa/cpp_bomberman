//
// parse_option.cpp for bomberman in /home/rousse_3/rendu/cpp_bomberman
// 
// Made by rousse_3
// Login   <rousse_3@epitech.net>
// 
// Started on  Sat Jun 13 20:18:01 2015 rousse_3
// Last update Sun Jun 14 16:07:24 2015 rousse_3
//

#include	<cstdlib>
#include	<iostream>
#include	"Option.hpp"

static bool		isNumber(const char *str)
{
  int			idx = 0;

  while (str[idx] != '\0')
    {
      if (str[idx] < '0' || str[idx] > '9')
	return (false);
      idx++;
    }
  return (true);
}

Option::Option(int argc, char **argv) : _sizeX(-1), _nbPlayer(-1)
{
  int		idx = 1;

  while (idx < argc)
    {
      if (isNumber(argv[idx]) != true)
	{
	  std::cerr << "Arg " << idx << " must be a number" << std::endl;
	  _isValid = false;
	  return;
	}
      if (_sizeX == -1)
	_sizeX = std::atoi(argv[idx]);
      else if (_nbPlayer == -1)
	_nbPlayer = std::atoi(argv[idx]);
      else
	{
	  std::cerr << "You have enter too many args" << std::endl;
	  _isValid = false;
	  return;
	}
      idx++;
    }
  if (_nbPlayer == -1)
    {
      std::cerr << "You must enter more args" << std::endl;
      _isValid = false;
      return;
    }
  _isValid = true;
}

Option::~Option(void) throw() {}

bool		Option::isValid(void) const
{
  return (_isValid);
}

int		Option::getSizeX(void) const
{
  return (_sizeX);
}

int		Option::getPlayer(void) const
{
  return (_nbPlayer);
}
