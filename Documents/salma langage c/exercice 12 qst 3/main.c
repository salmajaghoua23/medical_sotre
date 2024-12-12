#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int main()
{
    int i=0 ,somme=0;
    while((somme+pow(2,i))<1000){
        somme+=pow(2,i);
        i++;
    }


    printf("la vleur la plus grande inf est :%d",somme);
    return 0;
}
