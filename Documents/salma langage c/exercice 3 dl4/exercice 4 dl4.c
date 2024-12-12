#include <stdio.h>
#include <stdlib.h>
//programme qui calcul la somme des elements d'un tab//
int main()
{
int t[3][4];
  int *p;p=(int*)t;
  int i,j,som=0;
  printf("veuillez remplir les elements du tab \n");
  for(i=0;i<3;i++){
    for(j=0;j<4;j++){
        printf("t[%d][%d]=",i,j);
        scanf("%d",&t[i][j]);
    }
    printf("\n");
  }
  for(i=0;i<12;i++){
    som+=*(p+i);
  }
  printf("la somme est som=%d\n",som);
    return 0;
}
int main(){
//formalisme tableaux a deux indices//
   int t[3][4];
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
    return 0;
}
