#include <stdio.h>
#include <stdlib.h>
#include<math.h>

void tabl_mult(int x)
{
    int i;
    int p=1;
   printf("veuillez entrer le nombre \n");
   scanf("%d",&x);
   printf("-------- table de multiplication de x=%d --------\n",x);
   for(i=1;i<=10;i++)
   {
       p=x*i;
       printf("x * %d = %d\t",i,p);
       printf("\n");
   }
}
void bissextile (int *annee)
{
    if(((*annee)%100==0 &&(*annee)%4!=0) || *annee%400==0)
        printf("%d une annee bissextile \n",*annee);
    else
        printf("%d n'est pas une annee bisextille \n",*annee);
}
void nbr_premier(int *x)
{
    int i;
    for(i=2;i<sqrt(*x);i++)
    {
        if(*x%i!=0)
            printf("%d est  un nmbre premier :\n ",*x);
        else
            printf("n'est pas un nmbre premier:\n");
    }
}
int chiffres(int *x)
{
    int i=0;

    while(*x!=0)
    {
        *x = *x /10;
        i++;
    }
    return i;
}
int main()
{
  /*  int t[10],ti[10],tp[10];
    int i,ip=0,pp=0;
    printf("veuillez remplir le tableaux t\n");
    for(i=0;i<5;i++)
    {
        printf("t[%d]=\t",i);
        scanf("%d",&t[i]);
    }
    for(i=0;i<5;i++)
        tp[i]=0;
    for(i=0;i<5;i++)
        ti[i]=0;
    for(i=0;i<5;i++)
    {
        if(t[i]%2==0){
            tp[ip]=t[i];
            ip++;
        }
        else{
            ti[pp]=t[i];
            pp++;

        }
} for(i=0;i<ip;i++)
        printf("%d\t elements du tab paire\n",tp[i]);
    for(i=0;i<pp;i++)
        printf("%d\t elements du tab  impaire\n",ti[i]);


        */



/*
        int t[8];
        int i;
        int tmp;
        printf("veuillez entrer les elements du tableaux\n");
        for(i=0;i<8;i++)
        {
            printf("t[%d]=\t",i+1);
            scanf("%d",&t[i]);
        }
        tmp=t[0];
        for(i=1;i<8;i++)
            for(int j=0;j<8;j++)
        {
            if(t[i]>t[j]){
                tmp=t[j];
                t[j]=t[i];
                t[i]=tmp;
            }

        }


///////----------table de  multiplication----------//////////
        for(i=0;i<8;i++)
            printf("%d\t",t[i]);*/
          /*int x;
            tabl_mult(x);*/



/////////programme d'une annee bissextile---------------//////
          /*  int annee;
            printf("veuillez entrer une annee \n");
            scanf("%d",&annee);
            bissextile(&annee);*/




    //////nmbre premier ou non -------///
    /*int x;
    printf("veuillez eentrer un nmbre :\n");
    scanf("%d",&x);
    nbr_premier(&x);
*/




//////nbre de chiffre dans un nombre////


int x;
printf("veuillez entrer un nombre entier \n");
scanf("%d",&x);
printf("le nombre de chiffre de %d est %d :\n",x,chiffres(&x));


    return 0;
}
