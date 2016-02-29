//
// Parser.cpp for bomberman in /home/rousse_3/rendu/cpp_bomberman
// 
// Made by rousse_3
// Login   <rousse_3@epitech.net>
// 
// Started on  Sun May 24 20:49:25 2015 rousse_3
// Last update Mon Jun  8 13:38:57 2015 rousse_3
//

#include	"Parser.hpp"

IParserItem::~IParserItem(void) throw() {}

double		IParserItem::getDoubleValue(VarTable &table) const
{
  (void) table;
  return (0);
}

std::string	IParserItem::getStringValue(VarTable &table) const
{
  (void) table;
  return ("");
}

bool		IParserItem::getBoolValue(VarTable &table) const
{
  (void) table;
  return (false);
}

int		IParserItem::exec(VarTable &table) const
{
  (void) table;
  return (0);
}

bool		isDigit(char c)
{
  if (c <= '9' && c >= '0')
    return (true);
  return (false);
}

bool		isAlpha(char c)
{
  if (c <= 'z' && c >= 'a')
    return (true);
  if (c <= 'Z' && c >= 'A')
    return (true);
  return (false);
}

bool		isAlphaNum(char c)
{
  return (isAlpha(c) || isDigit(c) || c == '_');
}

bool		isBlank(char c)
{
  if (c == ' ' || c == '\t' || c == '\n')
    return (true);
  return (false);
}

int		passBlank(const std::string &str, int &index)
{
  int		ret = 0;

  while (isBlank(str[index]) == true)
    {
      ret++;
      index++;
    }
  return (ret);
}

