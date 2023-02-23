#include "menu.h"
game(){ system("cls");deadline();printf("\n\t\t\tLets play!\n\n");

                    // acredito que para o jogo, posso fazer uma matriz homogenea ou um struct (heterogeneo) para receber as keywords

                    ///talvez dê pra colocar o limite por alocação dinamica.



typedef struct entrada{
char comando[20];
int passos;
} entr; //struct de entrada com


    entr quantidade[20];    //declarei um novo tipo de variavel, que consiste num array (Matriz unidimensional) de uma estrutura.

    for (int indice = 0; indice < 20; indice++)
    {
        printf("\nDigite o Comando: ");
        scanf("%s", quantidade[indice].comando);
        printf(" Valor: ");
        scanf("%d", &quantidade[indice].passos);

    }

    /*função para exibir as entradas da matriz quantidade
    printf("Respostas:");
    int contagem;
    for (contagem = 0; contagem < 20; contagem++) {
        printf("Entrada %d: Comando=%s, Passos=%d\n", contagem, quantidade[contagem].comando, quantidade[contagem].passos);
    }
    */


    deadline();
}
