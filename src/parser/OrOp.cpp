//
// OrOp.cpp for bomberman in /home/rousse_3/rendu/cpp_bomberman
// 
// Made by rousse_3
// Login   <rousse_3@epitech.net>
// 
// Started on  Mon Jun  1 16:34:00 2015 rousse_3
// Last update Sun Jun  7 16:36:33 2015 rousse_3
//

#include	"OrOp.hpp"
#include	"AndOp.hpp"

int		OrOp::isOrOp(const std::string &str, int index)
{
  int		ret;
  int		ret_bis;

  if ((ret = AndOp::isAndOp(str, index)) == -1)
    return (-1);
  index += ret;
  ret += passBlank(str, index);
  if (str[index] != '|' || str[index + 1] != '|')
    return (ret);
  index += 2;
  ret += passBlank(str, index);
  if ((ret_bis = isOrOp(str, index)) == -1)
    return (-1);
  else
    return (ret + ret_bis);
}

OrOp::OrOp(const std::string &str, int &index, VarTable &table)
{
  _right = new AndOp(str, index, table);
  passBlank(str, index);
  if (str[index] == '|' && str[index + 1] == '|')
    {
      _ope = true;
      index += 2;
      passBlank(str, index);
      _left = new OrOp(str, index, table);
    }
  else
    {
      _ope = false;
      _left = NULL;
    }
}

OrOp::~OrOp(void) throw()
{
  delete _right;
  if (_ope)
    delete _left;
}

type		OrOp::getType(const VarTable &table) const
{
  if (_ope == true)
    return (BOOL);
  else
    return (_right->getType(table));
}

bool		OrOp::checkType(const VarTable &table) const
{
  if (_ope != true)
    return (_right->checkType(table));
  if (_right->getType(table) != BOOL || _left->getType(table) != BOOL)
    return (false);
  return (_right->checkType(table) && _left->checkType(table));
}


bool		OrOp::getBoolValue(VarTable &table) const
{
  if (_ope == true)
    return (_right->getBoolValue(table) || _left->getBoolValue(table));
  return (_right->getBoolValue(table));
}


double		OrOp::getDoubleValue(VarTable &table) const
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


std::string	OrOp::getStringValue(VarTable &table) const
{
  if (_ope != true)
    return (_right->getStringValue(table));
  return ("");
}
