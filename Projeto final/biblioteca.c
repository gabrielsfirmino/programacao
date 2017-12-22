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
    FUNÇÃO RANDOMICA QUE TORNA ALEATORIA AS ENTRADAS DO COMPETIDOR MAQUINA DURANTE TODA A BATALHA

 **********************************************************************************************************************/

Posicao sortearPosicoes() 
{
    Posicao posicao;
    int linha;
    int coluna;
    int i;
   
    linha = rand() % 10;
    coluna = rand() % 10;
 
    posicao.linha = linha;
    posicao.coluna = coluna;
 
    return posicao;
}

 /*********************************************************************************************************************
 **********************************************************************************************************************
    FUNÇÃO AUXILIAR RANDOMICA QUE TORNA ALEATORIA A ORIENTAÇÃO EM QUE SERÁ ALOCADO O BARCO 

 **********************************************************************************************************************/
 
int sorteiaOrientacao() 
{
    int orientacao;
 
    orientacao = rand() % 2;
 
    if(orientacao == HORIZONTAL) {
        return HORIZONTAL;
    }
 
    return VERTICAL;
}

 /*********************************************************************************************************************
 **********************************************************************************************************************
    FUNÇÃO AUXILIAR RANDOMICA QUE TORNA ALEATORIA A DIREÇÃO EM QUE SERÁ ALOCADO O BARCO

 **********************************************************************************************************************/
 
int sorteiaDirecao() 
{
    int direcao;
 
    direcao = rand() % 2;
 
    if(direcao == DIREITA) {
        return DIREITA;
    }
   
    return ESQUERDA;
}

 /*********************************************************************************************************************
 **********************************************************************************************************************
    FUNÇÃO PRINCIPAL PARA ALOCAÇÃO DO PORTA AVIÕES DENTRO DA STRUCT BASEADA NOS SORTEIOS RANDOMICOS REALIZADOS

 **********************************************************************************************************************/
 
void alocaPortaAvioes(Tabuleiro *tabuleiro) 
{
    Posicao posicaoSorteada;
    int orientacao;
    int direcao;
 
    posicaoSorteada = sortearPosicoes();
    orientacao = sorteiaOrientacao();
    direcao = sorteiaDirecao();
 
    if(orientacao == HORIZONTAL) {
        if(posicaoSorteada.coluna + 5 < 10) {
            tabuleiro->celulas[posicaoSorteada.linha][posicaoSorteada.coluna].conteudo = '<';
            tabuleiro->celulas[posicaoSorteada.linha][posicaoSorteada.coluna + 1].conteudo = '#';
            tabuleiro->celulas[posicaoSorteada.linha][posicaoSorteada.coluna + 2].conteudo = '#';
            tabuleiro->celulas[posicaoSorteada.linha][posicaoSorteada.coluna + 3].conteudo = '#';
            tabuleiro->celulas[posicaoSorteada.linha][posicaoSorteada.coluna + 4].conteudo = '>';
        } else {
            tabuleiro->celulas[posicaoSorteada.linha][posicaoSorteada.coluna].conteudo = '>';
            tabuleiro->celulas[posicaoSorteada.linha][posicaoSorteada.coluna - 1].conteudo = '#';
            tabuleiro->celulas[posicaoSorteada.linha][posicaoSorteada.coluna - 2].conteudo = '#';
            tabuleiro->celulas[posicaoSorteada.linha][posicaoSorteada.coluna - 3].conteudo = '#';
            tabuleiro->celulas[posicaoSorteada.linha][posicaoSorteada.coluna - 4].conteudo = '<';
        }
    }
 
    if(orientacao == VERTICAL) {
        if(posicaoSorteada.linha + 5 < 10) {
            tabuleiro->celulas[posicaoSorteada.linha][posicaoSorteada.coluna].conteudo = '^';
            tabuleiro->celulas[posicaoSorteada.linha + 1][posicaoSorteada.coluna].conteudo = '#';
            tabuleiro->celulas[posicaoSorteada.linha + 2][posicaoSorteada.coluna].conteudo = '#';
            tabuleiro->celulas[posicaoSorteada.linha + 3][posicaoSorteada.coluna].conteudo = '#';
            tabuleiro->celulas[posicaoSorteada.linha + 4][posicaoSorteada.coluna].conteudo = 'v';
        } else {
            tabuleiro->celulas[posicaoSorteada.linha][posicaoSorteada.coluna].conteudo = 'v';
            tabuleiro->celulas[posicaoSorteada.linha - 1][posicaoSorteada.coluna].conteudo = '#';
            tabuleiro->celulas[posicaoSorteada.linha - 2][posicaoSorteada.coluna].conteudo = '#';
            tabuleiro->celulas[posicaoSorteada.linha - 3][posicaoSorteada.coluna].conteudo = '#';
            tabuleiro->celulas[posicaoSorteada.linha - 4][posicaoSorteada.coluna].conteudo = '^';
        }
    }
}

 /*********************************************************************************************************************
 **********************************************************************************************************************
    FUNÇÃO PRINCIPAL PARA ALOCAÇÃO DO DESTROYER DENTRO DA STRUCT BASEADA DOS SORTEIOS RANDOMICOS REALIZADOS

 **********************************************************************************************************************/
 
