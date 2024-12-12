#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tab[6];
    int *p,*max,m;
    p=tab;
    m=*max;
    printf("veuillez remplir le tableaux :\n");

    for(p=tab;p<tab+10;p++){
        printf("tab[%d]=",p-tab);
        scanf("%d",p);
    /* s+=*p;
    }
    printf("la somme des elements est %d",s);
    return 0;*/
}
  *max=*p;
for(p=tab;p<tab+10;p++){

    if(*max<*(p++))
       *max=*(p++);
    else
        break;
}
printf("le max est :%d",m);

}
