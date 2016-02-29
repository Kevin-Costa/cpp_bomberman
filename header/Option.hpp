//
// Option.hpp for bomberman in /home/rousse_3/rendu/cpp_bomberman
// 
// Made by rousse_3
// Login   <rousse_3@epitech.net>
// 
// Started on  Sat Jun 13 20:25:28 2015 rousse_3
// Last update Sun Jun 14 16:07:55 2015 rousse_3
//

#ifndef		OPTION_HPP_
# define	OPTION_HPP_

class		Option
{
public:
  Option(int argc, char **argv);
  ~Option(void) throw();

  bool		isValid(void) const;
  int		getSizeX(void) const;
  int		getPlayer(void) const;
private:
  bool		_isValid;
  int		_sizeX;
  int		_nbPlayer;
};

#endif		/* !OPTION_HPP_ */
