///Cabe�alho de pr�-processamento das fun��es do jogo.

#ifndef JOGO_H_INCLUDED
#define JOGO_H_INCLUDED

///defini��es

#define largura 100
#define altura 50


typedef struct entrada
    {
        char comando[20];
        int passos;
    } entr;

chamada_game(); //fun��o que ir�o desencadear o jogo.





int board (char tabuleiro[largura][altura]);
inputs(entr quantidade[20]);
teste_inputs(entr quantidade[]);
transition();

#endif // JOGO_H_INCLUDED
