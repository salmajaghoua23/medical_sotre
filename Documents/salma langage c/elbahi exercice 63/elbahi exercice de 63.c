#include <stdio.h>
#include <stdlib.h>


void tabl_mult(int x)
{
    int i;
    int p=1;
   printf("veuillez entrer le nombre \n");
   scanf("%d",&x);
   printf("-------- table de multiplication de x=%d --------\n",x);
   for(i=1;i<=10;i++)
   {
       p=x*i;
       printf("x * %d = %d\t",i,p);
       printf("\n");
   }
}
int main()
{
  /*  int t[10],ti[10],tp[10];
    int i,ip=0,pp=0;
    printf("veuillez remplir le tableaux t\n");
    for(i=0;i<5;i++)
    {
        printf("t[%d]=\t",i);
        scanf("%d",&t[i]);
    }
    for(i=0;i<5;i++)
        tp[i]=0;
    for(i=0;i<5;i++)
        ti[i]=0;
    for(i=0;i<5;i++)
    {
        if(t[i]%2==0){
            tp[ip]=t[i];
            ip++;
        }
        else{
            ti[pp]=t[i];
            pp++;

        }
} for(i=0;i<ip;i++)
        printf("%d\t elements du tab paire\n",tp[i]);
    for(i=0;i<pp;i++)
        printf("%d\t elements du tab  impaire\n",ti[i]);


        */



/*
        int t[8];
        int i;
        int tmp;
        printf("veuillez entrer les elements du tableaux\n");
        for(i=0;i<8;i++)
        {
            printf("t[%d]=\t",i+1);
            scanf("%d",&t[i]);
        }
        tmp=t[0];
        for(i=1;i<8;i++)
            for(int j=0;j<8;j++)
        {
            if(t[i]>t[j]){
                tmp=t[j];
                t[j]=t[i];
                t[i]=tmp;
            }

        }
        for(i=0;i<8;i++)
            printf("%d\t",t[i]);*/
int x;
            tabl_mult(x);



    return 0;
}
