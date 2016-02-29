//
// Unop.hpp for bomberman in /home/rousse_3/rendu/cpp_bomberman
// 
// Made by rousse_3
// Login   <rousse_3@epitech.net>
// 
// Started on  Tue May 26 18:44:14 2015 rousse_3
// Last update Sat Jun  6 17:08:42 2015 rousse_3
//

#ifndef		UNOP_HPP_
# define	UNOP_HPP_

# include	"Parser.hpp"

class		UnOp : public IParserItem
{
public:
  static int	isUnOp(std::string const &str, int index);

  UnOp(std::string const &str, int &index, VarTable &table);
  ~UnOp(void) throw();

  type		getType(const VarTable &table) const;
  bool		checkType(const VarTable &table) const;

  double	getDoubleValue(VarTable &table) const;
  std::string	getStringValue(VarTable &table) const;
  bool		getBoolValue(VarTable &table) const;
private:
  enum		operand
    {
      MIN,
      NOT,
      LEN,
      NONE
    };
  operand	_op;
  IParserItem	*_right;
};

#endif		/* !UNOP_HPP_ */
