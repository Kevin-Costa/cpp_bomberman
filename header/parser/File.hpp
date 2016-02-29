//
// File.hpp for bomberman in /home/rousse_3/rendu/cpp_bomberman
// 
// Made by rousse_3
// Login   <rousse_3@epitech.net>
// 
// Started on  Sun Jun  7 00:30:02 2015 rousse_3
// Last update Sun Jun  7 01:01:04 2015 rousse_3
//

#ifndef		FILE_HPP_
# define	FILE_HPP_

# include	"Inst.hpp"

class		File
{
public:
  File(const std::string &filename, VarTable &table);
  ~File(void) throw();

  bool		checkType(const VarTable &table) const;
  void		exec(VarTable &table) const;
private:
  std::vector<Inst*>	_data;
};

#endif
