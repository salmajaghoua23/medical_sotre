#include <stdio.h>
#include <stdlib.h>
#define N 10
void echange(int *x,int *y){
    int t;
    printf("avant: %d %d\n",*x,*y);
    t=*x;
    *x=*y;
    *y=t;
    printf("apres %d %d\n",*x,*y);
}
/*void max_min(int t[],int n,int *p1,int *p2){
    int i,min,max;
    max=t[0];
    for(i=1;i<n;i++)
        if(max<t[i])
        max=t[i];
    min=t[0];
    for(i=1;i<n;i++)
        if(min>t[i])
        min=t[i];
    *p1=max;
    *p2=min;

    }*/
void max_min(int t[],int n,int *admax,int *admin)
{
    int i;
    *admax=t[0];
    *admin=t[0];
    for(i=1;i<n;i++){
        if(*admin>t[i])
            *admin=t[i];
        if(*admax<t[i])
            *admax=t[i];
    }
    printf("max=%d et min=%d\n",*admax,*admin);
}


int main()
{
   /* int x,y;
    printf("veuillez entrer deux valeurs :\n");
    scanf("%d%d",&x,&y);
    echange(&x,&y);                                                 //programme
    printf("dans le main %d %d\n",x,y);
    return 0;*/
  /* int t[3]={1,0,9} ;
   int max,min;
   max_min(t,3,&max,&min);
   printf("le max est max=%d \n",max);
    printf("le min est min=%d \n",min);*/

  /*  int t[50];
    int n,max,min;
    printf("veuillez entrer la taille du tableaux choisie \n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("t[%d]=",i);
        scanf("%d",&t[i]);
        printf("%d",t[i]);

    }
    max=t[0];
    min=t[0];
    max_min(t,n,&max,&min);
    printf("max=%d et min =%d\n",max,min);*/




    //exercice 6//
    //utilisation d'un autre tableaux//
   /* int t[5]={1,2,3,4,5};
    int A[5];
    int i;
    for(i=1;i<=5;i++){
        A[i]=t[5-i];
        printf("%d\t",A[i]);

    }*/



    //en utilsant un seul tableaux//
   /* int t[50];
    int n;
    int *p=&t;
    printf("veuillez entrer la taille du tab \n");
    scanf("%d",&n);
    for(p=t;p<=t+n;p++){
        printf("t[%d]=\t",p-t+1);
        scanf("%d",p);
    }
    for(p=t+n;p>=t;p--){
        printf("t[%d]=%d\t",p-t-n+1,*p);
    }
*/


int tab[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int *p = &tab[0], *q = &tab[N-1], temp;
while (p < q){
temp = *p;
*(p++) = *q;
*(q--) = temp;
}
for(p=tab;p<tab+10;p++)
    printf("tab[%d]=%d\t",p-tab+1,*p);
}
