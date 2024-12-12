#include <stdio.h>
#include <stdlib.h>
void operation(int *q,int *p,int *r,int *x)
{   *x=*q / *p;
    *r=*q % *p;
    printf("le quotient x=%d et le rest r=%d\n",*x, *r);
}

int main()
{
    int q,p,r,x;
    printf("donner deux entier \n");
    scanf("%d%d",&p,&q);
    if(q!=0)
        operation(&p,&q,&r,&x);
    else
        printf("impossible!");
    return 0;
}
