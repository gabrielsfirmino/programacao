 /*********************************************************************************************************************
 **********************************************************************************************************************
    DEFINIÇÃO DAS STRUCTS Tabuleiro e Celula UTILIZADAS DURANTE O DESENVOLVIMENTO DO PROGRAMA CUMPRINDO O REQUISITO NÃO FUNCIONAL (2.0),
    DEFINIÇÃO DAS STRUCTS Posicao e ListaPossibilidades, QUE AUXILIARAM NOS PROCESSOS PARA DINAMIZAR A MEMORIA UTILIZADA E DECLARAÇÃO 
    DAS FUNÇÕES UTILIZADAS DENTRO DO PROGRAMA

 **********************************************************************************************************************/

typedef struct Celula {
    char conteudo;
    char conteudo2;
    char atacada;
    struct Celula *cima;
    struct Celula *baixo;
    struct Celula *esquerda;
    struct Celula *direita;
} Celula;
 
typedef struct Tabuleiro {
    struct Celula celulas[10][10];
} Tabuleiro;
 
typedef struct Posicao {
    int linha;
    int coluna;
} Posicao;

typedef struct ListaPossibilidades 
{
    char vazio;
    Posicao possivelEsquerda;
    Posicao possivelDireita;
    Posicao possivelCima;
    Posicao possivelBaixo;
}ListaPossibilidades;

Posicao sortearPosicoes();
int sorteiaOrientacao();
int sorteiaDirecao();
void alocaPortaAvioes(Tabuleiro *);
void alocaDestroyer(Tabuleiro *);
void alocaJangada(Tabuleiro *);
void alocaFragata(Tabuleiro *);
void alocaSubmarino(Tabuleiro *);
void alocarEmbarcacoes(Tabuleiro *);
void inicializarTabuleiro(Tabuleiro *);
int atacar(Tabuleiro *, Posicao);
Posicao lerJogada();
void retiraSubmarino(Tabuleiro *);
Posicao sorteioInteligente(Tabuleiro *, ListaPossibilidades *);
int atacarInteligente(Tabuleiro *, Posicao, ListaPossibilidades *);
void imprimirTabuleiro(Tabuleiro *, Tabuleiro *);
Posicao maquinaJoga(Tabuleiro *, Tabuleiro *,ListaPossibilidades *);
Posicao humanoJoga(Tabuleiro *, Tabuleiro *);
