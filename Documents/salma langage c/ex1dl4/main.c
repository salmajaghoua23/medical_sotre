#include <stdio.h>
#include <stdlib.h>

void affiche(int t[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d\t", t[i]);
    }
    printf("\n");
}

void saisie(int t[], int n) {
    for (int i = 0; i < n; i++) {
        printf("t[%d] = ", i + 1);
        scanf("%d", &t[i]);
    }
}

void chercherVal(int tab[], int n, int a, int *pos, int *nbr_occ) {
    *nbr_occ = 0;
    *pos = -1;

    for (int i = 0; i < n; i++) {
        if (tab[i] == a) {
            *pos = i;  // La position est l'indice direct dans ce cas
            (*nbr_occ)++;
        }
    }
}

int main() {
    int tab[100], n, x, pos, nbr_occ;

    printf("Veuillez saisir la taille du tableau :\n");
    scanf("%d", &n);

    printf("Veuillez remplir les éléments du tableau :\n");
    saisie(tab, n);

    printf("Affichage du tableau :\n");
    affiche(tab, n);

    printf("Entrez la valeur à rechercher :\n");
    scanf("%d", &x);

    chercherVal(tab, n, x, &pos, &nbr_occ);

    if (pos != -1) {
        printf("La valeur %d a été trouvée à la position %d.\n", x, pos + 1);
        printf("Nombre d'occurrences de %d dans le tableau : %d\n", x, nbr_occ);
    } else {
        printf("La valeur %d n'a pas été trouvée dans le tableau.\n", x);
    }

    return 0;
}
