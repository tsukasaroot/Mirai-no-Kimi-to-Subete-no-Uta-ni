/*
** my_revstr.c for my_revstr in /home/jordan.roucom/CPool_Day06
** 
** Made by Jordan Rouco miguez
** Login   <jordan.roucom@epitech.net>
** 
** Started on  Mon Oct 10 09:44:31 2016 Jordan Rouco miguez
** Last update Sun Oct 30 02:47:13 2016 Jordan Rouco miguez
*/

#include "../../include/my.h"

char	*my_revstr(char *str)
{
  int	i;
  int	decr;
  int	tmp;

  i = 0;
  decr = my_strlen(str);
  while (i < decr)
    {
      tmp = str[i];
      str[i] = str[decr];
      str[decr] = tmp;
      i = i + 1;
      decr = decr - 1;
    }
  return (str);
}
