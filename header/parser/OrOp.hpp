//
// OrOp.hpp for Bomberman in /home/rousse_3/rendu/cpp_bomberman
// 
// Made by rousse_3
// Login   <rousse_3@epitech.net>
// 
// Started on  Mon Jun  1 16:33:23 2015 rousse_3
// Last update Sat Jun  6 17:07:41 2015 rousse_3
//

#ifndef		OROP_HPP_
# define	OROP_HPP_

# include	"Parser.hpp"

class		OrOp : public IParserItem
{
public:
  static int	isOrOp(const std::string &str, int index);
  
  OrOp(const std::string &str, int &index, VarTable &table);
  ~OrOp(void) throw();

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
