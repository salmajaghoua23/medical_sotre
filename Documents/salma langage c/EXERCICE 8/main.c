#include <stdio.h>
#include <stdlib.h>


int main()
{   int m,ms,jp,js,annee;

    printf("veuillez entrer l'annee :");
    scanf("%d",&annee);
    do{
    printf("veuillez entrer un mois\n et son premier jour sachant que 0(dimanche).....6(samedi) \n :");
    scanf("%d%d",&m,&jp);
}while((m<=0 || m>12) && (jp<0 || jp>6));
    if(m!=2){
            if(m==1 || m==3 || m==5 || m==7 || m==9 || m==10 || m==12){
                js=(31%7)+jp;
            }
            else {
                js=(30%7)+jp;
            }
    }
    else {
        if((annee%4==0 && annee %100!=0)||(annee%400==0)){
            js=(29%7)+jp;
        }
        else {
            js=(28%7)+jp;
    }
    }
    switch (js){
    case 0 : printf("dimanche");
           break;
    case 1 :printf("lundi");
            break;
     case 2 : printf("mardi");
           break;
    case 3 :printf("mercredi");
            break;
    case 4 : printf("jeudi");
           break;
    case 5 :printf("vendredi");
            break;
    case 6 : printf("samedi");
           break;
    }
    ms=m+1;
    printf(" le premier jour est %d\n",js);
    printf("et le mois suivants %d\n",ms);

    return 0;
}
int main()
{

}
