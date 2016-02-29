/*
** main_test.c for bomberman in /home/rousse_3/rendu/cpp_bomberman
** 
** Made by rousse_3
** Login   <rousse_3@epitech.net>
** 
** Started on  Fri Jun  5 19:02:58 2015 rousse_3
// Last update Wed Jun 10 14:48:18 2015 rousse_3
*/

#include		<iostream>
#include		"File.hpp"

int			main(int argc, const char **argv)
{
  if (argc != 2)
    {
      std::cerr << "Error please give a filename" << std::endl;
      return (1);
    }

  VarTable		table;

  table.addReadOnlyVar<double>("GoRight", 0);

  File			file(argv[1], table);

  std::cout << "Execution" << std::endl;
  file.exec(table);
  return (0);
}
