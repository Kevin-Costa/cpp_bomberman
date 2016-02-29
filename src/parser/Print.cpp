//
// Print.cpp for bomberman in /home/rousse_3/rendu/cpp_bomberman
// 
// Made by rousse_3
// Login   <rousse_3@epitech.net>
// 
// Started on  Sat Jun  6 22:19:22 2015 rousse_3
// Last update Sun Jun  7 20:20:50 2015 rousse_3
//

#include	<iomanip>
#include	<iostream>
#include	"OrOp.hpp"
#include	"Print.hpp"

int		Print::isPrint(const std::string &str, int index)
{
  int		ret;
  int		ret_bis = 0;

  if (str.compare(index, 5, "print") != 0)
    return (-1);
  index += 5;
  ret_bis += passBlank(str, index) + 5;
  if (str[index] != '(')
    return (-1);
  ret_bis += passBlank(str, index) + 1;
  index++;
  if ((ret = OrOp::isOrOp(str, index)) == -1)
    return (-1);
  index += ret;
  ret_bis += passBlank(str, index);
  if (str[index] != ')')
    return (-1);
  index++;
  ret_bis += passBlank(str, index) + 1;
  if (str[index] != ';')
    return (-1);
  else
    return (ret + ret_bis + 1);
}

Print::Print(const std::string &str, int &index, VarTable &table)
{
  index += 5;
  passBlank(str, index);
  index++;
  passBlank(str, index);
  _exp = new OrOp(str, index, table);
  passBlank(str, index);
  index++;
  passBlank(str, index);
  index++;
}

Print::~Print(void) throw()
{
  delete _exp;
}

type		Print::getType(const VarTable &table) const
{
  (void) table;
  return (NIL);
}

bool		Print::checkType(const VarTable &table) const
{
  return (_exp->checkType(table));
}

int		Print::exec(VarTable &table) const
{
  if (_exp->getType(table) == NUMBER)
    std::cout << _exp->getDoubleValue(table) << std::endl;
  else if (_exp->getType(table) == STRING)
    std::cout << _exp->getStringValue(table) << std::endl;
  else if (_exp->getType(table) == BOOL)
    std::cout << std::boolalpha << _exp->getBoolValue(table) << std::endl;
  return (0);
}
