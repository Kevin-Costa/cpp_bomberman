//
// AndOp.cpp for bomberman in /home/rousse_3/rendu/cpp_bomberman
// 
// Made by rousse_3
// Login   <rousse_3@epitech.net>
// 
// Started on  Mon Jun  1 16:12:16 2015 rousse_3
// Last update Sun Jun  7 16:36:46 2015 rousse_3
//

#include	"AndOp.hpp"
#include	"CompOp.hpp"

int		AndOp::isAndOp(const std::string &str, int index)
{
  int		ret;
  int		ret_bis;

  if ((ret = CompOp::isCompOp(str, index)) == -1)
    return (-1);
  index += ret;
  ret += passBlank(str, index);
  if (str[index] != '&' || str[index + 1] != '&')
    return (ret);
  index += 2;
  ret += passBlank(str, index);
  if ((ret_bis = isAndOp(str, index)) == -1)
    return (-1);
  else
    return (ret + ret_bis);
}

AndOp::AndOp(const std::string &str, int &index, VarTable &table)
{
  _right = new CompOp(str, index, table);
  passBlank(str, index);
  if (str[index] == '&' && str[index + 1] == '&')
    {
      _ope = true;
      index += 2;
      passBlank(str, index);
      _left = new AndOp(str, index, table);
    }
  else
    {
      _ope = false;
      _left = NULL;
    }
}

AndOp::~AndOp(void) throw()
{
  delete _right;
  if (_ope)
    delete _left;
}

type		AndOp::getType(const VarTable &table) const
{
  if (_ope == true)
    return (BOOL);
  else
    return (_right->getType(table));
}

bool		AndOp::checkType(const VarTable &table) const
{
  if (_ope != true)
    return (_right->checkType(table));
  if (_right->getType(table) != BOOL || _left->getType(table) != BOOL)
    return (false);
  return (_right->checkType(table) && _left->checkType(table));
}

bool		AndOp::getBoolValue(VarTable &table) const
{
  if (_ope == true)
    return (_right->getBoolValue(table) && _left->getBoolValue(table));
  return (_right->getBoolValue(table));
}

double		AndOp::getDoubleValue(VarTable &table) const
{
  if (_ope == true)
    {
      if (getBoolValue(table))
	return (1);
      else
	return (0);
    }
  else
    return (_right->getDoubleValue(table));
}

std::string	AndOp::getStringValue(VarTable &table) const
{
  if (_ope != true)
    return (_right->getStringValue(table));
  return ("");
}