void alocaDestroyer(Tabuleiro *tabuleiro)
{
    Posicao posicaoSorteada;
    int orientacao;
    int direcao;
    int i=1;
    posicaoSorteada = sortearPosicoes();
       
    orientacao = sorteiaOrientacao();
    direcao = sorteiaDirecao();
   
    while(i==1){
        posicaoSorteada = sortearPosicoes();
     
        if(orientacao == HORIZONTAL) {
            if(posicaoSorteada.coluna + 2 < 10 && tabuleiro->celulas[posicaoSorteada.linha][posicaoSorteada.coluna].conteudo == ' ' &&
                tabuleiro->celulas[posicaoSorteada.linha][posicaoSorteada.coluna+1].conteudo == ' ' &&
                tabuleiro->celulas[posicaoSorteada.linha][posicaoSorteada.coluna+2].conteudo == ' ')
            {
                    tabuleiro->celulas[posicaoSorteada.linha][posicaoSorteada.coluna].conteudo = '<';
                    tabuleiro->celulas[posicaoSorteada.linha][posicaoSorteada.coluna + 1].conteudo = '#';
                    tabuleiro->celulas[posicaoSorteada.linha][posicaoSorteada.coluna + 2].conteudo = '>';
                    i=0;
            } else if (tabuleiro->celulas[posicaoSorteada.linha][posicaoSorteada.coluna].conteudo == ' ' &&
                tabuleiro->celulas[posicaoSorteada.linha][posicaoSorteada.coluna+1].conteudo == ' ' &&
                tabuleiro->celulas[posicaoSorteada.linha][posicaoSorteada.coluna+2].conteudo == ' ')
            {
                    tabuleiro->celulas[posicaoSorteada.linha][posicaoSorteada.coluna].conteudo = '>';
                    tabuleiro->celulas[posicaoSorteada.linha][posicaoSorteada.coluna - 1].conteudo = '#';
                    tabuleiro->celulas[posicaoSorteada.linha][posicaoSorteada.coluna - 2].conteudo = '<';
                    i=0;
            }
        }
     
        if(orientacao == VERTICAL) {
            if(posicaoSorteada.linha + 2 < 10 && tabuleiro->celulas[posicaoSorteada.linha][posicaoSorteada.coluna].conteudo == ' ' &&
                tabuleiro->celulas[posicaoSorteada.linha+1][posicaoSorteada.coluna].conteudo == ' ' &&
                tabuleiro->celulas[posicaoSorteada.linha+2][posicaoSorteada.coluna].conteudo == ' ') {
                    tabuleiro->celulas[posicaoSorteada.linha][posicaoSorteada.coluna].conteudo = '^';
                    tabuleiro->celulas[posicaoSorteada.linha + 1][posicaoSorteada.coluna].conteudo = '#';
                    tabuleiro->celulas[posicaoSorteada.linha + 2][posicaoSorteada.coluna].conteudo = 'v';
                    i=0;
            }else if (tabuleiro->celulas[posicaoSorteada.linha][posicaoSorteada.coluna].conteudo == ' ' &&
                tabuleiro->celulas[posicaoSorteada.linha+1][posicaoSorteada.coluna].conteudo == ' ' &&
                tabuleiro->celulas[posicaoSorteada.linha+2][posicaoSorteada.coluna].conteudo == ' ')
            {
                    tabuleiro->celulas[posicaoSorteada.linha][posicaoSorteada.coluna].conteudo = 'v';
                    tabuleiro->celulas[posicaoSorteada.linha-1][posicaoSorteada.coluna].conteudo = '#';
                    tabuleiro->celulas[posicaoSorteada.linha-2][posicaoSorteada.coluna].conteudo = '^';
                    i=0;
            }
        }
     }
}

