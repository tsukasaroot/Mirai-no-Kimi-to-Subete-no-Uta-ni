/*
** my_strcpy.c for my_strcpy in /home/jordan.roucom/CPool_Day06
** 
** Made by Jordan Rouco miguez
** Login   <jordan.roucom@epitech.net>
** 
** Started on  Mon Oct 10 07:55:08 2016 Jordan Rouco miguez
** Last update Thu Oct 13 08:31:35 2016 Jordan Rouco miguez
*/

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  return (dest);
}
