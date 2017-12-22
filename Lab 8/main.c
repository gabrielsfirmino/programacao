#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "./listaencadeada.h"
#define  TAMnome 100

int main(int argc, char *argv[]) {
	FILE *fp;
	char opt;
	char buffer[500];
	TipoAgenda *contato;
	do {
		opt=menu();
		switch(opt){
			case 'I':
			    contato=(TipoAgenda*)malloc(sizeof(TipoAgenda));
				printf("Digite a matricula: ");
				scanf("%d", &(contato->matricula));
				cleanBuffer();
				printf("Digite o nome: ");
				fgets(buffer, TAMnome, stdin);
				buffer[strlen(buffer)-1] = '\0';
				strcpy(contato->nome,buffer);
				printf("Digite o ddd: ");
				scanf("%d", &(contato->ddd));
				cleanBuffer();
				printf("Digite o numero: ");
				scanf("%d", &(contato->numero));
				cleanBuffer();
				printf("Digite o tipo: ");
				scanf("%c", &(contato->tipo));
				cleanBuffer();
				inserir(contato);
				printf("\nContato adicionado com sucesso.\n");
				break;
			case 'P':
				break;
			case 'C':
				if (argc > 1) {
					fp = fopen(argv[1],"r");
					if (fp == NULL) {
						fprintf(stderr, "Erro abrindo o arquivo.\n");
						return EXIT_FAILURE;
					}
					carregar(fp);
					fclose(fp);
				}
				break;
			case 'S':
				break;
			case 'E':
				break;
		}
	} while(opt != 'E');

	return EXIT_SUCCESS;
}