/*********************************************************************************************************************
 **********************************************************************************************************************
    FUNÇÃO PRINCIPAL PARA ALOCAÇÃO DA JANGADA DENTRO DA STRUCT BASEADA DOS SORTEIOS RANDOMICOS REALIZADOS

 **********************************************************************************************************************/

void alocaJangada(Tabuleiro *tabuleiro)
{
    Posicao posicaoSorteada;
    int orientacao;
    int direcao;
    int i=1;
    posicaoSorteada = sortearPosicoes();
       
    orientacao = sorteiaOrientacao();
    direcao = sorteiaDirecao();
   
    while(i==1){
        posicaoSorteada = sortearPosicoes();
     
        if(orientacao == HORIZONTAL) {
            if(tabuleiro->celulas[posicaoSorteada.linha][posicaoSorteada.coluna].conteudo == ' ')
            {
                    tabuleiro->celulas[posicaoSorteada.linha][posicaoSorteada.coluna].conteudo = '&';
                    i=0;
            } else if (tabuleiro->celulas[posicaoSorteada.linha][posicaoSorteada.coluna].conteudo == ' ')
            {
                    tabuleiro->celulas[posicaoSorteada.linha][posicaoSorteada.coluna].conteudo = '&';
                    i=0;
            }
        }
     
        if(orientacao == VERTICAL) {
            if(tabuleiro->celulas[posicaoSorteada.linha][posicaoSorteada.coluna].conteudo == ' ') {
                    tabuleiro->celulas[posicaoSorteada.linha][posicaoSorteada.coluna].conteudo = '&';
                    i=0;
            }else if (tabuleiro->celulas[posicaoSorteada.linha][posicaoSorteada.coluna].conteudo == ' ')
            {
                    tabuleiro->celulas[posicaoSorteada.linha][posicaoSorteada.coluna].conteudo = '&';
                    i=0;
            }
        }
     } 
}

 /*********************************************************************************************************************
 **********************************************************************************************************************
    FUNÇÃO PRINCIPAL PARA ALOCAÇÃO DO FRAGATA DENTRO DA STRUCT BASEADA DOS SORTEIOS RANDOMICOS REALIZADOS

 **********************************************************************************************************************/
 
