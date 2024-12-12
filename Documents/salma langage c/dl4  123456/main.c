#include <stdio.h>
#include <stdlib.h>
 int quotient (int *a,int *b)
{
    if(*b!=0)
        return *a/ *b;

}
int rest(int *a,int *b)
{
    return *a % *b;
}
int quo_rest(int *a,int *b){
    int tab[]={*a/ *b,*a % *b};

    return tab;
}
int main()
{
int a,b,q,z;
printf("veuillez saisir les deux nombre :\n");
scanf("%d%d",&a,&b);
/*q=quotient(&a,&b);
z=rest(&a,&b);
printf("le quotient est q=%d et z=%d",q,z);*/
z=quo_rest(&a,&b);

printf("le quotient  et le rest est   z=%d",z);

    return 0;
}
