#include <stdio.h>
#include <stdlib.h>

int main()
{// calcule la longeur d'une chaine de caractere //
   char prenom[20],i;
   int L=0;

   printf("veuilez saisir votre prenom :");
   gets(prenom);
   for(i=0;i<20;i++){
    if(prenom[i]!='\0'){
        L++;
   }
   else
    break;

   }

   puts(L);

    return 0;
}
