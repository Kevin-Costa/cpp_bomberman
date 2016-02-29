//
// VarTable.cpp for bomberman in /home/rousse_3/rendu/cpp_bomberman
// 
// Made by rousse_3
// Login   <rousse_3@epitech.net>
// 
// Started on  Mon Jun  8 13:38:30 2015 rousse_3
// Last update Wed Jun 10 14:43:17 2015 rousse_3
//

#include	"Error.hpp"
#include	"VarTable.hpp"

template<>
std::string	convert<std::string>(const std::string &str)
{
  return (str);
}

template<>
std::string	nconvert<std::string>(const std::string &value)
{
  return (value);
}

template<>
type		get_type<double>(void)
{
  return (NUMBER);
}

template<>
type		get_type<bool>(void)
{
  return (BOOL);
}

template<>
type		get_type<std::string>(void)
{
  return (STRING);
}

VarTable::VarTable(void) {}

VarTable::~VarTable(void) {}

VarTable::VarTable(const VarTable &table) :
  _names(table._names),
  _types(table._types),
  _canWrite(table._canWrite),
  _values(table._values)
{}

void		VarTable::addVar(const std::string &name)
{
  std::vector<std::string>::const_iterator	it;
  std::vector<std::string>::const_iterator	it_end;

  it = _names.begin();
  it_end = _names.end();
  while (it != it_end)
    {
      if (*it == name)
	throw std::logic_error("Var already exist");
      it++;
    }
  _names.push_back(name);
  _types.push_back(NIL);
  _canWrite.push_back(true);
  _values.push_back("");
}

type		VarTable::getType(const std::string &name) const
{
  std::vector<std::string>::const_iterator	it;
  std::vector<std::string>::const_iterator	it_end;

  it = _names.begin();
  it_end = _names.end();
  while (it != it_end)
    {
      if (*it == name)
	return (_types[_names.begin() - it]);
      it++;
    }
  throw std::logic_error("Var " + name + " doesn't exist");
}
