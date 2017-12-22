#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "./biblioteca.h"

int main (int narg, char * argv[]) {
	clock_t inicioPercorrer,fimPercorrer;
	clock_t inicioBusca,fimBusca;

	arvoreBB *arvore;
	listaEncadeada *lista;
	int chave, i;
	float valor;

	lista = NULL;
	arvore = NULL;

	srand(time(NULL));

	for (i = 0;i < 50000; i++) {
		chave = rand();
		valor = (float)rand()/50000;
		inserirArvore(&arvore, chave, valor);
		inserirLista(&lista, chave, valor);
	}

	printf("\n");	
	inicioPercorrer = clock();
	percorrerArvore(arvore);
	fimPercorrer = clock();
	
	inicioBusca = clock();
	buscarLista(lista);
	fimBusca = clock();
	
	system("clear");
	printf("Tempo para percorrer a Arvore: %f segundos.\n", (double)(fimPercorrer-inicioPercorrer)/CLOCKS_PER_SEC);
	printf("Tempo para fazer uma busca na Lista: %f segundos.\n", (double)(fimBusca-inicioBusca)/CLOCKS_PER_SEC);

	return EXIT_SUCCESS;
}