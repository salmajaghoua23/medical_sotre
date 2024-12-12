#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int main()
{
 int i=1,SOMME=0;
 while(SOMME<1000){
    i=i*2;
    SOMME+=i;
 }
printf("la plus grande valeur <1000  de la somme est: %d\n ",SOMME -i);

 return 0;
}

