#include <stdio.h>
#include <stdlib.h>

int main(int narg, char *argv[]) {
	unsigned n;
	int i,cont=0,aux=0,aux1=0,inv=0;
	
	if (narg==1) {
		printf("Digite um número: ");
		scanf("%d", &n);	
	}
	else {
		n=atoi(argv[1]);
	}
	aux=n;
	while (aux>0) {
		cont++;
		aux=aux/10;
	}  
	for (i=1; i<=cont; i++){
		aux1=n%10;
		n=n/10;
		inv=(inv*10)+aux1;
	}
	printf("O inverso do número digitado é: %d \n", inv);	
	return EXIT_SUCCESS;
}
