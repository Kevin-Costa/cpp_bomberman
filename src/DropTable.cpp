//
// DropTable.cpp for bomberman in /home/boisso_c/rendu/cpp_bomberman/src
// 
// Made by Christian Boisson
// Login   <boisso_c@epitech.net>
// 
// Started on  Tue May 26 14:09:01 2015 Christian Boisson
// Last update Thu Jun 11 18:50:00 2015 rousse_3
// Last update Thu Jun 11 12:44:09 2015 Nicolas Ribeiro Teixeira
//

#include		<stdlib.h>
#include		<time.h>
#include		"DropTable.hpp"
#include		"Item.hpp"

DropTable::DropTable(void)
{
  std::pair< int, Item*>	p_range(5, new Item(1, RANGE));
  std::pair< int, Item*>	p_timer(5, new Item(1, TIMER));
  std::pair< int, Item*>	p_move(5, new Item(true));
  std::pair< int, Item*>	p_speed(5, new Item(10, SPEED));
  std::pair< int, Item*>	p_ammo(5, new Item(1, AMMO));
  std::pair< int, Item*>	p_null(75, NULL);

  m_table.push_back(p_range);
  m_table.push_back(p_timer);
  m_table.push_back(p_move);
  m_table.push_back(p_speed);
  m_table.push_back(p_ammo);
  m_table.push_back(p_null);
  srand(time(NULL));
}

DropTable::DropTable(const DropTable &old)
{
  m_table = old.m_table;
}

DropTable::~DropTable(void)
{
  while (m_table.size() > 0)
    {
      delete (m_table.back()).second;
      m_table.pop_back();
    }
}

Item			*DropTable::randItem(void)
{
  int			nb;
  int			it;
  unsigned int		i;

  nb = rand() % 100;
  i = 0;
  it = 0;
  while (i < m_table.size() && it < nb)
    {
      it += m_table[i].first;
      ++i;
    }
  if (i < m_table.size() && m_table[i].second != NULL)
    return (new Item(*(m_table[i].second)));
  return (NULL);
}
