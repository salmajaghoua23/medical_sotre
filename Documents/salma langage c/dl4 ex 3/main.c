#include <stdio.h>
#include <stdlib.h>

int main()
{//formalisme tableaux a deux indices//
  /* int t[3][4];
   int i,j,som=0;
   printf("veuillez remplir le tableaux :\n");
   for(i=0;i<3;i++){
    for(j=0;j<4;j++){
        printf("t[%d][%d]=\t",i,j);
        scanf("%d",&t[i][j]);
    }
   }
   for(i=0;i<3;i++){
    for(j=0;j<4;j++){
        som+=t[i][j];
            }
   }
   printf("la somme est som=%d",som);
    return 0;*/











    //formalisme pointeurs//
   int t[3][4];
    int *p;
    int i,j,SOM=0;
    p=(int *)t;
     printf("veuillez remplir le tableaux :\n");
   for(i=0;i<3;i++){
    for(j=0;j<4;j++){
        printf("t[%d][%d]=\t",i,j);
        scanf("%d",&t[i][j]);
    }
   }
   for(i=0;i<3;i++)
    for(j=0;j<4;j++)
            printf("%d\t",t[i][j]);
   for ( i =0; i <15; i ++)
             SOM += *(p + i );
    printf("la somme est SOM =%d",SOM);

}

