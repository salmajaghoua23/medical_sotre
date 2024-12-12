#include <stdio.h>
#include <stdlib.h>
void inverse(int n){
    int r=0;
    do{
        n=n/10;
        r=n%10;

        r=r*10+r;
    }while(n>10);
}

int main()
{//calcul le nombre des chiffre//
   /* double n ,m;
    int q=0;
    printf("veuillez entrer le nombre choisie\n :");
    scanf("%ld",&n);
    m=n;

    do{
     q++;
     n=n/10;
    }while(n!=0);
    printf("le nombre des chiffre est %d\n",q);
    return 0;
    int n,m;
    int r=0;
    printf("veuillez entrer le nombre n :");
    scanf("%d",&n);
    m=n;
    do{
        r=r*10+ m%10 ;
        m=m/10;
    }while(m !=0);
    printf("voici l'inverse de n=%d\n",r);

    if((int)r==(int)n)
        printf("le nombre est palandrome\n ");
    else
        printf("ce nombre n'est pas palandrome\n");
        int l,c                                         //programme d'un inverse et palandromme//
        int i,j;
        do{
        printf("veuillez entrer le nombre des lignes et des colonnes ");
        scanf("%d%d",&l,&c);
        }while(l<0 || c<0);
        for(i=0;i<l;i++){
                printf(" * ");
               for(j=0;j<c;j++){    //programme d'un rectanle d'etoile//
                    printf(" * ");

        }
        }
        printf(" \n");*/
   /*   int l;
      int i,j;
      do{
      printf("donner le nombre des lignes ")   ;
      scanf("%d",&l);
      }while(l<=0);
      for(i=0;i<l;i++){
        for(j=0;j<l;j++){
            printf(" * ");
            if(i==j    //programme d'un triangle d'etoile//
              break;
            else
                printf(" ");


        }
        printf("\n");
      }*/
      /*
int l,c;
int i,j;
do{
printf("veuillez entrer le nombre des lignes et des colonnes ");
scanf("%d%d",&l,&c);
}while(l<=0 || c<=0);
for(i=0;i<=l;i++){
        for(j=0;j<=c;j++){
        if(i==0 || i==l || j==0 || j==c)
        printf(" * ");
        else
            printf("   ");                //programme d'un cadre rectangle//
    }
    printf(" \n");
}*/
int i,j;
int l,c;
 do{
        printf("veuillez entrer le nombre des lignes et des colonnes ");
        scanf("%d%d",&l,&c);
        }while(l<0 || c<0);
for(i=1;i<=l;i++){
    for(j=1;j<=c;j++){
        if(i==1 || i==l || j==1 || j==c || j==i || j==l-i+1)
            printf(" * ");
        else
            printf("   ");
    }
printf("\n");

}
}
