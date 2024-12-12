#include <stdio.h>
#include <stdlib.h>
#define NP 50
struct point {
char c ;// nom attribue au point ´
int x , y ;// ses coordonnees ´
};
typedef struct point point;
void affiche(point courbe[]){
    int i;
    for(i=0;i<NP;i++)
    {
        printf("point %c de coordonnees %d et %d :\n",courbe[i].c,courbe[i].x,courbe[i].y);
    }
}

int main()
{ point courbe[NP];
  int i;
  for(i=0;i<NP;i++)
{   fflush(stdin);
    printf("veuillez entrer le nom du point \n");
   scanf("%c",&courbe[i].c);

    printf("veuilles entrer ses cordonnes \n");
    scanf("%d%d",&courbe[i].x,&courbe[i].y);

}
affiche(courbe);


    return 0;
}
