//
// If.cpp for bomberman in /home/rousse_3/rendu/cpp_bomberman
// 
// Made by rousse_3
// Login   <rousse_3@epitech.net>
// 
// Started on  Mon Jun  8 13:50:28 2015 rousse_3
// Last update Mon Jun  8 14:07:37 2015 rousse_3
//

#include	"Exp.hpp"
#include	"Block.hpp"
#include	"If.hpp"

int		If::isIf(const std::string &str, int index)
{
  int		ret = 0;
  int		ret_bis = 0;


  if (str.compare(index, 2, "if") != 0)
    return (-1);
  index += 2;
  ret += passBlank(str, index) + 2;
  if ((ret_bis = Exp::isExp(str, index)) == -1)
    return (-1);
  index += ret_bis;
  ret = passBlank(str, index) + ret_bis;
  if ((ret_bis = Block::isBlock(str, index)) == -1)
    return (-1);
  index += ret_bis;
  ret = passBlank(str, index) + ret_bis;
  if (str.compare(index, 4, "else") != 0)
    return (ret);
  index += 4;
  ret += passBlank(str, index) + 4;
  if (str.compare(index, 2, "if") == 0)
    ret_bis = isIf(str, index);
  else
    ret_bis = Block::isBlock(str, index);
  if (ret_bis == -1)
    return (-1);
  else
    return (ret + ret_bis);
}

If::If(const std::string &str, int &index, VarTable &table)
{
  index += 2;
  passBlank(str, index);
  _cond = new Exp(str, index, table);
  passBlank(str, index);
  _block = new Block(str, index, table);
  passBlank(str, index);
  if (str.compare(index, 4, "else") == 0)
    {
      index += 4;
      passBlank(str, index);
      if (str.compare(index, 2, "if") == 0)
	_else = new If(str, index, table);
      else
	_else = new Block(str, index, table);
    }
  else
    _else = NULL;
}

If::~If(void) throw()
{
  delete _cond;
  delete _block;
  if (_else != NULL)
    delete _else;
}

type		If::getType(const VarTable &table) const
{
  (void) table;
  return (NIL);
}

bool		If::checkType(const VarTable &table) const
{
  if (_cond->getType(table) != NUMBER && _cond->getType(table) != BOOL)
    return (false);
  if (_else != NULL && _cond->checkType(table) != true)
    return (false);
  return (_cond->checkType(table) && _block->checkType(table));
}

int		If::exec(VarTable &table) const
{
  if (_cond->getBoolValue(table) == true)
    return (_block->exec(table));
  else
    if (_else != NULL)
      return (_else->exec(table));
  return (0);
}
