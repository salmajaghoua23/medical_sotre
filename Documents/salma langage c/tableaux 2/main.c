#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T[4][5],i,j;
    for(j=0;j<5;j++){
        for(i=0;i<4;i++){
        printf("T[%d][%d]=",i,j);
        scanf("%d",&T[i][j]);
        }
    }
    printf("T[0][%d]=",T[0][j]);

    return 0;
}
