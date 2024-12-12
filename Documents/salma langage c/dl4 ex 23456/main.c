#include <stdio.h>
#include <stdlib.h>
int division(int *p,int *q ){
    int *z;
    if(q!=0)
        *z=*p / *q;

    else
        printf("impossible cet opperations ");
    return *z;
}
int rest (int* p,int *q){
    return  *p% *q;
}
int main()
{
   int a,b;
   printf("veuillez enrer deux nombre entier :\n");
   scanf("%d%d",&a,&b);
   division(&a,&b);
   rest(&a,&b);
   printf("le quotient et le rest de la division est %d ",division(&a,&b));
}
