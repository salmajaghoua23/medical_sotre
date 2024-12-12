#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
int somme(int x,int y){
    return x+y;
}
int sous (int x,int y){
    return x-y;
}
int mult(int x,int y){
    return x*y;
}
float division(int x,int y){
    return x/y;
}
int main()
{ int x,y,ch;
do{;
printf("veuillez entrer dex nombre entier :");
scanf("%d%d",&x,&y);

printf("0=quitee\n");
printf("1=somme\n");
printf("2=soustraction\n");
printf("3=multiplication");
printf("4=division\n");
printf("veuilez entrer votre choix \n");
scanf("%d",&ch);
switch(ch){
    case 1:printf("x+y",somme(x,y));
          break;
    case 2:printf("x-y",sous(x,y));
        break;
    case 3:printf("x*y",mult(x,y));
         break;
    case 4:printf("x/y",division(x,y));
break;
    case 0:printf(" fin de programme\n");
    break;
    default :printf("erronee\n");
}
getch();
}while(ch==0);

    return 0;
}
