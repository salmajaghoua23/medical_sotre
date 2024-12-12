#include <stdio.h>
#include <stdlib.h>
int factorielle(int x){
    int f, i ;
    f=1;
    for(i=2;i<=x ;i++)
        f=f*i;
    return f;
}
int puissance(int n,int p){
    int s=1;
    int i;
    for(i=1;i<=p;i++)
        s*=n;
    return s;
}
int nbr_chiffre(int x){
    int i=0;
   while(x!=0){
    x=x/10;
    i++;
   }
    return i;
}
int inverse(int z){
    int i=0,R;
    while(z!=0){
        R=z%10;
        z=z/10;
        i=i*10+R;
    }
    return i;

}
int PGCD(int n1,int n2){
    int R,A,B;
    R=n1;
    A=n1;
    B=n2;
    while(R!=0){
        R=A%B;
        A=B;
        B=R;
    }
    return A;
}
int AA(int m,int n){
    if(m<0 && n<0)
        return 0;
    else if(m==0)
        return n+1;
    else if (n==0)
        return AA(m-1,1);
    else
    return AA(m-1,AA(m,n-1));
}
void dessiner (int L,char c){
    int i,j;
    for(i=0;i<L;i++){
        for(j=0;j<L;j++){
                if(j==i || j==L-i-1)
                printf("%c",c);
            else
                printf(" ");
        }
        printf("\n");
    }
}

int main()
{int x;
 dessiner(5,'s');
 x=inverse(212);
 return 0;
}
