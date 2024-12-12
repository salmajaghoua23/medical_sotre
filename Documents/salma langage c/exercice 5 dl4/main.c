#include <stdio.h>
#include <stdlib.h>
void produit_somme(int *ptab,int *pn,int *som,int *p)
{ int t[100];
  ptab=t;
  *som=0;
  *p=1;
  for(ptab=t;ptab<t+(*pn);ptab++){
    printf("t[%d]=\n",ptab-t+1);
    scanf("%d",ptab);
  }

   for(ptab=t;ptab<t+(*pn);ptab++){
    *som= *som + *ptab;
    *p*=*ptab;
   }

}
int main()
{
    int t[100],n,som,p;
    printf("veuillez entere la taille du tab \n");
    scanf("%d",&n);
    printf("veuillez saisir les elements du tab\n");
    produit_somme(t,&n,&som,&p);
    printf("la somme et le produit som=%d et p=%d",som,p);
    return 0;
}
