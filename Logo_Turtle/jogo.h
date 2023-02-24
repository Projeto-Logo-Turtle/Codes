///Cabeçalho de pré-processamento das funções do jogo.

#ifndef JOGO_H_INCLUDED
#define JOGO_H_INCLUDED

///definições

#define largura 100
#define altura 50


typedef struct entrada
    {
        char comando[20];
        int passos;
    } entr;

game(); //função que irão desencadear o jogo.
inputs(entr quantidade[20]);
teste_inputs(entr quantidade[]);
transition();

#endif // JOGO_H_INCLUDED
