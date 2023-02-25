///Cabe�alho de pr�-processamento das fun��es do jogo.

#ifndef JOGO_H_INCLUDED
#define JOGO_H_INCLUDED

///defini��es
#define largura 50 //optei por deixar as duas variaveis simetricas
#define altura 100

///Var
typedef struct entrada
    {
        char comando[10]; //Diminui o tamanho do array de char (string)
        int passos;
    } entr;

///Signatures

void chamada_game(); //fun��o que ir�o desencadear o jogo.
int chama_print_tabu(char canva[largura][altura]);
int inputs(entr quantidade[20]);
int board(char tabuleiro[largura][altura]); //nessa sig, diz que ela vai receber uma array bidimensional (matriz). optarei por trocar o nome, a fim de n�o haver confus�o
/*teste_inputs(entr quantidade[]); vou deixar a fun��o de teste comentada, por enquanto*/
void transition(); // fun��o de print (impress�o na tela)
void tela_fim();
#endif // JOGO_H_INCLUDED

