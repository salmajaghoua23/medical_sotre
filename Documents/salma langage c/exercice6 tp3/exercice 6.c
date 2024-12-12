#include <stdio.h>
#include <stdlib.h>
#include<string.h>
void delspace(char ch[]){
    int i,j;
    for(i=0,j=0;ch[i]!='\0';i++)
    {

        if(ch[i]!=' '){
            ch[j]=ch[i];
            j++;
        }

    }
    ch[j]='\0';

}

int main()
{ char ch[100];
printf("saisir la chaine ");
gets(ch);
delspace(ch);
printf("%s",ch);


    return 0;
}
