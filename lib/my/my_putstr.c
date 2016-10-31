/*
** my_putstr.c for my_putstr in /home/jordan.roucom/CPool_Day04
**
** Made by Jordan Rouco miguez
** Login   <jordan.roucom@epitech.net>
**
** Started on  Thu Oct  6 09:11:16 2016 Jordan Rouco miguez
** Last update Sun Oct 30 02:45:12 2016 Jordan Rouco miguez
*/

#include "../../include/my.h"

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i = i + 1;
    }
  return (0);
}
