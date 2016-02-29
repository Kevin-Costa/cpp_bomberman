//
// ConOp.hpp for bomberman in /home/rousse_3/rendu/cpp_bomberman
// 
// Made by rousse_3
// Login   <rousse_3@epitech.net>
// 
// Started on  Wed May 27 17:18:09 2015 rousse_3
// Last update Sat Jun  6 17:06:05 2015 rousse_3
//

#ifndef		CONOP_HPP_
# define	CONOP_HPP_

# include	"Parser.hpp"

class		ConOp : public IParserItem
{
public:
  static int	isConOp(const std::string &str, int index);

  ConOp(const std::string &str, int &index, VarTable &table);
  ~ConOp(void) throw();

  type		getType(const VarTable &table) const;
  bool		checkType(const VarTable &table) const;

  double	getDoubleValue(VarTable &table) const;
  std::string	getStringValue(VarTable &table) const;
  bool		getBoolValue(VarTable &table) const;
private:
  IParserItem	*_right;
  bool		_concat;
  IParserItem	*_left;
};

#endif		/* !CONOP_HPP_ */
