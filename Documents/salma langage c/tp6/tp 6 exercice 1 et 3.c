#include <stdio.h>
#include <stdlib.h>
#include<math.h>

struct point {
    char c;
    int x;
    int y;
};

void Valeur(struct point p) {
    printf("point %c de coordonnees %d %d\n", p.c, p.x, p.y);
}

void Adresse(struct point *p) {
    printf("%c(%d,%d)\n", p->c, p->x, p->y);
}

void Reference(struct point *p) {
    printf("point %c de coordonnees %d %d\n", (*p).c, (*p).x, (*p).y);
}
float distance (struct point p1,struct point p2)
{
    float z;
   z= sqrt(pow((p1.x-p2.x),2 ) + pow((p1.y - p2.y),2 ) );
    return z;
}
struct point opposee(struct point *p)
{
    struct point p1;
    p1.c=p->c;
    p1.x=-p->x;
    p1.y=-p->y;
    return p1;

}
int main() {
    struct point p = {'B', 10, 12};
    struct point p3;
    float x;
    struct point p1,p2;
    Valeur(p);
    Adresse(&p);

    printf("veuillez entrer les coordonnee de point p1 ;\n") ;
    scanf("%d%d",&p1.x,&p1.y);

    printf("veuillez entrer les coordonnee de point p2 ;\n") ;
    scanf("%d%d",&p2.x,&p2.y);

    x=distance(p1,p2);
    printf("la distance  est x =%f \n",x);

    p3=opposee(&p);

    Valeur(p);

    Valeur(p3);

    return 0;
}



