/*
** my_strlen.c for my_strlen in /home/jordan.roucom/CPool_Day04
** 
** Made by Jordan Rouco miguez
** Login   <jordan.roucom@epitech.net>
** 
** Started on  Thu Oct  6 10:03:30 2016 Jordan Rouco miguez
** Last update Thu Oct  6 16:29:14 2016 Jordan Rouco miguez
*/

int	my_strlen(char *strlen)
{
  int	i;

  i = 0;
  while (strlen[i] != '\0')
    {
      i = i + 1;
    }
  return (i);
}
