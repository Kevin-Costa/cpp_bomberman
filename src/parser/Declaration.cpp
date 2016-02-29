//
// Declaration.cpp for bomberman in /home/rousse_3/rendu/cpp_bomberman
// 
// Made by rousse_3
// Login   <rousse_3@epitech.net>
// 
// Started on  Sat Jun  6 19:07:51 2015 rousse_3
// Last update Sun Jun  7 20:53:35 2015 rousse_3
//

#include	"Declaration.hpp"

int		Declaration::isDeclaration(const std::string &str, int index)
{
  int		ret = 0;
  int		ret_bis = 0;

  if (str.compare(index, 5, "local") != 0)
    return (-1);
  index += 5;
  if (isBlank(str[index]) != true)
    return (-1);
  index += 1;
  ret += passBlank(str, index) + 6;
  if ((ret_bis = Var::isVar(str, index)) == -1)
    return (-1);
  index += ret_bis;
  ret += passBlank(str, index);
  if (str[index] != ';')
    return (-1);
  return (ret_bis + ret);
}

Declaration::Declaration(const std::string &str, int &index, VarTable &table)
{
  index += 5;
  passBlank(str, index);
  _var = new Var(str, index, table);
  passBlank(str, index);
  index += 1;
}

Declaration::~Declaration(void) throw()
{
  delete _var;
}

type		Declaration::getType(const VarTable &table) const
{
  (void) table;
  return (NIL);
}

bool		Declaration::checkType(const VarTable &table) const
{
  return (_var->checkType(table));
}

int		Declaration::exec(VarTable &table) const
{
  table.addVar(_var->getName());
  return (0);
}
