//
// Inst.hpp for bomberman in /home/rousse_3/rendu/cpp_bomberman
// 
// Made by rousse_3
// Login   <rousse_3@epitech.net>
// 
// Started on  Sat Jun  6 16:46:13 2015 rousse_3
// Last update Sun Jun  7 00:44:37 2015 rousse_3
//

#ifndef		INST_HPP_
# define	INST_HPP_

# include	"Parser.hpp"

class		Inst : public IParserItem
{
public:
  static int	isInst(const std::string &str, int value);

  Inst(const std::string &str, int &value, VarTable &table);
  ~Inst(void) throw();

  type	getType(const VarTable &table) const;
  bool	checkType(const VarTable &table) const;

  int		exec(VarTable &table) const;
private:
  IParserItem	*_inst;
};

#endif			/* !INST_HPP_ */
