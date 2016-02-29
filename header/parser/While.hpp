//
// While.hpp for bomberman in /home/rousse_3/rendu/cpp_bomberman
// 
// Made by rousse_3
// Login   <rousse_3@epitech.net>
// 
// Started on  Sun Jun  7 23:50:19 2015 rousse_3
// Last update Mon Jun  8 00:34:43 2015 rousse_3
//

#ifndef		WHILE_HPP_
# define	WHILE_HPP_

# include	"Parser.hpp"

class		While : public IParserItem
{
public:
  static int	isWhile(const std::string &str, int index);

  While(const std::string &str, int &index, VarTable &table);
  ~While(void) throw();

  type		getType(const VarTable &table) const;
  bool		checkType(const VarTable &table) const;

  int		exec(VarTable &table) const;
private:
  IParserItem	*_cond;
  IParserItem	*_block;
};

#endif
