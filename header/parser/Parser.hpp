//
// Parser.hpp for bomberman in /home/rousse_3/rendu/cpp_bomberman
// 
// Made by rousse_3
// Login   <rousse_3@epitech.net>
// 
// Started on  Sun May 24 20:46:04 2015 rousse_3
// Last update Mon Jun  8 13:46:03 2015 rousse_3
//

#ifndef			PARSER_HPP_
# define		PARSER_HPP_

# include		<string>
# include		"Error.hpp"
# include		"VarTable.hpp"

class			IParserItem
{
public:
  virtual ~IParserItem(void) throw();

  virtual type	getType(const VarTable &table) const = 0;
  virtual bool	checkType(const VarTable &table) const = 0;

  virtual double	getDoubleValue(VarTable &table) const;
  virtual std::string	getStringValue(VarTable &table) const;
  virtual bool		getBoolValue(VarTable &table) const;

  virtual int		exec(VarTable &table) const;
};

bool		isDigit(char c);
bool		isAlpha(char c);
bool		isAlphaNum(char c);
bool		isBlank(char c);

int		passBlank(const std::string &str, int &index);

#endif			/* !PARSER_HPP_ */
