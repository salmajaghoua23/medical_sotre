#include <stdio.h>
#include <stdlib.h>

int main()
{
  int A[3][4],B[4][2],P[3][2];
  int i,k,j,X;
  printf("veuillez remplit les deux matrices :\n");
  for(i=0;i<3;i++)
    for(k=0;k<4;k++){
        printf("A[%d][%d]=",i,k);
        scanf("%d",&A[i][k]);
    }
    printf("\n");


  for(k=0;k<4;k++)
    for(j=0;j<2;j++){
        printf("B[%d][%d]=",k,j);
        scanf("%d",&B[k][j]);
    }
    printf("\n");

  for(i=0;i<3;i++)
    for(j=0;j<2;j++){
        X=0;
        for(k=0;k<4;k++){
            X+=A[i][k]*B[k][j];
        }
        P[i][j]=X;
  }
  for(i=0;i<3;i++){
    for(j=0;j<2;k++)
        printf("P[%d][%d]=%d",i,j,P[i][j]);

  }
   printf("\n");
    return 0;
}
