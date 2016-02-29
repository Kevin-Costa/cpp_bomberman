//
// Functor.hpp for bomberman in /home/rousse_3/rendu/cpp_bomberman
// 
// Made by rousse_3
// Login   <rousse_3@epitech.net>
// 
// Started on  Thu Jun 11 00:25:56 2015 rousse_3
// Last update Thu Jun 11 00:41:44 2015 rousse_3
//

#ifndef		FUNCTOR_HPP_
# define	FUNCTOR_HPP_

# include	"OrOp.hpp"
# include	"Parser.hpp"

class		Functor
{
public:
  Functor(void);
  ~Functor(void) throw();

  bool		isValid(std::vector<OrOp*> arg, VarTable &table) const;
  type		getRetType(void) const;
  OrOp		*exec(std::vector<OrOp*> arg) const;

private:
  std::vector<type>	_argType;
  type			_retType;
};

#endif		/* !FUNCTOR_HPP_ */
