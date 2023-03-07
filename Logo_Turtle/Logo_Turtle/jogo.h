///Cabeçalho de pré-processamento das funções do jogo.

#ifndef JOGO_H_INCLUDED
#define JOGO_H_INCLUDED

///definições
#define altura 50 //optei por deixar as duas variaveis simetricas
#define largura 100

///Var
typedef struct entrada
    {
        char comando[10]; //Diminui o tamanho do array de char (string)
        int passos;
    } entr;

///Signatures

void chamada_game(); //função que irão desencadear o jogo.
int chama_print_tabu(char canva[altura][largura]);

int board(char tabuleiro[altura][largura]); //nessa sig, diz que ela vai receber uma array bidimensional (matriz). optarei por trocar o nome, a fim de não haver confusão
int transition(char matriz [altura][largura]); // função de print (impressão na tela)
void tela_fim();

void primeira_chamada(char I_G[altura][largura]);
void primeira_position(char I_G[altura][largura]);
#endif // JOGO_H_INCLUDED

