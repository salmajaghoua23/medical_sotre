#include <stdio.h>
#include <stdlib.h>

int main()
{
 /*  int n,som=0,i;
   int *p;
   printf("veuillez saisir la taille du tableaux :\n");
   scanf("%d",&n);
    p=(int *)malloc(n * sizeof(int));
   if (p==NULL){
    printf("l'espace est insuffisante");
   }
   else{
    for(i=0;i<n;i++){
        printf("l'element du tab est %d\t",i+1);
        scanf("%d",(p+i));
    }
    for(i=0;i<n;i++){
        printf("%d",p);
        som+=*(p+i);
   }
   printf("la somme est som=%d\n",som);
   }
   free(p);
    return 0;*/





/*    int *p;
    int *SU=(int *)malloc(4);
    int *t;
    printf("veuillez entrer le prix de revient \n :");
    scanf("%d",p);
    p=(int*)malloc(sizeof(int));
    printf("veuillez enter le prix de vente:\n ");
    scanf("%d",t);
    t=(int*)malloc(sizeof(int));
  *SU=*p-*t;
  if(*SU>0)
    printf("tu es profit\n");
  else if (*SU<0)
    printf("tu es pert\n");
    else
        printf("ni pert ni profite");
free(p);
free(t);
free(SU);*/

int *t=malloc(sizeof(int));
int i;
int *somme=malloc(sizeof(int));
printf("donner la taille du tab n \n");
scanf("%d",t);
*somme=0;
for(i=1;i<=*t;i++)
{
    if(i%2!=0){
        *somme= *somme + i;
        i++;
    }
    else
        break;
}
printf("la sommme est =%d\n",*somme);
free(t);
free(somme);





}
