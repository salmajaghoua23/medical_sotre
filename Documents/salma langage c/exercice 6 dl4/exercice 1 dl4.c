#include <stdio.h>
#include <stdlib.h>


int* division(int p,int q)
{   int *t=malloc(2*sizeof(int));
    if(q==0)
    {
        printf("impossible!");
    return NULL;
    }
    else{
        t[0]=p/q;
        t[1]=p%q;
        return t;
    }
}

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
  /*  int tab[100], n, x, pos, nbr_occ;

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
*/



/*
 int x,y;
 printf("veillez entrer deux nombre\n");
 scanf("%d%d",&x,&y);
    int* result = division(x, y);

    if (result != NULL) {
        printf("Quotient: %d\n", result[0]);
        printf("Reste: %d\n", result[1]);

        free(result);  // N'oubliez pas de libérer la mémoire allouée
    }
*/

/*
int b [3][5];
int *a = *b , i;
for (i = 0;i <15;* a ++ = i ++);
** b = 15; **( b +1) = 16;
*( b [0]+1)=17; *(* b +8)=8;
*( b [1]+2) = 19; *(*( b +1)+5) = 20;
*( b [2]+3) = 21; *(*( b +2)+2) = 22;
 for(int i=0;i<3;i++){
    for(int j=0;j<5;j++)
        printf("%d\t",b[i][j]);
    printf("\n");
 }*/



int t[3][4];
int i,j;
int *p=&t[0][0];
for(i=0;i<3;i++){
    for(j=0;j<4;j++){
        printf("t[%d][%d]=\t",i,j);
        scanf("%d",p);
        (p)++;
    }
    printf("\n");
}

for(i=1;i<3;i++){
    for(j=0;j<4;j++)
            printf("%d\t",*p);

    printf("\n");
}



    return 0;
}
