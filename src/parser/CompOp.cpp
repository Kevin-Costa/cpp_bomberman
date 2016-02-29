//
// CompOp.cpp for bomberman in /home/rousse_3/rendu/cpp_bomberman
// 
// Made by rousse_3
// Login   <rousse_3@epitech.net>
// 
// Started on  Wed May 27 22:36:04 2015 rousse_3
// Last update Sun Jun  7 16:29:19 2015 rousse_3
//

#include	"ConOp.hpp"
#include	"CompOp.hpp"

#include	<iostream>

int		CompOp::isCompOp(const std::string &str, int index)
{
  int		ret;
  int		ret_bis;

  if ((ret = ConOp::isConOp(str, index)) == -1)
    return (-1);
  index += ret;
  ret += passBlank(str, index);
  if ((str[index] == '=' || str[index] == '!') && str[index + 1] == '=')
    {
      ret += 2;
      index += 2;
    }
  else if ((str[index] == '>' || str[index] == '<') && str[index + 1] == '=')
    {
      ret += 2;
      index += 2;
    }
  else if (str[index] == '>' || str[index] == '<')
    {
      ret += 1;
      index++;
    }
  else
      return (ret);
  ret += passBlank(str, index);
  if ((ret_bis = isCompOp(str, index)) == -1)
    return (-1);
  else
    return (ret + ret_bis);
}

CompOp::CompOp(const std::string &str, int &index, VarTable &table)
{
  _right = new ConOp(str, index, table);

  std::string	token = str.substr(index, 2);
  passBlank(str, index);
  if (token == "==")
    {
      _ope = EQU;
      index += 2;
    }
  else if (token == "!=")
    {
      _ope = NEQ;
      index += 2;
    }
  else if (token == ">=")
    {
      _ope = GEQ;
      index += 2;
    }
  else if (token[0] == '>')
    {
      _ope = GTH;
      index += 1;
    }
  else if (token == "<=")
    {
      _ope = LEQ;
      index += 2;
    }
  else if (token[0] == '<')
    {
      _ope = LTH;
      index += 1;
    }
  else
    _ope = NONE;
  passBlank(str, index);
  if (_ope != NONE)
    _left = new CompOp(str, index, table);
}

CompOp::~CompOp(void) throw()
{
  delete _right;
  if (_ope != NONE)
    delete _left;
}

type		CompOp::getType(const VarTable &table) const
{
  if (_ope == NONE)
    return (_right->getType(table));
  return (BOOL);
}

bool		CompOp::checkType(const VarTable &table) const
{
  if (_ope == NONE)
    return (_right->checkType(table));
  if (_right->getType(table) != NUMBER && _right->getType(table) != BOOL)
    return (false);
  if (_left->getType(table) != NUMBER && _left->getType(table) != BOOL)
    return (false);
  return (_right->checkType(table) && _left->checkType(table));
}

bool		CompOp::getBoolValue(VarTable &table) const
{
  if (_ope == NONE)
    return (_right->getDoubleValue(table));
  if (_ope == EQU)
    return (_right->getDoubleValue(table) == _left->getDoubleValue(table));
  else if (_ope == NEQ)
    return (_right->getDoubleValue(table) != _left->getDoubleValue(table));
  else if (_ope == GTH)
    return (_right->getDoubleValue(table) > _left->getDoubleValue(table));
  else if (_ope == GEQ)
    return (_right->getDoubleValue(table) >= _left->getDoubleValue(table));
  else if (_ope == LTH)
    return (_right->getDoubleValue(table) < _left->getDoubleValue(table));
  else if (_ope == LEQ)
    return (_right->getDoubleValue(table) <= _left->getDoubleValue(table));
  return (false);
}

double		CompOp::getDoubleValue(VarTable &table) const
{
  if (_ope == NONE)
    return (_right->getDoubleValue(table));
  if (getBoolValue(table))
    return (1);
  return (0);
}

std::string	CompOp::getStringValue(VarTable &table) const
{
  if (_ope == NONE)
    return (_right->getStringValue(table));
  return ("");
}
