//
// PowOp.cpp for bomberman in /home/rousse_3/rendu/cpp_bomberman
// 
// Made by rousse_3
// Login   <rousse_3@epitech.net>
// 
// Started on  Mon May 25 20:45:51 2015 rousse_3
// Last update Sun Jun  7 16:16:33 2015 rousse_3
//

#include	<cmath>
#include	"Exp.hpp"
#include	"PowOp.hpp"

int		PowOp::isPowOp(const std::string &str, int index)
{
  int		ret;
  int		ret_bis;

  if ((ret = Exp::isExp(str, index)) == -1)
    return (-1);
  index += ret;
  ret += passBlank(str, index);
  if (str[index] == '^')
    {
      index += 1;
      ret += passBlank(str, index) + 1;
      if ((ret_bis = Exp::isExp(str, index)) == -1)
	return (-1);
      ret += ret_bis;
    }
  return (ret);
}

PowOp::PowOp(const std::string &str, int &index, VarTable &table)
{
  _right = new Exp(str, index, table);
  passBlank(str, index);
  if (str[index] == '^')
    {
      index++;
      passBlank(str, index);
      _left = new Exp(str, index, table);
    }
  else
    _left = NULL;
}

PowOp::~PowOp(void) throw()
{
  if (_left != NULL)
    delete _left;
  delete _right;
}

type		PowOp::getType(const VarTable &table) const
{
  if (_left == NULL)
    return (_right->getType(table));
  return (NUMBER);
}

bool		PowOp::checkType(const VarTable &table) const
{
  if (_left == NULL)
    return (_right->checkType(table));
  if (_left->getType(table) != NUMBER || _right->getType(table) != NUMBER)
    return (false);
  return (_left->checkType(table) && _right->checkType(table));
}

double		PowOp::getDoubleValue(VarTable &table) const
{
  if (_left != NULL)
    return (std::pow(_right->getDoubleValue(table), _left->getDoubleValue(table)));
  else 
    return (_right->getDoubleValue(table));
}

bool		PowOp::getBoolValue(VarTable &table) const
{
  if (_left != NULL)
    return (std::pow(_right->getDoubleValue(table), _left->getDoubleValue(table) != 0));
  else 
    return (_right->getBoolValue(table));
}

std::string	PowOp::getStringValue(VarTable &table) const
{
  if (_left == NULL)
    return (_right->getStringValue(table));
  return ("");
}