void alocaFragata(Tabuleiro *tabuleiro)
{
    Posicao posicaoSorteada;
    int orientacao;
    int direcao;
    int i=1;
    posicaoSorteada = sortearPosicoes();
       
    orientacao = sorteiaOrientacao();
    direcao = sorteiaDirecao();
   
    while(i==1){
        posicaoSorteada = sortearPosicoes();
     
        if(orientacao == HORIZONTAL) {
            if(posicaoSorteada.coluna + 1 < 10 && tabuleiro->celulas[posicaoSorteada.linha][posicaoSorteada.coluna].conteudo == ' ' &&
                tabuleiro->celulas[posicaoSorteada.linha][posicaoSorteada.coluna+1].conteudo == ' ')
            {
                    tabuleiro->celulas[posicaoSorteada.linha][posicaoSorteada.coluna].conteudo = '<';
                    tabuleiro->celulas[posicaoSorteada.linha][posicaoSorteada.coluna + 1].conteudo = '>';
                    i=0;
            } else if (tabuleiro->celulas[posicaoSorteada.linha][posicaoSorteada.coluna].conteudo == ' ' &&
                tabuleiro->celulas[posicaoSorteada.linha][posicaoSorteada.coluna+1].conteudo == ' ')
            {
                    tabuleiro->celulas[posicaoSorteada.linha][posicaoSorteada.coluna].conteudo = '>';
                    tabuleiro->celulas[posicaoSorteada.linha][posicaoSorteada.coluna - 1].conteudo = '>';
                    i=0;
            }
        }
     
        if(orientacao == VERTICAL) {
            if(posicaoSorteada.linha + 1 < 10 && tabuleiro->celulas[posicaoSorteada.linha][posicaoSorteada.coluna].conteudo == ' ' &&
                tabuleiro->celulas[posicaoSorteada.linha+1][posicaoSorteada.coluna].conteudo == ' ')
            {
                    tabuleiro->celulas[posicaoSorteada.linha][posicaoSorteada.coluna].conteudo = '^';
                    tabuleiro->celulas[posicaoSorteada.linha + 1][posicaoSorteada.coluna].conteudo = 'v';
                    i=0;
            }else if (tabuleiro->celulas[posicaoSorteada.linha][posicaoSorteada.coluna].conteudo == ' ' &&
                tabuleiro->celulas[posicaoSorteada.linha+1][posicaoSorteada.coluna].conteudo == ' ')
            {
                    tabuleiro->celulas[posicaoSorteada.linha][posicaoSorteada.coluna].conteudo = 'v';
                    tabuleiro->celulas[posicaoSorteada.linha-1][posicaoSorteada.coluna].conteudo = '^';
                    i=0;
            }
        }
     }
}

 /*********************************************************************************************************************
 **********************************************************************************************************************
    FUNÇÃO PRINCIPAL PARA ALOCAÇÃO DO SUBMARINO DENTRO DA STRUCT BASEADA DOS SORTEIOS RANDOMICOS REALIZADOS

 **********************************************************************************************************************/
 
void alocaSubmarino(Tabuleiro *tabuleiro)
{
    Posicao posicaoSorteada;
    int orientacao;
    int direcao;
    int i=1;
    posicaoSorteada = sortearPosicoes();
       
    orientacao = sorteiaOrientacao();
    direcao = sorteiaDirecao();
   
    while(i==1){
        posicaoSorteada = sortearPosicoes();
     
        if(orientacao == HORIZONTAL) {
            if(tabuleiro->celulas[posicaoSorteada.linha][posicaoSorteada.coluna].conteudo == ' ')
            {
                    tabuleiro->celulas[posicaoSorteada.linha][posicaoSorteada.coluna].conteudo = '@';
                    i=0;
            } else if (tabuleiro->celulas[posicaoSorteada.linha][posicaoSorteada.coluna].conteudo == ' ')
            {
                    tabuleiro->celulas[posicaoSorteada.linha][posicaoSorteada.coluna].conteudo = '@';
                    i=0;
            }
        }
     
        if(orientacao == VERTICAL) {
            if(tabuleiro->celulas[posicaoSorteada.linha][posicaoSorteada.coluna].conteudo == ' ') {
                    tabuleiro->celulas[posicaoSorteada.linha][posicaoSorteada.coluna].conteudo = '@';
                    i=0;
            }else if (tabuleiro->celulas[posicaoSorteada.linha][posicaoSorteada.coluna].conteudo == ' ')
            {
                    tabuleiro->celulas[posicaoSorteada.linha][posicaoSorteada.coluna].conteudo = '@';
                    i=0;
            }
        }
     }
}

 /*********************************************************************************************************************
 **********************************************************************************************************************
    FUNÇÃO PARA INICIALIZAÇÃO DA STRUCT TABULEIRO, TRATANDO OS CASOS EM QUE OS CANTOS E AS BORDAS APONTAM PARA 
    NULL EM VEZ DE APONTAREM PARA ALGUMA OUTRA POSIÇÃO DE MEMORIA 

 **********************************************************************************************************************/
 
