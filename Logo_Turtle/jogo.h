///Cabe�alho de pr�-processamento das fun��es do jogo.

#ifndef JOGO_H_INCLUDED
#define JOGO_H_INCLUDED

typedef struct entrada
    {
        char comando[20];
        int passos;
    } entr;

game();//fun��o que ir�o desencadear o jogo.
inputs();
teste_inputs(entr quantidade[]);
#endif // JOGO_H_INCLUDED
