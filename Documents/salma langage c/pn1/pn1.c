#include <stdio.h>
#include <stdlib.h>
  int echange(int *x,int *y ){
    int tmp=0;
    if(*x * *y >0){
        tmp=*x;
        *x=*y;
        *y=tmp;
    }
    else{
        *x=*x + *y;
        *y=*x * *y;
    }
     return *x;
}

int main()
{
  /*  int a;
    int *p=&a;
    printf("veuillez entrer un nombre entier a\n :");
    scanf("%d",p);
    if(*p%2==0)
        printf("est pair \n");
    else
        printf("est impaire\n");
    return 0;*/




    //programme de calcul les diviseurs d'un entier//

   /* int n,i ;
    int *p=&n;
    printf("veuillez entrer un entier n");
    scanf("%d",p);
    for(i=1;i<=n;i++){
      if(n%i==0)
        printf(" %d est un diviseur de n=%d\n",i,n);
      else
        break;
    }

        */



     ////programme qui fait l'echange
   /*  int a,b;
     int *p=&a,*q=&b;
     printf("veuillez entrer deux entier a et b\n") ;
     scanf("%d%d",p,q) ;
     echange(p,q) ;
     printf("l'echange des deux entier est a=%d et b=%d\n",*p,*q);

*/
////ACCEDER A UN TABLEAUX A L'AIDE D'UN POINTEUR///
/* int tab[10],n;
 int *p;
 p=tab;
 printf("veuillez entrer la tail dutableaux strictement positive");
 scanf("%d",&n);
 printf("veuillez entrer les elements du tableaux \n");
 p=0;
 for(p=tab;p<tab+n;p++){
        printf("tab[%d]=",p-tab+1);
        scanf("%d",p);
 }
*/




//programme pointeur d'occcurence//
/*int t[20];
int *p;
int n,x;

p=t;
printf("veuillez chioisie une taiille du tab strict positive:\n");
scanf("%d",&n);
printf("-----------\n");
printf("veuillez remlir le tableaux:\n");
for(p=t;p<t+n;p++){
    printf("t[%d]=",p-t+1);
    scanf("%d",p);
}
printf("veuillez chisir un entier pour la eliminer du tableaux:\n");
scanf("%d",&x);
for(p=t;p<t+n;p++){
    if(*p==x)
        continue;
    printf("t[%d]=%d\n",p-t+1,*p);
}*/








//// ecrire un inverse d'un programme//



/*

int t[20],n;
int *p1,*p2;
int tmp=0;
p1=t;
p2=t;

printf("veuillez chioisie une taiille du tab strict positive:\n");
scanf("%d",&n);
printf("-----------\n");
printf("veuillez remlir le tableaux:\n");
for(p1=t;p1<t+n;p1++){
    printf("t[%d]=",p1-t+1);
    scanf("%d",p1);
}
for(p1=t,p2=t+n-1;p1<p2;p1++,p2--){
    tmp=*p1;
    *p1=*p2;
    *p2=tmp;
}
printf("les elements du tab inverse sont :\n");
for(p1=t;p1<t+n;p1++){
    printf(" t[%d]=%d\n",p1-t+1,*p1);
}*/





//programme qui transfert un tab vers un tab//








int A[20],B[20];
int m,n;
int *pa,*pb;
pa=A;
printf("veuilllez saisir la taille du tab A :\n");
scanf("%d",&n);
printf("veuillez remplir le tab :\n");
for(pa=A;pa<A+n;pa++){
    printf("A[%d]= ",pa-A+1);
    scanf("%d",pa);
}
pb=B;
printf("veuilllez saisir la taille du tab B :\n");
scanf("%d",&m);
printf("veuillez remplir le tab :\n");
for(pb=B;pb<B+m;pb++){
    printf("B[%d]=",pb-B+1);
    scanf("%d",pb);
}
for(pa=A+n,pb=B;pb<B+m;pa++,pb++){
    *pa=*pb;
}
n=n+m;
printf("les elements du tableaux A sont :\n");
for(pa=A;pa<A+n;pa++)
    printf("A[%d]=%d\n",pa-A+1,*pa);

}
