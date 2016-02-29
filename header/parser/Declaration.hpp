//
// Declaration.hpp for bomberman in /home/rousse_3/rendu/cpp_bomberman
// 
// Made by rousse_3
// Login   <rousse_3@epitech.net>
// 
// Started on  Sat Jun  6 18:51:34 2015 rousse_3
// Last update Sun Jun  7 00:43:00 2015 rousse_3
//

#ifndef		DECLARATION_HPP_
# define	DECLARATION_HPP_

# include	"Var.hpp"
# include	"Parser.hpp"

class		Declaration : public IParserItem
{
public:
  static int		isDeclaration(const std::string &str, int index);

  Declaration(const std::string &str, int &value, VarTable &table);
  ~Declaration(void) throw();

  type		getType(const VarTable &table) const;
  bool		checkType(const VarTable &table) const;

  int		exec(VarTable &table) const;
private:
  Var		*_var;
};

#endif		/* !DECLARATION_HPP_ */
