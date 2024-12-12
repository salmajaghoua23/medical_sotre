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
int tab[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

int *TableauDynamiquement(int *source, int taille) {
    // Allocation dynamique de mémoire pour la copie.
    int *copie = (int *)malloc(taille * sizeof(int));

    // Vérification de l'allocation de mémoire.
    if (copie == NULL) {
        fprintf(stderr, "Erreur d'allocation de mémoire.\n");
        exit(EXIT_FAILURE);
    }

    // Copie des éléments du tableau source dans la mémoire allouée dynamiquement.
    for (int i = 0; i < taille; ++i) {
        copie[i] = source[i];
    }

    return copie;
}

int main() {
    // Utilisation d'un pointeur pour accéder aux éléments du tableau.
    int *ptr = tab;

    // Copie du tableau dans un espace mémoire alloué dynamiquement.
    int *copieTableau = TableauDynamiquement(ptr, N);

    // Affichage de la copie.
    printf("Tableau copie dynamiquement : ");
    for (int i = 0; i < N; ++i) {
        printf("%d ", copieTableau[i]);
    }
    printf("\n");

    // Libération de la mémoire allouée dynamiquement.
    free(copieTableau);

    return 0;
}
