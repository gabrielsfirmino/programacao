#define  TAMnome 100

typedef struct registros {
	int matricula;
	char nome[TAMnome];
	int ddd;
	int numero;
	char tipo;
	struct registros *prox;
} TipoAgenda;


char menu();
void cleanBuffer();
void inserir(TipoAgenda*);
void carregar(FILE*);
//salvar();