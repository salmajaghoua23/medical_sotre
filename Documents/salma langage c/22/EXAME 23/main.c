#include <stdio.h>
#include <stdlib.h>

/*
void tableaux()
{
int t[50],m[10][10];
int n,i,j,k,l,c;
int x=0;
printf("veuillez entrer la taille du tableaux t :\n");
scanf("%d",&n);
printf("veuillez remplir le tableaux:\n");

for(i=0;i<n;i++){
    printf("t[%d]=\t",i);
    scanf("%d",&t[i]);
}
printf("veuillez entrer le nbre des lignes et des colonnes :\n ");
scanf("%d%d",&l,&c);
for(i=0;i<l;i++){
    for(j=0;j<c;j++){
        printf("m[%d][%d]=\t",i,j);
        scanf("%d",&m[i][j]);
    }
    printf("\n");
}
for(i=0;i<l;i++){
    for(j=0;j<c;j++){
        for(k=0;k<n;k++){
            if(t[k]==m[i][j])
                x++;
        }
    }
}
if(x==0)
    printf("n'existe aucun elements du tab dans la matrice :\n");
else if(x==n)
    printf("tous les elements sont existe dans m \n");
else
    printf(" %d elements du tableaux dans la matrice m :\n",x);

}*/

int main()
{
  /*  int n,somme=0,p=1;
    int i,x;
    float moy=0;
    printf("veuillez entrer la valeur de nbre n:\n");
    scanf("%d",&n);
   /* while(i<n){
        printf("veuillez entrer un nmbre entier :\n");
        scanf("%d",&x);
        somme+=x;
        p*=x;
        i++;
    }
    moy=(float)somme/p ;
    printf("la somme des elements est %d :\n",somme);
    printf("la produit des elements est %d :\n",p);
    printf("la moyenne des elements est %f :\n",moy);*/
  /*  do{
      printf("veuillez entrer un nmbre entier :\n");
      scanf("%d",&x);
      somme+=x;
       p*=x;
        i++;
    }while(i<n);
    moy=(float)somme/p ;
    printf("la somme des elements est %d :\n",somme);
    printf("la produit des elements est %d :\n",p);
    printf("la moyenne des elements est %f :\n",moy);
*/







/*
for(i=0;i<n;i++){
     printf("veuillez entrer un nmbre entier :\n");
      scanf("%d",&x);
      somme+=x;
       p*=x;
}
 moy=(float)somme/p ;
    printf("la somme des elements est %d :\n",somme);
    printf("la produit des elements est %d :\n",p);
    printf("la moyenne des elements est %f :\n",moy);
    return 0;*/

/*    int t[50],m[10][10];
int n,i,j,k,l,c;
int x=0;
printf("veuillez entrer la taille du tableaux t :\n");
scanf("%d",&n);
printf("veuillez remplir le tableaux:\n");

for(i=0;i<n;i++){
    printf("t[%d]=\t",i);
    scanf("%d",&t[i]);
}
printf("veuillez entrer le nbre des lignes et des colonnes :\n ");
scanf("%d%d",&l,&c);
for(i=0;i<l;i++){
    for(j=0;j<c;j++){
        printf("m[%d][%d]=\t",i,j);
        scanf("%d",&m[i][j]);
    }
    printf("\n");
}
for(i=0;i<l;i++){
    for(j=0;j<c;j++){
        for(k=0;k<n;k++){
            if(t[k]==m[i][j])
                x++;
        }
    }
}
if(x==0)
    printf("n'existe aucun elements du tab dans la matrice :\n");
else if(x==n)
    printf("tous les elements sont existe dans m \n");
else
    printf(" %d elements du tableaux dans la matrice m :\n",x);
*/




//formalisme pointeurs ----------//
int t[50],m[10][10];
int l,c,n,i,j;
int *p1;
int *p2=&m[0][0];
p1=t;
printf("veuillez entrer le nbr \n");
scanf("%d",&n);
for(p1=t;p1<t+n;p1++){
    printf("t[%d]=\t",p1-t);
    scanf("%d",p1);
}
printf("veuilles entrer les lignes et les nbr des colonnes :\n);
scanf("%d%d",&l,&c);
for (int *endM = pM + l * c; pM < endM; pM++) {
        printf("M = ");
        scanf("%d", pM);













}
