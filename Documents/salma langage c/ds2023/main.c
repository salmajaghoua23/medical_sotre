#include <stdio.h>
#include <stdlib.h>
int main(void) {
 char mot[] = "LXRS2Q2RN" ;
 int i ;
 for (i=1 ; i<8 ; ++i)
 mot[i]++ ;
 mot[i]=0 ;
 puts(mot) ;
 return 0 ;
}

