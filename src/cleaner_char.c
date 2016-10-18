/*
** cleaner_char.c for cleaner_char in /home/jordan.roucom/cleaner
** 
** Made by Jordan Rouco miguez
** Login   <jordan.roucom@epitech.net>
** 
** Started on  Tue Oct 18 13:28:36 2016 Jordan Rouco miguez
** Last update Tue Oct 18 13:36:41 2016 Jordan Rouco miguez
*/

#include <stdio.h>

void    cleanerchar(char const *string, FILE* filedest)
{
  ///Supprime les wrapper des dialogues
  for (int i = 0; string[i] != '\0'; ++i)
    {
      if ((string[i] == '[') && (string[i+1] == 'e'))
	{
	  fputc(string[i], filedest);
	}
      else if ((string[i] == '[') && (string[i+1] != 's'))
	{
	  while (string[i] != ']')
	    ++i;
	}
      else
	{
	  fputc(string[i], filedest);
	}
    }
}
