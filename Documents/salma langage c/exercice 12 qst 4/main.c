#include <stdio.h>
#include <stdlib.h>
#include<math.h>
int main()
{
   int i=1;
float som=1;
while (fabs(som-1.33)>0.01){
i++;
som += (i%2)? (1.0/i):( -1.0/i);
}
printf("Le nombre N tel que 1+1/2-...±1/N donne un resultat =1,33 est :%d",i);
}
