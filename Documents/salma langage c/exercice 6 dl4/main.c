#include <stdio.h>
#include <stdlib.h>

     #define N 10

int tab[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

// Fonction pour afficher les éléments du tableau en ordre croissant.
void Croissant(int *ptr, int taille) {
    for (int i = 0; i < taille; ++i) {
        printf("%d ", *(ptr + i));
    }
    printf("\n");
}

// Fonction pour afficher les éléments du tableau en ordre décroissant.
void Decroissant(int *ptr, int taille) {
    for (int i = taille - 1; i >= 0; --i) {
        printf("%d ", *(ptr + i));
    }
    printf("\n");
}

int main() {
    // Utilisation d'un pointeur pour accéder aux éléments du tableau.
    int *ptr = tab;

    // Affichage en ordre croissant.
    printf("Ordre croissant : ");
    Croissant(ptr, N);

    // Affichage en ordre décroissant.
    printf("Ordre décroissant : ");
    Decroissant(ptr, N);

    return 0;

}
