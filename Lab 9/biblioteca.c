#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "./biblioteca.h"

void inserirArvore (arvoreBB **arvore, int chave, float valor) {
	arvoreBB *auxiliar;

	if ((*arvore) == NULL) {
		auxiliar = (arvoreBB*)malloc(sizeof(arvoreBB));
		auxiliar->valor = valor;
		auxiliar->chave = chave;
		auxiliar->direita = auxiliar->esquerda = NULL;
		(*arvore) = auxiliar;
		return;
	}
	if (chave < (*arvore)->chave) {
		inserirArvore (&(*arvore)->esquerda, chave, valor);
		return;
	}
	if (chave > (*arvore)->chave) {
		inserirArvore (&(*arvore)->direita, chave, valor);
		return;
	}
}

void percorrerArvore (arvoreBB *arvore) {
	printf("Arvore binaria de busca:\n");
	if (arvore != NULL) {
		percorrerArvore(arvore->esquerda);
		printf("Chave = %d\n", arvore->chave);
		percorrerArvore(arvore->direita);
	}
}

void inserirLista (listaEncadeada **lista, int chave, float valor) {
	listaEncadeada *novo, *auxiliar;
	novo = (listaEncadeada*)malloc(sizeof(listaEncadeada));
	novo->chave = chave;
	novo->valor = valor;
	auxiliar = (*lista);

	if ((*lista) == NULL) {
		novo->proximo = NULL;
		novo->anterior = NULL;
		(*lista) = novo;
		return;
	}
	else {
		if (novo->chave < auxiliar->chave) {
			novo->proximo = auxiliar;
			novo->anterior = NULL;
			auxiliar->anterior = novo;
			(*lista) = novo;
			return;
		}
		else {
			while ((auxiliar->proximo != NULL) && (novo->chave > auxiliar->chave))
				auxiliar = auxiliar->proximo;
			if (novo->chave > auxiliar->chave) {
				novo->proximo = auxiliar->proximo;
				novo->anterior = auxiliar;
				auxiliar->proximo = novo;
				return;
			}
			if (novo->chave < auxiliar->chave) {
				novo->proximo = auxiliar;
				novo->anterior = auxiliar->anterior;
				(auxiliar->anterior)->proximo = novo;
				auxiliar->anterior = novo;
				return;
			}
		}
	}
}

void buscarLista(listaEncadeada *lista) {
	listaEncadeada *atual;
	atual=(lista);	
	printf("Lista duplamente encadeada:\n");
	while(atual!=NULL){
		printf("Chave = %f\n", lista->valor);
		atual=atual->proximo;
	}
}