void inicializarTabuleiro(Tabuleiro *tabuleiro) 
{
    int i, j;
 
    for(i = 0; i < 10; i++) {
        for(j = 0; j < 10; j++) {
            tabuleiro->celulas[i][j].conteudo = ' ';
            tabuleiro->celulas[i][j].conteudo2 = ' ';
            tabuleiro->celulas[i][j].atacada = FALSO;
            tabuleiro->celulas[i][j].cima = NULL;
            tabuleiro->celulas[i][j].baixo = NULL;
            tabuleiro->celulas[i][j].esquerda = NULL;
            tabuleiro->celulas[i][j].direita = NULL;
        }
    }
   for (i = 0; i < 10; ++i)
    {
        for (j = 0; j < 10; ++j)
        {
            if(i > 0 )
            {
                tabuleiro->celulas[i][j].cima = (&tabuleiro->celulas[i-1][j]);
            }
            if(i < 9 )
            {
                tabuleiro->celulas[i][j].baixo = (&tabuleiro->celulas[i+1][j]);
            }
            if (j > 0)
            {
                tabuleiro->celulas[i][j].esquerda = (&tabuleiro->celulas[i][j-1]);
            }
            if (j < 9) 
            {
                tabuleiro->celulas[i][j].direita = (&tabuleiro->celulas[i][j+1]);     
            } 
        }
    } 
}

  /*********************************************************************************************************************
 **********************************************************************************************************************
    FUNÇÃO PRINCIPAL PARA REPRESENTAÇÃO DO ATAQUE TANTO DO COMPETIDOR HUMANO QUANTO DO COMPETIDOR MAQUINA

 **********************************************************************************************************************/
 
int atacar(Tabuleiro *tabuleiro, Posicao posicao) 
{
    if(tabuleiro->celulas[posicao.linha][posicao.coluna].atacada == VERDADE)
    {
        return 0;
    }
    if (tabuleiro->celulas[posicao.linha][posicao.coluna].conteudo == '&')
    {
        tabuleiro->celulas[posicao.linha][posicao.coluna].atacada = VERDADE;
        return 1;
    }
    if(tabuleiro->celulas[posicao.linha][posicao.coluna].conteudo == ' ') {
        tabuleiro->celulas[posicao.linha][posicao.coluna].conteudo = 'O';
        tabuleiro->celulas[posicao.linha][posicao.coluna].atacada = VERDADE;
        return 2;
    }
    else
    {
        tabuleiro->celulas[posicao.linha][posicao.coluna].conteudo = '*';
        tabuleiro->celulas[posicao.linha][posicao.coluna].conteudo2 = '*';
        tabuleiro->celulas[posicao.linha][posicao.coluna].atacada = VERDADE;
        return 3;
    }
}

  /*********************************************************************************************************************
 **********************************************************************************************************************
    FUNÇÃO PRINCIPAL PARA A REPRESENTAÇÃO DA INTERFACE EM QUE SERÁ REALIZADO A BATALHA ENTRE HUMANO E MAQUINA

 **********************************************************************************************************************/
 
void imprimirTabuleiro(Tabuleiro *tabuleiroJ, Tabuleiro *tabuleiroM) 
{
    int i, j;
    printf("         Humano\t");
    printf("                       Computador\n");
    printf("    A B C D E F G H I J\t");
    printf("          A B C D E F G H I J\n");
    printf("  +---------------------+\t");
    printf("+---------------------+");
   
    for(i = 0; i < 10; i++) {
        printf("\n");
        if(i < 9) {
            printf(" %d| ", i + 1);
        } else {
            printf("%d| ", i + 1);
        }
        for(j = 0; j < 10; j++) {
            printf("%c ", tabuleiroJ->celulas[i][j].conteudo);
        }
        printf("+     ");
        if(i < 9) {
            printf(" %d| ", i + 1);
        } else {
            printf("%d| ", i + 1);
        }
        for(j = 0; j < 10; j++) {          
            if(tabuleiroM->celulas[i][j].atacada == VERDADE) {
                printf("%c ", tabuleiroM->celulas[i][j].conteudo);
            } else {
                printf("%c ", tabuleiroM->celulas[i][j].conteudo2);
            }
        }
        printf("|");
    }
    printf("\n  +---------------------+\t");
    printf("+---------------------+\n");
}

  /*********************************************************************************************************************
 **********************************************************************************************************************
    FUNÇÃO PARA  ALOCAÇÃO DE TODAS AS A EMBARCAÇÕES PARA O DEVIDO TABULEIRO ENTRADO 

 **********************************************************************************************************************/
 
