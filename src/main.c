/*
** main.c for main in /home/jordan.roucom/cleaner
** 
** Made by Jordan Rouco miguez
** Login   <jordan.roucom@epitech.net>
** 
** Started on  Tue Oct 18 11:03:31 2016 Jordan Rouco miguez
** Last update Mon Oct 31 16:16:40 2016 Jordan Rouco miguez
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../include/main.h"

int main()
{
  ///Le main appel prog() une première fois, puis boucle autant de fois qu'on en a besoin
  int y_n;

  printf("    Program created by Tsukasa, founder of DotHackers\n\n");
  delay(100);
    do
      {
	prog();
        printf("   Appuyez sur une touche\n");
	clearbuffer();
	printf("   Avez-vous d'autres fichiers à nettoyer/reconstruire ?\n  Oui=1\n  Non=2\n\n-> ");
	scanf("%d", &y_n);

	while (y_n != 1 && y_n != 2)
	  {
	    clearbuffer();

	    printf("   Mauvaise touche, entrez 1 ou 2\n->");
	    scanf("%d", &y_n);
	  }
      } while (y_n == 1);
    return 0;
}
