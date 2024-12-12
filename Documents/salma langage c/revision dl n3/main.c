#include <stdio.h>
#include <stdlib.h>
#include<math.h>

void polynome ()
{    float x,a,p=0;
      int n,i;

      do{
        printf("veuillez entrer la puissance n\n");
        scanf("%d",&n);
      }while(n<=0);
      printf("veuillez entrer le nbr x\n");
      scanf("%f",&x);
      for(i=0;i<=n;i++){
        printf("veuillez enter les coiff\n");
        scanf("%f",&a);
        p+=a*pow(x,i);

      }
   printf("la valeur du polynome est  %.2f:\n",p);
    return 0;
}


void chercheval(int tab[],int *n,int *A,int *nb_occ,int * pos)
{
    *pos=-1;
    *nb_occ=0;
    for(int i=0;i<n;i++)

        if(*A==tab[i])
        {
            *pos=i;
            (*nb_occ)++;
        }

    printf("le nbre d'occurence est %d et dans la pos %d\n",*nb_occ,*pos);

}
void saisies (int *ptab,int *pn)

{
    int tab[20];

    for(ptab=tab;ptab<tab+*pn;ptab++)

{
    printf("tab[%d]=\t",ptab-tab);
    scanf("%d",ptab);
}

}
void affiche(int tab[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf(" tab[%d]=%d\n",i,tab[i]);
    }
}
void tab_mult()
{   int res;
    int i,j;
    printf("-----------table de multiplication------------\n");
    printf(" X x Y | \n");
    for(i=0;i<10;i++)

    {
        for(j=0;j<10;j++)
        {
            printf(" %d\t",i*j);

        }
        printf("\n");
    }
}
int main ()
{ int tab[20];
int n,x;
int pos,nbr_occ;
int *p=&tab;
printf("veuilles entrer la taille du tab\n");
scanf("%d",&n);

saisies(p,&n);
printf("veuilles la valeur qui ont va la chercher\n");
scanf("%d",&x);
chercheval(tab,&n,&x,&nbr_occ,&pos);
affiche(tab,n);
if (pos != -1) {
        printf("La valeur %d a été trouvée à la position %d.\n", x, pos + 1);
        printf("Nombre d'occurrences de %d dans le tableau : %d\n", x, nbr_occ);
    } else {
        printf("La valeur %d n'a pas été trouvée dans le tableau.\n", x);
    }

}
