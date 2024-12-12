#include <stdio.h>
#include <stdlib.h>
#define NP 50
void affiche(int corbe[],int n,int x,int y,char c){
    int i;
    for(i=0;i<n;i++)
    {
        printf("point %c de coordonnees %d et %d :\n",c,x,y);
    }
}

int main()
{
   int courbe [NP];
   int i,n;
   char c;
   int x,y;
   printf("veuillez entrer la taille choisie pour le tab\n");
   scanf("%d",&n);

   for(i=0;i<n;i++)
   {
      fflush(stdin);
      printf("veuillez nommes cet point \n");
      c=getchar();

       printf("veuillez entrer les cordonnes de ce point \n");
       scanf("%d%d",&x,&y);
   }
   affiche(courbe,n,x,y,c);
    return 0;
}
