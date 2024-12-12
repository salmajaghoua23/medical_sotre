#include <stdio.h>
#include <stdlib.h>


struct point {
    char c;
    int x, y;
};

void Valeur(struct point p) {
    printf("point %c de coordonnees %d %d\n", p.c, p.x, p.y);
}

void Adresse(struct point *p) {
    printf("point %c de coordonnees %d %d\n", p->c, p->x, p->y);
}

void Reference(struct point *p) {
    printf("point %c de coordonnees %d %d\n", (*p).c, (*p).x, (*p).y);
}

int main() {
    // Création d'une structure point
    struct point myPoint = {'B', 10, 12};


    Valeur(myPoint);
    Adresse(&myPoint);
   Reference(&myPoint);

    return 0;
}



