//
// ConOp.cpp for bomberman in /home/rousse_3/rendu/cpp_bomberman
// 
// Made by rousse_3
// Login   <rousse_3@epitech.net>
// 
// Started on  Wed May 27 17:17:53 2015 rousse_3
// Last update Sun Jun  7 16:17:55 2015 rousse_3
//

#include	"ConOp.hpp"
#include	"LowOp.hpp"

#include	<iostream>

int		ConOp::isConOp(const std::string &str, int index)
{
  int		ret;
  int		ret_bis;

  if ((ret = LowOp::isLowOp(str, index)) == -1)
    return (-1);
  index += ret;
  ret += passBlank(str, index);
  if (str.substr(index, 2) != "..")
    return (ret);
  index += 2;
  ret += 2;
  ret += passBlank(str, index);
  if ((ret_bis = isConOp(str, index)) == -1)
    return (-1);
  else
    return (ret + ret_bis);
}

ConOp::ConOp(const std::string &str, int &index, VarTable &table)
{
  _right = new LowOp(str, index, table);
  passBlank(str, index);
  if (str.substr(index, 2) == "..")
    {
      _concat = true;
      index += 2;
      passBlank(str, index);
      _left = new ConOp(str, index, table);
    }
  else
    {
      _concat = false;
      _left = NULL;
    }
}

ConOp::~ConOp(void) throw()
{
  delete _right;
  if (_concat)
    delete _left;
}

type		ConOp::getType(const VarTable &table) const
{
  if (_concat)
    return (STRING);
  return (_right->getType(table));
}

bool		ConOp::checkType(const VarTable &table) const
{
  if (_concat == false)
    return (_right->checkType(table));
  if (_right->getType(table) != STRING && _left->getType(table) != STRING)
    return (false);
  return (_right->checkType(table) && _left->checkType(table));
}


double		ConOp::getDoubleValue(VarTable &table) const
{
  if (_concat == false)
    return (_right->getDoubleValue(table));
  return (0);
}


bool		ConOp::getBoolValue(VarTable &table) const
{
  if (_concat == false)
    return (_right->getBoolValue(table));
  return (false);
}


std::string	ConOp::getStringValue(VarTable &table) const
{
  if (_concat == false)
    return (_right->getStringValue(table));
  return (_right->getStringValue(table) + _left->getStringValue(table));
}
