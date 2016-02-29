//
// LowOp.hpp for bomberman in /home/rousse_3/rendu/cpp_bomberman
// 
// Made by rousse_3
// Login   <rousse_3@epitech.net>
// 
// Started on  Wed May 27 17:01:45 2015 rousse_3
// Last update Sat Jun  6 17:07:16 2015 rousse_3
//

#ifndef		LOWOP_HPP_
# define	LOWOP_HPP_

# include	"Parser.hpp"

class		LowOp : public IParserItem
{
public:
  static int	isLowOp(const std::string &str, int index);

  LowOp(const std::string &str, int &index, VarTable &table);
  ~LowOp(void) throw();

  type		getType(const VarTable &table) const;
  bool		checkType(const VarTable &table) const;

  double	getDoubleValue(VarTable &table) const;
  std::string	getStringValue(VarTable &table) const;
  bool		getBoolValue(VarTable &table) const;
private:
  enum		ope
    {
      ADD,
      MIN,
      NONE
    };
  IParserItem	*_right;
  ope		_ope;	
  IParserItem	*_left;
};

#endif
