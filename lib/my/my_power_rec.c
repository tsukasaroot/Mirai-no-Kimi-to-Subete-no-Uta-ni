/*
** my_power_rec.c for my_power_rec in /home/jordan.roucom/CPool_Day05
**
** Made by Jordan Rouco miguez
** Login   <jordan.roucom@epitech.net>
**
** Started on  Fri Oct  7 11:34:44 2016 Jordan Rouco miguez
** Last update Fri Oct  7 13:28:44 2016 Jordan Rouco miguez
*/

int	my_power_rec(int nb, int p)
{
  if (p == 0)
    {
      return (1);
    }
  return (my_power_rec(nb, p - 1) * nb);
}
