#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A[50][50];
    int i,j,L,C,N,SOMME=0;
    float det(A);
    printf("veuillez donner l'ordre du matrice chiosie :");
    scanf("%d",&N);
    do{
      printf("veuillez entrer un nombre entier des colonnes :  ");
      scanf("%d",&L);
      printf("veuillez entrer un nombre entier des lingne : ");
      scanf("%d",&C);
    }while((L>N || L<=0) &&(C>N ||C<=0));
    for(i=0;i<=N;i++)
    for(j=0;j<=N;j++){
        printf("A[%d][%d]=",i,j);
        scanf("%d",&A[i][j]);
    }
    return 0;
}
