/*
** my_putchar.c for my_putchar in /home/jordan.roucom/CPool_Day03
** 
** Made by Jordan Rouco miguez
** Login   <jordan.roucom@epitech.net>
** 
** Started on  Wed Oct  5 08:15:32 2016 Jordan Rouco miguez
** Last update Sun Oct 30 02:51:42 2016 Jordan Rouco miguez
*/

#include <unistd.h>

int	my_putchar(char c)
{
  write(1, &c, 1);
  return (0);
}
