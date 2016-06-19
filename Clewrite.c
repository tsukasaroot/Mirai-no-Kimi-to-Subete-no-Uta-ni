                //LICENCE
/*        Copyright or © or Copr. ROUCO MIGUEZ Jordan

    jorouco@free.fr

    This software is a computer program whose purpose is to [describe
    functionalities and technical features of your software].

    This software is governed by the CeCILL license under French law and abiding by the rules of distribution of free software. You can use, modify and/ or redistribute the software under the terms of the CeCILL license as circulated by CEA, CNRS and INRIA at the following URL "http://www.cecill.info".

    As a counterpart to the access to the source code and rights to copy, modify and redistribute granted by the license, users are provided only with a limited warranty and the software's author, the holder of the economic rights, and the successive licensors have only limited
    liability.

    In this respect, the user's attention is drawn to the risks associated with loading, using, modifying and/or developing or reproducing the software by the user in light of its specific status of free software, that may mean that it is complicated to manipulate, and that also
    therefore means that it is reserved for developers and experienced professionals having in-depth computer knowledge. Users are therefore encouraged to load and test the software's suitability as regards their requirements in conditions enabling the security of their systems and/or data to be ensured and, more generally, to use and operate it in the same conditions as regards security.

    The fact that you are presently reading this means that you have had knowledge of the CeCILL license and that you accept its terms.
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include<time.h>

#define MAX_LENGTH 2000

void delay(unsigned int mseconds)
{
    ///Créé un délai, utilisations diverses

    clock_t goal = mseconds + clock();
    while (goal > clock());
}

void ClearBuffer()
{
    ///Vide le buffer

    int c = 0;

    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}

void Wrapping(char *string, FILE* filedest)
{
    ///Réecriture des wrapper mot à mot

    int cpt=0;
    char WrappBegin[MAX_LENGTH]="[wrap text=\"", WrappMid[MAX_LENGTH]="\"]", WrappEnd[MAX_LENGTH]=" [w]\n";
    char WordCpy[MAX_LENGTH]="";

    fputs(WrappBegin, filedest);

    for (int j=0; string[j+1] != '\0'; ++j)
    {
        if (string[j] == '"')
        {
            fputc('-', filedest);
        }
        else if(string[j] == '\0')
        {
            fputs(WrappEnd, filedest);
        }
        else
        {
            if (string[j] != ' ')
            {
                WordCpy[j] = string[j];
                fputc(WordCpy[j], filedest);
            }
        }

        if (string[j] == ' ' || string[j+1] == '\n') //Si la condition est vraie, on met le WrappMid, et on entre dans la boucle pour réécrire le mot qui sera affiché dans le jeu, ensuite, on remet un WrappBegin
        {
            fputs(WrappMid, filedest);

            for (cpt; cpt <= j; ++cpt)
            {
                if (string[cpt] != '\0')
                {
                    fputc(string[cpt], filedest);
            	}
            }
            if (string[j+1] != '\n')
            {
                fputs(WrappBegin, filedest);
            }
        }
    }
    fputs(WrappEnd, filedest);
}

void CharRewriter(char *string, FILE* filedest)
{
    ///Appel la fonction wrapping

    Wrapping(string, filedest);
}

void rewrite(char *strings, FILE* filesrc, FILE* filedest)
{
    ///Réecrit toutes les fonctions sauf les dialogues

    fgets(strings, MAX_LENGTH, filesrc);

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
            fputs("\n", filedest);
            fputs(strings, filedest);
        }
        else if (strings[0] == '[')
        {
            fputs(strings, filedest);
        }
        else if (strings[0] != '\0' && strings[0] != '\n')
        {
            CharRewriter(strings, filedest);
        }

        fgets(strings, MAX_LENGTH, filesrc);

        if (feof(filesrc))
        {
            printf("\n\nOperation terminee.\n\n");

            fclose(filedest);
            delay(3000);
        }
    }
}

void CleanerChar(char *string, FILE* filedest)
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

void CleanerStrings(char *strings, FILE* filesrc, FILE* filedest)
{
    ///Réecrit dans un .txt tout sauf les dialogues

    fgets(strings, MAX_LENGTH, filesrc);

    while (!feof(filesrc))
    {
        if (!((strings[0] == '[') && (strings[1] == 'w') && (strings[2] == 'r') || (strings[0] == '[') && (strings[1] == 's') && (strings[3] == 'N')))  //Si c'est des wrapper on passe directement au else
        {
            if (strings[0] == '*')
                fputs("\n", filedest);

            if (strings[0] !=  '\n')
                fputs(strings, filedest);   //écrit la chaine dans le fichier
        }
        else
        {
            CleanerChar(strings, filedest); //on l'envoi à la fonction de nettoyage des wrapper

            printf("%c", strings);
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

int readchar(char *string, int length)
{
    ///Permet de supprimer '\n' de la chaine de caractère

    char *positionEntry = NULL;

    if (fgets(string, length, stdin) != NULL)
    {
        positionEntry = strchr(string, '\n');
        if (positionEntry != NULL)
        {
            *positionEntry = '\0';
        }
        else
        {
            ClearBuffer();
        }
        return 1;
    }
    else
    {
        ClearBuffer();
        return 0;
    }
}

int main()
{
    ///Le main fait l'ouverture du fichier et appelera les fonctions nécessaires au nettoyage ou à la reconstruction des wrapper du fichier entré

	FILE* filesrc = NULL;
	FILE* filedest = NULL;

	int choice = 0;
	char path[100], path2[100], strings[MAX_LENGTH] = "";

	printf("     Program created by Tsukasa, founder of DotHackers\n\n");
	delay(100);

    printf("     Nettoyage = 1\n     Creation du wordwrapping = 2(pas fonctionnel pour le moment)\n\n-> ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        ClearBuffer();

        printf("\n     Indiquer le chemin du fichier a copier.(sans l'extension)\n\n-> ");
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

                long ftell(FILE* filesrc);
                if (ftell != 0)
                {
                    void rewind(FILE* filesrc);//remet le curseur virtuel à zéro
                }

                CleanerStrings(strings, filesrc, filedest);
            }
            fclose(filesrc);
        }
        else
        {
            printf("  Impossible d'ouvrir le fichier source.");
            delay(3000);
            return -1;
        }
    }
    else if (choice == 2)
    {
        ClearBuffer();

        printf("\n     Indiquer le chemin du fichier a reecrire.(sans l'extension)\n\n-> ");
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

                long ftell(FILE* filesrc);
                if (ftell != 0)
                {
                    void rewind(FILE* filesrc);//remet le curseur virtuel à zéro
                }

                rewrite(strings, filesrc, filedest);
            }
            fclose(filesrc);
        }
        else
        {
            printf("  Impossible d'ouvrir le fichier source.");
            delay(3000);
            return -1;
        }
    }
    else
    {
        printf("  Option indisponible.");
        delay(1000);
        return -2;
    }

	return 0;
}