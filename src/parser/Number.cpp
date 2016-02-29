//
// Number.cpp for bomberman in /home/rousse_3/rendu/cpp_bomberman
// 
// Made by rousse_3
// Login   <rousse_3@epitech.net>
// 
// Started on  Sun May 24 23:06:46 2015 rousse_3
// Last update Sat Jun  6 17:12:21 2015 rousse_3
//

#include	<cstdlib>
#include	"Number.hpp"

#include	<iostream>

int		Number::isNumber(const std::string &str, int index)
{
  int		idx = 1;

  if (isDigit(str[index]) != true)
    return (-1);
  while (isDigit(str[index + idx]))
    idx++;
  if (str[index + idx] == '.')
    idx++;
  if (isDigit(str[index]) != true)
    return (-1);
  while (isDigit(str[index + idx]))
    idx++;
  return (idx);
}

Number::Number(const std::string &str, int &index, VarTable &table)
{
  int		idx = 0;

  (void) table;
  while (isDigit(str[index + idx]))
    idx++;
  if (str[index + idx] == '.')
    idx++;
  while (isDigit(str[index + idx]))
    idx++;
  _nb = std::atof(str.substr(index, idx).c_str());
  index += idx;
}

Number::~Number(void) throw() {}

type		Number::getType(const VarTable &table) const
{
  (void) table;
  return (NUMBER);
}

bool		Number::checkType(const VarTable &table) const
{
  (void) table;
  return (true);
}

double		Number::getDoubleValue(VarTable &table) const
{
  (void) table;
  return (_nb);
}

bool		Number::getBoolValue(VarTable &table) const
{
  (void) table;
  return (_nb != 0);
}
