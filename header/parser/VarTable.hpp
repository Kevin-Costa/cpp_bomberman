//
// VarTable.hpp for bomberman in /home/rousse_3/rendu/cpp_bomberman
// 
// Made by rousse_3
// Login   <rousse_3@epitech.net>
// 
// Started on  Mon Jun  8 13:34:23 2015 rousse_3
// Last update Wed Jun 10 14:48:52 2015 rousse_3
//

#ifndef		VARTABLE_HPP_
# define	VARTABLE_HPP_

# include	<sstream>
# include	<vector>
# include	"Type.hpp"

template<typename T>
type		get_type(void)
{
  return (NIL);
}

template<typename T>
T		convert(const std::string &str)
{
  std::stringstream	ss;
  T			value;

  ss << str;
  ss >> value;
  return (value);
}

template<typename T>
std::string	nconvert(const T &value)
{
    std::stringstream	ss;
    std::string		str;

    ss << value;
    ss >> str;
    return (str);
}

class		VarTable
{
public:
  VarTable(void);
  VarTable(const VarTable &table);
  ~VarTable(void);

  void		addVar(const std::string &name);
  type		getType(const std::string &name) const;

  template<typename T>
  void		addReadOnlyVar(const std::string &name, const T &value)
  {
    std::vector<std::string>::const_iterator	it;
    std::vector<std::string>::const_iterator	it_end;
    
    addVar(name);
    it = _names.begin();
    it_end = _names.end();
    while (it != it_end)
      {
	if (*it == name)
	  {
	    _canWrite[it - _names.begin()] = false;
	    _types[it - _names.begin()] = get_type<T>();
	    _values[it - _names.begin()] = nconvert<T>(value);
	    return;
	  }
	it++;
      }
  }

  template<typename T>
  void		setVar(const std::string &name, const T &value)
  {
    std::vector<std::string>::const_iterator	it;
    std::vector<std::string>::const_iterator	it_end;
    
    it = _names.begin();
    it_end = _names.end();
    while (it != it_end)
      {
	if (*it == name)
	  {
	    if (_canWrite[it - _names.begin()] == false)
	      throw std::logic_error("Var " + name + " can't be overwrite");
	    _types[it - _names.begin()] = get_type<T>();
	    _values[it - _names.begin()] = nconvert<T>(value);
	    return;
	  }
	it++;
      }
    throw std::logic_error("Var " + name + " doesn't exist");
  }

  template<typename T>
  T		getVar(const std::string &name) const
  {
    T			new_value;
    std::vector<std::string>::const_iterator	it;
    std::vector<std::string>::const_iterator	it_end;

    it = _names.begin();
    it_end = _names.end();
    while (it != it_end)
      {
	if (*it == name)
	  {
	    if (_types[it - _names.begin()] != get_type<T>())
	      throw std::logic_error("Bad Type of variable");
	    new_value = convert<T>(_values[it - _names.begin()]);
	    return (new_value);
	  }
	it++;
      }
    throw std::logic_error("Var doesn't exist");    
  }

private:
  std::vector<std::string>	_names;
  std::vector<type>		_types;
  std::vector<bool>		_canWrite;
  std::vector<std::string>	_values;
};

#endif	       /* !VARTABLE_HPP_ */
