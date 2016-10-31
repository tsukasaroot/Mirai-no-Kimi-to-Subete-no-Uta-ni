/*
** my_isneg.c for my_isneg in /home/jordan.roucom/CPool_Day03
**
** Made by Jordan Rouco miguez
** Login   <jordan.roucom@epitech.net>
**
** Started on  Wed Oct  5 09:59:49 2016 Jordan Rouco miguez
** Last update Sun Oct 30 02:53:56 2016 Jordan Rouco miguez
*/

#include "../../include/my.h"

int	my_isneg(int n)
{
  if (n >= 0)
    {
      my_putchar('P');
    }
  else
    {
      my_putchar('N');
    }
  return (0);
}
