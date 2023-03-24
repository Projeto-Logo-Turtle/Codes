///Cabe�alho de pr�-processamento das fun��es do jogo.

#ifndef JOGO_H_INCLUDED
#define JOGO_H_INCLUDED

///defini��es
#define altura 50 //optei por deixar as duas variaveis simetricas
#define largura 100

///Var
typedef struct entrada
    {
        char comando[10]; //Diminui o tamanho do array de char (string)
        int passos;
    } entr;

///Signatures

void chamada_game(); //fun��o que ir�o desencadear o jogo.
int chama_print_tabu(char canva[altura][largura]);

int board(char tabuleiro[altura][largura]); //nessa sig, diz que ela vai receber uma array bidimensional (matriz). optarei por trocar o nome, a fim de n�o haver confus�o
int transition(char matriz [altura][largura]); // fun��o de print (impress�o na tela)
void tela_fim();

void primeira_chamada(char I_G[altura][largura]);
void primeira_position(char I_G[altura][largura]);
#endif // JOGO_H_INCLUDED

