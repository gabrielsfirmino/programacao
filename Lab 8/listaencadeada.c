#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "./listaencadeada.h"
#define  TAMnome 100

void cleanBuffer() {
	char cl;
	cl = getchar();
	while (cl != '\n' && cl != EOF)
		cl = getchar();
}

char menu(){
	char op;
	do{
		printf("\n# AGENDA TELEFONICA #\n");
		printf("I- Inserir novo registro.\n");
		printf("P- Percorrer toda a agenda.\n");
		printf("C- Carregar agenda.\n");
		printf("S- Salvar agenda.\n");
		printf("E- Exit.\n");
		printf("Digite sua escolha: ");
	    __fpurge(stdin);
		scanf("%c", &op);
		op = toupper(op);
	} while((op!='I') && (op!='P') && (op!='C') && (op!='S') && (op!='E'));
	return op;
}

void inserir(TipoAgenda *registro){
	TipoAgenda *head;
	head = NULL;
	TipoAgenda *atual;
	atual=(TipoAgenda*)malloc(sizeof(TipoAgenda));
	TipoAgenda *auxiliar;

    if ((head->prox) == NULL)
		(head->prox) = registro;

	else {
        atual = (head->prox);
		do {
			if ((strcmp(atual->nome,(atual->prox)->nome) > 0) && (atual->prox != NULL)) {
				auxiliar = ((atual->prox)->prox);
				((atual->prox)->prox) = atual;
				(atual->prox) = auxiliar;
			}
			atual = (atual->prox);
		} while(atual != NULL);
		atual = registro;
		(atual->prox) = NULL;
	}
}

void carregar(FILE *arq){
	char buffer[500];
	TipoAgenda *novo;
	novo=(TipoAgenda*)malloc(sizeof(TipoAgenda));
		while (!feof(arq)) {
			fscanf(arq,"%d", &(novo->matricula));
			fgets(buffer, TAMnome, arq);
			buffer[strlen(buffer)-1] = '\0';
			strcpy(novo->nome,buffer);
			fscanf(arq,"%d", &(novo->ddd));
			fscanf(arq,"%d", &(novo->numero));
			fscanf(arq," %c", &(novo->tipo));
			(novo->prox) = NULL;
			inserir(novo);
		}
}