void alocarEmbarcacoes(Tabuleiro *tabuleiro) 
{
    alocaPortaAvioes(tabuleiro);
   
    alocaDestroyer(tabuleiro);
    alocaDestroyer(tabuleiro);
   
    alocaFragata(tabuleiro);
    alocaFragata(tabuleiro);
    alocaFragata(tabuleiro);
   
    alocaSubmarino(tabuleiro);
    alocaSubmarino(tabuleiro);
   
    alocaJangada(tabuleiro);
}

  /*********************************************************************************************************************
 **********************************************************************************************************************
    FUNÇÃO PRINCIPAL PARA LEITURA DA JOGADA E CONSEQUENTE VALIDAÇÃO DA MESMA

 **********************************************************************************************************************/
 
Posicao lerJogada() 
{
    #define TAMANHO_MAX_STRING 256
   
    char buffer_temporario[TAMANHO_MAX_STRING];
    char *jogada = NULL;
 
    Posicao posicao_jogada;
   
    int i;
 
    size_t tamanho_entrada = 0;
    size_t tamanho_buffer_temporario = 0;
 
    do {
        fgets(buffer_temporario, TAMANHO_MAX_STRING, stdin);
       
        tamanho_buffer_temporario += strlen(buffer_temporario);
        tamanho_entrada += tamanho_buffer_temporario;
       
        jogada = realloc(jogada, tamanho_entrada + 1);
        strcat(jogada, buffer_temporario);
    } while(tamanho_buffer_temporario == TAMANHO_MAX_STRING - 1 &&
        buffer_temporario[TAMANHO_MAX_STRING - 2]);
 
    posicao_jogada.linha = -1;
    posicao_jogada.coluna = -1;
 
    for(i = 0; jogada[i] != '\n'; i++) {
        if(jogada[i] == '1' && jogada[i + 1] == '0') {
            posicao_jogada.linha = 9;
            break;
        }
 
        if(jogada[i] >= 49 && jogada[i] <= 57) {
            posicao_jogada.linha = (int)jogada[i] - 49;
        }  
 
        if((jogada[i] >= 65 && jogada[i] <= 74)) {
            posicao_jogada.coluna = (int)jogada[i] - 65;
        }
 
        if(jogada[i] >= 97 && jogada[i] <= 106) {
            posicao_jogada.coluna = (int)jogada[i] - 97;
        }        
    }
 
    return posicao_jogada;
}

 /*********************************************************************************************************************
 **********************************************************************************************************************
    FUNÇÃO QUE TRATA O CASO EM QUE, QUANDO UM COMPETIDOR ACERTA UMA JANGADA DO ADVERSARIO
    UM SUBMARINO DEVERÁ SER DESTRUIDO DO SEU PROPRIO TABULEIRO

 **********************************************************************************************************************/

void retiraSubmarino(Tabuleiro *tabuleiro)
{
    int i,j,cont=0;

    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
        {
            if (tabuleiro->celulas[i][j].conteudo == '@' && cont == 0)
            {
                tabuleiro->celulas[i][j].conteudo = '*';   
                cont = 1;
            }
        }
    }
}

 /*********************************************************************************************************************
 **********************************************************************************************************************
    FUNÇÃO RANDOMICA DA POSIÇÃO DE PROXIMO ATAQUE BASEADA NO ULTIMO ACERTO REALIZADO PELO COMPETIDOR MAQUINA,
    UTILIZANDO A LISTA DE POSSIBILIDADES

 **********************************************************************************************************************/

Posicao sorteioInteligente(Tabuleiro *tabuleiro,ListaPossibilidades *lista) 
{
    Posicao posicao;
    int sorteio;
   
    sorteio = rand() % 4;
    if (sorteio == 0)
    {
        posicao.linha = lista->possivelDireita.linha;
        posicao.coluna = lista->possivelDireita.coluna;
        return posicao;
    }
        if (sorteio == 1)
        {
            posicao.linha = lista->possivelEsquerda.linha;
            posicao.coluna = lista->possivelEsquerda.coluna;
            return posicao;
        }
            if (sorteio == 2)
            {
                posicao.linha = lista->possivelBaixo.linha;
                posicao.coluna = lista->possivelBaixo.coluna;
                return posicao;
            }
                if (sorteio == 3)
                {
                    posicao.linha = lista->possivelCima.linha;
                    posicao.coluna = lista->possivelCima.coluna;
                    return posicao;
                }
}

 /*********************************************************************************************************************
 **********************************************************************************************************************
    FUNÇÃO QUE VALIDA O ATAQUE DO COMPETIDOR MAQUINA BASEADO NO SORTEIO INTELIGENTE DA POSIÇÃO DE ATAQUE
    E ATUALIZANDO OS VALORES DA LISTA DE POSSIBILIDADES

 **********************************************************************************************************************/

