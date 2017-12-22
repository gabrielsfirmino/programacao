#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define  TAMnome 100
#define TAMagenda 1000

typedef struct {
	int matricula;
	char nome[TAMnome];
	int ddd;
	int numero;
	char tipo;
} TipoAgenda;

void cleanBuffer() {
	char cl;
	cl = getchar();
	while (cl != '\n' && cl != EOF)
		cl = getchar();
}

int menu() {
	char op;
	do {
		printf("\n# AGENDA TELEFONICA #\n");
		printf("L- Listar nomes na agenda.\n");
		printf("I- Inserir novo registro.\n");
		printf("A- Apagar registro pelo nome.\n");
		printf("B- Buscar telefone pelo nome.\n");
		printf("S- Sair.\n");
		printf("Digite sua escolha: ");
	    __fpurge(stdin);
		scanf("%c", &op);
		op = toupper(op);
	} while ((op!='L') && (op!='I') && (op!='A') && (op!='B') && (op!='S'));
	return op;
}

int main (int narg, char *argv[]) {
	TipoAgenda agenda[TAMagenda];
    FILE *fp;
	int contador=0,auxiliar,buscado;
	char buffer[500], procurar[TAMnome],deletar[TAMnome],escolha;

	if (narg > 1) {
		fp = fopen(argv[1],"r");
		if (fp == NULL) {
			fprintf(stderr, "Erro abrindo o arquivo.\n");
			return EXIT_FAILURE;
		}
		while (!feof(fp)) {
			fscanf(fp,"%d\n", &(agenda[contador].matricula));
			fgets(buffer, TAMnome, fp);
			buffer[strlen(buffer)-1] = '\0';
			strcpy(agenda[contador].nome,buffer);
			fscanf(fp,"%d\n", &(agenda[contador].ddd));
			fscanf(fp,"%d\n", &(agenda[contador].numero));
			fscanf(fp,"%c\n", &(agenda[contador].tipo));
			contador ++;
		}
		fclose(fp);
	}
	do {
		escolha=menu();
		switch(escolha) {
			case 'L':
				if (contador==0) {
					printf("\nAgenda vazia.\n");
				}
				else {
					for (auxiliar=0; auxiliar<contador; auxiliar++) {
						if (agenda[auxiliar].tipo != '\n') {
							printf("\n%d\n", agenda[auxiliar].matricula);
							printf("%s\n", agenda[auxiliar].nome);
							printf("%d\n", agenda[auxiliar].ddd);
							printf("%d\n", agenda[auxiliar].numero);
							printf("%c\n", agenda[auxiliar].tipo);
						}
					}
				}
				break;
			case 'I':
				if (contador==TAMagenda) {
					printf("\nAgenda cheia.\n");
				}
				else {
					cleanBuffer();
					printf("Digite a matricula: ");
					scanf("%d", &(agenda[contador].matricula));
					cleanBuffer();
					printf("Digite o nome: ");
					fgets(buffer, TAMnome, stdin);
					buffer[strlen(buffer)-1] = '\0';
					strcpy(agenda[contador].nome,buffer);
					printf("Digite o ddd: ");
					scanf("%d", &(agenda[contador].ddd));
					cleanBuffer();
					printf("Digite o numero: ");
					scanf("%d", &(agenda[contador].numero));
					cleanBuffer();
					printf("Digite o tipo: ");
					scanf("%c", &(agenda[contador].tipo));
					cleanBuffer();
					printf("\nContato adicionado com sucesso.\n");
					contador++;
				}
				break;
			case 'A':
				buscado=0;
				cleanBuffer();
				printf("Digite o nome: ");
				fgets(buffer, TAMnome, stdin);
				buffer[strlen(buffer)-1] = '\0';
				strcpy(deletar,buffer);
				if (contador==0)
					printf("\nContato não encontrado.Agenda vazia.\n");
				else {
					for(auxiliar=0; auxiliar<contador; auxiliar++) {
						if ((strcmp(agenda[auxiliar].nome,deletar))==0) {
							agenda[auxiliar].matricula=0;
                        	strcpy(agenda[auxiliar].nome,"");
							agenda[auxiliar].ddd=0;
							agenda[auxiliar].numero=0;
							agenda[auxiliar].tipo='\n';
							printf("\nContato apagado com sucesso.\n");
							buscado=1;
						}
					}
					if (buscado==0)
						printf("\nContato não existe.\n");
				}
				break;
			case 'B':
				buscado=0;
				cleanBuffer();
				printf("Digite o nome: ");
				fgets(buffer, TAMnome, stdin);
				buffer[strlen(buffer)-1] = '\0';
				strcpy(procurar,buffer);
				if (contador==0) 
					printf("\nContato não encontrado.Agenda vazia.\n");
				else {
					for(auxiliar=0; auxiliar<contador; auxiliar++) {
						if ((strcmp(agenda[auxiliar].nome,procurar))==0) {
							printf("\nContato encontrado:");
							printf("\n%d\n", agenda[auxiliar].matricula);
							printf("%s\n", agenda[auxiliar].nome);
							printf("%d\n", agenda[auxiliar].ddd);
							printf("%d\n", agenda[auxiliar].numero);
							printf("%c\n", agenda[auxiliar].tipo);
							buscado=1;
						}
					}
					if (buscado==0)
						printf("\nContato não encontrado.\n");
				}
				break;
			case 'S':
				break;
		}
				
	} while(escolha != 'S');

	return EXIT_SUCCESS;
}
