#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N,i=0 ,S=0;
    printf("veuillez entrer un entier ", N);
    scanf("%d",&N);
    do{
        if(i%2!=0){
          S=S+i;
          i++;
            }

    }while(i>N);
    printf("la somme est des N premiers termes psitifs impairs :",S);
    return 0;
}
