//
// HighOp.cpp for bomberman in /home/rousse_3/rendu/cpp_bomberman
// 
// Made by rousse_3
// Login   <rousse_3@epitech.net>
// 
// Started on  Wed May 27 03:28:20 2015 rousse_3
// Last update Sun Jun  7 15:50:07 2015 rousse_3
//

#include	"UnOp.hpp"
#include	"HighOp.hpp"

int		HighOp::isHighOp(const std::string &str, int index)
{
  int		ret;
  int		ret_bis;

  if ((ret = UnOp::isUnOp(str, index)) == -1)
    return (-1);
  index += ret;
  ret += passBlank(str, index);
  if (str[index] != '*' && str[index] != '/')
    return (ret);
  index += 1;
  ret += passBlank(str, index);
  if ((ret_bis = isHighOp(str, index)) == -1)
    return (-1);
  else
    return (ret + ret_bis + 1);
}

HighOp::HighOp(const std::string &str, int &index, VarTable &table)
{
  _right = new UnOp(str, index, table);
  passBlank(str, index);
  if (str[index] == '*')
    {
      _op = MUL;
      index++;
      passBlank(str, index);
      _left = new HighOp(str, index, table);
    }
  else if (str[index] == '/')
    {
      _op = DIV;
      index++;
      passBlank(str, index);
      _left = new HighOp(str, index, table);
    }
  else
    {
      _op = NONE;
      _left = NULL;
    }
}

HighOp::~HighOp(void) throw()
{
  delete _right;
  if (_op != NONE)
    delete _left;
}

type		HighOp::getType(const VarTable &table) const
{
  if (_op == NONE)
    return (_right->getType(table));
  return (NUMBER);
}

bool		HighOp::checkType(const VarTable &table) const
{
  if (_op == NONE)
    return (_right->checkType(table));
  if (_right->getType(table) != NUMBER && _left->getType(table) != NUMBER)
    return (false);
  return (_right->checkType(table) && _left->checkType(table));
}


double		HighOp::getDoubleValue(VarTable &table) const
{
  if (_op == NONE)
    return (_right->getDoubleValue(table));
  else if (_op == MUL)
    return (_right->getDoubleValue(table) * _left->getDoubleValue(table));
  else if (_op == DIV)
    return (_right->getDoubleValue(table) / _left->getDoubleValue(table));
  return (0);
}


bool		HighOp::getBoolValue(VarTable &table) const
{
  if (_op == NONE)
    return (_right->getBoolValue(table));
  return (getDoubleValue(table) != 0);
}


std::string	HighOp::getStringValue(VarTable &table) const
{
  if (_op == NONE)
    return (_right->getStringValue(table));
  return ("");
}
