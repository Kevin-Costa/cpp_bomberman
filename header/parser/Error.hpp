//
// Error.hpp for bomberman in /home/rousse_3/rendu/cpp_bomberman
// 
// Made by rousse_3
// Login   <rousse_3@epitech.net>
// 
// Started on  Fri Jun  5 19:34:41 2015 rousse_3
// Last update Fri Jun  5 19:35:51 2015 rousse_3
//

#ifndef			ERROR_HPP_
# define		ERROR_HPP_

# include		<string>
# include		<stdexcept>

class			parserError : public std::runtime_error
{
public:
  parserError(const std::string &error);
  ~parserError(void) throw();

  const char		*what(void) const throw();
private:
  const std::string	_error;
};

class			typeError : public std::logic_error
{
public:
  typeError(const std::string &error);
  ~typeError(void) throw();

  const char		*what(void) const throw();
private:
  const std::string	_error;
};

#endif			/* !ERROR_HPP_ */
