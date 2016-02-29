//
// Var.cpp for bomberman in /home/rousse_3/rendu/cpp_bomberman
// 
// Made by rousse_3
// Login   <rousse_3@epitech.net>
// 
// Started on  Mon May 25 00:05:43 2015 rousse_3
// Last update Mon Jun  8 01:04:21 2015 rousse_3
//

#include	"Var.hpp"

int		Var::isVar(const std::string &str, int index)
{
  int		idx = 0;

  while (idx < 3)
    {
      if (isAlpha(str[index + idx]) != true)
	return (-1);
      idx++;
    }
  while (isAlphaNum(str[index + idx]) == true)
    idx++;
  return (idx);
}

Var::Var(const std::string &str, int &index, VarTable &table)
{
  int		idx = 0;

  (void) table;
  if ((idx = isVar(str, index)) == -1)
    throw parserError("Expected Var");
  _name = str.substr(index, idx);
  index += idx;
}

Var::~Var(void) throw() {}

type		Var::getType(const VarTable &table) const
{
  return (table.getType(_name));
}

bool		Var::checkType(const VarTable &table) const
{
  (void) table;
  return (true);
}

double		Var::getDoubleValue(VarTable &table) const
{
  if (table.getType(_name) == NUMBER)
    return (table.getVar<double>(_name));
  else
    return (table.getVar<bool>(_name));
}

bool		Var::getBoolValue(VarTable &table) const
{
  if (table.getType(_name) == NUMBER)
    return (table.getVar<double>(_name));
  else
    return (table.getVar<bool>(_name));
}

std::string		Var::getStringValue(VarTable &table) const
{
  return (table.getVar<std::string>(_name));
}

const std::string	&Var::getName(void) const
{
  return (_name);
}
