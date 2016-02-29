//
// Var.hpp for bomberman in /home/rousse_3/rendu/cpp_bomberman
// 
// Made by rousse_3
// Login   <rousse_3@epitech.net>
// 
// Started on  Mon May 25 00:01:34 2015 rousse_3
// Last update Sat Jun  6 18:02:55 2015 rousse_3
//

#ifndef		VAR_HPP_
# define	VAR_HPP_

# include	"Parser.hpp"

class		Var : public IParserItem
{
public:
  static int		isVar(const std::string &str, int index);

  Var(const std::string &str, int &index, VarTable &table);
  ~Var(void) throw();

  type			getType(const VarTable &table) const;
  bool			checkType(const VarTable &table) const;

  double		getDoubleValue(VarTable &table) const;
  std::string		getStringValue(VarTable &table) const;
  bool			getBoolValue(VarTable &table) const;

  const std::string	&getName(void) const;
private:
  std::string	_name;
};

#endif		/* !VAR_HPP_ */
