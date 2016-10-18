/*
** delay.c for delay in /home/jordan.roucom/cleaner
** 
** Made by Jordan Rouco miguez
** Login   <jordan.roucom@epitech.net>
** 
** Started on  Tue Oct 18 10:55:22 2016 Jordan Rouco miguez
** Last update Tue Oct 18 10:55:55 2016 Jordan Rouco miguez
*/

#include <time.h>

void delay(unsigned int ms)
{
  ///Créé un délai, utilisations diverses

  clock_t goal = ms + clock();
  while (goal > clock());
}
