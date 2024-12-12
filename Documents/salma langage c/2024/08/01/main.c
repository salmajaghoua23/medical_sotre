#include <stdio.h>
#include <stdlib.h>
#define  N 10
void somme_produit(int t[],int *n)
{
    int s=0,p1=1;

    for(int i=0;i<*n ;i++)
    {
        s+=t[i];
        p1*=t[i];
    }
    printf("la somme des elements du tableaux s=%d :\n",s);
    printf("le produit des elements du tableaux p=%d\n",p1);

}
void oc (int tab[]){
    int *p1, *p2;
    int tmp;
    p1=tab;
    printf("voicie les elements croissante :\n");
    for(p1=tab;p1<tab+N;p1++)
        for(p2=tab+1;p2<tab+N;p2++)
    {
        if(*p1>*p2){
            tmp=*p1;
            *p1=*p2;
            *p2=tmp;
        }
    }
    for(p1=tab;p1<=tab+N;p1++)
        printf("%d\t",*p1);
  printf("voicie les elements decroissantes :\n") ;
  for(p1=tab;p1<tab+N;p1++)
    for(p2=tab+1;p2<tab+N;p2++)
  {
      if(*p2>*p1){
        tmp=*p2;
        *p2=*p1;
        *p1=tmp;
      }
  }

}

int main()
{
  /*  int t[20],n,i;
    int *p=&t;
    printf("veuillez entrer la taille du tableaux t\n");
    scanf("%d",&n);
    printf("veuillez remplir le tableaux t :\n");
    for(i=0;i<n;i++)
    {
        printf("t[%d]=\t",i);
        scanf("%d",&t[i]);
    }
    printf("voicie la somme est le produit des elements du tableaux :\n" );
    somme_produit(p,&n);*/


    int tab[N];
    for(int i=0;i<N;i++){
        printf("tab[%d]=\t",i);
        scanf("%d",tab+i);
    }
    int*p=&tab;
    oc(p);

}
