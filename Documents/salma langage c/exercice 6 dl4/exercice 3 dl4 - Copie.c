#include <stdio.h>
#include <stdlib.h>

int main()
{//c'est le code//
   int b[3][5];
int *a = *b, i;
for (i = 0; i < 15; *a++ = i++);
**b = 15;
**(b + 1) = 16;
*(b[0] + 1) = 17;
*(*b + 8) = 8;
*(b[1] + 2) = 19;
*(*(b + 1) + 5) = 20;
*(b[2] + 3) = 21;
*(*(b + 2) + 2) = 22;

    return 0;
}
//le resultat c'est une matrice de deux dimensions//
15 17  0  0  0
 0  0 19  0 20
 0  0  0 21  0
