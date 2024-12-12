#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef char* mot;
typedef char*language;
int appartient(mot m,language l){
for(int i=0;i<strlen(l);i++){
if(strcmp(m,l)==0)
    return 1;
else
    return 0;
}
}
int ajouter(mot m,language l)
{
    language t=strcpy(l,m);
    printf("%s\n",t);
    if(m==NULL)
        return -1;
    else
        return strlen(t)+1;
}
//exercice 4 probleme//
struct complexe{
int a;
int b;
};
typedef struct complexe complexe;
void saisie(complexe z)
{
    printf("veuillez entrer les deux parametre du nombre imaginaire\n");
    scanf("%d%d",&z.a,&z.b);

}
void affiche(complexe z)
{
    printf("%d + i%d\n",z.a,z.b);
}
void somme(complexe *z,complexe *q)
{
    complexe somme;
    somme.a=(z->a)+(q->a);
    somme.b=(z->b)+(q->b);
    printf("la smme est %d +i%d\n",somme.a,somme.b);
}
int main()
{
    complexe z={1,2},q={2,4};
    mot m="salma";
    language l="sous";
    int x=appartient(m,l);
    somme(&z,&q);

    printf("%d\n",x);


    return 0;
}
