#include <stdio.h>
#include <stdlib.h>

int main()
{
   char CH[100]; /* cha�ne � convertir */
int I; /* indice courant */

/* Saisie de la cha�ne */
printf("Entrez la cha�ne � convertir : ");
gets(CH);
/* Conversion de la cha�ne */
for (I=0; CH[I]; I++)
{
if (CH[I]>='A' && CH[I]<='Z')
CH[I] = CH[I]-'A'+'a';
else if (CH[I]>='a' && CH[I]<='z')
CH[I] = CH[I]-'a'+'A';
}
/* Affichage de la cha�ne convertie */
printf("Cha�ne convertie : %s\n", CH);
return 0;
}


