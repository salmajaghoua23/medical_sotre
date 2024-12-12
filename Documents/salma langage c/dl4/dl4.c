#include <stdio.h>
#include <stdlib.h>
//fonctions qui saisie les elements du tableaux//
void affiche(int t[],int n){
    int *p;
    p=t;
    for(p=t;p<t+n;p++){

        printf("%d\t",p);
    }

}
//programme qui affiche les element du tab//
void    saisie(int *p,int *pn){
    int t[100];
    p=t;
    for(p=t;p<t+*pn;p++)
        printf(" t[%d]= \t",p-*pn+1);
        scanf("%d",p);
}

//programme qui cherche le nbr d'occurence//
void chercherVal(int tab[],int n,int a,int*pos,int *nbr_occ){
int   *p;
p=tab;
for(p=tab;p<tab+n;p++){
    if(*pos != *p)
        printf(" la valeur  n'est pas ete trouvee  -1 ");
    else
        *nbr_occ ++;

}
}

int main()
{
    int tab[100],n;
    int *p,*pn=&n;
    p=tab;
    printf("saisir la taille du tab\n");
    scanf("%d",&n);
    printf("veuillez entrere les elements du tab \n");
    saisie( &p,&pn);
