//
// Exp.cpp for bomberman in /home/rousse_3/rendu/cpp_bomberman
// 
// Made by rousse_3
// Login   <rousse_3@epitech.net>
// 
// Started on  Mon May 25 19:44:22 2015 rousse_3
// Last update Mon Jun  8 14:08:51 2015 rousse_3
//

#include	"Exp.hpp"
#include	"Var.hpp"
#include	"Bool.hpp"
#include	"OrOp.hpp"
#include	"Number.hpp"
#include	"String.hpp"

int		Exp::isExp(const std::string &str, int index)
{
  int		ret;
  int		ret_bis;

  if ((ret = Number::isNumber(str, index)) != -1)
    return (ret);
  if ((ret = Bool::isBool(str, index)) != -1)
    return (ret);
  if ((ret = Var::isVar(str, index)) != -1)
    return (ret);
  if ((ret = String::isString(str, index)) != -1)
    return (ret);
  if (str[index] != '(')
    return (-1);
  index++;
  ret = passBlank(str, index);
  if ((ret_bis = OrOp::isOrOp(str, index)) == -1)
    return (-1);
  index += ret_bis;
  ret_bis += passBlank(str, index);
  if (str[index] == ')')
    return (ret_bis + ret + 2);
  else
    return (-1);
}

Exp::Exp(const std::string &str, int &index, VarTable &table)
{
  if (Number::isNumber(str, index) != -1)
    _exp = new Number(str, index, table);
  else if (String::isString(str, index) != -1)
    _exp = new String(str, index, table);
  else if (Bool::isBool(str, index) != -1)
    _exp = new Bool(str, index, table);
  else if (Var::isVar(str, index) != -1)
    _exp = new Var(str, index, table);
  else
    {
      index++;
      passBlank(str, index);
      _exp = new OrOp(str, index, table);
      passBlank(str, index);
      index++;
    }
}

Exp::~Exp(void) throw()
{
  delete _exp;
}

type		Exp::getType(const VarTable &table) const
{
  return (_exp->getType(table));
}

bool		Exp::checkType(const VarTable &table) const
{
  return (_exp->checkType(table));
}


double		Exp::getDoubleValue(VarTable &table) const
{
  return (_exp->getDoubleValue(table));
}


bool		Exp::getBoolValue(VarTable &table) const
{
  return (_exp->getBoolValue(table));
}


std::string		Exp::getStringValue(VarTable &table) const
{
  return (_exp->getStringValue(table));
}
