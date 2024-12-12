#include <stdio.h>
#include <stdlib.h>
#include<string.h>


void inverser (char c1[],int n)
{
    int c2[strlen(c1)];
    int i,j;
    puts("veuillez donner une chaine de caracter:\n");
    gets(c1);
    for(i=0;c1[i]!='\0';i++){
            j=i+1;
        c2[j]=c1[n-i];
        j++;
    }
    printf("la longeurs de la deuxieme chaine est %d  :\n",j);
}

int main()
{ char CH1[101], CH2[101]; /* chaînes données */
char *P1, *P2; /* pointeurs d'aide dans CH1 et CH2 */
int TROUVE; /* indicateur logique: vrai, si le caractère */
/* actuel dans CH1 a été trouvé dans CH2. */

/* Saisie des données */
printf("Entrez la chaîne à transformer"
" (max.100 caractères) :\n");
gets(CH1);
printf("Entrez la chaîne à supprimer "
" (max.100 caractères) :\n");
gets(CH2);
/* Rechercher CH2 dans CH1 : */
/* L'expression P2-CH2 est utilisée pour déterminer l'indice */
/* de P2 dans CH2. On pourrait aussi résoudre le problème à */
/* l'aide d'un troisième pointeur P3 parcourant CH1. */
TROUVE=0;
for (P1=CH1 ; *P1 && !TROUVE ; P1++)
{
for (P2=CH2 ; *P2 == *(P1+(P2-CH2)) ; P2++)
;
if (!*P2)
TROUVE = 1;
}

/* A la fin de la boucle, P1 est incrémenté, donc */
P1--;
/* Si CH2 se trouve dans CH1, alors P1 indique la position */
/* de la première occurence de CH2 dans CH1 et P2 pointe à */
/* la fin de CH2. (P2-CH2) est alors la longueur de CH2. */
if (TROUVE)
strcpy(P1, P1+(P2-CH2));

/* Affichage du résultat */
printf("Chaîne résultat : \"%s\" \n", CH1);
return 0;
}
