
typedef struct arvoreBB {
	int chave;
	float valor;
	struct arvoreBB *direita;
	struct arvoreBB *esquerda;
} arvoreBB;

typedef struct listaEncadeada {
	int chave;
	float valor;
	struct listaEncadeada *proximo;
	struct listaEncadeada *anterior;
} listaEncadeada;

void inserirArvore (arvoreBB **, int, float);

void percorrerArvore (arvoreBB *);

void inserirLista (listaEncadeada **, int, float);

void buscarLista (listaEncadeada *);