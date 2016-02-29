//
// Affect.hpp for bomberman in /home/rousse_3/rendu/cpp_bomberman
// 
// Made by rousse_3
// Login   <rousse_3@epitech.net>
// 
// Started on  Sat Jun  6 16:49:45 2015 rousse_3
// Last update Sun Jun  7 00:42:43 2015 rousse_3
//

#ifndef		AFFECT_HPP_
# define	AFFECT_HPP_

# include	"Var.hpp"
# include	"Parser.hpp"

class		Affect : public IParserItem
{
public:
  static int	isAffect(const std::string &str, int index);

  Affect(const std::string &str, int &index, VarTable &table);
  ~Affect(void) throw();

  type		getType(const VarTable &table) const;
  bool		checkType(const VarTable &table) const;

  int		exec(VarTable &table) const;
private:

  Var		*_right;
  IParserItem	*_left;
};

#endif		/* !AFFECT_HPP_ */
