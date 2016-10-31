/*
** my_is_prime.c for my_is_print in /home/jordan.roucom/CPool_Day05
** 
** Made by Jordan Rouco miguez
** Login   <jordan.roucom@epitech.net>
** 
** Started on  Fri Oct  7 18:01:46 2016 Jordan Rouco miguez
** Last update Sun Oct 30 02:48:34 2016 Jordan Rouco miguez
*/

#include "../../include/my.h"

int my_is_prime(int nb)
{
  int	cpt;

  cpt = nb;

  if ((nb / 1 == 1) && nb / (nb == 1))
    {
      while (nb / cpt != 1)
	{
	  if (nb / cpt == 1)
	    {
	      return (1);
	    }
	  cpt = cpt + 1;
	}
    }
  else
    {
      return (0);
    }
}
