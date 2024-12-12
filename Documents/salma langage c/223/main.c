#include <stdio.h>
#include <stdlib.h>
void max_min(int *x,int *y,int *max)
{

    if(*x>*y)
        *max=*x;
    else
        *max=*y;
    printf("le maximum est max=%d:\n",*max);
}

int main()
{
    int x,y,max;
    printf("veuillez entrer x et y :\n");
    scanf("%d%d",&x,&y);

    printf("la valeur maximal est \n");
   max_min(&x,&y,&max);
    return 0;
}
