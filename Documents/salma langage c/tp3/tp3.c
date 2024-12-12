#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int main()
{//exercice 1tp3
/*

int a,b,c;
float delta,x1,x2;
printf("saisir a,b et c\n");
scanf("%d%d%d",&a,&b,&c);
if(a==0 && b==0 && c==0)
    printf("R");
else if (a==0 && b==0){
    printf("aucun solution");
}
else if(a==0){
    x1=(float)-c/b ;
    printf ("la solution %f est ",x1);
}
else{
    delta=b*b-4*a*c ;
    if (delta<0)
        printf("n'est pas de solution dans R");
    else if(delta==0){
        x1=(float)-b/2*a ;
        printf("la solution %f est",x1);
    }
    else{
        x1=(-b+sqrt(delta))/2*a ;
        x2=(-b-sqrt(delta))/2*a ;
        printf("les solution %f=x1 et %f=x2 sont",x1,x2);
    }
}

   return 0;
}//exercice 2 tp3
int tab[3]={2,-4,8};
int X;
tab[0]=0;
tab[1]=1;
tab[2]=2;
X=tab[0];
tab[0]=tab[2];
tab[2]=tab[1];
tab[1]=X;
printf("tab[0]=%d\n",tab[0]);
printf("tab[1]=%d\n",tab[1]);
printf("tab[2]=%d\n",tab[2]);

return 0;
int tab[10];
int i;
for(i=0;i<10;i++)
    printf("tab[%d]=%d \n",i,tab[i]);

    printf("\n");

for(i=0;i<10;i++)
    tab[i]=0;
for(i=0;i<10;i++)
    printf("tab[%d]=%d\n",i,tab[i]);

*/
//exercice 3 tp 3
int tab[10],i,SOMME=0;
int min;
for(i=0;i<10;i++){
    printf("tab[%d]=",i);
    scanf("%d",&tab[i]);
    SOMME+=tab[i];
}
min=tab[0];
for(i=0;i<10;i++){
    if(min>tab[i])
        min=tab[i];
}
printf("le min %d est",min);
}

