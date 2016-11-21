/*
** my_put_error.c for error_displays in /home/jordan.roucom/CPool_evalexpr
**
** Made by Jordan Rouco miguez
** Login   <jordan.roucom@epitech.net>
**
** Started on  Fri Oct 28 08:26:21 2016 Jordan Rouco miguez
** Last update Wed Nov  2 14:28:14 2016 Jordan Rouco miguez
*/

#include <unistd.h>
#include "../../include/my.h"

void	my_put_error(char *s)
{
  write(2, s, my_strlen(s));
}
