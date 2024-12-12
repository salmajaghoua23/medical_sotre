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
int tab[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

int *TableauDynamiquement(int *source, int taille) {
    // Allocation dynamique de m�moire pour la copie.
    int *copie = (int *)malloc(taille * sizeof(int));

    // V�rification de l'allocation de m�moire.
    if (copie == NULL) {
        fprintf(stderr, "Erreur d'allocation de m�moire.\n");
        exit(EXIT_FAILURE);
    }

    // Copie des �l�ments du tableau source dans la m�moire allou�e dynamiquement.
    for (int i = 0; i < taille; ++i) {
        copie[i] = source[i];
    }

    return copie;
}

int main() {
    // Utilisation d'un pointeur pour acc�der aux �l�ments du tableau.
    int *ptr = tab;

    // Copie du tableau dans un espace m�moire allou� dynamiquement.
    int *copieTableau = TableauDynamiquement(ptr, N);

    // Affichage de la copie.
    printf("Tableau copie dynamiquement : ");
    for (int i = 0; i < N; ++i) {
        printf("%d ", copieTableau[i]);
    }
    printf("\n");

    // Lib�ration de la m�moire allou�e dynamiquement.
    free(copieTableau);

    return 0;
}
