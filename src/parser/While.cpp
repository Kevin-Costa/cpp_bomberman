//
// While.cpp for bomberman in /home/rousse_3/rendu/cpp_bomberman
// 
// Made by rousse_3
// Login   <rousse_3@epitech.net>
// 
// Started on  Mon Jun  8 00:12:17 2015 rousse_3
// Last update Mon Jun  8 14:02:01 2015 rousse_3
//

#include	"Exp.hpp"
#include	"Block.hpp"
#include	"While.hpp"

int		While::isWhile(const std::string &str, int index)
{
  int		ret = 0;
  int		ret_bis = 0;

  if (str.compare(index, 5, "while") != 0)
    return (-1);
  index += 5;
  ret = passBlank(str, index) + 5;
  if ((ret_bis = Exp::isExp(str, index)) == -1)
    return (-1);
  index += ret_bis;
  ret = passBlank(str, index) + ret_bis;
  if ((ret_bis = Block::isBlock(str, index)) == -1)
    return (-1);
  return (ret + ret_bis);
}

While::While(const std::string &str, int &index, VarTable &table)
{
  index += 5;
  passBlank(str, index);
  _cond = new Exp(str, index, table);
  passBlank(str, index);
  _block = new Block(str, index, table);
}

While::~While(void) throw ()
{
  delete _cond;
  delete _block;
}

type		While::getType(const VarTable &table) const
{
  (void) table;
  return (NIL);
}

bool		While::checkType(const VarTable &table) const
{
  if (_cond->getType(table) != NUMBER && _cond->getType(table) != BOOL)
    return (false);
  return (_cond->checkType(table) && _block->checkType(table));
}

int		While::exec(VarTable &table) const
{
  int		idx = 0;

  while (idx < 500 && _cond->getBoolValue(table) != false)
    {
      if (_block->exec(table) == 1)
	return (1);
      idx++;
    }
  if (idx == 500)
    return (1);
  return (0);
}
