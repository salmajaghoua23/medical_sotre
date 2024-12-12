#include <stdio.h>
#include <stdlib.h>
#define  LG_NOM 30
struct date
{ int jour ;
int mois ;
int annee ;
} ;
struct personne
{ char nom [ LG_NOM +1] ; // chaıne de caract eres (de style C) `
// representant le nom ´
struct date date_embauche ;
struct date date_poste ;
} ;
void dialogue(struct personne A)
{
    int i;
   puts("veuillez entrer votre nom \n");
   gets(personne.nom);
   printf("date_embauche(%d %d %d ) :",personne.date_embauche.jour,personne.date_embauche.mois,personne.date_embauche.annee);

}
int main()
{

    return 0;
}
