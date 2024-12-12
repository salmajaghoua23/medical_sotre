#include <stdio.h>
#include <stdlib.h>
#include<string.h>
 main()
{ /* int p,q,aux;

printf("donner deux nombre a permuter  :",p,q);
scanf("%d%d",&p,&q);
aux=p;
p=q;
q=aux;
printf ("les nombres a permuter sont %d et %d",p,q);
*/
char ch1[30],ch2[30];
char ch3[20],ch4[20];
int y,x;
printf("ecrire la premier chaine de caractere \n:");
scanf("%s",ch1);
printf("ecrire la duexiemie chaine de caractere \n:");
scanf("%s",ch2);
y=strlen(ch1);
x=strlen(ch2);
strncpy(ch3,ch1,y/2);
strncpy(ch4,ch2,x/2);
strcat(ch3,ch4);
ch3[y/2 + x/2]='\0';
printf("la chaine est %s\n :",ch3);
    return 0;
}
