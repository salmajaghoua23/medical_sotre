#include <stdio.h>
#include <stdlib.h>


#include<stdio.h>
float ValeurAbsolue(float); /* d�claration : prototype de la fonction ValeurAbsolue */
int main( )
{
float x=-5.7, y;
y = ValeurAbsolue(x); /*L�appel de cette fonction*/
printf("La valeur absolue de %f est : %f \n " , x, y);
return 0;
}
float ValeurAbsolue(float a) { /*D�finition de la fonction ValeurAbsolue */
if (a<0)
a=-a;
return a;
}


