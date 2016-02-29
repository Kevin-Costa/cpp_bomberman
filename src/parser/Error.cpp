//
// Error.cpp for bomberman in /home/rousse_3/rendu/cpp_bomberman
// 
// Made by rousse_3
// Login   <rousse_3@epitech.net>
// 
// Started on  Fri Jun  5 19:36:51 2015 rousse_3
// Last update Fri Jun  5 19:37:02 2015 rousse_3
//

#include	"Error.hpp"

parserError::parserError(const std::string &error) : runtime_error(error), _error(error) {}

parserError::~parserError(void) throw() {}

const char	*parserError::what(void) const throw() { return _error.c_str(); }

typeError::typeError(const std::string &error) : logic_error(error), _error(error) {}

typeError::~typeError(void) throw() {}

const char	*typeError::what(void) const throw() { return _error.c_str(); }
