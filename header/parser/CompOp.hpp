//
// CompOp.hpp for bomberman in /home/rousse_3/rendu/cpp_bomberman
// 
// Made by rousse_3
// Login   <rousse_3@epitech.net>
// 
// Started on  Wed May 27 22:36:21 2015 rousse_3
// Last update Sat Jun  6 17:05:48 2015 rousse_3
//

#ifndef		COMPOP_HPP_
# define	COMPOP_HPP_

# include	"Parser.hpp"

class		CompOp : public IParserItem
{
public:
  static int	isCompOp(const std::string &str, int index);

  CompOp(const std::string &str, int &index, VarTable &table);
  ~CompOp(void) throw();

  type		getType(VarTable const &table) const;
  bool		checkType(VarTable const &table) const;

  double	getDoubleValue(VarTable &table) const;
  std::string	getStringValue(VarTable &table) const;
  bool		getBoolValue(VarTable &table) const;
private:
  enum		ope
    {
      EQU,
      NEQ,
      GTH,
      GEQ,
      LTH,
      LEQ,
      NONE
    };
  IParserItem	*_right;
  ope		_ope;
  IParserItem	*_left;
};

#endif		/* !COMPOP_HPP_ */
