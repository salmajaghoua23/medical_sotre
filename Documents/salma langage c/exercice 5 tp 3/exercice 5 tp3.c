#include <stdio.h>
#include <stdlib.h>
int strcomp(char ch1[],char ch2[]){
    int i;
    for(i=0;ch1[i]==ch2[i]&& ch1[i] != '\0';i++);
    if(ch1[i]==ch2[i])
        return 0;
    if(ch1[i]<ch2[i])
        return -1;
    else
        return 1;
}
int main(){
char chaine1[20],chaine2[20];
int x;
printf("veuillez entrer deux chaines de caractere \n :");
gets(chaine1);
gets(chaine2);
x=strcomp( chaine1,chaine2);
printf("la comparaison est donne le resultat suivants %d",x);
}
