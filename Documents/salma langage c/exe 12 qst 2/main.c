#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int main()
{
  //programme qui calcul la somme .
  int i,N;
  float SOMME=0;
  printf("veuillez entrer un entier strictement positive :");
  scanf("%d",&N);
  for(i=0;i<=N;i++){
    SOMME+=1/pow(2,i) ;
  }
  printf("la somme est :SOMME=%f",SOMME);
    return 0;
}
