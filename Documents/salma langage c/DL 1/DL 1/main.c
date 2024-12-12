#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int main()
{

    int  i,N,S=0;
    printf("veuillez entrer une valeur de N positif ");
    scanf("%d",&N);
   do{
      for(i=0;i<=N;i++)
        S=S+pow(2,i);
    }while(S>1000);
    printf("le plus grande valeur inf a 1000 de la somme est %d :",S);

    return 0;
}
{
    int N,i;
    float SOMME=1.0;
    do{
        for(i=1;i<=N;i++){
            SOMME +=pow(-1,i)/i;
            }
            printf("N=%d",i);

    }while(SOMME!=1.33);

}
