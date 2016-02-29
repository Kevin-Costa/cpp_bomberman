//
// If.hpp for bomberman in /home/rousse_3/rendu/cpp_bomberman
// 
// Made by rousse_3
// Login   <rousse_3@epitech.net>
// 
// Started on  Mon Jun  8 13:47:02 2015 rousse_3
// Last update Mon Jun  8 13:51:05 2015 rousse_3
//

#ifndef		IF_HPP_
# define	IF_HPP_

#include	"Parser.hpp"

class		If : public IParserItem
{
public:
  static int	isIf(const std::string &str, int index);

  If(const std::string &str, int &index, VarTable &table);
  ~If(void) throw();

  type		getType(const VarTable &table) const;
  bool		checkType(const VarTable &table) const;

  int		exec(VarTable &table) const;
private:
  IParserItem	*_cond;
  IParserItem	*_block;
  IParserItem	*_else;
};

#endif	/* !IF_HPP_ */
