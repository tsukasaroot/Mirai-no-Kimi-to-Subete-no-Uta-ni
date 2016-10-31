/*
** my_put_nbr.c for my_put_nbr in /home/jordan.roucom/CPool_Day03
** 
** Made by Jordan Rouco miguez
** Login   <jordan.roucom@epitech.net>
** 
** Started on  Wed Oct  5 11:22:38 2016 Jordan Rouco miguez
** Last update Sun Oct 30 02:43:38 2016 Jordan Rouco miguez
*/

#include <unistd.h>
#include "../../include/my.h"

void	sup_eq10(int *nb, int *dnb)
{
  while (*nb >= 10)
    {
      *nb = *nb / 10;
      *dnb = *dnb * 10;
    }
}
void	sup_eq10_2(int *nb, int *dnb)
{
  while (*nb >= 10)
    {
      my_putchar(*nb / *dnb + 48);
      *nb = *nb % *dnb;
      *dnb = *dnb / 10;
    }
}

int	my_put_nbr(int nb)
{
  int	temp;
  int	dnb;

  if (nb < 0)
    {
      nb * -1;
      my_putchar('-');
    }
  temp = nb;
  dnb = 1;
  sup_eq10(&nb, &dnb);
  nb = temp;
  sup_eq10_2(&nb, & dnb);
  my_putchar(nb + 48);
  return (0);
}
