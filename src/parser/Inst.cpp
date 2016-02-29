//
// Inst.cpp for bomberman in /home/rousse_3/rendu/cpp_bomberman
// 
// Made by rousse_3
// Login   <rousse_3@epitech.net>
// 
// Started on  Sat Jun  6 22:00:35 2015 rousse_3
// Last update Mon Jun  8 14:03:11 2015 rousse_3
//

#include	"If.hpp"
#include	"Inst.hpp"
#include	"Print.hpp"
#include	"While.hpp"
#include	"Affect.hpp"
#include	"Declaration.hpp"

int		Inst::isInst(const std::string &str, int index)
{
  int		ret;
  int		ret_bis;

  ret_bis = passBlank(str, index);
  if ((ret = (Affect::isAffect(str, index))) != -1)
    return (ret_bis + ret);
  if ((ret = (Declaration::isDeclaration(str, index))) != -1)
    return (ret_bis + ret);
  if ((ret = (If::isIf(str, index))) != -1)
    return (ret_bis + ret);
  if ((ret = (Print::isPrint(str, index))) != -1)
    return (ret_bis + ret);
  if ((ret = (While::isWhile(str, index))) != -1)
    return (ret_bis + ret);
  return (-1);
}

Inst::Inst(const std::string &str, int &index, VarTable &table) : _inst(NULL)
{
  passBlank(str, index);
  if ((Affect::isAffect(str, index)) != -1)
    _inst = new Affect(str, index, table);
  else if (Declaration::isDeclaration(str, index) != -1)
    _inst = new Declaration(str, index, table);
  else if (If::isIf(str, index) != -1)
    _inst = new If(str, index, table);
  else if (Print::isPrint(str, index) != -1)
    _inst = new Print(str, index, table);
  else if (While::isWhile(str, index) != -1)
    _inst = new While(str, index, table);
}

Inst::~Inst(void) throw()
{
  if (_inst != NULL)
    delete _inst;
}

type		Inst::getType(const VarTable &table) const
{
  if (_inst != NULL)
    return (_inst->getType(table));
  return (NIL);
}

bool		Inst::checkType(const VarTable &table) const
{
  if (_inst != NULL)
    return (_inst->checkType(table));
  return (false);
}

int		Inst::exec(VarTable &table) const
{
  if (_inst != NULL)
    return (_inst->exec(table));
  return (0);
}
