#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *unidades[] = {"","um","dois","tres","quatro","cinco","seis","sete","oito","nove"};
char *dezVinte[] = {"","onze","doze","treze","quatorze","quinze","dezesseis","dezessete","dezoito","dezenove"};
char *dezenas[] = {"","dez","vinte", "trinta","quarenta","cinquenta","sessenta","setenta,","oitenta","noventa"};
char *centenas[] = {"","cento","duzentos","trezentos","quatrocentos","quinhentos","seiscentos","setecentos","oitocentos","novecentos"};


char *extA(char *palavra1, char *palavra2){
	int tamanho1,tamanho2;
	char *buffer;
	int contador;
	tamanho1=strlen(palavra1);
	tamanho2=strlen(palavra2);
	buffer=(char *)malloc(tamanho1+tamanho2+1);
	for (contador=0; contador<tamanho1+tamanho2; contador++){
		if (contador<tamanho1)
			buffer[contador]=palavra1[contador];
	    	else
	      		buffer[contador]=palavra2[contador-tamanho1];
	}
  	return buffer;
}

char *extB(int num){
	char *e = " e ";
	char *nomeNumero;
	int cent,dez,uni,dv;
	cent=num/100;
	dez=num/10-cent*10;
	uni=num-(num/10)*10;
	dv=dez*10+uni;
	nomeNumero=unidades[uni];
	if (num<10)
		return nomeNumero;
	if ((dv>10) && (dv<20))
		nomeNumero=dezVinte[dv-10];
	else{
		if (uni==0)
			nomeNumero=dezenas[dez];
		else{
			nomeNumero=extA(e,nomeNumero);
			nomeNumero=extA(dezenas[dez],nomeNumero);
		}
	}
	if (num<100)
    		return nomeNumero;
	if ((dez==0)&&(uni==0)){
		if (cent==1)
			nomeNumero="cem";
		else
			nomeNumero=centenas[cent];
  	}
  	else{
		nomeNumero=extA(e,nomeNumero);
		nomeNumero=extA(centenas[cent],nomeNumero);
  	}
	return nomeNumero;
}

int main(int narg, char *argv[]){
	FILE *arquivo;
	int numero;
	char *numeroExtenso;
	if (narg > 1) {
		arquivo = fopen(argv[1],"r");
		if (arquivo == NULL) {
			fprintf(stderr, "Erro abrindo o arquivo.\n");
			return EXIT_FAILURE;
		}
		while (!feof(arquivo)) {
			fscanf(arquivo, "%d ", &numero);
			numeroExtenso=extB(numero);
			printf("Numero %d por extenso: %s\n",numero,numeroExtenso);
		}
	fclose(arquivo);
	}
	else {
		printf("Entre com um numero 0-999: ");
		scanf("%d",&numero);
		numeroExtenso=extB(numero);
		printf("Numero %d por extenso: %s\n",numero,numeroExtenso); 
	}
	return EXIT_SUCCESS;
}