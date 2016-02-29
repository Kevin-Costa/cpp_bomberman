//
// Bool.hpp for bomberman in /home/rousse_3/rendu/cpp_bomberman
// 
// Made by rousse_3
// Login   <rousse_3@epitech.net>
// 
// Started on  Sun May 24 23:19:39 2015 rousse_3
// Last update Sat Jun  6 17:05:28 2015 rousse_3
//

#ifndef		BOOL_HPP_
# define	BOOL_HPP_

# include	"Parser.hpp"

class		Bool : public IParserItem
{
public:
  static int	isBool(const std::string &str, int index);

  Bool(const std::string &str, int &index, VarTable &table);
  ~Bool(void) throw();

  type		getType(const VarTable &table) const;
  bool		checkType(const VarTable &table) const;

  double	getDoubleValue(VarTable &table) const;
  bool		getBoolValue(VarTable &table) const;
private:
  bool		_value;
};

#endif		/* !BOOL_HPP_ */
