


#include <stdio.h>
#include <stdlib.h>
#define N 10 //EX2 DLN2
void cof(int A[N][N], int temp[N][N], int p, int q, int n) {
    int i = 0, j = 0;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (row != p && col != q) {
                temp[i][j++] = A[row][col];
                if (j == n - 1) {
                    j = 0;
                    i++;}}}}}
int determinant(int A[N][N], int n) {
    int det = 0;
    if (n == 1) {
        return A[0][0];
    }
    int temp[N][N];
    int sign = 1;
    for (int f = 0; f < n; f++) {
        cof(A, temp, 0, f, n);
        det += sign * A[0][f] * determinant(temp, n - 1);
        sign = -sign;
    }
    return det;}
    int main() {
    int matrice[N][N], taille;
    printf("Entrer la taille de la matrice carree: ");
    scanf("%d", &taille);
    printf("entrer les elements de la matrice par ligne :\n");
    for (int i = 0; i < taille; i++) {
        for (int j = 0; j < taille; j++) {
            scanf("%d", &matrice[i][j]);}}
    int det_val = determinant(matrice, taille);
    printf("Le determinant de la matrice est : %d\n", det_val);
}