int atacarInteligente(Tabuleiro *tabuleiro, Posicao posicao, ListaPossibilidades *lista)
{
    if(tabuleiro->celulas[posicao.linha][posicao.coluna].atacada == VERDADE)
    {
        return 0;
    }
    if (tabuleiro->celulas[posicao.linha][posicao.coluna].conteudo == '&')
    {
        tabuleiro->celulas[posicao.linha][posicao.coluna].atacada = VERDADE;
        return 1;
    }
    if(tabuleiro->celulas[posicao.linha][posicao.coluna].conteudo == ' ') {
        tabuleiro->celulas[posicao.linha][posicao.coluna].conteudo = 'O';
        tabuleiro->celulas[posicao.linha][posicao.coluna].atacada = VERDADE;
        return 2;
    }
    else
    {
        tabuleiro->celulas[posicao.linha][posicao.coluna].conteudo = '*';
        tabuleiro->celulas[posicao.linha][posicao.coluna].conteudo2 = '*';
        tabuleiro->celulas[posicao.linha][posicao.coluna].atacada = VERDADE;
        if (posicao.linha == lista->possivelBaixo.linha && posicao.coluna == lista->possivelBaixo.coluna)
        {
            lista->possivelBaixo.linha = posicao.linha +1;
            lista->possivelBaixo.coluna = posicao.coluna; 
        }
        if (posicao.linha == lista->possivelCima.linha && posicao.coluna == lista->possivelCima.coluna)
        {
            lista->possivelCima.linha = posicao.linha -1;
            lista->possivelCima.coluna = posicao.coluna;             
        }
        if (posicao.linha == lista->possivelEsquerda.linha && posicao.coluna == lista->possivelEsquerda.coluna)
        {
            lista->possivelEsquerda.linha = posicao.linha;
            lista->possivelEsquerda.coluna = posicao.coluna -1;
        }
        if (posicao.linha == lista->possivelDireita.linha && posicao.coluna == lista->possivelDireita.coluna)
        {
            lista->possivelDireita.linha = posicao.linha;
            lista->possivelDireita.coluna = posicao.coluna +1;
        }
        return 3;
    }
} 

 /*********************************************************************************************************************
 **********************************************************************************************************************
    FUNÇÃO PRINCIPAL DO MOMENTO EM QUE O COMPETIDOR MAQUINA REALIZA SEUS ATAQUES, CONFERINDO ANTES SE SEUS ATAQUES SERÃO
    RANDOMICOS OU "INTELIGENTES"
    
 **********************************************************************************************************************/

