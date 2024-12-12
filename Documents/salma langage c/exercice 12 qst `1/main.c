#include <stdio.h>
#include <stdlib.h>

int main()
{
   { // programme qui calcul la somme des  N pemiers termes impairs.
    int N,i,SOM=0;
    printf("veuillez entrer un entier N :");
    scanf("%d",&N);
    for (i=0;i<=N;i++){
        SOM+=(i%2)  ?i : 0 ;
    }
    printf("la somme des N premier termes positifs impairs : %d",SOM);
    return 0;
}
    return 0;
}
