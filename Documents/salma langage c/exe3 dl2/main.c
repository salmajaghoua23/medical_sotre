
    #include<stdio.h>
void strsubs(char str[], char X[], int pos, int len) {
    int i, k;
    for (i = pos, k = 0; i < pos + len && X[k] != '\0'; i++, k++) {
        str[i] = X[k];
    }
}
int main() {
    char p[50];
    char s[50];
    int os, en;
    puts("Enter la chaine:");
    scanf("%[^\n]",s);
    while(getchar() != '\0');
    puts("Enter la chaine motif:");
    scanf("%[^\n]", p);
    puts("Enter la pos et len:");
    scanf("%d %d", &os, &en);
    strsubs(s, p, os, en);
    printf("s = %s \n", s);
    return 0;
}
