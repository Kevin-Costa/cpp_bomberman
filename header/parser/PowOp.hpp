//
// PowOp.hpp for bomberman in /home/rousse_3/rendu/cpp_bomberman
// 
// Made by rousse_3
// Login   <rousse_3@epitech.net>
// 
// Started on  Mon May 25 20:45:13 2015 rousse_3
// Last update Sat Jun  6 17:08:12 2015 rousse_3
//

#ifndef		POWOP_HPP_
# define	POWOP_HPP_

# include	"Parser.hpp"

class		PowOp : public IParserItem
{
public:
  static int	isPowOp(const std::string &value, int index);

  PowOp(const std::string &value, int &index, VarTable &table);
  ~PowOp(void) throw();

  type		getType(const VarTable &table) const;
  bool		checkType(const VarTable &table) const;

  double	getDoubleValue(VarTable &table) const;
  std::string	getStringValue(VarTable &table) const;
  bool		getBoolValue(VarTable &table) const;
private:
  IParserItem	*_right;
  IParserItem	*_left;
};

#endif		/* !POWOP_HPP_ */
