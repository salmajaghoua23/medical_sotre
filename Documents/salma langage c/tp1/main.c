#include <stdio.h>
#include <stdlib.h>

int main()
{
   /* int n,i;
    float U0,r,U1, U2;
    printf("veuillez donner une valeur de n :");
    scanf("%d",&n);
    printf("veuillez donner le raison et un valeur de premier term :");
    scanf("%f%f",&r,&U0);
    U1=U0+r*n;
    U2=U1+r;
    printf("la nieme valeur de la suite arithmetique est :%f",U2);

        return 0;
}

    char nom[30],prenom[30];
    int jr,mois,annee;
    printf("veuillez saisir votre nom et votre prenom :");
    scanf("%s %s",&nom,&prenom);
    printf("veuilez saisir l'annee,le mois et le jour de ta naissance :");
    scanf("%d%d%d",&annee,&mois,&jr);
    printf("tu t'appelle %s %s et tu es ne le %d/%d/%d.",nom,prenom,jr,mois,annee);
    return 0;


int A,B;
printf("saisir deux nombres entiers ");
scanf("%d%d",&A,&B);
if(A>B)
  printf("le plus grand =%d:",A);

    else{
       printf("le plus grand=%d :",B);
    }
}
 int a;
 printf("veuileez saisir a :");
 scanf("%d",&a);
 printf("la valeur absolue est %d",a>0?a:-a);
 return 0;
 }
 int A;
 printf("veuillez entrer  un entier :");
 scanf("%d",&A);
 if(A%2==0)
    printf("le nombbre est pair");
 else{
    printf("le nombre est impaire");
 }
  int a,b,c,max;
  printf("veuilez   entrer a,b et c :");
  scanf("%d%d%d",&a,&b,&c);
  printf("max=%d",a>b ?(a>c?a:c):(c<b?b:c));
*/
 float a,b ;
 printf("veuilez entrer dex valeurs reels :");
 scanf("%f%f",&a,&b);
 if(a*b<0)
 {
a=a+b;
b=a-b;
a=a-b;
printf("a=%f et b=%f",a,b);
 }
 else {
    a=a*b;
    b=(a/b) +b;
    printf("le produit dans la premiere donnee a=%f et leur somme  b=%f dans la deuxieme ",a,b);
 }
 }



