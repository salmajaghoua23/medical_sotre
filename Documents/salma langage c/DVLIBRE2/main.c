#include <stdio.h>
#include <stdlib.h>

int main()
{
    int C[50][50],D[50][50],P[50][50];
    int i,j,k;
    int M,L,N,X;
    do{
        printf("veuillez entrer le nombre des lings de C :");
        scanf("%d",&M);
        printf("veuillez entrer le nombre des Colonne de C :");
        scanf("%d",&L);
    }while((M>50 || M<=0)&&(L<=0 || L>50));
     do{
        printf("veuillez entrer le nombre des Colonne de D :");
        scanf("%d",&N);
    }while(N>50 || N<=0);
    for(i=0;i<M;i++)
        for(k=0;k<L;k++){
            printf("C[%d][%d]=",i,k);
            scanf("%d",&C[i][k]);
        }

    for(k=0;k<L;k++)
        for(j=0;j<N;j++){
            printf("D[%d][%d]=",k,j);
            scanf("%d",&D[k][j]);
        }
        printf("\n");

    for(i=0;i<M;i++)
         for(j=0;j<N;j++){
                X=0;
               for(k=0;k<L;k++){
                  X+= C[i][k]*D[k][j];
                  }
                 P[i][j]=X;
        }

   for(i=0;i<M;i++)
     for(j=0;j<N;j++){
    printf("P[%d][%d]=%d\t",i,j,P[i][j]);
     }
     printf("\n");



    return 0;
}
