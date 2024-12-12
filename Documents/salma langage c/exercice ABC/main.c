#include <stdio.h>
#include <stdlib.h>

int main()
{
    //examen 2023/2022//


    //formalisme tableaux//

/*
    int T[50],M[10][10];
    int n,l,c;
    int i,j,k;
    int x=0;
    printf("veuillez entrer la taille du tab t\n");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("T[%d]=\t",i);
        scanf("%d",&T[i]);
    }
    printf("veuillez entrer le nbre des ligne et  des colonnes\n");
    scanf("%d%d",&l,&c);
    for(i=0;i<l;i++)
        for(j=0;j<c;j++)
    {
        printf("M[%d][%d]=\t",i,j);
        scanf("%d",&M[i][j]);
    }
    for(i=0;i<l;i++){
        for(j=0;j<c;j++)
            for(k=0;k<n;k++){
            if(T[k]==M[i][j])
                x++;
            }

    }
    /* printf("%d elements qui se trouve dans la matrice M\n",x);*/
  /* if(x==0)
        printf("les elements du tab n'existe pas ans la matrice M\n");

    else if(x==n)
        printf("tous les elements du tab t existent dans la matrice M\n");
    else
        printf("%d elements qui se trouve dans la matrice M\n",x);*/

//formalisme pointeurs//



    int T[50], M[10][10];
    int n, l, c;
    int x = 0;

    printf("Veuillez entrer la taille du tableau T : ");
    scanf("%d", &n);

    // Utilisation de pointeurs pour le tableau T
    int *pT = T;
    for (int *endT = pT + n; pT < endT; pT++) {
        printf("T = ");
        scanf("%d", pT);
    }

    printf("Veuillez entrer le nombre de lignes et de colonnes de la matrice M : ");
    scanf("%d%d", &l, &c);

    // Utilisation de pointeurs pour la matrice M
    int *pM = &M[0][0];
    for (int *endM = pM + l * c; pM < endM; pM++) {
        printf("M = ");
        scanf("%d", pM);
    }

    // Utilisation de pointeurs pour la comparaison
    pT = T;
    pM = &M[0][0];
    for (int *endT = pT + n; pT < endT; pT++) {
        for (int *endM = pM + l * c; pM < endM; pM++) {
            if (*pT == *pM)
                x++;
        }
        pM = &M[0][0];  // Remettre le pointeur de la matrice au début après chaque ligne
    }

    // Affichage des résultats
    if (x == 0)
        printf("Aucun élément du tableau T n'existe pas dans la matrice M\n");

    else if (x == n)
        printf("Tous les éléments du tableau T existent dans la matrice M\n");
   else
     printf("%d elements qui se trouve dans la matrice M\n",x);
    return 0;
}







