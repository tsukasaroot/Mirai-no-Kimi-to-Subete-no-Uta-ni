/*
** my_strupcase.c for my_strupcase in /home/jordan.roucom/CPool_Day06
** 
** Made by Jordan Rouco miguez
** Login   <jordan.roucom@epitech.net>
** 
** Started on  Mon Oct 10 11:07:31 2016 Jordan Rouco miguez
** Last update Sun Oct 30 02:47:51 2016 Jordan Rouco miguez
*/

char	*my_strupcase(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      str[i] = str[i] - 32;
      i = i + 1;
    }
  return (str);
}
