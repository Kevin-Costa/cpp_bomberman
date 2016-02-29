//
// Bool.cpp for bomberman in /home/rousse_3/rendu/cpp_bomberman
// 
// Made by rousse_3
// Login   <rousse_3@epitech.net>
// 
// Started on  Sun May 24 23:20:37 2015 rousse_3
// Last update Sat Jun  6 17:09:48 2015 rousse_3
//

#include	"Bool.hpp"

int		Bool::isBool(const std::string &str, int index)
{
  if (str.compare(index, 4, "true") == 0)
    return (4);
  if (str.compare(index, 5, "false") == 0)
    return (5);
  return (-1);
}

Bool::Bool(const std::string &str, int &index, VarTable &table)
{
  (void) table;
  if (str.compare(index, 4, "true") == 0)
    {
      _value = true;
      index += 4;
    }
  else
    {
      _value = false;
      index += 5;
    }
}

Bool::~Bool(void) throw() {}

type		Bool::getType(const VarTable &table) const
{
  (void) table;
  return (BOOL);
}

bool		Bool::checkType(const VarTable &table) const
{
  (void) table;
  return (true);
}

double		Bool::getDoubleValue(VarTable &table) const
{
  (void) table;
  if (_value)
    return (1);
  return (0);
}

bool		Bool::getBoolValue(VarTable &table) const
{
  (void) table;
  if (_value)
    return (1);
  return (0);
}
