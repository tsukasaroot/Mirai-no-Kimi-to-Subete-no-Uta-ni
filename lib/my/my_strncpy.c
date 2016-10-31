/*
** my_strncpy.c for my_strncpy in /home/jordan.roucom/CPool_Day06
** 
** Made by Jordan Rouco miguez
** Login   <jordan.roucom@epitech.net>
** 
** Started on  Mon Oct 10 09:21:24 2016 Jordan Rouco miguez
** Last update Sun Oct 30 02:44:41 2016 Jordan Rouco miguez
*/

#include "../../include/my.h"

char	*my_strncpy(char *dest, char *src, int n)
{
  int	i;
  int	cpt;

  cpt = my_strlen(src);
  i = 0;
  while (i <= n - 1)
    {
      dest[i] = src[i];
      i = i + 1;
    }
  if (i > cpt)
    {
      dest[i] = '\0';
    }
  return (dest);
}
