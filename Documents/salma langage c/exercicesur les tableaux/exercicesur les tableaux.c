#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A[4][6],T[6][4],j,i;
    for(i=0;i<4;i++){
    for(j=0;j<6;j++){
        printf("A[%d][%d]=",i,j);
        scanf("%d",&A[i][j]);
    }
    printf("\n");
    }
    for(j=0;j<6;j++){
    for(i=0;i<4;i++){
            T[j][i]=A[i][j];
    }
    printf("\n");
    }
    //la matrie transposee//
    printf("A=\n");
    for(j=0;j<6;j++){
     for(i=0;i<4;i++){
            printf("%d\t",A[i][j]);
        }
        printf("\n");
     }
     printf("T=\n");
     for(j=0;j<6;j++){
     for(i=0;i<4;i++){
        printf("%d\t",T[j][i]);
     }
     }
return 0;
}
