#include <stdio.h>
#include <stdlib.h>

     #define N 10

int tab[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

// Fonction pour afficher les �l�ments du tableau en ordre croissant.
void Croissant(int *ptr, int taille) {
    for (int i = 0; i < taille; ++i) {
        printf("%d ", *(ptr + i));
    }
    printf("\n");
}

// Fonction pour afficher les �l�ments du tableau en ordre d�croissant.
void Decroissant(int *ptr, int taille) {
    for (int i = taille - 1; i >= 0; --i) {
        printf("%d ", *(ptr + i));
    }
    printf("\n");
}

int main() {
    // Utilisation d'un pointeur pour acc�der aux �l�ments du tableau.
    int *ptr = tab;

    // Affichage en ordre croissant.
    printf("Ordre croissant : ");
    Croissant(ptr, N);

    // Affichage en ordre d�croissant.
    printf("Ordre d�croissant : ");
    Decroissant(ptr, N);

    return 0;

}
