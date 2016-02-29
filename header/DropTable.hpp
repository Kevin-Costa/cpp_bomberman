//
// DropTable.cpp for bomberman in /home/boisso_c/rendu/cpp_bomberman/header
// 
// Made by Christian Boisson
// Login   <boisso_c@epitech.net>
// 
// Started on  Tue May 26 14:05:42 2015 Christian Boisson
// Last update Thu May 28 17:37:51 2015 Christian Boisson
//

#ifndef			DROP_TABLE_HPP_
# define		DROP_TABLE_HPP_

# include		<vector>
# include		<utility>

class			Item;

class			DropTable
{
public:
  DropTable(void);
  DropTable(const DropTable &old);
  ~DropTable(void);
  Item			*randItem(void);
private:
  std::vector< std::pair< int, Item *> >	m_table;
};

#endif			/* !DROP_TABLE_HPP_ */
