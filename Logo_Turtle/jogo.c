#include "menu.h"
game(){ system("cls");deadline();printf("\n\t\t\tLets play!\n\n");

                    // acredito que para o jogo, posso fazer uma matriz homogenea ou um struct (heterogeneo) para receber as keywords

                    ///talvez dê pra colocar o limite por alocação dinamica.



typedef struct entrada{
char comando[20];
int passos;
} entr; //struct de entrada com


    entr quantidade[20];    //declarei um novo tipo de variavel, que consiste num array (Matriz unidimensional) de uma estrutura.

    for (int i = 0; i < 20; i++)
    {
        printf("\t\t\tDigite o Comando: ");
        scanf("%s", quantidade[i].comando);
        printf("\b\b\b\b\b\b\bValor:  \n\n");
        scanf("%d", &quantidade[i].passos);

    }

    deadline();
}
