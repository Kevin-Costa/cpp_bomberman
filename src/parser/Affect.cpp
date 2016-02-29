//
// Affect.cpp for bomberman in /home/rousse_3/rendu/cpp_bomberman
// 
// Made by rousse_3
// Login   <rousse_3@epitech.net>
// 
// Started on  Sat Jun  6 16:53:27 2015 rousse_3
// Last update Sun Jun  7 20:44:14 2015 rousse_3
//

#include	"OrOp.hpp"
#include	"Affect.hpp"

int		Affect::isAffect(const std::string &str, int index)
{
  int		ret;
  int		ret_bis;

  if ((ret = Var::isVar(str, index)) == -1)
    return (-1);
  index += ret;
  ret += passBlank(str, index);
  if (str[index] != '=')
    return (-1);
  index += 1;
  ret += passBlank(str, index) + 1;
  if ((ret_bis = OrOp::isOrOp(str, index)) == -1)
    return (-1);
  index += ret_bis;
  if (str[index] != ';')
    return (-1);
  return (ret + ret_bis + 1);
}

Affect::Affect(const std::string &str, int &index, VarTable &table)
{
  _right = new Var(str, index, table);
  passBlank(str, index);
  index++;
  passBlank(str, index);
  _left = new OrOp(str, index, table);
  passBlank(str, index);
  index++;
}

Affect::~Affect(void) throw() {}

type		Affect::getType(const VarTable &table) const
{
  (void) table;
  return (NIL);
}

bool		Affect::checkType(const VarTable &table) const
{
  return (_right->checkType(table) && _left->checkType(table));
}

int		Affect::exec(VarTable &table) const
{
  type		varType = _left->getType(table);

  if (varType == NUMBER)
    table.setVar<double>(_right->getName(), _left->getDoubleValue(table));
  else if (varType == BOOL)
    table.setVar<bool>(_right->getName(), _left->getBoolValue(table));
  else if (varType == STRING)
    table.setVar<std::string>(_right->getName(), _left->getStringValue(table));
  return (0);
}
