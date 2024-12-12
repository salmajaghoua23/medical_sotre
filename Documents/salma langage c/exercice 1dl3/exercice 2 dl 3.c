#include <stdio.h>
#include <stdlib.h>
void tabl_mult(int x,int y){
    int i,j;
    printf(" x*y |  ");
    for(i=0;i<10;i++)
        printf("%d\t",i);
    printf("\n");
    for(i=0;i<10;i++)
           printf("---------");
    printf("\n");
    for(i=0;i<10;i++){
            printf("%d\t",i);
        for(j=0;j<10;j++){
            printf("%d\t",i*j);
        }
        printf("\n");
    }



}

int main()
{ int x,y;
 tabl_mult(x,y);
 return 0;
}
