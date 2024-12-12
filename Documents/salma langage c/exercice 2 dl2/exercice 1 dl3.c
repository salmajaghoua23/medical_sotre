#include <stdio.h>
#include <stdlib.h>

int main()
{int i,n;
float x,a,res;
do{
    printf("entrer le degre de polynome n :");
    scanf("%d",&n);
}while(n<=0);
printf("veuillez entrer x\n :");
scanf("%f",&x);
printf("veuillez entrer le coiff ");
scanf("%f",&a);
res=a;
 for(i=n-1;i>0;i--){
    printf("veuillez entrer le coiff de x ");
    scanf("%f",&a);
    res=res*x+a;

 }
 printf("le resultat est %f\n",res);
    return 0;
}
