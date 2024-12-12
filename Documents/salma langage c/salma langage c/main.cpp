#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int r,N,U,U1,U2,U0;
	int i;
	U0=0;
	printf("veuillez entrer une valeur pour U0\n,N\n et r\n");
	scanf("%d %d %d ",&U0,&N,&r);
	U1=U0+N*r;
	for(i=1;i<=N;i++){
		U=U1+r;
		U2=U1;
	}
	printf("la nieme valeur de la suit est %d:",U);
	
	return 0;
}
