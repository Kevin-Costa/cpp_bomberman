//
// Print.hpp for bomberman in /home/rousse_3/rendu/cpp_bomberman
// 
// Made by rousse_3
// Login   <rousse_3@epitech.net>
// 
// Started on  Sat Jun  6 22:14:35 2015 rousse_3
// Last update Sun Jun  7 00:42:50 2015 rousse_3
//

#ifndef		PRINT_HPP_
# define	PRINT_HPP_

# include	"Parser.hpp"

class		Print : public IParserItem
{
public:
  static int		isPrint(const std::string &str, int index);

  Print(const std::string &str, int &index, VarTable &table);
  ~Print(void) throw();

  type		getType(const VarTable &table) const;
  bool		checkType(const VarTable &table) const;

  int		exec(VarTable &table) const;
private:
  IParserItem	*_exp;
};

#endif		/* !PRINT_HPP_ */
