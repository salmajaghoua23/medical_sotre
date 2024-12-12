#include <stdio.h>
#include <stdlib.h>

int main()//exercice 11
{
   int N,x,S=0,P=1,i;
   float M;
   do{
    printf("saisir N");
    scanf("%d",&N);

   }while(N<=0);
   for(i=0;i<N;i++){
    printf("saisir x");
    scanf("%d",&x);
    S=S+x;
    P=P*x;
   }
   printf("la somme est %d",S);
   printf("le produit est %d",P);
   M=S/P;
   printf("la moyenne est %f",M);

    return 0;
}
