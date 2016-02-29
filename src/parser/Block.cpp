//
// Block.cpp for bomberman in /home/rousse_3/rendu/cpp_bomberman
// 
// Made by rousse_3
// Login   <rousse_3@epitech.net>
// 
// Started on  Sun Jun  7 23:57:00 2015 rousse_3
// Last update Mon Jun  8 01:01:59 2015 rousse_3
//

#include	"Inst.hpp"
#include	"Block.hpp"

int		Block::isBlock(const std::string &str, int index)
{
  int		ret = 0;
  int		ret_bis;

  if (str[index] != '{')
    return (-1);
  index++;
  ret += passBlank(str, index) + 1;
  while ((ret_bis = Inst::isInst(str, index)) != -1)
    {
      index += ret_bis;
      ret += passBlank(str, index) + ret_bis;
    }
  if (str[index] != '}')
    return (-1);
  return (ret + 1);
}

Block::Block(const std::string &str, int &index, VarTable &table)
{
  index++;
  passBlank(str, index);
  while (Inst::isInst(str, index) != -1)
    {
      _insts.push_back(new Inst(str, index, table));
      passBlank(str, index);
    }
  index++;
}

Block::~Block(void) throw()
{
  std::vector<IParserItem*>::iterator	it = _insts.begin();
  std::vector<IParserItem*>::iterator	end = _insts.end();

  while (it != end)
    {
      delete *it;
      it++;
    }
}

type		Block::getType(const VarTable &table) const
{
  (void) table;
  return (NIL);
}

bool		Block::checkType(const VarTable &table) const
{
  std::vector<IParserItem*>::const_iterator	it = _insts.begin();
  std::vector<IParserItem*>::const_iterator	end = _insts.end();

  while (it != end)
    {
      if ((*it)->checkType(table) != true)
	return (false);
      it++;
    }
  return (true);
}

int		Block::exec(VarTable &table) const
{
  std::vector<IParserItem*>::const_iterator	it = _insts.begin();
  std::vector<IParserItem*>::const_iterator	end = _insts.end();

  while (it != end)
    {
      if ((*it)->exec(table) == 1)
	return (1);
      it++;
    }
  return (0);
}
