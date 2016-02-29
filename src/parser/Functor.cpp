//
// Functor.cpp for bomberman in /home/rousse_3/rendu/cpp_bomberman
// 
// Made by rousse_3
// Login   <rousse_3@epitech.net>
// 
// Started on  Thu Jun 11 00:25:44 2015 rousse_3
// Last update Thu Jun 11 00:42:12 2015 rousse_3
//

#include	"Functor.hpp"

Functor::Functor(void) : _argType(), _retType(NIL) {}

Functor::~Functor(void) throw() {}

bool		Functor::isValid(std::vector<OrOp*> arg, VarTable &table) const
{
  unsigned int	idx = 0;

  if (arg.size() != _argType.size())
    return (false);
  while (idx < arg.size() && arg[idx]->getType(table) == _argType[idx])
    idx++;
  return (idx == arg.size());
}

type		Functor::getRetType(void) const
{
  return (_retType);
}

OrOp		*Functor::exec(std::vector<OrOp*> arg) const
{
  (void)arg;
  return (NULL);
}
