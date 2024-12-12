#include <stdio.h>
#include <stdlib.h>
void etoil(int n){
    int i,j,k;
    for(i=1;i<=n;i++){
        for(k=n-i;k>0;k--)
            printf(" ");
        for(j=1;j<=(2*i)+1;j++){
            printf(" * ");
        }
        printf("\n");
    }
}

int main()
{int n;
printf("veuillez entrer un entiere n ");
scanf("%d",&n);
etoil(n);
    return 0;
}