Posicao maquinaJoga(Tabuleiro *tabuleiroJogador,Tabuleiro *tabuleiroMaquina,ListaPossibilidades *lista)
{
    int verificador;
    Posicao jogada_computador;

    if (lista->vazio == VERDADE)
    {
        jogada_computador = sortearPosicoes();    
        verificador = atacar(tabuleiroJogador,jogada_computador);

        if (verificador == 0)
            jogada_computador = maquinaJoga(tabuleiroJogador,tabuleiroMaquina,lista);
        if (verificador == 1)
        {
            retiraSubmarino(tabuleiroMaquina);
            printf("O Computador acertou uma jangada, é a sua vez jogador.\n");
            return jogada_computador;
        }
        if (verificador == 2)
        {
            printf("O Computador errou, é a sua vez jogador.\n");
            return jogada_computador;
        }
        if (verificador == 3)
        {
            printf("O Computador acertou.\n");
            imprimirTabuleiro(tabuleiroJogador,tabuleiroMaquina);
            getchar();
            lista->vazio = FALSO;
            lista->possivelEsquerda.linha = jogada_computador.linha; 
            lista->possivelEsquerda.coluna = jogada_computador.coluna -1;
            lista->possivelDireita.linha = jogada_computador.linha; 
            lista->possivelDireita.coluna = jogada_computador.coluna +1;            
            lista->possivelCima.linha = jogada_computador.linha +1;
            lista->possivelCima.coluna = jogada_computador.coluna;
            lista->possivelBaixo.linha = jogada_computador.linha -1;
            lista->possivelBaixo.coluna = jogada_computador.coluna;
            jogada_computador = maquinaJoga(tabuleiroJogador,tabuleiroMaquina,lista);
        }
        return jogada_computador;
    }
    if (lista->vazio == FALSO)
    {
        jogada_computador = sorteioInteligente(tabuleiroJogador,lista);
        verificador = atacarInteligente(tabuleiroJogador,jogada_computador,lista);

        if (verificador == 0)
        {
            if (tabuleiroJogador->celulas[lista->possivelCima.linha][lista->possivelCima.coluna].atacada == VERDADE &&
                tabuleiroJogador->celulas[lista->possivelBaixo.linha][lista->possivelBaixo.coluna].atacada == VERDADE &&
                tabuleiroJogador->celulas[lista->possivelDireita.linha][lista->possivelDireita.coluna].atacada == VERDADE &&
                tabuleiroJogador->celulas[lista->possivelEsquerda.linha][lista->possivelEsquerda.coluna].atacada == VERDADE)
            {
                lista->vazio = VERDADE;
                jogada_computador = maquinaJoga(tabuleiroJogador,tabuleiroMaquina,lista);
            }
            else
            {   
                lista->vazio = FALSO;
                jogada_computador = maquinaJoga(tabuleiroJogador,tabuleiroMaquina,lista);
            }
        }
        if (verificador == 1)
        {
            printf("O Computador acertou uma jangada, é a sua vez jogador.\n");
            retiraSubmarino(tabuleiroMaquina);
            return jogada_computador;
        }
        if (verificador == 2)
        {
            printf("O Computador errou, é a sua vez jogador.\n");
            return jogada_computador;
        }
        if (verificador == 3)
        {
            printf("O Computador acertou.\n");
            imprimirTabuleiro(tabuleiroJogador,tabuleiroMaquina);
            getchar();            
            jogada_computador = maquinaJoga(tabuleiroJogador,tabuleiroMaquina,lista);
        }
        return jogada_computador;
    }
}

 /*********************************************************************************************************************
 **********************************************************************************************************************
    FUNÇÃO PRINIPAL DO MOMENTO EM QUE O COMPETIDOR HUMANO ATACA, CONFERINDO SE HOUVE ACERTO, ERRO, JOGADA INVALIDA
    OU JOGADA REPETIDA.

 **********************************************************************************************************************/

Posicao humanoJoga(Tabuleiro *tabuleiroJogador, Tabuleiro *tabuleiroMaquina)
{
    Posicao jogada_humano;
    int verificador;

    printf("Entre com a sua jogada: \n");
    __fpurge(stdin); //limpa a entrada do teclado.      
    jogada_humano = lerJogada();
    if(jogada_humano.linha == -1 || jogada_humano.coluna == -1) 
    {
        printf("\nErro ao realizar Jogada!\n");
        printf("Sua jogada nao é valida! Jogue novamente!\n\n");
    }

    verificador = atacar(tabuleiroMaquina, jogada_humano);
    imprimirTabuleiro(tabuleiroJogador,tabuleiroMaquina);
    getchar();

    if (verificador == 0)
    {
        printf("Jogada já foi feita\n");
        jogada_humano = humanoJoga(tabuleiroJogador, tabuleiroMaquina);
    }
    if (verificador == 1)
    {
        printf("O Jogador acertou uma jangada, é a vez do Computador.\n");
        retiraSubmarino(tabuleiroJogador);
        return jogada_humano;
    }
    if (verificador == 2)
    {
        printf("O Jogador errou, é a vez do Computador.\n");
        return jogada_humano;
    }
    if (verificador == 3)
    {
        printf("O Jogador acertou.\n");
        jogada_humano = humanoJoga(tabuleiroJogador,tabuleiroMaquina);
    }
    return jogada_humano;
}