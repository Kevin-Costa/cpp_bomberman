//
// File.cpp for bomberman in /home/rousse_3/rendu/cpp_bomberman
// 
// Made by rousse_3
// Login   <rousse_3@epitech.net>
// 
// Started on  Sun Jun  7 00:35:15 2015 rousse_3
// Last update Mon Jun  8 01:02:32 2015 rousse_3
//

#include	<iostream>
#include	<fstream>
#include	<sstream>
#include	"File.hpp"

File::File(const std::string &filename, VarTable &table)
{
  std::ifstream	in(filename.c_str());
  std::stringstream	ss;
  std::string	buffer = "";
  int		idx = 0;
  
  ss << in.rdbuf();
  buffer = ss.str();
  while (Inst::isInst(buffer, idx) != -1)
    {
      _data.push_back(new Inst(buffer, idx, table));
      passBlank(buffer, idx);
    }
  if (buffer[idx] != '\0')
    {
      std::cout << buffer.substr(idx) << std::endl;
      throw std::logic_error("Not the end of file\n");
    }
}

File::~File(void) throw()
{
  int		idx = 0;
  int		size = _data.size();

  while (idx < size)
    {
      delete _data[idx];
      idx++;
    }
}

bool		File::checkType(const VarTable &table) const
{
  int		idx = 0;
  int		size = _data.size();

  while (idx < size)
    {
      if (_data[idx]->checkType(table) != true)
	return (false);
      idx++;
    }
  return (true);
}

void		File::exec(VarTable &table) const
{
  int		idx = 0;
  int		size = _data.size();

  while (idx < size)
    {
      if (_data[idx]->exec(table) == 1)
	return;
      idx++;
    }
}
