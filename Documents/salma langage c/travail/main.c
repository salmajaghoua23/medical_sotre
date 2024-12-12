#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void siser(int tab[],int n){
 for(int i=0 ; i<n;i++){
    printf("t[%d]=\t",i);
    scanf("%d",&tab[i]);
 }

for(int i=0;i<n;i++)
    printf("%d\t",tab[i]);

}


/*#define MAX 10 // la taille maximale de la matrice

// une fonction qui affiche une matrice
void afficher_matrice(int m[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

// une fonction qui calcule le maximum d'une matrice
int max_matrice(int m[MAX][MAX], int n) {
    int max = m[0][0]; // on initialise le maximum avec le premier élément
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (m[i][j] > max) { // si on trouve un élément plus grand que le maximum actuel
                max = m[i][j]; // on le met à jour
            }
        }
    }
    return max; // on renvoie le maximum
}

// une fonction qui compte le nombre de lignes dans chaque ligne d'une matrice
void lignes_par_ligne(int m[MAX][MAX], int n, int *l) {
    for (int i = 0; i < n; i++) {
        l[i] = 0; // on initialise le compteur de lignes pour la i-ème ligne
        for (int j = 0; j < n; j++) {
            if (m[i][j] == 0) { // si on trouve un zéro
                l[i]++; // on incrémente le compteur de lignes
            }
        }
    }
}
*/

int main() {
  /*  int m[MAX][MAX] = {{1, 2, 0, 4}, {5, 6, 7, 0}, {9, 0, 11, 12}, {0, 14, 15, 16}}; // une matrice de test
    int n = 4; // la dimension de la matrice
    int l[MAX]; // un tableau qui contiendra le nombre de lignes dans chaque ligne
    int max; // une variable qui contiendra le maximum de la matrice

    printf("La matrice est:\n");
    afficher_matrice(m, n); // on affiche la matrice

    max = max_matrice(m, n); // on calcule le maximum de la matrice
    printf("Le maximum de la matrice est: %d\n", max); // on l'affiche

    lignes_par_ligne(m, n, l); // on calcule le nombre de lignes dans chaque ligne
    printf("Le nombre de lignes dans chaque ligne est:\n");
    for (int i = 0; i < n; i++) {
        printf("Ligne %d: %d\n", i + 1, l[i]); // on affiche le résultat
    }*/
    int tab[20];
    int n=4;
    siser(tab,n);









    return 0;
}
