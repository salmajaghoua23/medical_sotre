#include <stdio.h>
#include <stdlib.h>
int  produit_somme(int *ptab,int *pn)
{
   int tab[100] ;
   int p=1,s=0;
   *ptab=tab;
   for(ptab=tab;ptab<tab+(*pn);ptab++){
    p=p* *ptab +p;
    s+= *ptab;
   }
return s;
}
int main()
{
  int tab[100];
  int *p,n,z;
  p=tab;
        printf("veuillez choisie la taille du tab\n");
        scanf("%d",&n);
        printf("veuillez remplir le tab \n");
        for(p=tab;p<tab+n;p++){
            printf("tab[%d]=",p-tab+1);
            scanf("%d",p);
        }
      z=  produit_somme(&p,&n);
        printf("z=%d",z);
    return 0;
}
