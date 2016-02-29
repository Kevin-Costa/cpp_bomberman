//
// HighOp.hpp for bomberman in /home/rousse_3/rendu/cpp_bomberman
// 
// Made by rousse_3
// Login   <rousse_3@epitech.net>
// 
// Started on  Wed May 27 03:27:41 2015 rousse_3
// Last update Sat Jun  6 17:06:50 2015 rousse_3
//

#ifndef		HIGHOP_HPP_
# define	HIGHOP_HPP_

# include	"Parser.hpp"

class		HighOp : public IParserItem
{
public:
  static int	isHighOp(const std::string &str, int index);

  HighOp(const std::string &str, int &index, VarTable &table);
  ~HighOp(void) throw();

  type		getType(const VarTable &table) const;
  bool		checkType(const VarTable &table) const;

  double	getDoubleValue(VarTable &table) const;
  std::string	getStringValue(VarTable &table) const;
  bool		getBoolValue(VarTable &table) const;
private:
  enum		operate
    {
      MUL,
      DIV,
      NONE
    };
  IParserItem	*_right;
  operate	_op;
  IParserItem	*_left;
};

#endif		/* !HIGHOP_HPP_ */
