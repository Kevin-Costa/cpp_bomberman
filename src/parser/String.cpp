//
// String.cpp for bomberman in /home/rousse_3/rendu/cpp_bomberman
// 
// Made by rousse_3
// Login   <rousse_3@epitech.net>
// 
// Started on  Sun May 24 23:38:25 2015 rousse_3
// Last update Sat Jun  6 17:13:08 2015 rousse_3
//

#include	"String.hpp"

int		String::isString(const std::string &str, int index)
{
  int		ret = 1;

  if (str[index] != '"')
    return (-1);
  while (str[index + ret] != '"' && str[index + ret] != '\0')
    ret++;
  if (str[index + ret] != '"')
    return (-1);
  return (ret + 1);
}

String::String(const std::string &str, int &index, VarTable &table)
{
  int		idx;

  (void) table;
  idx = 1;
  while (str[index + idx] != '"' && str[index + idx] != '\0')
    idx++;
  _value = str.substr(index + 1, idx - 1);
  index += idx + 1;
}

String::~String(void) throw() {}

type		String::getType(const VarTable &table) const
{
  (void) table;
  return (STRING);
}

bool		String::checkType(const VarTable &table) const
{
  (void) table;
  return (true);
}


std::string	String::getStringValue(VarTable &table) const
{
  (void) table;
  return (_value);
}
