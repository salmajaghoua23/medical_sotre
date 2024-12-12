#include <stdio.h>
#include <stdlib.h>
struct date {
    int jour; char mois[10]; int annee;
};
struct employe{
char nom[15],prenom[15] ;
struct date date_embauche;
struct date  anniversaire;
};
typedef struct employe employe;
 struct etud{
    char nom[15],prenom[15];
    int cne;
    float notes[4],moyenne;
};
typedef struct etud etud;
int main()
{ /*excecujtion d'exercice 13*/
  /* employe t[4];
   int i;
   for(i=0;i<4;i++)
   {
       printf("Nom:");
       scanf("%s",t->nom);
       printf("prenom:");
       scanf("%s",t->prenom);
       printf("Date de naissance :");
       scanf("%d%s%d",&t[i].anniversaire.jour,&t[i].anniversaire.mois,&t[i].anniversaire.annee);
       printf("Date d'embauche :");
       scanf("%d%s%d",&t[i].date_embauche.jour,&t[i].date_embauche.mois,&t[i].date_embauche.annee);


   }
   */

  etud T[5];
   int j,i;
   float some=0.0;
   for(i=0;i<5;i++){
        fflush(stdin);
    printf("nom:\n");
    gets(T->nom);
     printf("prenom:\n");
    gets(T->prenom);
    printf("CNE:");
    scanf("%d",&T[i].cne);
    printf("entrer les notes:");
         for(j=0;j<4;j++){
           scanf("%f",&T[i].notes[j]);
           some+=T[i].notes[j];
         }
    T->moyenne=some/4.0 ;
   }









   /*exercice 14*/





    return 0;
}
