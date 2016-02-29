//
// Save.hpp for cpp_bomberman in /home/makusa_n/tek2/cpp_bomberman
// 
// Made by Nayden Makusa
// Login   <makusa_n@epitech.net>
// 
// Started on  Wed Jun 10 16:19:45 2015 Nayden Makusa
// Last update Fri Jun 12 15:48:58 2015 Nayden Makusa
//

#ifndef			SAVE_HPP_
# define		SAVE_HPP_

# include		<iostream>
# include		<string>
# include		<fstream>
# include		<sstream>
# include		"Map.hpp"
# include		"Player.hpp"

class			Map;

class			Save
{
public:
  Save();
  ~Save();
  bool			IsReadable(std::string);
  std::string		CheckFileExist();
  int			FileWriting(std::string, const Map &);
private:
};

#endif			/* !SAVE_HPP_ */
