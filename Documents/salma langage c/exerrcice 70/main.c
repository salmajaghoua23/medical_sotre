#include <stdio.h>
#include <stdlib.h>

int main()
{
 /* int m,n;
  int r,i=0;


  printf("veuillez entrer deux VALEURS DE M ET N :\n");
  scanf("%d%d",&m,&n);
  r=m%n;
  while(r!=0){
    r=m%n;
    m=n;
    n=r;
    i++;
  };
  printf("le pgcd est %d :\\n",m);
    return 0;*/



  /*  int i=1,N,M,Div_commun;
printf("Donner un entier:");
scanf("%d",&N);
printf("Donner un entier:");
scanf("%d",&M);

while(i<=N && i<=M ){
  if ( N%i==0 && M%i==0){
     Div_commun = i ;
  }
  i++;
}
printf(" PGCD(%d,%d)= %d",M,N,Div_commun);
return 0;*/

/*
int i,j,N;
printf("donner  un entier : ");
scanf("%d",&N);

for(i=0;i<N;i++){
  for(j=1;j<=(N*2)-1;j++){
    if (j>=N-i && j<= N+i )
        printf("*");
      else   printf(" ");
  }
  printf("\n");*/
int i=0,N;
  do{
 printf("Enter un entier:");
 scanf("%d",&N);
 if( N == 5 )
   i = i+1 ;
}while ( N != 0 );

  if( i != 0)
  printf("5 existe %d fois",i);
  else
  printf(" n'existe pas ");


  }




