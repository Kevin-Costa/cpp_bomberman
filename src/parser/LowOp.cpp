//
// LowOp.cpp for bomberman in /home/rousse_3/rendu/cpp_bomberman
// 
// Made by rousse_3
// Login   <rousse_3@epitech.net>
// 
// Started on  Wed May 27 17:01:34 2015 rousse_3
// Last update Sun Jun  7 16:20:12 2015 rousse_3
//

#include	"HighOp.hpp"
#include	"LowOp.hpp"

int		LowOp::isLowOp(const std::string &str, int index)
{
  int		ret;
  int		ret_bis;

  if ((ret = HighOp::isHighOp(str, index)) == -1)
    return (-1);
  index += ret;
  ret += passBlank(str, index);
  if (str[index] != '+' && str[index] != '-')
    return (ret);
  index++;
  ret += passBlank(str, index) + 1;
  if ((ret_bis = isLowOp(str, index)) == -1)
    return (-1);
  return (ret + ret_bis);
}

LowOp::LowOp(const std::string &str, int &index, VarTable &table)
{
  _right = new HighOp(str, index, table);
  passBlank(str, index);
  if (str[index] == '+')
    {
      index++;
      _ope = ADD;
      passBlank(str, index);
      _left = new LowOp(str, index, table);
    }
  else if (str[index] == '-')
    {
      index++;
      _ope = MIN;
      passBlank(str, index);
      _left = new LowOp(str, index, table);
    }
  else
    {
      _ope = NONE;
      _left = NULL;
    }
}

LowOp::~LowOp(void) throw()
{
  delete _right;
  if (_ope != NONE)
    delete _left;
}

type		LowOp::getType(const VarTable &table) const
{
  if (_ope == NONE)
    return (_right->getType(table));
  return (NUMBER);
}

bool		LowOp::checkType(const VarTable &table) const
{
  if (_ope == NONE)
    return (_right->checkType(table));
  if (_right->getType(table) != NUMBER && _left->getType(table) != NUMBER)
    return (false);
  return (_right->checkType(table) && _left->checkType(table));
}


double		LowOp::getDoubleValue(VarTable &table) const
{
  if (_ope == NONE)
    return (_right->getDoubleValue(table));
  else if (_ope == ADD)
    return (_right->getDoubleValue(table) + _left->getDoubleValue(table));
  else if (_ope == MIN)
    return (_right->getDoubleValue(table) - _left->getDoubleValue(table));
  return (0);
}


bool		LowOp::getBoolValue(VarTable &table) const
{
  if (_ope == NONE)
    return (_right->getBoolValue(table));
  return (this->getDoubleValue(table) != 0);
}


std::string		LowOp::getStringValue(VarTable &table) const
{
  if (_ope == NONE)
    return (_right->getStringValue(table));
  return ("");
}
