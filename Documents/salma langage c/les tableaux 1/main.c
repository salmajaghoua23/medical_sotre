#include <stdio.h>
#include <stdlib.h>

int main()
{
 /*  int tab[50],i,N;
   int s=0,p=1;
   float moy;
   do{
    printf("veuillez entrer un nombre n entier :");
    scanf("%d",&N);
   }while(N>50 || N<=0);
   for(i=0;i<N;i++){
    printf("tab[%d]=",i);
    scanf("%d",&tab[i]);
   }
   for(i=0;i<N;i++){
    s+=tab[i];
    p*=tab[i];
   }
   moy=(float)s/p ;
   printf("s=%d et p=%d et moy=%.2f :",s,p,moy);
    return 0;
    */
    int L,C,i,j;
    int tab[50][50];
    do{
        printf("veuillez entrer le nombre des lings et des colonne :");
        scanf("%d%d",&L,&C);
    }while((L<=0 || L>50)&&(C<=0 || C>50));
    for(i=0;i<L;i++){
        if(i%2==0){
            for(j=0;j<C;j++){
                printf("tab[%d][%d]=",i,j);
                scanf("%d",tab[i][j]);
            }
        }
        else{
            for(j=C-1;j>=0;j--)
                printf("tab[%d][%d]=",i,j);
                scanf("%d",tab[i][j]);
        }
    }
}

