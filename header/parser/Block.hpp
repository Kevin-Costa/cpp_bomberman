//
// Block.hpp for bomberman in /home/rousse_3/rendu/cpp_bomberman
// 
// Made by rousse_3
// Login   <rousse_3@epitech.net>
// 
// Started on  Sun Jun  7 23:54:18 2015 rousse_3
// Last update Sun Jun  7 23:58:07 2015 rousse_3
//

#ifndef		BLOCK_HPP_
# define	BLOCK_HPP_

# include	"Parser.hpp"

class		Block : public IParserItem
{
public:
  static int	isBlock(const std::string &str, int index);

  Block(const std::string &str, int &index, VarTable &table);
  ~Block(void) throw();

  type		getType(const VarTable &table) const;
  bool		checkType(const VarTable &table) const;

  int		exec(VarTable &table) const;
private:
  std::vector<IParserItem*>	_insts;
};

#endif
