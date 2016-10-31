/*
** my_strlowercase.c for my_strlowcase in /home/jordan.roucom/CPool_Day06
** 
** Made by Jordan Rouco miguez
** Login   <jordan.roucom@epitech.net>
** 
** Started on  Mon Oct 10 11:14:37 2016 Jordan Rouco miguez
** Last update Mon Oct 10 11:37:46 2016 Jordan Rouco miguez
*/

char	*my_strlowcase(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      str[i] = str[i] + 32;
      i = i + 1;
    }
  return (str);
}
