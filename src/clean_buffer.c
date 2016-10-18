/*
** clean_buffer.c for clean_buffer in /home/jordan.roucom/cleaner
** 
** Made by Jordan Rouco miguez
** Login   <jordan.roucom@epitech.net>
** 
** Started on  Tue Oct 18 10:52:21 2016 Jordan Rouco miguez
** Last update Tue Oct 18 11:02:03 2016 Jordan Rouco miguez
*/

#include <stdio.h>

void	clearbuffer()
{
  ///Vide le buffer
  int c = 0;

  while (c != '\n' && c != EOF)
    {
      c = getchar();
    }
}
