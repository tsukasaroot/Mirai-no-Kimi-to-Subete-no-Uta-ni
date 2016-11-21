/*
** cleaner_string.c for cleanerstring in /home/jordan.roucom/cleaner
** 
** Made by Jordan Rouco miguez
** Login   <jordan.roucom@epitech.net>
** 
** Started on  Tue Oct 18 13:10:56 2016 Jordan Rouco miguez
** Last update Mon Nov 21 12:25:55 2016 Jordan Rouco miguez
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/main.h"
#include "../include/my.h"

void    cleanerstrings(char *strings, FILE* filesrc, FILE* filedest)
{
  ///Réecrit dans un .txt tout sauf les dialogues
  fgets(strings, MAX_LENGTH, filesrc);
  while (!feof(filesrc))
    {
      if ((!((strings[0] == '[') && (strings[1] == 'w') && (strings[2] == 'r'))
	   || ((strings[0] == '[') && (strings[1] == 's') && (strings[3] == 'N'))))  //Si c'est des\	 wrapper on passe directement au else
	   {
	     fputs(strings, filedest);   //écrit la chaine dans le fichier
	   }
      else
	{
	  cleanerchar(strings, filedest); //on l'envoi à la fonction de nettoyage des wrapper
	  delay(1);
	}
      fgets(strings, MAX_LENGTH, filesrc);    //on avance le curseur
      if (feof(filesrc))  //Si on arrive à la fin du fichier on arrête le programme
	{
	  my_putstr("\n\n   Opération terminée.\n\n");
	  fclose(filedest);
	  delay(3000);
	}
    }
}
