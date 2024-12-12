#include <stdio.h>
#include <stdlib.h>

int main()
{
    //fonction strlength//
    char chaine[20];
    int i,L=0;
    printf("veuillez entrer la chaine de caractere\n :");
    gets(chaine);
    for(i=0;i<20;i++){
        if(chaine[i]!= '\0')
            L++;
        else
            break;
    }
    printf("longeur de votre chaine de caractere est %d lettre",L);

    return 0;*/
    //fonction strcomp//
    char chaine1[20],chaine2[20];
    int i;
    printf("veuillez entrer une chaine de caracter \n :");
    gets(chaine1);
    printf("veuillez entrer une chaine de caracter \n :");
    gets(chaine2);
    for(i=0;i<20;i++)
        if(chaine1[i]>chaine2[i])
             printf("alors chaine1 precede chaine2  donc -1");

       else if (chaine1[i]==chaine2[i])
        printf("sont egaux donc 0");


}


