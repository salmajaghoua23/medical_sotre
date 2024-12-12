#include <stdio.h>
#include <stdlib.h>
int longeur(char ch[]){
    int l;

    l=0;
while(ch[l] != '\0'){
    l++;
}
return l;
}

int main()
{int x;
 char S[100];
 printf("saisir la chaine de caractere \n :");
 gets(S);
 x=longeur(S);
 printf("la longeur est %d ",x);

    return 0;
}
