/*
** my_strcapitalize.c for my_strcapitalize in /home/jordan.roucom/CPool_Day06
** 
** Made by Jordan Rouco miguez
** Login   <jordan.roucom@epitech.net>
** 
** Started on  Mon Oct 10 11:50:16 2016 Jordan Rouco miguez
** Last update Sun Oct 30 02:45:52 2016 Jordan Rouco miguez
*/

#include "../../include/my.h"

char	*my_strcapitalize(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] >= 'a' && str[i] <= 'z' && str[i - 1] == ' ' ||
	  str[i - 1] == '-' || str[i - 1] == '+' || i == 0 || str[i - 1] >= '0'
	  && str[i - 1] <= '9' && str[i] >= 'a' && str[i] <= 'z')
	{
	  str[i] = str[i] - ' ';
	}
      i = i + 1;
    }
  return (str);
}
