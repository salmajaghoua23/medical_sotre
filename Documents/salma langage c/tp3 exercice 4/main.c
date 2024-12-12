#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A[10][10],B[10][10],S[10][10];
    int i,j,L,C;
    do{
        printf("veuillez entrer le nombre des linges et des colonnes \n :");
        scanf("%d%d",&L,&C);
    }while((L<=0 || L>10) &&(C<=0 || C>10));
    for(i=0;i<L;i++)
    for(j=0;j<C;j++){
        printf("A[%d][%d]=\t",i,j);
        scanf("%d",&A[i][j]);
    }
    printf("\n");
    for(i=0;i<L;i++)
    for(j=0;j<C;j++){
        printf("B[%d][%d]=\t",i,j);
        scanf("%d",&B[i][j]);
    }
    printf("\n");

    for(i=0;i<L;i++){
    for(j=0;j<C;j++){
        S[i][j]=A[i][j]+B[i][j];
    }
    printf("\n");
    }
    for(i=0;i<L;i++){
    for(j=0;j<C;j++){
            printf("%d\t",S[i][j]);
    }
    printf("\n");
}



    return 0;
}
