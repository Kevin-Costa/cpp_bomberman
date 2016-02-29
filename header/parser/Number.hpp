//
// Number.hpp for bomberman in /home/rousse_3/rendu/cpp_bomberman
// 
// Made by rousse_3
// Login   <rousse_3@epitech.net>
// 
// Started on  Sun May 24 22:53:35 2015 rousse_3
// Last update Sat Jun  6 17:07:27 2015 rousse_3
//

#ifndef		NUMBER_HPP_
# define	NUMBER_HPP_

# include	"Parser.hpp"

class		Number : public IParserItem
{
public:
  static int	isNumber(const std::string &str, int index);

  Number(const std::string &str, int &index, VarTable &table);
  ~Number(void) throw();

  type		getType(const VarTable &table) const;
  bool		checkType(const VarTable &table) const;

  virtual double	getDoubleValue(VarTable &table) const;
  virtual bool		getBoolValue(VarTable &table) const;
private:
  double	_nb;
};

#endif
