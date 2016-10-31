/*
** my_swap.c for my_swap in /home/jordan.roucom/CPool_Day04
**
** Made by Jordan Rouco miguez
** Login   <jordan.roucom@epitech.net>
**
** Started on  Thu Oct  6 07:57:32 2016 Jordan Rouco miguez
** Last update Sun Oct 30 02:50:33 2016 Jordan Rouco miguez
*/

int	my_swap(int *a, int *b)
{
  int	tmp;

  tmp = *a;
  *a = *b;
  *b = tmp;
  return (0);
}
