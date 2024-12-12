#include <stdio.h>
#include <stdlib.h>

int main()
{
int t[3][4];
  int *p;p=(int*)t;
  int i,j,som=0;
  printf("veuillez remplir les elements du tab \n");
  for(i=0;i<3;i++){
    for(j=0;j<4;j++){
        printf("t[%d][%d]=",i,j);
        scanf("%d",&t[i][j]);
    }
    printf("\n");
  }
  for(i=0;i<12;i++){
    som+=*(p+i);
  }
  printf("la somme est som=%d\n",som);
    return 0;
}
