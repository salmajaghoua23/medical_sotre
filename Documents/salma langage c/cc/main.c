#include <stdio.h>
#include <stdlib.h>

int main()
{
   char CH[100]; /* chaîne à convertir */
int I; /* indice courant */

/* Saisie de la chaîne */
printf("Entrez la chaîne à convertir : ");
gets(CH);
/* Conversion de la chaîne */
for (I=0; CH[I]; I++)
{
if (CH[I]>='A' && CH[I]<='Z')
CH[I] = CH[I]-'A'+'a';
else if (CH[I]>='a' && CH[I]<='z')
CH[I] = CH[I]-'a'+'A';
}
/* Affichage de la chaîne convertie */
printf("Chaîne convertie : %s\n", CH);
return 0;
}


