/*
** clewrite.c for cleaner&rewriter in /home/jordan.roucom/cleaner
** 
** Made by Jordan Rouco miguez
** Login   <jordan.roucom@epitech.net>
** 
** Started on  Sun Oct 16 14:01:35 2016 Jordan Rouco miguez
** Last update Sun Oct 16 14:19:20 2016 Jordan Rouco miguez
*/

#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <time.h>
#include <wchar.h>
#include "include/main.h"

#define MAX_LENGTH 2000

void delay(unsigned int ms)
{
    ///Créé un délai, utilisations diverses

    clock_t goal = ms + clock();
    while (goal > clock());
}

void clearbuffer()
{
    ///Vide le buffer

    int c = 0;

    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}

void wrapping(char const *string, FILE* filedest)
{
    ///Réecriture des wrapper mot à mot

    int cpt = 0, j=0;
    char wrappbegin[MAX_LENGTH]="[wrap text=\"", wrappmid[MAX_LENGTH]="\"]", wrappend[MAX_LENGTH]="[w]\n";
    char wordcpy[MAX_LENGTH]="";

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
                {
                    fputc('-', filedest);
                }
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
            {
               if (string[cpt] != '\0')
                    fputc(string[cpt], filedest);
            }

            if (string[j+1] != '\n')
            {
                fputs(wrappbegin, filedest);
            }
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
            printf("\n\nOpération terminée.\n\n");
	    
            fclose(filedest);
            delay(3000);
	  }
    }
}

void	cleanerchar(char const *string, FILE* filedest)
{
  ///Supprime les wrapper des dialogues
  
  for (int i=0; string[i] != '\0'; ++i)
    {
      if ((string[i] == '[') && (string[i+1] == 'e'))
        {
	  fputc(string[i], filedest);
	  printf("%c", string[i]);
        }
      else if ((string[i] == '[') && (string[i+1] != 's'))
        {
	  while (string[i] != ']')
	    ++i;
        }
      else
	{
	  printf("%c", string[i]);
	  fputc(string[i], filedest);
        }
    }
}

void	cleanerstrings(char *strings, FILE* filesrc, FILE* filedest)
{
  ///Réecrit dans un .txt tout sauf les dialogues
  
  fgets(strings, MAX_LENGTH, filesrc);
  
    while (!feof(filesrc))
      {
        if ((!((strings[0] == '[') && (strings[1] == 'w') && (strings[2] == 'r'))
	     || ((strings[0] == '[') && (strings[1] == 's') && (strings[3] == 'N'))))  //Si c'est des wrapper on passe directement au else
	  {
            fputs(strings, filedest);   //écrit la chaine dans le fichier
	  }
        else
	  {
            cleanerchar(strings, filedest); //on l'envoi à la fonction de nettoyage des wrapper
	    
            printf("%c", strings[1]);
            delay(1);
	  }
	
        fgets(strings, MAX_LENGTH, filesrc);    //on avance le curseur
	
        if (feof(filesrc))  //Si on arrive à la fin du fichier on arrête le programme
	  {
            printf("\n\nOperation terminee.\n\n");
	    
            fclose(filedest);
            delay(3000);
	  }
      }
}

int	readchar(char *path, int length)
{
  ///Permet de supprimer '\n' de la chaine de caractère
  
  char	*positionentry = NULL;
  
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

int	prog()
{
  FILE	*filesrc = NULL;
  FILE	*filedest = NULL;
  int	choice = 0;
  char	path[100], path2[100], strings[MAX_LENGTH] = "";
  
  printf("     Program created by Tsukasa, founder of DotHackers\n\n");
  delay(100);
  
  printf("     Nettoyage = 1\n     Création du wordwrapping = 2\n\n-> ");
  scanf("%d", &choice);
  
    if (choice == 1)       //Nettoyage des scripts
      {
        clearbuffer();
	
        printf("\n     Indiquer le chemin du fichier à copier.(sans l'extension)\n\n-> ");
        readchar(path, 100);
	
        strcpy(path2, path);
	//Concaténation du nom de fichier avec l'extension voulue
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
      }
    else if (choice == 2)   //Création du wordwrapping
      {
	clearbuffer();
	
	printf("\n     Indiquer le chemin du fichier a réecrire.(sans l'extension)\n\n-> ");
	readchar(path, 100);
	
	strcpy(path2, path);
		//Concaténation du nom de fichier avec l'extension voulue
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
	    printf("  Impossible d'ouvrir le fichier source.\n");
	    delay(3000);
	    return -1;
	  }
      }
    else
      {
        printf("  Option indisponible.\n");
        delay(1000);
        return -2;
      }
    
    return 0;
}

int main()
{
  ///Le main appel prog() une première fois, puis boucle autant de fois qu'on en a besoin
  
  int YoN;
  
  do
    {
      prog();
      
      clearbuffer();
      
      printf("   Avez-vous d'autres fichiers à nettoyer/reconstruire ?\n  Oui=1\n  Non=2\n");
      scanf("%d", &YoN);
      
      while (YoN != 1 && YoN != 2)
        {
	  clearbuffer();
	  
	  printf("   Mauvaise touche, entrez 1 ou 2\n");
	  scanf("%d", &YoN);
        }      
      //   prog();
    }while (YoN == 1);
  
  return 0;
}
