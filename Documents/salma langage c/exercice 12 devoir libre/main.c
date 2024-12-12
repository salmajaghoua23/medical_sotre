#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int main()
{
   /*int N ,i ,SOMME;
    printf("veuillez entrer un entier ",N);
    scanf("%d",&N);
    SOMME=0;
    for (i=0;i<=N;i++){
        if(i%2)
            SOMME+=i;

    }
    printf("SOMME=%d",SOMME);
return 0;
int N, somme, i;
 printf("Entrez le nombre N: ");
 scanf("%d", &N);
 somme = 0;
 for (i = 1; i <= 2 * N; i++){
 if (i % 2)
 somme += i;
 }
 printf("Donc la somme est: %d\n", somme);*/
 int i=2;
 float somme=0;
 do{
    somme+=1+pow(-1,i)/i ;
    printf("la valeur de i c'est :",i);
    i++;
 }while(somme !=1.33);

}

