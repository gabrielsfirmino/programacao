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

char menu() {
	char op;
	do {
		printf("\n# AGENDA TELEFONICA #\n");
		printf("L- Listar nomes na agenda.\n");
		printf("I- Inserir novo registro.\n");
		printf("A- Apagar registro pelo nome.\n");
		printf("B- Buscar telefone pelo nome.\n");
		printf("O- Ordenar pelo nome.\n");
		printf("S- Sair.\n");
		printf("Digite sua escolha: ");
	    __fpurge(stdin);
		scanf("%c", &op);
		op = toupper(op);
	} while ((op!='L') && (op!='I') && (op!='A') && (op!='B') && (op!='S') && (op!='O'));
	return op;
}

int main (int narg, char *argv[]) {
	TipoAgenda *agenda;
	TipoAgenda *novo[TAMagenda];
	TipoAgenda *auxiliar3;
    int contador=0,auxiliar,auxiliar2,escolha,buscado;
    char opt,buffer[500],procurar[TAMnome],deletar[TAMnome];
	FILE *fp;

	for (auxiliar=0; auxiliar<TAMagenda; auxiliar++)
		novo[auxiliar] = NULL;

	if (narg > 1) {
		fp = fopen(argv[1],"r");
		if (fp == NULL) {
			fprintf(stderr, "Erro abrindo o arquivo.\n");
			return EXIT_FAILURE;
		}
		while (!feof(fp)) {
			novo[contador]=(TipoAgenda*)malloc(sizeof(TipoAgenda));
			agenda=novo[contador];
			fscanf(fp,"%d\n", &(agenda->matricula));
			fgets(buffer, TAMnome, fp);
			buffer[strlen(buffer)-1] = '\0';
			strcpy(agenda->nome,buffer);
			fscanf(fp,"%d\n", &(agenda->ddd));
			fscanf(fp,"%d\n", &(agenda->numero));
			fscanf(fp,"%c\n", &(agenda->tipo));
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
						if (novo[auxiliar] != NULL) {
							printf("\n%d\n", novo[auxiliar]->matricula);
							printf("%s\n", novo[auxiliar]->nome);
							printf("%d\n", novo[auxiliar]->ddd);
							printf("%d\n", novo[auxiliar]->numero);
							printf("%c\n", novo[auxiliar]->tipo);
						}
					}
				}
				break;
			case 'I':
				if (contador==TAMagenda) {
					printf("\nAgenda cheia.\n");
				}
				else {
					auxiliar=0;
					while (novo[auxiliar] != NULL)
						auxiliar++;

					novo[auxiliar]=(TipoAgenda*)malloc(sizeof(TipoAgenda));
					printf("Digite a matricula: ");
					scanf("%d", &(novo[auxiliar]->matricula));
					cleanBuffer();
					printf("Digite o nome: ");
					fgets(buffer, TAMnome, stdin);
					buffer[strlen(buffer)-1] = '\0';
					strcpy(novo[auxiliar]->nome,buffer);
					printf("Digite o ddd: ");
					scanf("%d", &(novo[auxiliar]->ddd));
					cleanBuffer();
					printf("Digite o numero: ");
					scanf("%d", &(novo[auxiliar]->numero));
					cleanBuffer();
					printf("Digite o tipo: ");
					scanf("%c", &(novo[auxiliar]->tipo));
					cleanBuffer();
					printf("\nContato adicionado com sucesso.\n");
					if (auxiliar==contador)
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
						if ((strcmp(novo[auxiliar]->nome,deletar))==0) {
							novo[auxiliar] = NULL;
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
						if ((strcmp(novo[auxiliar]->nome,procurar))==0) {
							printf("\nContato encontrado:");
							printf("\n%d\n", novo[auxiliar]->matricula);
							printf("%s\n", novo[auxiliar]->nome);
							printf("%d\n", novo[auxiliar]->ddd);
							printf("%d\n", novo[auxiliar]->numero);
							printf("%c\n", novo[auxiliar]->tipo);
							buscado=1;
						}
					}
					if (buscado==0)
						printf("\nContato não encontrado.\n");
				} 
				break;
			case 'O':
					for(auxiliar2=(contador-1); auxiliar2>=0; auxiliar2--)  {
						for(auxiliar=0; auxiliar<auxiliar2; auxiliar++) {
							if (novo[auxiliar] != NULL) {
								if (strcmp(novo[auxiliar]->nome,novo[auxiliar+1]->nome)>0) {
									auxiliar3=novo[auxiliar];
									novo[auxiliar]=novo[auxiliar+1];
									novo[auxiliar+1]=auxiliar3;
								}
							}
						}
					}
					printf("\nLista ordenada.\n");
				break;
			case 'S':
				break;
		}
					
	} while(escolha != 'S');

	return EXIT_SUCCESS;
}
