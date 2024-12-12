#include <stdio.h>
#include <stdlib.h>
void saisie(int *ptab,int *pn)
{
    int t[100];
    ptab=t;
    for(ptab=t;ptab<t+ (*pn);ptab++)
    {
        printf("t[%d]=",ptab-t+1);
        scanf("%d",ptab);
    }
}
void affiche(int t[],int n)
{
    int i;

    for(i=0;i<n;i++)
        printf("%d\t",t[i]);

        printf("\n");
        }
void chercheVal(int t[],int n, int A,int *pos,int *nbr_occ)
{
    int i;

    *pos=-1;
    *nbr_occ=0;
    for(i=0;i<n;i++){
        if(t[i] == A){
            *pos=i;
            (*nbr_occ)++;
    }
}
printf("le nbr d'occurents est nbr occ=%d et la dernier indice est pos=%d\n",*nbr_occ,*pos);
}
int main()
{

    int t[100],n,A,nbr_occ,pos;
    printf("veuillez choisie la taille du tab \n");
    scanf("%d",&n);
    printf("voicie la saisie du programme \n");
    saisie(t,&n);
    printf("voicie l'affichage du tab \n");
    affiche(t,n);
    printf("veuillez choisir un nombre A \n");
    scanf("%d",&A);
    chercheVal(t,n,A,&pos,&nbr_occ);
    if (pos != -1) {
        printf("La valeur %d a été trouvée à la position %d.\n", A, pos + 1);
        printf("Nombre d'occurrences de %d dans le tableau : %d\n", A, nbr_occ);
    } else {
        printf("La valeur %d n'a pas été trouvée dans le tableau.\n", A);
    }

    return 0;
}
