#include <stdio.h>
#include <stdlib.h>

#define  NMOIS 12
struct enreg {
int stock ;
float prix ;
int ventes[NMOIS];
};
void raz (struct enreg *e)
{   int i;
    e->stock=0;
    for(i=0;i<NMOIS;i++)
        e->ventes[i]=0;

}
void affiche(struct enreg e)
{

    int i;
    printf("prix=%f \t stock=%d\n",e.prix,e.stock);
    for(i=0;i<NMOIS;i++)
        printf("%d\t",e.ventes[i]);
}
int main()
{
  struct enreg e={1,3,6,8,9,3,0,23,12,13,10,9};
  printf("avant les modification \n");
  affiche(e);
  raz(&e);
  printf("apre la fonctions raz \n");
  affiche(e);
    return 0;
}
