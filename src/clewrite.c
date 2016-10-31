/*
** clewrite.c for cleaner&rewriter in /home/jordan.roucom/cleaner
**
** Made by Jordan Rouco miguez
** Login   <jordan.roucom@epitech.net>
**
** Started on  Sun Oct 16 14:01:35 2016 Jordan Rouco miguez
** Last update Mon Oct 31 16:12:39 2016 Jordan Rouco miguez
*/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/main.h"
#include "../include/my.h"

void wrapping(char const *string, FILE* filedest)
{
  ///Réecriture des wrapper mot à mot
  int	cpt = 0, j=0;
  char	wrappbegin[MAX_LENGTH]="[wrap text=\"", wrappmid[MAX_LENGTH]="\"]", wrappend[MAX_LENGTH]="[w]\n";
  char	wordcpy[MAX_LENGTH]="";

  fputs(wrappbegin, filedest);
  for (j; string[j+1] != '\0'; ++j)
    {
      if (string[j] == '"')
        {
	  fputc('-', filedest);
        }
      else if (string[j] == ' ' && string[j+1] == '!' && string[j+2] == '?')  //attache les ponctuations complexes avec le mot précédent
        {
	  for (int i=0; i <= 2; ++i)
            {
	      fputc(string[j], filedest);
	      ++j;
	      if (string[j] == '"')
		fputc('-', filedest);
            }
        }
      else if ((string[j] == ' ' && string[j+1] == '?') || (string[j] == ' ' && string[j+1] == '!'))  //attache les ponctuations avec le mot précédent
        {
	  for (int i=0; i < 2; ++i)
            {
	      fputc(string[j], filedest);
	      ++j;

	      if (string[j] == '"')
                {
		  fputc('-', filedest);
                }
            }
        }
      else
        {
	  if (string[j] != ' ')
            {
	      wordcpy[j] = string[j];
	      fputc(wordcpy[j], filedest);
            }
        }
      if (string[j] == ' ' || string[j+1] == '\n') //Si la condition est vraie, on met le WrappMid, et on entre dans la boucle pour réécrire le mot qui sera affiché dans le jeu, ensuite, on remet un WrappBegin
        {
	  fputs(wrappmid, filedest);
	  for (cpt; cpt <= j; ++cpt)
	    if (string[cpt] != '\0')
	      fputc(string[cpt], filedest);
	  if (string[j+1] != '\n')
	    fputs(wrappbegin, filedest);
        }
    }
  if (string[j-1] != ' ')
    fputc(' ', filedest);
  fputs(wrappend, filedest);
}

void	rewrite(char *strings, FILE* filesrc, FILE* filedest)
{
  ///Réecrit toutes les fonctions sauf les dialogues
  while (!feof(filesrc))
    {
      if (strings[0] == ';')  //N'écrit que si ces conditions sont vraies
        {
	  fputs(strings, filedest);
        }
      else if ((strings[0] == '[') && (strings[1] == 'c') && (strings[2] == ']'))
        {
	  fputs(strings, filedest);
        }
      else if (strings[0] == '*')
        {
	  fputs(strings, filedest);
        }
      else if (strings[0] == '[')
        {
	  fputs(strings, filedest);
        }
      else if (strings[0] == '\n')
        {
	  fputs(strings, filedest);
        }
      else if (strings[0] != '\0')
        {
	  wrapping(strings, filedest);
        }
      fgets(strings, MAX_LENGTH, filesrc);
      if (feof(filesrc))
	{
	  printf("\n\n   Opération terminée.\n\n");
	  fclose(filedest);
	  delay(3000);
	}
    }
}

int	option_2(FILE* filesrc, FILE* filedest)
{
  char path[100], path2[100], strings[MAX_LENGTH] = "";

  clearbuffer();
  printf("\n    Indiquer le chemin du fichier a réecrire.(sans l'extension)\n\n-> ");
  readchar(path, 100);
  strcpy(path2, path);									  //Concaténation du nom de fichier avec l'extension voulue
  strcat(path, ".txt");
  filesrc = fopen(path, "r+");
  if (filesrc != NULL)
    {
      strcat(path2, ".ks");
      filedest = fopen(path2, "w+");
      if (filedest != NULL)
	{
	  rewrite(strings, filesrc, filedest);
	}
      fclose(filesrc);
    }
  else
    {
      write(2, "  Impossible d'ouvrir le fichier source.\n", my_strlen("  Impossible d'ouvrir le fichier source.\n"));
      delay(3000);
      return (-1);
    }
  return (1);
}

int	option_1(FILE* filesrc, FILE* filedest)
{
  char	path[100], path2[100], strings[MAX_LENGTH] = "";

  clearbuffer();
  printf("\n     Indiquer le chemin du fichier à copier.(sans l'extension)\n\n-> ");
  readchar(path, 100);
  strcpy(path2, path);									  //Concaténation du nom de fichier avec l'extension voulue
  strcat(path, ".ks");
  filesrc = fopen(path, "r+");
  if (filesrc != NULL)
    {
      strcat(path2, ".txt");
      filedest = fopen(path2, "w+");
      if (filedest != NULL)
	{
	  cleanerstrings(strings, filesrc, filedest);
	}
      fclose(filesrc);
    }
    else
    {
      printf("  Impossible d'ouvrir le fichier source.\n");
      delay(3000);
      return -1;
    }
  return (1);
}

int	prog()
{
  FILE	*filesrc = NULL;
  FILE	*filedest = NULL;
  int	choice = 0;

  printf("    Program created by Tsukasa, founder of DotHackers\n\n");
  delay(100);
  printf("     Nettoyage = 1\n     Création du wordwrapping = 2\n\n-> ");
  scanf("%d", &choice);
  if (choice == 1)       //Nettoyage des scripts
    {
      option_1(filesrc, filedest);
    }
  else if (choice == 2)   //Création du wordwrapping
    {
      option_2(filesrc, filedest);
    }
  else
    {
      put_error("  Option indisponible.\n");
      delay(1000);
      return (-2);
    }
  return (0);
}
