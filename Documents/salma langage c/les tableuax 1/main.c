#include <stdio.h>
#include <stdlib.h>

int main()
{   int tab[50],N,i;
    float moy=0;
do{
    printf("veuillez entrer un entier N :");
    scanf("%d",&N);
}while(N<=0 || N>50);
   for(i=0;i<N;i++){
    printf("tab[%d]=",i);
    scanf("%d",&tab[i]);
    moy=(float)(tab[i]+moy)/N;
   }
   printf("la moyenne = %.2f ",moy);


    return 0;
}



   float t[50],max;
   int N,i;
do{
    printf("veuillez entrer des elements entiers :");
    scanf("%d",&N);
}while(N>50 || N<=0);
max=t[0];
for(i=0;i<N;i++){
    printf("t[%f]="i);
    scanf("%f",&t[i]);
    if(t[i]>max)
        max=t[i];
}
printf("le maximale est%f ",max);

}
