#include <stdio.h>
#include <stdlib.h>

int main()
{
 /*float t[10];
 int i;
 float s=0,p=1,m;
 printf("veuillez remplir le tableaux :\n");
 for(i=0;i<10;i++){
    printf("t[%d]=",i);
    scanf("%f",&t[i]);
 }                                              //programme qui calcul le produit somme... d'uun tableaux//
 for(i=0;i<10;i++){
    s+=t[i];
    p*=t[i];
 }
 printf("la somme est s=%.2f et le produit est p=%.2f\n",s,p);
 m=s/p;
 printf("le moyeenne est m=%f\n",m);*/
/* int t[5],tab[5];
 int i,p=0;
 printf("veuillez saisir les element des deux tablaux :\n");
    for(i=0;i<5;i++){
    printf("t[%d]=",i);
    scanf("%d",&t[i]);
 }
   for(i=0;i<5;i++){
    printf("tab[%d]=\n",i);                //programme qui calcul le produit vectorielle//
    scanf("%d",&tab[i]);
 }

 for(i=0;i<5;i++)
    p+=t[i]*tab[i];
 printf("le produit vectorielle est p=%d\n",p);*/
 /* int tab[50];
  int i,n,x=0;
  printf("veuillez saisir les elements du tableaux :\n");
  for(i=0;i<10;i++){
    printf("tab[%d]=  ",i);              //programme qui calcull le nombre d'occurence//
    scanf("%d",&tab[i]);
  }
  printf("veullez saisir le nombre n :");
  scanf("%d",&n);
  for(i=0;i<10;i++){
    if(tab[i]==n)
        x++;


  }
  printf("%d se troouve dans le tableaux %d fois",n,x);*/
 /* float tab[10];
  int i,note,x=0;

  printf("veuillez saisir les notes des etudiants :\n");
  for(i=0;i<10;i++){
    printf("tab[%d]=",i);
    scanf("%f",&tab[i]);
  }
                                                          //programme qui renvoie le nombres des notes sup au moyenne//
  for(i=0;i<10;i++){
    if(tab[i]>=10)
        x++;
  }
printf("le nombres des notes superieure a la moyeenne est %d des etudients ",x);*/

/*
float tab[20];
int i;
float s=1000;
 for(i=0;i<20;i++) {
    s=s+s*0.02;
    tab[i]=s;
}
for(i=0;i<20;i++)
printf(" %d la somme du compt est %.2f\n",i+1,tab[i]);

*/
int tab[6],ts[6],i;
int n=6;
printf("veuillez remplir le tableaux----\n");
 for(i=0;i<n;i++){
    printf("tab[%d]=",i);
    scanf("%d",&tab[i]);
  }
for(i=0;i<n;i++){
    ts[n-1-i]=tab[i];
}
for(i=0;i<n;i++)
    printf("tab[%d]=%d\n",i,ts[i]);



    return 0;
}
