//
// String.hpp for bomberman in /home/rousse_3/rendu/cpp_bomberman
// 
// Made by rousse_3
// Login   <rousse_3@epitech.net>
// 
// Started on  Sun May 24 23:35:44 2015 rousse_3
// Last update Sat Jun  6 17:08:26 2015 rousse_3
//

#ifndef		STRING_HPP_
# define	STRING_HPP_

# include	"Parser.hpp"

class		String : public IParserItem
{
public:
  static int	isString(const std::string &str, int index);

  String(const std::string &str, int &index, VarTable &table);
  ~String(void) throw();

  type		getType(const VarTable &table) const;
  bool		checkType(const VarTable &table) const;

  std::string	getStringValue(VarTable &table) const;
private:
  std::string	_value;
};

#endif
