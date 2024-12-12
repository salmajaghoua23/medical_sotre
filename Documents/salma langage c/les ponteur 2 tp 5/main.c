#include <stdio.h>
#include <stdlib.h>
void echange(int *x,int *y){
    int t;
    printf("avant: %d %d\n",*x,*y);
    t=*x;
    *x=*y;
    *y=t;
    printf("apres %d %d\n",*x,*y);
}
void max_min(int t[],int n,int *p1,int *p2){
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

    }


int main()
{
   /* int x,y;
    printf("veuillez entrer deux valeurs :\n");
    scanf("%d%d",&x,&y);
    echange(&x,&y);                                                 //programme
    printf("dans le main %d %d\n",x,y);
    return 0;*/
   int t[3]={1,0,9} ;
   int max,min;
   max_min(t,3,&max,&min);
   printf("le max est max=%d \n",max);
    printf("le min est min=%d \n",min);
}
