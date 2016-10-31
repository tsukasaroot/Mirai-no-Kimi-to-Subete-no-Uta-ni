/*
** my_square_root.c for my_square_root in /home/jordan.roucom/CPool_Day05
**
** Made by Jordan Rouco miguez
** Login   <jordan.roucom@epitech.net>
**
** Started on  Fri Oct  7 13:30:57 2016 Jordan Rouco miguez
** Last update Sun Oct 30 02:44:10 2016 Jordan Rouco miguez
*/

#include "../../include/my.h"

int	my_square_root(int nb)
{
  int	bf;
  int	tmp;

  bf = 1;
  if (nb <= 0)
    {
      return (0);
    }
  while (bf < nb)
    {
      bf = bf + 1;
      tmp = bf * bf;
      if (tmp == nb)
	{
	  return (bf);
	}
    }
  return (0);
}
