/*
** my_strcmp.c for my_strcmp in /home/jordan.roucom/CPool_Day06
** 
** Made by Jordan Rouco miguez
** Login   <jordan.roucom@epitech.net>
** 
** Started on  Mon Oct 10 15:25:23 2016 Jordan Rouco miguez
** Last update Sun Oct 30 02:47:32 2016 Jordan Rouco miguez
*/

#include "../../include/my.h"

int	my_strcmp(char *s1, char *s2)
{
  int	i;
  int	len;
  int	cpt;

  i = 0;
  cpt = 0;
  len = my_strlen(s1);
  while (s1[i] != '\0')
    {
      if (s1[i] != s2[i])
	{
	  cpt = cpt - 1;
	}
      i = i + 1;
    }
  return (s1[i] - s2[i]);
}
