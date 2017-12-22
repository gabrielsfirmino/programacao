#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "./biblioteca.h"
#define VERTICAL 1
#define HORIZONTAL 0
#define ESQUERDA 1
#define DIREITA 0
#define VERDADE 1
#define FALSO 0

  /*********************************************************************************************************************
 **********************************************************************************************************************
    FUNÇÃO MAIN PRINCIPAL ONDE SÃO INICIALIZADOS O TABULEIRO DOS COMPETIDORES E A LISTA DE POSSIBILIDADES(USADA PARA 
    IDENTIFICAR AS POSSIVEIS JOGADAS DO COMPETIDOR MAQUINA)

 **********************************************************************************************************************/

int main(int argc, char const *argv[]) 
{
    Tabuleiro *tabuleiroJogador;
    Tabuleiro *tabuleiroMaquina;
    ListaPossibilidades *lista;
 
    Posicao jogadaHumano;
    Posicao jogadaComputador;

    srand(time(NULL));
 
    tabuleiroJogador = (Tabuleiro*) malloc(sizeof(Tabuleiro));
    inicializarTabuleiro(tabuleiroJogador);
 
    tabuleiroMaquina = (Tabuleiro*) malloc(sizeof(Tabuleiro));
    inicializarTabuleiro(tabuleiroMaquina);
 
    alocarEmbarcacoes(tabuleiroMaquina);
    alocarEmbarcacoes(tabuleiroJogador);

    lista = (ListaPossibilidades*) malloc(sizeof(ListaPossibilidades));
    lista->vazio = VERDADE;
    
    imprimirTabuleiro(tabuleiroJogador,tabuleiroMaquina); 
    getchar();

    while (VERDADE) 
    {
        jogadaHumano =  humanoJoga(tabuleiroJogador,tabuleiroMaquina);  
        imprimirTabuleiro(tabuleiroJogador,tabuleiroMaquina); 
        getchar();

        jogadaComputador = maquinaJoga(tabuleiroJogador,tabuleiroMaquina,lista);
        imprimirTabuleiro(tabuleiroJogador,tabuleiroMaquina); 
        getchar();

        printf("Ultima jogada do Computador: [%d][%d]\n",jogadaComputador.linha+1,jogadaComputador.coluna+1);
        printf("Ultima jogada do Humano: [%d][%d]\n",jogadaHumano.linha+1,jogadaHumano.coluna+1);
    }

    return 0;
}
