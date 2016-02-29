//
// Exp.hpp for bomberman in /home/rousse_3/rendu/cpp_bomberman
// 
// Made by rousse_3
// Login   <rousse_3@epitech.net>
// 
// Started on  Mon May 25 17:46:55 2015 rousse_3
// Last update Sat Jun  6 17:06:36 2015 rousse_3
//

#ifndef		EXP_HPP_
# define	EXP_HPP_

# include	"Parser.hpp"

class		Exp : public IParserItem
{
public:
  static int	isExp(const std::string &str, int index);

  Exp(const std::string &str, int &index, VarTable &table);
  ~Exp(void) throw();

  type		getType(const VarTable &table) const;
  bool		checkType(const VarTable &table) const;

  double	getDoubleValue(VarTable &table) const;
  std::string	getStringValue(VarTable &table) const;
  bool		getBoolValue(VarTable &table) const;
private:
  IParserItem	*_exp;
};

#endif		/* !EXP_HPP_ */
