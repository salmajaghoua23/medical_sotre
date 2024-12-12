#include <stdio.h>
#include <stdlib.h>
#include<math.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/*c'est l'exercice 12 la question n=2*/
int main() {
	int n,i;
	float s=0;
	printf("veuillez entrer un entier positif n\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
        s=s+1/pow(2,i);
    printf("la somme des element sont %f ",s);
	return 0;
}



   int N,i,somme,N_inf;
    printf("veuillez entrer une valeur entier %d :");
    scanf("%d",&N);
    somme=0
    do{
    for(i=0;i<=N;i++){
        somme=somme+pow(2,i);
    }
        }while(somme>1000);
       N_inf= somme;
       printf("la plus grande inferieur a 1000 de la somme est %d",N_inf);

    }


}
