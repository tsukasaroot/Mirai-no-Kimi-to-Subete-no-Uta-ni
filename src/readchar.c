/*
** readchar.c for readchar in /home/jordan.roucom/cleaner
** 
** Made by Jordan Rouco miguez
** Login   <jordan.roucom@epitech.net>
** 
** Started on  Tue Oct 18 11:12:49 2016 Jordan Rouco miguez
** Last update Tue Oct 18 11:14:50 2016 Jordan Rouco miguez
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "../include/main.h"

int     readchar(char *path, int length)
{
  ///Permet de supprimer '\n' de la chaine de caractère

  char  *positionentry = NULL;

  if (fgets(path, length, stdin) != NULL)
    {
      positionentry = strchr(path, '\n');
      if (positionentry != NULL)
	{
	  *positionentry = '\0';
	}
      else
	{
	  clearbuffer();
	}
      return 1;
    }
  else
    {
      clearbuffer();
      return 0;
    }
}
