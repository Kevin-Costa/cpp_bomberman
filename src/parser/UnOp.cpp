//
// UnOp.cpp for bomberman in /home/rousse_3/rendu/cpp_bomberman
// 
// Made by rousse_3
// Login   <rousse_3@epitech.net>
// 
// Started on  Tue May 26 18:52:02 2015 rousse_3
// Last update Sun Jun  7 16:16:58 2015 rousse_3
//

#include	"PowOp.hpp"
#include	"UnOp.hpp"

int		UnOp::isUnOp(std::string const &str, int index)
{
  int		ret;
  int		ret_bis;

  ret = 0;
  if (str[index] == '-' || str[index] == '#' || str[index] == '!')
    {
      index++;
      ret++;
    }
  ret += passBlank(str, index);
  if ((ret_bis = PowOp::isPowOp(str, index)) == -1)
    return (-1);
  else
    return (ret + ret_bis);
}

UnOp::UnOp(std::string const &str, int &index, VarTable &table)
{
  if (str[index] == '-')
    {
      _op = MIN;
      index++;
    }
  else if (str[index] == '#')
    {
      _op = LEN;
      index++;
    }
  else if (str[index] == '!')
    {
      _op = NOT;
      index++;
    }
  else
    _op = NONE;
  passBlank(str, index);
  _right = new PowOp(str, index, table);
}

UnOp::~UnOp(void) throw()
{
  delete _right;
}

type		UnOp::getType(const VarTable &table) const
{
  if (_op == NONE)
    return (_right->getType(table));
  return (NUMBER);
}

bool		UnOp::checkType(const VarTable &table) const
{
  if (_op == MIN && _right->getType(table) != NUMBER)
    return (false);
  if (_op == NOT && _right->getType(table) != BOOL)
    return (false);
  if (_op == LEN && _right->getType(table) != STRING)
    return (false);
  return (_right->checkType(table));
}


double		UnOp::getDoubleValue(VarTable &table) const
{
  if (_op == MIN)
    return (-1 * _right->getDoubleValue(table));
  else if (_op == NOT)
    return (!_right->getBoolValue(table));
  else if (_op == LEN)
    return (_right->getStringValue(table).length());
  else
    return (_right->getDoubleValue(table));
}


bool		UnOp::getBoolValue(VarTable &table) const
{
  if (_op == NONE)
    return (_right->getBoolValue(table));
  return (getDoubleValue(table));
}


std::string	UnOp::getStringValue(VarTable &table) const
{
  return (_right->getStringValue(table));
}
