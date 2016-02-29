//
// AndOp.hpp for bomberman in /home/rousse_3/rendu/cpp_bomberman
// 
// Made by rousse_3
// Login   <rousse_3@epitech.net>
// 
// Started on  Mon Jun  1 16:11:56 2015 rousse_3
// Last update Sat Jun  6 17:05:09 2015 rousse_3
//

#ifndef		ANDOP_HPP_
# define	ANDOP_HPP_

# include	"Parser.hpp"

class		AndOp : public IParserItem
{
public:
  static int	isAndOp(const std::string &str, int index);
  
  AndOp(const std::string &str, int &index, VarTable &table);
  ~AndOp(void) throw();

  type		getType(const VarTable &table) const;
  bool		checkType(const VarTable &table) const;

  double	getDoubleValue(VarTable &table) const;
  std::string	getStringValue(VarTable &table) const;
  bool		getBoolValue(VarTable &table) const;
private:
  IParserItem	*_right;
  bool		_ope;
  IParserItem	*_left;
};

#endif
